<?php
// Calculate the top and bottom percentage range used in calculating the damage percentage
// range each items damage amount.
if (!function_exists('ecmcheck')) {

	function ecmcheck($targetecm, $shipsensor, $modifier){
		global $ecm_modifier, $lowpercent_ecm_modifier, $max_tech_level;

		$shipsensor = max(0.01, $shipsensor);
		$targetecm = max(0.01, $targetecm);
		$success = $shipsensor / $targetecm;

		$sensorratio = $shipsensor / $max_tech_level;
		$ecmratio = $targetecm / $max_tech_level;

		 if($success == 1)
		{
			$success = 50;
		}
		else
		{
			$workratio = $sensorratio - $ecmratio;
			$workratio *= 50;
			$success = floor(50 + $workratio);
		}
		$lowpercent = min(max($success, 1), 100);

		if($modifier < 0)
		{
			$highpercent = min(floor($lowpercent - $modifier), 100);
		}
		else
		{
			$highpercent = min(floor($lowpercent + ($modifier * $ecm_modifier)), 100);
		}

		$percent_calc[0] = $lowpercent;
		$percent_calc[1] = $highpercent;

		return $percent_calc;
	}


// Calculate the amount of failure and return the total number of units failed and percentage of the total units that failed.

	function calc_failure($units, $attacktech){
		global $reliability_modifier, $failure_modifier, $tech_complete_failure;

		// The higher the tech level the more likely part of it will fail lowering its effectiveness.
		// With a slim chance of 100% failure.
		$failure = floor($attacktech * $reliability_modifier);
		$total_failure = array();

		$total_failure[1] = 0; // total number of units that failed
		$total_failure[2] = 0; // percentage of the total units that failed
		if(mt_rand(1, 100) < $failure){
			if(mt_rand(1, 100) <= $tech_complete_failure){
				$total_failure[1] = $units;
				$total_failure[2] = 100;
			}
			else
			{
				$total_failure[2] = mt_rand(1, floor($attacktech * $failure_modifier));
				$total_failure[1] = floor($units * ($total_failure[2] * 0.01));
			}
		}

		return $total_failure;
	}


// Calculate the amount of damage caused by the number of units involved and total number of units used.

	function calc_damage($units, $damagemax, $percent_calc, $attacktech, $targettech, $hitpoints_to_destroy){
		global $group_divider, $confusion_modifier;

		$damage = array();
//echo "start: $units<br>";
		$damage[0] = 0; // total damage points
		$damage[3] = 0; // number of units used to destroy item
		$damage[4] = 0; // number of units left unused to destroy item
		if($units == 0)
		{
			return $damage;
		}
		// If there is a really WIDE disparity between tech levels there can be confusion where the attack tech misses
		// the enemy targets because there are too many friendlies in the way and a danger of hitting them.
		$confusion = max(floor(($attacktech - $targettech) * $confusion_modifier), 0);

//echo "confusion: $confusion<br>";
		$groups = min($group_divider, $units);
		$group = floor($units / $groups);

//echo "groups divider: " . NUMBER($group_divider) . " - units: " . NUMBER($units) . "<br>";
//echo "groups: " . NUMBER($groups) . " - group size: " . NUMBER($group) . "<br>";
//echo "low: $percent_calc[0] - high: $percent_calc[1]<br>";
		$destroyed = 0;
		for($i = 0; $i < $groups; $i++)
		{
			$groupdamage = $group * floor($damagemax * (mt_rand($percent_calc[0], $percent_calc[1]) * 0.01));
			if(mt_rand(1, 100) < $confusion)
			{
				$groupdamage = 0;
			}

			$damage[0] += $groupdamage;
			$damage[3] += $group;

//			echo "<font color=white>damage[0] = $damage[0] - hitpoints_to_destroy = $hitpoints_to_destroy</font><br>";

			if($damage[0] > $hitpoints_to_destroy)
			{
				$damage[0] -= $groupdamage;
				$damage[3] -= $group;
				$damageperunit = floor($groupdamage / $group);
				$hitpoints_to_destroy -= $damage[0];
				$used_units = floor($hitpoints_to_destroy / $damageperunit) + $damageperunit;
				$damage[0] += ($used_units * $damageperunit);
				$damage[3] += $used_units;

				$destroyed = 1;
				$i = $groups;
			}
			$damage[4] = $units - $damage[3];
//			echo "<font color=lime>damage[0] = $damage[0] - hitpoints_to_destroy = $hitpoints_to_destroy</font><br>";
		}
//echo "<br>";
		$last_group = $units - ($group * $groups);
//echo "last group: " . NUMBER($last_group) . "<br>";
		if($last_group)
		{
			if($destroyed == 0)
			{
				$groupdamage = $last_group * floor($damagemax * (mt_rand($percent_calc[0], $percent_calc[1]) * 0.01));
				$damage[0] += $groupdamage;
				$damage[3] += $last_group;
//			echo "<font color=white>damage[0] = $damage[0] - hitpoints_to_destroy = $hitpoints_to_destroy</font><br>";
				if($damage[0] > $hitpoints_to_destroy)
				{
					$damage[0] -= $groupdamage;
					$damage[3] -= $last_group;
					$damageperunit = floor($groupdamage / $last_group);
					$hitpoints_to_destroy -= $damage[0];
					$used_units = floor($hitpoints_to_destroy / $damageperunit) + $damageperunit;
					$damage[0] += ($used_units * $damageperunit);
					$damage[3] += $used_units;
				}
				$damage[4] = $units - $damage[3];
//			echo "<font color=lime>damage[0] = $damage[0] - hitpoints_to_destroy = $hitpoints_to_destroy</font><br>";
			}
		}
		if($damage[3] > $units)
		{
			$damage[3] = $units;
			$damage[4] = 0;
		}
//echo "total damage points: $damage[0] - used: " . NUMBER($damage[3]) . "<br>";
		return $damage;
	}


// Calculates the amount of damage done to individual tech levels based upon the percentage
// of armor lost in combat and updates either the planet or player ship table.
// $id = ship_id or planet_id
// $type = 0 - ship, 1 - planet
// $percentage = percentage of armor lost

	function calc_internal_damage($id, $type, $percentage, $test = false){
		global $db, $db_prefix;
		global $internal_damage_percent;

		$percentage = abs($percentage);

		if($test)
		{
			echo "id: $id - type: $type - percentage: $percentage<br>";
		}

		$techsdamaged = floor($percentage * 10);
		for($i = 0; $i < 11; $i++){
			if(mt_rand(1, 10000) < ($internal_damage_percent * 100)){
				if($techsdamaged != 0){
					$techsdamaged--;
					$techdamage[$i] = mt_rand(100 - floor($percentage * 100), 100) * 0.01;
				}
				else
				{
					$techdamage[$i] = 1;
				}
			}
			else
			{
				$techdamage[$i] = 1;
			}
		}

		if($type){
			if($test)
			{
				echo "UPDATE {$db_prefix}planets SET armor=armor * $techdamage[0], fighter=fighter * $techdamage[1], sensors=sensors * $techdamage[2], beams=beams * $techdamage[3], torp_launchers=torp_launchers * $techdamage[4], shields=shields * $techdamage[5], cloak=cloak * $techdamage[6], jammer=jammer * $techdamage[7], sector_defense_weapons=sector_defense_weapons * $techdamage[8], sector_defense_sensors=sector_defense_sensors * $techdamage[9], sector_defense_cloak=sector_defense_cloak * $techdamage[10] WHERE planet_id=$id<br>";
			}
			else
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET armor=armor * $techdamage[0], fighter=fighter * $techdamage[1], sensors=sensors * $techdamage[2], beams=beams * $techdamage[3], torp_launchers=torp_launchers * $techdamage[4], shields=shields * $techdamage[5], cloak=cloak * $techdamage[6], jammer=jammer * $techdamage[7], sector_defense_weapons=sector_defense_weapons * $techdamage[8], sector_defense_sensors=sector_defense_sensors * $techdamage[9], sector_defense_cloak=sector_defense_cloak * $techdamage[10] WHERE planet_id=$id");
				db_op_result($debug_query,__LINE__,__FILE__);
			}
		}
		else
		{
			if($test)
			{
				echo "UPDATE {$db_prefix}ships SET engines=engines * $techdamage[0], power=power * $techdamage[1], armor=armor * $techdamage[2], hull=hull * $techdamage[3], fighter=fighter * $techdamage[4], sensors=sensors * $techdamage[5], beams=beams * $techdamage[6], torp_launchers=torp_launchers * $techdamage[7], shields=shields * $techdamage[8], cloak=cloak * $techdamage[9], ecm=ecm * $techdamage[10] WHERE ship_id=$id<br>";
			}
			else
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET engines=engines * $techdamage[0], power=power * $techdamage[1], armor=armor * $techdamage[2], hull=hull * $techdamage[3], fighter=fighter * $techdamage[4], sensors=sensors * $techdamage[5], beams=beams * $techdamage[6], torp_launchers=torp_launchers * $techdamage[7], shields=shields * $techdamage[8], cloak=cloak * $techdamage[9], ecm=ecm * $techdamage[10] WHERE ship_id=$id");
				db_op_result($debug_query,__LINE__,__FILE__);

				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_holds SET amount=amount * $techdamage[3] WHERE ship_id=" . $id);
				db_op_result($debug_query,__LINE__,__FILE__);
			}
		}
	}
}

?>
