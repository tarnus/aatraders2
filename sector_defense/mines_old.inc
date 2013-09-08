<?php
include ("languages/$langdir/lang_check_defenses.inc");
include ("languages/$langdir/lang_combat.inc");
include ("globals/db_kill_player.inc");
include ("globals/player_ship_destroyed.inc");
include ("globals/explode_mines.inc");
include ("globals/message_defense_owner.inc");
include ("globals/planet_bounty_check.inc");

$template_object->assign("l_cmb_SD_attacking", str_replace("[sector]", $destination_name, $l_cmb_SD_mines_attacking));

// Lets blow up some mines!
$totalmines = isset($defenses['mines']) ? $defenses['mines'] : 0;

if ($totalmines > 1)
{
	$defending_mines = abs(mt_rand(1, $totalmines));
}
else
{
	$defending_mines = 0;
}

$sector_check = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_id='$destination'", 1);
if($sector_check->RecordCount())
{
	$sect = $sector_check->fields;
	$sectorname = $sect['sector_name'];
}
$sector_check->close();

if($shipinfo['hull_normal'] > $mine_hullsize && $defending_mines != 0)
{
	$debug_query = $db->SelectLimit("SELECT * FROM {$db_prefix}ships WHERE player_id=$playerinfo[player_id] AND ship_id=$playerinfo[currentship]", 1);
	db_op_result($debug_query,__LINE__,__FILE__);
	$shipinfo = $debug_query->fields;
	$debug_query->close();

	// If the attacker would get a bounty by attacking the most powerful planet in the sector then their A&R is useless.
	$isfedbounty = planet_bounty_check($playerinfo, $destination, $planet_owner, 0);
	if($isfedbounty > 0)
	{
		$attacker_torps_left = 0;
		$attacker_fighters_left = 0;
	}
	$template_object->assign("isfedbounty", $isfedbounty);
	$template_object->assign("l_by_nofedbounty", $l_by_nofedbountyplanet);
	$template_object->assign("l_by_fedbounty2", $l_by_fedbounty);

	$playershields = NUM_SHIELDS($shipinfo['shields']);
	if ($playershields > $shipinfo['energy'])
	{
		$playershields = $shipinfo['energy'];
	}

	$template_object->assign("l_cmb_attacker_shields", $l_cmb_attacker_shields);
	$template_object->assign("start_attacker_shields", NUMBER($playershields));
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

	$defenses['mines'] = $totalmines - $defending_mines;
	$l_chm_youhitsomemines = str_replace("[chm_roll]", NUMBER($defending_mines), $l_chm_youhitsomemines);
	$l_chm_youhitsomemines = str_replace("[total_mines]", NUMBER($totalmines), $l_chm_youhitsomemines);
	$attacker_minedeflector_result[] = $l_chm_youhitsomemines;
	playerlog($playerinfo['player_id'], "LOG5_HIT_MINES", "$defending_mines|$destination");

	$inputtype[0] = "[chm_playerinfo_character_name]";
	$inputdata[0] = $playerinfo['character_name'];
	$inputtype[1] = "[chm_roll]";
	$inputdata[1] = $defending_mines;
	$inputtype[2] = "[chm_sector]";
	$inputdata[2] = "<a href=main.php?move_method=real&engage=1&destination=$sectorname>$sectorname</a>";
	message_defense_owner($destination, "l_chm_hehitminesinsector", "lang_check_defenses.inc", "mines", $inputtype, $inputdata);

	if ($attacker_minedeflectors >= $defending_mines)
	{
		$l_chm_youlostminedeflectors = str_replace("[chm_roll]", NUMBER($defending_mines), $l_chm_youlostminedeflectors);
		$attacker_minedeflector_result[] = $l_chm_youlostminedeflectors;
		$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount-$defending_mines WHERE device_id=" . $shipdevice['dev_minedeflector']['device_id']);
		db_op_result($debug_query,__LINE__,__FILE__);
		$attacker_minedeflectors -= $defending_mines;
		$target_mines -= $defending_mines;
	}
	else
	{
		if ($attacker_minedeflectors > 0)
		{
			$attacker_minedeflector_result[] = $l_chm_youlostallminedeflectors;
		}
		else
		{
			$attacker_minedeflector_result[] = $l_chm_youhadnominedeflectors;
		}

		$mines_left = $defending_mines - $attacker_minedeflectors;

		if ($playershields > $mines_left)
		{
			$l_chm_yourshieldshitforminesdmg = str_replace("[chm_mines_left]", NUMBER($mines_left), $l_chm_yourshieldshitforminesdmg);
			$attacker_minedeflector_result[] = $l_chm_yourshieldshitforminesdmg;
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships set energy=energy-$mines_left WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=0 WHERE device_id=" . $shipdevice['dev_minedeflector']['device_id']);
			db_op_result($debug_query,__LINE__,__FILE__);
			$playershields -= $mines_left;
			$target_mines -= $defending_mines;
		}
		else
		{
			$attacker_minedeflector_result[] = $l_chm_youlostallyourshields;
			$mines_left -= $playershields;
			$playershields = 0;
			if ($attacker_armor > $mines_left)
			{
				$l_chm_yourarmorhitforminesdmg = str_replace("[chm_mines_left]", NUMBER($mines_left), $l_chm_yourarmorhitforminesdmg);
				$attacker_minedeflector_result[] = $l_chm_yourarmorhitforminesdmg;
				$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=armor_pts-$mines_left,energy=0 WHERE ship_id=$shipinfo[ship_id]");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=0 WHERE device_id=" . $shipdevice['dev_minedeflector']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
				$attacker_armor -= $mines_left;

				calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts'] - $attacker_armor) / $shipinfo['armor_pts']);
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

				$attacker_minedeflector_result[] = $l_cmb_attacker_tech_drop;
				$target_mines -= $defending_mines;
			}
			else
			{
				$attacker_minedeflector_result[] = $l_chm_yourhullisbreached;
				playerlog($playerinfo['player_id'], "LOG5_SHIP_DESTROYED_MINES", "$destination|" . $shipdevice['dev_escapepod']['amount']);
				$mines_left -= $attacker_armor;
				$target_mines -= ($defending_mines - $mines_left);
				explode_mines($destination, ($defending_mines - $mines_left));

				$template_object->assign("end_attacker_shields", $playershields);
				$template_object->assign("end_attacker_armor", $attacker_armor);
				$template_object->assign("end_attacker_minedeflectors", $attacker_minedeflectors);
				$template_object->assign("end_target_mines", $target_mines);

				$attacker_exchange_result = array();
				$template_object->assign("l_cmb_attack_exchange_results", $l_cmb_attack_exchange_results);

				$armor_lost = max(($shipinfo['armor_pts'] - $attacker_armor), 0);
				$energy_lost = max(($shipinfo['energy'] - $playershields), 0);
				$minedeflectors_lost = max(($shipdevice['dev_minedeflector']['amount'] - $attacker_minedeflectors), 0);

				$l_cmb_SD_attacker_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">". NUMBER($armor_lost) . "</font>",$l_cmb_SD_attacker_lost_list);
				$l_cmb_SD_attacker_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">". NUMBER($energy_lost) . "</font>",$l_cmb_SD_attacker_lost_list);
				$l_cmb_SD_attacker_lost_list=str_replace("[deflectorslost]","<font color=\"#ff0000\">". NUMBER($minedeflectors_lost) . "</font>",$l_cmb_SD_attacker_lost_list);
				$attacker_exchange_result[] = $l_cmb_SD_attacker_lost_list;
				playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $targetname, $l_cmb_combat_player) . $l_cmb_SD_attacker_lost_list);

				$template_object->assign("attacker_exchange_result", $attacker_exchange_result);

				$template_object->assign("gotomain", $l_global_mmenu);
				$template_object->display("master_template/sector_defense/mine_attack.tpl");

				$template_object->assign("error_msg", $l_cmb_attacker_ship_destroyed);

				$inputtype[0] = "[chm_playerinfo_character_name]";
				$inputdata[0] = $playerinfo['character_name'];
				$inputtype[1] = "[chm_sector]";
				$inputdata[1] = "<a href=main.php?move_method=real&engage=1&destination=$sectorname>$sectorname</a>";
				message_defense_owner($destination, "l_chm_hewasdestroyedbyyourmines", "lang_check_defenses.inc", "mines", $inputtype, $inputdata);

				if ($shipdevice['dev_escapepod']['amount'] == 1) 
				{
					$template_object->assign("error_msg2", $l_cmb_escapepod_launched);
					player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], 0, 0, "killedSDpod", "Y");
				}
				else
				{
					$template_object->assign("error_msg2", $l_cmb_attacker_escapepod_failure);
					db_kill_player($playerinfo['player_id'], 0, 0, "killedSD", "Y");
				}
				$template_object->assign("gotomain", $l_global_mmenu);
				$template_object->display("master_template/genericdie.tpl");
				include ("footer.php");
				die();
			}
		}
	}
	explode_mines($destination, $defending_mines);

	$template_object->assign("end_attacker_shields", NUMBER($playershields));
	$template_object->assign("end_attacker_armor", NUMBER($attacker_armor));
	$template_object->assign("end_attacker_minedeflectors", NUMBER($attacker_minedeflectors));
	$template_object->assign("end_target_mines", NUMBER($target_mines));
	$template_object->assign("attacker_minedeflector_result", $attacker_minedeflector_result);

	$attacker_exchange_result = array();
	$template_object->assign("l_cmb_attack_exchange_results", $l_cmb_attack_exchange_results);

	$armor_lost = max(($shipinfo['armor_pts'] - $attacker_armor), 0);
	$energy_lost = max(($shipinfo['energy'] - $playershields), 0);
	$minedeflectors_lost = max(($shipdevice['dev_minedeflector']['amount'] - $attacker_minedeflectors), 0);

	$l_cmb_SD_attacker_lost_list=str_replace("[armorlost]","<font color=\"#ff0000\">". NUMBER($armor_lost) . "</font>",$l_cmb_SD_attacker_lost_list);
	$l_cmb_SD_attacker_lost_list=str_replace("[energylost]","<font color=\"#ff0000\">". NUMBER($energy_lost) . "</font>",$l_cmb_SD_attacker_lost_list);
	$l_cmb_SD_attacker_lost_list=str_replace("[deflectorslost]","<font color=\"#ff0000\">". NUMBER($minedeflectors_lost) . "</font>",$l_cmb_SD_attacker_lost_list);
	$attacker_exchange_result[] = $l_cmb_SD_attacker_lost_list;
	playerlog($playerinfo['player_id'], "LOG5_AFTER_ACTION", str_replace("[player]", $targetname, $l_cmb_combat_player) . $l_cmb_SD_attacker_lost_list);

	$template_object->assign("attacker_exchange_result", $attacker_exchange_result);

	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/sector_defense/mine_attack.tpl");
}
else
{
	$minesfound = 0;
}
?>