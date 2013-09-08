<?php
class seeker {
	var $class = "seeker";
	var $type = 6;
	var $l_probe_type;
	var $l_probe_target;
	var $l_probe_description;

	// fill language variables
	function seeker()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Tööotsija Probe";
				$this->l_probe_target = "Sihi sektor";
				$this->l_probe_description = "Tööotsija Probe spetsiaalselt otsida läbi Gateway Sektorid viib sektorites loodud Sector Genesis seade. Sondid ei ole aruande kõikide laevade või planeete leitakse. Sond ainult aruande olemasolu Gateway Sector, kui ta leiab ühe. Ta ei otsi SG sektorites. Kui ta leiab ja aruanded Gateway sektor jätkab otsin veel Gateway Valdkonnad, realspace.";
			break;

			case "french":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Public Sector";
				$this->l_probe_description = "La sonde Seeker est spécialement conçu pour rechercher des secteurs passerelle menant à des secteurs créés avec un appareil Genesis Secteur. Les sondes ne fera pas état des navires ou des planètes qu&#39;il trouve. La sonde ne signalerait l&#39;existence d&#39;un secteur Gateway quand il la trouve. Il ne recherchera SG secteurs. Une fois qu&#39;il constate et signale un secteur Gateway il continuera d&#39;en chercher davantage de secteurs Gateway en REALSPACE.";
			break;

			case "german":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Zielsektor";
				$this->l_probe_description = "The Seeker Probe ist speziell für die Suche von Gateway-Branche, die zu Sektoren mit einem Sektor Genesis-Gerät erzeugt. Die Sonden werden nicht auf Schiffe oder Planeten Bericht die es findet. Die Sonde wird nur berichten, die Existenz eines Gateway-Sektor, wenn sie feststellt, ein. Es wird nicht Suche SG Sektoren. Sobald er feststellt, und berichtet von einem Gateway Sektor wird sie auch weiterhin auf der Suche nach mehr Gateway Sektoren in realspace.";
			break;

			case "italian":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Target Settore";
				$this->l_probe_description = "La sonda Seeker è specificamente progettato per cercare Settori Gateway leader di settori creato con un dispositivo Settore Genesis. Le sonde non presenterà una relazione su eventuali navi o pianeti che trova. La sonda solo segnalano l&#39;esistenza di un settore Gateway quando trova uno. Non cercherà mai SG settori. Una volta che trova e segnala un settore Gateway che continuerà alla ricerca di settori più Gateway nel mondo fisico.";
			break;

			case "spanish":
				$this->l_probe_type = "Buscador de Sonda";
				$this->l_probe_target = "Objetivo del sector";
				$this->l_probe_description = "La sonda Seeker está específicamente diseñado para buscar sectores de puerta de enlace que conduce a los sectores creados con un dispositivo de Génesis Sector. Las sondas no se informe sobre los buques o los planetas que encuentra. La sonda de sólo el informe de la existencia de un sector de puerta de enlace cuando encuentra uno. No buscará SG sectores. Una vez que encuentra y los informes de un Sector de puerta de enlace que continuará en busca de más sectores de puerta de enlace en el espacio real.";
			break;

			case "albanian":
				$this->l_probe_type = "Kërkon hetimin";
				$this->l_probe_target = "Sektori i synuar";
				$this->l_probe_description = "Kërkon hetimin është projektuar posaçërisht për të kërkuar nga Sektoret Gateway çon në sektorët e krijuar me një Device Zanafilla sektorit. Hetimet nuk do të raportojë mbi ndonjë anije ose planete ajo gjen. Hetimi do të raportojnë vetëm ekzistencën e një Sektori Gateway kur gjen një. Kjo nuk do të kërkojë SG sektorë. Sapo gjen dhe raportet e një Sektori Gateway ajo do të vazhdojë në kërkim për më shumë Sektoret Gateway në realspace.";
			break;

			case "catalan":
				$this->l_probe_type = "Cercador de Sonda";
				$this->l_probe_target = "Objectiu del sector";
				$this->l_probe_description = "La sonda Seeker està específicament dissenyat per buscar sectors de porta d&#39;enllaç que condueix els sectors creats amb un dispositiu de Gènesi Sector. Les sondes no es informe sobre els vaixells o els planetes que troba. La sonda de només l&#39;informe de l&#39;existència d&#39;un sector de porta d&#39;enllaç quan troba un. No buscarà SG sectors. Una vegada que troba i els informes d&#39;un Sector de porta d&#39;enllaç que continuarà a la recerca de més sectors de porta d&#39;enllaç en l&#39;espai real.";
			break;

			case "danish":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Target Sector";
				$this->l_probe_description = "The Seeker Probe er specielt designet til at søge ud Gateway Sektorer, der fører til sektorer, der er oprettet med en sektor Genesis Enhed. Den sonder vil ikke rapportere om nogen skibe eller planeter den finder. Sonden vil kun rapporterer eksistensen af en Gateway sektor, når den finder en. Det vil ikke søge SG sektorer. Når den finder og rapporter Gateway sektor, det vil fortsætte på udkig efter mere Gateway Sektorer realspace.";
			break;

			case "dutch":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Doelgroep";
				$this->l_probe_description = "The Seeker Probe is specifiek ontworpen om te zoeken uit Gateway Sectoren die leidt tot sectoren gemaakt met een sector Genesis apparaat. De sondes zal geen verslag over alle schepen of planeten het vindt. De sonde zal alleen het verslag van het bestaan van een Gateway Sector wanneer zij van oordeel is. Het zal niet zoek SG sectoren. Zodra zij constateert en rapporteert een Gateway sector zal blijven op zoek naar meer Gateway Sectoren in realspace.";
			break;

			case "finnish":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Kohdealaksi";
				$this->l_probe_description = "Seeker Probe on suunniteltu erityisesti etsiä käsiinsä Gateway alat johtaa aloille luotu sektorin Genesis laite. Koettimet ei raportoida alusten tai planeettoja se toteaa. Koetin vain raportin olemassaolon Gateway-ala, kun se toteaa, että yhdellä. Se ei etsi SG aloilla. Kun se havaitsee ja raportit Gateway-ala on edelleen etsimässä lisää Gateway Alat realspace.";
			break;

			case "indonesian":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Target Sektor";
				$this->l_probe_description = "The Seeker Probe dirancang khusus untuk mencari Sektor Gateway menuju sektor diciptakan dengan Kejadian Sektor Device. The probe tidak akan melaporkan pada setiap kapal atau planet yang ditemukan. Penyidikan hanya akan melaporkan adanya Sektor Gateway ketika menemukan satu. Tidak akan mencari sektor SG. Setelah menemukan dan melaporkan Sektor Gateway akan terus mencari di lebih Gateway Sektor realspace.";
			break;

			case "norwegian":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Target Sector";
				$this->l_probe_description = "The Seeker Probe er spesielt designet for å søke ut Gateway Sektorer som fører til sektorer opprettet med en Sector Genesis enhet. Sondene vil ikke rapportere eventuelle skip eller planeter den finner. Sonden vil bare rapportere at det finnes en Gateway sektor når den finner en. Det vil ikke søke SG sektorer. Når den finner og rapporterer en Gateway Sector den fortsetter på jakt etter mer Gateway sektorer i realspace.";
			break;

			case "portuguese":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Objectivo do sector";
				$this->l_probe_description = "A sonda Seeker é projetado especificamente para procurar Setores Gateway levando a setores criados com um dispositivo Genesis Setor. As sondas não apresentará um relatório sobre todos os navios ou planetas que encontra. A sonda vai apenas comunicar a existência de um Setor de Gateway quando ele encontra um. Ele não vai procurar SG setores. Uma vez que se encontra e relatórios de um Sector Gateway vai continuar procurando mais setores Gateway em Realspace.";
			break;

			case "swedish":
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Målsektor";
				$this->l_probe_description = "The Seeker Probe är särskilt utformat för att leta reda Gateway Sektorer som leder till sektorer som skapats med en sektor Genesis enhet. Sonderna kommer inte rapportera om några fartyg eller planeter den hittar. Sonden kommer bara rapportera förekomsten av en Gateway sektor när den hittar en. Det kommer inte att söka SG sektorer. När den hittar och rapporterar en omlastningsplats sektor kommer att fortsätta leta efter fler Gateway Sektorer realspace.";
			break;

			default:
				$this->l_probe_type = "Seeker Probe";
				$this->l_probe_target = "Target Sector";
				$this->l_probe_description = "The Seeker Probe is specifically designed to search out Gateway Sectors leading to sectors created with a Sector Genesis Device.  The probes will not report on any ships or planets it finds.  The probe will only report the existance of a Gateway Sector when it finds one.  It will not search SG sectors.  Once it finds and reports a Gateway Sector it will continue looking for more Gateway Sectors in realspace.";
			break;
		}
	}

	var $tag = "LOG5_PROBE_SEEKER";

	function log_switch_data()
	{
		$data = '<?php
  if($entry[\'type\'] == "' . $this->tag . '")
  {
	list($name,$sector,$organics,$goods,$ore,$torps,$col,$credit,$fighter,$energy) = AAT_split ("\|", $entry[\'data\']);
	$resx = $db->SelectLimit("SELECT sector_name from {$db_prefix}universe WHERE sector_id =" . $sector, 1);
	db_op_result($resx,__LINE__,__FILE__);
	$sector = $resx->fields[\'sector_name\'];
	$retvalue[\'text\'] = str_replace("[name]", "<font color=white><b>$name</b></font>", $l_log_text[$entry[\'type\']]);
	$retvalue[\'title\'] = $l_log_title[$entry[\'type\']];
  }
?>
';
//		return $data;
	return;
	}

	function log_language_data()
	{
/*
		$log_language_data["estonian"]["title"] = "";
		$log_language_data["estonian"]["text"] = "";
		$log_language_data["french"]["title"] = "";
		$log_language_data["french"]["text"] = "";
		$log_language_data["german"]["title"] = "";
		$log_language_data["german"]["text"] = "";
		$log_language_data["italian"]["title"] = "";
		$log_language_data["italian"]["text"] = "";
		$log_language_data["russian"]["title"] = "";
		$log_language_data["russian"]["text"] = "";
		$log_language_data["spanish"]["title"] = "";
		$log_language_data["spanish"]["text"] = "";
		$log_language_data["english"]["title"] = "";
		$log_language_data["english"]["text"] = "";
*/
		return $log_language_data;
	}

	function probe_display_code($data)
	{
		
	}

	// htmlreturnvar = defaultvalue; inputtype ; availableselections ; description
	//
	// radiobutton = 0;	radio ; 0=Profiles Not Required, 1=Profiles Required ;0 = profiles are not required to play on this server, 1 = Thie server requires allplayers to have a registered profile before they are allowed to create a player.
	// numberonly = 10;	number; 5-50 ; 0 = No player limit, Any number over 0 is the number of players online at the same time the game will support.  If anyone tries to login when the limit is reached they will be told to wait and log in later.
	// textinput = 240;	text  ; ; 0 = No player online timelimit, Any number over 0 is the number of minutes a player is allowed to be online per day.  Default is 4 hours.
	// listselection = 5;list  ; 1=1 Planet, 2=2 Planets, 3=3 Planets, 4=4 Planets, 5=5 Planets; This is the maximum number of sector sizes.  This size determines how many planets/cities each sector can support. Do not set this higher than 5 but it can be set from 1 to 5.
	// noinput = ; noinput  ; ; Information text

	function probe_orders_code()
	{
		$orders_array = array();
		return $orders_array;
	}

	function probe_finishorders_code()
	{
		global $db, $db_prefix, $l_global_mmenu, $templatename, $template_object;
		global $probeclass, $new_type, $probe_id, $l_probe_forbidFED, $title, $sectorinfo;

		if($sectorinfo['zone_id'] == 2)
		{
			include ("header.php");
			$template_object->assign("title", $title);
			$template_object->assign("error_msg", $l_probe_forbidFED);
			$template_object->assign("gotomain", $l_global_mmenu);
			$template_object->display("master_template/genericdie.tpl");
			include ("footer.php");
			die();
		}
		else
		{
			$debug_query = $db->Execute("UPDATE {$db_prefix}probe SET class='$probeclass[$new_type]', type=$new_type, data='' WHERE probe_id=$probe_id");
			db_op_result($debug_query,__LINE__,__FILE__);
			echo "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=probes.php\">";
			die();
		}
	}

	function probe_move_code($probeinfo, $shiptype, $destination)
	{
	}

	function probe_scheduler_code($probeinfo)
	{
		global $db, $db_prefix, $level_factor;

		$linkres = $db->Execute ("SELECT link_dest FROM {$db_prefix}links WHERE link_start='$probeinfo[sector_id]'");
		db_op_result($linkres,__LINE__,__FILE__);

		$targetlink = 0;
		$findem = $db->SelectLimit("SELECT galaxy_id FROM {$db_prefix}universe where sector_id = $probeinfo[sector_id]", 1);
		$galaxy_id = $findem->fields['galaxy_id'];

		if($linkres->RecordCount() == 0)
		{
			$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and zone_id != 2 and galaxy_id = $galaxy_id ORDER BY rand()", 1);
			$targetlink = $findem->fields['sector_id'];
		}

		while (!$linkres->EOF)
		{
			if(( mt_rand(1,1000) <= 250 && $targetlink == 0) || $linkres->fields['link_dest'] == $probeinfo['target_sector'])
			{
				$targetlink = $linkres->fields['link_dest'];
			}
			$linkres->MoveNext();
		}

		if($targetlink > 0)
		{
			$sectres = $db->Execute ("SELECT zone_id, sg_sector FROM {$db_prefix}universe WHERE sector_id='$targetlink'");
			if ($sectres->fields['zone_id'] == 2 || $sectres->fields['sg_sector'] != 0)
			{
				$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and zone_id != 2 and galaxy_id = $galaxy_id ORDER BY rand()", 1);
				$targetlink = $findem->fields['sector_id'];
			}
		}

		if($targetlink > 0)
		{
			$resultcc = $db->SelectLimit("SELECT turns FROM {$db_prefix}players WHERE player_id=$probeinfo[owner_id]", 1);
			db_op_result($resultcc,__LINE__,__FILE__);
			if ($resultcc > 0)
			{
				if ($resultcc->fields['turns'] >= 1)
				{
					TextFlush ("Safe Move to sector $targetlink <br>");
					$query="UPDATE {$db_prefix}players SET  turns_used=turns_used+1, turns=turns-1 WHERE player_id=$probeinfo[owner_id]";
					$move_result = $db->Execute ("$query");
					$db->Execute("UPDATE {$db_prefix}probe SET sector_id = $targetlink WHERE probe_id = $probeinfo[probe_id]");

					$this->scan_for_SG($targetlink, $probeinfo['owner_id'], $probeinfo['probe_id']);
					log_move($probeinfo['owner_id'], $probeinfo['probe_id'], $probeinfo['sector_id'], $targetlink, 1, $probeinfo['cloak'], $sectres->fields['zone_id']);
				}else{
					TextFlush ("Failed Move not enough turns - 1 turn needed <br>");
					PROBE_playerlog($probeinfo['owner_id'], "LOG9_PROBE_NOTURNS", "$probeinfo[probe_id]|$targetlink"); 
				}
			}
		}
	}

	function scan_for_SG($targetlink, $owner_id, $probe_id)
	{
		global $db, $db_prefix;
		$res = $db->Execute("SELECT {$db_prefix}universe.sector_name FROM {$db_prefix}links, {$db_prefix}universe WHERE {$db_prefix}links.link_start='$targetlink' and {$db_prefix}universe.sector_id ={$db_prefix}links.link_dest and {$db_prefix}universe.sg_sector!=0");
		db_op_result($res,__LINE__,__FILE__);
		if($res->RecordCount() > 0)
		{
			TextFlush ("<font color=\"lime\"><b>Found a Gateway!</b></font><br>");
			PROBE_playerlog($owner_id, "LOG9_PROBE_DETECTED_GATEWAY", "$probe_id|$targetlink");
		}
	}
}

?>