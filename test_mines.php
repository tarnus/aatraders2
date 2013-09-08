<?php
// This program is free software; you can redistribute it and/or modify it	
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: create_game.php

$default_lang = "english";
$_SESSION['zlangdir'] = $default_lang;
$langdir = $_SESSION['langdir'];
$game_number = 0;
include ("globals/combat_functions.inc");

include ("config/config.php");
$template_object->enable_gzip = 0;

$templatename = "master_template/";

include ("header.php");


get_post_ifset("planetcloak, planetsensor, planetfighter, sdfighters, shipsensors, shipecm, shipengines, shiparmor,shiptorps");
get_post_ifset("sdmines, shipbasehull, shiphull, shipmd");


$shipinfo['sensors'] = $shipsensors;
$shipinfo['ecm'] = $shipecm;
$shipinfo['engines'] = $shipengines;
$shipinfo['basehull'] = $shipbasehull;
$shipinfo['hull'] = $shiphull;
$playerinfo['player_id'] = 2;

$shipinfo['torp_class'] = 'Ship_Torpedo';
$shipinfo['armor_class'] = 'Ship_Armor';

$attacker_armor_left = NUM_PER_LEVEL($shiparmor);
$shipinfo['armor_pts'] = NUM_PER_LEVEL($shiparmor);
$defenses['mines'] = $sdmines;
$shipdevice['dev_minedeflector']['amount'] = $shipmd;
$shipinfo['torp_launchers'] = $shiptorps;

$destination = 22601;
$playerinfo['character_name'] = "Test Player";
$max_tech_level = 600;

$mine_debug = 1;

include ("sector_defense/mines_work.inc");
?>
<form action="test_mines.php" method="post" enctype="multipart/form-data">
Planet SD Mine Amount:<input type="text" name="sdmines" value="<?php echo $sdmines;?>"><br>
<hr>
Ship Sensor Tech Level:<input type="text" name="shipsensors" value="<?php echo $shipsensors;?>"><br>
Ship ECM Tech Level:<input type="text" name="shipecm" value="<?php echo $shipecm;?>"><br>
Ship Engines Tech Level:<input type="text" name="shipengines" value="<?php echo $shipengines; ?>"><br>
Ship Armor Tech Level:<input type="text" name="shiparmor" value="<?php echo $shiparmor;?>"><br>
Ship Torp Level:<input type="text" name="shiptorps" value="<?php echo $shiptorps;?>"><br>
Ship Base Hull Level:<input type="text" name="shipbasehull" value="<?php echo $shipbasehull;?>"><br>
Ship Hull Tech Level:<input type="text" name="shiphull" value="<?php echo $shiphull;?>"><br>
Ship Mine Deflectors:<input type="text" name="shipmd" value="<?php echo $shipmd;?>"><br>
<hr>
<input type="submit" name="Calculate">
</form>
<?

include ("footer.php");

?>
