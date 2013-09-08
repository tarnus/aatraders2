<?php
$directorylist = array();

$directorylist[1] = "artifacts";

$directorylist[2] = "commodities";

$directorylist[3] = "debris";

$directorylist[4] = "devices";

$directorylist[5] = "dignitaries";

$directorylist[6] = "probes";

$directorylist[7] = "spies";

$langlist = array();
$langid = array();

$langlist[1] = "english";
$langid[1] = "en";

$langlist[2] = "swedish";
$langid[2] = "sv";

$langlist[3] = "portuguese";
$langid[3] = "pt";

$langlist[4] = "norwegian";
$langid[4] = "no";

$langlist[5] = "indonesian";
$langid[5] = "id";

$langlist[6] = "finnish";
$langid[6] = "fi";

$langlist[7] = "dutch";
$langid[7] = "nl";

$langlist[8] = "danish";
$langid[8] = "da";

$langlist[9] = "catalan";
$langid[9] = "ca";

$langlist[10] = "albanian";
$langid[10] = "sq";

$langlist[11] = "spanish";
$langid[11] = "es";

$langlist[12] = "italian";
$langid[12] = "it";

$langlist[13] = "german";
$langid[13] = "de";

$langlist[14] = "french";
$langid[14] = "fr";

$langlist[15] = "estonian";
$langid[15] = "et";

include ("config/config.php");

get_post_ifset("doit, transstring");

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


if(empty($transstring))
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
<form action="language translate classes.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
<TEXTAREA name="transstring" ROWS="10" COLS="60"></textarea>
<input type="submit" name="translate">
</form>
<br>
<br>

<?php

//	echo "$transstring<hr>";
	set_time_limit(12000);

	for($langnumber = 1; $langnumber <= count($langid); $langnumber++)
	{
		echo "<br>\n<br>\n" . ($langlist[$langnumber]) . "<br>\n<br>\n";

		$is_modified = 0;
		$englishlines = explode("\n", $transstring);

		for($i = 0; $i < count($englishlines); $i++)
		{
			$englishvariable = array();
			$englishvariable = explode("=", trim($englishlines[$i]));
			$englishvariable[0] = trim($englishvariable[0]);
			$englishvariable[1] = str_replace($englishvariable[0] . " = ", "", trim($englishlines[$i]));
			$tabcount = substr_count($englishlines[$i] , "\t", 0, 8);

			$match = 0;
			if(substr(trim($englishlines[$i]), 0, 1) == "$")
			{
				$transstringhold = trim(rtrim($englishvariable[1], ";"), " \"");

				$pos = strpos($transstringhold, "\" . \$this->");
				$thisvarcount = substr_count($transstringhold , "\" . \$this->");

				$transstringarray = array();
				$thisarray = array();
				if($pos == false)
				{
					$transstringarray[] = $transstringhold;
					$string_elements = 1;
				}
				else
				{
					// process for multiple entries
					$transstringarray[] = substr($transstringhold, 0, $pos);
//					echo "Phase 1:" . $transstringarray[0] . "<br>";
					$string_elements = 1;
					$pos2 = strpos($transstringhold, " . \"");
					if(substr($transstringhold, $pos - 1, 1) == " ")
					{
						$addspace = " ";
					}
					else
					{
						$addspace = "";
					}

					if(substr($transstringhold, $pos2 + 4, 1) == " ")
					{
						$addspaceafter = " ";
					}
					else
					{
						$addspaceafter = "";
					}

					$thisarray[] = $addspace . substr($transstringhold, $pos, $pos2 - $pos + 4) . $addspaceafter;
//					echo "Phase 1:" . $thisarray[0] . "<br>";

					if($thisvarcount > 1)
					{
// add second here
						$pos = strpos($transstringhold, "\" . \$this->", $pos2 + 4);
						$transstringarray[] = substr($transstringhold, $pos2 + 4, $pos - ($pos2 + 4));
//						echo "Phase 2:" . $transstringarray[1] . "<br>";
						$string_elements = 2;
						$pos2 = strpos($transstringhold, " . \"", $pos2 + 4);
						if(substr($transstringhold, $pos - 1, 1) == " ")
						{
							$addspace = " ";
						}
						else
						{
							$addspace = "";
						}

						if(substr($transstringhold, $pos2 + 4, 1) == " ")
						{
							$addspaceafter = " ";
						}
						else
						{
							$addspaceafter = "";
						}

						$thisarray[] = $addspace . substr($transstringhold, $pos, $pos2 - $pos + 4) . $addspaceafter;
//						echo "Phase 2:" . $thisarray[1] . "<br>";
						$transstringarray[] = substr($transstringhold, $pos2 + 4);
						$string_elements = 3;
//						echo "Phase 3:" . $transstringarray[2] . "<br>";
					}
					else
					{
						$transstringarray[] = substr($transstringhold, $pos2 + 4);
						$string_elements = 2;
					}
				}

				for($element = 0; $element < $string_elements; $element++)
				{
					$transstringwork = $transstringarray[$element];
					$foundone = 0;
					$replacement = array();
					$tag = "";
					$count = 0;
					for($iz = 0; $iz < strlen($transstringwork); $iz++)
					{
						$character = substr($transstringwork, $iz, 1);
						if($character == "[" || $character == "]" || $foundone == 1)
						{
							$foundone = 1;
							$tag .= $character;
							if($character == "]")
							{
//								echo $tag . "<br>";
								$replacement[$count] = $tag;
								$tag = "";
								$foundone = 0;
								$count++;
							}
						}
					}
					$result = translateTexts(array($transstringwork, ""), 'en', $langid[$langnumber]);
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
//								echo $tag . "<br>";
								$pattern[$count] = $tag;
								$tag = "";
								$foundone = 0;
								$count++;
							}
						}
					}
					for($iz = 0; $iz < count($pattern); $iz++)
					{
//						echo $pattern[$iz] . " - " . $replacement[$iz] . "<br>";
						$result[0] = str_replace($pattern[$iz], $replacement[$iz], $result[0]);
					}
					$transstringarray[$element] = $result[0];
				}
				if($string_elements == 1)
				{
					$finalresult = $transstringarray[0];
				}
				else
				{
					$finalresult = "";
					for($element = 0; $element < $string_elements; $element++)
					{
						$finalresult .= $transstringarray[$element] . $thisarray[$element];
					}
				}
				echo str_repeat("\t" , $tabcount) . $englishvariable[0] . " = \"" . utf8_decode($finalresult) . "\";\n";
			}
		}
	}
}
else
{
?>
<form action="language translate classes.php" method="post" enctype="multipart/form-data">
<input type="hidden" name="doit" value="1">
<TEXTAREA name="transstring" ROWS="10" COLS="60"></textarea>
<input type="submit" name="translate">
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


