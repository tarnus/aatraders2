<?php
include ("languages/$langdir/lang_bounty.inc");
include ("languages/$langdir/lang_combat.inc");
include ("languages/$langdir/lang_sector_fighters.inc");
include ("globals/planet_bounty_check.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/explode_mines.inc");
include ("globals/message_defense_owner.inc");
include ("globals/destroy_fighters.inc");
include ("globals/get_player.inc");

$template_object->assign("l_cmb_SD_attacking", str_replace("[sector]", $destination_name, $l_cmb_SD_fighters_attacking));

// get target beam, shield and armor values

$attacker_armor_left = $shipinfo['armor_pts'];
$attacker_torps_left = $shipinfo['torps'];
$attacker_fighters_left = $shipinfo['fighters'];

$target_torps_left = isset($defenses['mines']) ? $defenses['mines'] : 0;
$target_fighters_left = isset($defenses['fighters']) ? $defenses['fighters'] : 0;

$template_object->assign("l_cmb_attacker_fighters", $l_cmb_attacker_fighters);
$template_object->assign("l_cmb_attacker_torps", $l_cmb_attacker_torps);
$template_object->assign("l_cmb_attacker_armor", $l_cmb_attacker_armor);

$template_object->assign("l_cmb_target_fighters", $l_cmb_target_fighters);
$template_object->assign("l_cmb_target_mines", $l_cmb_target_mines);

$template_object->assign("start_attacker_fighters", NUMBER($attacker_fighters_left));
$template_object->assign("start_attacker_torps", NUMBER($attacker_torps_left));
$template_object->assign("start_attacker_armor", NUMBER($attacker_armor_left));
$template_object->assign("start_target_fighters", NUMBER($target_fighters_left));
$template_object->assign("start_target_mines", NUMBER($target_torps_left));
$template_object->assign("l_cmb_sector_defense", $l_cmb_sector_defense);

$has_fighters = 0;
$highjammer=0;
$highcloak = 0;
$highsensor = 0;
$highfighter = 0;
$hightorps = 0;
$high_player_id = 0;
$high_player_score = 0;
$fm_owner = 0;
$sector_playerrating = 0;

$energy_required = ROUND($target_fighters_left * $energy_per_fighter * 2);
$energy_available = 0;

$resultSDb = $db->Execute("SELECT * from {$db_prefix}sector_defense WHERE sector_id='$destination' and player_id != '$playerinfo[player_id]' and defense_type='fighters'");
db_op_result($resultSDb,__LINE__,__FILE__);

if ($resultSDb > 0)
{
	while (!$resultSDb->EOF)
	{
		$fm_owner = $resultSDb->fields['player_id'];
		$resultSDc = $db->Execute("SELECT * from {$db_prefix}players WHERE player_id='$fm_owner'");
		db_op_result($resultSDc,__LINE__,__FILE__);
		if ($resultSDc > 0)
		{
		   	$fighterowner= $resultSDc->fields['team'];
		   	$sector_playerrating = $resultSDc->fields['rating'];
		}

		if($high_player_score < $resultSDc->fields['score'])
		{
			$high_player_score = $resultSDc->fields['score'];
			$high_player_id = $resultSDc->fields['player_id'];
		}

		$result4 = $db->SelectLimit("SELECT sector_defense_cloak from {$db_prefix}planets where (owner=$fm_owner or (team > 0 and team=$fighterowner)) and base='Y' and sector_id='$destination' order by sector_defense_cloak DESC", 1);
		db_op_result($result4,__LINE__,__FILE__);
		$planets = $result4->fields;
		if ($highcloak < $planets['sector_defense_cloak'])
		{
			$highcloak=$planets['sector_defense_cloak'] + $basedefense;
		}
		$result4->close();

		$result4 = $db->SelectLimit("SELECT sector_defense_sensors from {$db_prefix}planets where (owner=$fm_owner or (team > 0 and team=$fighterowner)) and base='Y' and sector_id='$destination' order by sector_defense_sensors DESC", 1);
		db_op_result($result4,__LINE__,__FILE__);
		$planets = $result4->fields;
		if ($highsensor < $planets['sector_defense_sensors'])
		{
			$highsensor=$planets['sector_defense_sensors'] + $basedefense;
		}
		$result4->close();

		$result4 = $db->SelectLimit("SELECT sector_defense_weapons, owner from {$db_prefix}planets where (owner=$fm_owner or (team > 0 and team=$fighterowner)) and base='Y' and sector_id='$destination' order by sector_defense_weapons DESC", 1);
		db_op_result($result4,__LINE__,__FILE__);
		$planets = $result4->fields;
		if ($highfighter < $planets['sector_defense_weapons'])
		{
			$highfighter=$planets['sector_defense_weapons'] + $basedefense;
			$hightorps=$planets['sector_defense_weapons'] + $basedefense;
		}
		$result4->close();

		$resultSDb->MoveNext();
	}
	$res4 = $db->Execute("SELECT SUM(energy) as energy_available from {$db_prefix}planets where (owner = $fm_owner or (team = $fighterowner AND $fighterowner <> 0)) and sector_id = '$destination' and energy > 0 and base='Y'"); 
	$energy_available = $res4->fields['energy_available'];
}

$target_fighters_unused = 0;
if ($energy_available < $energy_required)
{
	$target_fighters_unused = $target_fighters_left - round($energy_available / ($energy_per_fighter * 2));
	$target_fighters_energy = round($energy_available / ($energy_per_fighter * 2));
	$energy_required = $energy_available;
}
else
{
	$target_fighters_energy = $target_fighters_left;
}

$attackerlowpercent = ecmcheck($highcloak, $shipinfo['sensors'], $full_attack_modifier);
$targetlowpercent = ecmcheck($shipinfo['ecm'], $highsensor, -$full_attack_modifier);

$targetshiptorp_launchers = $targetship['torp_launchers'];
$targetshipfighter = $targetship['fighter'];

$targetname = $destination_name . " " . $l_cmb_sector_defense;

if(!class_exists($shipinfo['fighter_class']))
{
	include ("class/" . $shipinfo['fighter_class'] . ".inc");
}

$attackobject = new $shipinfo['fighter_class']();
$fighter_damage_shields = $attackobject->fighter_damage_shields;
$fighter_damage_all = $attackobject->fighter_damage_all;
$fighter_hit_pts = $attackobject->fighter_hit_pts;

if(!class_exists($shipinfo['torp_class']))
{
	include ("class/" . $shipinfo['torp_class'] . ".inc");
}

$attackobject = new $shipinfo['torp_class']();
$torp_damage_shields = $attackobject->torp_damage_shields;
$torp_damage_all = $attackobject->torp_damage_all;
$torp_hit_pts = $attackobject->torp_hit_pts;

if(!class_exists($shipinfo['armor_class']))
{
	include ("class/" . $shipinfo['armor_class'] . ".inc");
}

$attackobject = new $shipinfo['armor_class']();
$ship_armor_hit_pts = $attackobject->ship_armor_hit_pts;

if(!class_exists("Ship_Fighter"))
{
	include ("class/Ship_Fighter.inc");
}

$targetobject = new Ship_Fighter();
$fighter_damage_shields = $targetobject->fighter_damage_shields;
$fighter_damage_all = $targetobject->fighter_damage_all;
$fighter_hit_pts = $targetobject->fighter_hit_pts;

if(!class_exists("Ship_Torpedo"))
{
	include ("class/Ship_Torpedo.inc");
}

$targetobject = new Ship_Torpedo();
$torp_damage_shields = $targetobject->torp_damage_shields;
$torp_damage_all = $targetobject->torp_damage_all;
$torp_hit_pts = $targetobject->torp_hit_pts;

$result5 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=". $high_player_id . "", 1);
db_op_result($result5,__LINE__,__FILE__);
$planet_owner = $result5->fields;

// If the attacker would get a bounty by attacking the most powerful planet in the sector then their A&R is useless.
$isfedbounty = planet_bounty_check($playerinfo, $destination, $planet_owner, 0);
if($isfedbounty > 0)
{
	$attacker_torps_left = 0;
	$attacker_fighters_left = 0;
}
$template_object->assign("isfedbounty", $isfedbounty);
$template_object->assign("l_by_nofedbounty", $l_by_nofedbountyplanet);
$template_object->assign("l_by_fedbounty2", $l_by_fedbounty2);

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sector Defense Fighter Combat Start:</B></font><BR>
	Attacker " . $playerinfo['character_name'] . " (id: $playerinfo[player_id]) in sector $destination_name<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Fighters: <B>" . NUMBER($attacker_fighters_left) . "</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>,
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	 Armor Tech: $shipinfo[armor], 
	 Torp Tech: $shipinfo[torp_launchers], 
	 Fighter Bay: $shipinfo[fighter]<br><br>
	Defender " . $planet_owner['character_name'] . " (id: $planet_owner[player_id])
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Sector Fighters: <B>" . NUMBER($target_fighters_left) . "</B>, 
	 Sector Mines: <B>" . NUMBER($target_torps_left) . "</B>. 
	 Sector Defense Weapons Tech: $hightorps, 
	 Sector Defense Sensor Tech: $highsensor, 
	 Sector Defense Cloak Bay: $highcloak, 
	 Base Factor: $basedefense");

// Stage 1 fighter to fighter, fighter to torp/mine Exchange
$template_object->assign("l_cmb_SD_fighterFighter_exchange", $l_cmb_SD_fighterFighter_exchange);

$attacker_fighters_died = 0;
$attacker_torps_died = 0;
$attacker_armor_used = 0;
$target_fighters_died = 0;
$target_torps_died = 0;

if($attacker_fighters_left != 0)
{
	$target_fighter_hit_pts = $target_fighters_left * $fighter_hit_pts;

	$attack_fighter_failure = calc_failure($attacker_fighters_left, $shipinfo['fighter']);
	$attacker_fighters_left2 = $attacker_fighters_left - $attack_fighter_failure[1];

	$attack_fighter_damage = calc_damage($attacker_fighters_left2, $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $highfighter, $target_fighter_hit_pts);

	if($attack_fighter_failure[2] > 0)
	{
		$attacker_fighter_result[] = $l_cmb_yourfighterfail1;
		$attacker_fighter_result[] = str_replace("[percent]", (100 - $attack_fighter_failure[2]), $l_cmb_yourfighterfail2);
	}

	$attacker_fighter_result[] = str_replace("[units]", NUMBER($attacker_fighters_left2), $l_cmb_attackfighterunits);
}

if($attacker_torps_left != 0)
{
	$target_fighter_hit_pts = $target_fighters_left * $fighter_hit_pts;

	$attack_torp_failure = calc_failure($attacker_torps_left, $shipinfo['torp_launchers']);
	$attacker_torps_left2 = $attacker_torps_left - $attack_torp_failure[1];

	$attack_torp_damage = calc_damage($attacker_torps_left2, $torp_damage_all, $attackerlowpercent, $shipinfo['torp_launchers'], $highfighter, $target_fighter_hit_pts);

	// Launched Ship Torpedoes destroy all of the Sector Defense fighters
	if($attack_torp_failure[2] > 0)
	{
		$attacker_torpmine_result[] = $l_cmb_yourtorpfail1;
		$attacker_torpmine_result[] = str_replace("[percent]", (100 - $attack_torp_failure[2]), $l_cmb_yourtorpfail2);
	}

	$attacker_torpmine_result[] = str_replace("[units]", NUMBER($attacker_torps_left2), $l_cmb_attacktorpunits);
}

if($target_fighters_left != 0)
{
	$attack_fighter_hit_pts = $attacker_fighters_left * $fighter_hit_pts;

	$target_fighter_failure = calc_failure($target_fighters_left, $highfighter);
	$target_fighters_left2 = $target_fighters_left - $target_fighter_failure[1];

	$target_fighter_damage = calc_damage($target_fighters_left2, $fighter_damage_all, $targetlowpercent, $highfighter, $shipinfo['fighter'], $attack_fighter_hit_pts);

	if($target_fighter_failure[2] == 100)
	{
		$target_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_enemyfighterfailfighter);
	}

	$target_fighter_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fighters_left2), $l_cmb_targetfighterunits));

	// Sector Defense Fighters destroy all of the launched ship fighters
	if($target_fighter_damage[0] > $attack_fighter_hit_pts)
	{
		if($attacker_fighters_left > 0)
		{
			$target_fighter_result[] = str_replace("[fighterslost]", NUMBER($attacker_fighters_left), $l_cmb_attacker_fighters_lost);
		}
		$target_fighter_result[] = $l_cmb_attacker_lost_all_fighters;
		$attacker_fighters_died = $attacker_fighters_left;
		$attack_torp_hit_pts = $attacker_torps_left * $torp_hit_pts;

		$target_fighter2_failure = calc_failure($target_fighter_damage[4], $highfighter);
		$target_fighter_damage[4] -= $target_fighter2_failure[1];

		$target_fighter2_damage = calc_damage($target_fighter_damage[4], $fighter_damage_all, $targetlowpercent, $highfighter, $shipinfo['torp_launchers'], $attack_torp_hit_pts);

		if($target_fighter2_failure[2] == 100)
		{
			$target_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_enemyfighterfailtorp);
		}

		$target_fighter_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fighter_damage[4]), $l_cmb_targetfighterunits));

		// Sector Defense Fighters destroy all of the launched ship torpedoes
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
			// Sector Defense Fighters destroy some of the launched ship torpedoes
			$attack_torp_hit_pts = $attack_torp_hit_pts - $target_fighter2_damage[0];
			$attack_torps_used = floor($target_fighter2_damage[0] / $torp_hit_pts);
			$target_fighter_result[] = str_replace("[torpslost]", NUMBER($attack_torps_used), $l_cmb_attacker_torps_lost);
			$attacker_torps_died = $attack_torps_used;
		}
	}
	else
	{
		// Sector Defense Fighters destroy some of the launched ship fighters and none of the ship torpedoes
		$attack_fighter_hit_pts = $attack_fighter_hit_pts - $target_fighter_damage[0];
		$attack_fighters_used = floor($target_fighter_damage[0] / $fighter_hit_pts);
		$target_fighter_result[] = str_replace("[fighterslost]", NUMBER($attack_fighters_used), $l_cmb_attacker_fighters_lost);
		$attacker_fighters_died = $attack_fighters_used;
	}
}
else
{
	// Sector Defense Fighters were not present
	$target_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_send_fighteres);
}

if($attacker_fighters_left != 0)
{
	// Launched Ship Fighters destroy all of the Sector Defense fighters
	if($attack_fighter_damage[0] > $target_fighter_hit_pts)
	{
		if($target_fighters_left > 0)
		{
			$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_left), $l_cmb_target_fighters_lost));
		}
		$attacker_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_fighters);

		$target_fighters_died = $target_fighters_left;
		$target_torp_hit_pts = $target_torps_left * $torp_hit_pts;

		$attack_fighter2_failure = calc_failure($attack_fighter_damage[4], $shipinfo['fighter']);
		$attack_fighter_damage[4] -= $attack_fighter2_failure[1];

		$attack_fighter2_damage = calc_damage($attack_fighter_damage[4], $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $hightorps, $target_torp_hit_pts);

		if($attack_fighter2_failure[2] > 0){
			$attacker_fighter_result[] = $l_cmb_yourfighterfail1;
			$attacker_fighter_result[] = str_replace("[percent]", (100 - $attack_fighter2_failure[2]), $l_cmb_yourfighterfail2);
		}

		$attacker_fighter_result[] = str_replace("[units]", NUMBER($attack_fighter_damage[4]), $l_cmb_attackfighterunits);

		// Launched Ship Fighters destroy all of the Sector Defense mines
		if($attack_fighter2_damage[0] > $target_torp_hit_pts)
		{
			$attack_damage = floor($target_torp_hit_pts / $torp_hit_pts);
			if($attack_damage > 0)
			{
				$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[torpslost]", NUMBER($attack_damage), $l_cmb_target_torps_lost));
			}
			$target_torps_died = $attack_damage;
			$attacker_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_torps);
		}
		else
		{
			// Launched Ship Fighters destroy some of the Sector Defense mines
			$target_torp_hit_pts = $target_torp_hit_pts - $attack_fighter2_damage[0];
			$target_torps_used = floor($attack_fighter2_damage[0] / $torp_hit_pts);
			$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[torpslost]", NUMBER($target_torps_used), $l_cmb_target_torps_lost));
			$target_torps_died = $target_torps_used;
		}
	}
	else
	{
		// Launched Ship Fighters destroy some of the Sector Defense fighters
		$target_fighter_hit_pts = $target_fighter_hit_pts - $attack_fighter_damage[0];
		$target_fighters_used = floor($attack_fighter_damage[0] / $fighter_hit_pts);
		$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_used), $l_cmb_target_fighters_lost));
		$target_fighters_died = $target_fighters_used;
	}
}
else
{
	// Ship never launched Ship Fighters
	$attacker_fighter_result[] = $l_cmb_attacker_no_fighters;
}

$attacker_fighters_left -= $attacker_fighters_died;
$attacker_torps_left -= $attacker_torps_died;
$target_fighters_left -= $target_fighters_died;
$target_torps_left -= $target_torps_died;

$template_object->assign("stage1_attacker_fighters", NUMBER($attacker_fighters_left));
$template_object->assign("stage1_attacker_torps", NUMBER($attacker_torps_left));
$template_object->assign("stage1_attacker_armor", NUMBER($attacker_armor_left));
$template_object->assign("stage1_target_fighters", NUMBER($target_fighters_left));
$template_object->assign("stage1_target_mines", NUMBER($target_torps_left));

$template_object->assign("attacker_fighter_result", $attacker_fighter_result);
$template_object->assign("target_fighter_result", $target_fighter_result);

$attacker_torpmine_result = array();

// Stage 2 ship torp to sector fighter Exchange
$template_object->assign("l_cmb_SD_torpFighter_exchange", $l_cmb_SD_torpFighter_exchange);

$attacker_fighters_died2 = 0;
$attacker_torps_died2 = 0;
$target_fighters_died2 = 0;
$target_torps_died2 = 0;

if($target_fighters_left != 0)
{
	if($attacker_torps_left != 0)
	{
		$target_fighter_hit_pts = $target_fighters_left * $fighter_hit_pts;

		$attack_torp_failure = calc_failure($attacker_torps_left, $shipinfo['torp_launchers']);
		$attacker_torps_left2 = $attacker_torps_left - $attack_torp_failure[1];

		$attack_torp_damage = calc_damage($attacker_torps_left2, $torp_damage_all, $attackerlowpercent, $shipinfo['torp_launchers'], $highfighter, $target_fighter_hit_pts);
		$attacker_torps_died2 = $attack_torp_damage[3];
		$attacker_torps_died += $attack_torp_damage[3];

		$attacker_torpmine_result[] = str_replace("[units]", NUMBER($attacker_torps_left2), $l_cmb_attacktorpunits);

		if($attack_torp_damage[0] > $target_fighter_hit_pts)
		{
			if($target_fighters_left > 0)
			{
				$attacker_torpmine_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_left), $l_cmb_target_fighters_lost));
			}
			$attacker_torpmine_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_fighters);
			$target_fighters_died2 = $target_fighters_left;
			$target_fighters_died += $target_fighters_left;
		}
		else
		{
			$target_fighter_hit_pts = $target_fighter_hit_pts - $attack_torp_damage[0];
			$target_fighters_used = floor($attack_torp_damage[0] / $fighter_hit_pts);
			$attacker_torpmine_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_used), $l_cmb_target_fighters_lost));
			$target_fighters_died2 = $target_fighters_used;
			$target_fighters_died += $target_fighters_used;
		}
	}
	else
	{
		$attacker_torpmine_result[] = $l_cmb_attacker_no_torps;
	}
}
else
{
	$attacker_torpmine_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_send_fighteres);
}

$attacker_fighters_left -= $attacker_fighters_died2;
$attacker_torps_left -= $attacker_torps_died2;
$target_fighters_left -= $target_fighters_died2;
$target_torps_left -= $target_torps_died2;

$template_object->assign("stage2_attacker_fighters", NUMBER($attacker_fighters_left));
$template_object->assign("stage2_attacker_torps", NUMBER($attacker_torps_left));
$template_object->assign("stage2_attacker_armor", NUMBER($attacker_armor_left));
$template_object->assign("stage2_target_fighters", NUMBER($target_fighters_left));
$template_object->assign("stage2_target_mines", NUMBER($target_torps_left));

$template_object->assign("attacker_torpmine_result", $attacker_torpmine_result);

// Stage 3 sector fighter to ship armor Exchange
$template_object->assign("l_cmb_SD_armor_exchange", $l_cmb_SD_armor_exchange);

$target_armor_result = array();

if($target_fighters_left != 0)
{
	// we reverse the attack and target tech this will kick in the confusion
	// calculation and cause the sector defense to miss.  The higher the ships engine the more the sector defense will miss.
	$attack_armor_hit_pts = $attacker_armor_left * $ship_armor_hit_pts;

	$target_fighter_failure = calc_failure($target_fighters_left, $shipinfo['engines']);
	$target_fighters_left2 = $target_fighters_left - $target_fighter_failure[1];

	$target_fighter_damage = calc_damage($target_fighters_left2, $fighter_damage_all, $targetlowpercent, $shipinfo['engines'], $highfighter, $attack_armor_hit_pts);

	if($target_fighter_failure[2] == 100)
	{
		$target_armor_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_send_fighteres);
	}

	$target_armor_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fighters_left2), $l_cmb_targetfighterunits));

	// Sector Defense Fighters destroy all of the Ship Armor
	if($target_fighter_damage[0] > $attack_armor_hit_pts)
	{
		if($attacker_armor_left > 0)
		{
			$target_armor_result[] = str_replace("[damage]", NUMBER($attacker_armor_left), $l_cmb_attacker_armor_hit);
		}
		$target_armor_result[] = $l_cmb_attacker_armor_down;
		$attacker_armor_used = $attacker_armor_left;
		$attacker_armor_left = 0;
	}
	else
	{
		// Sector Defense Fighters destroy some of the Ship Armor
		$attack_armor_hit_pts = $attack_armor_hit_pts - $target_fighter_damage[0];
		$attacker_armor_used = max(0, $attacker_armor_left - floor($attack_armor_hit_pts / $ship_armor_hit_pts));
		$attacker_armor_left -= $attacker_armor_used;
		$target_armor_result[] = str_replace("[damage]", NUMBER($attacker_armor_used), $l_cmb_attacker_armor_hit);
	}
}
else
{
	// Sector Defense Fighters were not present
	$target_armor_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_send_fighteres);
}

$template_object->assign("target_armor_result", $target_armor_result);

$template_object->assign("end_attacker_fighters", NUMBER($attacker_fighters_left));
$template_object->assign("end_attacker_torps", NUMBER($attacker_torps_left));
$template_object->assign("end_attacker_armor", NUMBER($attacker_armor_left));
$template_object->assign("end_target_fighters", NUMBER($target_fighters_left));
$template_object->assign("end_target_mines", NUMBER($target_torps_left));

$total_sector_mines_lost = $target_torps_died;
$fighterslost = $target_fighters_died;

$energy_required = ($fighterslost * $energy_per_fighter * 2) + round(($target_fighters_left) * ($energy_per_fighter * 0.01));

if ($energy_available < $energy_required)
{
	$energy_required = $energy_available;
}

$where = "";
$res2 = $db->Execute("SELECT planet_id from {$db_prefix}planets where (owner = $fm_owner or (team = $fighterowner AND $fighterowner <> 0)) and sector_id = $destination and energy > 0 and base='Y'"); 
while (!$res2->EOF)
{
	$where .= "planet_id=" . $res2->fields['planet_id'] . " or ";
	$res2->MoveNext();
}

if($where != "")
{
	$where .= "planet_id=-1";
	$debug_query = $db->Execute("UPDATE {$db_prefix}planets set energy = energy - " .
	                "GREATEST(ROUND($energy_required * (energy / $energy_available)),1)  where $where");
	db_op_result($debug_query,__LINE__,__FILE__);
}

$sector_check = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_id='$destination'", 1);

if($sector_check->RecordCount())
{
	$sect = $sector_check->fields;
	$sectorname = $sect['sector_name'];
}
$sector_check->close();

$inputtype[0] = "[player]";
$inputdata[0] = $playerinfo['character_name'];
$inputtype[1] = "[lost]";
$inputdata[1] = NUMBER($fighterslost);
$inputtype[2] = "[sector]";
$inputdata[2] = "<a href=main.php?move_method=real&engage=1&destination=$sectorname>$sectorname</a>";
message_defense_owner($destination, "l_cmb_SD_target_sendlog", "lang_combat.inc", "fighters", $inputtype, $inputdata);

destroy_fighters($destination,$fighterslost);
explode_mines($destination,$target_torps_died);

playerlog($playerinfo['player_id'], "LOG5_DEFS_DESTROYED_F", "$fighterslost|$destination");

if ($attacker_armor_left < 1)
{
	$attacker_exchange_result = array();
	$template_object->assign("l_cmb_attack_exchange_results", $l_cmb_attack_exchange_results);

	$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET fighters=GREATEST(fighters-$attacker_fighters_died, 0), armor_pts=GREATEST(armor_pts-$attacker_armor_used, 0), torps=GREATEST(torps-$attacker_torps_died, 0) WHERE ship_id=$shipinfo[ship_id]");
	db_op_result($debug_query,__LINE__,__FILE__);

	$l_cmb_attacker_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">". NUMBER($attacker_armor_used) . "</font>",$l_cmb_attacker_lost_list);
	$l_cmb_attacker_lost_list=str_replace("[fighterslost]","<font color=\"#ff0000\">". NUMBER($attacker_fighters_died) . "</font>",$l_cmb_attacker_lost_list);
	$l_cmb_attacker_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">0</font>",$l_cmb_attacker_lost_list);
	$l_cmb_attacker_lost_list=str_replace("[torpslost]","<font color=\"#ff0000\">". NUMBER($attacker_torps_died) . "</font>",$l_cmb_attacker_lost_list);
	$attacker_exchange_result[] = $l_cmb_attacker_lost_list;
	playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $targetname, $l_cmb_combat_player) . $l_cmb_attacker_lost_list);

	$template_object->assign("attacker_exchange_result", $attacker_exchange_result);

	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/sector_defense/fighter_attack.tpl");

	$template_object->assign("error_msg", $l_cmb_attacker_ship_destroyed);

	$inputtype[0] = "[player]";
	$inputdata[0] = $playerinfo['character_name'];
	$inputtype[1] = "[sector]";
	$inputdata[1] = "<a href=main.php?move_method=real&engage=1&destination=$sectorname>$sectorname</a>";
	message_defense_owner($sector, "l_cmb_SD_attacker_sendlog", "lang_combat.inc", "fighters", $inputtype, $inputdata);

	if ($shipdevice['dev_escapepod']['amount'] == 1) 
	{
		$template_object->assign("error_msg2", $l_cmb_escapepod_launched);
		playerlog($playerinfo['player_id'], "LOG5_DEFS_KABOOM", "$destination|1");
		player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], $planet_owner['player_id'], $planet_owner['rating'], "killedSDpod", "Y");
	}
	else
	{ 
		$template_object->assign("error_msg2", $l_cmb_attacker_escapepod_failure);
		playerlog($playerinfo['player_id'], "LOG5_DEFS_KABOOM", "$destination|0");
		db_kill_player($playerinfo['player_id'], $planet_owner['player_id'], $planet_owner['rating'], "killedSD", "Y");
	}
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/genericdie.tpl");
	include ("footer.php");
	die();
}

$attacker_exchange_result = array();
$template_object->assign("l_cmb_attack_exchange_results", $l_cmb_attack_exchange_results);

if($attacker_armor_left > 0 && $attacker_armor_left < $shipinfo['armor_pts'])
{
	calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts'] - $attacker_armor_left) / $shipinfo['armor_pts']);

	$result = $db->SelectLimit("SELECT hull, engines, power, fighter, sensors, beams, torp_launchers, shields, cloak, ecm, armor FROM {$db_prefix}ships WHERE ship_id='$shipinfo[ship_id]'", 1);
	$afteractionshiptech = $result->fields;
	$attacker_exchange_result[] = $l_cmb_attacker_lost_tech;

	$build_log_entry = $l_cmb_attacker_tech_drop;
	$build_log_entry=str_replace("[hull]","<font color=\"#00ff00\">". $shipinfo['hull'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[hull_new]","<font color=\"#ff0000\">". $afteractionshiptech['hull'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[engines]","<font color=\"#00ff00\">". $shipinfo['engines'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[engines_new]","<font color=\"#ff0000\">". $afteractionshiptech['engines'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[power]","<font color=\"#00ff00\">". $shipinfo['power'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[power_new]","<font color=\"#ff0000\">". $afteractionshiptech['power'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[fighter]","<font color=\"#00ff00\">". $shipinfo['fighter'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionshiptech['fighter'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[sensors]","<font color=\"#00ff00\">". $shipinfo['sensors'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionshiptech['sensors'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[beams]","<font color=\"#00ff00\">". $shipinfo['beams'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionshiptech['beams'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[torps]","<font color=\"#00ff00\">". $shipinfo['torp_launchers'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionshiptech['torp_launchers'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[shields]","<font color=\"#00ff00\">". $shipinfo['shields'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionshiptech['shields'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[cloak]","<font color=\"#00ff00\">". $shipinfo['cloak'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionshiptech['cloak'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[ecm]","<font color=\"#00ff00\">". $shipinfo['ecm'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[ecm_new]","<font color=\"#ff0000\">". $afteractionshiptech['ecm'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[armor]","<font color=\"#00ff00\">". $shipinfo['armor'] . "</font>",$build_log_entry);
	$build_log_entry=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionshiptech['armor'] . "</font>",$build_log_entry);
	playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", $build_log_entry);

	if($afteractionshiptech['hull'] < $shipinfo['hull'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[hull]","<font color=\"#00ff00\">". $shipinfo['hull'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[hull_new]","<font color=\"#ff0000\">". $afteractionshiptech['hull'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[hull]","<font color=\"#00ff00\">". $shipinfo['hull'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[hull_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['engines'] < $shipinfo['engines'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[engines]","<font color=\"#00ff00\">". $shipinfo['engines'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[engines_new]","<font color=\"#ff0000\">". $afteractionshiptech['engines'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[engines]","<font color=\"#00ff00\">". $shipinfo['engines'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[engines_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['power'] < $shipinfo['power'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[power]","<font color=\"#00ff00\">". $shipinfo['power'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[power_new]","<font color=\"#ff0000\">". $afteractionshiptech['power'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[power]","<font color=\"#00ff00\">". $shipinfo['power'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[power_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['fighter'] < $shipinfo['fighter'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[fighter]","<font color=\"#00ff00\">". $shipinfo['fighter'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionshiptech['fighter'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[fighter]","<font color=\"#00ff00\">". $shipinfo['fighter'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[fighter_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['sensors'] < $shipinfo['sensors'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[sensors]","<font color=\"#00ff00\">". $shipinfo['sensors'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionshiptech['sensors'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[sensors]","<font color=\"#00ff00\">". $shipinfo['sensors'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[sensors_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['beams'] < $shipinfo['beams'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[beams]","<font color=\"#00ff00\">". $shipinfo['beams'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionshiptech['beams'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[beams]","<font color=\"#00ff00\">". $shipinfo['beams'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[beams_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['torp_launchers'] < $shipinfo['torp_launchers'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[torps]","<font color=\"#00ff00\">". $shipinfo['torp_launchers'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionshiptech['torp_launchers'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[torps]","<font color=\"#00ff00\">". $shipinfo['torp_launchers'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[torps_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['shields'] < $shipinfo['shields'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[shields]","<font color=\"#00ff00\">". $shipinfo['shields'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionshiptech['shields'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[shields]","<font color=\"#00ff00\">". $shipinfo['shields'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[shields_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['cloak'] < $shipinfo['cloak'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[cloak]","<font color=\"#00ff00\">". $shipinfo['cloak'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionshiptech['cloak'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[cloak]","<font color=\"#00ff00\">". $shipinfo['cloak'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[cloak_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['ecm'] < $shipinfo['ecm'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[ecm]","<font color=\"#00ff00\">". $shipinfo['ecm'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[ecm_new]","<font color=\"#ff0000\">". $afteractionshiptech['ecm'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[ecm]","<font color=\"#00ff00\">". $shipinfo['ecm'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[ecm_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	if($afteractionshiptech['armor'] < $shipinfo['armor'])
	{
		$l_cmb_attacker_tech_drop=str_replace("[armor]","<font color=\"#00ff00\">". $shipinfo['armor'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionshiptech['armor'] . "</font>",$l_cmb_attacker_tech_drop);
	}
	else
	{
		$l_cmb_attacker_tech_drop=str_replace("[armor]","<font color=\"#00ff00\">". $shipinfo['armor'] . "</font>",$l_cmb_attacker_tech_drop);
		$l_cmb_attacker_tech_drop=str_replace("[armor_new]","<font color=\"#ff0000\">". $l_none . "</font>",$l_cmb_attacker_tech_drop);
	}

	$attacker_exchange_result[] = $l_cmb_attacker_tech_drop;
}

$debug_query = $db->Execute ("UPDATE {$db_prefix}ships SET fighters=GREATEST(fighters-$attacker_fighters_died, 0), armor_pts=GREATEST(armor_pts-$attacker_armor_used, 0), torps=GREATEST(torps-$attacker_torps_died, 0) WHERE ship_id=$shipinfo[ship_id]");
db_op_result($debug_query,__LINE__,__FILE__);

$l_cmb_attacker_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">". NUMBER($attacker_armor_used) . "</font>",$l_cmb_attacker_lost_list);
$l_cmb_attacker_lost_list=str_replace("[fighterslost]","<font color=\"#ff0000\">". NUMBER($attacker_fighters_died) . "</font>",$l_cmb_attacker_lost_list);
$l_cmb_attacker_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">0</font>",$l_cmb_attacker_lost_list);
$l_cmb_attacker_lost_list=str_replace("[torpslost]","<font color=\"#ff0000\">". NUMBER($attacker_torps_died) . "</font>",$l_cmb_attacker_lost_list);
$attacker_exchange_result[] = $l_cmb_attacker_lost_list;
playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $targetname, $l_cmb_combat_player) . $l_cmb_attacker_lost_list);

$template_object->assign("attacker_exchange_result", $attacker_exchange_result);

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sector Defense Fighter Combat End:</B></font><BR>Attacker " . $playerinfo['character_name'] . "
	 Fighters: <B>" . NUMBER($attacker_fighters_left)."</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>. 
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	Defender ".$planet_owner['character_name'] . "
	 Fighters: <B>" . NUMBER($target_fighters_left) . "</B>,
	 Mines: <B>" . NUMBER($target_torps_left) . "</B>");

$template_object->assign("gotomain", $l_global_mmenu);
$template_object->display("master_template/sector_defense/fighter_attack.tpl");
$sector_combat = 1;
?>
