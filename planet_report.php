<?php
// This program is free software; you can redistribute it and/or modify it	 
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: planet_report.php

include ("config/config.php");
include ("languages/$langdir/lang_planet_report.inc");
include ("languages/$langdir/lang_planets.inc");
include("languages/$langdir/lang_report.inc");
include ("languages/$langdir/lang_teams.inc");
include ("languages/$langdir/lang_ports.inc");
include ("globals/spy_detect_planet.inc");
include ("globals/get_commodity_name.inc");

get_post_ifset("commandpage, sort, page");

if(empty($page))
{
	$page = 1;
}

$title = $l_pr_title;

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

$entries_per_page = 25;
$template_object->assign("sort", $sort);
$template_object->assign("l_submit", $l_submit);
$template_object->assign("l_rpt_prev", $l_rpt_prev);
$template_object->assign("l_rpt_next", $l_rpt_next);
$template_object->assign("l_rpt_totalpages", $l_rpt_totalpages);
$template_object->assign("l_rpt_selectpage", $l_rpt_selectpage);
$template_object->assign("l_rpt_page", $l_rpt_page);

$template_object->assign("l_pr_planetstatus", $l_pr_planetstatus);
$template_object->assign("l_pr_pdefense", $l_pr_pdefense);
$template_object->assign("l_pr_changeprods", $l_pr_changeprods);
$template_object->assign("l_pr_baserequired", $l_pr_baserequired);
$template_object->assign("l_pr_prod_disp", $l_pr_prod_disp);
$template_object->assign("l_pr_teamlink", $l_pr_teamlink);
$template_object->assign("l_pr_showtd", $l_pr_showtd);
$template_object->assign("l_pr_showd", $l_pr_showd);
$template_object->assign("l_pr_comm_disp", $l_pr_comm_disp);
$template_object->assign("l_pr_display", $l_pr_display);
$template_object->assign("l_pr_team_disp", $l_pr_team_disp);
$template_object->assign("l_pr_menulink", $l_pr_menulink);

if($commandpage == "")
{
	$template_object->display("master_template/planet_reports/menu.tpl");
}
else
{
	include ("planet_reports/" . AAT_strtolower($commandpage) . ".inc");
}

include ("footer.php");
close_database();
?>
