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

$query = "SELECT {$db_prefix}universe.galaxy_id, {$db_prefix}universe.sector_name, {$db_prefix}universe.sg_sector, {$db_prefix}universe.zone_id, {$db_prefix}planets.* FROM {$db_prefix}planets, {$db_prefix}universe WHERE {$db_prefix}planets.owner=$playerinfo[player_id] AND {$db_prefix}planets.base='Y' and {$db_prefix}universe.sector_id ={$db_prefix}planets.sector_id";

if (!empty($sort))
{
	$query .= " ORDER BY";
	if ($sort == "name")
	{
		$query .= " $sort ASC";
	}
	elseif ($sort == "organics" || $sort == "ore" || $sort == "goods" || $sort == "energy" || $sort == "fighters" || $sort == "special")
	{
		$query .= " prod_$sort DESC, sector_name ASC";
	}
	elseif ($sort == "colonists" || $sort == "credits")
	{
		$query .= " $sort DESC, sector_name ASC";
	}
	elseif ($sort == "torp")
	{
		$query .= " prod_torp DESC, sector_name ASC";
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
if ($res)
{
	while (!$res->EOF)
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
		if ($enable_spies)
		{
			spy_detect_planet($shipinfo['ship_id'], $planet[$i]['planet_id'], $planet_detect_success2);
		}
		$i++;
		$res->MoveNext();
	}
}

$num_planets = $i;

$total_colonists = 0;
$total_credits = 0;
$total_team = 0;

$temp_var = 0;

for($i=0; $i<$num_planets; $i++)
{
	$total_colonists += $planet[$i]['colonists'];
	$total_credits += $planet[$i]['credits'];
	if (empty($planet[$i]['name']))
	{
		$planet[$i]['name'] = $l_unnamed;
	}
	$planetsector[$i] = $planet[$i]['sector_name'];
	$planetname[$i] = $planet[$i]['name'];
	$planetid[$i] = $planet[$i]["planet_id"];
	$planetore[$i] = $planet[$i]["prod_ore"];
	$planetorganics[$i] = $planet[$i]["prod_organics"];
	$planetgoods[$i] = $planet[$i]["prod_goods"];
	$planetenergy[$i] = $planet[$i]["prod_energy"];
	$planetspecial[$i] = $planet[$i]["prod_special"];
	$planetspecialname[$i] = get_commodity_name($planet[$i]["special_name"]);
	$planetcolonists[$i] = NUMBER($planet[$i]['colonists']);
	$planetcredits[$i] = NUMBER($planet[$i]['credits']);
	$planetfighters[$i] = $planet[$i]["prod_fighters"];
	$planettorps[$i] = $planet[$i]["prod_torp"];
	$planetresearch[$i] = $planet[$i]["prod_research"];
	$planetbuild[$i] = $planet[$i]["prod_build"];
	$planetzone_id[$i] = ($planet[$i]['sg_sector'] == 0) ? $planet[$i]['zone_id'] : $planet_sg_zone[$planet[$i]['sg_sector']];
	$galaxylocation[$i] = $galaxynames[$planet[$i]['galaxy_id']];
	$galaxylocationgalaxy[$i] = $planet[$i]['galaxy_id'];

	if ($playerinfo['team'] > 0){
		$planetteam[$i] = $planet[$i]['team'];
	}
	$planettcash[$i] = $planet[$i]['team_cash'];
}

$template_object->assign("currentgalaxy", $shipinfo['galaxy_id']);
$template_object->assign("galaxylocationgalaxy", $galaxylocationgalaxy);
$template_object->assign("galaxylocation", $galaxylocation);
$template_object->assign("l_galaxy", $l_galaxy);
$template_object->assign("title", $title);
$template_object->assign("l_pr_special", $l_pr_special);
$template_object->assign("planetspecialname", $planetspecialname);
$template_object->assign("planetspecial", $planetspecial);
$template_object->assign("l_pr_build", $l_pr_build);
$template_object->assign("l_pr_research", $l_pr_research);
$template_object->assign("l_pr_production", $l_pr_production);
$template_object->assign("l_pr_menulink", $l_pr_menulink);
$template_object->assign("playerteam", $playerinfo['team']);
$template_object->assign("num_planets", $num_planets);
$template_object->assign("l_pr_noplanet", $l_pr_noplanet);
$template_object->assign("l_pr_clicktosort", $l_pr_clicktosort);
$template_object->assign("l_pr_sector", $l_pr_sector);
$template_object->assign("l_name", $l_name);
$template_object->assign("l_ore", $l_ore);
$template_object->assign("l_organics", $l_organics);
$template_object->assign("l_goods", $l_goods);
$template_object->assign("l_energy", $l_energy);
$template_object->assign("l_colonists", $l_colonists);
$template_object->assign("l_credits", $l_credits);
$template_object->assign("l_fighters", $l_fighters);
$template_object->assign("l_torps", $l_torps);
$template_object->assign("l_team", $l_team);
$template_object->assign("l_teamcash", $l_teamcash);
$template_object->assign("l_pr_totals", $l_pr_totals);
$template_object->assign("total_colonists", NUMBER($total_colonists));
$template_object->assign("total_credits", NUMBER($total_credits));
$template_object->assign("player_id", $playerinfo['player_id']);
$template_object->assign("l_submit", $l_submit);
$template_object->assign("l_reset", $l_reset);
$template_object->assign("planetzone_id", $planetzone_id);
$template_object->assign("planetsector", $planetsector);
$template_object->assign("planetname", $planetname);
$template_object->assign("planetid", $planetid);
$template_object->assign("planetore", $planetore);
$template_object->assign("planetorganics", $planetorganics);
$template_object->assign("planetgoods", $planetgoods);
$template_object->assign("planetenergy", $planetenergy);
$template_object->assign("planetcolonists", $planetcolonists);
$template_object->assign("planetcredits", $planetcredits);
$template_object->assign("planetfighters", $planetfighters);
$template_object->assign("planettorps", $planettorps);
$template_object->assign("planetresearch", $planetresearch);
$template_object->assign("planetbuild", $planetbuild);
$template_object->assign("planetteam", $planetteam);
$template_object->assign("planettcash", $planettcash);
$template_object->assign("gotomain", $l_global_mmenu);

$template_object->display("master_template/planet_reports/production_view.tpl");
include ("footer.php");
die();

?>