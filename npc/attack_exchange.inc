<?php
// This program is free software; you can redistribute it and/or modify it   
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: attack_exchange.inc

// Order of attack results in a foreach array
// $attacker_beam_result array
// $target_beam_result array
// $attacker_fighter_result array
// $target_fighter_result array
// $attacker_torp_result array
// $target_torp_result array

if (preg_match("/attack_exchange.inc/i", $_SERVER['PHP_SELF'])) 
{ 
		 echo "You can not access this file directly!"; 
		 die(); 
} 
include ("globals/get_player.inc");

if($attacktype == "planet")
{
	$success = SCAN_SUCCESS($shipinfo['sensors'], $planetinfo['cloak']);

 

	//$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $ownerinfo, 1);
	$target_title = str_replace("[player]", $ownerinfo['character_name'], str_replace("[planet]", $planetinfo['name'], $l_cmb_title_target_planet));
	include ("globals/display_this_planet.inc");
	$countplanet = 0;
	display_this_planet($planetinfo);
	$titleimage = $planetimg[0];
	 

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>" .  ucfirst($attacktype) . " Combat Start:</B></font><BR>
	Attacker " . $playerinfo['character_name'] . " (id: $playerinfo[player_id]) in sector $sectorinfo[name]<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Beams:<B> " . NUMBER($attacker_beam_energy + $attack_beamtofighter_dmg + $attack_beamtotorp_dmg) . "</B>, 
	 Fighters: <B>" . NUMBER($attacker_fighters_left) . "</B>, 
	 Shields: <B>" . NUMBER($attacker_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>,
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	 Shield Tech: $shipinfo[shields], 
	 Armor Tech: $shipinfo[armor], 
	 Torp Tech: $shipinfo[torp_launchers], 
	 Beam Tech: $shipinfo[beams], 
	 Fighter Bay: $shipinfo[fighter]<br><br>
	Defender " . $ownerinfo['character_name'] . " (id: $ownerinfo[player_id]) on planet $planetinfo[name] (id: $planetinfo[planet_id])<br>
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Beams: <B>" . NUMBER($target_beam_energy) . "</B>, 
	 Fighters: <B>" . NUMBER($target_fighters_left) . "</B>, 
	 Shields: <B>" . NUMBER($target_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($target_torps_left) . "</B>. 
	 Armor Points: <B>" . NUMBER($target_armor_left) . "</B><br>
	 Shield Tech: $planetinfo[shields], 
	 Armor Tech: $planetinfo[armor], 
	 Torp Tech: $planetinfo[torp_launchers], 
	 Beam Tech: $planetinfo[beams], 
	 Fighter Bay: $planetinfo[fighter], 
	 Base Factor: $basedefense");
}
else
{
	$success = SCAN_SUCCESS($shipinfo['sensors'], $targetship['cloak']);

 

	//$isfedbounty = ship_bounty_check($playerinfo, $shipinfo['sector_id'], $targetinfo, 1);
	$target_title = str_replace("[player]", $targetinfo['character_name'], str_replace("[ship]", $targetship['name'], $l_cmb_title_target_ship));
	$getshipimage = $db->SelectLimit("SELECT image FROM {$db_prefix}ship_types WHERE type_id = $targetship[class]", 1);
	$titleimage = $getshipimage->fields['image'];
 

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>" .  ucfirst($attacktype) . " Combat Start:</B></font><BR>
	Attacker " . $playerinfo['character_name'] . " (id: $playerinfo[player_id]) in sector $sectorinfo[name]<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Beams:<B> " . NUMBER($attacker_beam_energy + $attack_beamtofighter_dmg + $attack_beamtotorp_dmg) . "</B>, 
	 Fighters: <B>" . NUMBER($attacker_fighters_left) . "</B>, 
	 Shields: <B>" . NUMBER($attacker_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>,
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	 Shield Tech: $shipinfo[shields], 
	 Armor Tech: $shipinfo[armor], 
	 Torp Tech: $shipinfo[torp_launchers], 
	 Beam Tech: $shipinfo[beams], 
	 Fighter Bay: $shipinfo[fighter]<br><br>
	Defender " . $targetinfo['character_name'] . " (id: $targetinfo[player_id])
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Beams: <B>" . NUMBER($target_beam_energy + $target_beamtofighter_dmg + $target_beamtotorp_dmg) . "</B>, 
	 Fighters: <B>" . NUMBER($target_fighters_left) . "</B>, 
	 Shields: <B>" . NUMBER($target_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($target_torps_left) . "</B>. 
	 Armor Points: <B>" . NUMBER($target_armor_left) . "</B><br>
	 Shield Tech: $targetship[shields], 
	 Armor Tech: $targetship[armor], 
	 Torp Tech: $targetship[torp_launchers], 
	 Beam Tech: $targetship[beams], 
	 Fighter Bay: $targetship[fighter]");
}

 

adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>" .  ucfirst($attacktype) . " Combat Class Values:</B></font><BR>fighter_damage_shields:<B> " . NUMBER($fighter_damage_shields) .
"</B><BR>fighter_damage_all: <B>" . NUMBER($fighter_damage_all) . "</B><BR>fighter_hit_pts: <B>" . NUMBER($fighter_hit_pts) . "</B><BR>beam_damage_shields: <B>" . NUMBER($beam_damage_shields) . "</B><BR>beam_damage_all: <B>" . NUMBER($beam_damage_all) . "</B>
<br>torp_damage_shields: <B>" . NUMBER($torp_damage_shields) . "</B><BR>torp_damage_all: <B>" . NUMBER($torp_damage_all) . "</B><BR>torp_hit_pts: <B>" . NUMBER($torp_hit_pts) . "</B><BR>ship_shield_hit_pts: <B>" . NUMBER($ship_shield_hit_pts) . "</B><BR>ship_armor_hit_pts: <B>" . NUMBER($ship_armor_hit_pts) . "</B>");

 

$attack_fighters_died = 0; // $attacker_fighters_left
$attack_torps_died = 0; // $attacker_torps_left
$attack_beams_died = 0; // $attacker_beam_energy + $attack_beamtofighter_dmg + $attack_beamtotorp_dmg
$attack_shields_died = 0; // $attacker_shield_energy
$attack_armor_died = 0; // $attacker_armor_left
$target_fighters_died = 0; // $target_fighters_left
$target_torps_died = 0; // $target_torps_left
$target_beams_died = 0; // $target_beam_energy
$target_shields_died = 0; // $target_shield_energy
$target_armor_died = 0; // $target_armor_left

$attacker_beam_result = array();

if($attacker_beam_energy != 0)
{
	$target_shield_hit_pts = $target_shield_energy * $ship_shield_hit_pts;
	$target_armor_hit_pts = $target_armor_left * $ship_armor_hit_pts;
//echo "beams: " . NUMBER($attacker_beam_energy) . "<br>";
	$attack_fire_failure = calc_failure($attacker_beam_energy, $shipinfo['beams']);
	$attacker_beam_energy2 = $attacker_beam_energy - $attack_fire_failure[1];
//echo "beams: " . NUMBER($attacker_beam_energy) . "<br>";
//echo "failure: " . NUMBER($attack_fire_failure[1]) . "<br>";

	$attack_fire_damage = calc_damage($attacker_beam_energy2, $beam_damage_shields, $attackerlowpercent, $shipinfo['beams'], $targetshipshields, $target_shield_hit_pts);
	$attack_beams_died = $attack_fire_damage[3];
//echo "used: " . NUMBER($attack_fire_damage[3]) . "<br>";

	if($attack_fire_failure[2] > 0){
		$attacker_beam_result[] = $l_cmb_yourbeamfail1;
		$attacker_beam_result[] = str_replace("[percent]", (100 - $attack_fire_failure[2]), $l_cmb_yourbeamfail2);
	}

	$attacker_beam_result[] = str_replace("[units]", NUMBER($attacker_beam_energy2), $l_cmb_attackbeamunits);

	if($attack_fire_damage[0] > $target_shield_hit_pts)
	{
		if($target_shield_energy > 0)
		{
			$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($target_shield_energy), $l_cmb_target_shields_hit));
		}
		$attacker_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_shields_down);
		$target_shields_died = $target_shield_energy;

		$attack_fire2_failure = calc_failure($attack_fire_damage[4], $shipinfo['beams']);
		$attack_fire_damage[4] -= $attack_fire2_failure[1];

		$attack_fire2_damage = calc_damage($attack_fire_damage[4], $beam_damage_all, $attackerlowpercent, $shipinfo['beams'], $targetshiparmor, $target_armor_hit_pts);
		$attack_beams_died += $attack_fire2_damage[3];
//
		if($attack_fire2_failure[2] > 0){
			$attacker_beam_result[] = $l_cmb_yourbeamfail1;
			$attacker_beam_result[] = str_replace("[percent]", (100 - $attack_fire2_failure[2]), $l_cmb_yourbeamfail2);
		}

		$attacker_beam_result[] = str_replace("[units]", NUMBER($attack_fire_damage[4]), $l_cmb_attackbeamunits);

		if($attack_fire2_damage[0] > $target_armor_hit_pts)
		{
			$attack_fire2_damage[0] = $attack_fire2_damage[0] - $target_armor_hit_pts;
			$attack_damage = floor($target_armor_hit_pts / $ship_armor_hit_pts);
			if($attack_damage > 0)
			{
				$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($attack_damage), $l_cmb_target_armor_hit) . "testing 1");
			}
			$attacker_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_armor_down);
			$target_armor_died = $attack_damage;
		}
		else
		{
			$target_armor_hit_pts = $target_armor_hit_pts - $attack_fire2_damage[0];
			$target_armor_used = floor($attack_fire2_damage[0] / $ship_armor_hit_pts);
			$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($target_armor_used), $l_cmb_target_armor_hit) . "testing 2");
			$target_armor_died = $target_armor_used;
		}
	}
	else
	{
		$target_shield_hit_pts = $target_shield_hit_pts - $attack_fire_damage[0];
		$target_shields_used = floor($attack_fire_damage[0] / $ship_shield_hit_pts);
		$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($target_shields_used), $l_cmb_target_shields_hit));
		$target_shields_died = $target_shields_used;
	}
}
else
{
	$attacker_beam_result[] = $l_cmb_attacker_no_beams;
}

//echo "beams died: " . NUMBER($attack_beams_died) . "<hr>";

if($attack_beamtofighter_dmg != 0)
{
	$target_fighter_hit_pts = $target_fighters_left * $fighter_hit_pts;

	$attack_fighter_failure = calc_failure($attack_beamtofighter_dmg, $shipinfo['beams']);
	$attack_beamtofighter_dmg2 = $attack_beamtofighter_dmg - $attack_fighter_failure[1];

	$attack_fighter_damage = calc_damage($attack_beamtofighter_dmg2, $beam_damage_all, $attackerlowpercent, $shipinfo['beams'], $targetshipfighter, $target_fighter_hit_pts);
	$attack_beams_died += $attack_fighter_damage[3];

	if($attack_fighter_failure[2] > 0){
		$attacker_beam_result[] = $l_cmb_yourbeamfail1;
		$attacker_beam_result[] = str_replace("[percent]", (100 - $attack_fighter_failure[2]), $l_cmb_yourbeamfail2);
	}

	$attacker_beam_result[] = str_replace("[units]", NUMBER($attack_beamtofighter_dmg2), $l_cmb_attackbeamunits);

	if($attack_fighter_damage[0] > $target_fighter_hit_pts)
	{
		if($target_fighters_left > 0)
		{
			$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_left), $l_cmb_target_fighters_lost));
		}
		$target_fighters_died = $target_fighters_left;
		$attacker_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_fighters);
	}
	else
	{
		$target_fighter_hit_pts = $target_fighter_hit_pts - $attack_fighter_damage[0];
		$target_fighters_used = floor($attack_fighter_damage[0] / $fighter_hit_pts);
		$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_used), $l_cmb_target_fighters_lost));
		$target_fighters_died = $target_fighters_used;
	}
}
else
{
	$attacker_beam_result[] = $l_cmb_attacker_no_beams;
}

//echo "beams died: " . NUMBER($attack_beams_died) . "<hr>";

if($attack_beamtotorp_dmg != 0)
{
	$target_torp_hit_pts = $target_torps_left * $torp_hit_pts;

	$attack_torp_failure = calc_failure($attack_beamtotorp_dmg, $shipinfo['beams']);
	$attack_beamtotorp_dmg2 = $attack_beamtotorp_dmg - $attack_torp_failure[1];

	$attack_torp_damage = calc_damage($attack_beamtotorp_dmg2, $beam_damage_all, $attackerlowpercent, $shipinfo['beams'], $targetshiptorp_launchers, $target_torp_hit_pts);
	$attack_beams_died += $attack_torp_damage[3];

	if($attack_torp_failure[2] > 0){
		$attacker_beam_result[] = $l_cmb_yourbeamfail1;
		$attacker_beam_result[] = str_replace("[percent]", (100 - $attack_torp_failure[2]), $l_cmb_yourbeamfail2);
	}

	$attacker_beam_result[] = str_replace("[units]", NUMBER($attack_beamtotorp_dmg2), $l_cmb_attackbeamunits);

	if($attack_torp_damage[0] > $target_torp_hit_pts)
	{
		if($target_torps_left > 0)
		{
			$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[torpslost]", NUMBER($target_torps_left), $l_cmb_target_torps_lost));
		}
		$target_torps_died = $target_torps_left;
		$attacker_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_torps);
	}
	else
	{
		$target_torp_hit_pts = $target_torp_hit_pts - $attack_torp_damage[0];
		$target_torps_used = floor($attack_torp_damage[0] / $torp_hit_pts);
		$attacker_beam_result[] = str_replace("[player]", $targetname, str_replace("[torpslost]", NUMBER($target_torps_used), $l_cmb_target_torps_lost));
		$target_torps_died = $target_torps_used;
	}
}
else
{
	$attacker_beam_result[] = $l_cmb_attacker_no_beams;
}

//echo "beams died: " . NUMBER($attack_beams_died) . "<hr>";

$target_torps_left -= $target_torps_died;
$target_fighters_left -= $target_fighters_died;
$target_shield_energy -= $target_shields_died;
$target_armor_left -= $target_beams_died;

$attacker_beam_energy = $attacker_beam_energy + $attack_beamtofighter_dmg + $attack_beamtotorp_dmg;
$attacker_beam_energy -= $attack_beams_died;

 

$target_beam_result = array();

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
		$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_enemybeamfailshield);
	}

	$target_beam_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_beam_energy2), $l_cmb_targetbeamunits));

	if(mt_rand(1, 100) <= $defender_lucky_percentage)
	{
		$target_fire_damage[0] = $target_fire_damage[0] * $defender_lucky_multiplier;
		$target_beam_result[] = str_replace("[times]", $defender_lucky_multiplier, $l_cmb_target_beams_overload);
	}

	if($target_fire_damage[0] > $attack_shield_hit_pts)
	{
		if($attacker_shield_energy > 0)
		{
			$target_beam_result[] = str_replace("[damage]", NUMBER($attacker_shield_energy), $l_cmb_attacker_shields_hit);
		}
		$target_beam_result[] = $l_cmb_attacker_shields_down;
		$attack_shields_died = $attacker_shield_energy;

		$target_fire2_failure = calc_failure($target_fire_damage[4], $targetshipbeams);
		$$target_fire_damage[4] -= $target_fire2_failure[1];

		$target_fire2_damage = calc_damage($target_fire_damage[4], $beam_damage_all, $targetlowpercent, $targetshipbeams, $shipinfo['armor'], $attack_armor_hit_pts);
		$target_beams_died += $target_fire2_damage[3];

		if($target_fire2_failure[2] == 100)
		{
			$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_enemybeamfailarmor);
		}

		$target_beam_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fire_damage[4]), $l_cmb_targetbeamunits));

		if($target_fire2_damage[0] > $attack_armor_hit_pts)
		{
			$attack_damage = floor($attack_armor_hit_pts / $ship_armor_hit_pts);
			if($attack_damage > 0)
			{
				$target_beam_result[] = str_replace("[damage]", NUMBER($attack_damage), $l_cmb_attacker_armor_hit);
			}
			$target_beam_result[] = $l_cmb_attacker_armor_down;
			$attack_armor_died = $attack_damage;
		}
		else
		{
			$attack_armor_hit_pts = $attack_armor_hit_pts - $target_fire2_damage[0];
			$attacker_armor_used = floor($target_fire2_damage[0] / $ship_armor_hit_pts);
			$target_beam_result[] = str_replace("[damage]", NUMBER($attacker_armor_used), $l_cmb_attacker_armor_hit);
			$attack_armor_died = $attacker_armor_used;
		}
	}
	else
	{
		$attack_shield_hit_pts = $attack_shield_hit_pts - $target_fire_damage[0];
		$attacker_shields_used = floor($target_fire_damage[0] / $ship_shield_hit_pts);
		$target_beam_result[] = str_replace("[damage]", NUMBER($attacker_shields_used), $l_cmb_attacker_shields_hit);
		$attack_shields_died = $attacker_shields_used;
	}
}
else
{
	$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_beams);
}

if($target_beamtofighter_dmg != 0)
{
	$attack_fighter_hit_pts = $attacker_fighters_left * $fighter_hit_pts;

	$target_fighter_failure = calc_failure($target_beamtofighter_dmg, $targetshipbeams);
	$target_beamtofighter_dmg2 = $target_beamtofighter_dmg - $target_fighter_failure[1];

	$target_fighter_damage = calc_damage($target_beamtofighter_dmg2, $beam_damage_all, $targetlowpercent, $targetshipbeams, $shipinfo['fighters'], $attack_fighter_hit_pts);
	$target_beams_died += $target_fighter_damage[3];

	if($target_fighter_failure[2] == 100){
		$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_enemybeamfailfighter);
	}

	$target_beam_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_beamtofighter_dmg2), $l_cmb_targetbeamunits));

	if(mt_rand(1, 100) <= $defender_lucky_percentage)
	{
		$target_fighter_damage[0] = $target_fighter_damage[0] * $defender_lucky_multiplier;
		$target_beam_result[] = str_replace("[times]", $defender_lucky_multiplier, $l_cmb_target_beams_overload);
	}

	if($target_fighter_damage[0] > $attack_fighter_hit_pts)
	{
		if($attacker_fighters_left > 0)
		{
			$target_beam_result[] = str_replace("[fighterslost]", NUMBER($attacker_fighters_left), $l_cmb_attacker_fighters_lost);
		}
		$attack_fighters_died = $attacker_fighters_left;
		$target_beam_result[] = $l_cmb_attacker_lost_all_fighters;
	}
	else
	{
		$attack_fighter_hit_pts = $attack_fighter_hit_pts - $target_fighter_damage[0];
		$attacker_fighters_used = floor($target_fighter_damage[0] / $fighter_hit_pts);
		$target_beam_result[] = str_replace("[fighterslost]", NUMBER($attacker_fighters_used), $l_cmb_attacker_fighters_lost);
		$attack_fighters_died = $attacker_fighters_used;
	}
}
else
{
	$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_beams);
}

if($target_beamtotorp_dmg != 0)
{
	$attack_torp_hit_pts = $attacker_torps_left * $torp_hit_pts;

	$target_torp_failure = calc_failure($target_beamtotorp_dmg, $targetshipbeams);
	$target_beamtotorp_dmg2 = $target_beamtotorp_dmg - $target_torp_failure[1];

	$target_torp_damage = calc_damage($target_beamtotorp_dmg2, $beam_damage_all, $targetlowpercent, $targetshipbeams, $shipinfo['torp_launchers'], $attack_torp_hit_pts);
	$target_beams_died += $target_torp_damage[3];

	if($target_torp_failure[2] == 100){
		$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_enemybeamfailtorp);
	}

	$target_beam_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_beamtotorp_dmg2), $l_cmb_targetbeamunits));

	if(mt_rand(1, 100) <= $defender_lucky_percentage)
	{
		$target_torp_damage[0] = $target_torp_damage[0] * $defender_lucky_multiplier;
		$target_beam_result[] = str_replace("[times]", $defender_lucky_multiplier, $l_cmb_target_beams_overload);
	}

	if($target_torp_damage[0] > $attack_torp_hit_pts)
	{
		if($attacker_torps_left > 0)
		{
			$target_beam_result[] = str_replace("[torpslost]", NUMBER($attacker_torps_left), $l_cmb_attacker_torps_lost);
		}
		$attack_torps_died = $attacker_torps_left;
		$target_beam_result[] = $l_cmb_attacker_lost_all_torps;
	}
	else
	{
		$attack_torp_hit_pts = $attack_torp_hit_pts - $target_torp_damage[0];
		$attacker_torps_used = floor($target_torp_damage[0] / $torp_hit_pts);
		$target_beam_result[] = str_replace("[torpslost]", NUMBER($attacker_torps_used), $l_cmb_attacker_torps_lost);
		$attack_torps_died = $attacker_torps_used;
	}
}
else
{
	$target_beam_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_beams);
}

$attacker_torps_left -= $attack_torps_died;
$attacker_fighters_left -= $attack_fighters_died;
$attacker_shield_energy -= $attack_shields_died;
$attacker_armor_left -= $attack_armor_died;

$target_beam_energy = $target_beam_energy + $target_beamtofighter_dmg + $target_beamtotorp_dmg;
$target_beam_energy -= $target_beams_died;

 

// Stage 2 fighter Exchange



$attacker_fighter_result = array();
$target_fighter_result = array();

$attack_fighters_died2 = 0;
$attack_torps_died2 = 0;
$target_fighters_died2 = 0;
$target_torps_died2 = 0;

if($target_fighters_left != 0)
{
	$attack_fighter_hit_pts = $attacker_fighters_left * $fighter_hit_pts;

	$target_fighter_failure = calc_failure($target_fighters_left, $targetshipfighter);
	$target_fighters_left2 = $target_fighters_left - $target_fighter_failure[1];

	$target_fighter_damage = calc_damage($target_fighters_left2, $fighter_damage_all, $targetlowpercent, $targetshipfighter, $shipinfo['fighter'], $attack_fighter_hit_pts);

	if($target_fighter_failure[2] == 100)
	{
		$target_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_enemyfighterfailfighter);
	}
	$target_fighter_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fighters_left2), $l_cmb_targetfighterunits));
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
			$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_left), $l_cmb_target_fighters_lost));
		}
		$attacker_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_fighters);

		$target_fighters_died2 = $target_fighters_left;
		$target_fighters_died += $target_fighters_left;

		$attack_fighter2_failure = calc_failure($attack_fighter_damage[4], $shipinfo['fighter']);
		$attack_fighter_damage[4] -= $attack_fighter2_failure[1];

		$attack_fighter2_damage = calc_damage($attack_fighter_damage[4], $fighter_damage_all, $attackerlowpercent, $shipinfo['fighter'], $targetshiptorp_launchers, $target_torp_hit_pts);

		$attacker_fighter_result[] = str_replace("[units]", NUMBER($attack_fighter_damage[4]), $l_cmb_attackfighterunits);

		if($attack_fighter2_damage[0] > $target_torp_hit_pts)
		{
			$attack_fighter2_damage[0] = $attack_fighter2_damage[0] - $target_torp_hit_pts;
			$attack_damage = floor($target_torp_hit_pts / $torp_hit_pts);
			if($attack_damage > 0)
			{
				$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[torpslost]", NUMBER($attack_damage), $l_cmb_target_torps_lost));
			}
			$target_torps_died2 = $attack_damage;
			$target_torps_died += $attack_damage;
			$attacker_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_target_lost_all_torps);
		}
		else
		{
			$target_torp_hit_pts = $target_torp_hit_pts - $attack_fighter2_damage[0];
			$target_torps_used = floor($attack_fighter2_damage[0] / $torp_hit_pts);
			$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[torpslost]", NUMBER($target_torps_used), $l_cmb_target_torps_lost));
			$target_torps_died2 = $target_torps_used;
			$target_torps_died += $target_torps_used;
		}
	}
	else
	{
		$target_fighter_hit_pts = $target_fighter_hit_pts - $attack_fighter_damage[0];
		$target_fighters_used = floor($attack_fighter_damage[0] / $fighter_hit_pts);
		$attacker_fighter_result[] = str_replace("[player]", $targetname, str_replace("[fighterslost]", NUMBER($target_fighters_used), $l_cmb_target_fighters_lost));
		$target_fighters_died2 = $target_fighters_used;
		$target_fighters_died += $target_fighters_used;
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
		$attack_fighters_died2 = $attacker_fighters_left;
		$attack_fighters_died += $attacker_fighters_left;
		$attack_torp_hit_pts = $attacker_torps_left * $torp_hit_pts;

		$target_fighter_failure = calc_failure($target_fighter_damage[4], $targetshipfighter);
		$target_fighter_damage[4] -= $target_fighter_failure[1];

		$target_fighter2_damage = calc_damage($target_fighter_damage[4], $fighter_damage_all, $targetlowpercent, $targetshipfighter, $shipinfo['torp_launchers'], $attack_torp_hit_pts);

		$target_fighter_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_fighter_damage[4]), $l_cmb_targetfighterunits));

		if($target_fighter2_damage[0] > $attack_torp_hit_pts)
		{
			$attack_damage = floor($attack_torp_hit_pts / $torp_hit_pts);
			if($attack_damage > 0)
			{
				$target_fighter_result[] = str_replace("[torpslost]", NUMBER($attack_damage), $l_cmb_attacker_torps_lost);
			}
			$target_fighter_result[] = $l_cmb_attacker_lost_all_torps;
			$attack_torps_died2 = $attack_damage;
			$attack_torps_died += $attack_damage;
		}
		else
		{
			$attack_torp_hit_pts = $attack_torp_hit_pts - $target_fighter2_damage[0];
			$attack_torps_used = floor($target_fighter2_damage[0] / $torp_hit_pts);
			$target_fighter_result[] = str_replace("[torpslost]", NUMBER($attack_torps_used), $l_cmb_attacker_torps_lost);
			$attack_torps_died2 = $attack_torps_used;
			$attack_torps_died += $attack_torps_used;
		}
	}
	else
	{
		$attack_fighter_hit_pts = $attack_fighter_hit_pts - $target_fighter_damage[0];
		$attack_fighters_used = floor($target_fighter_damage[0] / $fighter_hit_pts);
		$target_fighter_result[] = str_replace("[fighterslost]", NUMBER($attack_fighters_used), $l_cmb_attacker_fighters_lost);
		$attack_fighters_died2 = $attack_fighters_used;
		$attack_fighters_died += $attack_fighters_used;
	}
}
else
{
	$target_fighter_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_send_fighteres);
}

$attacker_fighters_left -= $attack_fighters_died2;
$attacker_torps_left -= $attack_torps_died2;
$target_fighters_left -= $target_fighters_died2;
$target_torps_left -= $target_torps_died2;

 

// Stage 3 torp Exchange

 

$attacker_torp_result = array();
$target_torp_result = array();

$attack_torps_died2 = 0; // $attacker_torps_left
$attack_shields_died2 = 0; // $attacker_shield_energy
$attack_armor_died2 = 0; // $attacker_armor_left
$target_torps_died2 = 0; // $target_torps_left
$target_shields_died2 = 0; // $target_shield_energy
$target_armor_died2 = 0; // $target_armor_left

if($target_torps_left != 0)
{
	$attack_shield_hit_pts = $attacker_shield_energy * $ship_shield_hit_pts;
	$attack_armor_hit_pts = $attacker_armor_left * $ship_armor_hit_pts;

	$target_torp_failure = calc_failure($target_torps_left, $targetshiptorp_launchers);
	$target_torps_left2 = $target_torps_left - $target_torp_failure[1];

	$target_torp_damage = calc_damage($target_torps_left2, $torp_damage_shields, $targetlowpercent, $targetshiptorp_launchers, $shipinfo['shields'], $attack_shield_hit_pts);

	if($target_torp_failure[2] == 100){
		$target_torp_result[] = str_replace("[player]", $targetname, $l_cmb_enemytorpfailshields);
	}
	$target_torp_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_torps_left2), $l_cmb_targettorpunits));
}

if($attacker_torps_left != 0)
{
	$target_shield_hit_pts = $target_shield_energy * $ship_shield_hit_pts;
	$target_armor_hit_pts = $target_armor_left * $ship_armor_hit_pts;

	$attack_torp_failure = calc_failure($attacker_torps_left, $shipinfo['torp_launchers']);
	$attacker_torps_left2 = $attacker_torps_left - $attack_torp_failure[1];

	$attack_torp_damage = calc_damage($attacker_torps_left2, $torp_damage_shields, $attackerlowpercent, $shipinfo['torp_launchers'], $targetshipshields, $target_shield_hit_pts);
	$attack_torps_died2 = $attack_torp_damage[3];
	$attack_torps_died += $attack_torp_damage[3];

	if($attack_torp_failure[2] > 0){
		$attacker_torp_result[] = $l_cmb_yourtorpfail1;
		$attacker_torp_result[] = str_replace("[percent]", (100 - $attack_torp_failure[2]), $l_cmb_yourtorpfail2);
	}

	$attacker_torp_result[] = str_replace("[units]", NUMBER($attacker_torps_left2), $l_cmb_attacktorpunits);

	if($attack_torp_damage[0] > $target_shield_hit_pts)
	{
		if($target_shields_left > 0)
		{
			$attacker_torp_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($target_shield_energy), $l_cmb_target_shields_hit));
		}
		$attacker_torp_result[] = str_replace("[player]", $targetname, $l_cmb_target_shields_down);
		$target_shields_died2 = $target_shield_energy;
		$target_shields_died += $target_shield_energy;

		$attack_torp2_failure = calc_failure($attack_torp_damage[4], $shipinfo['torp_launchers']);
		$attack_torp_damage[4] -= $attack_torp2_failure[1];

		$attack_torp2_damage = calc_damage($attack_torp_damage[4], $torp_damage_all, $attackerlowpercent, $shipinfo['torp_launchers'], $targetshiparmor, $target_armor_hit_pts);
		$attack_torps_died2 += $attack_torp2_damage[3];
		$attack_torps_died += $attack_torp2_damage[3];

		if($attack_torp2_failure[2] > 0){
			$attacker_torp_result[] = $l_cmb_yourtorpfail1;
			$attacker_torp_result[] = str_replace("[percent]", (100 - $attack_torp2_failure[2]), $l_cmb_yourtorpfail2);
		}

		$attacker_torp_result[] = str_replace("[units]", NUMBER($attack_torp_damage[4]), $l_cmb_attacktorpunits);

		if($attack_torp2_damage[0] > $target_armor_hit_pts)
		{
			$attack_torp2_damage[0] = $attack_torp2_damage[0] - $target_armor_hit_pts;
			$attack_damage = floor($target_armor_hit_pts / $ship_armor_hit_pts);
			if($attack_damage > 0)
			{
				$attacker_torp_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($attack_damage), $l_cmb_target_armor_hit));
			}
			$attacker_torp_result[] = str_replace("[player]", $targetname, $l_cmb_target_armor_down);
			$target_armor_died2 = $attack_damage;
			$target_armor_died += $attack_damage;
		}
		else
		{
			$target_armor_hit_pts = $target_armor_hit_pts - $attack_torp2_damage[0];
			$target_armor_used = floor($attack_torp2_damage[0] / $ship_armor_hit_pts);
			$attacker_torp_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($target_armor_used), $l_cmb_target_armor_hit));
			$target_armor_died2 = $target_armor_used;
			$target_armor_died += $target_armor_used;
		}
	}
	else
	{
		$target_shield_hit_pts = $target_shield_hit_pts - $attack_torp_damage[0];
		$target_shields_used = floor($attack_torp_damage[0] / $ship_shield_hit_pts);
		$attacker_torp_result[] = str_replace("[player]", $targetname, str_replace("[damage]", NUMBER($target_shields_used), $l_cmb_target_shields_hit));
		$target_shields_died2 = $target_shields_used;
		$target_shields_died += $target_shields_used;
	}
}
else
{
	$attacker_torp_result[] = $l_cmb_attacker_no_torps;
}


if($target_torps_left != 0)
{
	$target_torps_died2 = $target_torp_damage[3];
	$target_torps_died += $target_torp_damage[3];
	if(mt_rand(1, 100) <= $defender_lucky_percentage)
	{
		$target_torp_damage[0] = $target_torp_damage[0] * $defender_lucky_multiplier;
		$target_torp_result[] = str_replace("[times]", $defender_lucky_multiplier, $l_cmb_target_surprise_torps);
	}

	if($target_torp_damage[0] > $attack_shield_hit_pts)
	{
		if($attacker_shields_left > 0)
		{
			$target_torp_result[] = str_replace("[damage]", NUMBER($attacker_shields_left), $l_cmb_attacker_shields_hit);
		}
		$target_torp_result[] = $l_cmb_attacker_shields_down;
		$attack_shields_died2 = $attacker_shield_energy;
		$attack_shields_died += $attacker_shield_energy;

		$target_torp_failure = calc_failure($target_torp_damage[4], $targetshiptorp_launchers);
		$target_torp_damage[4] -= $target_torp_failure[1];

		$target_torp2_damage = calc_damage($target_torp_damage[4], $torp_damage_all, $targetlowpercent, $targetshiptorp_launchers, $shipinfo['armor'], $attack_armor_hit_pts);
		$target_torps_died2 += $target_torp2_damage[3];
		$target_torps_died += $target_torp2_damage[3];

		if($target_torp_failure[2] == 100){
			$target_torp_result[] = str_replace("[player]", $targetname, $l_cmb_enemytorpfailarmor);
		}

		$target_torp_result[] = str_replace("[player]", $targetname, str_replace("[units]", NUMBER($target_torp_damage[4]), $l_cmb_targettorpunits));

		if($target_torp2_damage[0] > $attack_armor_hit_pts)
		{
			$target_torp2_damage[0] = $target_torp2_damage[0] - $attack_armor_hit_pts;
			$attack_damage = floor($attack_armor_hit_pts / $ship_armor_hit_pts);
			if($attack_damage > 0)
			{
				$target_torp_result[] = str_replace("[damage]", NUMBER($attack_damage), $l_cmb_attacker_armor_hit);
			}
			$target_torp_result[] = $l_cmb_attacker_armor_down;
			$attack_armor_died2 = $attack_damage;
			$attack_armor_died += $attack_damage;
		}
		else
		{
			$attack_armor_hit_pts = $attack_armor_hit_pts - $target_torp2_damage[0];
			$attacker_armor_used = floor($target_torp2_damage[0] / $ship_armor_hit_pts);
			$target_torp_result[] = str_replace("[damage]", NUMBER($attacker_armor_used), $l_cmb_attacker_armor_hit);
			$attack_armor_died2 = $attacker_armor_used;
			$attack_armor_died += $attacker_armor_used;
		}
	}
	else
	{
		$attack_shield_hit_pts = $attack_shield_hit_pts - $target_torp_damage[0];
		$attacker_shields_used = floor($target_torp_damage[0] / $ship_shield_hit_pts);
		$target_torp_result[] = str_replace("[damage]", NUMBER($attacker_shields_used), $l_cmb_attacker_shields_hit);
		$attack_shields_died2 = $attacker_shields_used;
		$attack_shields_died += $attacker_shields_used;
	}
}
else
{
	$target_torp_result[] = str_replace("[player]", $targetname, $l_cmb_target_no_torps);
}

$attacker_shield_energy -= $attack_shields_died2;
$attacker_armor_left -= $attack_armor_died2;
$attacker_torps_left -= $attack_torps_died2;
$target_shield_energy -= $target_shields_died2;
$target_armor_left -= $target_armor_died2;
$target_torps_left -= $target_torps_died2;

 


if($attacktype == "planet")
{
	$success = SCAN_SUCCESS($shipinfo['sensors'], $planetinfo['cloak']);

 
}
else
{
	$success = SCAN_SUCCESS($shipinfo['sensors'], $targetship['cloak']);

 
}

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sector Defense Mine Combat End:</B></font><BR>Attacker " . $playerinfo['character_name'] . "
	 Beams: <B>" . NUMBER($attacker_beam_energy)."</B>,
	 Fighters: <B>" . NUMBER($attacker_fighters_left)."</B>, 
	 Shields: <B>" . NUMBER($attacker_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($attacker_torps_left) . "</B>. 
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	Defender ".$planet_owner['character_name'] . "
	 Beams: <B>" . NUMBER($target_beam_energy) ."</B>,
	 Fighters: <B>" . NUMBER($target_fighters_left) . "</B>,
	 Shields: <B>" . NUMBER($target_shield_energy) . "</B>, 
	 Torpedoes: <B>" . NUMBER($target_torps_left) . "</B>. 
	 Armor Points: <B>" . NUMBER($target_armor_left) . "</B>");

?>
