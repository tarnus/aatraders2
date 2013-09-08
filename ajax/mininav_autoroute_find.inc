<?php

get_post_ifset("endsector");

$endsector = urldecode($endsector);

$returnvalue = "";

function findlinkpath($startsector, $endsector)
{
	global $db, $db_prefix, $shipinfo, $max_tech_level, $search_results_echo, $warp_list, $found, $ADODB_FETCH_MODE, $search_depth;

	$max_search_depth = round($shipinfo['fighter'] / (5 * ($max_tech_level / 54)))+2;
	if($max_search_depth > 10)
	{
		$max_search_depth = 10;
	}

	$found = 0;
	for ($search_depth = 1; $search_depth <= $max_search_depth; $search_depth++)
	{
		$search_query = "SELECT a1.link_start , a1.link_dest \n";
		for ($i = 2; $i<=$search_depth; $i++)
		{
			$search_query = $search_query . " ,a". $i . ".link_dest \n";
		}

		$search_query = $search_query . "FROM {$db_prefix}links AS a1 \n";
		for ($i = 2; $i<=$search_depth; $i++)
		{
			$search_query = $search_query . " ,{$db_prefix}links AS a". $i . " \n";
		}

		$search_query = $search_query . "WHERE a1.link_start = $startsector \n";
		for ($i = 2; $i<=$search_depth; $i++)
		{
			$k = $i-1;
			$search_query = $search_query . " AND a" . $k . ".link_dest = a" . $i . ".link_start \n";
		}

		$search_query = $search_query . " AND a" . $search_depth . ".link_dest = $endsector \n";
		$search_query = $search_query . " AND a1.link_dest != a1.link_start \n";
		for ($i=2; $i<=$search_depth; $i++)
		{
			$search_query = $search_query . " AND a" . $i . ".link_dest not in (a1.link_dest, a1.link_start ";
			for ($j=2; $j<$i; $j++)
			{
				$search_query = $search_query . ",a".$j.".link_dest ";
			}
			$search_query = $search_query . ")\n";
		}

		$search_query = $search_query . "ORDER BY a1.link_start, a1.link_dest ";
		for ($i=2; $i<=$search_depth; $i++)
		{
			$search_query = $search_query . ", a" . $i . ".link_dest";
		}

		$search_query = $search_query . " \nLIMIT 1";

		// Okay, this is tricky. We need the db returns to be numeric, not associative, so that we 
		// can get a count from it. A good page on it is here: http://php.weblogs.com/adodb_tutorial .
		// We also dont need to set it BACK to the game default, because each page sets it again (by calling config).
		// If someone can think of a way to recode this to not need this line, I would deeply appreciate it!
		//echo "$search_query<br><br>";
		$ADODB_FETCH_MODE = ADODB_FETCH_NUM;
		$debug_query = $db->Execute ($search_query);
		db_op_result($debug_query,__LINE__,__FILE__);
		$found = $debug_query->RecordCount();
//		echo "$found<br><br>";
		if ($found > 0)
		{
			break;
		}
	}

	$search_results_echo = '';
	$warp_list = '';
	if ($found > 0)
	{
		$links = $debug_query->fields;
		$ADODB_FETCH_MODE = ADODB_FETCH_ASSOC;
		$result2 = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_id=$links[0]", 1);
		db_op_result($result2,__LINE__,__FILE__);
		for ($i=1; $i < $search_depth+1; $i++)
		{
			$result2 = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_id=$links[$i]", 1);
			db_op_result($result2,__LINE__,__FILE__);
			$sector_name = $result2->fields['sector_name'];
			if ($i==1)
			{
				$search_results_echo = $search_results_echo . $sector_name;
			}
			else
			{
				$search_results_echo = $search_results_echo . " >> " . $sector_name;
			}
			if($i <= ($search_depth -1)){
				$warp_list = $warp_list . $sector_name;
				if($i != ($search_depth - 1))
					$warp_list = $warp_list . "|";
			}
		}
	}
}

$result2 = $db->SelectLimit("SELECT sector_id, sg_sector, sector_name, galaxy_id FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr(trim($endsector)), 1);
db_op_result($result2,__LINE__,__FILE__);
if($result2->RecordCount() > 0)
{
	$sector_id = $result2->fields['sector_id'];
	$sector_name = $result2->fields['sector_name'];
	if($result2->fields['galaxy_id'] != $sectorinfo['galaxy_id'])
	{
		echo "-1";
		return;
	}
}
else
{
	echo "-1";
	return;
}

$search_results_echo = $search_results_echo . " >> " . $sector_name;

findlinkpath($shipinfo['sector_id'], $sector_id);

if($found == 0)
{
	echo "-1";
	return;
}

$returnvalue = $warp_list . "^" . $sector_name . "^" . $search_results_echo . "^" . $search_depth;

echo $returnvalue;
?> 
