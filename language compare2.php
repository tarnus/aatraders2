<?php
include ("config/config.php");

get_post_ifset("doit, directory");

$template_object->enable_gzip = 0;

$title = "Find English lines in non-english language files.";
$templatename = "master_template/";

$sectorinfo['spiral_arm'] = 2;

include ("header.php");

echo "<H1>$title</H1>\n";


?>
<table width="80%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width="100%">
<?php
if($doit == 1){
?>
<form action="language compare2.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
Directory to scan: <input type="text" name="directory">
<input type="submit" name="scan">
</form>
<br>
Only translate the text between the double quotes " between here ".
<br><br>
Do not translate any text between brackets [].  IE: [ORE] is not translated.  These are control phrases and are used to insert data into a string.
<br>

<?php
	set_time_limit(600);

	$start_dir = $gameroot."languages/english"; 
	$filelist = get_dirlist($start_dir);

	$itemcount = 0;
	for ($c=0; $c<count($filelist); $c++) { 
		$languagefile =  str_replace($gameroot."languages/english/", "", $filelist[$c]); 

//		echo "Opening english language file <b>$languagefile</b><br><br>";
		$englishlines = file ("languages/english/$languagefile");
		echo "Opening $directory language file <b>$languagefile</b><br><br>";
		$newlines = file ("languages/$directory/$languagefile");
		for($i = 0; $i < count($englishlines); $i++)
		{
			$englishvariable = explode("=", trim($englishlines[$i]));
			$englishvariable[0] = trim($englishvariable[0]);
			//$englishvariable[1] = trim(trim($englishvariable[1]), "\"");
			$match = 0;
			if(substr($englishlines[$i], 0, 1) == "$")
			{
				for($i1 = 0; $i1 < count($newlines); $i1++)
				{
					$newvariable = explode("=", trim($newlines[$i1]));
					$newvariable[0] = trim($newvariable[0]);
					//$newvariable[1] = trim(trim($newvariable[1]), "\"");
					if($englishvariable[1] == $newvariable[1])
					{
						echo trim(htmlspecialchars($newlines[$i1])) . "<br>";
						break;
					}
				}
			}
		}
		echo "<br>Closing $directory language file <b>$languagefile</b><br><hr><br>";
	}
}
else
{
?>
<form action="language compare2.php" method="post" enctype="multipart/form-data">
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


