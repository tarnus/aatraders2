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


function exportvariables($silent = 0){
	global $gameroot, $game_number;
	global $db, $db_prefix;
	$filename = $gameroot . "support/variables" . $game_number . ".inc";
	$file = fopen($filename,"w") or die ("Failed opening file: enable write permissions for '$filename'");
	if($silent == 0)
		echo "<b>Saving $filename</b><br><br>";
	
	$debug_query = $db->Execute("SELECT * FROM {$db_prefix}config_values");
	db_op_result($debug_query,__LINE__,__FILE__);

	fwrite($file,"<?\n"); 
	while (!$debug_query->EOF)
	{
		$row = $debug_query->fields;
		$db_config_name = $row['name'];
		$db_config_value = $row['value'];
//		echo "Writing data: " . $db_config_name . "=\"" . $db_config_value . "\";<br>"; 
		fwrite($file,"$" . $db_config_name . "=\"" . $db_config_value . "\";\n"); 
		$debug_query->MoveNext();
	}
	fwrite($file,"?>\n"); 
	fclose($file);
}

$time = $db->query_time_total;
$resultSDb = $db->Execute("SHOW TABLE STATUS FROM aatrade_main0 LIKE 'aatrade_bounty'");
$time = $db->query_time_total - $time;
echo sprintf("%01.4f", $time);
include ("footer.php");
?>
