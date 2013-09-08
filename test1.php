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

include ("config/config.php");
$template_object->enable_gzip = 0;

$templatename = "master_template/";

include ("header.php");
$template_object->send_now = 1;
$cargo_query = $db->Execute("SELECT avg(score) as scores FROM {$db_prefix}players where player_id > 3 and npc = 0");
db_op_result($cargo_query,__LINE__,__FILE__);
echo $start_credits . " : " . ($start_credits + floor($cargo_query->fields['scores'] * $start_credits_modifier)) . "<br>";

// cargo port placement
$cargototal = 0;
$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 order by defaultcargoplanet DESC");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$cargo_info = $cargo_query->fields;
	$index = str_replace(" ", "_", $cargo_info['classname']);
	$cargoindex[$index] = $cargototal;
	$newcargotype[$cargototal] = AAT_strtolower($cargo_info['classname']);
	$newcargoclass[$cargototal] = AAT_strtolower($cargo_info['class']);
	$limit[$cargototal] = $cargo_info['itemlimit'];
	$initialamount[$cargototal] = $cargo_info['itemlimit'];
	$fixed_start_price[$cargototal] = $cargo_info['fixed_start_price'];
	$increaserate[$cargototal] = $cargo_info['increaserate'];
	$goodevil[$cargototal] = $cargo_info['goodevil'];
	$cargosellbuy[$cargototal] = $cargo_info['cargosellbuy'];
	$cargototal++;
	$cargo_query->Movenext();
}
$cargo_query->close();

$earth_sector = $db->SelectLimit("SELECT x, y, z ".
							 "FROM {$db_prefix}universe ".
							 "WHERE ".
							 "sector_id='1'", 1);
db_op_result($earth_sector,__LINE__,__FILE__);

$Xdistance = floor($earth_sector->fields['x']);
$Ydistance = floor($earth_sector->fields['y']);
$Zdistance = floor($earth_sector->fields['z']);

$query2 = "SELECT SQRT(POW(($Xdistance-x),2)+POW(($Ydistance-y),2)+POW(($Zdistance-z),2)) as distance FROM {$db_prefix}universe where sector_id!=1 and sg_sector = 0  ORDER BY distance DESC";

$results = $db->SelectLimit($query2, 1);

$max_distance = floor($results->fields['distance']);

$query2 = "SELECT *, SQRT(POW(($Xdistance-x),2)+POW(($Ydistance-y),2)+POW(($Zdistance-z),2)) as distance FROM {$db_prefix}universe where sector_id!=1 and sg_sector = 0 and port_type != 'casino' and port_type != 'none' and port_type != 'upgrades' and port_type != 'devices' and port_type != 'spacedock' ORDER BY distance DESC";

$port_sector = $db->Execute($query2);

while(!$port_sector->EOF)
{
	$ratio = $port_sector->fields['distance'] / $max_distance;
	$randomsector = $port_sector->fields['sector_id'];
	$commodity_query = $db->Execute("SELECT * FROM {$db_prefix}universe_ports WHERE sector_id=" . $randomsector . " order by data_id ASC");
	db_op_result($commodity_query,__LINE__,__FILE__);
	$first = 0;

	while(!$commodity_query->EOF)
	{
		$commodity_data = $commodity_query->fields;
		$index = str_replace(" ", "_", $commodity_data['commodity_type']);
		$i = $cargoindex[$index];
		echo $ratio . "<br>" . nl2br(print_r($commodity_data, true)) . $fixed_start_price[$i] . "<br>";

		if($commodity_data['fixed_price'] == 1){
			$fixed_price = (mt_rand(500, $fixed_start_price[$i] * 1000) / 1000) * 3;
			$prices = $fixed_price / 2;

			if($increaserate[$i] == 0)
			{
				$prices = $fixed_start_price[$i];
			}
			if($first == 1)
			{
				$startprices = (mt_rand(500, $fixed_start_price[$i] * 1000) / 1000) * 2;
				$startprices += $fixed_start_price[$i] * $ratio;
				$startpricesfixed = $startprices / 2;
				if($increaserate[$i] == 0)
				{
					$startprices = $prices;
					$startpricesfixed = $prices;
				}
				echo ", ($random_sector, '" . $newcargotype[$i] . "', $limit[$i], " . $startpricesfixed . ", " . $startprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$i])<br>";
			}
		}else{
			$prices = mt_rand(1, $fixed_start_price[$i]);

			if($increaserate[$i] == 0)
			{
				$prices = $fixed_start_price[$i];
			}
			if($first == 1)
			{
				$startprices = (mt_rand(500, $fixed_start_price[$i] * 1000) / 1000);
				$startprices += $fixed_start_price[$i] * $ratio;
				if($increaserate[$i] == 0)
				{
					$startprices = $prices;
				}
				echo ", ($random_sector, '" . $newcargotype[$i] . "', $limit[$i], " . $startprices . ", 0, '" . date("Y-m-d H:i:s") . "', $goodevil[$i])<br>";
			}
		}
		if($first == 0)
		{
			$prices += floor($prices * $ratio);
			if($increaserate[$i] == 0)
			{
				$prices = $fixed_start_price[$i];
			}
			$port_query = "INSERT INTO {$db_prefix}universe_ports 
				(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
				VALUES 
				('$random_sector', '" . $newcargotype[$i] . "', '$limit[$i]', '$prices', '" . date("Y-m-d H:i:s") . "', '$goodevil[$i]') 
				<br>";
			echo $port_query . "<br>";
			$first = 1;
		}
		echo"<br>";
		$commodity_query->Movenext();
	}
	if($first == 0)
	{
		echo "<font color=\"lime\">universeports empty<br><br>" . nl2br(print_r($port_sector->fields, true)) . "</font>";
	}
	echo "<hr>";
	$port_sector->Movenext();
}
$port_sector->close();


include ("footer.php");

?>
