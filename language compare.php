<?php
include ("config/config.php");

get_post_ifset("doit, directory");

$template_object->enable_gzip = 0;

$title = "Find missing lines in non-english language files.";
$templatename = "master_template/";

include ("header.php");

echo "<H1>$title</H1>\n";


?>
<table width="80%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width="100%">
<?php
if($doit == 1){
?>
<form action="language compare.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
Directory to scan: <input type="text" name="directory">
<input type="submit" name="scan">
</form>
<?php
	set_time_limit(600);

	$start_dir = $gameroot."languages/english"; 
	$filelist = get_dirlist($start_dir);

	$itemcount = 0;
	for ($c=0; $c<count($filelist); $c++) { 
		$languagefile =  str_replace($gameroot."languages/english/", "", $filelist[$c]); 

		echo "Opening english language file <b>$languagefile</b><br><br>";
		$englishlines = file ("languages/english/$languagefile");
		echo "Opening $directory language file <b>$languagefile</b><br><br>";
		$newlines = file ("languages/$directory/$languagefile");
		for($i = 0; $i < count($englishlines); $i++)
		{
			$englishvariable = explode("=", trim($englishlines[$i]));
			$englishvariable[0] = trim($englishvariable[0]);
			$match = 0;
			for($i1 = 0; $i1 < count($newlines); $i1++)
			{
				$newvariable = explode("=", trim($newlines[$i1]));
				$newvariable[0] = trim($newvariable[0]);
				if($englishvariable[0] == $newvariable[0])
				{
					$match = 1;
					break;
				}
			}
			if($match != 1){
				echo trim($englishlines[$i]) . "<br>";
			}
		}
		echo "<br>Closing both language files.<br><hr><br>";
	}
}
else
{
?>
<form action="language compare.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
Directory to scan: <input type="text" name="directory">
<input type="submit" name="scan">
</form>
<?php
}
?>
				</td>
			</tr>
		</table>
<?php

	include ("footer.php");
?>


