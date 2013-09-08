<?php

include ("languages/$langdir/lang_combat.inc");
include ("globals/combat_functions.inc");
include ("globals/planet_bounty_check.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/send_system_im.inc");
include ("globals/planet_log.inc");
include ("globals/insert_news.inc");
include ("globals/get_rating_change.inc");
include ("globals/device_ship_tech_modify.inc");
include ("globals/display_this_planet.inc");
include ("globals/get_player.inc");

$shipinfo_old = $shipinfo;
$shipinfo = device_ship_tech_modify($shipinfo, $shipdevice);

$countplanet = 0;
display_this_planet($planetinfo);
$titleimage = $planetimg[0];
$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $ownerinfo, 0);
$template_object->assign("isfedbounty", $isfedbounty);
$template_object->assign("l_by_fedbounty2", $l_by_fedbounty2);
$template_object->assign("l_by_nofedbounty", $l_by_nofedbountyplanet);

$template_object->assign("titleimage", $titleimage);

$template_object->assign("planetname", $planetinfo['name']);
$template_object->assign("l_sofa", $l_sofa);

if ($sofa_on && $planetinfo['owner'] != 3)
{
	if($playerinfo[turns] < 1)
	{
		$template_object->assign("error_msg", $l_cmb_atleastoneturn);
		$template_object->assign("gotomain", $l_global_mmenu);
		$template_object->display("master_template/attackdie.tpl");
		include("footer.php");
		die();
	}
	if($shipinfo[fighters] < 1)
	{
		$template_object->assign("error_msg", $l_cmb_needfighters);
		$template_object->assign("gotomain", $l_global_mmenu);
		$template_object->display("master_template/attackdie.tpl");
		include("footer.php");
		die();
	}

	$attacker_exchange_result = array();
	$target_exchange_result = array();

	$res = $db->SelectLimit("SELECT last_login FROM {$db_prefix}players WHERE player_id = $ownerinfo[player_id]", 1);
	$last_login = $res->fields['last_login'];
	$res->close();
	send_system_im($ownerinfo['player_id'], $l_planet_imtitleattack, $playerinfo['character_name'] . " $l_planet_imsofa $planetinfo[name] $l_planet_iminsector $planetinfo[sector_name].", $last_login);

	update_player_experience($playerinfo['player_id'], $sofa_planet);

	$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $ownerinfo, 1);
	$template_object->assign("isfedbounty", $isfedbounty);
	$template_object->assign("l_by_fedbounty2", $l_by_fedbounty2);
	$template_object->assign("l_by_nofedbounty", $l_by_nofedbountyplanet);

	planet_log($planetinfo['planet_id'],$planetinfo['owner'],$playerinfo['player_id'],"PLOG_SOFA");

	$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['fighter'] / $max_tech_level))) : 0;
	$planet_comp_level = NUM_FIGHTERS($planetinfo['fighter'] + $base_factor);
	$figs = $planetinfo['fighters'];
	$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
	if ($res)  
	{
		while (!$res->EOF)  
		{
			$figs += $res->fields['fighters'];  
			$ship_comp =  NUM_FIGHTERS($res->fields['fighter']);  
			$planet_comp_level = $planet_comp_level + $ship_comp;  
			$res->MoveNext();  
		}
	}
	$res->close();

	if ($planet_comp_level > $figs)
	{
		$target_fighters_left = $figs;
	}
	else
	{
		$target_fighters_left = $planet_comp_level;
	}

	$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['torps'] / $max_tech_level))) : 0;
	$planet_comp_level = NUM_TORPEDOES($planetinfo['torps'] + $base_factor);
	$torps = $planetinfo['torps'];
	$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
	if ($res)  
	{
		while (!$res->EOF)  
		{
			$torps += $res->fields['torps'];  
			$ship_comp =  NUM_TORPEDOES($res->fields['torps']);  
			$planet_comp_level = $planet_comp_level + $ship_comp;  
			$res->MoveNext();  
		}
	}
	$res->close();

	if ($planet_comp_level > $torps)
	{
		$target_torps_left = $torps;
	}
	else
	{
		$target_torps_left = $planet_comp_level;
	}

	$target_shield_energy = floor($planetinfo['energy'] * 0.4);
	$target_beam_energy = $planetinfo['energy'] - $target_shield_energy;

	$base_factor = ($planetinfo['base'] == 'Y') ? round($basedefense * (1 - ($planetinfo['beams'] / $max_tech_level))) : 0;
	if ($planetinfo['beams'] == 0) 
	{
		$targetbeams = 0;
	}
	else
	{
		$targetbeams = NUM_BEAMS($planetinfo['beams'] + $base_factor);
	}

	$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
	while (!$res->EOF)
	{
		$targetbeams += NUM_BEAMS($res->fields['beams']);
		$res->MoveNext();
	}
	$res->close();

	if ($targetbeams < $target_beam_energy)
	{
		$target_beam_energy = $targetbeams;
	}

	$targetenergyset = $target_beam_energy;

	// get attacker beam, shield and armor values
	$attacker_shield_energy = floor($shipinfo['energy'] * 0.6);
	$attacker_beam_energy = $shipinfo['energy'] - $attacker_shield_energy;

	$attackershields = NUM_SHIELDS($shipinfo['shields']);

	if ($attackershields < $attacker_shield_energy)
	{
		$attacker_shield_energy = $attackershields;
	}

	$attackerbeams = NUM_BEAMS($shipinfo['beams']);

	if ($attackerbeams < $attacker_beam_energy)
	{
		$attacker_beam_energy = $attackerbeams;
	}

	$attackerenergyset = $attacker_beam_energy + $attacker_shield_energy;

	$attacker_armor_left = $shipinfo['armor_pts'];
	$attacker_torps_left = $shipinfo['torps'];
	$attacker_fighters_left = $shipinfo['fighters'];

	$attackerlowpercent = ecmcheck($planetinfo['sector_defense_cloak'], $shipinfo['sensors'] * 0.75, $full_attack_modifier);
	$targetlowpercent = ecmcheck($shipinfo['ecm'] * 0.75, $planetinfo['sensors'], -$full_attack_modifier);

	if(!class_exists($shipinfo['fighter_class']))
	{
		include ("class/" . $shipinfo['fighter_class'] . ".inc");
	}

	$attackobject = new $shipinfo['fighter_class']();
	$fighter_damage_all = $attackobject->fighter_damage_all;

	if(!class_exists($shipinfo['shield_class']))
	{
		include ("class/" . $shipinfo['shield_class'] . ".inc");
	}

	$attackobject = new $shipinfo['shield_class']();
	$ship_shield_hit_pts = $attackobject->ship_shield_hit_pts;

	if(!class_exists($shipinfo['armor_class']))
	{
		include ("class/" . $shipinfo['armor_class'] . ".inc");
	}

	$attackobject = new $shipinfo['armor_class']();
	$ship_armor_hit_pts = $attackobject->ship_armor_hit_pts;

	if(!class_exists($planetinfo['fighter_class']))
	{
		include ("class/planet/" . $planetinfo['fighter_class'] . ".inc");
	}

	$targetobject = new $planetinfo['fighter_class']();
	$fighter_hit_pts = $targetobject->hit_pts;

	if(!class_exists($planetinfo['beam_class']))
	{
		include ("class/planet/" . $planetinfo['beam_class'] . ".inc");
	}

	$targetobject = new $planetinfo['beam_class']();
	$beam_damage_all = $targetobject->damage_all;
	$beam_damage_shields = $targetobject->damage_shields;

	if(!class_exists($planetinfo['torp_class']))
	{
		include ("class/planet/" . $planetinfo['torp_class'] . ".inc");
	}

	$targetobject = new $planetinfo['torp_class']();
	$torp_hit_pts = $targetobject->hit_pts;

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sofa Bombing Combat Start:</B></font><BR>
	Attacker " . $playerinfo['character_name'] . " (id: $playerinfo[player_id]) in sector $sectorinfo[name]<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Beams:<B> " . NUMBER($attacker_beam_energy) . "</B>, 
	 Fighters: <B>" . NUMBER($attacker_fighters_left) . "</B>, 
	 Shields: <B>" . NUMBER($attacker_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>,
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	 Shield Tech: $shipinfo[shields], 
	 Armor Tech: $shipinfo[armor], 
	 Torp Tech: $shipinfo[torp_launchers], 
	 Beam Tech: $shipinfo[beams], 
	 Fighter Bay: $shipinfo[fighter]<br><br>
	Defender " . $planet_owner['character_name'] . " (id: $planet_owner[player_id]) on planet $planetinfo[name] (id: $planetinfo[planet_id])<br>
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Beams: <B>" . NUMBER($target_beam_energy) . "</B>, 
	 Fighters: <B>" . NUMBER($target_fighters_left) . "</B>, 
	 Shields: <B>" . NUMBER($target_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($target_torps_left) . "</B>. 
	 Armor Points: <B>" . NUMBER($planetinfo['armor_pts']) . "</B><br>
	 Shield Tech: $planetinfo[shields], 
	 Armor Tech: $planetinfo[armor], 
	 Torp Tech: $planetinfo[torp_launchers], 
	 Beam Tech: $planetinfo[beams], 
	 Fighter Bay: $planetinfo[fighter], 
	 Base Factor: $basedefense");

	$template_object->assign("start_target_beams", NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $target_beam_energy)));
	$template_object->assign("start_target_fighters", NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $target_fighters_left)));
	$template_object->assign("start_target_shields", NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $target_shield_energy)));
	$template_object->assign("start_target_torps", NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $target_torps_left)));
	$template_object->assign("start_target_armor", NUMBER(SCAN_ERROR($shipinfo['sensors'], $planetinfo['jammer'], $planetinfo['armor_pts'])));

	$template_object->assign("l_cmb_attacker_beams", $l_cmb_attacker_beams);
	$template_object->assign("l_cmb_attacker_fighters", $l_cmb_attacker_fighters);
	$template_object->assign("l_cmb_attacker_shields", $l_cmb_attacker_shields);
	$template_object->assign("l_cmb_attacker_torps", $l_cmb_attacker_torps);
	$template_object->assign("l_cmb_attacker_armor", $l_cmb_attacker_armor);
	$template_object->assign("l_cmb_target_beams", $l_cmb_target_beams);
	$template_object->assign("l_cmb_target_fighters", $l_cmb_target_fighters);
	$template_object->assign("l_cmb_target_shields", $l_cmb_target_shields);
	$template_object->assign("l_cmb_target_torps", $l_cmb_target_torps);
	$template_object->assign("l_cmb_target_armor", $l_cmb_target_armor);
	$template_object->assign("l_cmb_you", $l_cmb_you);

	$template_object->assign("start_attacker_beam_energy", NUMBER($attacker_beam_energy));
	$template_object->assign("start_attackerfighters", NUMBER($attacker_fighters_left));
	$template_object->assign("start_attacker_shield_energy", NUMBER($attacker_shield_energy));
	$template_object->assign("start_attackertorps", NUMBER($attacker_torps_left));
	$template_object->assign("start_attackerarmor", NUMBER($attacker_armor_left));

	//  Check to see if planet detects planet bombs.  Because of fast atmospheric entry ship cloak reduced by 60%
	$success = SCAN_SUCCESS($planetinfo['sensors'], floor($shipinfo['cloak'] * 0.6));

	$energy_lost = 0;
	$template_object->assign("is_fighter_echange", 0);

	//echo "$attackercloak $planetsensors $roll  $success<br>";
	if (mt_rand(1, 100) < $success)
	{
		$template_object->assign("is_fighter_echange", 2);
		// All of Beams Fire
//		echo "$target_beam_energy<hr>";
		$ddamageroll=mt_rand(1,25);
		if ($ddamageroll <= 2)
		{
			$target_beam_multiplier = 4;
			$target_exchange_result[] = $l_planet_beamfire3;
		}
		if ($ddamageroll > 2 && $ddamageroll <= 5)
		{
			$target_beam_multiplier = 3;
			$target_exchange_result[] = $l_planet_beamfire2;
		}
		if($ddamageroll > 5 and $ddamageroll <= 9)
		{
			$target_beam_multiplier = 2;
			$target_exchange_result[] = $l_planet_beamfire1;
		}
		if($ddamageroll > 9)
		{
			$target_beam_multiplier = 1;
			$target_exchange_result[] = $l_planet_beamfire4;
		}
		$target_beam_energy *= $target_beam_multiplier;
//		echo "$target_beam_energy<hr>";

		$template_object->assign("l_cmb_beam_exchange", $l_cmb_beam_exchange);

		$target_beams_died = 0; // $target_beam_energy
		$attacker_shields_died = 0;
		$attacker_armor_died = 0;

		if($target_beam_energy != 0)
		{
			$attack_shield_hit_pts = $attacker_shield_energy * $ship_shield_hit_pts;
			$attack_armor_hit_pts = $attacker_armor_left * $ship_armor_hit_pts;

			$target_fire_failure = calc_failure($target_beam_energy, $targetshipbeams);
			$target_beam_energy2 = $target_beam_energy - $target_fire_failure[1];

			$target_fire_damage = calc_damage($target_beam_energy2, $beam_damage_shields, $targetlowpercent, $targetshipbeams, $shipinfo['shields'], $attack_shield_hit_pts);
			$target_beams_died = $target_fire_damage[3];

			if($target_fire_failure[2] == 100)
			{
				$target_exchange_result[] = str_replace("[player]", $targetname, $l_cmb_enemybeamfailshield);
			}

			$target_exchange_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_beam_energy2), $l_cmb_targetbeamunits));

			if($target_fire_damage[0] > $attack_shield_hit_pts)
			{
				if($attacker_shield_energy > 0)
				{
					$target_exchange_result[] = str_replace("[damage]", NUMBER($attacker_shield_energy), $l_cmb_attacker_shields_hit);
				}
				$target_exchange_result[] = $l_cmb_attacker_shields_down;
				$attacker_shields_died = $attacker_shield_energy;

				$target_fire2_failure = calc_failure($target_fire_damage[4], $targetshipbeams);
				$target_fire_damage[4] -= $attack_fire2_failure[1];

				$target_fire2_damage = calc_damage($target_fire_damage[4], $beam_damage_all, $targetlowpercent, $targetshipbeams, $shipinfo['armor'], $attack_armor_hit_pts);
				$target_beams_died += $target_fire2_damage[3];

				if($target_fire2_failure[2] == 100)
				{
					$target_exchange_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_enemybeamfailarmor);
				}

				$target_exchange_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fire_damage[4]), $l_cmb_targetbeamunits));

				if($target_fire2_damage[0] > $attack_armor_hit_pts)
				{
					$attack_damage = floor($attack_armor_hit_pts / max(1,$ship_armor_hit_pts));
					if($attack_damage > 0)
					{
						$target_exchange_result[] = str_replace("[damage]", NUMBER($attack_damage), $l_cmb_attacker_armor_hit);
					}
					$target_exchange_result[] = $l_cmb_attacker_armor_down;
					$attacker_armor_died = $attack_damage;
				}
				else
				{
					$attack_armor_hit_pts = $attack_armor_hit_pts - $target_fire2_damage[0];
					$attacker_armor_used = floor($target_fire2_damage[0] / max(1,$ship_armor_hit_pts));
					$target_exchange_result[] = str_replace("[damage]", NUMBER($attacker_armor_used), $l_cmb_attacker_armor_hit);
					$attacker_armor_died = $attacker_armor_used;
				}
			}
			else
			{
				$attack_shield_hit_pts = $attack_shield_hit_pts - $target_fire_damage[0];
				$attacker_shields_used = floor($target_fire_damage[0] / max(1,$ship_shield_hit_pts));
				$target_exchange_result[] = str_replace("[damage]", NUMBER($attacker_shields_used), $l_cmb_attacker_shields_hit);
				$attacker_shields_died = $attacker_shields_used;
			}
		}
		else
		{
			$target_exchange_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_target_no_beams);
		}

		$attacker_armor_left -= $attacker_armor_died;
		$attacker_shields_left -= $attacker_shields_died;
		$used_target_beams = floor($target_beams_died / $target_beam_multiplier);

		$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts-$attacker_armor_died, 0), energy=GREATEST(energy-$attacker_shields_died, 0) WHERE ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET energy=GREATEST(energy-$used_target_beams, 0) WHERE planet_id=$planetinfo[planet_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		if($attacker_armor_left < 1 and $attacker_shields_left < 1)
		{
			$free_ore = round($shipinfo['ore']/2);
			$free_organics = round($shipinfo['organics']/2);
			$free_goods = round($shipinfo['goods']/2);
			$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $shipinfo['hull']))+round(mypw($upgrade_factor, $shipinfo['engines']))+round(mypw($upgrade_factor, $shipinfo['power']))+round(mypw($upgrade_factor, $shipinfo['fighter']))+round(mypw($upgrade_factor, $shipinfo['sensors']))+round(mypw($upgrade_factor, $shipinfo['beams']))+round(mypw($upgrade_factor, $shipinfo['torp_launchers']))+round(mypw($upgrade_factor, $shipinfo['shields']))+round(mypw($upgrade_factor, $shipinfo['armor']))+round(mypw($upgrade_factor, $shipinfo['cloak']))+round(mypw($upgrade_factor, $shipinfo['ecm'])));
			$ship_salvage_rate=mt_rand(0,10);
			$ship_salvage=$ship_value*($ship_salvage_rate/100);
			adminlog("LOG0_ADMIN_COMBAT", "<font color=\"yellow\"><B>Sofa Bombing Salvage Values:</B></font><BR> Ship Value: " . NUMBER($ship_salvage) . " - upgrade_cost = $upgrade_cost, upgrade_factor = $upgrade_factor<br>");
			$attacker_exchange_result[] = $l_cmb_attacker_ship_destroyed;

			if($shipdevice['dev_escapepod']['amount'] == 1) 
			{
				$shipid1=$shipinfo['ship_id'];
				$attacker_exchange_result[] = $l_cmb_escapepod_launched;
				player_ship_destroyed($shipid1, $playerinfo['player_id'], $playerinfo['rating'], 0, 0, "killedsofapod");
				$playernames = $playerinfo['character_name'];
				insert_news($playernames, 1, "pattackerpod");
			}
			else
			{
				$attacker_exchange_result[] = $l_cmb_attacker_escapepod_failure;
				db_kill_player($playerinfo['player_id'], 0, 0, "killedsofa");
				$playernames = $playerinfo['character_name'];
				insert_news($playernames, 1, "pattackerdied");
			}
		}
		else
		{
			$free_ore=0;
			$free_goods=0;
			$free_organics=0;
			$ship_salvage_rate=0;
			$ship_salvage=0;

			if($attacker_armor_left > 0 && $attacker_armor_left < $shipinfo['armor_pts'])
			{
				calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts']-$attacker_armor_left) / $shipinfo['armor_pts']);
				$result = $db->SelectLimit("SELECT hull, engines, power, fighter, sensors, beams, torp_launchers, shields, cloak, ecm, armor FROM {$db_prefix}ships WHERE ship_id='$shipinfo[ship_id]'", 1);
				$afteractionshiptech = $result->fields;
				$attacker_exchange_result[] = $l_cmb_attacker_lost_tech;

				$build_log_entry = $l_cmb_attacker_tech_drop;
				$build_log_entry=str_replace("[hull]","<font color=\"#00ff00\">". $shipinfo_old['hull'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[hull_new]","<font color=\"#ff0000\">". $afteractionshiptech['hull'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[engines]","<font color=\"#00ff00\">". $shipinfo_old['engines'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[engines_new]","<font color=\"#ff0000\">". $afteractionshiptech['engines'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[power]","<font color=\"#00ff00\">". $shipinfo_old['power'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[power_new]","<font color=\"#ff0000\">". $afteractionshiptech['power'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[fighter]","<font color=\"#00ff00\">". $shipinfo_old['fighter'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionshiptech['fighter'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sensors]","<font color=\"#00ff00\">". $shipinfo_old['sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionshiptech['sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[beams]","<font color=\"#00ff00\">". $shipinfo_old['beams'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionshiptech['beams'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[torps]","<font color=\"#00ff00\">". $shipinfo_old['torp_launchers'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionshiptech['torp_launchers'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[shields]","<font color=\"#00ff00\">". $shipinfo_old['shields'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionshiptech['shields'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[cloak]","<font color=\"#00ff00\">". $shipinfo_old['cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionshiptech['cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[ecm]","<font color=\"#00ff00\">". $shipinfo_old['ecm'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[ecm_new]","<font color=\"#ff0000\">". $afteractionshiptech['ecm'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[armor]","<font color=\"#00ff00\">". $shipinfo_old['armor'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionshiptech['armor'] . "</font>",$build_log_entry);
				playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", $build_log_entry);

				if($afteractionshiptech['hull'] < $shipinfo_old['hull'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[hull]","<font color=\"#00ff00\">". $shipinfo_old['hull'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[hull_new]","<font color=\"#ff0000\">". $afteractionshiptech['hull'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[hull]","<font color=\"#00ff00\">". $shipinfo_old['hull'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[hull_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['engines'] < $shipinfo_old['engines'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[engines]","<font color=\"#00ff00\">". $shipinfo_old['engines'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[engines_new]","<font color=\"#ff0000\">". $afteractionshiptech['engines'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[engines]","<font color=\"#00ff00\">". $shipinfo_old['engines'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[engines_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['power'] < $shipinfo_old['power'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[power]","<font color=\"#00ff00\">". $shipinfo_old['power'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[power_new]","<font color=\"#ff0000\">". $afteractionshiptech['power'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[power]","<font color=\"#00ff00\">". $shipinfo_old['power'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[power_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['fighter'] < $shipinfo_old['fighter'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[fighter]","<font color=\"#00ff00\">". $shipinfo_old['fighter'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionshiptech['fighter'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[fighter]","<font color=\"#00ff00\">". $shipinfo_old['fighter'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[fighter_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['sensors'] < $shipinfo_old['sensors'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[sensors]","<font color=\"#00ff00\">". $shipinfo_old['sensors'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionshiptech['sensors'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[sensors]","<font color=\"#00ff00\">". $shipinfo_old['sensors'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[sensors_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['beams'] < $shipinfo_old['beams'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[beams]","<font color=\"#00ff00\">". $shipinfo_old['beams'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionshiptech['beams'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[beams]","<font color=\"#00ff00\">". $shipinfo_old['beams'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[beams_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['torp_launchers'] < $shipinfo_old['torp_launchers'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[torps]","<font color=\"#00ff00\">". $shipinfo_old['torp_launchers'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionshiptech['torp_launchers'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[torps]","<font color=\"#00ff00\">". $shipinfo_old['torp_launchers'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[torps_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['shields'] < $shipinfo_old['shields'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[shields]","<font color=\"#00ff00\">". $shipinfo_old['shields'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionshiptech['shields'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[shields]","<font color=\"#00ff00\">". $shipinfo_old['shields'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[shields_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['cloak'] < $shipinfo_old['cloak'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[cloak]","<font color=\"#00ff00\">". $shipinfo_old['cloak'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionshiptech['cloak'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[cloak]","<font color=\"#00ff00\">". $shipinfo_old['cloak'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[cloak_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['ecm'] < $shipinfo_old['ecm'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[ecm]","<font color=\"#00ff00\">". $shipinfo_old['ecm'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[ecm_new]","<font color=\"#ff0000\">". $afteractionshiptech['ecm'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[ecm]","<font color=\"#00ff00\">". $shipinfo_old['ecm'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[ecm_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}

				if($afteractionshiptech['armor'] < $shipinfo_old['armor'])
				{
					$l_cmb_attacker_tech_drop=str_replace("[armor]","<font color=\"#00ff00\">". $shipinfo_old['armor'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionshiptech['armor'] . "</font>",$l_cmb_attacker_tech_drop);
				}
				else
				{
					$l_cmb_attacker_tech_drop=str_replace("[armor]","<font color=\"#00ff00\">". $shipinfo_old['armor'] . "</font>",$l_cmb_attacker_tech_drop);
					$l_cmb_attacker_tech_drop=str_replace("[armor_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
				}
				$attacker_exchange_result[] = $l_cmb_attacker_tech_drop;
			}
			$attacker_exchange_result[] = $l_cmb_you_survived_sofa_beams;
		}

		$rating_change=get_rating_change($playerinfo['rating'], $ownerinfo['rating'], $rating_SOFA_attack_planet, $ownerinfo['player_id']);
		$debug_query = $db->Execute("UPDATE {$db_prefix}players SET rating=rating+$rating_change, turns=turns-1, turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$l_cmb_attacker_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">". NUMBER($attacker_armor_died) . "</font>",$l_cmb_attacker_lost_list);
		$l_cmb_attacker_lost_list=str_replace("[fighterslost]","<font color=\"#ff0000\>0</font>",$l_cmb_attacker_lost_list);
		$l_cmb_attacker_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">". NUMBER($attacker_shields_died) . "</font>",$l_cmb_attacker_lost_list);
		$l_cmb_attacker_lost_list=str_replace("[torpslost]","<font color=\"#ff0000\">0</font>",$l_cmb_attacker_lost_list);
		$attacker_exchange_result[] = $l_cmb_attacker_lost_list;
		playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $targetinfo['character_name'], $l_cmb_combat_player) . $l_cmb_attacker_lost_list);

		$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET energy=GREATEST(energy-$attacker_shields_died, 0) WHERE ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$l_cmb_target_lost_list=str_replace("[player]","<font color=\"#ff0000\">". $planetinfo['name'] . "</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">0</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[fighterslost]","<font color=\"#ff0000\">0</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">". NUMBER($used_target_beams) . "</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[torpslost]","<font color=\"#ff0000\">0</font>",$l_cmb_target_lost_list);
		$target_exchange_result[] = $l_cmb_target_lost_list;
		playerlog($planetinfo['owner'], "LOG5_AFTER_ACTION", str_replace("[player]", $planetinfo['name'], $l_cmb_combat_player) . $l_cmb_target_lost_list);

		$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET energy=GREATEST(energy-$used_target_beams, 0) WHERE planet_id=$planetinfo[planet_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		playerlog($ownerinfo['player_id'], "LOG5_PLANET_BOMBED", "$planetinfo[name]|$shipinfo[sector_id]|$playerinfo[character_name]|$beamsused|$torps_lost|$fighters_lost");
		$template_object->assign("attacker_beam_result", $attacker_exchange_result);
		$template_object->assign("target_beam_result", $target_exchange_result);
	}
	else
	{
		$attacker_fighter_result = array();
		$target_fighter_result = array();
		$template_object->assign("l_cmb_fighter_exchange", $l_cmb_fighter_exchange);
		$template_object->assign("is_fighter_echange", 1);

		$attacker_fighters_died = 0;
		$attacker_torps_died = 0;
		$target_fighters_died = 0;
		$target_torps_died = 0;

		if($target_fighters_left != 0)
		{
			$attack_fighter_hit_pts = $attacker_fighters_left * $fighter_hit_pts;

			$target_fighter_failure = calc_failure($target_fighters_left, $targetshipfighter);
			$target_fighters_left2 = $target_fighters_left - $target_fighter_failure[1];

			$target_fighters_left = calc_damage($target_fighters_left2, $fighter_damage_all, $targetlowpercent, $targetshipfighter, $shipinfo['fighter'], $attack_fighter_hit_pts);

			if($target_fighter_failure[2] == 100)
			{
				$target_fighter_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_enemyfighterfailfighter);
			}
			$target_fighter_result[] = str_replace("[player]", $planetinfo['name'], str_replace("[units]", NUMBER($target_fighters_left2), $l_cmb_targetfighterunits));
		}

		if($attacker_fighters_left != 0)
		{
			$target_fighter_hit_pts = $target_fighters_left * $fighter_hit_pts;
			$target_torp_hit_pts = $target_torps_left * $torp_hit_pts;

			$attack_fighter_failure = calc_failure($attacker_fighters_left, $shipinfo['fighter']);
			$attacker_fighters_left2 = $attacker_fighters_left - $attack_fighter_failure[1];

			$attack_fighter_damage = calc_damage($attacker_fighters_left2, $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $targetshipfighter, $target_fighter_hit_pts);

			if($attack_fighter_failure[2] > 0)
			{
				$attacker_fighter_result[] = $l_cmb_yourfighterfail1;
				$attacker_fighter_result[] = str_replace("[percent]", (100 - $attack_fighter_failure[2]), $l_cmb_yourfighterfail2);
			}

			$attacker_fighter_result[] = str_replace("[units]", NUMBER($attacker_fighters_left2), $l_cmb_attackfighterunits);

			if($attack_fighter_damage[0] > $target_fighter_hit_pts)
			{
				if($target_fighters_left > 0)
				{
					$attacker_fighter_result[] = str_replace("[player]", $planetinfo['name'], str_replace("[fighterslost]", NUMBER($target_fighters_left), $l_cmb_target_fighters_lost));
				}
				$attacker_fighter_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_target_lost_all_fighters);

				$target_fighters_died = $target_fighters_left;

				$attack_fighter2_failure = calc_failure($attack_fighter_damage[4], $shipinfo['fighter']);
				$attack_fighter_damage[4] -= $attack_fighter2_failure[1];

				$attack_fighter2_damage = calc_damage($attack_fighter_damage[4], $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $targetshiptorp_launchers, $target_torp_hit_pts);

				if($attack_fighter2_failure[2] > 0)
				{
					$attacker_fighter_result[] = $l_cmb_yourfighterfail1;
					$attacker_fighter_result[] = str_replace("[percent]", (100 - $attack_fighter2_failure[2]), $l_cmb_yourfighterfail2);
				}

				$attacker_fighter_result[] = str_replace("[units]", NUMBER($attack_fighter_damage[4]), $l_cmb_attackfighterunits);

				if($attack_fighter2_damage[0] > $target_torp_hit_pts)
				{
					$attack_damage = floor($target_torp_hit_pts / $torp_hit_pts);
					if($attack_damage > 0)
					{
						$attacker_fighter_result[] = str_replace("[player]", $planetinfo['name'], str_replace("[torpslost]", NUMBER($attack_damage), $l_cmb_target_torps_lost));
					}
					$target_torps_died = $attack_damage;
					$attacker_fighter_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_target_lost_all_torps);
				}
				else
				{
					$target_torp_hit_pts = $target_torp_hit_pts - $attack_fighter2_damage[0];
					$target_torps_used = floor($attack_fighter2_damage[0] / $torp_hit_pts);
					$attacker_fighter_result[] = str_replace("[player]", $planetinfo['name'], str_replace("[torpslost]", NUMBER($target_torps_used), $l_cmb_target_torps_lost));
					$target_torps_died = $target_torps_used;
				}
			}
			else
			{
				$target_fighter_hit_pts = $target_fighter_hit_pts - $attack_fighter_damage[0];
				$target_fighters_used = floor($attack_fighter_damage[0] / $fighter_hit_pts);
				$attacker_fighter_result[] = str_replace("[player]", $planetinfo['name'], str_replace("[fighterslost]", NUMBER($target_fighters_used), $l_cmb_target_fighters_lost));
				$target_fighters_died = $target_fighters_used;
			}
		}
		else
		{
			$attacker_fighter_result[] = $l_cmb_attacker_no_fighters;
		}

		if($target_fighters_left != 0)
		{
			if(mt_rand(1, 100) <= $defender_lucky_percentage)
			{
				$target_fighter_damage[0] = $target_fighter_damage[0] * $defender_lucky_multiplier;
				$target_fighter_result[] = str_replace("[times]", $defender_lucky_multiplier, $l_cmb_target_surprise_fighters);
			}

			if($target_fighter_damage[0] > $attack_fighter_hit_pts)
			{
				if($attacker_fighters_left > 0)
				{
					$target_fighter_result[] = str_replace("[fighterslost]", NUMBER($attacker_fighters_left), $l_cmb_attacker_fighters_lost);
				}
				$target_fighter_result[] = $l_cmb_attacker_lost_all_fighters;
				$attacker_fighters_died = $attacker_fighters_left;
				$attack_torp_hit_pts = $attacker_torps_left * $torp_hit_pts;

				$target_fighter_failure = calc_failure($target_fighter_damage[4], $highfighter);
				$target_fighter_damage[4] -= $target_fighter_failure[1];

				$target_fighter2_damage = calc_damage($target_fighter_damage[4], $fighter_damage_all, $targetlowpercent, $highfighter, $shipinfo['torp_launchers'], $attack_torp_hit_pts);

				if($target_fighter_failure[2] == 100)
				{
					$target_fighter_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_enemyfighterfailtorp);
				}

				$target_fighter_result[] = str_replace("[player]", $planetinfo['name'], str_replace("[units]", NUMBER($target_fighter_damage[4]), $l_cmb_targetfighterunits));

				if($target_fighter2_damage[0] > $attack_torp_hit_pts)
				{
					$attack_damage = floor($attack_torp_hit_pts / $torp_hit_pts);
					if($attack_damage > 0)
					{
						$target_fighter_result[] = str_replace("[torpslost]", NUMBER($attack_damage), $l_cmb_attacker_torps_lost);
					}
					$target_fighter_result[] = $l_cmb_attacker_lost_all_torps;
					$attacker_torps_died = $attack_damage;
				}
				else
				{
					$attack_torp_hit_pts = $attack_torp_hit_pts - $target_fighter2_damage[0];
					$attack_torps_used = floor($target_fighter2_damage[0] / $torp_hit_pts);
					$target_fighter_result[] = str_replace("[torpslost]", NUMBER($attack_torps_used), $l_cmb_attacker_torps_lost);
					$attacker_torps_died = $attack_torps_used;
				}
			}
			else
			{
				$attack_fighter_hit_pts = $attack_fighter_hit_pts - $target_fighter_damage[0];
				$attack_fighters_used = floor($target_fighter_damage[0] / $fighter_hit_pts);
				$target_fighter_result[] = str_replace("[fighterslost]", NUMBER($attack_fighters_used), $l_cmb_attacker_fighters_lost);
				$attacker_fighters_died = $attack_fighters_used;
			}
		}
		else
		{
			$target_fighter_result[] = str_replace("[player]", $planetinfo['name'], $l_cmb_target_no_send_fighteres);
		}

		$attacker_fighters_left -= $attacker_fighters_died;
		$attacker_torps_left -= $attacker_torps_died;
		$target_fighters_left -= $target_fighters_died;
		$target_torps_left -= $target_torps_died;

		if($targetinfo['player_id'] <= 3)
		{
			$rating_SOFA_attack_planet = 0;
		}

		$rating_change=get_rating_change($playerinfo['rating'], $ownerinfo['rating'], $rating_SOFA_attack_planet, $ownerinfo['player_id']);
		$debug_query = $db->Execute("UPDATE {$db_prefix}players SET rating=rating+$rating_change, turns=turns-1, turns_used=turns_used+1 WHERE player_id=$playerinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$l_cmb_attacker_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">0</font>",$l_cmb_attacker_lost_list);
		$l_cmb_attacker_lost_list=str_replace("[fighterslost]","<font color=\"#ff0000\">". NUMBER($attacker_fighters_died) . "</font>",$l_cmb_attacker_lost_list);
		$l_cmb_attacker_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">0</font>",$l_cmb_attacker_lost_list);
		$l_cmb_attacker_lost_list=str_replace("[torpslost]","<font color=\"#ff0000\">" . NUMBER($attacker_torps_died) . "</font>",$l_cmb_attacker_lost_list);
		$attacker_fighter_result[] = $l_cmb_attacker_lost_list;
		playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $targetinfo['character_name'], $l_cmb_combat_player) . $l_cmb_attacker_lost_list);

		$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET fighters=GREATEST(fighters-$attacker_fighters_died, 0), torps=GREATEST(torps-$attacker_torps_died, 0) WHERE ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$l_cmb_target_lost_list=str_replace("[player]","<font color=\"#ff0000\">". $planetinfo['name'] . "</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">0</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[fighterslost]","<font color=\"#ff0000\">". NUMBER($target_fighters_died) . "</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">0</font>",$l_cmb_target_lost_list);
		$l_cmb_target_lost_list=str_replace("[torpslost]","<font color=\"#ff0000\">". NUMBER($target_torps_died) . "</font>",$l_cmb_target_lost_list);
		$target_fighter_result[] = $l_cmb_target_lost_list;
		playerlog($planetinfo['owner'], "LOG5_AFTER_ACTION", str_replace("[player]", $planetinfo['name'], $l_cmb_combat_player) . $l_cmb_target_lost_list);

		$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET fighters=GREATEST(fighters-$target_fighters_died, 0), torps=GREATEST(torps-$target_torps_died, 0) WHERE planet_id=$planetinfo[planet_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		playerlog($ownerinfo['player_id'], "LOG5_PLANET_BOMBED", "$planetinfo[name]|$shipinfo[sector_id]|$playerinfo[character_name]|$beamsused|$torps_lost|$fighters_lost");

		$template_object->assign("attacker_fighter_result", $attacker_fighter_result);
		$template_object->assign("target_fighter_result", $target_fighter_result);
	}

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sofa Bombing Combat End:</B></font><BR>Attacker " . $playerinfo['character_name'] . "
	 Fighters: <B>" . NUMBER($attacker_fighters_left)."</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>. 
	 Shields: <B>" . NUMBER($attacker_shields_left) . "</B>
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	Defender ".$planet_owner['character_name'] . "
	 Beams Used: <B>" . NUMBER($used_target_beams) ."</B>,
	 Fighters: <B>" . NUMBER($target_fighters_left) . "</B>,
	 Torpedoes: <B>" . NUMBER($target_torps_left) . "</B>");

	$template_object->assign("l_clickme", $l_clickme);
	$template_object->assign("l_toplanetmenu", $l_toplanetmenu);
	$template_object->assign("allow_ibank", $allow_ibank);
	$template_object->assign("planet_id", $planet_id);
	$template_object->assign("l_igb_term", $l_igb_term);
	$template_object->assign("l_ifyouneedplan", $l_ifyouneedplan);
	$template_object->assign("l_by_placebounty", $l_by_placebounty);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/planet_unowned/sofa_attack.tpl");
	include ("footer.php");
	die();
}
else
{
	$template_object->assign("l_command_no", $l_command_no);
	$template_object->assign("l_clickme", $l_clickme);
	$template_object->assign("l_toplanetmenu", $l_toplanetmenu);
	$template_object->assign("allow_ibank", $allow_ibank);
	$template_object->assign("planet_id", $planet_id);
	$template_object->assign("l_igb_term", $l_igb_term);
	$template_object->assign("l_ifyouneedplan", $l_ifyouneedplan);
	$template_object->assign("l_by_placebounty", $l_by_placebounty);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/planet_unowned/sofa_attack.tpl");
	include ("footer.php");
	die();
}

?>