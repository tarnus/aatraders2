<?php
// This program is free software; you can redistribute it and/or modify it	
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: create_game.php

$default_lang = "english";
$_SESSION['langdir'] = $default_lang;
$langdir = $_SESSION['langdir'];
$game_number = 0;

include ("config/config.php");
$template_object->enable_gzip = 0;

$level_scan = 250;
$level_cloak = 150;
echo "Planet<br>";
echo SCAN_SUCCESS(($level_scan * .4), $level_cloak) . "<br>";

echo SCAN_SUCCESS(($level_scan * .58), $level_cloak) . "<br>";

echo SCAN_SUCCESS(($level_scan * .61), $level_cloak) . "<br>";
echo "Ship<br>";
echo SCAN_SUCCESS(($level_scan * .55), $level_cloak) . "<br>";

echo SCAN_SUCCESS(($level_scan * .6), $level_cloak) . "<br>";

echo SCAN_SUCCESS(($level_scan * .85), $level_cloak) . "<br>";

function calc_ship_cleanup_cost($level_avg = 0, $type = 1)
{
	global $level_factor, $upgrade_cost;
  
	if ($type==1)
	{
		$c=1;
	}
	elseif ($type==2)
	{
		$c=2;
	}
	else
	{
		$c=4;
	}

	// You must check for upper boundary. Otherwise the typecast can cause it to flip to negative amounts.
	$cl_cost = (mypw($level_factor, ($level_avg * 1.1)) * 70 * $upgrade_cost * $c);

	if ($cl_cost < 0)
	{
		$cl_cost = 2000000000;
	}
  
	$cl_cost = floor( $cl_cost);  
	return $cl_cost;
}

function calc_planet_cleanup_cost($colo = 0, $type = 1)
{
	global $db, $db_prefix, $planet_id, $planetinfo;
	global $colonist_limit, $colonist_tech_add, $spy_cleanup_planet_credits1, $spy_cleanup_planet_credits2, $spy_cleanup_planet_credits3, $max_spies_per_planet;

	$spy_cleanup_planet_credits[1] = $spy_cleanup_planet_credits1;
	$spy_cleanup_planet_credits[2] = $spy_cleanup_planet_credits2;
	$spy_cleanup_planet_credits[3] = $spy_cleanup_planet_credits3;

	$cl_cost = ($colonist_limit + ($colonist_tech_add * (($planetinfo['fighter_normal'] + $planetinfo['cloak_normal'] + $planetinfo['jammer_normal'] + $planetinfo['shields_normal'] + $planetinfo['torp_launchers_normal'] + $planetinfo['beams_normal'] + $planetinfo['sensors_normal']) / 7))) * $spy_cleanup_planet_credits[$type];
	// Here we reduce the costs of scans by 9.9% per spy the owner has on the planet.
//	$res66 = $db->Execute("SELECT * FROM {$db_prefix}spies WHERE planet_id=$planet_id AND owner_id=$planetinfo[owner]");
//	$spies_on_planet = $res66->RecordCount();
  $spies_on_planet = 5;

	$cl_cost = ($cl_cost - ($cl_cost * $spies_on_planet / $max_spies_per_planet * 0.50) );  

	$cl_cost = floor( $cl_cost);  
	return $cl_cost;
}
echo "<hr>";
echo calc_ship_cleanup_cost($level_scan, 1) . "<br>";
echo calc_ship_cleanup_cost($level_scan, 2) . "<br>";
echo calc_ship_cleanup_cost($level_scan, 3) . "<br>";

echo "<hr>";

$planetinfo['fighter_normal'] = $planetinfo['cloak_normal'] = $planetinfo['jammer_normal'] = $planetinfo['shields_normal'] = $planetinfo['torp_launchers_normal'] = $planetinfo['beams_normal'] = $planetinfo['sensors_normal'] = $level_scan;
$colonists = $colonist_limit + ($colonist_tech_add * $level_scan);
echo "colonists: " . number($colonists) . "<br>";
echo number(calc_planet_cleanup_cost($colonists, 1)) . "<br>";
echo number(calc_planet_cleanup_cost($colonists, 2)) . "<br>";
echo number(calc_planet_cleanup_cost($colonists, 3)) . "<br>";
echo "<hr>";
echo number(floor(phpMaxCreditsDelta($level_scan, 0) * 7));
echo "<hr>";

$level_scan = 300;
$level_cloak = 250;
echo "Ship scan: $level_scan - cloak: $level_cloak<br>";
echo "Probe/Artifact: " . SCAN_SUCCESS($level_scan, $level_cloak, 1) . "<br>";

echo "Super Cargo: " . SCAN_SUCCESS($level_scan, $level_cloak, 10) . "<br>";

echo "Pioneer: " . SCAN_SUCCESS($level_scan, $level_cloak, 50) . "<br>";

echo "Stealth: " . SCAN_SUCCESS($level_scan, $level_cloak, 70) . "<br>";

echo "Columbus: " . SCAN_SUCCESS($level_scan, $level_cloak, 120) . "<br>";

echo "Endeavour: " . SCAN_SUCCESS($level_scan, $level_cloak, 150) . "<br>";

echo "Razorback: " . SCAN_SUCCESS($level_scan, $level_cloak, 170) . "<br>";

echo "Voyager: " . SCAN_SUCCESS($level_scan, $level_cloak, 200) . "<br>";

echo "Excelsior: " . SCAN_SUCCESS($level_scan, $level_cloak, 250) . "<br>";

echo "<hr>";

$level_scan = 300;
$level_cloak = 300;
echo "Ship scan: $level_scan - cloak: $level_cloak<br>";
echo "Probe/Artifact: " . SCAN_SUCCESS($level_scan, $level_cloak, 1) . "<br>";

echo "Super Cargo: " . SCAN_SUCCESS($level_scan, $level_cloak, 10) . "<br>";

echo "Pioneer: " . SCAN_SUCCESS($level_scan, $level_cloak, 50) . "<br>";

echo "Stealth: " . SCAN_SUCCESS($level_scan, $level_cloak, 70) . "<br>";

echo "Columbus: " . SCAN_SUCCESS($level_scan, $level_cloak, 120) . "<br>";

echo "Endeavour: " . SCAN_SUCCESS($level_scan, $level_cloak, 150) . "<br>";

echo "Razorback: " . SCAN_SUCCESS($level_scan, $level_cloak, 170) . "<br>";

echo "Voyager: " . SCAN_SUCCESS($level_scan, $level_cloak, 200) . "<br>";

echo "Excelsior: " . SCAN_SUCCESS($level_scan, $level_cloak, 250) . "<br>";


echo "<hr>";

$level_scan = 250;
$level_cloak = 400;
echo "Ship scan: $level_scan - cloak: $level_cloak<br>";
echo "Probe/Artifact: " . SCAN_SUCCESS($level_scan, $level_cloak, 1) . "<br>";

echo "Super Cargo: " . SCAN_SUCCESS($level_scan, $level_cloak, 10) . "<br>";

echo "Pioneer: " . SCAN_SUCCESS($level_scan, $level_cloak, 50) . "<br>";

echo "Stealth: " . SCAN_SUCCESS($level_scan, $level_cloak, 70) . "<br>";

echo "Columbus: " . SCAN_SUCCESS($level_scan, $level_cloak, 120) . "<br>";

echo "Endeavour: " . SCAN_SUCCESS($level_scan, $level_cloak, 150) . "<br>";

echo "Razorback: " . SCAN_SUCCESS($level_scan, $level_cloak, 170) . "<br>";

echo "Voyager: " . SCAN_SUCCESS($level_scan, $level_cloak, 200) . "<br>";

echo "Excelsior: " . SCAN_SUCCESS($level_scan, $level_cloak, 250) . "<br>";

include ("footer.php");
?>