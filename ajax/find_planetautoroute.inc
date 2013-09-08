<?php

get_post_ifset("planetid, sectornametwo");

$planetid = urldecode($planetid);
$sectornametwo = urldecode($sectornametwo);

$returnvalue = "";

$res = $db->Execute("SELECT sector_id FROM {$db_prefix}planets WHERE planet_id=$planetid");
db_op_result($res,__LINE__,__FILE__);
$sectorid = $res->fields['sector_id'];

$res = $db->Execute("SELECT sector_name FROM {$db_prefix}universe WHERE sector_id=$sectorid");
db_op_result($res,__LINE__,__FILE__);
$sectorname = $res->fields['sector_name'];

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
	$returnvalue .= $autoroute['warp_list'];
}
else
{
	$returnvalue .= "0^";
}

$returnvalue = "$sectorid^$sectorname";

echo $returnvalue;

?> 
