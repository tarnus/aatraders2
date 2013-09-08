<?php
// 1
// 1900
// 1440
// 0
// Y
// How often the Federation will find new sectors that are added to the game..


// enable schedule - 0 disable schedule, 1 enable schedule
// execution order - the order of execution
// ticks full - how many minues between each execution
// loop_count - the number of times to execute schedule before deleting
// is_loop - "Y" loop enlessly, "N" - execute the number of times indocated by spawn value
// extra info - description of the schedule

include ("globals/insert_news.inc");
include ("globals/create_sector_coordinates.inc");
include ("globals/create_sector_number.inc");

function check_php_version () {
   $testSplit = explode ('.', '4.3.0');
   $currentSplit = explode ('.', phpversion());

   if ($testSplit[0] < $currentSplit[0])
       return True;
   if ($testSplit[0] == $currentSplit[0]) {
       if ($testSplit[1] < $currentSplit[1])
           return True;
       if ($testSplit[1] == $currentSplit[1]) {
           if ($testSplit[2] <= $currentSplit[2])
               return True;
       }
   }
   return False;
}

$cargototal = 0;
$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 order by defaultcargoplanet DESC, default_create_percent DESC");
db_op_result($cargo_query,__LINE__,__FILE__);

$default_create_ratio = 100 / $cargo_query->fields['default_create_percent'];
$default_create_ratio_new = 1;

while (!$cargo_query->EOF) 
{
	$cargo_info = $cargo_query->fields;
	$newcargotype[$cargototal] = $cargo_info['classname'];
	$limitamount[$cargototal] = $cargo_info['itemlimit'];
	$initialamount[$cargototal] = $cargo_info['itemlimit'] * $_POST['initscommod'] / 100.0;
	$fixed_start_price[$cargototal] = $cargo_info['fixed_start_price'];
	$increaserate[$cargototal] = $cargo_info['increaserate'];
	$goodevil[$cargototal] = $cargo_info['goodevil'];
	$cargosellbuy[$cargototal] = $cargo_info['cargosellbuy'];
	$default_create_percent[$cargototal] = $cargo_info['default_create_percent'] * $default_create_ratio;
	if($cargo_info['defaultcargoplanet'] == 0 && $default_create_ratio_new == 1)
	{
		$default_create_ratio_new = 200 / $cargo_info['default_create_percent'];
		echo $cargo_info['default_create_percent'] . "<br>";
	}
	$default_create_percent_new[$cargototal] = $cargo_info['default_create_percent'] * $default_create_ratio_new;
	$hold_space[$cargototal] = $cargo_info['hold_space'];
	$cargototal++;
	$cargo_query->Movenext();
}
$cargo_query->close();
echo "ratio: " . $default_create_ratio . " - " . $default_create_ratio_new . "<br>";
$defaultcargototal = 0;
$extracargototal = 0;

$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where defaultcargoplanet=1 or cargoplanet=1 order by defaultcargoplanet DESC");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$cargo_info = $cargo_query->fields;
	if($cargo_info['defaultcargoplanet'] == 1)
	{
		$dnewcargotype[$defaultcargototal] = $cargo_info['classname'];
		$dcargoclass[$defaultcargototal] = $cargo_info['cargoclass'];
		$ddefault_prod[$defaultcargototal] = $cargo_info['default_prod'];
		$ddefault_indy_prod[$defaultcargototal] = $cargo_info['default_indy_prod'];
		$dfixed_start_price[$defaultcargototal] = $cargo_info['fixed_start_price'];
		$dlimitamount[$defaultcargototal] = $cargo_info['itemlimit'];
		$dincreaserate[$defaultcargototal] = $cargo_info['increaserate'];
		$dis_prod[$defaultcargototal] = ($cargo_info['cargoclass'] == "commodity") ? 1 : 0;
		$dgoodevil[$defaultcargototal] = $cargo_info['goodevil'];
		$defaultcargototal++;
	}
	else
	{
		if($cargo_info['cargoplanet'] == 1)
		{
			$p_newcargotype[$extracargototal] = $cargo_info['classname'];
			$p_cargoclass[$extracargototal] = $cargo_info['cargoclass'];
			$p_default_prod[$extracargototal] = $cargo_info['default_prod'];
			$p_default_indy_prod[$defaultcargototal] = $cargo_info['default_indy_prod'];
			$p_is_prod[$extracargototal] = ($cargo_info['cargoclass'] == "commodity") ? 1 : 0;
			$p_goodevil[$extracargototal] = $cargo_info['goodevil'];
			$extracargototal++;
		}
	}
	$cargo_query->Movenext();
}
$cargo_query->close();

if($allow_expanding_universe == 1){
	TextFlush ( "<b>Expanding Universe</b><br><br>\n");

	$earth_sector = $db->SelectLimit("SELECT x, y, z ".
								 "FROM {$db_prefix}universe ".
								 "WHERE ".
								 "sector_id='1'", 1);
	db_op_result($earth_sector,__LINE__,__FILE__);

	$Xdistance = floor($earth_sector->fields['x']);
	$Ydistance = floor($earth_sector->fields['y']);
	$Zdistance = floor($earth_sector->fields['z']);

	$query2 = "SELECT sector_name, spiral_arm, sector_id as dest_sector, port_type, zone_id, x, y, z,SQRT(POW(($Xdistance-x),2)+POW(($Ydistance-y),2)+POW(($Zdistance-z),2)) as distance FROM {$db_prefix}universe where sector_id!=1 and sg_sector = 0  ORDER BY distance DESC";

	$results = $db->SelectLimit($query2, 1);

	$max_distance = max(floor($results->fields['distance']), 1);

	$debug_query = $db->SelectLimit("SELECT sector_id from {$db_prefix}universe order by sector_id DESC", 1);
	db_op_result($debug_query,__LINE__,__FILE__);

	$endsector = $debug_query->fields['sector_id'];

	$debug_query->close();
	$stamp = date("Y-m-d H:i:s");

	$collisions = 0;
	# calculate the scale to use such that 
	# the max distance between 2 points will be
	# approx $universe_size.
	$scale = $universe_size / (4.0*pi());

	# compute the angle between arms
	$angle = deg2rad(360/$spiral_galaxy_arms);
	$addedsectors = mt_rand(1, $universe_expansion_rate);
	$found_planets = array();
	$new_ports = array();
	$addedgalaxysectors = array();

	for($i=1; $i <= $galaxy; $i++)
	{
		$found_planets[$i] = 0;
		$new_ports[$i] = 0;
		$addedgalaxysectors[$i] = 0;
	}

	TextFlush ("Creating ". $addedsectors ." New Sectors <br><br>");
	for ($i=0; $i < $addedsectors; $i++) 
	{
		$sector = '';
		$collision = FALSE;
		while (TRUE) 
		{
			create_sector_coordinates();

			// Collision check
			$debug_query = $db->SelectLimit("SELECT sector_id from {$db_prefix}universe WHERE x=$sector[x] and y=$sector[y] and z=$sector[z] ", 1);
			db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query->close();

			if ($debug_query->RecordCOunt() != 0) 
			{
				$collisions++;
			}
			else 
			{
				break;
			}
		}
		$galaxynumber = mt_rand(1, $galaxy);
		$addedgalaxysectors[$galaxynumber]++;
		$port_type= mt_rand(0,100);
		if($max_sector_size > 5)
			$max_sector_size = 5;
		$star_size = mt_rand(0, $max_sector_size);

		if ($port_type > 30){
			$port="none";
			$res = $db->Execute("INSERT INTO {$db_prefix}universe (zone_id, star_size, x, y, z, spiral_arm, port_type, creation_date, galaxy_id) VALUES (1, " . $star_size . ", $sector[x], $sector[y], $sector[z], $sector[spiral_arm], '$port', '$stamp', $galaxynumber) ");
			db_op_result($res,__LINE__,__FILE__);
			$sector_id = $db->insert_id();
			$res->close();
		}elseif ($port_type >5){
			$random_port = mt_rand(5, $cargototal - 1);
			$port = $newcargotype[$random_port];

			if($cargosellbuy[$random_port] != 1)
			{
				$random_value = mt_rand(0, 100);
				echo $random_value . " - " . $default_create_percent_new[$random_port] . "<br>";
				if($random_value < $default_create_percent_new[$random_port])
				{
					TextFlush ("Creating New ". ucwords($newcargotype[$random_port]) ." Port <br>");
					$res = $db->Execute("INSERT INTO {$db_prefix}universe (zone_id, star_size, x, y, z, spiral_arm, port_type, creation_date, galaxy_id) VALUES (1, " . $star_size . ", $sector[x], $sector[y], $sector[z], $sector[spiral_arm], '$port', '$stamp', $galaxynumber) ");
					db_op_result($res,__LINE__,__FILE__);

	    			$new_distance = sqrt(pow($sector['x'],2.0)+pow($sector['y'],2.0)+pow($sector['z'],2.0));

					$ratio = $new_distance / $max_distance;
					$sector_id = $db->insert_id();
					$res->close();

					$randompoint = mt_rand(500000, 1000000) / 1000000;
					$prices = floor($fixed_start_price[$random_port] * $randompoint);
					if($increaserate[$random_port] == 0)
					{
						$prices = $fixed_start_price[$random_port];
					}

					$maxcommodities = $max_port_buy_commodities;
					$insertlist = "";
					for($ii = 0; $ii < $cargototal; $ii++)
					{
						if($maxcommodities > 0)
						{
							if($ii != $random_port && mt_rand(1, 100) < 50 && $cargosellbuy[$ii] != 2)
							{
								$randompoint = mt_rand(500000, 1000000) / 1000000;
								$buyprices = floor($fixed_start_price[$ii] * $randompoint) * 3;
								$buyprices += $fixed_start_price[$ii] * $ratio;
								if($increaserate[$ii] == 0)
								{
									$buyprices = $fixed_start_price[$ii] / 2;
								}
								$insertlist .= ", ($sector_id, '" . $newcargotype[$ii] . "', $limitamount[$ii], " . $buyprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$ii])";
								$maxcommodities--;
							}
						}
					}

					$debug_query = $db->Execute("INSERT INTO {$db_prefix}universe_ports 
						(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
						VALUES 
						($sector_id, '" . $newcargotype[$random_port] . "', $limitamount[$random_port], $prices, '" . date("Y-m-d H:i:s") . "', $goodevil[$random_port]) 
						$insertlist");
					db_op_result($debug_query,__LINE__,__FILE__);
					$debug_query->close();
					$new_ports[$galaxynumber]++;
				}
				else
				{
					$random_port = mt_rand(0, $defaultcargototal - 1);
					$port = $dnewcargotype[$random_port];

					TextFlush ("Creating New ". ucwords($dnewcargotype[$random_port]) ." Port <br>");
					$res = $db->Execute("INSERT INTO {$db_prefix}universe (zone_id, star_size, x, y, z, spiral_arm, port_type, creation_date, galaxy_id) VALUES (1, " . $star_size . ", $sector[x], $sector[y], $sector[z], $sector[spiral_arm], '$port', '$stamp', $galaxynumber) ");
					db_op_result($res,__LINE__,__FILE__);

	    			$new_distance = sqrt(pow($sector['x'],2.0)+pow($sector['y'],2.0)+pow($sector['z'],2.0));

					$ratio = $new_distance / $max_distance;
					$sector_id = $db->insert_id();
					$res->close();

					$randompoint = mt_rand(500000, 1000000) / 1000000;
					$prices = floor($fixed_start_price[$random_port] * $randompoint);
					if($dincreaserate[$random_port] == 0)
					{
						$prices = $dfixed_start_price[$random_port];
					}

					$maxcommodities = $max_port_buy_commodities;
					$insertlist = "";
					for($ii = 0; $ii < $cargototal; $ii++)
					{
						if($maxcommodities > 0)
						{
							if($port != $newcargotype[$ii] && mt_rand(1, 100) < 50 && $cargosellbuy[$ii] != 2)
							{
								$randompoint = mt_rand(500000, 1000000) / 1000000;
								$buyprices = floor($fixed_start_price[$ii] * $randompoint) * 3;
								$buyprices += $fixed_start_price[$ii] * $ratio;
								if($increaserate[$ii] == 0)
								{
									$buyprices = $fixed_start_price[$ii] / 2;
								}
								$insertlist .= ", ($sector_id, '" . $newcargotype[$ii] . "', $limitamount[$ii], " . $buyprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$ii])";
								$maxcommodities--;
							}
						}
					}

					$debug_query = $db->Execute("INSERT INTO {$db_prefix}universe_ports 
						(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
						VALUES 
						($sector_id, '" . $dnewcargotype[$random_port] . "', $dlimitamount[$random_port], $prices, '" . date("Y-m-d H:i:s") . "', $dgoodevil[$random_port]) 
						$insertlist");
					db_op_result($debug_query,__LINE__,__FILE__);
				}
			}
			else
			{
				$random_port = mt_rand(0, $defaultcargototal - 1);
				$port = $dnewcargotype[$random_port];

				TextFlush ("Creating New ". ucwords($dnewcargotype[$random_port]) ." Port <br>");
				$res = $db->Execute("INSERT INTO {$db_prefix}universe (zone_id, star_size, x, y, z, spiral_arm, port_type, creation_date, galaxy_id) VALUES (1, " . $star_size . ", $sector[x], $sector[y], $sector[z], $sector[spiral_arm], '$port', '$stamp', $galaxynumber) ");
				db_op_result($res,__LINE__,__FILE__);

    			$new_distance = sqrt(pow($sector['x'],2.0)+pow($sector['y'],2.0)+pow($sector['z'],2.0));

				$ratio = $new_distance / $max_distance;
				$sector_id = $db->insert_id();
				$res->close();

				$randompoint = mt_rand(500000, 1000000) / 1000000;
				$prices = floor($fixed_start_price[$random_port] * $randompoint);
				if($dincreaserate[$random_port] == 0)
				{
					$prices = $dfixed_start_price[$random_port];
				}

				$maxcommodities = $max_port_buy_commodities;
				$insertlist = "";
				for($ii = 0; $ii < $cargototal; $ii++)
				{
					if($maxcommodities > 0)
					{
						if($port != $newcargotype[$ii] && mt_rand(1, 100) < 50 && $cargosellbuy[$ii] != 2)
						{
							$randompoint = mt_rand(500000, 1000000) / 1000000;
							$buyprices = floor($fixed_start_price[$ii] * $randompoint) * 3;
							$buyprices += $fixed_start_price[$ii] * $ratio;
							if($increaserate[$ii] == 0)
							{
								$buyprices = $fixed_start_price[$ii] / 2;
							}
							$insertlist .= ", ($sector_id, '" . $newcargotype[$ii] . "', $limitamount[$ii], " . $buyprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$ii])";
							$maxcommodities--;
						}
					}
				}

				$debug_query = $db->Execute("INSERT INTO {$db_prefix}universe_ports 
					(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
					VALUES 
					($sector_id, '" . $dnewcargotype[$random_port] . "', $dlimitamount[$random_port], $prices, '" . date("Y-m-d H:i:s") . "', $dgoodevil[$random_port]) 
					$insertlist");
				db_op_result($debug_query,__LINE__,__FILE__);
			}
		}else{
			$random_port = mt_rand(1,3);
			if ($random_port==1){
				$port="upgrades";
			}elseif ($random_port==2){
				$port="devices";
			}else{
				$port="spacedock";
			}
			TextFlush ("Creating New ". ucwords($port) ." Port<br>");
			$res = $db->Execute("INSERT INTO {$db_prefix}universe (zone_id, star_size, x, y, z, spiral_arm, port_type, creation_date, galaxy_id) VALUES (1, " . $star_size . ", $sector[x], $sector[y], $sector[z], $sector[spiral_arm], '$port', '$stamp', $galaxynumber) ");
			db_op_result($res,__LINE__,__FILE__);
			$sector_id = $db->insert_id();
			$res->close();
			$new_ports[$galaxynumber]++;
		}
		$sectorname = create_sector_number((string)$galaxynumber + chr(80 + $sector['spiral_arm']) . (string)$star_size);
		$debug_query = $db->Execute("UPDATE {$db_prefix}universe SET sector_name = " . $db->qstr($sectorname) . " WHERE sector_id = $sector_id");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();

		for($star = 0; $star < $star_size; $star++)
		{
			if(mt_rand(0, 10000) < 1000)
			{
				$new_age = ($display_percentage_age / 2) + mt_rand(0, $display_percentage_age);
				$insertlist = "";
				$insertlistprod = "";
				for($ii = 0; $ii < $defaultcargototal; $ii++)
				{
					if($ddefault_prod[$ii] > 0)
					{
						$insertlist .= ", prod_" . AAT_strtolower($dnewcargotype[$ii]);
						$insertlistprod .= ", '$ddefault_prod[$ii]'";
					}
				}

				$specialcargo = mt_rand(0, $extracargototal - 1);
				if(mt_rand(0, 100) < 50 && $extracargototal != 0)
				{
					$special_cargo = $p_newcargotype[$specialcargo];
					$special_goodevil = $p_goodevil[$specialcargo];
				}
				else
				{
					$special_cargo = '';
					$special_goodevil = 0;
				}

				if(mt_rand(1, 100) <= $planet_production_skew)
				{
					$organics_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
				}
				else
				{
					$organics_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
				}

				if(mt_rand(1, 100) <= $planet_production_skew)
				{
					$ore_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
				}
				else
				{
					$ore_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
				}

				if(mt_rand(1, 100) <= $planet_production_skew)
				{
					$goods_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
				}
				else
				{
					$goods_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
				}

				if(mt_rand(1, 100) <= $planet_production_skew)
				{
					$energy_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
				}
				else
				{
					$energy_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
				}
				TextFlush ("<font color=\"green\">A planet has been found in sector</font> <font color=\"yellow\">$sectorname</font><br>");
				$creation_date = date("Y-m-d H:i:s");
				$debug_query = $db->Execute("INSERT INTO {$db_prefix}planets 
				(sector_id, max_credits, prod_fighters, prod_torp, special_name, special_goodevil, organics_planet, ore_planet, goods_planet, energy_planet, use_age, creation_date" . $insertlist . ") 
				VALUES 
				('$sector_id', '$base_credits', '$default_prod_fighters', '$default_prod_torp', '$special_cargo', '$special_goodevil', '$organics_planet', '$ore_planet', '$goods_planet', '$energy_planet', '$new_age', '$creation_date'" . $insertlistprod . ")");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
				$found_planets[$galaxynumber]++;
			}
		}

		unset($sector);
	}

	if ($collisions) 
	{
		TextFlush ("<font color=\"yellow\">$collisions sector collisions repaired</font> ");
	} 
	else 
	{
		TextFlush ("No sector collisions detected ");
	}

	$galaxylist_galaxy = array();
	$galaxylist_sector = array();
	$debug_query = $db->Execute("SELECT sector_id, galaxy_id from {$db_prefix}universe where sector_id > 5 and sg_sector=0");
	db_op_result($debug_query,__LINE__,__FILE__);
	while (!$debug_query->EOF) 
	{
		$galaxylist_galaxy = $debug_query->fields['galaxy_id'];
		$galaxylist_sec = $debug_query->fields['sector_id'];
		$galaxylist_sector[$galaxylist_galaxy][$galaxylist_sec] = $debug_query->fields['sector_id'];
		$debug_query->Movenext();
	}

	$debug_query1 = $db->Execute("SELECT sector_id, galaxy_id from {$db_prefix}universe where  sg_sector=0 and sector_id > " . $endsector );
	db_op_result($debug_query1,__LINE__,__FILE__);

	$linktotalcount = array();
	TextFlush ( "<br>Generating warp links <br>\n");
	while (!$debug_query1->EOF) 
	{
		$i = $debug_query1->fields['sector_id'];
		$galaxy_id = $debug_query1->fields['galaxy_id'];
		$numlinks = mt_rand(2, round($link_max/2));

		if(mt_rand(0, 100) > 95)
		{
			$numlinks = 0;
		}

		for ($j=0; $j < $numlinks; $j++)
		{
			$destination = array_rand($galaxylist_sector[$galaxy_id], 1);
 
			$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES ($i," . $galaxylist_sector[$galaxy_id][$destination] . ");");
			db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query->close();
			$linktotalcount[$i]++;
			$link_odds = mt_rand(0,100);
			if ($link_odds < 50)
			{
				if($linktotalcount[$i] <= 5){
					$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES (" . $galaxylist_sector[$galaxy_id][$destination] . ",$i);");
					db_op_result($debug_query,__LINE__,__FILE__);
					$debug_query->close();
					$linktotalcount[$destination]++;
				}
			}
		}
		$debug_query1->Movenext();
	}
	$debug_query->close();
	$debug_query = $db->Execute("DELETE FROM {$db_prefix}navmap");
	db_op_result($debug_query,__LINE__,__FILE__);
	TextFlush ( "<br><font color=\"lime\">- operation completed successfully.</font><br><br>");
}
 

//if($found_planets > 0)
//{
//	insert_news($found_planets, 1, "found_planets", 0);
//}
//if($new_ports > 0)
//{
//	insert_news($new_ports, 1, "new_ports", 0);
//}
//if($addedsectors > 0)
//{
//	insert_news($addedsectors, 1, "addedsectors", 0);
//}

$result2 = $db->Execute("SELECT galaxy_id, galaxy_name FROM {$db_prefix}universe_galaxy");
db_op_result($result2,__LINE__,__FILE__);
while (!$result2->EOF)
{
	$galaxy_id = $result2->fields['galaxy_id'];
	$galaxyname = $result2->fields['galaxy_name'];
	if($addedgalaxysectors[$galaxy_id] > 0)
	{
		$newlyfoundsectors = $galaxyname . "|" . $addedgalaxysectors[$galaxy_id] . "|" . $new_ports[$galaxy_id] . "|" . $found_planets[$galaxy_id];
		insert_news($newlyfoundsectors, 1, "newgalaxysectors", 0);
	}
	$result2->MoveNext();
}
$result2->close();

TextFlush ( "<br>\n");
$multiplier = 0; //no use to run this again

$new_ticks = 1440 + ((mt_rand(0, 288) - 144) * 5);
//$newticks=10;
TextFlush ("<br><br>Next Tick: $new_ticks<br><br>");
$debug_query = $db->Execute("UPDATE {$db_prefix}scheduler SET ticks_full=$new_ticks WHERE sched_file='sched_expanding.inc'");
db_op_result($debug_query,__LINE__,__FILE__);
TextFlush ( "<br>\n");
TextFlush ( "<br>\n");

?>
