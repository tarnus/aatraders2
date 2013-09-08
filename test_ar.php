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
include ("globals/combat_functions.inc");

include ("config/config.php");
$template_object->enable_gzip = 0;

$templatename = "master_template/";

include ("header.php");

function test_ar()
{

global $shipinfo, $highcloak, $highsensor, $highfighter, $attacker_armor_left, $target_fighters_left, $shiparmor, $energy_per_fighter;
$attack_run_engine_modifier = 0.25;
$attack_run_modifier = 50;
$ship_armor_hit_pts = 1500;
$fighter_damage_all = 1000;

$attackerlowpercent = ecmcheck($highcloak, $shipinfo['sensors'], $attack_run_modifier + floor(($shipinfo['engines'] - $highfighter) * $attack_run_engine_modifier));
$targetlowpercent = ecmcheck($shipinfo['ecm'], $highsensor, -($attack_run_modifier + floor(($shipinfo['engines'] - $highfighter) * $attack_run_engine_modifier)));

echo "Attacker Low Percentage: <font color=red><b>$attackerlowpercent[0]</b></font> - Target Low Percentage: <font color=red><b>$targetlowpercent[0]</b></font><br>";
echo "Attacker High Percentage: <font color=lime><b>$attackerlowpercent[1]</b></font> - Target High Percentage: <font color=lime><b>$targetlowpercent[1]</b></font><br>";
		// we reverse the attack and target tech this will kick in the confusion
		// calculation and cause the sector defense to miss.  The higher the ships engine the more the sector defense will miss.
		$target_fighter_damage = calc_damage($target_fighters_left, $fighter_damage_all, $targetlowpercent, $shipinfo['engines'], $highfighter);

		if($target_fighter_damage[2] == 100){
			echo "<br><font color='#ff0000' ><b><font color=white >" . $targetname . "</font>$l_sf_fnoattacka</b></font><br><br>";
		}

		$attack_armor_hit_pts = $attacker_armor_left * $ship_armor_hit_pts;
		$ratio = $target_fighter_damage[0] / ($target_fighters_left * $fighter_damage_all);

		$ddamageroll=mt_rand(1,50);
		if($ddamageroll > 45){
			$ratio = $ratio * 1;
		}else
		if($ddamageroll > 35){
			$ratio = $ratio * 0.9;
		}else
		if($ddamageroll > 25){
			$ratio = $ratio * 0.8;
		}
		if($ddamageroll > 20){
			$ratio = $ratio * 0.7;
		}else
		if($ddamageroll > 15){
			$ratio = $ratio * 0.6;
		}else
		if($ddamageroll > 10){
			$ratio = $ratio * 0.5;
		}else
		if($ddamageroll > 5){
			$ratio = $ratio * 0.4;
		}else
		if($ddamageroll > 0){
			$ratio = $ratio * 0.3;
		}

echo "Maximum number of SD fighters Planet Fighter Tech <font color=lime><b>$highfighter</b></font> should hold: <font color=red><b>" . NUMBER(NUM_PER_LEVEL($highfighter) * 10) . "</b></font><br>
Maximum Damage SD Fighters can cause: <font color=red><b>" . NUMBER($target_fighters_left * $fighter_damage_all) . "</b></font><br>
Maximum Energy Needed: <font color=red>" . NUMBER($energy_per_fighter * $target_fighters_left) . "</b></font><br>
Number of damage hitpoints Ship Armor Tech <font color=lime><b>$shiparmor</b></font> can absorb armor hit points: <font color=lime><b>" . NUMBER($attack_armor_hit_pts) . "</b></font><br>
Actual damage SD fighters cause if normal Attack: <font color=yellow><b>" . NUMBER($target_fighter_damage[0]) . "</b></font> * ratio: <font color=yellow><b>" . $ratio . "</b></font><br>
Number of damage hitpoints Ship absorbed: <font color=lime><b>" . NUMBER(floor($target_fighter_damage[0] * $ratio)) . "</b></font><br>
Total damage to ship armor: <font color=red><b>" . NUMBER(floor(($target_fighter_damage[0] * $ratio) / $ship_armor_hit_pts)) . "</b></font><br>";
		$target_fighter_damage[0] = floor($target_fighter_damage[0] * $ratio);
		if($target_fighter_damage[0] > $attack_armor_hit_pts)
		{
			$target_fighter_damage[0] = $target_fighter_damage[0] - $attack_armor_hit_pts;
			$attacker_armor_left = 0;
		}
		else
		{
			$attack_armor_hit_pts = $attack_armor_hit_pts - $target_fighter_damage[0];
			$attacker_armor_used = $attacker_armor_left - floor($attack_armor_hit_pts / $ship_armor_hit_pts);
			$attacker_armor_left = floor($attack_armor_hit_pts / $ship_armor_hit_pts);
		}

$armor_lost = max(($shipinfo['armor_pts'] - $attacker_armor_left), 0);
	echo "Percentage of armor lost: <font color=yellow><b>" . floor($armor_lost / $shipinfo['armor_pts'] * 100) . "</b></font><br><hr>";
}

get_post_ifset("planetcloak, planetsensor, planetfighter, sdfighters, shipsensors, shipecm, shipengines, shiparmor");


$highcloak = $planetcloak;
$highsensor = $planetsensor;
$highfighter = $planetfighter;
$shipinfo['sensors'] = $shipsensors;
$shipinfo['ecm'] = $shipecm;
$shipinfo['engines'] = $shipengines;

$attacker_armor_left = NUM_PER_LEVEL($shiparmor);
$shipinfo['armor_pts'] = NUM_PER_LEVEL($shiparmor);
$target_fighters_left = $sdfighters;

test_ar();
?>
<form action="test_ar.php" method="post" enctype="multipart/form-data">
Planet Cloak Tech Level:<input type="text" name="planetcloak" value="<?php echo $planetcloak;?>"><br>
Planet Sensor Tech Level:<input type="text" name="planetsensor" value="<?php echo $planetsensor;?>"><br>
Planet Fighter Tech Level:<input type="text" name="planetfighter" value="<?php echo $planetfighter;?>"><br>
Planet SD Fighter Amount:<input type="text" name="sdfighters" value="<?php echo $sdfighters;?>"><br>
<hr>
Ship Sensor Tech Level:<input type="text" name="shipsensors" value="<?php echo $shipsensors;?>"><br>
Ship ECM Tech Level:<input type="text" name="shipecm" value="<?php echo $shipecm;?>"><br>
Ship Engines Tech Level:<input type="text" name="shipengines" value="<?php echo $shipengines;?>"><br>
Ship Armor Tech Level:<input type="text" name="shiparmor" value="<?php echo $shiparmor;?>"><br>
<hr>
<input type="submit" name="Calculate">
</form>
<?

include ("footer.php");

?>
