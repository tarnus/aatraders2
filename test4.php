<?php
$default_lang = "english";
$_SESSION['langdir'] = $default_lang;
$langdir = $_SESSION['langdir'];
$game_number = 0;

include ("config/config.php");
include ("globals/combat_functions.inc");
$template_object->enable_gzip = 0;

echo "Full attack modifier: $full_attack_modifier<hr>";
for($targettech = 10; $targettech < 350; $targettech+=10)
{
	for($attacktech = 10; $attacktech < 600; $attacktech+=10)
	{
		$ecmresult = ecmcheck($targettech, $attacktech, -$full_attack_modifier);
		echo "ECM - Sensor: $attacktech, ECM: $targettech, Result 1: $ecmresult[0], Result 2: $ecmresult[1]<br>";
		echo "Scan - Sensor: $attacktech, ECM: $targettech, Result 1: " . SCAN_SUCCESS($attacktech, $targettech) . "<hr>";
	}
}

include ("footer.php");
?>