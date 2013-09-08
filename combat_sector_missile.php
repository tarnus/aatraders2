<?php
// This program is free software; you can redistribute it and/or modify it   
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: combat_sector_missile.php

include ("config/config.php");
include ("languages/$langdir/lang_bounty.inc");
include ("languages/$langdir/lang_sectormissile.inc");
include ("languages/$langdir/lang_combat.inc");
include ("globals/combat_functions.inc");
include ("globals/ship_bounty_check.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/send_system_im.inc");
include ("globals/get_player.inc");
include ("globals/log_move.inc");
include ("globals/get_rating_change.inc");
include ("globals/device_ship_tech_modify.inc");

get_post_ifset("sector, ship_id");

$title = $l_sm_title;

if (checklogin() or $tournament_setup_access == 1)
{
	$template_object->enable_gzip = 0;
	include ("footer.php");
	die();
}

$templatename = "master_template/";

include ("header.php");

$template_object->assign("title", $title);
$template_object->assign("templatename", $templatename);

$ship_id = stripnum($ship_id);

$result = $db->SelectLimit("SELECT * FROM {$db_prefix}ships WHERE ship_id='$ship_id'", 1);
$targetship = $result->fields;

$result2 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=$targetship[player_id]", 1);
$targetinfo = $result2->fields;

$result2 = $db->SelectLimit("SELECT * FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr($sector), 1);
$targetsector = $result2->fields;

$targetshipdevice = $db->GetToFieldArray("SELECT * FROM {$db_prefix}ship_devices WHERE ship_id=$ship_id", '', 'class');

$targetship_old = $targetship;
$shipinfo_old = $shipinfo;
$targetship = device_ship_tech_modify($targetship, $targetshipdevice);
$shipinfo = device_ship_tech_modify($shipinfo, $shipdevice);

if ($targetsector['zone_id'] == 2 || $shipinfo['ship_id'] == $ship_id || $targetship['sector_id'] != $targetsector['sector_id'] || $targetship['on_planet'] == "Y" || $ship_id != $targetinfo['currentship'])
{
	$template_object->assign("error_msg", $l_sm_notarg);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/attackdie.tpl");
	include ("footer.php");
	die();
}

if ($playerinfo['turns'] < 1)
{
	$template_object->assign("error_msg", $l_sm_noturn);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/attackdie.tpl");
	include ("footer.php");
	die();
}

if ($shipdevice['dev_sectormissile']['amount'] < 1)
{
	$template_object->assign("error_msg", $l_sm_nosectormissile);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/attackdie.tpl");
	include ("footer.php");
	die();
}

$result = $db->Execute("SELECT * FROM {$db_prefix}links WHERE link_start='$shipinfo[sector_id]' AND link_dest='$targetsector[sector_id]'");
if($result) {
	if($result->RecordCount() == 0)
	{
		$template_object->assign("error_msg", $l_sm_invalid);
		$template_object->assign("gotomain", $l_global_mmenu);
		$template_object->display("master_template/genericdie.tpl");
		include ("footer.php");
		die();
	}
}

$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount-1 WHERE device_id=" . $shipdevice['dev_sectormissile']['device_id']);
db_op_result($debug_query,__LINE__,__FILE__);

/* determine percent chance of success in detecting target ship - based on player's sensors and opponent's cloak */
$success = SCAN_SUCCESS($shipinfo['sensors'], $targetship['cloak'], $shiptypes[$targetship['class']]['basehull']);
$roll = mt_rand(1, 100);

if ($roll > $success)
{
	/* if scan fails - inform both player and target. */
	$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);

	playerlog($targetinfo['player_id'], "LOG5_SM_OUTSCAN", "$playerinfo[character_name]");
	$template_object->assign("error_msg", $l_sm_noscan);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/attackdie.tpl");
	include ("footer.php");
	die();
}

$is_missile_detected = 0;
$success = SCAN_SUCCESS($targetship['sensors'], $shipinfo['cloak'], $shiptypes[$shipinfo['class']]['basehull']);

$roll = mt_rand(1, 100);
if ($roll > $success)
{
	playerlog($targetinfo['player_id'], "LOG5_SM_ATTACK", "$playerinfo[character_name]|$shipinfo[sector_id]");
	$is_missile_detected = 1;
	$player_name = $playerinfo['character_name'];
}
else
{
	$player_name = $l_unknown;
}

$success = SCAN_SUCCESS($shipinfo['engines'], ($targetship['engines'] / 2), $shiptypes[$targetship['class']]['basehull']);
$roll2 = mt_rand(1, 100);

if (($success < $roll2 && $is_missile_detected) || $targetship['player_id'] < 4)
{
	$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);
	playerlog($targetinfo['player_id'], "LOG5_SM_OUTMAN", "$player_name");
	$template_object->assign("error_msg", $l_sm_flee);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/attackdie.tpl");
	include ("footer.php");
	die();
}

if($is_missile_detected)
{
	/* if scan succeeds, show results and inform target. */
	$shipavg = $targetship['basehull'] + ($targetship['hull'] + $targetship['engines'] + $targetship['power'] + $targetship['fighter'] + $targetship['sensors'] + $targetship['beams'] + $targetship['torp_launchers'] + $targetship['shields'] + $targetship['cloak'] + $targetship['armor'] + $targetship['ecm']) / 11;

	if ($shipavg > $ewd_maxavgtechlevel)
	{
		$chance = round($shipavg / $max_tech_level) * 100;
	}
	else
	{
		$chance = 0;
	}
	$random_value = mt_rand(1,100);
	if ($targetshipdevice['dev_emerwarp']['amount'] > 0 && $random_value > $chance)
	{
		/* need to change warp destination to random sector in universe */
		$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_sector_missile_attack);
		$source_sector = $shipinfo['sector_id'];

		$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and sector_id > 5 and galaxy_id = " . $targetship['galaxy_id'] . " ORDER BY rand()", 1);
		$dest_sector = $findem->fields['sector_id'];

		$debug_query = $db->SelectLimit("SELECT zone_id FROM {$db_prefix}universe WHERE sector_id=$source_sector", 1);
		db_op_result($debug_query,__LINE__,__FILE__);
		$zones = $debug_query->fields;

		$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns-1,turns_used=turns_used+1,rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		playerlog($targetinfo['player_id'], "LOG5_SM_EWD", "$player_name");

		$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET sector_id=$dest_sector, cleared_defenses=' ', on_planet='N' WHERE ship_id=$ship_id");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount-1 WHERE device_id=" . $targetshipdevice['dev_emerwarp']['device_id']);
		db_op_result($debug_query,__LINE__,__FILE__);

		log_move($targetinfo['player_id'],$targetship['ship_id'],$source_sector,$dest_sector,$shipinfo['class'],$shipinfo['cloak'],$zones['zone_id']);
		$template_object->assign("error_msg", $l_sm_ewd);
		$template_object->assign("gotomain", $l_global_mmenu);
		$template_object->display("master_template/attackdie.tpl");
		include ("footer.php");
		die();
	}
	else
	{
		playerlog($targetinfo['player_id'], "LOG5_SM_EWDFAIL", $playerinfo['character_name']);
	}
}


$l_sm_imbody = str_replace("[playername]", "<b>$player_name</b>", $l_sm_imbody);
send_system_im($targetinfo['player_id'], $l_sm_imtitle, $l_sm_imbody, $targetinfo['last_login']);

if(!class_exists('dev_sectormissile')){
	include ("class/devices/dev_sectormissile.inc");
}

$sm_object = new dev_sectormissile();
$sm_damage_shields = $sm_object->damage_shields;
$sm_damage_all = $sm_object->damage_all;

if(!class_exists($targetship['armor_class'])){
	include ("class/" . $targetship['armor_class'] . ".inc");
}

// get target beam, shield and armor values
$target_shield_energy = floor($targetship['energy'] * 0.4);
$sectormissile_attack_energy = $targetship['energy'] - $target_shield_energy;

if (NUM_SHIELDS($targetship['shields']) < $target_shield_energy)
{
	$target_shield_energy = NUM_SHIELDS($targetship['shields']);
}

$targetenergyset = $target_shield_energy + $sectormissile_attack_energy;

$left_over_energy = max(0, $targetship['energy'] - $targetenergyset);

$targetarmor = $targetship['armor_pts'];

$targetshipshields = $targetship['shields'];
$targetshiparmor = $targetship['armor'];
$targetname = $targetinfo['character_name'];

if(!class_exists($targetship['shield_class'])){
	include ("class/" . $targetship['shield_class'] . ".inc");
}

$targetobject = new $targetship['shield_class']();
$ship_shield_hit_pts = $targetobject->ship_shield_hit_pts;

if(!class_exists($targetship['armor_class'])){
	include ("class/" . $targetship['armor_class'] . ".inc");
}

$targetobject = new $targetship['armor_class']();
$ship_armor_hit_pts = $targetobject->ship_armor_hit_pts;

update_player_experience($playerinfo['player_id'], $attacking_ship);

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sector Missile Combat Start:</B></font><BR>
	Attacker " . $playerinfo['character_name'] . " (id: $playerinfo[player_id]) in sector $sectorinfo[name]<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Sensor Tech: $shipinfo[sensor], 
	 Cloak: $shipinfo[cloak]<br><br>
	Defender " . $targetinfo['character_name'] . " (id: $targetinfo[player_id])
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Total Energy: <B>" . NUMBER($targetship['energy']) . "</B>, 
	 Attack nergy: <B>" . NUMBER($sectormissile_attack_energy) . "</B>, 
	 Shields: <B>" . NUMBER($target_shield_energy) . "</B>, 
	 Armor Points: <B>" . NUMBER($targetarmor) . "</B><br>
	 Shield Tech: $targetinfo[shields], 
	 Armor Tech: $targetinfo[armor]");

$success = SCAN_SUCCESS($shipinfo['sensors'], $targetship['cloak']);

$template_object->assign("start_target_shields", (mt_rand(1, 100) > $success) ? 0 : NUMBER(SCAN_ERROR($shipinfo['sensors'], $targetship['ecm'], $target_shield_energy)));
$template_object->assign("start_target_armor", (mt_rand(1, 100) > $success) ? 0 : NUMBER(SCAN_ERROR($shipinfo['sensors'], $targetship['ecm'], $targetarmor)));

$isfedbounty = ship_bounty_check($playerinfo, $targetsector['sector_id'], $targetinfo, 1);
$template_object->assign("isfedbounty", $isfedbounty);
$template_object->assign("l_by_nofedbounty", $l_by_nofedbountyship);
$template_object->assign("l_by_fedbounty2", $l_by_fedbounty2);
$target_title = str_replace("[player]", $targetinfo['character_name'], str_replace("[ship]", $targetship['name'], $l_cmb_title_target_ship));
$getshipimage = $db->SelectLimit("SELECT image FROM {$db_prefix}ship_types WHERE type_id = $targetship[class]", 1);
$titleimage = $getshipimage->fields['image'];
$template_object->assign("titleimage", $titleimage);
$template_object->assign("target_title", $target_title);

$template_object->assign("l_cmb_target_shields", $l_cmb_target_shields);
$template_object->assign("l_cmb_target_armor", $l_cmb_target_armor);

$template_object->assign("l_cmb_sector_missile_exchange", $l_cmb_sector_missile_exchange);

$attacker_missile_result = array();

$used_attack_energy = 0;
$target_armor_died = 0;
$target_shields_died = 0;

$attackerlowpercent = ecmcheck($targetship['ecm'], $shipinfo['sensors'], -mt_rand($full_attack_modifier, 90));

if($sectormissile_attack_energy != 0)
{
	$target_shield_hit_pts = $target_shield_energy * $ship_shield_hit_pts;
	$target_armor_hit_pts = $targetarmor * $ship_armor_hit_pts;

	$attack_fire_failure = calc_failure($sectormissile_attack_energy, $targetshipshields);
	$sectormissile_attack_energy -= $attack_fire_failure[1];

	if($attack_fire_failure[2] > 0){
		$attacker_missile_result[] = $l_sm_sectormissilefail;
	}

	$attack_fire_damage = calc_damage($sectormissile_attack_energy, $sm_damage_shields, $attackerlowpercent, $targetshipshields, $targetshipshields, $target_shield_hit_pts);
	$used_attack_energy = $attack_fire_damage[3];

	$attacker_missile_result[] = str_replace("[units]", NUMBER($sectormissile_attack_energy), $l_cmb_attackSMunits);

	if($attack_fire_damage[0] > $target_shield_hit_pts)
	{
		if($target_shield_energy > 0)
		{
			$l_sm_shieldhit = str_replace("[target]", "<b>$targetname</b>", $l_sm_shieldhit);
			$l_sm_shieldhit = str_replace("[amount]", "<b>" . NUMBER($target_shield_energy) . "</b>", $l_sm_shieldhit);
			$attacker_missile_result[] = $l_sm_shieldhit;
		}
		$l_sm_shieldsdown = str_replace("[target]", "<b>$targetname</b>", $l_sm_shieldsdown);
		$attacker_missile_result[] = $l_sm_shieldsdown;
		$target_shields_died = $target_shield_energy;

		$attackerlowpercent = ecmcheck($targetship['ecm'], $shipinfo['sensors'], -mt_rand($full_attack_modifier, 90));
		$attack_fire2_failure = calc_failure($attack_fire_damage[4], $targetshiparmor);
		$attack_fire_damage[4] -= $attack_fire2_failure[1];

		if($attack_fire2_failure[2] > 0){
			$attacker_missile_result[] = $l_sm_sectormissilefail2;
		}

		$attacker_missile_result[] = str_replace("[units]", NUMBER($attack_fire_damage[4]), $l_cmb_attackSMarmorunits);

		$attack_fire2_damage[4] = calc_damage($attack_fire_damage[4], $sm_damage_all, $attackerlowpercent, $targetshiparmor, $targetshiparmor, $target_armor_hit_pts);
		$used_attack_energy += $attack_fire2_damage[3];

		if($attack_fire2_damage[0] > $target_armor_hit_pts)
		{
			$attack_damage = floor($target_armor_hit_pts / $ship_armor_hit_pts);
			if($attack_damage > 0)
			{
				$l_sm_armorhit = str_replace("[target]", "<b>$targetname</b>", $l_sm_armorhit);
				$l_sm_armorhit = str_replace("[amount]", "<b>" . NUMBER($attack_damage) . "</b>", $l_sm_armorhit);
				$attacker_missile_result[] = $l_sm_armorhit;
			}
			$attacker_missile_result[] = str_replace("[target]", "<b>$targetname</b>", $l_sm_armorbreached);
			$target_armor_died = $attack_damage;
		}
		else
		{
			$target_armor_hit_pts = $target_armor_hit_pts - $attack_fire2_damage[0];
			$target_armor_used = floor($attack_fire2_damage[0] / $ship_armor_hit_pts);
			$l_sm_armorhit = str_replace("[target]", "<b>$targetname</b>", $l_sm_armorhit);
			$attacker_missile_result[] = str_replace("[amount]", "<b>" . NUMBER($target_armor_used) . "</b>", $l_sm_armorhit);
			$target_armor_died = $target_armor_used;
		}
	}
	else
	{
		$target_shield_hit_pts = $target_shield_hit_pts - $attack_fire_damage[0];
		$target_shields_used = floor($attack_fire_damage[0] / $ship_shield_hit_pts);
		$l_sm_shieldhit = str_replace("[target]", "<b>$targetname</b>", $l_sm_shieldhit);
		$attacker_missile_result[] = str_replace("[amount]", "<b>" . NUMBER($target_shields_used) . "</b>", $l_sm_shieldhit);
		$target_shields_died = $target_shields_used;
	}
}
else
{
	$attacker_missile_result[] = $l_sm_targetnoenergy;
}

$template_object->assign("attacker_missile_result", $attacker_missile_result);

$target_armor_left = $targetarmor - $target_armor_died;
$target_shields_left -= $target_shields_died;
$used_attack_energy += $target_shields_died;

$template_object->assign("end_target_shields", (mt_rand(1, 100) > $success) ? 0 : NUMBER(SCAN_ERROR($shipinfo['sensors'], $targetship['ecm'], $target_shields_left)));
$template_object->assign("end_target_armor", (mt_rand(1, 100) > $success) ? 0 : NUMBER(SCAN_ERROR($shipinfo['sensors'], $targetship['ecm'], $target_armor_left)));

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Combat Sector Missile Combat End:</B></font><BR>Attacker " . $playerinfo['character_name'] . "<br>
	Defender ".$planet_owner['character_name'] . "
	 Shields: <B>" . NUMBER($target_shields_left) . "</B>, 
	 Armor Points: <B>" . NUMBER($target_armor_left) . "</B>");

$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts-$target_armor_died, 0), energy=GREATEST(energy-$used_attack_energy, 0) WHERE ship_id=$targetship[ship_id]");
db_op_result($debug_query,__LINE__,__FILE__);

update_player_experience($playerinfo['player_id'], $attacking_ship);

$target_exchange_result = array();

if ($target_armor_left < 1)
{
	//	target_died();
	update_player_experience($playerinfo['player_id'], $destroying_enemyship);
	$l_sm_destroyed = str_replace("[target]", "<b>" . $targetinfo['character_name'] . "</b>", $l_sm_destroyed);
	$target_exchange_result[] = $l_sm_destroyed;
	if ($targetshipdevice['dev_escapepod']['amount'] == 1)
	{
		$target_exchange_result[] = $l_sm_escapepod;
		player_ship_destroyed($targetship['ship_id'], $targetinfo['player_id'], $targetinfo['rating'], $playerinfo['player_id'], $playerinfo['rating'], "killedsectormissilepod");
		playerlog($targetinfo['player_id'], "LOG5_SM_LOSE", "$player_name|" . $targetshipdevice['dev_escapepod']['amount']);
	}
	else
	{
		$l_cmb_escapepod_failure=str_replace("[player]",$targetinfo['character_name'], $l_cmb_escapepod_failure);
		$target_exchange_result[] = $l_cmb_escapepod_failure;
		playerlog($targetinfo['player_id'], "LOG5_SM_LOSE", "$playerinfo[character_name]|" . $targetshipdevice['dev_escapepod']['amount']);
		db_kill_player($targetinfo['player_id'], $playerinfo['player_id'], $playerinfo['rating'], "killedsectormissile");
	}

	$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_sector_missile_attack);

	$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $targetship_old['hull']))+round(mypw($upgrade_factor, $targetship_old['engines']))+round(mypw($upgrade_factor, $targetship_old['power']))+round(mypw($upgrade_factor, $targetship_old['fighter']))+round(mypw($upgrade_factor, $targetship_old['sensors']))+round(mypw($upgrade_factor, $targetship_old['beams']))+round(mypw($upgrade_factor, $targetship_old['torp_launchers']))+round(mypw($upgrade_factor, $targetship_old['shields']))+round(mypw($upgrade_factor, $targetship_old['armor']))+round(mypw($upgrade_factor, $targetship_old['cloak']))+round(mypw($upgrade_factor, $targetship_old['ecm'])));
	$ship_salvage_rate = mt_rand(10,20);
	$ship_salvage=$ship_value*$ship_salvage_rate/100;

	$l_att_ysalv=str_replace("[ship_salvage_rate]", $ship_salvage_rate ,$l_att_ysalv);
	$l_att_ysalv=str_replace("[ship_salvage]", NUMBER($ship_salvage) ,$l_att_ysalv);
	$l_att_ysalv=str_replace("[rating_change]", NUMBER(abs($rating_change)) ,$l_att_ysalv);

	$target_exchange_result[] = $l_att_ysalv;

	adminlog("LOG0_ADMIN_COMBAT", "<font color=\"yellow\"><B>Sector Missile Salvage Values:</B></font><BR> Ship Value: " . NUMBER($ship_salvage) . " - $l_att_ysalv : upgrade_cost = $upgrade_cost, upgrade_factor = $upgrade_factor<br>");

	$debug_query = $db->Execute ("UPDATE {$db_prefix}players SET credits=credits+$ship_salvage, rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);

	$armor_lost=$targetship['armor_pts']-$target_armor_left;
	$energy_lost=$targetship['energy'] - $target_shields_left;

	$l_sm_lost = str_replace("[target]", "<b>$targetinfo[character_name]</b>", $l_sm_lost);
	$l_sm_lost = str_replace("[armor]", "<b>" . NUMBER($armor_lost) . "</b>", $l_sm_lost);
	$l_sm_lost = str_replace("[energy]", "<b>" . NUMBER($energy_lost) . "</b>", $l_sm_lost);
	$target_exchange_result[] = $l_sm_lost;
	playerlog($targetinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $playerinfo['character_name'], $l_cmb_combat_player) . $l_sm_lost);
}
else
{
	$l_sm_targetok=str_replace("[name]",$targetinfo['character_name'],$l_sm_targetok);
	$target_exchange_result[] = $l_sm_targetok;

	if($target_armor_left > 0 && $target_armor_left < $targetship['armor_pts'])
	{
		calc_internal_damage($targetship['ship_id'], 0, ($targetship['armor_pts']-$target_armor_left) / $targetship['armor_pts']);
		$result = $db->SelectLimit("SELECT hull, engines, power, fighter, sensors, beams, torp_launchers, shields, cloak, ecm, armor FROM {$db_prefix}ships WHERE ship_id='$targetship[ship_id]'", 1);
		$afteractionshiptech = $result->fields;
		$attacker_exchange_result[] = $l_cmb_attacker_lost_tech;

		$build_log_entry = $l_cmb_attacker_tech_drop;
		$build_log_entry=str_replace("[hull]","<font color=\"#00ff00\">". $targetship_old['hull'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[hull_new]","<font color=\"#ff0000\">". $afteractionshiptech['hull'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[engines]","<font color=\"#00ff00\">". $targetship_old['engines'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[engines_new]","<font color=\"#ff0000\">". $afteractionshiptech['engines'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[power]","<font color=\"#00ff00\">". $targetship_old['power'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[power_new]","<font color=\"#ff0000\">". $afteractionshiptech['power'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[fighter]","<font color=\"#00ff00\">". $targetship_old['fighter'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionshiptech['fighter'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[sensors]","<font color=\"#00ff00\">". $targetship_old['sensors'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionshiptech['sensors'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[beams]","<font color=\"#00ff00\">". $targetship_old['beams'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionshiptech['beams'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[torps]","<font color=\"#00ff00\">". $targetship_old['torp_launchers'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionshiptech['torp_launchers'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[shields]","<font color=\"#00ff00\">". $targetship_old['shields'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionshiptech['shields'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[cloak]","<font color=\"#00ff00\">". $targetship_old['cloak'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionshiptech['cloak'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[ecm]","<font color=\"#00ff00\">". $targetship_old['ecm'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[ecm_new]","<font color=\"#ff0000\">". $afteractionshiptech['ecm'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[armor]","<font color=\"#00ff00\">". $targetship_old['armor'] . "</font>",$build_log_entry);
		$build_log_entry=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionshiptech['armor'] . "</font>",$build_log_entry);
		playerlog($targetinfo['player_id'], "LOG5_AFTER_ACTION", $build_log_entry);
	}
	$armor_lost=$targetship['armor_pts'] - $target_armor_left;
	$energy_lost=$targetship['energy'] - $target_shields_left;
	playerlog($targetinfo['player_id'], "LOG5_SM_WIN", "$player_name|$armor_lost|$energy_lost");
	$l_sm_lost = str_replace("[target]", "<b>$targetinfo[character_name]</b>", $l_sm_lost);
	$l_sm_lost = str_replace("[armor]", "<b>" . NUMBER($armor_lost) . "</b>", $l_sm_lost);
	$l_sm_lost = str_replace("[energy]", "<b>" . NUMBER($energy_lost) . "</b>", $l_sm_lost);
	$target_exchange_result[] = $l_sm_lost;
	playerlog($targetinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $playerinfo['character_name'], $l_cmb_combat_player) . $l_sm_lost);

	$rating_change=get_rating_change($playerinfo['rating'], $targetinfo['rating'], $rating_attack_ship);
	$debug_query = $db->Execute ("UPDATE {$db_prefix}players SET turns=turns-1, turns_used=turns_used+1, rating=rating+$rating_change WHERE player_id=$playerinfo[player_id]");
	db_op_result($debug_query,__LINE__,__FILE__);
}

$template_object->assign("l_cmb_attack_exchange_results", $l_cmb_attack_exchange_results);
$template_object->assign("target_exchange_result", $target_exchange_result);

$template_object->assign("gotomain", $l_global_mmenu);
$template_object->display("master_template/sector_missile_exchange.tpl");

include ("footer.php");

?>
