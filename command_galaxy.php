<?php
// Galaxy
//
// The second line MUST be the name of the command that is to be shown in the command list.
//
// This program is free software; you can redistribute it and/or modify it   
// under the terms of the GNU General Public License as published by the	 
// Free Software Foundation; either version 2 of the License, or (at your	
// option) any later version.												
// 
// File: galaxy.php

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
$title = "View Galactic Distances $templatename";

$debug_query = $db->Execute ("SELECT sector_id, x, y, z FROM {$db_prefix}universe ORDER BY sector_id ASC");
db_op_result($debug_query,__LINE__,__FILE__);

echo "<H1>$title</H1>\n";

?>
<img src="templates/<?php echo $templatename;?>images/planetoo1.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo2.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo3.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo4.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo5.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo6.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo7.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo8.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo9.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo10.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo11.png" border="0" alt=""><BR><BR>
<img src="templates/<?php echo $templatename;?>images/planetoo-1.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-2.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-3.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-4.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-5.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-6.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-7.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-8.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-9.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-10.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planetoo-11.png" border="0" alt=""><BR><BR>
<img src="templates/<?php echo $templatename;?>images/planeto-o-1.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-2.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-3.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-4.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-5.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-6.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-7.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-8.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-9.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-10.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o-11.png" border="0" alt=""><BR><BR>
<img src="templates/<?php echo $templatename;?>images/planeto-o1.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o2.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o3.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o4.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o5.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o6.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o7.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o8.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o9.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o10.png" border="0" alt="">
<img src="templates/<?php echo $templatename;?>images/planeto-o11.png" border="0" alt=""><BR><BR>
<?php
while (!$debug_query->EOF)
{
	$row = $debug_query->fields;
	echo "$row[sector_id], $row[x], $row[y], $row[z]<BR>\n";
	$debug_query->MoveNext();
}

echo "Click <a href=main.php>here</a> to return to main menu.";

include ("footer.php");
?> 

