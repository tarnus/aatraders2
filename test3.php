<?php
$default_lang = "english";
$_SESSION['langdir'] = $default_lang;
$langdir = $_SESSION['langdir'];
$game_number = 0;

include ("config/config.php");
include ("globals/calc_dist.inc");
$template_object->enable_gzip = 0;

$turns = round(max(1, (calc_dist(866, 2329)/ mypw($level_factor, 600))));
echo "Turns to move at 600 engines: $turns<hr>";

$turns = round(max(1, (calc_dist(866, 2329)/ mypw($level_factor, 400))));
echo "Turns to move at 400 engines: $turns<hr>";

$turns = round(max(1, (calc_dist(866, 2329)/ mypw($level_factor, 250))));
echo "Turns to move at 250 engines: $turns<hr>";

$turns = round(max(1, (calc_dist(866, 2329)/ mypw($level_factor, 100))));
echo "Turns to move at 100 engines: $turns<hr>";

for($i = 1; $i < 5000; $i++)
{
	$turns = round(max(1, (calc_dist(1, $i)/ mypw($level_factor, 200))));
	echo "x1/x2: " . $x1 . "/" . $x2 . " - y1/y2: " . $y1 . "/" . $y2 . " - z1/z2: " . $z1 . "/" . $z2 . " - <br>";
	echo "Distance: " . calc_dist(1, $i) . " - Turns to move at 200 engines: $turns<hr>";
}

include ("footer.php");
?>