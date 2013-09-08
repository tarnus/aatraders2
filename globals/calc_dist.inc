<?php
if (!function_exists('calc_dist')) {
	// Calculate the distance between two sectors.
	// We even run the queries ourselves.
	function calc_dist($src,$dst) 
	{
		global $db, $db_prefix;

		global $z1, $x2;
		global $z2, $y1;
		global $x1, $y2;

		if ($dst == '' or $src == '')
		{
			return 0;
		}

		$results = $db->SelectLimit("SELECT x,y,z FROM {$db_prefix}universe WHERE sector_id=$src", 1);
		db_op_result($results,__LINE__,__FILE__);

		$x1 = $results->fields['x'];
		$y1 = $results->fields['y'];
		$z1 = $results->fields['z'];
		$results->close();

		$results = $db->SelectLimit("SELECT x,y,z FROM {$db_prefix}universe WHERE sector_id=$dst", 1);
		db_op_result($results,__LINE__,__FILE__);

		$x2 = $results->fields['x'];
		$y2 = $results->fields['y'];
		$z2 = $results->fields['z'];

		$results->close();

		$distance = abs(sqrt(($x2-$x1)*($x2-$x1) + ($y2-$y1)*($y2-$y1) + ($z2-$z1)*($z2-$z1)));

		return $distance;
	}
}
?>
