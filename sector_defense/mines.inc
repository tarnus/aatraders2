<?php
include ("languages/$langdir/lang_check_defenses.inc");
include ("languages/$langdir/lang_combat.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/explode_mines.inc");
include ("globals/message_defense_owner.inc");
include ("globals/planet_bounty_check.inc");
include ("globals/get_player.inc");
// Lets blow up some mines!
//$template_object->enable_gzip = 0;

//$mine_debug = 1;

$template_object->assign("l_cmb_SD_attacking", str_replace("[sector]", $destination_name, $l_cmb_SD_mines_attacking));

// Lets blow up some mines!
$totalmines = isset($defenses['mines']) ? $defenses['mines'] : 0;

$sector_check = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_id='$destination'", 1);
if($sector_check->RecordCount())
{
	$sect = $sector_check->fields;
	$sectorname = $sect['sector_name'];
}
$sector_check->close();

$shipinfo_old = $shipinfo;

if($shipinfo['hull_normal'] + $shipinfo['basehull'] > $mine_hullsize && $totalmines != 0)
{
	$debug_query = $db->SelectLimit("SELECT * FROM {$db_prefix}ships WHERE player_id=$playerinfo[player_id] AND ship_id=$playerinfo[currentship]", 1);
	db_op_result($debug_query,__LINE__,__FILE__);
	$shipinfo = $debug_query->fields;
	$debug_query->close();

	$attack_deflectors_left = $shipdevice['dev_minedeflector']['amount'];
	$attacker_armor_left = $shipinfo['armor_pts'];

	// If the attacker would get a bounty by attacking the most powerful planet in the sector then their A&R is useless.
	$isfedbounty = planet_bounty_check($playerinfo, $destination, $planet_owner, 0);
	if($isfedbounty > 0)
	{
		$attack_deflectors_left = 0;
	}
	$template_object->assign("isfedbounty", $isfedbounty);
	$template_object->assign("l_by_nofedbounty", $l_by_nofedbountyplanet);
	$template_object->assign("l_by_fedbounty2", $l_by_fedbounty);

	$resultSDb = $db->Execute("SELECT * from {$db_prefix}sector_defense WHERE sector_id='$destination' and player_id != '$playerinfo[player_id]' and defense_type='mines'");
	db_op_result($resultSDb,__LINE__,__FILE__);

	$highjammer=0;
	$highcloak = 0;
	$highsensor = 0;
	$hightorps = 0;
	$fm_owner = 0;
	$high_player_id = 0;
	$high_player_score = 0;

	if ($resultSDb > 0)
	{
		while (!$resultSDb->EOF)
		{
			$fm_owner = $resultSDb->fields['player_id'];
			$resultSDc = $db->Execute("SELECT * from {$db_prefix}players  WHERE player_id='$fm_owner'");
			db_op_result($resultSDc,__LINE__,__FILE__);
			if ($resultSDc > 0)
			{
		   		$mineowner= $resultSDc->fields['team'];
			   	$targetname = $resultSDc->fields['character_name'];
			}

			if($high_player_score < $resultSDc->fields['score'])
			{
				$high_player_score = $resultSDc->fields['score'];
				$high_player_id = $resultSDc->fields['player_id'];
			}

			$result4 = $db->SelectLimit("SELECT sector_defense_cloak from {$db_prefix}planets where (owner=$fm_owner or (team > 0 and team=$mineowner)) and base='Y' and sector_id='$destination' order by sector_defense_cloak DESC", 1);
			db_op_result($result4,__LINE__,__FILE__);
			$planets = $result4->fields;
			if ($highcloak < $planets['sector_defense_cloak'])
			{
				$highcloak=$planets['sector_defense_cloak'] + $basedefense;
			}
			$result4->close();

			$result4 = $db->SelectLimit("SELECT sector_defense_sensors from {$db_prefix}planets where (owner=$fm_owner or (team > 0 and team=$mineowner)) and base='Y' and sector_id='$destination' order by sector_defense_sensors DESC", 1);
			db_op_result($result4,__LINE__,__FILE__);
			$planets = $result4->fields;
			if ($highsensor < $planets['sector_defense_sensors'])
			{
				$highsensor=$planets['sector_defense_sensors'] + $basedefense;
			}
			$result4->close();

			$result4 = $db->SelectLimit("SELECT sector_defense_weapons, owner from {$db_prefix}planets where (owner=$fm_owner or (team > 0 and team=$mineowner)) and base='Y' and sector_id='$destination' order by sector_defense_weapons DESC", 1);
			db_op_result($result4,__LINE__,__FILE__);
			$planets = $result4->fields;
			if ($hightorps < $planets['sector_defense_weapons'])
			{
				$hightorps=$planets['sector_defense_weapons'] + $basedefense;
			}
			$result4->close();

			$resultSDb->MoveNext();
		}
	}

	$result5 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=". $high_player_id . "", 1);
	db_op_result($result5,__LINE__,__FILE__);
	$planet_owner = $result5->fields;

	if(!class_exists($shipinfo['torp_class']))
	{
		include ("class/" . $shipinfo['torp_class'] . ".inc");
	}

	$attackobject = new $shipinfo['torp_class']();
	$mine_deflector_damage = $attackobject->mine_deflector_damage;

	if($mine_debug == 1)
	{
		echo "mine_deflector_damage: $mine_deflector_damage<br>";
	}

	if(!class_exists("Ship_Torpedo"))
	{
		include ("class/Ship_Torpedo.inc");
	}

	$targetobject = new Ship_Torpedo();
	$mine_damage_all = $targetobject->mine_deflector_damage;
	$mine_hit_pts = $targetobject->mine_hit_pts;

	if($mine_debug == 1)
	{
		echo "mine_damage_all: $mine_damage_all<br>";
		echo "mine_hit_pts: $mine_hit_pts<br>";
	}

	if(!class_exists($shipinfo['armor_class']))
	{
		include ("class/" . $shipinfo['armor_class'] . ".inc");
	}

	$attackobject = new $shipinfo['armor_class']();
	$ship_armor_hit_pts = $attackobject->ship_armor_hit_pts;

	if($mine_debug == 1)
	{
		echo "ship_armor_hit_pts: $ship_armor_hit_pts<br>";
	}

	$minepercent = (min(1, NUM_HOLDS($shipinfo['basehull'] + $shipinfo['hull_normal']) / NUM_HOLDS($max_tech_level * ((mt_rand(95, 105) * 0.01) * $mine_holds_percentage_modifier))));
	if($mine_debug == 1)
	{
		echo "attacker_armor_left: " . NUMBER($attacker_armor_left) . "<br>";
		echo "attacker_armor_damage: " . NUMBER($attack_deflectors_left * $attacker_armor_left) . "<br>";

		echo "base hull: $shipinfo[basehull]<br>";
		echo "hull: $shipinfo[hull_normal]<br>";
		echo "attacker holds: " . NUMBER(NUM_HOLDS($shipinfo['basehull'] + $shipinfo['hull_normal'])) . "<br>";
		echo "randomizer: " . (mt_rand(95, 105) * 0.01) . "<br>";
		echo "randomizer2: " . ((mt_rand(95, 105) * 0.01) * $mine_holds_percentage_modifier) . "<br>";
		echo "attacker holds modifier: " . $minepercent . "<br>";
	}

	$target_mines_left = floor($totalmines * $minepercent);
	$target_mines_start = $target_mines_left;

	if($mine_debug == 1)
	{
		echo "total mines: " . NUMBER($totalmines) . "<br>";
		echo "deflectors: " . NUMBER($attack_deflectors_left) . "<br>";
		echo "total mines left: " . NUMBER($target_mines_left) . "<br>";
		echo "total mines start: " . NUMBER($target_mines_start) . "<br>";
		echo "highsensor: $highsensor<br>";
		echo "shipinfo['ecm']: $shipinfo[ecm]<br>";
		echo "highcloak: $highcloak<br>";
		echo "shipinfo['sensors']: $shipinfo[sensors]<br>";
		echo "hightorps: $hightorps<br>";
		echo "shipinfo['torp_launchers']: $shipinfo[torp_launchers]<br>";
		echo "attack_mine_modifier: $attack_mine_modifier<br>";
		echo "attack_mine_torp_modifier: $attack_mine_torp_modifier<br>";
		echo "mine_holds_percentage_modifier: $mine_holds_percentage_modifier<br>";
	}

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sector Defense Mine Combat Start:</B></font><BR>
	Attacker " . $playerinfo['character_name'] . " (id: $playerinfo[player_id]) in sector $destination_name<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Mine Deflectors: <B>" . NUMBER($attack_deflectors_left) . "</B>, 
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	 Armor Tech: $shipinfo[armor], 
	 Torp Tech: $shipinfo[torp_launchers], 
	 Fighter Bay: $shipinfo[fighter]<br><br>
	Defender " . $planet_owner['character_name'] . " (id: $planet_owner[player_id])
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Sector Mines: <B>" . NUMBER($target_torps_left) . "</B>. 
	 Sector Defense Weapons Tech: $hightorps, 
	 Sector Defense Sensor Tech: $highsensor, 
	 Sector Defense Cloak Bay: $highcloak, 
	 Base Factor: $basedefense");

	$attackerlowpercent = ecmcheck($shipinfo['ecm'], $highsensor, $attack_mine_modifier);
	$targetlowpercent = ecmcheck($highcloak, $shipinfo['sensors'], -$attack_mine_modifier);

	$template_object->assign("l_cmb_attacker_armor", $l_cmb_attacker_armor);
	$attacker_armor = $shipinfo['armor_pts'];
	$template_object->assign("start_attacker_armor", NUMBER($attacker_armor));
	$template_object->assign("l_cmb_attacker_minedeflectors", $l_cmb_attacker_minedeflectors);
	$template_object->assign("l_cmb_target_mines", $l_cmb_target_mines);
	$attacker_minedeflectors = $shipdevice['dev_minedeflector']['amount'];
	$template_object->assign("start_attacker_minedeflectors", NUMBER($attacker_minedeflectors));
	$target_mines = $totalmines;
	$template_object->assign("start_target_mines", NUMBER($target_mines));
	$template_object->assign("l_cmb_SD_minedeflector_exchange", $l_cmb_SD_minedeflector_exchange);

	$attacker_minedeflector_result = array();

	$totalmines = $totalmines - $target_mines_left;

	if($mine_debug == 1)
	{
		echo "attackerlowpercent : " . nl2br(print_r($attackerlowpercent, true)) . "<br>";
		echo "targetlowpercent: " . nl2br(print_r($targetlowpercent, true)) . "<br>";
		echo "total mines new : " . NUMBER($totalmines) . "<br>";
	}

	$l_chm_youhitsomemines = str_replace("[chm_roll]", "<font color=\"red\">" . NUMBER($target_mines_left) . "</font>", $l_chm_youhitsomemines);
	$l_chm_youhitsomemines = str_replace("[total_mines]", "<font color=\"green\">" . NUMBER($totalmines + $target_mines_left) . "</font>", $l_chm_youhitsomemines);
	$attacker_minedeflector_result[] = $l_chm_youhitsomemines;

	if($mine_debug != 1)
	{
		playerlog($playerinfo['player_id'], "LOG5_HIT_MINES", "$target_mines_left|$destination");
		$inputtype[0] = "[chm_playerinfo_character_name]";
		$inputdata[0] = $playerinfo['character_name'];
		$inputtype[1] = "[chm_roll]";
		$inputdata[1] = NUMBER($target_mines_left);
		$inputtype[2] = "[chm_sector]";
		$inputdata[2] = "<a href='main.php?move_method=real&engage=1&destination=$sectorname'>$sectorname</a>";
		message_defense_owner($destination, "l_chm_hehitminesinsector", "lang_check_defenses.inc", "mines", $inputtype, $inputdata);
	}

	$attack_deflectors_died = 0;
	$attack_armor_died = 0;
	$target_mines_died = 0;

	if($attack_deflectors_left != 0)
	{
		$target_mine_hit_pts = $target_mines_left * $mine_hit_pts;

		$attack_deflector_failure = calc_failure($attack_deflectors_left, $shipinfo['torp_launchers']);
		$attack_deflectors_left2 = $attack_deflectors_left - $attack_deflector_failure[1];

		$attack_deflector_damage = calc_damage($attack_deflectors_left2, $mine_deflector_damage, $attackerlowpercent, $shipinfo['torp_launchers'], $hightorps, $target_mine_hit_pts);
		$attack_deflectors_died = $attack_deflector_damage[3];

		if($attack_deflector_failure[2] > 0)
		{
			$l_chm_yourdeflectormalf2a = str_replace("[deflectors]", "<font color='red'>" . (100 - $attack_deflector_failure[2]) . "</font>", $l_chm_yourdeflectormalf2a);
			$attacker_minedeflector_result[] = $l_chm_yourdeflectormalf1;
			$attacker_minedeflector_result[] = $l_chm_yourdeflectormalf2a;
		}
		$attacker_deflectors_left_malfunction = $attack_deflector_failure[1];

		if($mine_debug == 1)
		{
			echo "attacker_deflectors_left_malfunction = " . NUMBER($attacker_deflectors_left_malfunction) . "<br>";
		}

		if($attack_deflector_damage[0] > $target_mine_hit_pts)
		{
			$attack_deflector_damage[0] = $attack_deflector_damage[0] - $target_mine_hit_pts;
			$l_chm_mines_destroyed = str_replace("[number]", "<FONT COLOR='red'>" . NUMBER($target_mines_left) . "</font>", $l_chm_mines_destroyed);
			$l_chm_mines_destroyed = str_replace("[target]", "<font color=green>" . $targetname . "</font>", $l_chm_mines_destroyed);
			$attacker_minedeflector_result[] = $l_chm_mines_destroyed;
			$target_mines_died = $target_mines_left;
		}
		else
		{
			$target_mine_hit_pts = $target_mine_hit_pts - $attack_deflector_damage[0];
			$target_mines_used = floor($attack_deflector_damage[0] / $mine_hit_pts);
			$l_chm_mines_destroyed = str_replace("[number]", "<FONT COLOR='red'>" . NUMBER($target_mines_used) . "</font>", $l_chm_mines_destroyed);
			$l_chm_mines_destroyed = str_replace("[target]", "<font color=green>" . $targetname . "</font>", $l_chm_mines_destroyed);
			$attacker_minedeflector_result[] = $l_chm_mines_destroyed;
			$target_mines_died = $target_mines_used;
		}
	}
	else
	{
		$attacker_minedeflector_result[] = $l_chm_youhadnominedeflectors;
	}

	$l_chm_youlostminedeflectors = str_replace("[chm_roll]", "<font color=\"red\">" . NUMBER($attack_deflectors_died) . "</font>", $l_chm_youlostminedeflectors);
	$attacker_minedeflector_result[] = $l_chm_youlostminedeflectors;

	$target_mines_left3 = $target_mines_left - $target_mines_died;

	if($target_mines_left3 != 0)
	{
		$l_chm_mines_left = str_replace("[number]", "<font color=green>" . NUMBER($target_mines_left3) . "</font>", $l_chm_mines_left);
		$attacker_minedeflector_result[] = $l_chm_mines_left;

		$attacker_armor_hit_pts = $attacker_armor_left * $ship_armor_hit_pts;

		$target_mine_failure = calc_failure($target_mines_left3, $hightorps);
		$target_mines_left2 = $target_mines_left3 - $target_mine_failure[1];

		$target_mine_damage = calc_damage($target_mines_left2, $mine_damage_all, $targetlowpercent, $hightorps, $shipinfo['armor'], $attacker_armor_hit_pts);
		$target_mines_died += $target_mine_damage[3];

		if($target_mine_failure[2] > 0)
		{
			$l_chm_minemalf2a = str_replace("[deflectors]", "<font color=red>" . (100 - $target_mine_failure[2]) . "</font>", $l_chm_minemalf2a);
			$attacker_minedeflector_result[] = $l_chm_minemalf1;
			$attacker_minedeflector_result[] = $l_chm_minemalf2a;
		}
		$target_mines_left_malfunction = $target_mine_failure[1];

		if($target_mine_damage[0] > $attacker_armor_hit_pts)
		{
			$target_mine_damage[0] = $target_mine_damage[0] - $attacker_armor_hit_pts;
			$attacker_minedeflector_result[] = $l_chm_yourhullisbreached;
			$attack_armor_died = $attacker_armor_left;
		}
		else
		{
			$attacker_armor_hit_pts = $attacker_armor_hit_pts - $target_mine_damage[0];
			$attacker_armor_used = floor($target_mine_damage[0] / $ship_armor_hit_pts);
			$l_chm_yourarmorhitforminesdmg = str_replace("[chm_mines_left]", "<font color=red>" . NUMBER($attacker_armor_used) . "</font>", $l_chm_yourarmorhitforminesdmg);
			$attacker_minedeflector_result[] = $l_chm_yourarmorhitforminesdmg;
			$attack_armor_died = $attacker_armor_left;
			$attack_armor_died = $attacker_armor_used;
		}
	}
	else
	{
		$l_chm_mines_exhausted = str_replace("[player]", "<font color=red>$targetname</font>", $l_chm_mines_exhausted);
		$attacker_minedeflector_result[] = $l_chm_mines_exhausted;
	}

	$l_chm_mine_deflectors_left = str_replace("[number]", "<font color=green>" . NUMBER($attack_deflectors_left - $attack_deflectors_died) . "</font>", $l_chm_mine_deflectors_left);
	$attacker_minedeflector_result[] = $l_chm_mine_deflectors_left;

	$attack_deflectors_left -= $attack_deflectors_died;
	$attacker_armor_left -= $attack_armor_died;
	$target_mines_left -= $target_mines_died;
	$target_mines -= $target_mines_died;

	if($mine_debug != 1)
	{
		$debug_query = $db->Execute("UPDATE {$db_prefix}ships set armor_pts=GREATEST(armor_pts-$attack_armor_died, 0) where ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=GREATEST(amount-$attack_deflectors_died, 0) WHERE device_id=" . $shipdevice['dev_minedeflector']['device_id']);
		db_op_result($debug_query,__LINE__,__FILE__);
	}

	$template_object->assign("end_attacker_armor", NUMBER($attacker_armor_left));
	$template_object->assign("end_attacker_minedeflectors", NUMBER($attack_deflectors_left));
	$template_object->assign("end_target_mines", NUMBER($target_mines));
	$template_object->assign("attacker_minedeflector_result", $attacker_minedeflector_result);

	$attacker_exchange_result = array();
	$template_object->assign("l_cmb_attack_exchange_results", $l_cmb_attack_exchange_results);

	if ($attacker_armor_left > 0)
	{
		if($attack_armor_died != 0)
		{
			$l_chm_armor_left = str_replace("[number]", "<font color=\"green\">" . NUMBER($attacker_armor_left) . "</font>", $l_chm_armor_left);
			$attacker_exchange_result[] = $l_chm_armor_left;

			if($mine_debug != 1)
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
		}

		$l_cmb_attackermine_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">" . NUMBER($attack_armor_died) . "</font>",$l_cmb_attackermine_lost_list);
		$l_cmb_attackermine_lost_list=str_replace("[deflectorslost]","<font color=\"#ff0000\">" . NUMBER($attack_deflectors_died) . "</font>",$l_cmb_attackermine_lost_list);
		playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $l_cmb_sector_defense . " (" . $sectorname . ")", $l_cmb_combat_player) . $l_cmb_attackermine_lost_list);
		$attacker_exchange_result[] = $l_cmb_attackermine_lost_list;
	}
	else
	{
		$pod = $shipdevice['dev_escapepod']['amount'];
		if($mine_debug != 1)
		{
			playerlog($playerinfo['player_id'], "LOG5_SHIP_DESTROYED_MINES", "$destination|$pod");
		}

		if($mine_debug != 1)
		{
			$inputtype[0] = "[chm_playerinfo_character_name]";
			$inputdata[0] = $playerinfo['character_name'];
			$inputtype[1] = "[chm_sector]";
			$inputdata[1] = "<a href=main.php?move_method=real&engage=1&destination=$sectorname>$sectorname</a>";
			message_defense_owner($destination, "l_chm_hewasdestroyedbyyourmines", "lang_check_defenses.inc", "mines", $inputtype, $inputdata);
		}
		$attacker_exchange_result[] = $l_chm_yourshiphasbeendestroyed;

		$move_failed = 1;

		if ($shipdevice['dev_escapepod']['amount'] == 1)
		{
			$attacker_exchange_result[] = $l_cmb_escapepod_launched;
			if($mine_debug != 1)
			{
				player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], $planet_owner['player_id'], $planet_owner['rating'], "killedSDpod");
			}
		}
		else
		{
			$attacker_exchange_result[] = $l_cmb_attacker_escapepod_failure;
			if($mine_debug != 1)
			{
				db_kill_player($playerinfo['player_id'], $planet_owner['player_id'], $planet_owner['rating'], "killedSD");
			}
		}
	}

	if($mine_debug != 1)
	{
		explode_mines($destination, $target_mines_died);
	}
	$template_object->assign("attacker_exchange_result", $attacker_exchange_result);

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sector Defense Mine Combat End:</B></font><BR>Attacker " . $playerinfo['character_name'] . "<br>
	 Mine Deflectors: <B>" . NUMBER($attack_deflectors_left) . "</B><br> 
	 Armor Points: <B>" . NUMBER($attacker_armor_left) . "</B><br>
	Defender ".$planet_owner['character_name'] . "<br>
	 Mines: <B>" . NUMBER($target_mines) . "</B>");

	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/sector_defense/mine_attack.tpl");
}
else
{
	$minesfound = 0;
}

?>