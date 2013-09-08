<?php
// Step 110 - Create all One and Two Way warp links

TextFlush("<br><b>Generating two way Federation warp links for sector 1 to $_POST[fedsecs]</b><br>\n");
$silent = 1;

$onewaylist = array();
$twowaylist = array();
$federationwaylist = array();
$federationstartlist = array();
// Put in the sector 1, 2, 3 and 4 warp loop.
$federationwaylist[1] = "1|2";
$federationwaylist[2] = "1|3";
$federationwaylist[3] = "1|4";
$federationwaylist[4] = "1|5";
$federationwaylist[5] = "2|1";
$federationwaylist[6] = "2|3";
$federationwaylist[7] = "2|4";
$federationwaylist[8] = "2|5";
$federationwaylist[9] = "3|1";
$federationwaylist[10] = "3|2";
$federationwaylist[11] = "3|4";
$federationwaylist[12] = "3|5";
$federationwaylist[13] = "4|1";
$federationwaylist[14] = "4|2";
$federationwaylist[15] = "4|3";
$federationwaylist[16] = "4|5";
$federationwaylist[17] = "5|1";
$federationwaylist[18] = "5|2";
$federationwaylist[19] = "5|3";
$federationwaylist[20] = "5|4";

$federationstartlist[1] = 1;
$federationstartlist[2] = 1;
$federationstartlist[3] = 1;
$federationstartlist[4] = 1;
$federationstartlist[5] = 2;
$federationstartlist[6] = 2;
$federationstartlist[7] = 2;
$federationstartlist[8] = 2;
$federationstartlist[9] = 3;
$federationstartlist[10] = 3;
$federationstartlist[11] = 3;
$federationstartlist[12] = 3;
$federationstartlist[13] = 4;
$federationstartlist[14] = 4;
$federationstartlist[15] = 4;
$federationstartlist[16] = 4;
$federationstartlist[17] = 5;
$federationstartlist[18] = 5;
$federationstartlist[19] = 5;
$federationstartlist[20] = 5;

$totalfederationways = 21;
$galaxylist_linkcount = array();
for ($i=1; $i<=$_POST['fedsecs']; $i++)
{
	$numlinks = mt_rand(1,$_POST['linksper'] / 2);
	for ($j=0; $j < $numlinks; $j++)
	{
		$destination = mt_rand(1,$_POST['fedsecs']);

		if($i != $destination)
		{
			if($galaxylist_linkcount[$i] < ($_POST['linksper'] / 2))
			{
				$federationwaylist[$totalfederationways] = $i . "|" . $destination;
				$galaxylist_linkcount[$i]++;
				$totalfederationways++;
				if($galaxylist_linkcount[$destination] < $_POST['linksper'] / 2)
				{
					$federationwaylist[$totalfederationways] = $destination . "|" . $i;
					$galaxylist_linkcount[$destination]++;
					$totalfederationways++;
				}
			}
		}
	}
}

$newfederationways = array_unique($federationwaylist);
unset($federationwaylist);
unset($federationstartlist);

$valuelist = "";
$totalfederationways = 1;
$totalcount = count($newfederationways);
$start_end = ($totalcount < 999) ? $totalcount: 999;
TextFlush("<br>Exporting links 1 to $start_end to the database (" . $totalcount . " total).<br>\n");
foreach ($newfederationways as $v) { 
	if(!($totalfederationways % 1000)){
		if($totalfederationways + 999 > $totalcount)
			$end = $totalcount - $totalfederationways;
		else
			$end = 999;
		TextFlush("Exporting links $totaloneways to " . ($totalfederationways + $end) . " to the database (" . $totalcount . " total).<br>\n");
	}
	$links = explode("|", $v);

	if(!($totalfederationways % 100)){
		$valuelist .= "($links[0],$links[1]),";
		$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES " .  AAT_substr($valuelist, 0, -1) );
		db_op_result($debug_query,__LINE__,__FILE__);
		$valuelist = "";
	}
	else
	{
		$valuelist .= "($links[0],$links[1]),";
	}
	$totalfederationways++;
}
unset($newfederationways);

if($valuelist != "")
{
	$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES " .  AAT_substr($valuelist, 0, -1) );
	db_op_result($debug_query,__LINE__,__FILE__);
}

TextFlush("<br><b>Generating warp links for sector 1 to $_POST[sektors]</b><br>\n");
$silent = 1;
$result4 = $db->Execute("SELECT link_start FROM {$db_prefix}links order by link_id");
$total = $result4->RecordCount();

for($i = 1; $i <= $total; $i++)
{
	$federationstart[$i] = $result4->fields['link_start'];
	$result4->MoveNext();	
}
$result4->close();

$federationarraylist = array_count_values($federationstart);

$galaxyoverall_linkcount = array();

for($galaxynumber = 1; $galaxynumber <= $galaxy; $galaxynumber++)
{
	$galaxylist_galaxy = array();
	$galaxylist_sector = array();
	$galaxylist_linkcount = array();

	$debug_query = $db->Execute("SELECT sector_id from {$db_prefix}universe where galaxy_id = $galaxynumber");
	db_op_result($debug_query,__LINE__,__FILE__);
	while (!$debug_query->EOF) 
	{
		$galaxylist_sec = $debug_query->fields['sector_id'];
		$galaxylist_sector[$galaxylist_sec] = $debug_query->fields['sector_id'];
		$galaxylist_linkcount[$galaxylist_sec] = 0;
		$debug_query->Movenext();
	}
	$debug_query->MoveFirst();

	while (!$debug_query->EOF) 
	{
		$i = $debug_query->fields['sector_id'];
		$galaxy_id = $debug_query->fields['galaxy_id'];

		$max_links_left = $_POST['linksper'] - $federationarraylist[$federationstart[$i]];
		if($max_links_left > 0)
		{
			$numlinks = mt_rand(2, round($max_links_left/2));
		}
		else
		{
			$numlinks = 0;
		}

		if(mt_rand(1, 1000) == 1)
		{
			$numlinks = 0;
		}

		for ($j=0; $j <= $numlinks; $j++)
		{
			$destination = array_rand($galaxylist_sector);
			if($i != $destination)
			{
				if($galaxylist_linkcount[$i] < $_POST['linksper'])
				{
					$onewaylist[] = $i . "|" . $galaxylist_sector[$destination];
					$galaxylist_linkcount[$i]++;
					$galaxyoverall_linkcount[$i]++;
				}
			}
		}
		$debug_query->Movenext();
	}
	$debug_query->close();
}

$newoneways = array_unique($onewaylist);
unset($onewaylist);

$onewaylist = array();
foreach ($newoneways as $v)
{
	$onewaylist[] = $v;
	$links = explode("|", $v);

	$link_odds = mt_rand(0,100);
	if ($link_odds < $_POST['twoways'] && $galaxyoverall_linkcount[$links[1]] < mt_rand(($_POST['linksper'] / 2), ($_POST['linksper'] / 4) * 3))
	{
		$onewaylist[] = $links[1] . "|" . $links[0];
		$galaxyoverall_linkcount[$links[1]]++;
	}
}

$valuelist = "";
$totaloneways = 1;
$totalcount = count($onewaylist);
$start_end = ($totalcount < 999) ? $totalcount: 999;
TextFlush("<br>Exporting links 1 to $start_end to the database (" . $totalcount . " total).<br>\n");
foreach ($onewaylist as $v) { 
	if(!($totaloneways % 1000)){
		if($totaloneways + 999 > $totalcount)
			$end = $totalcount - $totaloneways;
		else
			$end = 999;
		TextFlush("Exporting links $totaloneways to " . ($totaloneways + $end) . " to the database (" . $totalcount . " total).<br>\n");
	}
	$links = explode("|", $v);

	if(!($totaloneways % 100)){
		$valuelist .= "($links[0],$links[1]),";
		$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES " .  AAT_substr($valuelist, 0, -1) );
		db_op_result($debug_query,__LINE__,__FILE__);
		$valuelist = "";
	}
	else
	{
		$valuelist .= "($links[0],$links[1]),";
	}
	$totaloneways++;
}

if($valuelist != "")
{
	$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES " .  AAT_substr($valuelist, 0, -1) );
	db_op_result($debug_query,__LINE__,__FILE__);
}

echo "<input type=hidden name=step value=110>";

?>