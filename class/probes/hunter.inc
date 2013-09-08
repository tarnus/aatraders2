<?php
class hunter {
	var $class = "hunter";
	var $type = 5;
	var $l_probe_type;
	var $probe_cost = 1000000;
	var $l_probe_target;
	var $l_probe_shipclass;
	var $l_probe_description;
	var $l_probe_info;
	var $l_probe_imtitle;
	var $l_probe_imbody;

	// fill language variables
	function hunter()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Suunatud Player";
				$this->l_probe_shipclass = "Laev klassi TARGETiga";
				$this->l_probe_description = "Probe Hind: " . $this->probe_cost . "<br><br> Hunter Probes eesmärk on otsida konkreetset vaenlase laevade ja rünnaku ta. Võite valida mängija ning laeva klassi soovite sond rünnak. Kui sond leiab suunatud mängija ja nad on valitud laeva klassi see plahvatama nagu sektori rakett. Ainus erinevus Hunter ja drenaa?i Sector rakettide on suunatud laeva ei saa vältida rünnak.";
				$this->l_probe_info = "Target: [target] <br> Laeva klass: [class]";
				$this->l_probe_imtitle = "Laev rünnaku all";
				$this->l_probe_imbody = "Hunter Probe omanduses [playername] ründab oma laeva!";
			break;

			case "french":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Ciblées Player";
				$this->l_probe_shipclass = "Navire de la classe à Target";
				$this->l_probe_description = "Probe Coût: " . $this->probe_cost . "<br><br> Hunter sondes sont conçues pour rechercher un navire ennemi précis et l&#39;attaquer. Vous pouvez sélectionner le joueur et le navire de la classe que vous voulez la sonde à l&#39;attaque. Si la sonde trouve le joueur ciblé et ils sont choisis dans la classe du navire avec lequel il fera exploser comme un missile de secteur. La seule différence entre une sonde de chasseur et un secteur des missiles est le navire ciblés peuvent pas se soustraire à l&#39;attaque.";
				$this->l_probe_info = "Target: [target] <br> Navire de la classe: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Une sonde Hunter détenue par [playername] est d&#39;attaquer votre bateau!";
			break;

			case "german":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Gezielte Player";
				$this->l_probe_shipclass = "Schiffsklasse an Target";
				$this->l_probe_description = "Probe Kosten: " . $this->probe_cost . "<br><br> Hunter Sonden sind so konzipiert, für eine bestimmte gegnerische Schiff zu suchen und sie anzugreifen. Sie können die Spieler und das Schiff Klasse, die Sie wollen, dass die Sonde zum Angriff. Wenn die Sonde findet die anvisierte Spieler und sie sind in der gewählten Schiffsklasse wird es wie ein Sektor Raketen zünden. Der einzige Unterschied zwischen einer Probe und ein Hunter Sector Missile ist die gezielte Schiff nicht entziehen kann den Angriff.";
				$this->l_probe_info = "Target: [target] <br> Schiffsklasse: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Ein Hunter Probe im Besitz von [playername] greift Ihr Schiff!";
			break;

			case "italian":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Mirati Player";
				$this->l_probe_shipclass = "Nave di classe a Target";
				$this->l_probe_description = "Sonda Costo: " . $this->probe_cost . "<br><br> Sonde Hunter sono progettati per la ricerca di una nave specifica nemico e attaccarlo. È possibile selezionare il giocatore e la classe della nave che si desidera la sonda ad attaccare. Se la sonda si trova il giocatore mirate e sono in nave selezionata classe sarà esplodere come un missile settore. L&#39;unica differenza tra una sonda Hunter e un missile settore è la nave mirata non può sottrarsi all&#39;attacco.";
				$this->l_probe_info = "Target: [target] <br> Nave di classe: [class]";
				$this->l_probe_imtitle = "Nave Under Attack";
				$this->l_probe_imbody = "Una sonda Hunter di proprietà di [playername] sta attaccando la vostra nave!";
			break;

			case "spanish":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Dirigida Player";
				$this->l_probe_shipclass = "Barco de la clase a Target";
				$this->l_probe_description = "Costo de la sonda: " . $this->probe_cost . "<br><br> Sondas de Hunter están diseñados para la búsqueda de un buque enemigo específico y atacarlo. Usted puede seleccionar el jugador y la clase del buque que desee de la sonda al ataque. Si la sonda se encuentra a ese jugador y están en la nave de clase seleccionada se detonan como un misil sector. La única diferencia entre una sonda Hunter y un misil sector es el barco blanco no puede eludir el ataque.";
				$this->l_probe_info = "Objetivo: [target] <br> Barco de la clase: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Una sonda Hunter propiedad de [playername] está atacando su nave!";
			break;

			case "albanian":
				$this->l_probe_type = "Gjahtari hetimin";
				$this->l_probe_target = "Synuar Player";
				$this->l_probe_shipclass = "Klasa anije për të synuar";
				$this->l_probe_description = "Kosto hetimin: " . $this->probe_cost . "<br><br> Gjahtari heton janë të dizajnuara për të kërkuar për një anije specifike dhe goditjen e armik atë. Ju mund të zgjidhni lojtar dhe klasës anije doni hetim për sulmin. Nëse hetimi gjen lojtar në shënjestër dhe ata janë në anije zgjedhur klasë se do të shpërthente si një raketë sektor. I vetmi ndryshim midis një hetim gjahtari dhe një raketave Sektori është anija synuar NUK MUND t&#39;i shmanget sulmit.";
				$this->l_probe_info = "Synimi: [target] <br> Anije Klasa: [class]";
				$this->l_probe_imtitle = "Anije Sipas Attack";
				$this->l_probe_imbody = "Një hetim gjahtari në pronësi nga [playername] është sulmuar anijen tuaj!";
			break;

			case "catalan":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Dirigida Player";
				$this->l_probe_shipclass = "Vaixell de la classe a Target";
				$this->l_probe_description = "Cost de la sonda: " . $this->probe_cost . "<br><br> Sondes de Hunter estan dissenyats per a la recerca d&#39;un vaixell enemic específic i atacar-lo. Vostè pot seleccionar el jugador i la classe del vaixell que desitgi de la sonda a l&#39;atac. Si la sonda es troba a aquest jugador i estan en la nau de classe seleccionada es detonen com un míssil sector. L&#39;única diferència entre una sonda Hunter i un míssil sector és el vaixell blanc no pot eludir l&#39;atac.";
				$this->l_probe_info = "Objectiu: [target] <br> Vaixell de la classe: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Una sonda Hunter propietat de [playername] està atacant la seva nau!";
			break;

			case "danish":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Målrettet Player";
				$this->l_probe_shipclass = "Skib klasse til Target";
				$this->l_probe_description = "Sonde Pris: " . $this->probe_cost . "<br><br> Hunter Probes er designet til at søge på en specifik fjende skib og angribe den. Du kan vælge den spiller, og skibets klasse du vil sonden til at angribe. Hvis sonden finder målrettede spiller, og de er i den valgte skibets klasse, det vil detonere som en sektor missil. Den eneste forskel mellem en Hunter Probe og en sektor Missile er målrettet skibet ikke kan omgå angrebet.";
				$this->l_probe_info = "Mål: [target] <br> Skib Klasse: [class]";
				$this->l_probe_imtitle = "Skib under angreb";
				$this->l_probe_imbody = "En Hunter Probe ejes af [playername] er at angribe dit skib!";
			break;

			case "dutch":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Gerichte Player";
				$this->l_probe_shipclass = "Schip Class aan Target";
				$this->l_probe_description = "Probe Kosten: " . $this->probe_cost . "<br><br> Hunter Probes zijn ontworpen om te zoeken naar een specifiek vijandelijk schip en het aanvallen. U kunt de speler en het schip klasse u wilt dat de sonde aan te vallen. Als de sonde vindt de doelgerichte speler en ze zijn in de gekozen klasse schip zal ontploffen als een sector raket. Het enige verschil tussen een Hunter Probe en een sector Missile is de gerichte schip kan niet uit de weg de aanval.";
				$this->l_probe_info = "Target: [target] <br> Schip Klasse: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Een jager Probe eigendom van [playername] is aanvallend uw schip!";
			break;

			case "finnish":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Kohdennetut Player";
				$this->l_probe_shipclass = "Aluksen luokka TARGETiin";
				$this->l_probe_description = "Probe Hinta: " . $this->probe_cost . "<br><br> Hunter Probes on tarkoitus etsiä tietyn vihollisen laivan ja hyökätä niitä vastaan. Voit valita soittimen ja aluksen luokan haluat anturilla hyökätä. Jos anturi havaitsee kohdennettuja pelaaja, ja ne on valittu aluksen luokan se räjähtää kuin alan ohjus. Ainoa ero Hunter Anturin ja Ala Missile on suunnattu alus voi väistää hyökkäyksen.";
				$this->l_probe_info = "Kohde: [target] <br> Aluksen luokka: [class]";
				$this->l_probe_imtitle = "Aluksen Under Attack";
				$this->l_probe_imbody = "Hunter Probe omistama [playername] hyökkää sinun laiva!";
			break;

			case "indonesian":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Target Player";
				$this->l_probe_shipclass = "Kapal Kelas untuk Target";
				$this->l_probe_description = "Probe Biaya: " . $this->probe_cost . "<br><br> Pemburu Probe dirancang untuk mencari kapal musuh tertentu dan serangan itu. Anda dapat memilih pemain dan kelas kapal Anda ingin probe untuk menyerang. Jika pemeriksaan menemukan pemain yang ditargetkan dan mereka berada di kelas yang dipilih kapal itu akan meledak seperti rudal sektor. Satu-satunya perbedaan antara Hunter Probe dan Sektor rudal adalah kapal ditargetkan TIDAK BISA menghindari serangan.";
				$this->l_probe_info = "Sasaran: [target] <br> Kapal Kelas: [class]";
				$this->l_probe_imtitle = "Kapal Under Attack";
				$this->l_probe_imbody = "Seorang Hunter Probe dimiliki oleh [playername] adalah menyerang kapal Anda!";
			break;

			case "norwegian":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Målrettet Player";
				$this->l_probe_shipclass = "Ship klassen til Target";
				$this->l_probe_description = "Probe Kostnad: " . $this->probe_cost . "<br><br> Hunter Probes er utformet for å søke etter et bestemt fiendens skip og angripe det. Du kan velge spilleren og skipet klassen du vil sonden til å angripe. Dersom sonden finner målrettede spilleren og de er i den valgte skipet klassen vil detonere som en sektor rakett. Den eneste forskjellen mellom en Hunter Probe og en sektor Missile er målrettet skipet kan ikke unngå å bli angrepet.";
				$this->l_probe_info = "Target: [target] <br> Ship Klasse: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "En Hunter Probe eid av [playername] angriper skipet ditt!";
			break;

			case "portuguese":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Targeted Player";
				$this->l_probe_shipclass = "Navio da classe a Target";
				$this->l_probe_description = "Custo Probe: " . $this->probe_cost . "<br><br> Hunter Sondas destinam-se a busca por um navio inimigo específico e atacá-lo. Você pode selecionar o jogador e da classe que você deseja que o navio sonda para atacar. Se a sonda encontra o jogador alvo e estão na classe do navio selecionado vai detonar como um míssil sector. A única diferença entre um caçador e um Teste de mísseis do Setor é o navio alvo não pode escapar do ataque.";
				$this->l_probe_info = "Objectivo: [target] <br> Navio de Classe: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "A Sonda Hunter propriedade [playername] está atacando seu navio!";
			break;

			case "swedish":
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Riktade Player";
				$this->l_probe_shipclass = "Ship klass till Target";
				$this->l_probe_description = "Probe Kostnad: " . $this->probe_cost . "<br><br> Hunter Probes är utformade för att söka efter en specifik fiende skepp och angripa den. Du kan välja spelaren och fartygets klass du vill sonden till attack. Om sökningen hittar riktade spelare och de är i den valda fartyget klassen kommer det att detonera som en sektor missil. Den enda skillnaden mellan en Hunter Probe och en sektor missil är riktade fartyget kan inte undandra sig attacken.";
				$this->l_probe_info = "Målgrupp: [target] <br> Ship Klass: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "Jägare Probe ägs av [playername] attackerar ditt skepp!";
			break;

			default:
				$this->l_probe_type = "Hunter Probe";
				$this->l_probe_target = "Targeted Player";
				$this->l_probe_shipclass = "Ship Class to Target";
				$this->l_probe_description = "Probe Cost: " . $this->probe_cost . "<br><br>Hunter Probes are designed to search for a specific enemy ship and attack it.  You can select the player and the ship class you want the probe to attack.  If the probe finds the targetted player and they are in the selected ship class it will detonate like a sector missile.  The only difference between a Hunter Probe and a Sector Missile is the targetted ship CANNOT evade the attack.";
				$this->l_probe_info = "Target: [target]<br>Ship Class: [class]";
				$this->l_probe_imtitle = "Ship Under Attack";
				$this->l_probe_imbody = "A Hunter Probe owned by [playername] is attacking your ship!";
			break;
		}
	}

	var $tag = "LOG5_PROBE_HUNTER";

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
		$info = str_replace("[target]", get_player($hunter_target_player_id), $this->l_probe_info);
		$info = str_replace("[class]", get_shipclassname($hunter_ship_class), $info);
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

		$orders_array[] = "hunter_target_player_id = ;	list  ;" . $playerlist . " ; " . $this->l_probe_target;
		$orders_array[] = "hunter_ship_class = ;	list  ;" . $classdata . " ; " . $this->l_probe_shipclass;
		return $orders_array;
	}
 
	function probe_finishorders_code()
	{
		global $db, $db_prefix, $hunter_target_player_id, $hunter_ship_class,$probe_id, $l_global_mmenu, $l_probe_forbidFED, $title;
		global $probeclass, $new_type, $playerinfo, $l_probe2_nocredits, $template_object, $templatename, $sectorinfo;

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
			$data = "hunter_target_player_id=" . $_POST['hunter_target_player_id'] . ",hunter_ship_class=" . $_POST['hunter_ship_class'];

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
		global $db, $db_prefix, $shipinfo, $playerinfo, $sectorinfo, $shipdevice, $langdir, $full_attack_modifier, $shiptypes;

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

		if($hunter_target_player_id == $playerinfo['player_id'] && $hunter_ship_class == $shipinfo['class'])
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

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Hunter Probe Combat Start:</B></font><BR>
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

	adminlog("LOG0_ADMIN_COMBAT","<font color=yellow><B>Hunter Probe Combat End:</B></font><BR>Attacker " . get_player($probeinfo['owner_id']) . "<br>
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
							player_ship_destroyed($shipinfo['ship_id'], $playerinfo['player_id'], $playerinfo['rating'], $probeownerinfo['player_id'], $probeownerinfo['rating'], "killedhunterprobepod");
							playerlog($playerinfo['player_id'], "LOG5_DESTROYED_PROBE_ATTACK", "$probeownerinfo[character_name]|$destination");
							playerlog($probeownerinfo['player_id'], "LOG5_PROBE_ATTACK_SUCCEEDED", "$playerinfo[character_name]|$destination");
						}
						else
						{
							playerlog($playerinfo['player_id'], "LOG5_DESTROYED_PROBE_ATTACK", "$probeownerinfo[character_name]|$destination");
							playerlog($probeownerinfo['player_id'], "LOG5_PROBE_ATTACK_SUCCEEDED", "$playerinfo[character_name]|$destination");
							db_kill_player($playerinfo['player_id'], $probeownerinfo['player_id'], $probeownerinfo['rating'], "killedhunterprobe");
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

	function probe_scheduler_code($probeinfo)
	{
		global $db, $db_prefix, $level_factor;

		$targetlink = 0;

		$items = explode(",", trim($probeinfo['data']));
		for($i = 0; $i < count($items); $i++)
		{
			$variable = explode("=", $items[$i]);
			$variable[0] = trim($variable[0]);
			$variable[1] = trim($variable[1]);
			$$variable[0] = $variable[1];
		}

		$lastshipseen = $db->SelectLimit("SELECT {$db_prefix}universe.sector_id, {$db_prefix}sector_log.* from {$db_prefix}sector_log, {$db_prefix}universe WHERE {$db_prefix}sector_log.player_id <> $probeinfo[owner_id] AND {$db_prefix}sector_log.source = $probeinfo[sector_id] and {$db_prefix}sector_log.destination!=0  and {$db_prefix}universe.sector_id ={$db_prefix}sector_log.destination ORDER BY {$db_prefix}sector_log.time DESC", 1);
		db_op_result($lastshipseen,__LINE__,__FILE__);
		$lastseeninfo = $lastshipseen->fields;
		if($hunter_target_player_id == $lastseeninfo['player_id'])
		{
			$targetlink = $lastseeninfo['sector_id'];
			TextFlush ("<font color=\"lime\"><b>Found Target " . $lastseeninfo['player_id'] . " following to sector " . $lastseeninfo['sector_id'] . ".</b></font><br>");
		}

		$linkres = $db->Execute ("SELECT link_dest FROM {$db_prefix}links WHERE link_start='$probeinfo[sector_id]'");
		db_op_result($linkres,__LINE__,__FILE__);

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
			$sectres = $db->Execute ("SELECT zone_id FROM {$db_prefix}universe WHERE sector_id='$targetlink'");
			if ($sectres->fields['zone_id'] == 2)
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

					$this->probe_scan_code( $probeinfo, $targetlink );
					log_move($probeinfo['owner_id'], $probeinfo['probe_id'], $probeinfo['sector_id'], $targetlink, 1, $probeinfo['cloak'], $sectres->fields['zone_id']);
				}else{
					TextFlush ("Failed Move not enough turns - 1 turn needed <br>");
					PROBE_playerlog($probeinfo['owner_id'], "LOG9_PROBE_NOTURNS", "$probeinfo[probe_id]|$targetlink"); 
				}
			}
		}
	}

	function probe_scan_code( $probeinfo, $targetlink )
	{
		global $db, $db_prefix, $shipinfo, $playerinfo, $shipdevice;
		include ("globals/get_shipclassname.inc");

		$result4 = $db->Execute(" SELECT {$db_prefix}ships.*
							  FROM {$db_prefix}ships
							  LEFT JOIN {$db_prefix}players ON {$db_prefix}ships.player_id={$db_prefix}players.player_id
							  WHERE {$db_prefix}ships.player_id<>$probeinfo[owner_id]
							  AND {$db_prefix}ships.sector_id=$targetlink
							  AND {$db_prefix}ships.on_planet='N' AND {$db_prefix}players.currentship={$db_prefix}ships.ship_id");

		if($result4->RecordCount() > 0)
		{
			TextFlush ("<font color=\"lime\"><b>Found " . $result4->RecordCount() . " ships in this sector.</b></font><br>");
		}
		else
		{
			TextFlush ("Found " . $result4->RecordCount() . " ships in this sector.<br>");
		}

		if (!$result4->EOF)
		{
			while (!$result4->EOF)
			{
				$shipinfo = $result4->fields;
				$result3 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=" . $shipinfo['player_id'], 1);
				$playerinfo = $result3->fields;
				$shipdevice = $db->GetToFieldArray("SELECT * FROM {$db_prefix}ship_devices WHERE ship_id=$playerinfo[currentship]", '', 'class');
				$shiptype = get_shipclassname($shipinfo['class']);
				$this->probe_move_code($probeinfo, $shiptype, $targetlink);
				$result4->MoveNext();
			}
		}
	}
}

?>