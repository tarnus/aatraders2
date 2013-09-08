<?php
class sentry {
	var $class = "sentry";
	var $type = 0;
	var $l_probe_type;
	var $l_probe_description;

	// fill language variables
	function sentry()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondid ei liigu Stealth sondid. Kui paigutada sektori nad istuda ja oodata igal laeval siseneda sektoris. See skaneerida laeva ja kohe registreerivad andmed hilisemaks. Kui sond on hävitada kõik salvestatud teave võib kustuda. Kui sond asetatakse sektori comtaining planeedid ta püüab Scan planeedid regulaarselt ja aru mingit teavet.";
				$this->lss1 = "Jooksev Valdkond: [destination_name] Viimane Laev vaadatuna: [shiptype] klassi laeva.";
				$this->lss2 = "Jooksev Valdkond: [destination_name] Viimane Laev vaadates: Mängija [character_name] pardal [shiptype] klassi laeva.";
			break;

			case "french":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondes sont des sondes furtivité stationnaire. Lorsqu&#39;il est placé dans un secteur ils sont assis et attendre que tout navire d&#39;entrer dans le secteur. Il va scanner le navire et enregistre immédiatement les informations pour référence future. Si la sonde est détruite toutes les informations enregistrées sont perdues. Si la sonde est placée dans un secteur comtaining planètes il va essayer de scanner des planètes sur une base régulière et de faire rapport tous renseignements.";
				$this->lss1 = "Secteur actuel: [destination_name], Ship Dernière visite: [shiptype] navire de la classe.";
				$this->lss2 = "Secteur actuel: [destination_name], Ship Dernière visite: Player [character_name] à bord d&#39;un [shiptype] navire de la classe.";
			break;

			case "german":
				$this->l_probe_type = "Wachposten";
				$this->l_probe_description = "Sentry Sonden sind stationäre Stealth-Sonden. Wenn in einem Sektor platziert sie sitzen und warten, bis jedes Schiff, auf dem Sektor geben. Es wird das Schiff sofort scannen und speichern die Informationen für später auf. Wenn die Sonde alle aufgezeichneten Informationen zerstört ist, ist verloren. Wenn die Sonde in einem Sektor comtaining Planeten wird es versuchen, den Planeten regelmäßig scannen und Bericht zu erstatten Informationen gelegt.";
				$this->lss1 = "Current Sector: [destination_name] Last Ship Gesehen: [shiptype] Klasse Schiff.";
				$this->lss2 = "Current Sector: [destination_name] Last Ship Gesehen: Player [character_name] an Bord eines [shiptype] Klasse Schiff.";
			break;

			case "italian":
				$this->l_probe_type = "Sonda di avvistamento";
				$this->l_probe_description = "Sonde Sentry sono sonde stealth fermo. Al momento dell&#39;immissione in un settore in cui sedersi e aspettare che ogni nave ad entrare nel settore. E &#39;la scansione della nave e registra immediatamente le informazioni per riferimento futuro. Se la sonda viene distrutto tutte le informazioni registrate è perduto. Se la sonda viene posto in un settore comtaining pianeti si cercherà di eseguire la scansione dei pianeti su base regolare e riferire tutte le informazioni.";
				$this->lss1 = "Current Settore: [destination_name], Nave Ultimo Click: [shiptype] nave di classe.";
				$this->lss2 = "Current Settore: [destination_name], Nave Ultimo Click: Player [character_name] a bordo di un [shiptype] nave di classe.";
			break;

			case "spanish":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Las sondas Sentry son las sondas sigilo estacionaria. Cuando se coloca en un sector que sentarse y esperar a que un buque para entrar en el sector. Se analizará el barco inmediatamente y registrar la información para referencia futura. Si la sonda se destruye toda la información registrada se ha perdido. Si la sonda se coloca en un sector comtaining planetas que tratará de explorar los planetas en forma regular e informar cualquier información.";
				$this->lss1 = "Actual del sector: [destination_name], último barco Visto: [shiptype] barco de la clase.";
				$this->lss2 = "Actual del sector: [destination_name], último barco Visto: Player [character_name] a bordo de un buque [shiptype] clase.";
			break;

			case "albanian":
				$this->l_probe_type = "Rojë hetimin";
				$this->l_probe_description = "Rojë hetimet janë hetimet stacionare vjedhurazi. Kur vendoset në një sektor që ulen dhe presin për çdo anije për të hyrë në sektor. Ajo do të scan anije dhe menjëherë rekord për referim në të ardhmen. Nëse hetim është shkatërruar të gjitha informatat të regjistruara është e humbur. Nëse hetimi është vendosur në një sektor comtaining planetet do të përpiqet të scan planetet në një bazë të rregullt dhe të raportojnë përsëri ndonjë informacion.";
				$this->lss1 = "Sektori i tanishëm: [destination_name], Ship Last Seen: [shiptype] anije klasës.";
				$this->lss2 = "Sektori i tanishëm: [destination_name], Ship Last Seen: Player [character_name] në bordin e një [shiptype] anije klasës.";
			break;

			case "catalan":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Les sondes Sentry són les sondes sigil estacionària. Quan es col loca en un sector que seure i esperar que un vaixell per entrar en el sector. S&#39;analitzarà el vaixell immediatament i registrar la informació per a referència futura. Si la sonda es destrueix tota la informació registrada s&#39;ha perdut. Si la sonda es col loca en un sector comtaining planetes que tractarà d&#39;explorar els planetes en forma regular i informar qualsevol informació.";
				$this->lss1 = "Actual del sector: [destination_name], el darrer vaixell Vist: [shiptype] vaixell de la classe.";
				$this->lss2 = "Actual del sector: [destination_name], el darrer vaixell Vist: Player [character_name] a bord d&#39;un vaixell [shiptype] classe.";
			break;

			case "danish":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sonder er stationær stealth-sonder. Når den placeres i en sektor, de sidde og vente på ethvert skib at komme ind i sektoren. Det vil skanne skibet og umiddelbart registrere de oplysninger til fremtidig brug. Hvis sonden er ødelagt alle registrerede oplysninger går tabt. Hvis sonden er placeret i en sektor comtaining planeter vil forsøge at scanne planeter regelmæssigt og rapportere tilbage nogen oplysninger.";
				$this->lss1 = "Nuværende Sektor: [destination_name], Last Seen Ship: [shiptype] class skib.";
				$this->lss2 = "Nuværende Sektor: [destination_name], Last Seen Ship: Spiller [character_name] om bord på et [shiptype] class skib.";
			break;

			case "dutch":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondes stilstaat stealth-sondes. Wanneer geplaatst in een sector zij zitten en wachten tot een schip aan de sector te betreden. Het scant het schip en direct opnemen van de informatie voor toekomstig gebruik. Als de sonde wordt alle opgeslagen informatie vernietigd verloren. Als de sonde wordt geplaatst in een sector comtaining planeten zal proberen om de planeten scannen op een regelmatige basis en verslag uit alle informatie.";
				$this->lss1 = "Huidige Sector: [destination_name], laatste schip Seen: [shiptype] klasse schip.";
				$this->lss2 = "Huidige Sector: [destination_name], laatste schip Seen: Player [character_name] aan boord van een [shiptype] klasse schip.";
			break;

			case "finnish":
				$this->l_probe_type = "Sentrylle Probe";
				$this->l_probe_description = "Sentry mittapäät ovat paikallaan varkain probes. Joutuessa alalla he istua ja odottaa, että kaikki alukset tulla alalle. Se skannaa aluksen ja välittömästi tallentaa tiedot myöhempää käyttöä varten. Jos anturi on tuhonnut kaikki tallennettu tieto on menetetty. Jos anturi on sijoitettu alan comtaining planeetat se yrittää skannata planeetat säännöllisesti ja raportoi tiedot.";
				$this->lss1 = "Nykyinen Ala: [destination_name] Viimeisin Ship nähty: [shiptype] luokan alus.";
				$this->lss2 = "Nykyinen Ala: [destination_name] Viimeisin Ship nähty: Pelaaja [character_name] aluksella [shiptype] luokan alus.";
			break;

			case "indonesian":
				$this->l_probe_type = "Penjaga Probe";
				$this->l_probe_description = "Penjaga probe probe yang diam diam-diam. Ketika ditempatkan di sektor mereka duduk dan menunggu untuk setiap kapal untuk memasuki sektor. Ini akan memindai kapal dan segera merekam informasi untuk referensi di masa mendatang. Jika probe dicatat menghancurkan semua informasi yang hilang. Jika probe ditempatkan di sektor comtaining planet itu akan mencoba untuk memindai planet secara teratur dan melaporkan kembali informasi apapun.";
				$this->lss1 = "Current Sektor: [destination_name], Kapal Last Seen: [shiptype] kelas kapal.";
				$this->lss2 = "Current Sektor: [destination_name], Kapal Last Seen: Player [character_name] on board a [shiptype] kelas kapal.";
			break;

			case "norwegian":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry prober er stillestående stealth sonder. Når plassert i en sektor de sitte og vente på noen skip å gå inn i sektoren. Det vil skanne skipet og umiddelbart registrere informasjonen for fremtidig referanse. Hvis sonden er ødelagt all registrert informasjon er tapt. Hvis sonden er plassert i en sektor comtaining planetene vil det prøve å skanne planetene på regelmessig basis og rapportere tilbake noen informasjon.";
				$this->lss1 = "Nåværende Sektor: [destination_name], Sist Ship Seen: [shiptype] klasse skip.";
				$this->lss2 = "Nåværende Sektor: [destination_name], Sist Ship Seen: Player [character_name] ombord a [shiptype] klasse skip.";
			break;

			case "portuguese":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondas são sondas stealth estacionária. Quando colocado em um setor que sentar e esperar por qualquer navio a entrar no setor. Ele irá varrer o navio e imediatamente registrar as informações para referência futura. Se a sonda for destruído toda a informação gravada será perdida. Se a sonda é colocada em um setor comtaining planetas ele vai tentar fazer a varredura dos planetas em uma base regular e comunicar qualquer informação.";
				$this->lss1 = "Current Sector: [destination_name], Navio Última atividade: [shiptype] navio da classe.";
				$this->lss2 = "Current Sector: [destination_name], Navio Última atividade: Player [character_name] a bordo de um [shiptype].";
			break;

			case "swedish":
				$this->l_probe_type = "Vaktpost Probe";
				$this->l_probe_description = "Sentry sonder är stationära stealth sonder. När den placeras i en sektor de sitta och vänta på att alla fartyg att komma in i branschen. Det kommer att skanna fartyget och omedelbart registrera information för framtida referens. Om sonden är förstört alla registrerade information går förlorad. Om sonden är placerad i en sektor comtaining planeter man kommer att försöka att söka planeterna på regelbunden basis och rapportera tillbaka all information.";
				$this->lss1 = "Nuvarande Sector: [destination_name], Last Ship Seen: [shiptype] klass skepp.";
				$this->lss2 = "Nuvarande Sector: [destination_name], Last Ship Seen: Player [character_name] ombord a [shiptype] klass skepp.";
			break;

			default:
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry probes are stationary stealth probes.  When placed in a sector they sit and wait for any ship to enter the sector.  It will scan the ship and immediately record the information for future reference.  If the probe is destroyed all recorded information is lost.  If the probe is placed in a sector comtaining planets it will try to scan the planets on a regular basis and report back any information.";
				$this->lss1 = "Current Sector: [destination_name], Last Ship Seen: [shiptype] class ship.";
				$this->lss2 = "Current Sector: [destination_name], Last Ship Seen: Player [character_name] on board a [shiptype] class ship.";
			break;
		}
	}

	var $tag = "LOG5_PROBE_SENTRY";

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
	// listselection = 5; list  ; 1=1 Planet, 2=2 Planets, 3=3 Planets, 4=4 Planets, 5=5 Planets; This is the maximum number of sector sizes.  This size determines how many planets/cities each sector can support. Do not set this higher than 5 but it can be set from 1 to 5.
	// noinput = ; noinput  ; ; Information text

	function probe_orders_code()
	{
		// No orders for this probe
		$orders_array = array();
		return $orders_array;
	}

	function probe_finishorders_code()
	{
		global $db, $db_prefix, $probe_id, $l_global_mmenu, $templatename, $template_object;
		global $probeclass, $new_type, $l_probe_forbidFED, $title, $sectorinfo;

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
		global $db, $db_prefix, $shipinfo, $playerinfo, $shipdevice, $langdir, $lssd_level_two, $destination_name, $shiptypes;

		$sensors = $probeinfo['sensors'];
		$probe_id = $probeinfo['probe_id'];
		$owner_id = $probeinfo['owner_id'];

		$success = SCAN_SUCCESS($sensors, $shipinfo['cloak'], $shiptypes[$shipinfo['class']]['basehull']);

		if (mt_rand(1, 100) < $success)
		{
			$resteam = $db->SelectLimit("SELECT team FROM {$db_prefix}players WHERE player_id=$owner_id", 1);
			db_op_result($resteam,__LINE__,__FILE__);
			$sb_alli = $resteam->fields['team'];
			$resteam->close();

			if ($sb_alli != 0)
			{
				if ($sensors >= $lssd_level_two)
				{
					$sbt = str_replace("[destination_name]", $destination_name, $this->lss2);
					$sbt = str_replace("[character_name]", $playerinfo['character_name'], $sbt);
					$sbt = str_replace("[shiptype]", $shiptype, $sbt);
				}
				else
				{
					$sbt = str_replace("[destination_name]", $destination_name, $this->lss1);
					$sbt = str_replace("[shiptype]", $shiptype, $sbt);
				}

			  	$res = $db->Execute("INSERT INTO {$db_prefix}shoutbox (player_id,player_name,sb_date,sb_text,sb_alli) VALUES ($owner_id,'probe - $probe_id'," . time() . "," . $db->qstr($sbt) . ",$sb_alli) ");
				db_op_result($res3,__LINE__,__FILE__);
			}

			if ($sensors >= $lssd_level_two)
			{
				playerlog($owner_id, "LOG9_PROBE_DETECTED_SHIP", "$probe_id|$destination|$playerinfo[character_name]($shiptype)");
			}
			else
			{
				playerlog($owner_id, "LOG9_PROBE_DETECTED_SHIP", "$probe_id|$destination|$l_unknown($shiptype)");
			}

			if (mt_rand(1, 100) < $success)
			{
				$sc_hull = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['hull']) : "???";
				$sc_engines = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['engines']) : "???";
				$sc_power = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['power']) : "???";
				$sc_fighter = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['fighter']) : "???";
				$sc_sensors = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['sensors']) : "???";
				$sc_beams = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['beams']) : "???";
				$sc_torp_launchers = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['torp_launchers']) : "???";
				$sc_armor = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['armor']) : "???";
				$sc_shields = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['shields']) : "???";
				$sc_cloak = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['cloak']) : "???";
				$sc_ecm = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['ecm']) : "???";
				$sc_armor_pts = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['armor_pts'])) : "???";
				$sc_ship_fighters = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['fighters'])) : "???";
				$sc_torps = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['torps'])) : "???";
				$sc_credits = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['credits'])) : "???";
				$sc_ship_energy = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['energy'])) : "???";
				$sc_dev_minedeflector = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipdevice['dev_minedeflector']['amount'])) : "???";
				$sc_dev_emerwarp = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipdevice['dev_emerwarp']['amount']) : "???";
				$sc_dev_pod = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipdevice['dev_escapepod']['amount']) : "???";
				$sc_ship_colonists = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['colonists'])) : "???";
				$sc_ship_ore = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['ore'])) : "???";
				$sc_ship_organics = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['organics'])) : "???";
				$sc_ship_goods = (mt_rand(1, 100) < $success) ? NUMBER(SCAN_ERROR($sensors, $shipinfo['cloak'], $shipinfo['goods'])) : "???";
				$sc_dev_warpedit = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipdevice['dev_warpedit']['amount']) : "???";
				$sc_dev_genesis = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipdevice['dev_genesis']['amount']) : "???";
				$sc_scoop = (mt_rand(1, 100) < $success) ? SCAN_ERROR($sensors, $shipinfo['cloak'], $shipdevice['dev_fuelscoop']['amount']) : "???";
				playerlog($owner_id, "LOG9_PROBE_SCAN_SHIP", "$probe_id|$destination|$playerinfo[character_name]($shiptype)|$sc_hull|$sc_engines|$sc_power|$sc_fighter|$sc_sensors|$sc_beams|$sc_torp_launchers|$sc_armor|$sc_shields|$sc_cloak|$sc_armor_pts|$sc_ship_fighters|$sc_torps|$sc_credits|$sc_ship_energy|$sc_dev_minedeflector|$sc_dev_emerwarp|$sc_dev_pod|$sc_ecm");
			}
		}
	}

	function probe_scheduler_code()
	{
	}
}

?>