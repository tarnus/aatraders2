<?php
// Bug Reports
//
// The second line MUST be the name of the command that is to be shown in the command list.
//
// This program is free software; you can redistribute it and/or modify it   
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: bugreport.php

include ("config/config.php");
$template_object->enable_gzip = 0;

if (checklogin())
{
	$template_object->enable_gzip = 0;
	include ("footer.php");
	die();
}

$templatename = "master_template/";

include ("header.php");

echo "<h1>Send Bug Report</h1><br><br>";
?>
<script language="Javascript" type="text/javascript">
<!--
	window.open('http://www.aatraders.com/bugtrack/index.php', '_bugreport', 'HEIGHT=400,resizable=yes,WIDTH=700,scrollbars=yes,toolbar=yes');
//-->
</script>
<?php
echo "A window has been opened to the Bug Report Page.<br><br>";
echo $l_global_mmenu;

include ("footer.php");
?> 

