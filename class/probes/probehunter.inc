<?php
class probehunter {
	var $class = "probehunter";
	var $type = 999999;
	var $l_probe_type;
	var $l_probe_description;
	var $l_stationary;
	var $l_roaming;

	// fill language variables
	function probehunter()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Probe Hunter Probe";
				$this->l_probe_description = "Probe Hunter eesmärk on leida ja hävitada kõik vaenlased sondid. See kasutada ainult Warp Viited liikuda ja saab reisida SG sektorid. Kui ta leiab sond see hävitada ning jätkata otsin veel sondid hävitada. Scan Tech kasutada püüda leida Kaetud vaenlane sondid.";
				$this->l_stationary = "Statsionaarne Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "french":
				$this->l_probe_type = "Hunter Probe Probe";
				$this->l_probe_description = "The Hunter Probe est conçu pour rechercher et détruire toutes les sondes ennemi. Il utilisera uniquement Warp Liens de circuler et il peut Voyage dans les secteurs SG. Quand il trouve une sonde il le détruire et de poursuivre la recherche de sondes de plus à détruire. Le Scan est utilisé pour essayer de trouver des sondes ennemi masqué.";
				$this->l_stationary = "Stationary Garde Probe";
				$this->l_roaming = "Itinérance Attack Probe";
			break;

			case "german":
				$this->l_probe_type = "Hunter Probe Probe";
				$this->l_probe_description = "Die Probe Hunter wurde entwickelt, um zu suchen und alle feindlichen Sonden zu vernichten. Es wird dann nur Warp Links zu bewegen und es kann in SG Branchen zu reisen. Wenn er feststellt, wird eine Sonde zu zerstören und weiter auf der Suche nach mehr Sonden zu vernichten. Die Scan-Technik wird verwendet, um zu versuchen, gehüllt Feind Sonden finden.";
				$this->l_stationary = "Stationäre Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "italian":
				$this->l_probe_type = "Sonda Hunter Probe";
				$this->l_probe_description = "Il Cacciatore Probe è stato progettato per individuare e distruggere tutte le sonde nemico. Essa si limita ad utilizzare Warp Link a muoversi e si può viaggiare in Settori SG. Quando si trova una sonda che distrugge e proseguire la ricerca di sonde di più per distruggere. Tech Scan viene utilizzato per cercare di trovare le sonde nemico mascherato.";
				$this->l_stationary = "Stazionarie Guardia Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "spanish":
				$this->l_probe_type = "Sonda Sonda de Hunter";
				$this->l_probe_description = "El Cazador de la sonda está diseñada para buscar y destruir todas las sondas enemigo. Así, sólo se Warp Enlaces a circular y se puede viajar en los sectores SG. Cuando encuentra una sonda que va a destruir y seguir buscando más sondeos a destruir. La tecnología de escaneo se utiliza para tratar de encontrar las sondas enemigo encubierto.";
				$this->l_stationary = "Estacionario de la Guardia Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "albanian":
				$this->l_probe_type = "Hetim gjahtari hetimin";
				$this->l_probe_description = "Gjahtari hetim është projektuar për të kërkuar jashtë dhe shkatërrojë të gjitha hetimet e armikut. Ajo do të përdorin vetëm Warp Lidhje të lëvizin dhe kjo mund të udhëtojnë në sektorët SG. Kur të gjen një hetim do të shkatërrojë dhe të vazhdojë hetimet në kërkim për më shumë për të shkatërruar. Teknike Skano është përdorur për t&#39;u përpjekur dhe për të gjetur hetimet cloaked armik.";
				$this->l_stationary = "Stacionare Gardës hetimin";
				$this->l_roaming = "Roaming Sulmi hetimin";
			break;

			case "catalan":
				$this->l_probe_type = "Sonda Sonda de Hunter";
				$this->l_probe_description = "El Caçador de la sonda està dissenyada per buscar i destruir totes les sondes enemic. Així, només es Warp Enllaços a circular i es pot viatjar en els sectors SG. Quan troba una sonda que va a destruir i seguir buscant més sondejos a destruir. La tecnologia d&#39;escaneig s&#39;utilitza per tractar de trobar les sondes enemic encobert.";
				$this->l_stationary = "Estacionari de la Guàrdia Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "danish":
				$this->l_probe_type = "Probe Hunter Probe";
				$this->l_probe_description = "Sonden Hunter er designet til at opsøge og destruere alle fjendens sonder. Det vil kun bruge Warp Links til at flytte, og det kan rejse i SG sektorer. Når den finder en sonde det vil ødelægge det og fortsætte på udkig efter mere sonder til at ødelægge. Scan Tech bruges til at forsøge at finde sløret fjende sonder.";
				$this->l_stationary = "Stationære Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "dutch":
				$this->l_probe_type = "Hunter Probe Probe";
				$this->l_probe_description = "De Probe Hunter is ontworpen om te zoeken en alle vijandelijke sondes vernietigen. Het zal alleen gebruik Warp links te bewegen en kan het reizen in SG Sectoren. Wanneer zij constateert een sonde zal vernietigen en blijven op zoek naar meer sondes te vernietigen. De Scan-Tech is gebruikt om te proberen en gehuld vijand sondes te vinden.";
				$this->l_stationary = "Stationaire Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "finnish":
				$this->l_probe_type = "Probe Hunter Probe";
				$this->l_probe_description = "Probe Hunter tarkoituksena on etsiä ja tuhota kaikki vihollisen probes. Se käyttää vain Warp Linkit liikkua ja se voi matkustaa SG alat. Kun se havaitsee anturilla tuhoaa sen ja jatkaa etsivät lisää koetin tuhota. Scan Tech käytetään yrittää löytää Cloaked vihollisen probes.";
				$this->l_stationary = "Paikallaan Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "indonesian":
				$this->l_probe_type = "Hunter Probe Probe";
				$this->l_probe_description = "Probe Hunter yang dirancang untuk mencari dan menghancurkan semua musuh probe. Hanya akan menggunakan Warp Link untuk bergerak dan dapat melakukan perjalanan di Sektor SG. Ketika ia menemukan sebuah probe ia akan menghancurkan itu dan terus mencari lebih probe untuk menghancurkan. Scan Tech digunakan untuk mencoba dan menemukan musuh berjubah probe.";
				$this->l_stationary = "Stationary Probe Guard";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "norwegian":
				$this->l_probe_type = "Probe Hunter Probe";
				$this->l_probe_description = "The Probe Hunter er utformet for å oppsøke og ødelegge alle fiendtlige sonder. Det vil bare bruke Warp Links å flytte, og det kan reise i SG Sectors. Når den finner en sonde det vil ødelegge den og fortsetter på utkikk etter flere sonder for å ødelegge. Den Scan Tech brukes til å prøve og finne innhyllet fiende sonder.";
				$this->l_stationary = "Stasjonære Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "portuguese":
				$this->l_probe_type = "Hunter Probe Probe";
				$this->l_probe_description = "O Caçador Probe é projetado para procurar e destruir todas as sondas inimigas. Só vai usar Warp Links para movimentar e pode viajar em SG Setores. Quando encontra uma sonda que irá destruí-lo e continuar procurando mais sondas para destruir. A Tech Scan é utilizado para tentar encontrar sondas inimiga camuflada.";
				$this->l_stationary = "Guarda de estacionária Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			case "swedish":
				$this->l_probe_type = "Probe Hunter Probe";
				$this->l_probe_description = "Sonden Hunter är utformad för att söka upp och förstöra all fiendens sonder. Det kommer bara att använda Warp Länkar att flytta och man kan resa i SG Sectors. När den hittar en sond det kommer att förstöra den och fortsätta leta efter fler sonder för att förstöra. Den Scan Tech används för att försöka hitta cloaked fiende sonder.";
				$this->l_stationary = "Stationära Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;

			default:
				$this->l_probe_type = "Probe Hunter Probe";
				$this->l_probe_description = "The Probe Hunter is designed to seek out and destroy all enemy probes.  It will only use Warp Links to move and it can travel in SG Sectors.  When it finds a probe it will destroy it and continue looking for more probes to destroy.  The Scan Tech is used to try and find cloaked enemy probes.";
				$this->l_stationary = "Stationary Guard Probe";
				$this->l_roaming = "Roaming Attack Probe";
			break;
		}
	}

	var $tag = "LOG5_PROBE_HUNTER_PROBE";

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
		$items = explode(",", trim($data));
		for($i = 0; $i < count($items); $i++)
		{
			$variable = explode("=", $items[$i]);
			$variable[0] = trim($variable[0]);
			$variable[1] = trim($variable[1]);
			$$variable[0] = $variable[1];
		}
		if($probe_hunter_list == 0)
		{
			$info = $this->l_stationary;
		}
		else
		{
			$info = $this->l_roaming;
		}
		return $info;
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
		$orders_array[] = "probe_hunter_list = 0;	list ; 0=Stationary Guard Probe, 1=Roaming Attack Probe ;A Stationary Guard Probe will sit in the sector you have dropped it and attack any probe that enters the sector.  The Roaming Attack Probe will use warp links to travel around the universe attacking all probes it can find.";
		return $orders_array;
	}
 
	function probe_finishorders_code()
	{
		global $db, $db_prefix, $warp_target_sector, $template_object, $l_global_mmenu, $templatename, $title, $sectorinfo;
		global $probeclass, $title, $new_type, $l_probe_forbidSG, $l_probe_forbidFED, $l_probe_forbidINVALID, $probe_id;

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
		$data = "probe_hunter_list=" . $_POST['probe_hunter_list'];

		$debug_query = $db->Execute("UPDATE {$db_prefix}probe SET class='$probeclass[$new_type]', type=$new_type, data=" . $db->qstr($data) . " WHERE probe_id=$probe_id");
		db_op_result($debug_query,__LINE__,__FILE__);
		echo "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=probes.php\">";
	}

	function probe_move_code($probeinfo, $shiptype, $destination)
	{
	}

	function probe_scheduler_code($probeinfo)
	{
		global $db, $db_prefix, $level_factor;

		$items = explode(",", trim($probeinfo['data']));
		for($i = 0; $i < count($items); $i++)
		{
			$variable = explode("=", $items[$i]);
			$variable[0] = trim($variable[0]);
			$variable[1] = trim($variable[1]);
			$$variable[0] = $variable[1];
		}

		if($probe_hunter_list == 1)
		{
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
					$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and zone_id != 2 and galaxy_id = $galaxy_idORDER BY rand()", 1);
					$targetlink = $findem->fields['sector_id'];
				}
			}

			if($targetlink > 0)
			{
				$resultcc = $db->SelectLimit("SELECT turns, team, character_name FROM {$db_prefix}players WHERE player_id=$probeinfo[owner_id]", 1);
				db_op_result($resultcc,__LINE__,__FILE__);
				if ($resultcc > 0)
				{
					if ($resultcc->fields['turns'] >= 1)
					{
						TextFlush ($this->l_roaming . " Safe Move to sector $targetlink <br>");
						$query="UPDATE {$db_prefix}players SET  turns_used=turns_used+1, turns=turns-1 WHERE player_id=$probeinfo[owner_id]";
						$move_result = $db->Execute ("$query");
						$db->Execute("UPDATE {$db_prefix}probe SET sector_id = $targetlink WHERE probe_id = $probeinfo[probe_id]");

						$this->scan_for_probe($probeinfo, $resultcc->fields['team'], $resultcc->fields['character_name']);
						log_move($probeinfo['owner_id'], $probeinfo['probe_id'], $probeinfo['sector_id'], $targetlink, 1, $probeinfo['cloak'], $sectres->fields['zone_id']);
					}else{
						TextFlush ("Failed Move not enough turns - 1 turn needed <br>");
						PROBE_playerlog($probeinfo['owner_id'], "LOG9_PROBE_NOTURNS", "$probeinfo[probe_id]|$targetlink"); 
					}
				}
			}
		}
		else
		{
			$resultcc = $db->SelectLimit("SELECT team, character_name FROM {$db_prefix}players WHERE player_id=$probeinfo[owner_id]", 1);
			db_op_result($resultcc,__LINE__,__FILE__);
			TextFlush ($this->l_stationary . "<br>");
			$this->scan_for_probe($probeinfo, $resultcc->fields['team'], $resultcc->fields['character_name']);
		}
	}

	function scan_for_probe($probeinfo, $team, $character_name)
	{
		global $db, $db_prefix;
		$targetlink = $probeinfo['sector_id'];
		$owner_id = $probeinfo['owner_id'];
		$probe_id = $probeinfo['probe_id'];
		if($team == 0)
		{
			$query = "SELECT * FROM {$db_prefix}probe, {$db_prefix}players WHERE {$db_prefix}probe.sector_id = $targetlink and {$db_prefix}probe.owner_id != $owner_id and {$db_prefix}players.player_id={$db_prefix}probe.owner_id";
		}
		else
		{
			$query = "SELECT * FROM {$db_prefix}probe, {$db_prefix}players WHERE {$db_prefix}probe.sector_id = $targetlink and {$db_prefix}probe.owner_id != $owner_id and ({$db_prefix}players.player_id={$db_prefix}probe.owner_id and {$db_prefix}players.team != $team)";
		}
		$result4 = $db->Execute($query);
		db_op_result($result4,__LINE__,__FILE__);
		if($result4->RecordCount() > 0)
		{
			while (!$result4->EOF)
			{
				$moreinfo = $result4->fields;
				TextFlush ("<font color=\"lime\"><b>Found $moreinfo[character_name]'s $moreinfo[class] probe!</b></font><br>");
				$success = SCAN_SUCCESS($probeinfo['sensors'], $moreinfo['cloak'], 1);
				if (mt_rand(1, 100) < $success)
				{
					TextFlush ("<font color=\"yellow\"><b>ATTACKING $moreinfo[character_name]'s $moreinfo[class] probe!</b></font><br>");
					PROBE_playerlog($owner_id, "LOG9_PROBEHUNTER_SUCCEED", "$moreinfo[class]|$targetlink|$moreinfo[character_name]");
					PROBE_playerlog($moreinfo['owner_id'], "LOG9_PROBEHUNTER_DESTROYED", "$moreinfo[class]|$targetlink|$character_name");
					$debug_query = $db->Execute("DELETE from {$db_prefix}probe where probe_id=$moreinfo[probe_id]");
					db_op_result($debug_query,__LINE__,__FILE__);

					if(mt_rand(1, 1500) < 250)
					{
						TextFlush ("<font color=\"red\"><b>Probe destroyed in explosion from attacked probe.</b></font><br>");
						PROBE_playerlog($owner_id, "LOG9_PROBEHUNTER_EXPLODED", "$moreinfo[class]|$targetlink|$moreinfo[character_name]");
						$debug_query = $db->Execute("DELETE from {$db_prefix}probe where probe_id=$probe_id");
						db_op_result($debug_query,__LINE__,__FILE__);
						break;
					}
				}
				$result4->MoveNext();
			}
		}
	}
}

?>