<?php

get_post_ifset("sectorname, sectornametwo");

$sectorname = urldecode($sectorname);
$sectornametwo = urldecode($sectornametwo);

$returnvalue = "";

$res = $db->Execute("SELECT * FROM {$db_prefix}autoroutes WHERE player_id=$playerinfo[player_id] and start_sector=" . $db->qstr($sectorname) . " and destination=" . $db->qstr($sectornametwo));
db_op_result($res,__LINE__,__FILE__);
if($res->RecordCount())
{
	$autoroute = $res->fields;

	if($autoroute['warp_list'] == "")
	{
		$autoroute['autoroute_id'] = "0";
		$autoroute['warp_list'] = "";
	}

	$returnvalue .= $autoroute['autoroute_id'] . "^";
	$returnvalue .= $autoroute['warp_list'] . "^";
}
else
{
	$returnvalue .= "0^^";
}

$res = $db->Execute("SELECT * FROM {$db_prefix}autoroutes WHERE player_id=$playerinfo[player_id] and start_sector=" . $db->qstr($sectornametwo) . " and destination=" . $db->qstr($sectorname));
db_op_result($res,__LINE__,__FILE__);
if($res->RecordCount())
{
	$autoroute = $res->fields;

	if($autoroute['warp_list'] == "")
	{
		$autoroute['autoroute_id'] = "0";
	}

	$returnvalue .= $autoroute['autoroute_id'] . "^";
	$returnvalue .= $autoroute['warp_list'];
}
else
{
	$returnvalue .= "0^";
}

echo $returnvalue;

?> 
