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
				$this->l_probe_description = "SG Sector Otsing juures on v�ga v�imas juures. Viska juures arvesse peasekret�ri sektor ja sond alustab automaatselt otsivad k�ik SG sektorite taga Gateway sektor ja j�ta kunagi m��gi alal. Ta j�lgib k�iki SG Sektorid ta on otsinud ja alati valis unsearched SG sektori sulatada leitud linke. See tagasi saata mis tahes teavet nagu Warp Probe p�hineb Sensor tase SG Otsing Probe. Kui sond on langenud arvesse sektori ilma sulatada link SG sektori see �mber arvestada Sentry Probe.";
			break;

			case "french":
				$this->l_probe_type = "SG Probe Recherche par secteur";
				$this->l_probe_description = "Une SG Recherche par secteur de la sonde est une sonde tr�s puissante. Vous d�posez la sonde dans le secteur SG et la sonde se lance automatiquement la recherche de tous les secteurs SG derri�re le secteur de la Porte et ne jamais quitter la zone de SG. Elle permet de conserver une trace de tous les Secteurs SG il a cherch� et toujours choisi un secteur fouill� SG de la cha�ne des liens trouv�s. Il renverra toute information, tout comme une sonde Warp bas� sur le niveau du capteur de la sonde Recherche SG. Si la sonde est plac�e dans un secteur sans lien de cha�ne � un secteur SG qu&#39;elle convertira en une sonde Sentry.";
			break;

			case "german":
				$this->l_probe_type = "SG Sector Suche Probe";
				$this->l_probe_description = "Ein SG Sector Suche Probe ist ein sehr leistungsf�higes Sonde. Du l�sst die Sonde in SG Sektor und die Sonde wird automatisch mit der Suche alle SG Sektoren hinter dem Gateway-Sektor und niemals die SG Gebiet zu verlassen. Es wird im Auge behalten alle SG Branche hat gesucht und w�hlte stets ein recherchierte SG Sektors aus dem Warp-Links gefunden. Es sendet keine Informationen zur�ck wie ein Warp-Sonde auf dem Sensor Level des Generalsekret�rs Suche auf Probe. Wenn die Sonde in einem Bereich ohne eine Kette Link auf eine SG-Sektor wird in eine Probe Sentry umwandeln lie�.";
			break;

			case "italian":
				$this->l_probe_type = "Sonda SG Settore Ricerca";
				$this->l_probe_description = "Un SG Settore Ricerca Probe � una sonda molto potente. Si elimina la sonda in SG Settore e la sonda si avvier� automaticamente una ricerca in tutti i settori SG dietro il Settore Gateway e non lasciare mai la zona SG. E non mancher� di tenere traccia di tutti i settori SG ha sempre cercato e scelto un settore unsearched SG dalla curvatura link trovati. Si provvede poi ad inviare tutte le informazioni proprio come una sonda Warp basata sul livello del sensore della sonda SG ricerca. Se la sonda � caduto in un settore senza un collegamento ordito ad un settore SG si convertir� in un Probe Sentry.";
			break;

			case "spanish":
				$this->l_probe_type = "Sonda SG sector de las b�squedas";
				$this->l_probe_description = "Un SG Buscar Sector Probe es una sonda muy poderosa. Se le cae la sonda en SG Sector y la sonda se iniciar� autom�ticamente la b�squeda de todos los sectores SG detr�s de la puerta de enlace del sector y que no deje el �rea de SG. Asimismo, mantendr� un registro de todos los sectores SG se ha buscado y siempre la opci�n de un sector de SG unsearched de la urdimbre se han encontrado v�nculos. Se enviar� de nuevo toda la informaci�n al igual que una sonda Warp basa en el nivel del sensor de la sonda SG b�squeda. Si la sonda se coloca en un sector sin un v�nculo de la urdimbre a un sector SG se convierte en una sonda Sentry.";
			break;

			case "albanian":
				$this->l_probe_type = "Hetim SG Sektori Search";
				$this->l_probe_description = "Nj� Sektori SG K�rko hetim �sht� nj� hetim shum� t� fuqishme. Ju r�nie hetim n� Sektorin SG dhe hetimi do t� filloj� automatikisht n� k�rkim t� gjith� sektor�t SG prapa Sektori Gateway dhe nuk largohen nga zona SG. Ajo do t� mbajn� gjurm�t e t� gjith� sektor�t SG ka kontrolluar dhe gjithmon� zgjodhi nj� sektor unsearched SG nga shtremb�rim lidhjet gjetur. Ai do t� d�rgoj� t� mb�shteste �do informacion vet�m si nj� hetim Warp bazuar mbi nivelin sensor i hetimin SG Search. N�se hetim �sht� r�n� n� nj� sektor pa nj� lidhje t� t�rheq me litar n� nj� sektor SG ajo do t� konvertohet n� nj� hetim rojtar.";
			break;

			case "catalan":
				$this->l_probe_type = "Sonda SG sector de les cerques";
				$this->l_probe_description = "Un SG Cerca Sector Probe �s una sonda molt poderosa. Se li cau la sonda en SG Sector i la sonda s&#39;iniciar� autom�ticament la recerca de tots els sectors SG darrere de la porta d&#39;enlla� del sector i que no deixi l&#39;�rea de SG. Aix� mateix, mantindr� un registre de tots els sectors SG s&#39;ha buscat i sempre l&#39;opci� d&#39;un sector de SG unsearched de l&#39;ordit s&#39;han trobat vincles. S&#39;enviar� de nou tota la informaci� igual que una sonda Warp basa en el nivell del sensor de la sonda SG cerca. Si la sonda es col loca en un sector sense un vincle de l&#39;ordit a un sector SG es converteix en una sonda Sentry.";
			break;

			case "danish":
				$this->l_probe_type = "SG Sector S�g Probe";
				$this->l_probe_description = "En SG Sector S�g Probe er en meget kraftfuld sonde. Du slipper sonden ind SG sektor og sonden vil automatisk begynde at s�ge alle de SG sektorer bag Gateway sektor og aldrig forlader SG omr�det. Det vil holde styr p� alle de SG Sektorer det har s�gt og altid valgt en unsearched SG sektor fra warp links fundet. Det vil sende tilbage oplysninger, ligesom en Warp Probe baseret p� Sensor niveau af SG S�g Probe. Hvis sonden er faldet i en sektor, uden en k�de link til en SG sektor, det vil konvertere til en Sentry Probe.";
			break;

			case "dutch":
				$this->l_probe_type = "SG Sector Search Probe";
				$this->l_probe_description = "Een SG Sector Zoeken Probe is een zeer krachtige sonde. U drop de sonde in SG sector en de sonde zal automatisch beginnen met zoeken alle sectoren van de SG achter de Gateway sector en nooit de SG gebied te verlaten. Het zal bijhouden van alle SG Sectoren heeft doorzocht en altijd gekozen voor een unsearched SG sector van de warp links gevonden. Het zal alle informatie terug te sturen, net als een Warp-Probe op basis van de sensor niveau van de SG Search Probe. Als de sonde is gevallen in een sector zonder een warp link naar een SG sector zal omzetten in een Sentry Probe.";
			break;

			case "finnish":
				$this->l_probe_type = "SG Sector Etsi Probe";
				$this->l_probe_description = "SG Ala Etsi Probe on eritt�in voimakas anturi. Pudotat mittap�� SG sektori ja koetin automaattisesti alkaa etsi� kaikki SG alojen takana Gateway-ala ja koskaan j�t� SG alueella. Se pit�� kirjaa kaikista SG Ala on etsinyt ja aina valitsi unsearched SG alaa loimi linkkej� l�ytynyt. Se palauttaa kaikki tiedot, kuten Warp Probe perustuu anturi taso korkeana Etsi Probe. Jos anturi on pudotettu alalle ilman taivuttaa linkki SG alan se muuntaa Sentry Probe.";
			break;

			case "indonesian":
				$this->l_probe_type = "SG Sektor Cari Probe";
				$this->l_probe_description = "Sebuah SG Sektor Cari Probe adalah pemeriksaan yang sangat kuat. Anda menjatuhkan SG Sektor penyelidikan dan probe akan secara otomatis mulai mencari semua sektor SG di belakang Gateway Sektor dan tidak pernah meninggalkan wilayah SG. Ini akan terus melacak semua Sektor SG telah mencari dan selalu memilih sebuah SG unsearched sektor dari link lungsin ditemukan. Akan mengirimkan kembali informasi apapun sama seperti Probe Warp berdasarkan Tingkat Sensor DC Pencarian Probe. Jika probe dijatuhkan ke dalam sektor tanpa warp link ke suatu sektor SG akan mengkonversi ke dalam Sentry Probe.";
			break;

			case "norwegian":
				$this->l_probe_type = "SG Sector S�k Probe";
				$this->l_probe_description = "Et SG Sector S�k Probe er en meget kraftig sonde. Du slipper sonde inn i SG sektor og sonden vil automatisk begynne � s�ke alle SG sektorene bak Gateway sektor og aldri forlate SG omr�det. Det vil holde oversikt over alle SG Sektorer har s�kte og alltid valgte en unsearched SG sektor fra warp koblinger. Det vil sende tilbake noen opplysninger som en Warp Probe basert p� Sensor Niv� av SG Search Probe. Hvis sonden er sluppet inn i en sektor uten en deformere lenke til en SG sektor vil konvertere til et Sentry Probe.";
			break;

			case "portuguese":
				$this->l_probe_type = "SG Probe Setor de Pesquisa";
				$this->l_probe_description = "Um SG Setor de Pesquisa Probe � um teste muito poderoso. Est� suspensa a sonda para SG Setor ea sonda ir� automaticamente come�ar a procurar todos os setores SG atr�s do Setor Gateway e nunca deixar a �rea SG. Ele ir� acompanhar todos os Sectores SG tem procurado e sempre escolhia um sector SG unsearched da urdidura links found. Ele ir� devolver qualquer informa��o apenas como uma sonda Warp baseado no sensor de n�vel da Sonda SG Pesquisa. Se o teste � deixado em um setor sem um link para uma urdidura sector SG ir� converter em uma sonda sentinela.";
			break;

			case "swedish":
				$this->l_probe_type = "SG Sector Search Probe";
				$this->l_probe_description = "En SG Sector Search Probe �r en mycket kraftfull sond. Du sl�pper sonden till SG Sektor och sonden kommer automatiskt att b�rja s�ka alla SG sektorer bakom Gateway sektorn och aldrig l�mnar SG omr�det. Det kommer att h�lla reda p� alla SG sektorer som har s�kt och alltid valde en unsearched SG sektor fr�n varp l�nkar hittades. Det kommer att skicka tillbaka all information precis som en Warp Probe baserat p� Sensor niv� av generalsekreteraren Search Probe. Om sonden hamnar i ett omr�de utan en varp l�nk till en SG sektor kommer att omvandlas till ett Sentry Probe.";
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