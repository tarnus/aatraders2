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
include ("globals/get_commodity_name.inc");
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

//-------------------------------------------------------------------------------------------------

$template_object->assign("title", $title);
$template_object->assign("templatename", $templatename);

$result = $db->Execute("SELECT count(traderoute_id) as total FROM {$db_prefix}traderoutes WHERE player_id=$playerinfo[player_id]");
$num_traderoutes = $result->fields['total'];

if ($num_traderoutes >= $max_traderoutes_player)
{
	$template_object->assign("error_msg", $l_tdr_maxtdr);
	$template_object->assign("gotomain", $l_global_mmenu);
	$template_object->display("master_template/traderoutes/traderoute_die.tpl");
	include ("footer.php");
	die();
}

$template_object->assign("l_tdr_createnew", $l_tdr_createnew);
$template_object->assign("l_tdr_traderoute", $l_tdr_traderoute);

$result = $db->Execute("SELECT {$db_prefix}planets.* FROM {$db_prefix}planets, {$db_prefix}universe WHERE {$db_prefix}planets.owner=$playerinfo[player_id] and {$db_prefix}universe.sector_id={$db_prefix}planets.sector_id and {$db_prefix}universe.galaxy_id=$shipinfo[galaxy_id] ORDER BY {$db_prefix}planets.sector_id");
db_op_result($result,__LINE__,__FILE__);

$num_planets = $result->RecordCount();
$i=0;
while (!$result->EOF)
{
	$planets[$i] = $result->fields;
	if ($planets[$i]['name'] == "")
		$planets[$i]['name'] = $l_tdr_unnamed;
	$i++;
	$result->MoveNext();
}

$template_object->assign("l_tdr_cursector", $l_tdr_cursector);
$template_object->assign("shipsector", $sectorinfo['sector_name']);

$template_object->assign("l_tdr_selspoint", $l_tdr_selspoint);
$template_object->assign("l_tdr_port", $l_tdr_port);

//-------------------- Personal Planet
$template_object->assign("l_tdr_planet", $l_tdr_planet);
$template_object->assign("num_planets", $num_planets);
$template_object->assign("l_tdr_none", $l_tdr_none);
$planetspecial = "";
if ($num_planets != 0)
{
	$planetcount=0;
	while ($planetcount < $num_planets)
	{
		if ($planets[$planetcount]['planet_id'] == $editroute['source_id']){
			$planetselected[$planetcount] = "selected ";
		}else{
			$planetselected[$planetcount] = " ";
		}
		$planetid[$planetcount] = $planets[$planetcount]['planet_id'];
		$planetname[$planetcount] = $planets[$planetcount]['name'];
		$planetspecial .= "planetspecial[" . $planetid[$planetcount] . "] = '" . $planets[$planetcount]['special_name'] . "';\n";
		$name_result = $db->SelectLimit("SELECT * FROM {$db_prefix}universe WHERE sector_id=" . $planets[$planetcount]['sector_id'], 1);
		$planetsectorid[$planetcount] = $name_result->fields['sector_name'];
		$planetcount++;
	}
}
$template_object->assign("planetspecial", $planetspecial);
$template_object->assign("planetcount", $planetcount);
$template_object->assign("planetselected", $planetselected);
$template_object->assign("l_tdr_insector", $l_tdr_insector);
$template_object->assign("planetid", $planetid);
$template_object->assign("planetname", $planetname);
$template_object->assign("planetsectorid", $planetsectorid);

$commodity_item_count=1;
$commodity_commodity_type[0] = "None";
$commodity_commodity_type_name[0] = $l_none;
$debug_query = $db->Execute("SELECT classname FROM {$db_prefix}class_modules_commodities WHERE defaultcargoplanet=1");
db_op_result($debug_query,__LINE__,__FILE__);
while(!$debug_query->EOF){
	$commodity_commodity_type[$commodity_item_count] = $debug_query->fields['classname'];
	$commodity_commodity_type_name[$commodity_item_count] = get_commodity_name($commodity_commodity_type[$commodity_item_count]);
	$commodity_item_count++;
	$debug_query->MoveNext();
}

$template_object->assign("commodity_item_count", $commodity_item_count);
$template_object->assign("commodity_commodity_type", $commodity_commodity_type);
$template_object->assign("commodity_commodity_type_name", $commodity_commodity_type_name);

$template_object->assign("l_tdr_selendpoint", $l_tdr_selendpoint);

$template_object->assign("l_tdr_selmovetype", $l_tdr_selmovetype);
$template_object->assign("l_tdr_realspace", $l_tdr_realspace);
$template_object->assign("l_tdr_warp", $l_tdr_warp);
$template_object->assign("l_tdr_selcircuit", $l_tdr_selcircuit);
$template_object->assign("l_tdr_oneway", $l_tdr_oneway);
$template_object->assign("l_tdr_bothways", $l_tdr_bothways);
$template_object->assign("l_tdr_create", $l_tdr_create);
$template_object->assign("l_tdr_returnmenu", $l_tdr_returnmenu);
$template_object->assign("l_tdr_tdrescooped", $l_tdr_tdrescooped);
$template_object->assign("l_tdr_trade", $l_tdr_trade);
$template_object->assign("l_tdr_keep", $l_tdr_keep);
$template_object->assign("l_tdr_fighters", $l_tdr_fighters);
$template_object->assign("l_tdr_torps", $l_tdr_torps);
$template_object->assign("l_upgrade_ports", $l_upgrade_ports);
$template_object->assign("l_port", $l_port);
$template_object->assign("l_trade", $l_trade);
$template_object->assign("l_commodity", $l_commodity);
$template_object->assign("l_planets", $l_planets);
$template_object->assign("l_tdr_noneavailable", $l_tdr_noneavailable);
$template_object->assign("l_tdr_autoroute", $l_tdr_autoroute);

$template_object->assign("gotomain", $l_global_mmenu);
$template_object->display("master_template/traderoutes/traderoute_create.tpl");
include ("footer.php");

?>
