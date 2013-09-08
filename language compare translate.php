<?php
$langlist = array();
$langid = array();

$langlist[1] = "albanian";
$langid[1] = "sq";

$langlist[2] = "catalan";
$langid[2] = "ca";

$langlist[3] = "danish";
$langid[3] = "da";

$langlist[4] = "dutch";
$langid[4] = "nl";

$langlist[5] = "estonian";
$langid[5] = "et";

$langlist[6] = "finnish";
$langid[6] = "fi";

$langlist[7] = "french";
$langid[7] = "fr";

$langlist[8] = "german";
$langid[8] = "de";

$langlist[9] = "indonesian";
$langid[9] = "id";

$langlist[10] = "italian";
$langid[10] = "it";

$langlist[11] = "norwegian";
$langid[11] = "no";

$langlist[12] = "portuguese";
$langid[12] = "pt";

$langlist[13] = "spanish";
$langid[13] = "es";

$langlist[14] = "swedish";
$langid[14] = "sv";

include ("config/config.php");

get_post_ifset("doit, langnumber, write");

$template_object->enable_gzip = 0;

function translateTexts($src_texts = array(), $src_lang, $dest_lang)
{
	//setting language pair  
	$lang_pair = $src_lang.'|'.$dest_lang;  
	$src_texts_query = "";  
	foreach ($src_texts as $src_text)
	{
	    $src_texts_query .= "&q=".urlencode($src_text);
	}
	$url = "http://ajax.googleapis.com/ajax/services/language/translate?v=1.0".$src_texts_query."&langpair=".urlencode($lang_pair);
	// sendRequest  
	// note how referer is set manually  
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_REFERER, "http://www.aatraders.com");
	$body = curl_exec($ch);
	curl_close($ch);
	// now, process the JSON string
	$json = json_decode($body, true);
	if ($json['responseStatus'] != 200)
	{
		return false;  
	}
	$results = $json['responseData'];    
	$return_array = array();    
	foreach ($results as $result)
	{    
		if ($result['responseStatus'] == 200)
		{      
			$return_array[] = $result['responseData']['translatedText'];    
		}
		else
		{      
			$return_array[] = false;    
		}  
	}    
	//return translated text  
	return $return_array;
}

$title = "Find English lines in non-english language files and translate through Google Translate.";
$templatename = "master_template/";

$sectorinfo['spiral_arm'] = 2;

include ("header.php");

echo "<H1>$title</H1>\n";


if(empty($langnumber))
{
	$doit = 0;
}
?>
<table width="80%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width="100%">
<?php
if($doit == 1)
{
?>
<form action="language compare translate.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
Language to Update: <select name="langnumber">
<?php
	for($i = 1; $i <= count($langlist); $i++)
	{
		echo "<option value=\"$i\">" . ucfirst($langlist[$i]) . "</option>\n";
	}
?>
<option value="">-------</option>
</select>
<br><br>
Test: <input type="radio" name="write" value="0" checked>
Write: <input type="radio" name="write" value="1">
<br><br>
<input type="submit" name="scan">
</form>
<br>
<br>

<?php

	$directory = $langlist[$langnumber];

	set_time_limit(1200);

	$start_dir = $gameroot."languages/english"; 
	$filelist = get_dirlist($start_dir);
	$looping = 0;
	$itemcount = 0;
	for ($c=0; $c<count($filelist); $c++)
	{
		$languagefile =  str_replace($gameroot."languages/english/", "", $filelist[$c]);
		if(substr($languagefile, 0, 5) == "lang_")
		{
			$englishlines = file ("languages/english/$languagefile");
			echo "Opening $directory language file <b>$languagefile</b><br><br>";
			$newlines = file ("languages/$directory/$languagefile");
			$updated_data = array();
			$updated_data = $newlines;
			$is_modified = 0;

			for($i = 0; $i < count($englishlines); $i++)
			{
				$englishvariable = explode("=", trim($englishlines[$i]));
				$englishvariable[0] = trim($englishvariable[0]);
				$match = 0;
				if(substr($englishlines[$i], 0, 1) == "$")
				{
					for($i1 = 0; $i1 < count($newlines); $i1++)
					{
						$newvariable = explode("=", trim($newlines[$i1]), 2);
						$newvariable[0] = trim($newvariable[0]);
	//					echo "-> " . ($englishvariable[1] == $newvariable[1]) . " -> " . ($englishvariable[1] === $newvariable[1]) . " E: " . $englishvariable[1] . " N: " . $newvariable[1] . "<br>";
						if($englishvariable[1] == $newvariable[1])
						{
							$transstring = trim(rtrim($englishvariable[1], ";"), " \"");
							$foundone = 0;
							$replacement = array();
							$tag = "";
							$count = 0;
							for($iz = 0; $iz < strlen($transstring); $iz++)
							{
								$character = substr($transstring, $iz, 1);
								if($character == "[" || $character == "]" || $foundone == 1)
								{
									$foundone = 1;
									$tag .= $character;
									if($character == "]")
									{
										echo $tag . "<br>";
										$replacement[$count] = $tag;
										$tag = "";
										$foundone = 0;
										$count++;
									}
								}
							}

							echo ($transstring) . "<br>";
							echo trim(($newlines[$i1])) . "<br>";
							$result = translateTexts(array($transstring, ""), 'en', $langid[$langnumber]);

							$foundone = 0;
							$pattern = array();
							$tag = "";
							$count = 0;
							for($iz = 0; $iz < AAT_strlen($result[0]); $iz++)
							{
								$character = AAT_substr($result[0], $iz, 1);
								if($character == "[" || $character == "]" || $foundone == 1)
								{
									$foundone = 1;
									$tag .= $character;
									if($character == "]")
									{
										echo $tag . "<br>";
										$pattern[$count] = $tag;
										$tag = "";
										$foundone = 0;
										$count++;
									}
								}
							}

							for($iz = 0; $iz < count($pattern); $iz++)
							{
								echo $pattern[$iz] . " - " . $replacement[$iz] . "<br>";
								$result[0] = str_replace($pattern[$iz], $replacement[$iz], $result[0]);
							}

							if(trim(trim($englishvariable[1]), "\";") == $result[0])
							{
								echo "The same text:  Saving of text line aborted.<br><br>";
							}
							else
							{
								echo $englishvariable[0] . " = \"" . utf8_decode($result[0]) . "\";<br><br>";
								$updated_data[$i1] = $englishvariable[0] . " = \"" . utf8_decode($result[0]) . "\";";
								$newlines[$i1] = "";
								$is_modified = 1;
								break;
							}
						}
					}
				}
			}
			echo "<br>Closing $directory language file <b>$languagefile</b><br><hr><br>";
			if($write == 1 && $is_modified == 1)
			{
				echo "<br>Writing Updated $directory language file <b>" . $languagefile . "</b><br><hr><br>";
				$filename = "languages/$directory/$languagefile";
				$file = fopen($filename,"w") or die ("Failed opening file: enable write permissions for '$languagefile'");
				for($iz = 0; $iz < count($updated_data); $iz++)
				{
					fwrite($file, trim($updated_data[$iz]) . "\r\n");
				}
				fclose($file);
				echo "<br>Closing Updated $directory language file <b>" . $languagefile . "</b><br><hr><br>";
			}
			if($write == 0 and $looping == 2)
			{
				break;
			}
			$looping++;
		}
	}
}
else
{
?>
<form action="language compare translate.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
Language to Update: <select name="langnumber">
<?php
	for($i = 1; $i <= count($langlist); $i++)
	{
		echo "<option value=\"$i\">" . ucfirst($langlist[$i]) . "</option>\n";
	}
?>
<option value="">-------</option>
</select>
<br><br>
Test: <input type="radio" name="write" value="0" checked>
Write: <input type="radio" name="write" value="1">
<br><br>
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


