<?php
$query = "SELECT count(planet_id) as total FROM {$db_prefix}planets WHERE owner=$playerinfo[player_id]";
$res = $db->SelectLimit($query, 1);
$totalplanets = $res->fields['total'];
$res->close();

$start = ($page - 1) * $entries_per_page;
$totalpages = ceil($totalplanets / $entries_per_page);
$template_object->assign("currentpage", $page);
if($page < $totalpages)
{
	$next = $page + 1;
}
else
{
	$next = $page;
}
$template_object->assign("nextpage", $next);
if($page > 1)
{
	$prev = $page - 1;
}
else
{
	$prev = 1;
}
$template_object->assign("previouspage", $prev);
$template_object->assign("totalpages", $totalpages);
$template_object->assign("totalplanets", $totalplanets);

$galaxynames = array();
$result2 = $db->Execute("SELECT galaxy_id, galaxy_name FROM {$db_prefix}universe_galaxy");
db_op_result($result2,__LINE__,__FILE__);
while (!$result2->EOF)
{
	$galaxy_id = $result2->fields['galaxy_id'];
	$galaxynames[$galaxy_id] = $result2->fields['galaxy_name'];
	$result2->MoveNext();
}
$result2->close();

$galaxylocation = array();
$galaxylocationgalaxy = array();

$query = "SELECT {$db_prefix}universe.galaxy_id, {$db_prefix}universe.sector_name, {$db_prefix}universe.zone_id, {$db_prefix}universe.sg_sector, {$db_prefix}planets.* FROM {$db_prefix}planets, {$db_prefix}universe WHERE {$db_prefix}planets.owner=$playerinfo[player_id] and {$db_prefix}universe.sector_id ={$db_prefix}planets.sector_id";

if(!empty($sort))
{
	$query .= " ORDER BY";
	if($sort == "name")
	{
		$query .= " $sort ASC";
	}
	elseif($sort == "fighter" || $sort == "sensors" || $sort == "beams" || $sort == "torp_launchers" ||  
		$sort == "shields" || $sort == "cloak" || $sort == "base" || $sort == "jammer")
	{
		$query .= " $sort DESC, sector_name ASC";
	}
	elseif ($sort == "galaxy")
	{
		$query .= " galaxy_id ASC, sector_name ASC";
	}
	else
	{
		$query .= " sector_name ASC";
	}
}
else
{
	$query .= " ORDER BY sector_name ASC";
}

$res = $db->SelectLimit($query, $entries_per_page, $start);

$planet_sg_zone = array();
$i = 0;
if($res)
{
	while(!$res->EOF)
	{
		$planet[$i] = $res->fields;
		if($planet[$i]['sg_sector'] == 0)
		{
			$planet_sg_zone[$planet[$i]['sector_id']] = $planet[$i]['zone_id'];
		}
		else
		{
			if(!isset($planet_sg_zone[$planet[$i]['sg_sector']]))
			{
				$query = "SELECT zone_id FROM {$db_prefix}universe WHERE sector_id=" . $planet[$i]['sg_sector'];
				$getzone = $db->SelectLimit($query, 1);
				$planet_sg_zone[$planet[$i]['sg_sector']] = $getzone->fields['zone_id'];
			}
		}

//echo $planet[$i]['sector_id'] . " - " . $planet[$i]['sg_sector'] . " - " . $planet[$i]['zone_id'] . "<br>";
		if($enable_spies)
		{
			spy_detect_planet($shipinfo['ship_id'], $planet[$i]['planet_id'], $planet_detect_success2);
		}
		$i++;
		$res->MoveNext();
	}
}

$num_planets = $i;

$total_base = 0;

for($i=0; $i<$num_planets; $i++)
{
	if(empty($planet[$i]['name']))
	{
		$planet[$i]['name'] = $l_unnamed;
	}
	$planetsector[$i] = $planet[$i]['sector_name'];
	$planetname[$i] = $planet[$i]['name'];
	$planetfighter[$i] = NUMBER($planet[$i]['fighter']);
	$planetsensors[$i] = NUMBER($planet[$i]['sensors']);
	$planetbeams[$i] = NUMBER($planet[$i]['beams']);
	$planettorps[$i] = NUMBER($planet[$i]['torp_launchers']);
	$planetshields[$i] = NUMBER($planet[$i]['shields']);
	$planetjammer[$i] = NUMBER($planet[$i]['jammer']);
	$planetcloak[$i] = NUMBER($planet[$i]['cloak']);
	$planetsdweapons[$i] = NUMBER($planet[$i]['sector_defense_weapons']);
	$planetsdsensors[$i] = NUMBER($planet[$i]['sector_defense_sensors']);
	$planetsdcloak[$i] = NUMBER($planet[$i]['sector_defense_cloak']);
	$planetbase[$i] = $planet[$i]['base'];
	$planetbaseitems[$i] = ($planet[$i]['ore'] >= $base_ore && $planet[$i]['organics'] >= $base_organics && $planet[$i]['goods'] >= $base_goods && $planet[$i]['credits'] >= $base_credits);
	$planetid[$i] = $planet[$i]["planet_id"];
	$planetzone_id[$i] = ($planet[$i]['sg_sector'] == 0) ? $planet[$i]['zone_id'] : $planet_sg_zone[$planet[$i]['sg_sector']];
	$galaxylocation[$i] = $galaxynames[$planet[$i]['galaxy_id']];
	$galaxylocationgalaxy[$i] = $planet[$i]['galaxy_id'];
//echo $planet[$i]['sg_sector'] . " - " . $planetzone_id[$i] . "<br>";

	$total_base += 1;
}

$template_object->assign("currentgalaxy", $shipinfo['galaxy_id']);
$template_object->assign("galaxylocationgalaxy", $galaxylocationgalaxy);
$template_object->assign("galaxylocation", $galaxylocation);
$template_object->assign("l_galaxy", $l_galaxy);
$template_object->assign("title", $title);
$template_object->assign("l_pr_menulink", $l_pr_menulink);
$template_object->assign("playerteam", $playerinfo['team']);
$template_object->assign("num_planets", $num_planets);
$template_object->assign("l_pr_clicktosort", $l_pr_clicktosort);
$template_object->assign("l_pr_totals", $l_pr_totals);
$template_object->assign("total_base", $total_base);
$template_object->assign("l_yes", $l_yes);
$template_object->assign("l_no", $l_no);
$template_object->assign("l_pr_build", $l_pr_build);
$template_object->assign("planetsector", $planetsector);
$template_object->assign("planetname", $planetname);
$template_object->assign("planetfighter", $planetfighter);
$template_object->assign("planetsensors", $planetsensors);
$template_object->assign("planetbeams", $planetbeams);
$template_object->assign("planettorps", $planettorps);
$template_object->assign("planetshields", $planetshields);
$template_object->assign("planetjammer", $planetjammer);
$template_object->assign("planetcloak", $planetcloak);
$template_object->assign("planetsdweapons", $planetsdweapons);
$template_object->assign("planetsdsensors", $planetsdsensors);
$template_object->assign("planetsdcloak", $planetsdcloak);
$template_object->assign("planetbase", $planetbase);
$template_object->assign("planetbaseitems", $planetbaseitems);
$template_object->assign("planetid", $planetid);
$template_object->assign("planetzone_id", $planetzone_id);
$template_object->assign("l_pr_sector", $l_pr_sector);
$template_object->assign("l_name", $l_name);
$template_object->assign("l_fighter", $l_fighter);
$template_object->assign("l_sensors", $l_sensors);
$template_object->assign("l_beams", $l_beams);
$template_object->assign("l_torp_launch", $l_torp_launch);
$template_object->assign("l_shields", $l_shields);
$template_object->assign("l_jammer", $l_jammer);
$template_object->assign("l_cloak", $l_cloak);
$template_object->assign("l_base", $l_base);
$template_object->assign("l_pr_noplanet", $l_pr_noplanet);

$template_object->assign("l_planetary_SD_weapons", $l_planetary_SD_weapons);
$template_object->assign("l_planetary_SD_sensors", $l_planetary_SD_sensors);
$template_object->assign("l_planetary_SD_cloak", $l_planetary_SD_cloak);

$template_object->assign("gotomain", $l_global_mmenu);
$template_object->display("master_template/planet_reports/defenses.tpl");

?>