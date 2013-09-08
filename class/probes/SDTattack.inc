<?php
class SDTattack {
	var $class = "SDTattack";
	var $type = 70;
	var $l_probe_type;
	var $l_probe_target;
	var $l_probe_description;

	// fill language variables
	function SDTattack()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Valdkond Defense Tech Attack Probe";
				$this->l_probe_description = "Valdkond Defense Tech Attack Probe on üks võimsamaid sondid loodud vähendada sektori kaitseministeeriumi võimet ühtegi sektorit. Vabasta see sond väljaspool sektori soovid on vähenenud keinojasi ja suunata see kaasa selles sektoris. Sond on sulatada arvesse sektori skaneerida iga planeedi leida planeedi kõrgeima Sector Defense Tech taseme ja eesmärgi ta. Sond hakkab varastada energiat iga planeedi sektoris. Seda kasutatakse energiat suurendada sondid varjatud tehniline tase. Kui sond arvab oma varjatud tehniline tase on kõrge ehough vahelejätmise poolt suunatud planeedid andurid see rünnak. Teil tuleb määrata sondid andurid piisavalt kõrge, et täpselt skaneerida planeete. Kui andurid on liiga madal sondi võivad rünnata enne varjatud Tech on piisavalt suur, et minna mööda planeete andurid. Teil tuleb määrata sondid varjatud tech piisavalt kõrge, et takistada selle avastada, kui ta hakkab varastada energiat. Kui sond möödasõidu planeedid andurid see rünnak planeedid Sector Defense Tech tasemete vähendamise tõhususe sektori keinojasi.";
			break;

			case "french":
				$this->l_probe_type = "Secteur de la défense Tech Attack Probe";
				$this->l_probe_description = "Le secteur de la défense Tech Attack Probe est l&#39;une des sondes les plus puissant créé pour réduire les capacités de défense du secteur de n&#39;importe quel secteur. Drop cette sonde en dehors du secteur que vous aimeriez avoir réduit les défenses et les cibler sur ce secteur. La sonde de chaîne dans le secteur, de numériser toutes les planètes, de trouver la planète avec les plus hauts niveaux du secteur des technologies de défense et de les cibler. La sonde va commencer à voler l&#39;énergie de chaque planète dans le secteur. Cette énergie est utilisée pour augmenter les sondes Cloak niveau Tech. Une fois la sonde pense son manteau niveau de technologie est élevé ehough pour être ignoré par les capteurs planètes ciblée, il va attaquer. Vous aurez besoin de mettre les capteurs sondes suffisamment élevée pour analyser avec précision les planètes. Si les capteurs sont trop faibles, la sonde de mai avant d&#39;attaquer le Tech manteau est suffisamment élevé afin de contourner les capteurs planètes. Vous aurez besoin de fixer le manteau de sondes de haute technologie suffisante pour l&#39;empêcher d&#39;être détecté lors de son démarrage voler l&#39;énergie. Si la sonde court-circuite les capteurs planètes elle attaquera les planètes secteur de la défense Tech réduire le degré de l&#39;efficacité des défenses secteur.";
			break;

			case "german":
				$this->l_probe_type = "Sector Defense Tech Attack Probe";
				$this->l_probe_description = "Der Sektor Defense Tech Attack Probe ist einer der mächtigsten Sonden zur Verringerung der Sektor Verteidigungsfähigkeit eines Sektors geschaffen. Drop dieser Sonde außerhalb des Sektors möchten Verteidigung verringert haben und Ziel auf diesem Sektor. Die Sonde wird in den Sektor Kette, Scannen jeder Planet, der Suche nach den Planeten mit der höchsten Sector Defense Tech Ebenen und sie nur. Die Sonde beginnt zu stehlen Energie aus jeder Planet in der Branche. Diese Energie wird benutzt, um die Sonden zu erhöhen Umhang Tech Ebene. Sobald die Sonde hält seine Umhang Tech ist hoch ehough durch die gezielte Planeten Sensoren wird es Angriff ignoriert werden. Sie müssen die Sonden-Sensoren hoch genug, um genau die Planeten Scan eingestellt ist. Wenn die Sensoren zu niedrig sind, kann die Sonde vor dem Umhang Tech Angriff ist hoch genug, um die Planeten-Sensoren zu umgehen. Sie müssen die Sonden gesetzt Mantel Tech hoch genug, um es aus entdeckt zu werden, wenn es gestohlen Energie beginnt zu verhindern. Wenn die Sonde den Planeten umgeht Sensoren wird die Planeten Sector Defense Tech Stufen verringert die Wirksamkeit des Sektors Verteidigung anzugreifen.";
			break;

			case "italian":
				$this->l_probe_type = "Settore Difesa Tech Attack Probe";
				$this->l_probe_description = "Il Settore Difesa Tech Attack Probe è una delle sonde più potente creato per ridurre le capacità di difesa del settore di qualsiasi settore. Drop questa sonda al di fuori del settore che si desidera avere ridotto le difese e di destinazione verso questo settore. La sonda sarà ordito nel settore, la scansione di ogni pianeta, trovare il pianeta con il più alto Settore Difesa livelli Tech e targeting. La sonda inizierà rubare energia da tutti i pianeti del settore. Questa energia è utilizzata per aumentare il livello di sonde Cloak Tech. Una volta che la sonda pensa il suo manto livello tecnico è alto ehough di essere ignorato dal mirati pianeti sensori sarà attacco. Sarà necessario impostare i sensori sonde ad alta precisione sufficiente per eseguire la scansione dei pianeti. Se i sensori sono troppo bassi della sonda possono attaccare prima che il Tech mantello è abbastanza alto per bypassare i sensori pianeti. Sarà necessario impostare il mantello di sonde ad alta tecnologia sufficiente per impedire che venga rilevato quando si avvia il furto di energia. Se la sonda bypassa i sensori pianeti si attaccano i pianeti Settore Difesa Tech Livelli di ridurre l&#39;efficacia delle difese del settore.";
			break;

			case "spanish":
				$this->l_probe_type = "Sector Defensa Tech Attack Probe";
				$this->l_probe_description = "El sector de tecnología de Defensa Ataque Probe es una de las sondas más potente creado para la reducción de las capacidades de defensa del sector de cualquier sector. Caída de este sondeo fuera del sector que le gustaría tener defensas reducida y de dirigirla hacia ese sector. La sonda de la urdimbre en el sector, escanear todos los planetas, encontrar el planeta con los más altos niveles del Sector de Tecnología de Defensa y de dirigirla. La investigación se iniciará el robo de energía de cada planeta en el sector. Esta energía se utiliza para aumentar el nivel de las sondas de Capa Tech. Una vez que la sonda piensa que su manto de alto nivel de tecnología es ehough a ser ignorado por los sensores orientados planetas se ataque. Usted tendrá que configurar los sensores de las sondas de alta precisión suficiente para explorar los planetas. Si los sensores son demasiado bajos de la sonda puede atacar antes de que la tecnología capa es suficientemente alto como para evitar los sensores de los planetas. Usted tendrá que establecer la capa de sondas de alta tecnología suficiente como para evitar que se detecta cuando se inicia el robo de energía. Si la sonda pasa por alto los sensores de los planetas que atacará los planetas Sector Defensa Tech reducción de los niveles de la eficacia de las defensas del sector.";
			break;

			case "albanian":
				$this->l_probe_type = "Sektori i Mbrojtjes Teknike Sulmi hetimin";
				$this->l_probe_description = "Mbrojtjes, Sektori Teknike Sulmi hetim është një nga hetimet më të fuqishme krijuar për uljen e aftësive të sektorit të mbrojtjes të çdo sektori. Drop këtë hetim jashtë sektorit ju do të donit të kishit mbrojtëse të reduktuara dhe të synojë drejt se ajo e sektorit. Hetimi do të tërheq me litar në sektor, skanim çdo planetit, gjeni planetit me nivelet më të larta Teknike Sektorit të Mbrojtjes dhe të synojë atë. Hetimi do të fillojë duke vjedhur energji nga çdo planet në sektor. Kjo energji është përdorur për të rritur nivelin hetimet mantelin Teknike. Pasi hetimi mendon nivel mantel saj është e lartë Teknike ehough të injoruar nga sensorë planetet në shënjestër ai do të sulmojë. Ju do të duhet për të vendosur sensorë hetimet e lartë të mjaftueshme për të saktë scan planetet. Nëse sensore janë shumë të ulëta hetim mund sulm para Teknike mantelin është e lartë, të mjaftueshme për të anashkalojë sensorë planetet. Ju do të duhet për të vendosur hetimet mantelin e teknologjisë së lartë të mjaftueshme për të parandaluar atë nga të qenit zbuluar kur ajo fillon vjedhje të energjisë. Nëse hetimi anashkalon sensorë planetet se planetet do të sulmojë Teknike Sektorit të Mbrojtjes Nivelet zvogëluar efikasitetin e sektorit mbrojtëse.";
			break;

			case "catalan":
				$this->l_probe_type = "Sector Defensa Tech Attack Probe";
				$this->l_probe_description = "El sector de tecnologia de Defensa Atac Probe és una de les sondes més potent creat per a la reducció de les capacitats de defensa del sector de qualsevol sector. Caiguda d&#39;aquest sondeig fora del sector que li agradaria tenir defenses reduïda i de dirigir-la cap a aquest sector. La sonda de l&#39;ordit en el sector, escanejar tots els planetes, trobar el planeta amb els més alts nivells del sector de Tecnologia de Defensa i de dirigir-la. La recerca s&#39;iniciarà el robatori d&#39;energia de cada planeta en el sector. Aquesta energia s&#39;utilitza per augmentar el nivell de les sondes de Capa Tech Una vegada que la sonda pensa que el seu mantell d&#39;alt nivell de tecnologia és ehough a ser ignorat pels sensors orientats planetes es atac. Vostè haurà de configurar els sensors de les sondes d&#39;alta precisió suficient per explorar els planetes. Si els sensors són massa baixos de la sonda pot atacar abans que la tecnologia capa és suficientment alt com per evitar els sensors dels planetes. Vostè haurà d&#39;establir la capa de sondes d&#39;alta tecnologia suficient com per evitar que es detecta quan s&#39;inicia el robatori d&#39;energia. Si la sonda passa per alt els sensors dels planetes que atacarà els planetes Sector Defensa Tech reducció dels nivells de l&#39;eficàcia de les defenses del sector.";
			break;

			case "danish":
				$this->l_probe_type = "Sektor Defense Tech Attack Probe";
				$this->l_probe_description = "Sektoraftalen Defense Tech Attack Probe er en af de mest magtfulde sonder skabt for at reducere sektorens forsvar kapaciteter af enhver sektor. Drop denne sonde uden for sektoren, du gerne vil have nedsat immunforsvar og målrette den mod denne sektor. Sonden vil kæde ind i sektoren, scanne hver planet, finde planeten med det højeste Sektor Defense Tech niveauer og målrette det. Sonden vil begynde at stjæle energi fra hver planet i sektoren. Denne energi bruges til at øge sonder Cloak Tech niveau. Når sonden mener dens Cloak Tech er højt ehough at blive ignoreret af målrettede planeter sensorer det vil angribe. Du bliver nødt til at indstille sonder sensorer høj nok til præcist at scanne planeterne. Hvis sensorerne er for lav sonden kan angribe før Cloak Tech er høj nok til at omgå den planeter sensorer. Du bliver nødt til at indstille sonder kappen tech høj nok til at forhindre det i at blive opdaget, når det begynder at stjæle energi. Hvis sonden omfartsveje planeterne sensorer det vil angribe planeterne Sektor Defense Tech Niveauer mindske effektiviteten af sektoren forsvarsværker.";
			break;

			case "dutch":
				$this->l_probe_type = "Sector Defense Tech Attack Probe";
				$this->l_probe_description = "De sector Defense Tech Attack Probe is een van de meest krachtige sondes gemaakt voor het verminderen van de sector defensie capaciteiten van elke sector. Drop deze sonde buiten de sector die u wilt verminderde afweer hebben en het doel de richting van die sector. De sonde zal ketting in de sector, scannen elke planeet, vinden de planeet met de hoogste Sector Defense Tech niveaus en hem te richten. De sonde zal beginnen met het stelen van energie uit elke planeet in de sector. Deze energie wordt gebruikt om de verhoging sondes Cloak Tech niveau. Zodra de sonde denkt haar Cloak Tech niveau is hoog ehough worden genegeerd door de gerichte planeten sensoren zal aanvallen. U moet om de sondes sensoren hoog genoeg om nauwkeurig de planeten scannen. Als de sensoren zijn te laag van de sonde kan aanvallen voordat de Cloak Tech is hoog genoeg om de planeten sensoren omzeilen. U moet om de sondes mantel tech hoog genoeg is om te voorkomen dat het wordt ontdekt wanneer het begint te stelen energie. Als de sonde passeert de planeten sensoren zal de aanval van de planeten Sector Defense Tech Levels vermindering van de effectiviteit van de sector defensie.";
			break;

			case "finnish":
				$this->l_probe_type = "Alan Defense Tech Attack Probe";
				$this->l_probe_description = "Ala Defense Tech Attack Probe on yksi tehokkaimmista antureista luotu vähentää alan puolustusvoimavarojen tahansa alalla. Pudota tämä koetin ulkopuolella alan haluaisit saada alennettua puolustuksemme ja kohdentamaan tukea tällä alalla. Luotain taivuttaa alalle, skannata jokainen planeetta, löytää maapallon suurin sektorin Defense Tech tasoa ja kohdistaa sen. Koetin alkaa varastaa energiaa jokaista maapallon alalla. Tämä energia käytetään lisäämään antureista Viitta Tech tasolla. Kun koetin arvelee Viitta tekninen taso on korkea ehough välittävän kohteena planeetat anturit se hyökkäys. Sinun tulee asettaa antureista anturit riittävän korkea tarkasti skannata planeettoja. Jos anturit ovat liian alhaiset kohdalla voi hyökätä ennen viitta Tech on tarpeeksi korkea ohittaa planeettoja anturit. Sinun tulee asettaa antureista piilo tech riittävän korkea estämään se havaitaan, kun se alkaa varastaa energiaa. Jos luotain ohittaa planeetan anturit se hyökkäys planeetat Ala Defense Tech tasot vähentää tehokkuutta alan puolustuksemme.";
			break;

			case "indonesian":
				$this->l_probe_type = "Sektor Pertahanan Tech Attack Probe";
				$this->l_probe_description = "Sektor Pertahanan Tek Attack Probe adalah salah satu probe yang paling kuat yang diciptakan untuk mengurangi kemampuan pertahanan sektor setiap sektor. Drop probe ini di luar sektor yang ingin Anda telah mengurangi pertahanan dan target itu terhadap sektor tersebut. Penyidikan akan warp ke dalam sektor, scan setiap planet, menemukan planet dengan tertinggi tingkat Tek Sektor Pertahanan dan target itu. Penyidikan akan mulai mencuri energi dari setiap planet di sektor ini. Energi ini digunakan untuk meningkatkan tingkat Tech Jubah probe. Setelah penyelidikan yang Jubah Tek berpikir tingkat ehough tinggi untuk diabaikan oleh sensor planet yang ditargetkan akan menyerang. Anda akan perlu untuk mengatur sensor probe cukup tinggi secara akurat memindai planet. Jika terlalu rendah sensor probe dapat menyerang sebelum Tech Jubah cukup tinggi untuk melewati sensor planet. Anda akan perlu untuk mengatur jubah probe tech cukup tinggi untuk mencegah terdeteksi ketika mulai mencuri energi. Jika probe sensor bypasses planet itu akan menyerang planet Tek Sektor Pertahanan Tingkat mengurangi efektivitas dari sektor pertahanan.";
			break;

			case "norwegian":
				$this->l_probe_type = "Sector Defense Tech Attack Probe";
				$this->l_probe_description = "Sektoren Defense Tech Attack Probe er en av de mektigste sonder som er opprettet for å redusere sektor forsvarsevne noen sektor. Drop dette sonde utenfor sektoren du vil ha redusert forsvar og målrette den mot at sektoren. Sonden vil bli lokket inn i sektoren, skanne hver planet, finne planeten med høyest Sector Defense Tech nivåer og mål den. Sonden vil starte stjeler energi fra hver planet i sektoren. Denne energien brukes til å øke sonder Cloak Tech nivå. Når sonden tenker sin kappe Tech nivået er høyt ehough å bli ignorert av målrettet planetene sensorene vil den angripe. Du må sette sonder sensorene høy nok til nøyaktig skanne planetene. Dersom sensorene er for lave sonden kan angripe før Cloak Tech er høy nok til å omgå planetene sensorer. Du må sette sonder kappen tech høyt nok til å hindre den fra å bli oppdaget når det begynner å stjele energi. Dersom sonden forbigår planetene sensorene vil angripe planetene Sector Defense Tech Levels redusere effektiviteten i sektoren forsvar.";
			break;

			case "portuguese":
				$this->l_probe_type = "Setor de Defesa Tech Attack Probe";
				$this->l_probe_description = "O Setor de Defesa Tech Attack Probe é uma das sondas mais poderoso criado para reduzir as capacidades do sector de defesa de qualquer setor. Drop esta sonda fora do setor que você gostaria de ter defesas reduzidas e destiná-las para esse setor. A sonda irá deformar para o setor, a varredura de cada planeta, localizar o planeta, com níveis mais elevados do Setor de Defesa Tech e destiná-las. A sonda vai começar a roubar energia de cada planeta no setor. Essa energia é utilizada para aumentar as sondas Cloak nível de tecnologia. Uma vez que a sonda acha que seu manto de nível técnico é alto ehough a ser ignorado pelos sensores direcionados planetas que vai atacar. Você precisará configurar os sensores de sondas de alta precisão suficiente para digitalizar os planetas. Se os sensores são muito baixos a sonda pode atacar antes do Tech Manto é alta o suficiente para ultrapassar os sensores de planetas. Você precisará configurar o manto sondas de alta tecnologia suficiente para impedir que ele seja detectado quando ele começa a roubar energia. Se a sonda ignora os sensores de planetas que irá atacar os planetas Setor de Defesa Tech Níveis de reduzir a eficácia das defesas do setor.";
			break;

			case "swedish":
				$this->l_probe_type = "Sector Defense Tech Attack Probe";
				$this->l_probe_description = "Sektorsöverenskommelsen Defense Tech Attack Probe är en av de mest kraftfulla sonder som skapats för att minska kapaciteten inom försvaret i någon sektor. Drop denna sond utanför sektorn du vill ha reducerat försvar och rikta den mot denna sektor. Sonden kommer varp i sektorn, scanna varje planet, hitta planeten med den högsta Sector Defense Tech nivåer och inrikta det. Sonden kommer att börja stjäla energi från varje planet inom sektorn. Denna energi används för att öka sonder manteln Tech nivå. När sonden tror att dess Cloak Tech är hög ehough att ignoreras av riktade planeterna sensorerna det kommer att attackera. Du måste ställa in sonder sensorer tillräckligt hög för att noggrant skanna planeterna. Om sensorerna är för lågt sonden kan anfalla innan manteln Tech är tillräckligt hög för att kringgå planeterna sensorer. Du måste ställa in sonder kappan tech tillräckligt högt för att förhindra den från att bli upptäckt när det börjar stjäl energi. Om sonden förbi planeterna sensorerna det kommer att angripa planeterna Sector Defense Tech Nivåer minskar effektiviteten i sektorn försvar.";
			break;

			default:
				$this->l_probe_type = "Sector Defense Tech Attack Probe";
				$this->l_probe_description = "The Sector Defense Tech Attack Probe is one of the most powerful probes created for reducing sector defense capabilities of any sector.  Drop this probe outside the sector you would like to have reduced defenses and target it towards that sector.  The probe will warp into the sector, scan every planet, find the planet with the highest Sector Defense Tech levels and target it.  The probe will start stealing energy from every planet in the sector.  This energy is used to increase the probes Cloak Tech level.  Once the probe thinks its Cloak Tech level is high ehough to be ignored by the targeted planets sensors it will attack.  You will need to set the probes sensors high enough to accurately scan the planets.  If the sensors are too low the probe may attack before the Cloak Tech is high enough to bypass the planets sensors.  You will need to set the probes cloak tech high enough to prevent it from being detected when it starts stealing energy.  If the probe bypasses the planets sensors it will attack the planets Sector Defense Tech Levels reducing the effectiveness of the sector defenses.";
			break;
		}
	}

	var $tag = "LOG5_PROBE_SDTATTACK";

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