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

echo __FILE__ . " = " . str_replace("test.php","",__FILE__);

echo "ECM Check Full Attack<br><br>";
$result = ecmcheck("50", "30", $full_attack_modifier);
echo "Low Percent 30: " . $result[0] . "<br>";
echo "High Percent 30: " . $result[1] . "<br>";
$result = ecmcheck("500", "300", $full_attack_modifier);
echo "Low Percent 300: " . $result[0] . "<br>";
echo "High Percent 300: " . $result[1] . "<br>";
echo "<hr>";

echo "ECM Check A&R<br><br>";
$result = ecmcheck("50", "30", $attack_run_modifier);
echo "Low Percent 30: " . $result[0] . "<br>";
echo "High Percent 30: " . $result[1] . "<br>";
$result = ecmcheck("500", "300", $attack_run_modifier);
echo "Low Percent 300: " . $result[0] . "<br>";
echo "High Percent 300: " . $result[1] . "<br>";
echo "<hr>";


echo "Calc Internal Damage Ship<br><br>";
$result = calc_internal_damage(1, 0, 0.50, true);
echo "<hr>";

echo "Calc Internal Damage Planet<br><br>";
$result = calc_internal_damage(1, 1, 0.50, true);
echo "<hr>";

echo "Calc Failure 10<br><br>";
$reliability_modifier = 0.5;
$failure_modifier = 1;
$result = calc_failure(100000000, 30, 5);
echo "Calc Failure 100<br><br>";
$reliability_modifier = 0.05;
$failure_modifier = 0.1;
$result = calc_failure(100000000, 300, 50);
echo "<hr>";

echo "Calc Damage 10<br>";
$reliability_modifier = 0.5;
$failure_modifier = 1;
$confusion_modifier = 1.8;
$attackerlowpercent = ecmcheck("50", "30", $full_attack_modifier);
echo "Low Percent 30: " . $attackerlowpercent[0] . "<br>";
echo "High Percent 30: " . $attackerlowpercent[1] . "<br>";
$result = calc_damage(100000, 2000, $attackerlowpercent, 30, 50);
echo "<br>Calc Damage 100<br>";
$reliability_modifier = 0.05;
$failure_modifier = 0.1;
$confusion_modifier = 0.18;
$attackerlowpercent = ecmcheck("500", "300", $full_attack_modifier);
echo "Low Percent 30: " . $attackerlowpercent[0] . "<br>";
echo "High Percent 30: " . $attackerlowpercent[1] . "<br>";
$result = calc_damage(100000, 2000, $attackerlowpercent, 300, 500);
echo "<hr>";

$attackerlowpercent = ecmcheck(300, 250, 50 + floor((250 - 300) * 0.25));
$targetlowpercent = ecmcheck(250, 300, -(50 + floor((250 - 300) * 0.25)));
echo "alp: $attackerlowpercent[0] - tlp: $targetlowpercent[0]<br>";
echo "alp: $attackerlowpercent[1] - tlp: $targetlowpercent[1]<br>";
$target_fighter_damage = calc_damage(100000000, 1000, $targetlowpercent, 200, 200);
echo nl2br(print_r($target_fighter_damage, true));
$ratio = $target_fighter_damage[0] / (100000000 * 1000) * $target_fighter_damage[0];
echo "Ratio: $ratio<br>";
echo"<hr>";
$attackerlowpercent = ecmcheck(250, 300, 50 + floor((300 - 250) * 0.25));
$targetlowpercent = ecmcheck(300, 250, -(50 + floor((300 - 250) * 0.25)));
echo "alp: $attackerlowpercent[0] - tlp: $targetlowpercent[0]<br>";
echo "alp: $attackerlowpercent[1] - tlp: $targetlowpercent[1] - " . -(75 + floor((100 - 350) * 0.25)) . "<br>";
$target_fighter_damage = calc_damage(100000000, 1000, $targetlowpercent, 100, 300);
echo nl2br(print_r($target_fighter_damage, true));
$ratio = $target_fighter_damage[0] / (100000000 * 1000);
echo "Ratio: $ratio<br>";
echo"<hr>";
$attackerlowpercent = ecmcheck(300, 100, 50 + floor((100 - 300) * 0.25));
$targetlowpercent = ecmcheck(100, 300, -(50 + floor((100 - 300) * 0.25)));
echo "alp: $attackerlowpercent[0] - tlp: $targetlowpercent[0]<br>";
echo "alp: $attackerlowpercent[1] - tlp: $targetlowpercent[1] - " . -(75 + floor((100 - 350) * 0.25)) . "<br>";
$target_fighter_damage = calc_damage(100000000, 1000, $targetlowpercent, 100, 300);
echo nl2br(print_r($target_fighter_damage, true));
$ratio = $target_fighter_damage[0] / (100000000 * 1000);
echo "Ratio: $ratio<br>";

$result4 = $db->SelectLimit("SELECT MAX(sh.hull) AS hull_max, MAX(sh.ecm) AS ecm_max, MAX(sh.cloak) AS cloak_max, MAX(sh.armor) AS armor_max, MAX(sh.shields) AS shields_max, MAX(sh.engines) AS engines_max, MAX(sh.power) AS power_max, MAX(sh.fighter) AS fighter_max, MAX(sh.sensors) AS sensors_max, MAX(sh.beams) AS beams_max, MAX(sh.torp_launchers) AS torp_launchers_max FROM {$db_prefix}ships as sh,  {$db_prefix}players as pl where pl.player_id=sh.player_id and pl.npc=0", 1);
db_op_result($result4,__LINE__,__FILE__);
$max_list = $result4->fields;
$result4->close();

echo nl2br(print_r($max_list, true));

echo "<hr>";

$playerinfo[player_id] = 3;
$playerinfo[team] = 3;
$shipinfo[sector_id] = 483;
$db->debug = 1;
$resultSDb = $db->Execute("SELECT {$db_prefix}sector_defense.quantity, {$db_prefix}sector_defense.defense_id, {$db_prefix}sector_defense.defense_type  from {$db_prefix}sector_defense, {$db_prefix}players WHERE 
{$db_prefix}sector_defense.sector_id=$shipinfo[sector_id] and {$db_prefix}sector_defense.player_id != '$playerinfo[player_id]'
and (({$db_prefix}players.player_id = {$db_prefix}sector_defense.player_id) and ({$db_prefix}players.team != $playerinfo[team] or $playerinfo[team] = 0)) and {$db_prefix}sector_defense.defense_type = 'fighters'");
db_op_result($resultSDb,__LINE__,__FILE__);
$db->debug = 0;

echo "Total SD: " . $resultSDb->fields['quantity'];

echo "<hr>";
echo number(phpChangePlanetDelta(400, 0));
echo "<hr>";
echo number(phpChangePlanetDelta(400, 0) / 400);

$time = $db->query_time_total;
$resultSDb = $db->Execute("SHOW TABLE STATUS FROM pj LIKE 'aatrade_sector_log'");
$time = $db->query_time_total - $time;
echo sprintf("%01.4f", $time);
echo "<hr>";

$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}planets ORDER BY rand()", 1);
db_op_result($findem,__LINE__,__FILE__);
echo "Sector: " . $findem->fields['sector_id'];

echo "<hr>";

$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}Universe ORDER BY rand()", 1);
echo "Sector: " . $findem->fields['sector_id'];

echo "<hr>";

$template_object->assign('data',array(1,2,3,4,5,6,7,8,9,10));
$template_object->assign('tr',array('bgcolor="#eeeeee"','bgcolor="#dddddd"'));
$template_object->display($templatename.'test.tpl');

//$template_object->left_delimiter = "{";
//$template_object->right_delimiter = "}";

$file_contents = '<H1><?tpl $Title ?></H1><hr>
<?php echo $Title;?>
<? //stuff ?>
<?php //stuff2 ?>
<hr>
<?$no_body?>
<?tpl$no_body?>
';
echo "<hr>" . htmlentities(preg_replace('/<\?=(.*?)\?>/', '<?php echo \\1?>'."\n", $file_contents)) . "<hr>";
echo "<hr>" . htmlentities(preg_replace('%(<\?(?!php|=|$))%i', '<?php echo \'\\1\'?>'."\n", $file_contents)) . "<hr>";

function microtime_float() 
{ 
    list($usec, $sec) = explode(' ', microtime()); 
    return (float)($usec + $sec); 
} 

$array = array();
for($i=0; $i<50000; $i++)
{
	$array[] = mt_rand(1,$i);
}
echo 'Array is ' . count($array) . " elements in length.<br><br>"; 

/** 
 * ***************************************** 
 */ 
echo "COUNT() in loop<br>"; 

$timestart = microtime_float(); 
for ($i=0; $i<count($array); $i++) { 
    $k = 0; 
} 
$timeend = microtime_float(); 
$timelength = $timeend - $timestart; 

echo $timelength; 
flush(); 
echo "<br><br><br>";

/** 
 * ***************************************** 
 */ 
echo "COUNT() outside loop<br>"; 
$array = array();
for($i=0; $i<3; $i++)
{
	$array[] = mt_rand(1,$i);
}
echo 'Array is ' . count($array) . " elements in length.<br><br>"; 

$timestart = microtime_float(); 
$count = count($array);
for ($i=0; $i<$count; $i++) { 
    $k = 0; 
} 
$timeend = microtime_float(); 
$timelength = $timeend - $timestart; 

echo $timelength; 
flush(); 
echo "<br><br><br>";
$testarray[4] = "stuff";
$testarray[74] = "stuff7347";
$testarray[474] = "stuff57547545";
echo nl2br(print_r($testarray, true)) . "<br>";
unset($testarray[74]);
echo nl2br(print_r($testarray, true)) . "<br>";

function print_current_date($params, &$tpl) {
	if(empty($params['format']))
		$format = "m/d/Y";
	return date($format, time());
}
$template_object->register_function("date_now", "print_current_date");

function compiler_show_tplheader1($arguments, &$tpl)
{
	return "\necho '" . $tpl->_file . " compiled at " . date('Y-m-d H:M').  "';";
}
$template_object->register_compiler("show_tplheader", "compiler_show_tplheader1");

function db_get_template ($tpl_name, &$tpl_source, &$smarty_obj)
{
	global $db;
    // do database call here to fetch your template,
    // populating $tpl_source
    $result = $db->execute("select tpl_source
                   from my_table
                  where tpl_name='$tpl_name'");
    $tpl_source = $result->fields['tpl_source'];
        return true;
}

function db_get_timestamp($tpl_name, &$tpl_timestamp, &$smarty_obj)
{
    // do database call here to populate $tpl_timestamp.
	global $db;
    $result = $db->execute("select tpl_timestamp
                   from my_table
                  where tpl_name='$tpl_name'");
         $tpl_timestamp = strtotime($result->fields['tpl_timestamp']);
        return true;
}

$template_object->register_resource("db", array("db_get_template",
                                       "db_get_timestamp",
                                       "db_get_secure",
                                       "db_get_trusted"));

// using resource from php script
$template_object->display("db:index.tpl");
?>
<?
// Example array
$total = 26;
for($i = 0; $i < $total; $i++)
{
	$items[] = $i;
}

// display the columns
$column_total = 4;
?>
<table cellpadding="3" cellspacing="5" border="0"> 
	<?
	$elements = ceil($total / $column_total);
	?>
	<tr> 
		<?
		for ($columns = 0; $columns < $column_total; $columns++)
		{ 
		?>
			<td valign="top"> 
				<?
				for($i=0; $i < $elements; $i++)
				{
					$column_position = $columns * $elements;
					if(isset($items[$column_position + $i]))
						echo "$elements Element: " . $items[$column_position + $i] . "<br>";
				}?>
			</td> 
		<?}?>
	</tr>
</table>


<?


function defense_vs_defense($player_id)
{
	global $db, $db_prefix;

	$result1 = $db->Execute("SELECT * from {$db_prefix}sector_defense where player_id = $player_id");
	db_op_result($result1,__LINE__,__FILE__);

	if ($result1 > 0)
	{
		while (!$result1->EOF)
		{
			$row = $result1->fields;
			$deftype = $row['defense_type'] == 'fighters' ? 'Fighters' : 'Mines';
			$qty = $row['quantity'];
			$result2 = $db->Execute("SELECT * from {$db_prefix}sector_defense where sector_id = $row[sector_id] and player_id <> $player_id ORDER BY quantity DESC");
			db_op_result($result2,__LINE__,__FILE__);
			if ($result2 > 0)
			{
				while (!$result2->EOF && $qty > 0)
				{
					$cur = $result2->fields;
					$targetdeftype = $cur[defense_type] == 'fighters' ? $l_fighters : $l_mines;
					if ($qty > $cur['quantity'])
					{
						$debug_query = $db->Execute("DELETE FROM {$db_prefix}sector_defense WHERE defense_id = $cur[defense_id]");
						$qty -= $cur['quantity'];
						db_op_result($debug_query,__LINE__,__FILE__);

						$debug_query = $db->Execute("UPDATE {$db_prefix}sector_defense SET quantity = $qty where defense_id = $row[defense_id]");
						db_op_result($debug_query,__LINE__,__FILE__);
						playerlog($cur[player_id], "LOG5_DEFS_DESTROYED", "$cur[quantity]|$targetdeftype|$row[sector_id]");
						playerlog($row[player_id], "LOG5_DEFS_DESTROYED", "$cur[quantity]|$deftype|$row[sector_id]");
					}else{
						$debug_query = $db->Execute("DELETE FROM {$db_prefix}sector_defense WHERE defense_id = $row[defense_id]");
						db_op_result($debug_query,__LINE__,__FILE__);

						$debug_query = $db->Execute("UPDATE {$db_prefix}sector_defense SET quantity=quantity - $qty WHERE defense_id = $cur[defense_id]");
						db_op_result($debug_query,__LINE__,__FILE__);

						playerlog($cur[player_id], "LOG5_DEFS_DESTROYED", "$qty|$targetdeftype|$row[sector_id]");
						playerlog($row[player_id], "LOG5_DEFS_DESTROYED", "$qty|$deftype|$row[sector_id]");
						$qty = 0;
					}
					$result2->MoveNext();
				}
			}
			$result1->MoveNext();
		}
		$debug_query = $db->Execute("DELETE FROM {$db_prefix}sector_defense WHERE quantity <= 0");
		db_op_result($debug_query,__LINE__,__FILE__);	  
	}
}

defense_vs_defense(139);
/*
require_once "backends/SwiftMailer/lib/Swift.php";
require_once "backends/SwiftMailer/lib/Swift/Connection/SMTP.php";

$smtp =& new Swift_Connection_SMTP("mail.aatraders.com", 25);
$smtp->setUsername("aatrade%aatraders.com");
$smtp->setPassword("diga");

$swift =& new Swift($smtp);

//Create the message
$message =& new Swift_Message("My subject", "My body");
 
//Now check if Swift actually sends it
$response = $swift->send($message, "panama@springfield.net", "aatrade@aatraders.com");
if ($response) echo "Sent $response";
else echo "Failed $response";

require_once "backends/SwiftMailer/lib/Swift.php";
require_once "backends/SwiftMailer/lib/Swift/Connection/SMTP.php";

$smtp =& new Swift_Connection_SMTP($SMTP_Server_Address, $SMPT_Server_Port);
$smtp->setUsername($SMTP_User_Name);
$smtp->setPassword($SMTP_User_Password);

$swift =& new Swift($smtp);

//Create the message
$message =& new Swift_Message($l_feedback_subj, $msg);

//Now check if Swift actually sends it
$response = $swift->send($message, "panama@springfield.net", $SMTP_Email_Address);
if ($response) echo "Sent $response";
else echo "Failed $response";
*/

			$player_details['player_id'] = 15;
			$calc_planet_defense = "(fighters * $fighter_price) + (torps * $torpedo_price) + if (base='Y', $base_credits, 0)";
			$calc_planet_credits = "credits + hidden_credits";

			$calc_planet_fighter = "exp(fighter * log(GREATEST($planet_upgrade_factor, 1)))";
			$calc_planet_sensors = "exp(sensors * log(GREATEST($planet_upgrade_factor, 1)))";
			$calc_planet_beams = "exp(beams * log(GREATEST($planet_upgrade_factor, 1)))";
			$calc_planet_torp_launchers = "exp(torp_launchers * log(GREATEST($planet_upgrade_factor, 1)))";
			$calc_planet_shields = "exp(shields * log(GREATEST($planet_upgrade_factor, 1)))";
			$calc_planet_jammer = "exp(jammer * log(GREATEST($planet_upgrade_factor, 1)))";
			$calc_planet_cloak = "exp(cloak * log(GREATEST($planet_upgrade_factor, 1)))";

			$calc_planet_sector_defense_weapons = "exp(sector_defense_weapons * log(GREATEST($planet_SD_upgrade_factor, 1)))";
			$calc_planet_sector_defense_sensors = "exp(sector_defense_sensors * log(GREATEST($planet_SD_upgrade_factor, 1)))";
			$calc_planet_sector_defense_cloak = "exp(sector_defense_cloak * log(GREATEST($planet_SD_upgrade_factor, 1)))";
			 //Add $calc_planet_armor if necessary
			$calc_planet_def_levels = "($calc_planet_fighter + $calc_planet_sensors + $calc_planet_beams + $calc_planet_torp_launchers + $calc_planet_shields + $calc_planet_jammer + $calc_planet_cloak + $calc_planet_sector_defense_weapons + $calc_planet_sector_defense_sensors + $calc_planet_sector_defense_cloak)*$upgrade_cost";
			$res_planet = $db->SelectLimit("SELECT planet_id, sector_id, name, $calc_planet_defense + $calc_planet_credits + $calc_planet_def_levels " . $calc_planets . " AS score FROM {$db_prefix}planets WHERE owner=$player_details[player_id] order by score desc", 1);
			db_op_result($res_planet,__LINE__,__FILE__);
			$planet_info = $res_planet->fields;
			echo $res_planet->RecordCount();
			$res_planet->close();
			print_r($planet_info);

echo"<hr>";

$distance = $universe_size;
$query2 = "SELECT sector_name, spiral_arm, sector_id as dest_sector, port_type, zone_id, x, y, z,SQRT(POW(($sectorinfo[x]-x),2)+POW(($sectorinfo[y]-y),2)+POW(($sectorinfo[z]-z),2)) as distance FROM {$db_prefix}universe where SQRT(POW(($sectorinfo[x]-x),2)+POW(($sectorinfo[y]-y),2)+POW(($sectorinfo[z]-z),2)) < $distance and sector_id!=$shipinfo[sector_id]  and sg_sector = 0  ORDER BY distance DESC";

$results = $db->SelectLimit($query2, 1);

echo $distance . " - " . $results->fields['distance'] . "<br>";

$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 and cargosellbuy != 1 order by default_create_percent DESC");
db_op_result($cargo_query,__LINE__,__FILE__);

$default_create_ratio = 100 / $cargo_query->fields['default_create_percent'];

while (!$cargo_query->EOF) 
{
	$cargoclass = $cargo_query->fields['class'];
	$default_create_percent = $cargo_query->fields['default_create_percent'];
	
	echo "<tr><td>Percentage " . ucwords($cargoclass) . ": $default_create_percent - " . mt_rand(0, 100) . " - price: " .  $cargo_query->fields['price'] . " - hold_space: " . $cargo_query->fields['hold_space'] . "</td></tr>\n";
	$cargo_query->Movenext();
}

echo "<tr><td><br><hr><br></td></tr>";
 
$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where defaultcargoplanet!=1 and cargoplanet=1 order by default_create_percent DESC");
db_op_result($cargo_query,__LINE__,__FILE__);

$default_create_ratio = 100 / $cargo_query->fields['default_create_percent'];
echo "<tr><td><br>$default_create_ratio<br></td></tr>";

while (!$cargo_query->EOF) 
{
	$cargoclass = $cargo_query->fields['class'];
	$default_create_percent = $cargo_query->fields['default_create_percent'];
	
	echo "<tr><td>Percentage " . ucwords($cargoclass) . ": $default_create_percent - (" . ($default_create_percent * $default_create_ratio)  . ") - " . mt_rand(0,100) . " - price: " .  $cargo_query->fields['price'] . " - hold_space: " . $cargo_query->fields['hold_space'] . "</td></tr>\n";
	$cargo_query->Movenext();
}



$result2 = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr("R01D4DT"), 1);
db_op_result($result2,__LINE__,__FILE__);
$target_sectorid = $result2->fields['sector_id'];

$res = $db->Execute("SELECT {$db_prefix}universe.sector_name, {$db_prefix}universe.sector_id, {$db_prefix}links.link_dest FROM {$db_prefix}links, {$db_prefix}universe WHERE {$db_prefix}links.link_start='$target_sectorid' and {$db_prefix}universe.sector_id ={$db_prefix}links.link_dest ORDER BY {$db_prefix}universe.sector_name ASC");
db_op_result($res,__LINE__,__FILE__);

$resultlist = "";
if ($res > 0)
{
	while (!$res->EOF)
	{
		$res_return = $db->Execute("SELECT source FROM {$db_prefix}sector_log WHERE player_id=$playerinfo[player_id] and (source='" . $res->fields['sector_id'] . "' or destination='" . $res->fields['sector_id'] . "')");
		db_op_result($res_return,__LINE__,__FILE__);
		$visitedcount = $res_return->RecordCount();
		$res_return->close();
		$visited = "";
		if($visitedcount == 0)
		{
			$visited = "`";
		}
		$resultlist .= $visited . $res->fields['sector_name'] . "|";
		$res->MoveNext();
	}
}
$res->close();



echo"<hr>";

$typetotal = 0;
$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where defaultcargoplanet=1 order by defaultcargoplanet DESC");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$cargo_info = $cargo_query->fields;
	$fedcargotype[$typetotal] = AAT_strtolower($cargo_info['classname']);
	$fedlimit[$typetotal] = $cargo_info['itemlimit'];
	$fed_start_price[$typetotal] = $cargo_info['fixed_start_price'];
	$fedgoodevil[$typetotal] = $cargo_info['goodevil'];
	$fedincreaserate[$cargototal] = $cargo_info['increaserate'];
	$typetotal++;
	$cargo_query->Movenext();
}
$cargo_query->close();

$port_query = $db->Execute("SELECT sector_id FROM {$db_prefix}universe WHERE port_type='none' and zone_id = 2");
db_op_result($port_sector,__LINE__,__FILE__);

while (!$port_query->EOF) 
{
	$port_info = $port_query->fields;
	$index = mt_rand(0, $typetotal-1);
	$query = "UPDATE {$db_prefix}universe SET port_type='" . $fedcargotype[$index] . "' WHERE sector_id='$port_info[sector_id]'";
//	echo $query . "<br>";
	$debug_query = $db->Execute($query);
	db_op_result($debug_query,__LINE__,__FILE__);

	$randompoint = mt_rand(500000, 1000000) / 1000000;
	$prices = floor($fed_start_price[$index] * $randompoint);
	if($fedincreaserate[$index] == 0)
	{
		$prices = $fed_start_price[$index];
	}
	$insertlist = "";

	for($ii = 0; $ii < 5; $ii++)
	{
		if($fedcargotype[$ii] != $fedcargotype[$index])
		{
			$randompoint = mt_rand(500000, 1000000) / 1000000;
			$startprices = floor($fed_start_price[$ii] * $randompoint) * 3;
			if($fedincreaserate[$ii] == 0)
			{
				$startprices = $fed_start_price[$ii] / 2;
			}
			$insertlist .= ", ($port_info[sector_id], '" . $fedcargotype[$ii] . "', $fedlimit[$ii], " . $startprices . ", '" . date("Y-m-d H:i:s") . "', $fedgoodevil[$ii])";
		}
	}

	$insert_query = "INSERT INTO {$db_prefix}universe_ports 
		(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
		VALUES 
		('$port_info[sector_id]', '" . $fedcargotype[$index] . "', '$fedlimit[$index]', '$prices', '" . date("Y-m-d H:i:s") . "', '$fedgoodevil[$index]') 
		$insertlist";
//	echo $insert_query . "<hr>";
	$debug_query = $db->Execute($insert_query);
	db_op_result($debug_query,__LINE__,__FILE__);
	$port_query->Movenext();
}


include ("footer.php");

?>
