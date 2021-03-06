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
				$this->l_probe_description = "Sentry sondid ei liigu Stealth sondid. Kui paigutada sektori nad istuda ja oodata igal laeval siseneda sektoris. See skaneerida laeva ja kohe registreerivad andmed hilisemaks. Kui sond on h�vitada k�ik salvestatud teave v�ib kustuda. Kui sond asetatakse sektori comtaining planeedid ta p��ab Scan planeedid regulaarselt ja aru mingit teavet.";
				$this->lss1 = "Jooksev Valdkond: [destination_name] Viimane Laev vaadatuna: [shiptype] klassi laeva.";
				$this->lss2 = "Jooksev Valdkond: [destination_name] Viimane Laev vaadates: M�ngija [character_name] pardal [shiptype] klassi laeva.";
			break;

			case "french":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondes sont des sondes furtivit� stationnaire. Lorsqu&#39;il est plac� dans un secteur ils sont assis et attendre que tout navire d&#39;entrer dans le secteur. Il va scanner le navire et enregistre imm�diatement les informations pour r�f�rence future. Si la sonde est d�truite toutes les informations enregistr�es sont perdues. Si la sonde est plac�e dans un secteur comtaining plan�tes il va essayer de scanner des plan�tes sur une base r�guli�re et de faire rapport tous renseignements.";
				$this->lss1 = "Secteur actuel: [destination_name], Ship Derni�re visite: [shiptype] navire de la classe.";
				$this->lss2 = "Secteur actuel: [destination_name], Ship Derni�re visite: Player [character_name] � bord d&#39;un [shiptype] navire de la classe.";
			break;

			case "german":
				$this->l_probe_type = "Wachposten";
				$this->l_probe_description = "Sentry Sonden sind station�re Stealth-Sonden. Wenn in einem Sektor platziert sie sitzen und warten, bis jedes Schiff, auf dem Sektor geben. Es wird das Schiff sofort scannen und speichern die Informationen f�r sp�ter auf. Wenn die Sonde alle aufgezeichneten Informationen zerst�rt ist, ist verloren. Wenn die Sonde in einem Sektor comtaining Planeten wird es versuchen, den Planeten regelm��ig scannen und Bericht zu erstatten Informationen gelegt.";
				$this->lss1 = "Current Sector: [destination_name] Last Ship Gesehen: [shiptype] Klasse Schiff.";
				$this->lss2 = "Current Sector: [destination_name] Last Ship Gesehen: Player [character_name] an Bord eines [shiptype] Klasse Schiff.";
			break;

			case "italian":
				$this->l_probe_type = "Sonda di avvistamento";
				$this->l_probe_description = "Sonde Sentry sono sonde stealth fermo. Al momento dell&#39;immissione in un settore in cui sedersi e aspettare che ogni nave ad entrare nel settore. E &#39;la scansione della nave e registra immediatamente le informazioni per riferimento futuro. Se la sonda viene distrutto tutte le informazioni registrate � perduto. Se la sonda viene posto in un settore comtaining pianeti si cercher� di eseguire la scansione dei pianeti su base regolare e riferire tutte le informazioni.";
				$this->lss1 = "Current Settore: [destination_name], Nave Ultimo Click: [shiptype] nave di classe.";
				$this->lss2 = "Current Settore: [destination_name], Nave Ultimo Click: Player [character_name] a bordo di un [shiptype] nave di classe.";
			break;

			case "spanish":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Las sondas Sentry son las sondas sigilo estacionaria. Cuando se coloca en un sector que sentarse y esperar a que un buque para entrar en el sector. Se analizar� el barco inmediatamente y registrar la informaci�n para referencia futura. Si la sonda se destruye toda la informaci�n registrada se ha perdido. Si la sonda se coloca en un sector comtaining planetas que tratar� de explorar los planetas en forma regular e informar cualquier informaci�n.";
				$this->lss1 = "Actual del sector: [destination_name], �ltimo barco Visto: [shiptype] barco de la clase.";
				$this->lss2 = "Actual del sector: [destination_name], �ltimo barco Visto: Player [character_name] a bordo de un buque [shiptype] clase.";
			break;

			case "albanian":
				$this->l_probe_type = "Roj� hetimin";
				$this->l_probe_description = "Roj� hetimet jan� hetimet stacionare vjedhurazi. Kur vendoset n� nj� sektor q� ulen dhe presin p�r �do anije p�r t� hyr� n� sektor. Ajo do t� scan anije dhe menj�her� rekord p�r referim n� t� ardhmen. N�se hetim �sht� shkat�rruar t� gjitha informatat t� regjistruara �sht� e humbur. N�se hetimi �sht� vendosur n� nj� sektor comtaining planetet do t� p�rpiqet t� scan planetet n� nj� baz� t� rregullt dhe t� raportojn� p�rs�ri ndonj� informacion.";
				$this->lss1 = "Sektori i tanish�m: [destination_name], Ship Last Seen: [shiptype] anije klas�s.";
				$this->lss2 = "Sektori i tanish�m: [destination_name], Ship Last Seen: Player [character_name] n� bordin e nj� [shiptype] anije klas�s.";
			break;

			case "catalan":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Les sondes Sentry s�n les sondes sigil estacion�ria. Quan es col loca en un sector que seure i esperar que un vaixell per entrar en el sector. S&#39;analitzar� el vaixell immediatament i registrar la informaci� per a refer�ncia futura. Si la sonda es destrueix tota la informaci� registrada s&#39;ha perdut. Si la sonda es col loca en un sector comtaining planetes que tractar� d&#39;explorar els planetes en forma regular i informar qualsevol informaci�.";
				$this->lss1 = "Actual del sector: [destination_name], el darrer vaixell Vist: [shiptype] vaixell de la classe.";
				$this->lss2 = "Actual del sector: [destination_name], el darrer vaixell Vist: Player [character_name] a bord d&#39;un vaixell [shiptype] classe.";
			break;

			case "danish":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sonder er station�r stealth-sonder. N�r den placeres i en sektor, de sidde og vente p� ethvert skib at komme ind i sektoren. Det vil skanne skibet og umiddelbart registrere de oplysninger til fremtidig brug. Hvis sonden er �delagt alle registrerede oplysninger g�r tabt. Hvis sonden er placeret i en sektor comtaining planeter vil fors�ge at scanne planeter regelm�ssigt og rapportere tilbage nogen oplysninger.";
				$this->lss1 = "Nuv�rende Sektor: [destination_name], Last Seen Ship: [shiptype] class skib.";
				$this->lss2 = "Nuv�rende Sektor: [destination_name], Last Seen Ship: Spiller [character_name] om bord p� et [shiptype] class skib.";
			break;

			case "dutch":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondes stilstaat stealth-sondes. Wanneer geplaatst in een sector zij zitten en wachten tot een schip aan de sector te betreden. Het scant het schip en direct opnemen van de informatie voor toekomstig gebruik. Als de sonde wordt alle opgeslagen informatie vernietigd verloren. Als de sonde wordt geplaatst in een sector comtaining planeten zal proberen om de planeten scannen op een regelmatige basis en verslag uit alle informatie.";
				$this->lss1 = "Huidige Sector: [destination_name], laatste schip Seen: [shiptype] klasse schip.";
				$this->lss2 = "Huidige Sector: [destination_name], laatste schip Seen: Player [character_name] aan boord van een [shiptype] klasse schip.";
			break;

			case "finnish":
				$this->l_probe_type = "Sentrylle Probe";
				$this->l_probe_description = "Sentry mittap��t ovat paikallaan varkain probes. Joutuessa alalla he istua ja odottaa, ett� kaikki alukset tulla alalle. Se skannaa aluksen ja v�litt�m�sti tallentaa tiedot my�hemp�� k�ytt�� varten. Jos anturi on tuhonnut kaikki tallennettu tieto on menetetty. Jos anturi on sijoitettu alan comtaining planeetat se yritt�� skannata planeetat s��nn�llisesti ja raportoi tiedot.";
				$this->lss1 = "Nykyinen Ala: [destination_name] Viimeisin Ship n�hty: [shiptype] luokan alus.";
				$this->lss2 = "Nykyinen Ala: [destination_name] Viimeisin Ship n�hty: Pelaaja [character_name] aluksella [shiptype] luokan alus.";
			break;

			case "indonesian":
				$this->l_probe_type = "Penjaga Probe";
				$this->l_probe_description = "Penjaga probe probe yang diam diam-diam. Ketika ditempatkan di sektor mereka duduk dan menunggu untuk setiap kapal untuk memasuki sektor. Ini akan memindai kapal dan segera merekam informasi untuk referensi di masa mendatang. Jika probe dicatat menghancurkan semua informasi yang hilang. Jika probe ditempatkan di sektor comtaining planet itu akan mencoba untuk memindai planet secara teratur dan melaporkan kembali informasi apapun.";
				$this->lss1 = "Current Sektor: [destination_name], Kapal Last Seen: [shiptype] kelas kapal.";
				$this->lss2 = "Current Sektor: [destination_name], Kapal Last Seen: Player [character_name] on board a [shiptype] kelas kapal.";
			break;

			case "norwegian":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry prober er stillest�ende stealth sonder. N�r plassert i en sektor de sitte og vente p� noen skip � g� inn i sektoren. Det vil skanne skipet og umiddelbart registrere informasjonen for fremtidig referanse. Hvis sonden er �delagt all registrert informasjon er tapt. Hvis sonden er plassert i en sektor comtaining planetene vil det pr�ve � skanne planetene p� regelmessig basis og rapportere tilbake noen informasjon.";
				$this->lss1 = "N�v�rende Sektor: [destination_name], Sist Ship Seen: [shiptype] klasse skip.";
				$this->lss2 = "N�v�rende Sektor: [destination_name], Sist Ship Seen: Player [character_name] ombord a [shiptype] klasse skip.";
			break;

			case "portuguese":
				$this->l_probe_type = "Sentry Probe";
				$this->l_probe_description = "Sentry sondas s�o sondas stealth estacion�ria. Quando colocado em um setor que sentar e esperar por qualquer navio a entrar no setor. Ele ir� varrer o navio e imediatamente registrar as informa��es para refer�ncia futura. Se a sonda for destru�do toda a informa��o gravada ser� perdida. Se a sonda � colocada em um setor comtaining planetas ele vai tentar fazer a varredura dos planetas em uma base regular e comunicar qualquer informa��o.";
				$this->lss1 = "Current Sector: [destination_name], Navio �ltima atividade: [shiptype] navio da classe.";
				$this->lss2 = "Current Sector: [destination_name], Navio �ltima atividade: Player [character_name] a bordo de um [shiptype].";
			break;

			case "swedish":
				$this->l_probe_type = "Vaktpost Probe";
				$this->l_probe_description = "Sentry sonder �r station�ra stealth sonder. N�r den placeras i en sektor de sitta och v�nta p� att alla fartyg att komma in i branschen. Det kommer att skanna fartyget och omedelbart registrera information f�r framtida referens. Om sonden �r f�rst�rt alla registrerade information g�r f�rlorad. Om sonden �r placerad i en sektor comtaining planeter man kommer att f�rs�ka att s�ka planeterna p� regelbunden basis och rapportera tillbaka all information.";
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