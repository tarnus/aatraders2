<?php
class sgsearch {
	var $class = "sgsearch";
	var $type = 7;
	var $l_probe_type;
	var $l_probe_target;
	var $l_probe_description;

	// fill language variables
	function sgsearch()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "SG Sector Otsing Probe";
				$this->l_probe_description = "SG Sector Otsing juures on väga võimas juures. Viska juures arvesse peasekretäri sektor ja sond alustab automaatselt otsivad kõik SG sektorite taga Gateway sektor ja jäta kunagi müügi alal. Ta jälgib kõiki SG Sektorid ta on otsinud ja alati valis unsearched SG sektori sulatada leitud linke. See tagasi saata mis tahes teavet nagu Warp Probe põhineb Sensor tase SG Otsing Probe. Kui sond on langenud arvesse sektori ilma sulatada link SG sektori see ümber arvestada Sentry Probe.";
			break;

			case "french":
				$this->l_probe_type = "SG Probe Recherche par secteur";
				$this->l_probe_description = "Une SG Recherche par secteur de la sonde est une sonde très puissante. Vous déposez la sonde dans le secteur SG et la sonde se lance automatiquement la recherche de tous les secteurs SG derrière le secteur de la Porte et ne jamais quitter la zone de SG. Elle permet de conserver une trace de tous les Secteurs SG il a cherché et toujours choisi un secteur fouillé SG de la chaîne des liens trouvés. Il renverra toute information, tout comme une sonde Warp basé sur le niveau du capteur de la sonde Recherche SG. Si la sonde est placée dans un secteur sans lien de chaîne à un secteur SG qu&#39;elle convertira en une sonde Sentry.";
			break;

			case "german":
				$this->l_probe_type = "SG Sector Suche Probe";
				$this->l_probe_description = "Ein SG Sector Suche Probe ist ein sehr leistungsfähiges Sonde. Du lässt die Sonde in SG Sektor und die Sonde wird automatisch mit der Suche alle SG Sektoren hinter dem Gateway-Sektor und niemals die SG Gebiet zu verlassen. Es wird im Auge behalten alle SG Branche hat gesucht und wählte stets ein recherchierte SG Sektors aus dem Warp-Links gefunden. Es sendet keine Informationen zurück wie ein Warp-Sonde auf dem Sensor Level des Generalsekretärs Suche auf Probe. Wenn die Sonde in einem Bereich ohne eine Kette Link auf eine SG-Sektor wird in eine Probe Sentry umwandeln ließ.";
			break;

			case "italian":
				$this->l_probe_type = "Sonda SG Settore Ricerca";
				$this->l_probe_description = "Un SG Settore Ricerca Probe è una sonda molto potente. Si elimina la sonda in SG Settore e la sonda si avvierà automaticamente una ricerca in tutti i settori SG dietro il Settore Gateway e non lasciare mai la zona SG. E non mancherà di tenere traccia di tutti i settori SG ha sempre cercato e scelto un settore unsearched SG dalla curvatura link trovati. Si provvede poi ad inviare tutte le informazioni proprio come una sonda Warp basata sul livello del sensore della sonda SG ricerca. Se la sonda è caduto in un settore senza un collegamento ordito ad un settore SG si convertirà in un Probe Sentry.";
			break;

			case "spanish":
				$this->l_probe_type = "Sonda SG sector de las búsquedas";
				$this->l_probe_description = "Un SG Buscar Sector Probe es una sonda muy poderosa. Se le cae la sonda en SG Sector y la sonda se iniciará automáticamente la búsqueda de todos los sectores SG detrás de la puerta de enlace del sector y que no deje el área de SG. Asimismo, mantendrá un registro de todos los sectores SG se ha buscado y siempre la opción de un sector de SG unsearched de la urdimbre se han encontrado vínculos. Se enviará de nuevo toda la información al igual que una sonda Warp basa en el nivel del sensor de la sonda SG búsqueda. Si la sonda se coloca en un sector sin un vínculo de la urdimbre a un sector SG se convierte en una sonda Sentry.";
			break;

			case "albanian":
				$this->l_probe_type = "Hetim SG Sektori Search";
				$this->l_probe_description = "Një Sektori SG Kërko hetim është një hetim shumë të fuqishme. Ju rënie hetim në Sektorin SG dhe hetimi do të fillojë automatikisht në kërkim të gjithë sektorët SG prapa Sektori Gateway dhe nuk largohen nga zona SG. Ajo do të mbajnë gjurmët e të gjithë sektorët SG ka kontrolluar dhe gjithmonë zgjodhi një sektor unsearched SG nga shtrembërim lidhjet gjetur. Ai do të dërgojë të mbështeste çdo informacion vetëm si një hetim Warp bazuar mbi nivelin sensor i hetimin SG Search. Nëse hetim është rënë në një sektor pa një lidhje të tërheq me litar në një sektor SG ajo do të konvertohet në një hetim rojtar.";
			break;

			case "catalan":
				$this->l_probe_type = "Sonda SG sector de les cerques";
				$this->l_probe_description = "Un SG Cerca Sector Probe és una sonda molt poderosa. Se li cau la sonda en SG Sector i la sonda s&#39;iniciarà automàticament la recerca de tots els sectors SG darrere de la porta d&#39;enllaç del sector i que no deixi l&#39;àrea de SG. Així mateix, mantindrà un registre de tots els sectors SG s&#39;ha buscat i sempre l&#39;opció d&#39;un sector de SG unsearched de l&#39;ordit s&#39;han trobat vincles. S&#39;enviarà de nou tota la informació igual que una sonda Warp basa en el nivell del sensor de la sonda SG cerca. Si la sonda es col loca en un sector sense un vincle de l&#39;ordit a un sector SG es converteix en una sonda Sentry.";
			break;

			case "danish":
				$this->l_probe_type = "SG Sector Søg Probe";
				$this->l_probe_description = "En SG Sector Søg Probe er en meget kraftfuld sonde. Du slipper sonden ind SG sektor og sonden vil automatisk begynde at søge alle de SG sektorer bag Gateway sektor og aldrig forlader SG området. Det vil holde styr på alle de SG Sektorer det har søgt og altid valgt en unsearched SG sektor fra warp links fundet. Det vil sende tilbage oplysninger, ligesom en Warp Probe baseret på Sensor niveau af SG Søg Probe. Hvis sonden er faldet i en sektor, uden en kæde link til en SG sektor, det vil konvertere til en Sentry Probe.";
			break;

			case "dutch":
				$this->l_probe_type = "SG Sector Search Probe";
				$this->l_probe_description = "Een SG Sector Zoeken Probe is een zeer krachtige sonde. U drop de sonde in SG sector en de sonde zal automatisch beginnen met zoeken alle sectoren van de SG achter de Gateway sector en nooit de SG gebied te verlaten. Het zal bijhouden van alle SG Sectoren heeft doorzocht en altijd gekozen voor een unsearched SG sector van de warp links gevonden. Het zal alle informatie terug te sturen, net als een Warp-Probe op basis van de sensor niveau van de SG Search Probe. Als de sonde is gevallen in een sector zonder een warp link naar een SG sector zal omzetten in een Sentry Probe.";
			break;

			case "finnish":
				$this->l_probe_type = "SG Sector Etsi Probe";
				$this->l_probe_description = "SG Ala Etsi Probe on erittäin voimakas anturi. Pudotat mittapää SG sektori ja koetin automaattisesti alkaa etsiä kaikki SG alojen takana Gateway-ala ja koskaan jätä SG alueella. Se pitää kirjaa kaikista SG Ala on etsinyt ja aina valitsi unsearched SG alaa loimi linkkejä löytynyt. Se palauttaa kaikki tiedot, kuten Warp Probe perustuu anturi taso korkeana Etsi Probe. Jos anturi on pudotettu alalle ilman taivuttaa linkki SG alan se muuntaa Sentry Probe.";
			break;

			case "indonesian":
				$this->l_probe_type = "SG Sektor Cari Probe";
				$this->l_probe_description = "Sebuah SG Sektor Cari Probe adalah pemeriksaan yang sangat kuat. Anda menjatuhkan SG Sektor penyelidikan dan probe akan secara otomatis mulai mencari semua sektor SG di belakang Gateway Sektor dan tidak pernah meninggalkan wilayah SG. Ini akan terus melacak semua Sektor SG telah mencari dan selalu memilih sebuah SG unsearched sektor dari link lungsin ditemukan. Akan mengirimkan kembali informasi apapun sama seperti Probe Warp berdasarkan Tingkat Sensor DC Pencarian Probe. Jika probe dijatuhkan ke dalam sektor tanpa warp link ke suatu sektor SG akan mengkonversi ke dalam Sentry Probe.";
			break;

			case "norwegian":
				$this->l_probe_type = "SG Sector Søk Probe";
				$this->l_probe_description = "Et SG Sector Søk Probe er en meget kraftig sonde. Du slipper sonde inn i SG sektor og sonden vil automatisk begynne å søke alle SG sektorene bak Gateway sektor og aldri forlate SG området. Det vil holde oversikt over alle SG Sektorer har søkte og alltid valgte en unsearched SG sektor fra warp koblinger. Det vil sende tilbake noen opplysninger som en Warp Probe basert på Sensor Nivå av SG Search Probe. Hvis sonden er sluppet inn i en sektor uten en deformere lenke til en SG sektor vil konvertere til et Sentry Probe.";
			break;

			case "portuguese":
				$this->l_probe_type = "SG Probe Setor de Pesquisa";
				$this->l_probe_description = "Um SG Setor de Pesquisa Probe é um teste muito poderoso. Está suspensa a sonda para SG Setor ea sonda irá automaticamente começar a procurar todos os setores SG atrás do Setor Gateway e nunca deixar a área SG. Ele irá acompanhar todos os Sectores SG tem procurado e sempre escolhia um sector SG unsearched da urdidura links found. Ele irá devolver qualquer informação apenas como uma sonda Warp baseado no sensor de nível da Sonda SG Pesquisa. Se o teste é deixado em um setor sem um link para uma urdidura sector SG irá converter em uma sonda sentinela.";
			break;

			case "swedish":
				$this->l_probe_type = "SG Sector Search Probe";
				$this->l_probe_description = "En SG Sector Search Probe är en mycket kraftfull sond. Du släpper sonden till SG Sektor och sonden kommer automatiskt att börja söka alla SG sektorer bakom Gateway sektorn och aldrig lämnar SG området. Det kommer att hålla reda på alla SG sektorer som har sökt och alltid valde en unsearched SG sektor från varp länkar hittades. Det kommer att skicka tillbaka all information precis som en Warp Probe baserat på Sensor nivå av generalsekreteraren Search Probe. Om sonden hamnar i ett område utan en varp länk till en SG sektor kommer att omvandlas till ett Sentry Probe.";
			break;

			default:
				$this->l_probe_type = "SG Sector Search Probe";
				$this->l_probe_description = "An SG Sector Search Probe is a very powerful probe.  You drop the probe into SG Sector and the probe will automatically start searching all of the SG sectors behind the Gateway Sector and never leave the SG area.  It will keep track of all the SG Sectors it has searched and always chose an unsearched SG sector from the warp links found.  It will send back any information just like a Warp Probe based upon the Sensor Level of the SG Search Probe. If the probe is dropped into a sector without a warp link to an SG sector it will convert into a Sentry Probe.";
			break;
		}
	}

	var $tag = "LOG5_PROBE_SGSEARCH";

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
		global $db, $db_prefix, $warp_target_sector, $template_object, $l_global_mmenu, $templatename, $title, $sectorinfo;
		global $probeclass, $title, $new_type, $probe_id;

		$debug_query = $db->Execute("UPDATE {$db_prefix}probe SET class='$probeclass[$new_type]', type=$new_type, data='' WHERE probe_id=$probe_id");
		db_op_result($debug_query,__LINE__,__FILE__);
		echo "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=probes.php\">";
	}

	function probe_move_code($probeinfo, $shiptype, $destination)
	{
	}

	function probe_scheduler_code($probeinfo)
	{
		global $db, $db_prefix, $level_factor;

		$sector_id_list = explode(",", trim($probeinfo['data']));
		$targetlink = 0;
		$oldlinks = array();

		$linkres = $db->Execute ("SELECT link_dest FROM {$db_prefix}links WHERE link_start='$probeinfo[sector_id]'");
		db_op_result($linkres,__LINE__,__FILE__);
		while (!$linkres->EOF)
		{
			$oldlinks[] = $linkres->fields['link_dest'];
			echo $linkres->fields['link_dest'] . " - ";
			$sectres = $db->Execute ("SELECT zone_id, sg_sector FROM {$db_prefix}universe WHERE sector_id='" . $linkres->fields['link_dest'] . "'");
			if ($sectres->fields['zone_id'] == 2 || $sectres->fields['sg_sector'] == 0)
			{
				array_pop($oldlinks);
			}
			else
			{
				if(!in_array($linkres->fields['link_dest'], $sector_id_list) && $targetlink == 0)
				{
					$targetlink = $linkres->fields['link_dest'];
				}
			}
//echo $targetlink . "<br>";
//print_r( $oldlinks ). "<br>";
			$linkres->MoveNext();
		}

		if($targetlink == 0)
		{
//echo $targetlink . "<br>";
//echo count($oldlinks) . "<br>";
//print_r( $oldlinks ). "<br>";
			if(count($oldlinks) > 0)
			{
				$targetlink = $oldlinks[array_rand($oldlinks)];
//echo $targetlink . "<br>";
			}
			else
			{
				$result = $db->Execute("UPDATE {$db_prefix}probe SET type=0, class='sentry' WHERE probe_id=$probeinfo[probe_id]");
				db_op_result($result,__LINE__,__FILE__);
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
					if(!in_array($targetlink, $sector_id_list))
					{
						$probeinfo['data'] .= "$targetlink,";
					}
					$db->Execute("UPDATE {$db_prefix}probe SET sector_id = $targetlink, data=" . $db->qstr($probeinfo['data']) . " WHERE probe_id = $probeinfo[probe_id]");

					sched_probe_detect( $probeinfo );
					log_move($probeinfo['owner_id'], $probeinfo['probe_id'], $probeinfo['sector_id'], $targetlink, 1, $probeinfo['cloak'], $sectres->fields['zone_id']);
				}else{
					TextFlush ("Failed Move not enough turns - 1 turn needed <br>");
					PROBE_playerlog($probeinfo['owner_id'], "LOG9_PROBE_NOTURNS", "$probeinfo[probe_id]|$targetlink"); 
				}
			}
		}
	}
}
?>