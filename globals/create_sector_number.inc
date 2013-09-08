<?php
if (!function_exists('create_sector_number'))
{
	function create_sector_number($prefix)
	{
		global $db, $db_prefix;

		$alphanumeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		$newname = $prefix . AAT_substr($alphanumeric, mt_rand(25, 34), 1) . AAT_substr($alphanumeric, mt_rand(0, 34), 1) . AAT_substr($alphanumeric, mt_rand(25, 34), 1) . AAT_substr($alphanumeric, mt_rand(0, 34), 1) . AAT_substr($alphanumeric, mt_rand(0, 34), 1);
		$sector_check = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_name='$newname'", 1);
		db_op_result($sector_check,__LINE__,__FILE__);

		if($sector_check->RecordCount() != 0)
		{
			create_sector_number($prefix);
		} 
		else 
		{
			return $newname;
		}
	}
}

?>
