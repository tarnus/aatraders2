<?php
include("support/variables0.inc");

function MaxCreditsPOW($one,$two)
{
	global $max_tech_level;
	$increment = 0;

	$oldvalue = 0;
	$breakpoint = floor($max_tech_level * 0.435);
	if($two > $breakpoint)
	{
echo "B1 ";
		$oldvalue = pow($one,$breakpoint);
		$multiplier = pow($one,$breakpoint) - pow($one,($breakpoint - 1));
		$numberlevels = $two - $breakpoint;
		$newvalue = $numberlevels * ($multiplier + pow($one, ($two - $breakpoint)));

		$breakpoint2 = floor($max_tech_level * 0.62);
		if($two > $breakpoint2)
		{
echo "B2";
			$numberlevels = $breakpoint2 - $breakpoint;
			$newvalue = $numberlevels * ($multiplier + pow($one, ($breakpoint2 - $breakpoint)));
			$numberlevels = $breakpoint2 - $breakpoint + 1;
			$newvalue2 = $numberlevels * ($multiplier + pow($one, ($breakpoint2 - $breakpoint)));
			$increment = $newvalue2 - $newvalue;
			$newvalue = ($increment * ($two - $breakpoint)) + (110000 * ($two - $breakpoint2));
			return $newvalue + $oldvalue;
		}
		else
		{
			return $newvalue + $oldvalue;
		}
	}
	else
	{
		return pow($one,$two);
	}
}

function mypw($one,$two)
{
	return pow($one,$two);
}

function mypw2($one,$two)
{
 	return exp($two * log(max($one, 1)));
}

function phpChangeDelta($desiredvalue,$currentvalue)
{
	global $upgrade_cost, $upgrade_factor;
//echo mypw($upgrade_factor, $desiredvalue) . " - " . mypw($upgrade_factor, $currentvalue) . " : ";
	return (mypw($upgrade_factor, $desiredvalue) - mypw($upgrade_factor, $currentvalue)) * $upgrade_cost;
}

function phpChangeDelta2($desiredvalue,$currentvalue)
{
	global $upgrade_cost, $upgrade_factor;
//echo mypw($upgrade_factor, $desiredvalue) . " - " . mypw($upgrade_factor, $currentvalue) . " : ";
	return (mypw2($upgrade_factor, $desiredvalue) - mypw2($upgrade_factor, $currentvalue)) * $upgrade_cost;
}

function phpChangePlanetDelta($desiredvalue,$currentvalue)
{
	global $upgrade_cost, $planet_upgrade_factor;

	return (mypw($planet_upgrade_factor, $desiredvalue) - mypw($planet_upgrade_factor, $currentvalue)) * $upgrade_cost;
}

function phpChangePlanetDelta2($desiredvalue,$currentvalue)
{
	global $upgrade_cost, $planet_upgrade_factor;

	return (mypw2($planet_upgrade_factor, $desiredvalue) - mypw2($planet_upgrade_factor, $currentvalue)) * $upgrade_cost;
}

function phpMaxCreditsDelta($desiredvalue,$currentvalue)
{
	global $upgrade_cost, $planet_upgrade_factor;

	return MaxCreditsPOW($planet_upgrade_factor, $desiredvalue) * $upgrade_cost;
}

function NUMBER($number, $decimals = 0)
{
	global $local_number_dec_point;
	global $local_number_thousands_sep;
	return number_format($number, $decimals, $local_number_dec_point, $local_number_thousands_sep);
}


for ($i =220; $i < 600; $i++)
{
echo $i . ". ";
//tech cost: " . NUMBER(floor(phpChangePlanetDelta($i, 0))) . " - upgrade cost: " . NUMBER(floor(phpChangePlanetDelta($i, $i-1)));

$maxcredits = (floor(phpMaxCreditsDelta($i, 0) * 7) * $planet_credit_multi) + $base_credits;

echo " - max credits: " . NUMBER($maxcredits);
echo " || "; 
//echo "tech cost: " . NUMBER(floor(phpChangePlanetDelta2($i, 0))) . " - upgrade cost: " . NUMBER(floor(phpChangePlanetDelta2($i, $i-1)));

$maxcredits = (floor(phpChangePlanetDelta2($i, 0) * 7) * $planet_credit_multi) + $base_credits;

echo " - max credits: " . NUMBER($maxcredits);
echo "<hr>";
}

echo "<hr>";

for ($i = 220; $i < 600; $i++)
{
echo $i . ". tech cost: " . NUMBER(floor(phpChangeDelta($i, 0))) . " - upgrade cost: " . NUMBER(floor(phpChangeDelta($i, $i-1)));
echo " || "; 
echo "tech cost: " . NUMBER(floor(phpChangeDelta2($i, 0))) . " - upgrade cost: " . NUMBER(floor(phpChangeDelta2($i, $i-1)));

echo "<hr>";
}

?>
