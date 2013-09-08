<?php
// This program is free software; you can redistribute it and/or modify it	 
// under the terms of the GNU General Public License as published by the		 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: traderoute_create.php

include ("config/config.php");
include ("languages/$langdir/lang_traderoute.inc");
include ("languages/$langdir/lang_teams.inc");
include ("languages/$langdir/lang_bounty.inc");
include ("languages/$langdir/lang_ports.inc");

get_post_ifset("editing, ptype1, port_id1, planet_id1, source_planet_commodity, ptype2, port_id2, planet_id2, destination_planet_commodity, move_type, circuit_type, trade_energy, trade_fighters, trade_torps");
get_post_ifset("returnautorouteid, forwardautorouteid");

$port_id1 = trim($port_id1);
$port_id2 = trim($port_id2);

$total_experience = 0;

$title = $l_tdr_title;

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

$result = $db->Execute("SELECT * FROM {$db_prefix}traderoutes WHERE player_id=$playerinfo[player_id]");
$num_traderoutes = $result->RecordCount();

$i = 0;
while (!$result->EOF)
{
	$traderoutes[$i] = $result->fields;
	$i++;
	$result->MoveNext();
}

// Error in trade route

function traderoute_die($error_msg)
{
	global $templatename, $playerinfo, $l_global_mmenu, $total_experience, $l_footer_until_update, $l_footer_players_on_1, $l_footer_players_on_2, $l_footer_one_player_on, $sched_ticks, $template_object;

	$template_object->assign("error_msg", $error_msg);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/traderoutes/traderoute_die.tpl");
	include ("footer.php");
	die();
}

// check if valid trade route

function traderoute_check_compatible($type1, $type2, $move, $circuit, $src, $dest)
{
	global $playerinfo, $shipinfo, $template_object, $forwardautorouteid;
	global $l_tdr_nowlink1, $l_tdr_nowlink2, $l_tdr_sportissrc, $l_tdr_notownplanet, $l_tdr_planetisdest;
	global $l_tdr_samecom, $l_tdr_sportcom, $l_tdr_invalidspoint;
	global $db, $db_prefix;

	if ($move != 'warp')
	{
		$sector_res = $db->SelectLimit("SELECT sg_sector FROM {$db_prefix}universe WHERE sector_id=$src[sector_id] and galaxy_id=$shipinfo[galaxy_id]", 1);
		$src_type = $sector_res->fields['sg_sector'];
		$src_exists = $sector_res->RecordCount();
		$sector_res = $db->SelectLimit("SELECT sg_sector FROM {$db_prefix}universe WHERE sector_id=$dest[sector_id] and galaxy_id=$shipinfo[galaxy_id]", 1);
		$dst_type = $sector_res->fields['sg_sector'];
		$dest_exists = $sector_res->RecordCount();
		if(($src_type != 0) || ($dst_type != 0))
		{
			if($src['sector_id'] != $dest['sector_id']){
				$l_tdr_nowlink1 = str_replace("[tdr_src_sector_id]", $src['sector_name'], $l_tdr_nowlink1);
				$l_tdr_nowlink1 = str_replace("[tdr_dest_sector_id]", $dest['sector_name'], $l_tdr_nowlink1);
				traderoute_die($l_tdr_nowlink1);
			}
		}
		if($src_exists == 0 || $dest_exists == 0){
			$l_tdr_nowlink1 = str_replace("[tdr_src_sector_id]", $src['sector_name'], $l_tdr_nowlink1);
			$l_tdr_nowlink1 = str_replace("[tdr_dest_sector_id]", $dest['sector_name'], $l_tdr_nowlink1);
			traderoute_die($l_tdr_nowlink1);
		}
	}

	//check warp links compatibility
	if ($move == 'warp' && $src['sector_id'] != $dest['sector_id'])
	{
		if($forwardautorouteid == 0)
		{
			$query = $db->SelectLimit("SELECT link_id FROM {$db_prefix}links WHERE link_start=$src[sector_id] AND link_dest=$dest[sector_id]", 1);
			if ($query->EOF)
			{
				$l_tdr_nowlink1 = str_replace("[tdr_src_sector_id]", $src['sector_name'], $l_tdr_nowlink1);
				$l_tdr_nowlink1 = str_replace("[tdr_dest_sector_id]", $dest['sector_name'], $l_tdr_nowlink1);
				traderoute_die($l_tdr_nowlink1);
			}
			if ($circuit == '2')
			{
				$query = $db->SelectLimit("SELECT link_id FROM {$db_prefix}links WHERE link_start=$dest[sector_id] AND link_dest=$src[sector_id]", 1);
				if ($query->EOF)
				{
					$l_tdr_nowlink2 = str_replace("[tdr_src_sector_id]", $src['sector_name'], $l_tdr_nowlink2);
					$l_tdr_nowlink2 = str_replace("[tdr_dest_sector_id]", $dest['sector_name'], $l_tdr_nowlink2);
					traderoute_die($l_tdr_nowlink2);
				}
			}
		}
	}

	//check ports compatibility
	if ($type1 == 'port')
	{
		if ($src['port_type'] == 'upgrades')
		{
			if ($type2 != 'planet')
			traderoute_die($l_tdr_sportissrc);
			if ($dest['owner'] != $playerinfo['player_id'])
			traderoute_die($l_tdr_notownplanet);
		}
		else
		{
			if ($type2 != 'planet')
			{
				if ($src['port_type'] == $dest['port_type'])
				{
					traderoute_die($l_tdr_samecom);
				}
			}
		}
		if ($src['port_type'] == 'devices' || $src['port_type'] == 'casino' || $src['port_type'] == 'spacedock')
		{
				traderoute_die($l_tdr_invalidspoint);
		}
	}
}


	if ($num_traderoutes >= $max_traderoutes_player && empty($editing))
	{
		traderoute_die($l_tdr_maxtdr);
	}

	$port_id1 = trim($port_id1);
	//dbase sanity check for source
	if ($ptype1 == 'port')
	{
		$query = $db->SelectLimit("SELECT * FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr($port_id1), 1);
//		echo $query->RecordCount();
		if (!$query || $query->EOF)
		{
			$l_tdr_errnotvalidport = str_replace("[tdr_port_id]", $port_id1, $l_tdr_errnotvalidport);
			traderoute_die($l_tdr_errnotvalidport);
		}

		$source=$query->fields;
		if ($source['port_type'] == 'none')
		{
			$l_tdr_errnoport = str_replace("[tdr_port_id]", $port_id1, $l_tdr_errnoport);
			traderoute_die($l_tdr_errnoport);
		}

		// ensure that they have been in the sector for the first port, but only if its a valid port type.
		$res1 = $db->SelectLimit("SELECT * from {$db_prefix}sector_log WHERE player_id = $playerinfo[player_id] AND (source = $source[sector_id] or destination = $source[sector_id])", 1);
		if (!$res1 || $res1->EOF)
		{
			traderoute_die($l_tdr_explorefirst);
		}
	}
	else
	{
			$query = $db->SelectLimit("SELECT * FROM {$db_prefix}planets WHERE planet_id=$planet_id1", 1);
			if (!$query || $query->EOF) { traderoute_die($l_tdr_errnosrc); }
			$source=$query->fields;
			if ($source['owner'] != $playerinfo['player_id']) 	{
					$l_tdr_errnotownnotsell = str_replace("[tdr_source_name]", $source['name'], $l_tdr_errnotownnotsell);
					traderoute_die($l_tdr_errnotownnotsell);
			}
	}

	$port_id2 = trim($port_id2);

	if ($ptype2 == 'port')
	{
		$query = $db->SelectLimit("SELECT * FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr($port_id2), 1);
		if (!$query || $query->EOF)
		{
			$l_tdr_errnotvaliddestport = str_replace("[tdr_port_id]", $port_id2, $l_tdr_errnotvaliddestport);
			traderoute_die($l_tdr_errnotvaliddestport);
		}

		$destination=$query->fields;
		if ($destination['port_type'] == 'none') {
			$l_tdr_errnoport2 = str_replace("[tdr_port_id]", $port_id2, $l_tdr_errnoport2);
			traderoute_die($l_tdr_errnoport2);
		}

		$destination=$query->fields;
		if ($destination['port_type'] == 'devices' || $destination['port_type'] == 'casino' || $destination['port_type'] == 'spacedock')
		{
			$l_tdr_errnoport2 = str_replace("[tdr_port_id]", $port_id2, $l_tdr_errnoport2);
			traderoute_die($l_tdr_errnoport2);
		}

		// ensure that they have been in the sector for the second port, but only if its a valid port type.
		$res1 = $db->SelectLimit("SELECT * from {$db_prefix}sector_log WHERE player_id = $playerinfo[player_id] AND (source = $destination[sector_id] or destination = $destination[sector_id])", 1);
		if (!$res1 || $res1->EOF)
		{
			traderoute_die($l_tdr_explorefirst);
		}
	}
	else
	{
		if ($ptype2 == "planet") {
			$query = $db->SelectLimit("SELECT * FROM {$db_prefix}planets WHERE planet_id=$planet_id2", 1);
			if (!$query || $query->EOF) {
				traderoute_die($l_tdr_errnodestplanet);
			}
			$destination=$query->fields;
	
			if ($destination['owner'] != $playerinfo['player_id']) {
				$l_tdr_errnotownnotsell2 = str_replace("[tdr_dest_name]", $destination['name'], $l_tdr_errnotownnotsell2);
				traderoute_die($l_tdr_errnotownnotsell2);
			}
		}
	}

	//check traderoute for src => dest
	traderoute_check_compatible($ptype1, $ptype2, $move_type, $circuit_type, $source , $destination);

	$source_sector = 0;
	$source_planet_id = 0;
	$source_sector = $source['sector_id'];
	$query = $db->SelectLimit("SELECT port_type FROM {$db_prefix}universe WHERE sector_id='$source[sector_id]'", 1);
	$source_commodity = $query->fields['port_type'];
	if ($ptype1 == 'planet')
	{
		$source_planet_id = $planet_id1;
		$source_commodity = $source_planet_commodity;
	}

	$destination_sector = 0;
	$destination_planet_id = 0;
	$destination_sector = $destination['sector_id'];
	$query = $db->SelectLimit("SELECT port_type FROM {$db_prefix}universe WHERE sector_id='$destination[sector_id]'", 1);
	$destination_commodity = $query->fields['port_type'];
	if ($ptype2 == 'planet')
	{
		$destination_planet_id = $planet_id2;
		$destination_commodity = $destination_planet_commodity;
	}

	$source_type = $ptype1;
	$destination_type = $ptype2;

	if ($move_type == 'realspace')
	{
		$mtype = 'R';
		$forwardautorouteid = 0;
		$returnautorouteid = 0;
	}
	else
	{
		$mtype = 'W';
	}

	if($source_sector == $destination_sector)
	{
		$circuit_type = "Y";
	}

	if (empty($editing))
	{
		$debug_query = $db->Execute("INSERT INTO {$db_prefix}traderoutes 
		(source_sector, source_planet_id, source_type, source_commodity, destination_sector, destination_planet_id, destination_type,
		destination_commodity, trade_energy, trade_fighters, trade_torps, move_type, player_id, roundtrip, galaxy_id, forward_autoroute_id, return_autoroute_id)
		VALUES($source_sector, $source_planet_id, '$source_type', '$source_commodity', $destination_sector, $destination_planet_id, '$destination_type',
		'$destination_commodity', '$trade_energy', '$trade_fighters', '$trade_torps', '$mtype', $playerinfo[player_id], '$circuit_type', $shipinfo[galaxy_id], $forwardautorouteid, $returnautorouteid)");
		db_op_result($debug_query,__LINE__,__FILE__);
		$template_object->assign("l_changed", $l_tdr_newtdrcreated);
	}
	else
	{
		$debug_query = $db->Execute("UPDATE {$db_prefix}traderoutes SET 
		source_sector=$source_sector, source_planet_id=$source_planet_id, source_type='$source_type', source_commodity='$source_commodity',
		destination_sector=$destination_sector, destination_planet_id=$destination_planet_id, destination_type='$destination_type', destination_commodity='$destination_commodity',
		trade_energy='$trade_energy', trade_fighters='$trade_fighters', trade_torps='$trade_torps', move_type='$mtype', player_id=$playerinfo[player_id], galaxy_id=$shipinfo[galaxy_id], forward_autoroute_id=$forwardautorouteid, return_autoroute_id=$returnautorouteid, 
		roundtrip='$circuit_type' WHERE traderoute_id=$editing");
		db_op_result($debug_query,__LINE__,__FILE__);
		$template_object->assign("l_changed", $l_tdr_tdrmodified);
	}

	$template_object->assign("l_tdr_returnmenu", $l_tdr_returnmenu);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/traderoutes/traderoute_save.tpl");
	include ("footer.php");

?>
