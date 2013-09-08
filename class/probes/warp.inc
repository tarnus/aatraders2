<?php
class warp {
	var $class = "warp";
	var $type = 2;
	var $l_probe_type;
	var $l_probe_target;
	var $l_probe_description;

	// fill language variables
	function warp()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Sihi sektor";
				$this->l_probe_description = "Warp Probe juhuslikult valige sulatada lingile ja hüpata järgmisele sektori otsin suunatud sektoris. Kui ta leiab soovitud sektoris see muutuda Sentry Probe. See skaneerida ja esitada teavet planeetide ja teiste mängijate ükskõik millises sektoris see läheb. Sond kasutab ka ühe omakorda üles sulatada liikuda. Kui teil on tähelepanu pöörete juures ei liigu. Kui sond siseneb ummiktee sektor, mis ei sisalda ühtegi sulatada lingid see muutuda Sentry Probe.";
				$this->lss1 = "Jooksev Valdkond: [destination_name] Viimane Laev vaadatuna: [shiptype] klassi laeva.";
				$this->lss2 = "Jooksev Valdkond: [destination_name] Viimane Laev vaadates: Mängija [character_name] pardal [shiptype] klassi laeva.";
			break;

			case "french":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Public Sector";
				$this->l_probe_description = "Une sonde Warp choisira au hasard un lien de chaîne et passer au prochain secteur à la recherche du secteur cible. Une fois qu&#39;il trouve le secteur de la cible, il se transforme en une sonde Sentry. Il va analyser et rapporter des informations sur les planètes et les autres acteurs dans n&#39;importe quel secteur il entre. La sonde utilisera aussi un tour de faire un pas de chaîne. Si vous êtes hors de tours de la sonde ne bouge pas. Si la sonde pénètre dans un secteur de l&#39;impasse qui ne contiennent pas de liens de chaîne il va se transformer en une sonde Sentry.";
				$this->lss1 = "Secteur actuel: [destination_name], Ship Dernière visite: [shiptype] navire de la classe.";
				$this->lss2 = "Secteur actuel: [destination_name], Ship Dernière visite: Player [character_name] à bord d&#39;un [shiptype] navire de la classe.";
			break;

			case "german":
				$this->l_probe_type = "Warp-Sonde";
				$this->l_probe_target = "Ziel-Sector";
				$this->l_probe_description = "Ein Warp-Probe wird nach dem Zufallsprinzip auszuwählen, deren Kette Link und Sprung zum nächsten Sektor der Suche nach dem Ziel-Sektor. Sobald er feststellt, die angesprochenen Verkehrskreise sie wird in eine Probe Sentry ändern. Es scannt und der Bericht Informationen über die Planeten und andere Spieler in jeder Branche, der sie betritt. Die Sonde wird auch ein wiederum zu einer Kette bewegen. Wenn Sie außer Haus sind sich die Sonde bewegt sich nicht. Wenn die Sonde in eine Sackgasse Sektor, die keine Kette enthält Links geht es in eine Sentry Probe zu machen.";
				$this->lss1 = "Current Sector: [destination_name] Last Ship Gesehen: [shiptype] Klasse Schiff.";
				$this->lss2 = "Current Sector: [destination_name] Last Ship Gesehen: Player [character_name] an Bord eines [shiptype] Klasse Schiff.";
			break;

			case "italian":
				$this->l_probe_type = "Sonda Warp";
				$this->l_probe_target = "Settore di destinazione";
				$this->l_probe_description = "Una sonda Warp verrà selezionato casualmente un link ordito e saltare al prossimo settore che cercano per il settore di destinazione. Una volta che si trova il settore di riferimento, si trasformerà in una sonda Sentry. Si esegue la scansione e trasmettere le informazioni sui pianeti e gli altri giocatori in qualsiasi settore in cui entra. La sonda sarà inoltre possibile utilizzare un turno per fare una mossa di curvatura. Se si è fuori di giri la sonda non si muove. Se la sonda entra in un settore vicolo cieco che non contiene alcuna curvatura link che si trasformerà in una sonda Sentry.";
				$this->lss1 = "Current Settore: [destination_name], Nave Ultimo Click: [shiptype] nave di classe.";
				$this->lss2 = "Current Settore: [destination_name], Nave Ultimo Click: Player [character_name] a bordo di un [shiptype] nave di classe.";
			break;

			case "spanish":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Objetivo del sector";
				$this->l_probe_description = "Una sonda Warp seleccionará al azar un vínculo de la urdimbre y saltar a la siguiente sector buscando el sector de destino. Una vez que encuentra el sector de la meta que se convertirá en una sonda Sentry. Este podrá analizar y reportar información acerca de los planetas y los otros jugadores en cualquier sector en el que entra. La sonda también utilizará un turno para hacer un movimiento de la urdimbre. Si se encuentra fuera de los turnos de la sonda no se moverá. Si la sonda entra en un sector del callejón sin salida que no contiene enlaces la urdimbre se convertirá en una sonda Sentry.";
				$this->lss1 = "Actual del sector: [destination_name], último barco Visto: [shiptype] barco de la clase.";
				$this->lss2 = "Actual del sector: [destination_name], último barco Visto: Player [character_name] a bordo de un buque [shiptype] clase.";
			break;

			case "albanian":
				$this->l_probe_type = "Warp hetimin";
				$this->l_probe_target = "Sektori i synuar";
				$this->l_probe_description = "Një hetim Warp rastësisht do të zgjidhni një lidhje të tërheq me litar dhe të kërcejnë në sektorin e ardhshëm kërkoj për sektorin e caktuar. Sapo gjen sektori objektiv ai do të ndryshojë në një hetim rojtar. Ajo do të scan dhe raportojnë informacion në lidhje me planetet dhe lojtarë të tjerë në çdo sektor të hyjë. Hetimi do të përdorë gjithashtu një të kthehet për të bërë një lëvizje prish. Nëse jeni të kthehet nga hetimi nuk do të lëvizë. Nëse hyn në një hetim sektori i vdekur në fund që nuk përmban asnjë shtrembërim lidhje ajo do të kthehet në një hetim rojtar.";
				$this->lss1 = "Sektori i tanishëm: [destination_name], Ship Last Seen: [shiptype] anije klasës.";
				$this->lss2 = "Sektori i tanishëm: [destination_name], Ship Last Seen: Player [character_name] në bordin e një [shiptype] anije klasës.";
			break;

			case "catalan":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Objectiu del sector";
				$this->l_probe_description = "Una sonda Warp seleccionarà a l&#39;atzar un vincle de l&#39;ordit i saltar a la següent sector buscant el sector de destinació. Una vegada que troba el sector de la meta que es convertirà en una sonda Sentry. Aquest podrà detectar i reportar informació sobre els planetes i els altres jugadors en qualsevol sector en què entra. La sonda també a un únic torn per fer un moviment de l&#39;ordit. Si es troba fora dels torns de la sonda no es mourà. Si la sonda entra en un sector del carreró sense sortida que no conté enllaços l&#39;ordit es convertirà en una sonda Sentry.";
				$this->lss1 = "Actual del sector: [destination_name], el darrer vaixell Vist: [shiptype] vaixell de la classe.";
				$this->lss2 = "Actual del sector: [destination_name], el darrer vaixell Vist: Player [character_name] a bord d&#39;un vaixell [shiptype] classe.";
			break;

			case "danish":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Target Sector";
				$this->l_probe_description = "En Warp Probe vil tilfældigt vælge en kæde link og gå til den næste sektor udkig efter målet sektor. Når den finder målet sektor, det vil ændre sig til et Sentry Probe. Det vil scanne og rapportere oplysninger om planeter og andre aktører inden for en sektor den kommer ind. Sonden skal også bruge en tur til at gøre en warp flytte. Hvis du er ude af forvandler sonden vil ikke flytte. Hvis sonden ind i en blindgyde sektor, der ikke indeholder nogen kæde links, som det bliver til en Sentry Probe.";
				$this->lss1 = "Nuværende Sektor: [destination_name], Last Seen Ship: [shiptype] class skib.";
				$this->lss2 = "Nuværende Sektor: [destination_name], Last Seen Ship: Spiller [character_name] om bord på et [shiptype] class skib.";
			break;

			case "dutch":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Doelgroep";
				$this->l_probe_description = "Een Warp Probe zal willekeurig selecteert u een warp link en spring naar de volgende sector op zoek naar de doelgroep. Zodra zij constateert de doelgroep zal veranderen in een Sentry Probe. Het zal scannen en de informatie over planeten en andere spelers in een sector die het binnenkomt. De sonde zal ook gebruik maken van een beurt om een warp bewegen. Als je uit de bocht de sonde zal niet bewegen. Als de sonde een doodlopende sector die bevat geen schering binnenkomt links zal veranderen in een Sentry Probe.";
				$this->lss1 = "Huidige Sector: [destination_name], laatste schip Seen: [shiptype] klasse schip.";
				$this->lss2 = "Huidige Sector: [destination_name], laatste schip Seen: Player [character_name] aan boord van een [shiptype] klasse schip.";
			break;

			case "finnish":
				$this->l_probe_type = "Warp silavakiikari";
				$this->l_probe_target = "Kohdealaksi";
				$this->l_probe_description = "Warp luotain valittava satunnaisesti loimi-linkkiä ja siirtyä seuraavaan alan etsimässä kohdealaksi. Kun se katsoo kohdealaksi se muuttuu Sentry Probe. Ohjelma aloittaa skannauksen ja tiedottamaan planeetat ja muiden toimijoiden millään alalla se tulee. Luotain käyttää myös yksi kierros, jotta loimi liikkua. Jos olet poissa kierrosta luotain ei liiku. Jos anturin tulee umpikujaan alaa, joka ei sisällä mitään taivuttaa Linkit se muuttuu Sentry Probe.";
				$this->lss1 = "Nykyinen Ala: [destination_name] Viimeisin Ship nähty: [shiptype] luokan alus.";
				$this->lss2 = "Nykyinen Ala: [destination_name] Viimeisin Ship nähty: Pelaaja [character_name] aluksella [shiptype] luokan alus.";
			break;

			case "indonesian":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Target Sektor";
				$this->l_probe_description = "Sebuah Warp Probe akan secara acak memilih link lungsin dan melompat ke sektor berikutnya mencari sektor sasaran. Setelah menemukan sektor target akan berubah menjadi Sentry Probe. Ini akan memindai dan melaporkan informasi tentang planet dan pemain lain dalam sektor apapun masuk. Penyidikan juga akan menggunakan satu putaran untuk membuat warp bergerak. Jika Anda berada di luar mengubah probe tidak akan bergerak. Jika probe memasuki sektor buntu yang tidak berisi link lungsin itu akan berubah menjadi Sentry Probe.";
				$this->lss1 = "Current Sektor: [destination_name], Kapal Last Seen: [shiptype] kelas kapal.";
				$this->lss2 = "Current Sektor: [destination_name], Kapal Last Seen: Player [character_name] on board a [shiptype] kelas kapal.";
			break;

			case "norwegian":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Target Sector";
				$this->l_probe_description = "En Warp Probe vil tilfeldig velge en deformere kobling og hoppe til neste sektor leter etter målet sektor. Når den finner målet sektor vil endre til en Sentry Probe. Det vil skanne og rapportere informasjon om planetene og andre spillere i en sektor det går inn. Sonden vil også bruke en tur å gjøre et varp trekk. Hvis du er ute av snur sonden vil ikke flytte. Dersom sonden går inn i en blindgate sektor som ikke inneholder noen varp koblinger vil det bli til en Sentry Probe.";
				$this->lss1 = "Nåværende Sektor: [destination_name], Sist Ship Seen: [shiptype] klasse skip.";
				$this->lss2 = "Nåværende Sektor: [destination_name], Sist Ship Seen: Player [character_name] ombord a [shiptype] klasse skip.";
			break;

			case "portuguese":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Objectivo do sector";
				$this->l_probe_description = "A Sonda Warp irá sortear um link warp e passar para o próximo setor procurando o setor de destino. Uma vez que se encontra o setor-alvo que irá se transformar em uma sonda sentinela. Ele irá verificar e relatar informações sobre os planetas e outros jogadores em qualquer sector da sua entrada. A sonda também vai usar uma vez para fazer um movimento dobra. Se você estiver fora de voltas a sonda não se move. Se a sonda entra em um beco sem saída do sector que não contém qualquer urdidura ligações que vai se transformar em uma sonda sentinela.";
				$this->lss1 = "Current Sector: [destination_name], Navio Última atividade: [shiptype] navio da classe.";
				$this->lss2 = "Current Sector: [destination_name], Navio Última atividade: Player [character_name] a bordo de um [shiptype].";
			break;

			case "swedish":
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Målsektor";
				$this->l_probe_description = "En Warp Probe kommer slumpmässigt välja en varp länk och hoppa till nästa sektor söker i målgruppen. När den finner i målgruppen det kommer att ändra till en Sentry Probe. Det kommer att skanna och rapportera information om planeter och andra aktörer inom någon sektor införseln. Sonden kommer också att använda en sväng för att göra en varp flytta. Om du är ute varv sonden kommer inte att flytta. Om sonden går in i en återvändsgränd sektor som inte innehåller några varp länkar det kommer att förvandlas till en Sentry Probe.";
				$this->lss1 = "Nuvarande Sector: [destination_name], Last Ship Seen: [shiptype] klass skepp.";
				$this->lss2 = "Nuvarande Sector: [destination_name], Last Ship Seen: Player [character_name] ombord a [shiptype] klass skepp.";
			break;

			default:
				$this->l_probe_type = "Warp Probe";
				$this->l_probe_target = "Target Sector";
				$this->l_probe_description = "A Warp Probe will randomly select a warp link and jump to the next sector looking for the target sector.  Once it finds the target sector it will change into a Sentry Probe.  It will scan and report information about planets and other players in any sector it enters. The probe will also use one turn to make a warp move. If you are out of turns the probe will not move. If the probe enters a dead end sector that doesn't contain any warp links it will turn into a Sentry Probe.";
				$this->lss1 = "Current Sector: [destination_name], Last Ship Seen: [shiptype] class ship.";
				$this->lss2 = "Current Sector: [destination_name], Last Ship Seen: Player [character_name] on board a [shiptype] class ship.";
			break;
		}
	}

	var $tag = "LOG5_PROBE_WARP";

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
		$orders_array[] = "warp_target_sector = ;	text  ; ; " . $this->l_probe_target;
		return $orders_array;
	}

	function probe_finishorders_code()
	{
		global $db, $db_prefix, $warp_target_sector, $template_object, $l_global_mmenu, $templatename, $title, $sectorinfo;
		global $probeclass, $title, $new_type, $l_probe_forbidSG, $l_probe_forbidFED, $l_probe_forbidINVALID, $probe_id;

		$warp_target_sector = $_POST['warp_target_sector'];

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

		if(empty($warp_target_sector))
		{
			$warp_target_sector = "";
		}

		$resx = $db->SelectLimit("SELECT sector_id, zone_id, sg_sector, galaxy_id from {$db_prefix}universe WHERE sector_name =" . $db->qstr($warp_target_sector), 1);
		db_op_result($resx,__LINE__,__FILE__);
		if($resx->RecordCount() > 0)
		{
			$sector_id = $resx->fields['sector_id'];
		}
		else
		{
			$sector_id = 0;
		}

		if(($resx->fields['galaxy_id'] != $sectorinfo['galaxy_id'] || empty($sector_id) || $sector_id == 0 || $resx->fields['zone_id'] == 2 || ($resx->fields['sg_sector'] != 0 && $new_type == 3)) && $new_type != 0)
		{
			include ("header.php");
			$template_object->assign("title", $title);
			if($resx->fields['sg_sector'] != 0 && $new_type == 3)
			{
				$template_object->assign("error_msg", $l_probe_forbidSG);
			}
			if($resx->fields['zone_id'] == 2 || $resx->fields['zone_id'] == 3)
			{
				$template_object->assign("error_msg", $l_probe_forbidFED);
			}
			else
			{
				$template_object->assign("error_msg", $l_probe_forbidINVALID);
			}
			$sector_id = 1;
			$new_type = 0;

			$debug_query = $db->Execute("UPDATE {$db_prefix}probe SET class='$probeclass[$new_type]', type=$new_type, target_sector=$sector_id, data='' WHERE probe_id=$probe_id");
			db_op_result($debug_query,__LINE__,__FILE__);

			$template_object->assign("gotomain", $l_global_mmenu);
			$template_object->display("master_template/genericdie.tpl");
			include ("footer.php");
			die();
		}
		else
		{
			if(!empty($sector_id))
			{
				$debug_query = $db->Execute("UPDATE {$db_prefix}probe SET class='$probeclass[$new_type]', type=$new_type, target_sector=$sector_id, data='' WHERE probe_id=$probe_id");
				db_op_result($debug_query,__LINE__,__FILE__);
			}

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

	function probe_scheduler_code($probeinfo)
	{
		global $db, $db_prefix, $level_factor;

		if($probeinfo['sector_id'] == $probeinfo['target_sector'])
		{
			$result = $db->Execute("UPDATE {$db_prefix}probe SET type=0, class='sentry' WHERE probe_id=$probeinfo[probe_id]");
			db_op_result($result,__LINE__,__FILE__);
			return;
		}

		$targetlink = 0;
		$linkres = $db->Execute ("SELECT link_dest FROM {$db_prefix}links WHERE link_start='$probeinfo[sector_id]'");
		db_op_result($linkres,__LINE__,__FILE__);

		if($linkres->RecordCount() == 0)
		{
			$result = $db->Execute("UPDATE {$db_prefix}probe SET type=0, class='sentry' WHERE probe_id=$probeinfo[probe_id]");
			db_op_result($result,__LINE__,__FILE__);
			return;
		}

		while (!$linkres->EOF)
		{
			if(( mt_rand(1,1000) <= 500 && $targetlink == 0) || $linkres->fields['link_dest'] == $probeinfo['target_sector'])
			{
				$targetlink = $linkres->fields['link_dest'];
			}
			$linkres->MoveNext();
		}

		if($targetlink > 0)
		{
			$sectres = $db->Execute ("SELECT zone_id FROM {$db_prefix}universe WHERE sector_id='$targetlink'");
			if ($sectres->fields['zone_id'] == 2)
			{
				$targetlink = 0;
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