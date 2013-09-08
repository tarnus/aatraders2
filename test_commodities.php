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

$templatename = "master_template/";

$template_object->enable_gzip = 0;
$template_object->send_now = 1;
include ("header.php");

$multiplier = 1;

echo "<tr>";
echo "<td>commodity_type</td>";
echo "<td>commodity_amount</td>";
echo "<td>commodity_price</td>";
echo "<td>fixed_commodity_price</td>";
echo "</tr>";

$cargo_query = $db->Execute("SELECT * FROM `aatrade_universe_ports` WHERE `sector_id` =3 order by commodity_type ASC");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$row = $cargo_query->fields;
	echo "<tr>";
	echo "<td>" . $row['commodity_type'] . "</td>";
	echo "<td>" . $row['commodity_amount'] . "</td>";
	echo "<td>" . $row['commodity_price'] . "</td>";
	echo "<td>" . $row['fixed_commodity_price'] . "</td>";
	echo "</tr>";
	$cargo_query->Movenext();
}
$cargo_query->close();

$cargo_query = $db->Execute("SELECT classname, increaserate, price from {$db_prefix}class_modules_commodities where cargoport=1");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$cargotype = $cargo_query->fields['classname'];
	$increaserate = $cargo_query->fields['increaserate'];
	$price = $cargo_query->fields['price'];
	echo "<tr>";
	echo "<td>" . $cargotype . "</td>";
	echo "<td></td>";
	echo "<td>" . $increaserate . "</td>";
	echo "<td>" . $price . "</td>";
	echo "</tr>";

	$debug_query = $db->Execute("UPDATE {$db_prefix}universe_ports SET 
						commodity_price=commodity_price+((RAND()*$increaserate * $multiplier)*$price)
						WHERE commodity_type = '" . $cargotype);
	db_op_result($debug_query,__LINE__,__FILE__);
	$debug_query->close();

	$debug_query = $db->Execute("UPDATE {$db_prefix}universe_ports SET 
						commodity_price=LEAST(commodity_price+((RAND()*$increaserate * $multiplier)*$price), fixed_commodity_price)
						WHERE commodity_type = '" . $cargotype);
	db_op_result($debug_query,__LINE__,__FILE__);
	$debug_query->close();
	$cargo_query->Movenext();
}
$cargo_query->close();

$cargo_query = $db->Execute("SELECT classname, itemlimit, rate from {$db_prefix}class_modules_commodities where cargoport=1");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$cargotype = $cargo_query->fields['classname'];
	$limit = $cargo_query->fields['itemlimit'];
	$rate = $cargo_query->fields['rate'];

	$debug_query = $db->Execute("UPDATE {$db_prefix}universe_ports SET 
						commodity_amount=GREATEST(LEAST(commodity_amount + ($rate * $multiplier), $limit), 0)
						WHERE commodity_type = '" . $cargotype . "'");
	db_op_result($debug_query,__LINE__,__FILE__);
	$cargo_query->Movenext();
}
$cargo_query->close();

echo "<tr>";
echo "<td>&nbsp;</td>";
echo "<td>&nbsp;</td>";
echo "<td>&nbsp;</td>";
echo "<td>&nbsp;</td>";
echo "</tr>";

echo "<tr>";
echo "<td>commodity_type</td>";
echo "<td>commodity_amount</td>";
echo "<td>commodity_price</td>";
echo "<td>fixed_commodity_price</td>";
echo "</tr>";

$cargo_query = $db->Execute("SELECT * FROM `aatrade_universe_ports` WHERE `sector_id` =3 order by commodity_type ASC");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$row = $cargo_query->fields;
	echo "<tr>";
	echo "<td>" . $row['commodity_type'] . "</td>";
	echo "<td>" . $row['commodity_amount'] . "</td>";
	echo "<td>" . $row['commodity_price'] . "</td>";
	echo "<td>" . $row['fixed_commodity_price'] . "</td>";
	echo "</tr>";
	$cargo_query->Movenext();
}
$cargo_query->close();

include ("footer.php");

?>
