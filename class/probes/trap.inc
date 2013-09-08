<?php
class trap {
	var $class = "trap";
	var $type = 4;
	var $l_probe_type;
	var $probe_cost = 1000000;
	var $l_probe_target;
	var $l_probe_shipclass;
	var $l_probe_description;
	var $l_probe_info;
	var $l_probe_imtitle;
	var $l_probe_imbody;

	// fill language variables
	function trap()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Suunatud Player";
				$this->l_probe_shipclass = "Laev klassi TARGETiga";
				$this->l_probe_description = "Probe Hind: " . $this->probe_cost . "<br><br> Sentry Trap Probes eesmärk on oodata konkreetse vaenlase laeval siseneda sektori ja rünnaku ta. Võite valida mängija ning laeva klassi soovite sond rünnak. Kui suunatud mängija sisestage sektor, kus juures on ootel ja need on valitud laeva klassi see plahvatama nagu sektori rakett. Ainus erinevus Sentry lõksust ja drenaa?i Sector rakettide on suunatud laeva ei saa vältida rünnak.";
				$this->l_probe_info = "Target: [target] <br> Laeva klass: [class]";
				$this->l_probe_imtitle = "Laev rünnaku all";
				$this->l_probe_imbody = "Sentry Trap Probe omanduses [playername] ründab oma laeva!";
			break;

			case "french":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Ciblées Player";
				$this->l_probe_shipclass = "Navire de la classe à Target";
				$this->l_probe_description = "Probe Coût: " . $this->probe_cost . "<br><br> Sentry Probes Trap sont conçus pour attendre un navire ennemi précis d&#39;entrer dans un secteur et l&#39;attaquer. Vous pouvez sélectionner le joueur et le navire de la classe que vous voulez la sonde à l&#39;attaque. Si le joueur ciblé entrer dans le secteur où la sonde est en attente et ils sont choisis dans la classe du navire avec lequel il fera exploser comme un missile de secteur. La seule différence entre une sonde Trap Sentry et d&#39;un missile du secteur est le navire ciblés peuvent pas se soustraire à l&#39;attaque.";
				$this->l_probe_info = "Target: [target] <br> Navire de la classe: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Une sentinelle Trap Probe détenue par [playername] est d&#39;attaquer votre bateau!";
			break;

			case "german":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Gezielte Player";
				$this->l_probe_shipclass = "Schiffsklasse an Target";
				$this->l_probe_description = "Probe Kosten: " . $this->probe_cost . "<br><br> Sentry Trap Sonden sind so konzipiert, für eine bestimmte gegnerische Schiff warten, um einen Bereich geben, und es anzugreifen. Sie können die Spieler und das Schiff Klasse, die Sie wollen, dass die Sonde zum Angriff. Wenn der anvisierte Spieler geben Sie den Bereich, in dem die Sonde wartet, und sie sind in der gewählten Schiffsklasse wird es wie ein Sektor Raketen zünden. Der einzige Unterschied zwischen einem Sentry Trap Probe und ein Sektor Missile ist die gezielte Schiff nicht entziehen kann den Angriff.";
				$this->l_probe_info = "Target: [target] <br> Schiffsklasse: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Eine Sentry Trap Probe im Besitz von [playername] greift Ihr Schiff!";
			break;

			case "italian":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Mirati Player";
				$this->l_probe_shipclass = "Nave di classe a Target";
				$this->l_probe_description = "Sonda Costo: " . $this->probe_cost . "<br><br> Sentry Sonde Trap sono progettati per aspettare per una determinata nave nemica di entrare in un settore e attaccarlo. È possibile selezionare il giocatore e la classe della nave che si desidera la sonda ad attaccare. Se il giocatore con targeting per entrare nel settore in cui la sonda è in attesa e sono in nave selezionata classe sarà esplodere come un missile settore. L&#39;unica differenza tra una sentinella Trap Probe e un missile settore è la nave mirata non può sottrarsi all&#39;attacco.";
				$this->l_probe_info = "Target: [target] <br> Nave di classe: [class]";
				$this->l_probe_imtitle = "Nave Under Attack";
				$this->l_probe_imbody = "Una sonda Sentry Trap di proprietà di [playername] sta attaccando la vostra nave!";
			break;

			case "spanish":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Dirigida Player";
				$this->l_probe_shipclass = "Barco de la clase a Target";
				$this->l_probe_description = "Costo de la sonda: " . $this->probe_cost . "<br><br> Sentry Trap sondas están diseñadas para esperar a que un buque enemigo específico para entrar en un sector y atacarlo. Usted puede seleccionar el jugador y la clase del buque que desee de la sonda al ataque. Si el jugador objetivo entrar en el sector en el que la sonda está esperando y que están en el barco seleccionado clase que detonará como un misil sector. La única diferencia entre una sonda Trap Sentry y un misil Sector es el barco blanco no puede eludir el ataque.";
				$this->l_probe_info = "Objetivo: [target] <br> Barco de la clase: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Una sonda Sentry Trap propiedad de [playername] está atacando su nave!";
			break;

			case "albanian":
				$this->l_probe_type = "Rojë Trap hetimin";
				$this->l_probe_target = "Synuar Player";
				$this->l_probe_shipclass = "Klasa anije për të synuar";
				$this->l_probe_description = "Kosto hetimin: " . $this->probe_cost . "<br><br> Rojë kurth heton janë projektuar për të pritur për një anije specifike armik për të hyrë në një sektor dhe sulmuar atë. Ju mund të zgjidhni lojtar dhe klasës anije doni hetim për sulmin. Nëse lojtari synuar të hyjë sektori ku hetim është duke pritur dhe ata janë në anije zgjedhur klasë se do të shpërthente si një raketë sektor. I vetmi ndryshim midis një hetim kurth rojë dhe një raketave Sektori është anija synuar NUK MUND t&#39;i shmanget sulmit.";
				$this->l_probe_info = "Synimi: [target] <br> Anije Klasa: [class]";
				$this->l_probe_imtitle = "Anije Sipas Attack";
				$this->l_probe_imbody = "Një hetim kurth rojë në pronësi nga [playername] është sulmuar anijen tuaj!";
			break;

			case "catalan":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Dirigida Player";
				$this->l_probe_shipclass = "Vaixell de la classe a Target";
				$this->l_probe_description = "Cost de la sonda: " . $this->probe_cost . "<br><br> Sentry Trap sondes estan dissenyades per esperar que un vaixell enemic específic per entrar en un sector i atacar-lo. Vostè pot seleccionar el jugador i la classe del vaixell que desitgi de la sonda a l&#39;atac. Si el jugador objectiu entrar al sector en què la sonda està esperant i que estan al vaixell seleccionat classe que detonar com un míssil sector. L&#39;única diferència entre una sonda Trap Sentry i un míssil Sector és el vaixell blanc no pot eludir l&#39;atac.";
				$this->l_probe_info = "Objectiu: [target] <br> Vaixell de la classe: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Una sonda Sentry Trap propietat de [playername] està atacant la seva nau!";
			break;

			case "danish":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Målrettet Player";
				$this->l_probe_shipclass = "Skib klasse til Target";
				$this->l_probe_description = "Sonde Pris: " . $this->probe_cost . "<br><br> Sentry Trap Probes er designet til at vente på en specifik fjende at anløbe en sektor og angribe den. Du kan vælge den spiller, og skibets klasse du vil sonden til at angribe. Hvis den målrettede spiller ind i sektoren, hvor sonden venter, og de er i den valgte skibets klasse, det vil detonere som en sektor missil. Den eneste forskel mellem en Sentry Trap Probe og en sektor, Missile er målrettet skibet ikke kan omgå angrebet.";
				$this->l_probe_info = "Mål: [target] <br> Skib Klasse: [class]";
				$this->l_probe_imtitle = "Skib under angreb";
				$this->l_probe_imbody = "En Sentry Trap Probe ejes af [playername] er at angribe dit skib!";
			break;

			case "dutch":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Gerichte Player";
				$this->l_probe_shipclass = "Schip Class aan Target";
				$this->l_probe_description = "Probe Kosten: " . $this->probe_cost . "<br><br> Sentry Trap Probes zijn ontworpen om te wachten op een specifiek vijandelijk schip tot een sector te gaan werken en te vallen. U kunt de speler en het schip klasse u wilt dat de sonde aan te vallen. Als de beoogde speler voer de sector waar de sonde zit te wachten en ze zijn in de gekozen klasse schip zal ontploffen als een sector raket. Het enige verschil tussen een Sentry Trap Probe en een sector Missile is de gerichte schip kan niet uit de weg de aanval.";
				$this->l_probe_info = "Target: [target] <br> Schip Klasse: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Een Sentry Trap Probe eigendom van [playername] is aanvallend uw schip!";
			break;

			case "finnish":
				$this->l_probe_type = "Vartiosotilas Trap Probe";
				$this->l_probe_target = "Kohdennetut Player";
				$this->l_probe_shipclass = "Aluksen luokka TARGETiin";
				$this->l_probe_description = "Probe Hinta: " . $this->probe_cost . "<br><br> Sentry Trap Probes on suunniteltu odottaa tietyn vihollisen laivan tulla alalle ja hyökätä niitä vastaan. Voit valita soittimen ja aluksen luokan haluat anturilla hyökätä. Jos kohdennettuja pelaaja tulee alalla, jossa anturi odottaa, ja ne on valittu aluksen luokan se räjähtää kuin alan ohjus. Ainoa ero Sentry Trap Anturin ja Ala Missile on suunnattu alus voi väistää hyökkäyksen.";
				$this->l_probe_info = "Kohde: [target] <br> Aluksen luokka: [class]";
				$this->l_probe_imtitle = "Aluksen Under Attack";
				$this->l_probe_imbody = "Sentry Trap Probe omistama [playername] hyökkää sinun laiva!";
			break;

			case "indonesian":
				$this->l_probe_type = "Penjaga Trap Probe";
				$this->l_probe_target = "Target Player";
				$this->l_probe_shipclass = "Kapal Kelas untuk Target";
				$this->l_probe_description = "Probe Biaya: " . $this->probe_cost . "<br><br> Perangkap penjaga Probe dirancang untuk menunggu kapal musuh tertentu untuk memasuki sektor dan serangan itu. Anda dapat memilih pemain dan kelas kapal Anda ingin probe untuk menyerang. Jika pemain yang ditargetkan masuk ke sektor mana probe menunggu dan mereka berada di kelas yang dipilih kapal itu akan meledak seperti rudal sektor. Satu-satunya perbedaan antara Trap Sentry Probe dan Sektor rudal adalah kapal ditargetkan TIDAK BISA menghindari serangan.";
				$this->l_probe_info = "Sasaran: [target] <br> Kapal Kelas: [class]";
				$this->l_probe_imtitle = "Kapal Under Attack";
				$this->l_probe_imbody = "Sebuah Perangkap Sentry Probe dimiliki oleh [playername] adalah menyerang kapal Anda!";
			break;

			case "norwegian":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Målrettet Player";
				$this->l_probe_shipclass = "Ship klassen til Target";
				$this->l_probe_description = "Probe Kostnad: " . $this->probe_cost . "<br><br> Sentry Trap Probes er utformet for å vente på en bestemt motstanderens skip å legge inn en sektor og angripe det. Du kan velge spilleren og skipet klassen du vil sonden til å angripe. Hvis målrettet spilleren inn i sektoren der sonden venter og de er i den valgte skipet klassen vil detonere som en sektor rakett. Den eneste forskjellen mellom en Sentry Trap Probe og en sektor Missile er målrettet skipet kan ikke unngå å bli angrepet.";
				$this->l_probe_info = "Target: [target] <br> Ship Klasse: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "En Sentry Trap Probe eid av [playername] angriper skipet ditt!";
			break;

			case "portuguese":
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Targeted Player";
				$this->l_probe_shipclass = "Navio da classe a Target";
				$this->l_probe_description = "Custo Probe: " . $this->probe_cost . "<br><br> Sentry Trap Sondas destinam-se a esperar por um navio inimigo específico para introduzir um setor e atacá-lo. Você pode selecionar o jogador e da classe que você deseja que o navio sonda para atacar. Se o jogador alvo entrar no sector em que a sonda está esperando e eles estão na classe do navio selecionado vai detonar como um míssil sector. A única diferença entre uma armadilha Sentry Sonda e um míssil Setor é o navio alvo não pode escapar do ataque.";
				$this->l_probe_info = "Objectivo: [target] <br> Navio de Classe: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "A Sentinela Probe Trap propriedade [playername] está atacando seu navio!";
			break;

			case "swedish":
				$this->l_probe_type = "Vaktpost Trap Probe";
				$this->l_probe_target = "Riktade Player";
				$this->l_probe_shipclass = "Ship klass till Target";
				$this->l_probe_description = "Probe Kostnad: " . $this->probe_cost . "<br><br> Sentry Trap Probes är utformade för att vänta på en specifik fiende fartyg att anlöpa en sektor och angripa den. Du kan välja spelaren och fartygets klass du vill sonden till attack. Om det drabbade spelaren in i sektorer där sonden väntar och de är i den valda fartyget klassen kommer det att detonera som en sektor missil. Den enda skillnaden mellan en Sentry Trap Probe och en sektor missil är riktade fartyget kan inte undandra sig attacken.";
				$this->l_probe_info = "Målgrupp: [target] <br> Ship Klass: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "En Sentry Trap Probe ägs av [playername] attackerar ditt skepp!";
			break;

			default:
				$this->l_probe_type = "Sentry Trap Probe";
				$this->l_probe_target = "Targeted Player";
				$this->l_probe_shipclass = "Ship Class to Target";
				$this->l_probe_description = "Probe Cost: " . $this->probe_cost . "<br><br>Sentry Trap Probes are designed to wait for a specific enemy ship to enter a sector and attack it.  You can select the player and the ship class you want the probe to attack.  If the targetted player enter the sector where the probe is waiting and they are in the selected ship class it will detonate like a sector missile.  The only difference between a Sentry Trap Probe and a Sector Missile is the targetted ship CANNOT evade the attack.";
				$this->l_probe_info = "Target: [target]<br>Ship Class: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "A Sentry Trap Probe owned by [playername] is attacking your ship!";
			break;
		}
	}

	var $tag = "LOG5_PROBE_TRAP";

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
		include ("globals/get_player.inc");
		include ("globals/get_shipclassname.inc");
		$items = explode(",", trim($data));
		for($i = 0; $i < count($items); $i++)
		{
			$variable = explode("=", $items[$i]);
			$variable[0] = trim($variable[0]);
			$variable[1] = trim($variable[1]);
			$$variable[0] = $variable[1];
		}
		$info = str_replace("[target]", get_player($trap_target_player_id), $this->l_probe_info);
		$info = str_replace("[class]", get_shipclassname($trap_ship_class), $info);
		return $info;
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
		global $db, $db_prefix;
		$orders_array = array();
		$playerlist = "";
		$res = $db->Execute("SELECT player_id,character_name FROM {$db_prefix}players where player_id>3 ORDER BY character_name");
		$totalplayers = $res->RecordCount();
		$playercount = 0;
		while (!$res->EOF)
		{
			$row = $res->fields;
			$playerlist .= "$row[player_id]=$row[character_name]";
			$playercount++;
			if($playercount != $totalplayers)
			{
				$playerlist .= ", ";
			}
			$res->MoveNext();
		}

		$classdata = "";
		$res = $db->Execute("SELECT type_id,name FROM {$db_prefix}ship_types where buyable='Y' ORDER BY type_id");
		$totalclasses = $res->RecordCount();
		$classrcount = 0;
		while (!$res->EOF)
		{
			$row = $res->fields;
			$classdata .= "$row[type_id]=$row[name]";
			$classrcount++;
			if($classrcount != $totalclasses)
			{
				$classdata .= ", ";
			}
			$res->MoveNext();
		}

		$orders_array[] = "trap_target_player_id = ;	list  ;" . $playerlist . " ; " . $this->l_probe_target;
		$orders_array[] = "trap_ship_class = ;	list  ;" . $classdata . " ; " . $this->l_probe_shipclass;
		return $orders_array;
	}
 
	function probe_finishorders_code()
	{
		global $db, $db_prefix, $trap_target_player_id, $trap_ship_class, $l_global_mmenu, $probe_id;
		global $probeclass, $new_type, $probe_id, $playerinfo, $l_probe2_nocredits, $template_object, $templatename, $l_probe_forbidFED, $title, $sectorinfo;

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
		if($playerinfo['credits'] < $this->probe_cost)
		{
			include ("header.php");
			$template_object->assign("title", $title);
			$l_probe2_nocredits = str_replace("[total]", NUMBER($this->probe_cost), $l_probe2_nocredits);
			$l_probe2_nocredits = str_replace("[credits]", NUMBER($playerinfo['credits']), $l_probe2_nocredits);
			$template_object->assign("error_msg", $l_probe2_nocredits);
			$template_object->assign("gotomain", $l_global_mmenu);
			$template_object->display("master_template/genericdie.tpl");
			include ("footer.php");
			die();
		}
		else
		{
			$data = "trap_target_player_id=" . $_POST['trap_target_player_id'] . ",trap_ship_class=" . $_POST['trap_ship_class'];

			$debug_query = $db->Execute("UPDATE {$db_prefix}probe SET class='$probeclass[$new_type]', type=$new_type, data=" . $db->qstr($data) . " WHERE probe_id=$probe_id");
			db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits-$this->probe_cost WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
			echo "<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=probes.php\">";
			die();
		}
	}

	function probe_move_code($probeinfo, $shiptype, $destination)
	{
		global $db, $db_prefix, $shipinfo, $playerinfo, $sectorinfo, $shipdevice, $langdir, $full_attack_modifier, $shipdevice, $shiptypes;

		include ("globals/combat_functions.inc");
		include ("globals/ship_bounty_check.inc");
		include ("globals/db_kill_player.inc");
		include ("globals/player_ship_destroyed.inc");
		include ("globals/get_player.inc");
		include ("globals/send_system_im.inc");

		$items = explode(",", trim($probeinfo['data']));
		for($i = 0; $i < count($items); $i++)
		{
			$variable = explode("=", $items[$i]);
			$variable[0] = trim($variable[0]);
			$variable[1] = trim($variable[1]);
			$$variable[0] = $variable[1];
		}

		if($trap_target_player_id == $playerinfo['player_id'] && $trap_ship_class == $shipinfo['class'])
		{
			$success = SCAN_SUCCESS($probeinfo['sensors'], $shipinfo['cloak'], $shiptypes[$shipinfo['class']]['basehull']);

			if (mt_rand(1, 100) < $success)
			{
				$resteam = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=$probeinfo[owner_id]", 1);
				db_op_result($resteam,__LINE__,__FILE__);
				$teammate = $resteam->fields['team'];
				$probeownerinfo = $resteam->fields;
				$resteam->close();
				$isfedbounty = ship_bounty_check($probeownerinfo, $destination, $playerinfo, 0);

				if ($playerinfo['team'] != $teammate && $isfedbounty == 0 && $probeownerinfo['player_id'] != $playerinfo['player_id'])
				{
					$sm_damage_shields = 11000;
					$sm_damage_all = 9000;

					if(!class_exists($shipinfo['armor_class'])){
						include ("class/" . $shipinfo['armor_class'] . ".inc");
					}

					// get target beam, shield and armor values
					$target_shield_energy = floor($shipinfo['energy'] * 0.4);
					$sectormissile_attack_energy = $shipinfo['energy'] - $target_shield_energy;

					if (NUM_SHIELDS($shipinfo['shields']) < $target_shield_energy)
					{
						$target_shield_energy = NUM_SHIELDS($shipinfo['shields']);
					}

					$targetenergyset = $target_shield_energy + $sectormissile_attack_energy;

					$left_over_energy = max(0, $shipinfo['energy'] - $targetenergyset);

					$targetarmor = $shipinfo['armor_pts'];

					$shipinfoshields = $shipinfo['shields'];
					$shipinfoarmor = $shipinfo['armor'];
					$targetname = $playerinfo['character_name'];

					if(!class_exists($shipinfo['shield_class'])){
						include ("class/" . $shipinfo['shield_class'] . ".inc");
					}

					$targetobject = new $shipinfo['shield_class']();
					$ship_shield_hit_pts = $targetobject->ship_shield_hit_pts;

					if(!class_exists($shipinfo['armor_class'])){
						include ("class/" . $shipinfo['armor_class'] . ".inc");
					}

					$targetobject = new $shipinfo['armor_class']();
					$ship_armor_hit_pts = $targetobject->ship_armor_hit_pts;

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Trap Probe Combat Start:</B></font><BR>
	Attacker " . get_player($probeinfo['owner_id']) . " (id: $probeinfo[player_id]) in sector $sectorinfo[name]<br>
	 Attacker Score: " . $debug_attack['attackerscore'] . ", 
	 Owns Sector: " . $debug_attack['isowner'] . ",  
	 Opposite Alignment: " . $debug_attack['isopposite'] . ", 
	 Attack Ratio: " . $debug_attack['ratio'] . ", <br>
	 Sensor Tech: $probeinfo[sensor], 
	 Cloak: $probeinfo[cloak]<br><br>
	Defender " . $playerinfo['character_name'] . " (id: $playerinfo[player_id])
	 Target Score: " . $debug_attack['targetscore'] . ", 
	 Has Bounty: " . $debug_attack['hasbounty'] . ", 
	 Target Turns: " . $debug_attack['turns'] . ", <br>
	 Total Energy: <B>" . NUMBER($shipinfo['energy']) . "</B>, 
	 Attack nergy: <B>" . NUMBER($sectormissile_attack_energy) . "</B>, 
	 Shields: <B>" . NUMBER($target_shield_energy) . "</B>, 
	 Armor Points: <B>" . NUMBER($targetarmor) . "</B><br>
	 Shield Tech: $shipinfo[shields], 
	 Armor Tech: $shipinfo[armor]");

					$attackerlowpercent = ecmcheck($shipinfo['ecm'], $probeinfo['sensors'], -mt_rand($full_attack_modifier, 90));

					$used_attack_energy = 0;
					$target_armor_died = 0;
					$target_shields_died = 0;

					if($sectormissile_attack_energy != 0)
					{
						$target_shield_hit_pts = $target_shield_energy * $ship_shield_hit_pts;
						$target_armor_hit_pts = $targetarmor * $ship_armor_hit_pts;
						$attack_fire_failure = calc_failure($sectormissile_attack_energy, $shipinfoshields);
						$sectormissile_attack_energy -= $attack_fire_failure[1];

						$attack_fire_damage = calc_damage($sectormissile_attack_energy, $sm_damage_shields, $attackerlowpercent, $shipinfoshields, $shipinfoshields, $target_shield_hit_pts);
						$used_attack_energy = $attack_fire_damage[3];

						if($attack_fire_damage[0] > $target_shield_hit_pts)
						{
							$target_shields_died = $target_shield_energy;

							$attackerlowpercent = ecmcheck($shipinfo['ecm'], $probeinfo['sensors'], -mt_rand($full_attack_modifier, 90));
							$attack_fire2_failure = calc_failure($attack_fire_damage[4], $shipinfoarmor);
							$attack_fire_damage[4] -= $attack_fire2_failure[1];

							$attack_fire2_damage = calc_damage($attack_fire_damage[4], $sm_damage_all, $attackerlowpercent, $shipinfoarmor, $shipinfoarmor, $target_armor_hit_pts);
							$used_attack_energy += $attack_fire2_damage[3];

							if($attack_fire2_damage[0] > $target_armor_hit_pts)
							{
								$attack_damage = floor($target_armor_hit_pts / $ship_armor_hit_pts);
								$target_armor_died = $attack_damage;
							}
							else
							{
								$target_armor_hit_pts = $target_armor_hit_pts - $attack_fire2_damage[0];
								$target_armor_used = floor($attack_fire2_damage[0] / $ship_armor_hit_pts);
								$target_armor_died = $target_armor_used;
							}
						}
						else
						{
							$target_shield_hit_pts = $target_shield_hit_pts - $attack_fire_damage[0];
							$target_shields_used = floor($attack_fire_damage[0] / $ship_shield_hit_pts);
							$target_shields_died = $target_shields_used;
						}
					}

					//                 End of Attack code
					$target_armor_left = $targetarmor - $target_armor_died;
					$target_shields_left -= $target_shields_died;
					$used_attack_energy += $target_shields_died;

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Sentry Trap Probe Combat End:</B></font><BR>Attacker " . get_player($probeinfo['owner_id']) . "<br>
	Defender ".$playerinfo['character_name'] . "
	 Shields: <B>" . NUMBER($target_shields_left) . "</B>, 
	 Armor Points: <B>" . NUMBER($target_armor_left) . "</B>");

					$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts-$target_armor_died, 0), energy=GREATEST(energy-$used_attack_energy, 0) WHERE ship_id=$shipinfo[ship_id]");
					db_op_result($debug_query,__LINE__,__FILE__);

					if ($target_armor_left < 1)
					{
						//	target_died();
						if ($shipdevice['dev_escapepod']['amount'] == 1)
						{
							player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], $probeownerinfo['player_id'], $probeownerinfo['rating'], "killedtrapprobepod");
							playerlog($playerinfo['player_id'], "LOG5_DESTROYED_PROBE_ATTACK", "$probeownerinfo[character_name]|$destination");
							playerlog($probeownerinfo['player_id'], "LOG5_PROBE_ATTACK_SUCCEEDED", "$playerinfo[character_name]|$destination");
						}
						else
						{
							playerlog($playerinfo['player_id'], "LOG5_DESTROYED_PROBE_ATTACK", "$probeownerinfo[character_name]|$destination");
							playerlog($probeownerinfo['player_id'], "LOG5_PROBE_ATTACK_SUCCEEDED", "$playerinfo[character_name]|$destination");
							db_kill_player($playerinfo['player_id'], $probeownerinfo['player_id'], $probeownerinfo['rating'], "killedtrapprobe");
						}
					}
					else
					{
						if($target_armor_left > 0)
						{
							calc_internal_damage($shipinfo['ship_id'], 0, ($shipinfo['armor_pts']-$target_armor_left) / $shipinfo['armor_pts']);
						}
						$armor_lost = $shipinfo['armor_pts'] - $target_armor_left;
						$energy_lost = $used_attack_energy;
						playerlog($playerinfo['player_id'], "LOG5_SURVIVE_PROBE_ATTACK", "$probeownerinfo[character_name]|$armor_lost|$energy_lost|$destination");
						playerlog($probeownerinfo['player_id'], "LOG5_PROBE_ATTACK_FAILED", "$playerinfo[character_name]|$destination");
					}
					$debug_query = $db->Execute("DELETE FROM {$db_prefix}probe WHERE probe_id=$probeinfo[probe_id]");
					db_op_result($debug_query,__LINE__,__FILE__);
					$l_probe_imbody = str_replace("[playername]", $probeownerinfo['character_name'], $this->l_probe_imbody);
					send_system_im($playerinfo['player_id'], $this->l_probe_imtitle, $l_probe_imbody, $playerinfo['last_login']);
				}
			}
		}
	}

	function probe_scheduler_code()
	{
	}
}

?>