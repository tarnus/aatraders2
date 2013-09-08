<?php
    // Start universe table
	TextFlush( "Dropping: {$db_prefix}universe_galaxy ");
	$res = $db->Execute("DROP TABLE IF EXISTS `{$db_prefix}universe_galaxy`");
	db_op_result($res,__LINE__,__FILE__);

    TextFlush( "Creating table: {$db_prefix}universe_galaxy ");
	$res = $db->Execute("CREATE TABLE IF NOT EXISTS `{$db_prefix}universe_galaxy` (
	`galaxy_id` smallint(5) unsigned NOT NULL auto_increment,
	`galaxy_name` varchar(100) NOT NULL default '',
    `universe_size` double(32,0) NOT NULL default '0',
	PRIMARY KEY	(`galaxy_id`)
) TYPE={$database_type}{$dbencoding}");
    db_op2_result("{$db_prefix}universe_galaxy", $res,__LINE__,__FILE__);
    // End of universe table

?>