<?
$file = "http://xml.traveltoday.net/xmlhotel.jsp?xml=%3CHotelRequest%20method=%22runHotelInfoListRequest%22%3E%3CHotelInfoListRequest%3E%3Ccity%3ESpringfield%3C/city%3E%3CstateProvince%3EMO%3C/stateProvince%3E%3Ccountry%3EUS%3C/country%3E%3CdataSetRequested%3ECOMPLETE%3C/dataSetRequested%3E%3C/HotelInfoListRequest%3E%3C/HotelRequest%3E";
$xml_parser = xml_parser_create();

if (!($fp = fopen($file, "r"))) {
   die("could not open XML input");
}

$data = '';
while (!feof($fp)) {
  $data .= fread($fp, 8192);
}

fclose($fp);
$xml_parser = xml_parser_create();
xml_parse_into_struct($xml_parser, $data, $vals, $index);
xml_parser_free($xml_parser);

$params = array();
$level = array();
foreach ($vals as $xml_elem) {
  if ($xml_elem['type'] == 'open') {
   if (array_key_exists('attributes',$xml_elem)) {
     list($level[$xml_elem['level']],$extra) = array_values($xml_elem['attributes']);
   } else {
     $level[$xml_elem['level']] = $xml_elem['tag'];
   }
  }
  if ($xml_elem['type'] == 'complete') {
   $start_level = 1;
   $php_stmt = '$params';
   while($start_level < $xml_elem['level']) {
     $php_stmt .= '[$level['.$start_level.']]';
     $start_level++;
   }
   $php_stmt .= '[$xml_elem[\'tag\']] = $xml_elem[\'value\'];';
   eval($php_stmt);
  }
}

echo "<pre>";
echo "URL: http://xml.traveltoday.net/xmlhotel.jsp?xml=%3CHotelRequest%20method=%22runHotelInfoListRequest%22%3E%3CHotelInfoListRequest%3E%3Ccity%3ESpringfield%3C/city%3E%3CstateProvince%3EMO%3C/stateProvince%3E%3Ccountry%3EUS%3C/country%3E%3CdataSetRequested%3ECOMPLETE%3C/dataSetRequested%3E%3C/HotelInfoListRequest%3E%3C/HotelRequest%3E <br><hr><br>";
print_r ($params);
echo "</pre>";

$file = "http://xml.ihsadvantage.com/xmlhotel.jsp?xml=%3CHotelSessionRequest%20method=%22runHotelInfoRequest%22%3E%3CHotelInfoRequest%3E%3ChotelID%3E88664%3C/hotelID%3E%3CdataSetRequested%3ECOMPLETE%3C/dataSetRequested%3E%3C/HotelInfoRequest%3E%3C/HotelSessionRequest%3E";
$xml_parser = xml_parser_create();

if (!($fp = fopen($file, "r"))) {
   die("could not open XML input");
}

$data = '';
while (!feof($fp)) {
  $data .= fread($fp, 8192);
}

fclose($fp);
xml_parse_into_struct($xml_parser, $data, $vals, $index);
xml_parser_free($xml_parser);

$params = array();
$level = array();
foreach ($vals as $xml_elem) {
  if ($xml_elem['type'] == 'open') {
   if (array_key_exists('attributes',$xml_elem)) {
     list($level[$xml_elem['level']],$extra) = array_values($xml_elem['attributes']);
   } else {
     $level[$xml_elem['level']] = $xml_elem['tag'];
   }
  }
  if ($xml_elem['type'] == 'complete') {
   $start_level = 1;
   $php_stmt = '$params';
   while($start_level < $xml_elem['level']) {
     $php_stmt .= '[$level['.$start_level.']]';
     $start_level++;
   }
   $php_stmt .= '[$xml_elem[\'tag\']] = $xml_elem[\'value\'];';
   eval($php_stmt);
  }
}

echo "<pre>";
echo "URL: http://xml.ihsadvantage.com/xmlhotel.jsp?xml=%3CHotelSessionRequest%20method=%22runHotelInfoRequest%22%3E%3CHotelInfoRequest%3E%3ChotelID%3E88664%3C/hotelID%3E%3CdataSetRequested%3ECOMPLETE%3C/dataSetRequested%3E%3C/HotelInfoRequest%3E%3C/HotelSessionRequest%3E <br><hr><br>";
print_r ($params);
echo "</pre>";
?>