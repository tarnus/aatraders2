<?php
include ("config/config.php");
$template_object->enable_gzip = 0;

$templatename = "master_template/";

//include ("templates/".$templatename."/skin_config.inc");
include ("header.php");

// map_dirs(path,level)
// path, level to start (start at 0)
$gameroot = "/aatrade/aatrade/";

$filename = $gameroot . "build_md5list.lst";
$fileread = fopen($filename,"r") or die ("Failed opening file: enable write permissions for '$filename'");

$filename = $gameroot . "support/md5_list.inc";
$filewrite = fopen($filename,"w") or die ("Failed opening file: enable write permissions for '$filename'");

while(!@feof($fileread))
{
	$file = $gameroot . trim(@fgets($fileread));
	$md5 = md5_file($file);
	$rootfile = str_replace($gameroot, "", $file);
	if($rootfile != "support/md5_list.inc" && $rootfile != "")
	{
		echo"$rootfile=$md5 <br>\n";
		fwrite($filewrite, $rootfile . "=" . $md5 . "\n"); 
//		fwrite($file, $rootfile . "\n"); 
// 		echo"$path/$node - $md5 <br>\n";
	}
}

fclose($fileread);
fclose($filewrite);

	include ("footer.php");
?>


