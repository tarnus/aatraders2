<?php
class megaplanet
{
	var $class = "megaplanet";
	var $pieces = 30;
	var $min_cloak = 350; // Cloak value of each artifact piece
	var $max_cloak = 410; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 0; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 1; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function megaplanet()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Mega Planet Tehis";
				$this->description = "See Tehis loob Mega Planet ühe planeedi Realspace sektor. Planeet on 400 tasemetega techs 60% maksimaalse arvu toetas kolonistide ja 300% energia tootmiseks. Neljas kaup on laeva kere. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud Mega Planet luuakse. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Mega planeet on loodud sektoris [sector].";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
			break;

			case "french":
				$this->classname = "Mega Planet Artefact";
				$this->description = "Cet artefact se créer une planète en un seul Mega planète REALSPACE Secteur. La planète aura 400 niveaux sur les techniciens, 60% du nombre maximum de colons soutenus et la production de 300% d&#39;énergie. Le quatrième produit sera coques de navires. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont a trouvé la planète Mega sera créé. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". The Planet Mega a été créé dans le secteur [sector].";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
			break;

			case "german":
				$this->classname = "Mega Planet Artefakt";
				$this->description = "Dieses Artefakt wird ein Mega Planet in einem einzigen Planeten Realspace Sektor. Der Planet wird 400 Stufen auf Techniker, 60% der maximalen Anzahl der unterstützten Siedler und 300% der Energieerzeugung. Die vierte Ware wird Schiffsrümpfen. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Stücke fanden die Mega Planeten geschaffen werden. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Das Mega-Planet wurde im Sektor geschaffen [sector].";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
			break;

			case "italian":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Artefatto questo creerà un Planet Mega in un pianeta unico settore mondo fisico. Il pianeta avranno 400 livelli su tech, il 60% del numero massimo di coloni sostenuto e 300% la produzione di energia. La merce quarto saranno gli scafi delle navi. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi si trovano il Planet Mega sarà creato. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". Il Mega Planet è stato creato nel settore [sector].";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
			break;

			case "spanish":
				$this->classname = "Mega Planet Artefacto";
				$this->description = "Este artefacto creará un planeta Mega en un solo planeta espacio real del sector. El planeta tendrá 400 niveles de técnicos, el 60% del número máximo de colonos apoyó la producción de energía y 300%. La mercancía de sesiones se cascos de los barcos. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran el planeta Mega será creado. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". El planeta Mega se ha creado en el sector [sector].";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
			break;

			case "albanian":
				$this->classname = "Mega Planet Objekti";
				$this->description = "Kjo Objekti i do të krijojë një Planeti Mega në një të vetme Sektorin e planetit Realspace. Planet do të ketë 400 nivelet më techs, 60% të numrit maksimal të kolonë mbështetur dhe 300% të prodhimit të energjisë. Mall i katërt do të jetë Hulls anijes. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur Planeti Mega do të jetë krijuar. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Planet Mega është krijuar në sektorin [sector].";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
			break;

			case "catalan":
				$this->classname = "Mega Planet Artefacte";
				$this->description = "Aquest artefacte crearà un planeta Mega en un sol planeta espai real del sector. El planeta tindrà 400 nivells de tècnics, el 60% del nombre màxim de colons va recolzar la producció d&#39;energia i 300%. La mercaderia de sessions es cascs de vaixells. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben el planeta Mega serà creat. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". El planeta Mega s&#39;ha creat en el sector [sector].";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
			break;

			case "danish":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Dette Artifact vil skabe et Mega Planet i en enkelt planet Realspace Sector. Planeten vil have 400 niveauer på techs, 60% af det maksimale antal støttede kolonisterne og 300% energi produktion. Den fjerde råvare vil blive skibsskrog. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle stykker er fundet Mega Planet vil blive oprettet. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". The Mega Planet er blevet oprettet i sektor [sector].";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
			break;

			case "dutch":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Artefact Dit zal leiden tot een Mega Planet in een enkele planeet Realspace Sector. De planeet zal hebben 400 niveaus op techs, 60% van het maximale aantal ondersteunde kolonisten en 300% energie productie. De vierde grondstoffen zal worden scheepsrompen. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn de Mega Planet gevonden zal worden gecreëerd. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". De Mega Planet is opgericht in de sector [sector].";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
			break;

			case "finnish":
				$this->classname = "Mega Planet Teos";
				$this->description = "Tämä Teos luo Mega Planet on yksi planeetan Realspace Sector. Planet on 400 tasoa tech, 60% enimmäismäärän tukea uudisasukkaita ja 300% energian tuotannosta. Neljäs hyödyke on Ship runkoa. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset ovat löytäneet Mega Planet luodaan. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Mega Planet on luotu alalla [sector].";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
			break;

			case "indonesian":
				$this->classname = "Mega Planet artifak";
				$this->description = "Artefak ini akan menciptakan sebuah Mega Planet dalam satu planet Realspace Sektor. Planet akan memiliki 400 tingkat di teknisi, 60% dari jumlah maksimum yang didukung koloni dan 300% produksi energi. Komoditi keempat akan Kapal Hulls. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Planet Mega akan dibuat. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Mega Planet telah diciptakan di sektor [sector].";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
			break;

			case "norwegian":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Dette Artifact vil opprette en Mega planet i et enkelt planet Realspace sektor. Planeten vil ha 400 nivå på teknikken, 60% av det maksimale antallet støttede kolonister og 300% energiproduksjon. Den fjerde varen vil bli Ship Skrog. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet Mega Planet vil bli opprettet. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". The Mega Planet har blitt opprettet i sektor [sector].";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
			break;

			case "portuguese":
				$this->classname = "Mega Planet Artefato";
				$this->description = "Este artefato vai criar um Planet Mega num único planeta Realspace Setor. O planeta terá 400 em níveis técnicos, 60% do número máximo de colonos apoiados e 300% da produção de energia. A mercadoria será quarta cascos dos navios. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas no Planeta Mega será criada. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". O Planet Mega foi criado no sector [sector].";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
			break;

			case "swedish":
				$this->classname = "Mega Planet Artefakt";
				$this->description = "Detta Artefakt kommer att skapa en Mega Planet i en enda planet Realspace Sector. Planeten kommer att ha 400 våningar på teknologier, 60% av det högsta antal som stöds kolonister och 300% energi. Den fjärde råvara kommer att fartygsskrov. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar återfinns Mega Planet kommer att skapas. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Mega Planet har skapats inom sektorn [sector].";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
			break;

			default:
				$this->classname = "Mega Planet Artifact";
				$this->description = "This Artifact will create a Mega Planet in a single planet Realspace Sector.  The planet will have 400 levels on techs, 60% of the maximum number of supported colonists and 300% energy production.  The fourth commodity will be Ship Hulls.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found the Mega Planet will be created.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  The Mega Planet has been created in sector [sector].";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
			break;
		}
	}

	function sched_process_artifact($artifact_type)
	{
		global $db, $db_prefix, $adminexecuted;

		include ("globals/artifacts_sched.inc");

		if($adminexecuted == 1)
		{
			TextFlush ( "<b>" . ucwords($artifact_type) . " Artifact Added</b><br>");
		}

		$result2 = $db->Execute("SELECT count(sector_id) as total FROM {$db_prefix}universe WHERE sg_sector=0");
   		db_op_result($result2,__LINE__,__FILE__);
		$ratio = $result2->fields['total'] / 5000;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);

 		$totalpieces = ($this->pieces * floor($this->maximum_in_galaxy * $ratio)) - $res->fields['total'];
		for ($i = 1; $i <= $totalpieces; $i++)
		{
			artifacts_sched($artifact_type, $this->min_cloak, $this->max_cloak, $this->scoremax, $i);
		}
	}

	function found_artifact_piece($artifact_id)
	{
		global $db, $db_prefix, $playerinfo, $enable_spiral_galaxy, $universe_size, $spiral_galaxy_arms;

		include ("globals/insert_news.inc");
		include ("globals/create_sector_coordinates.inc");

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
			$updateit = $db->Execute("UPDATE {$db_prefix}artifacts SET on_port=0, on_planet_id=0, sector_id=0, player_id = $playerinfo[player_id] WHERE artifact_id=$artifact_id");
    		db_op_result($updateit,__LINE__,__FILE__);
    		$res->fields['total']++;
    	}

   		if($res->fields['total'] == $this->pieces)
   		{
			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$collisions = 0;
			# calculate the scale to use such that 
			# the max distance between 2 points will be
			# approx $universe_size.
			$scale = $universe_size / (4.0*pi());

			# compute the angle between arms
			$angle = deg2rad(360/$spiral_galaxy_arms);

			$sector = '';
			$collision = FALSE;
			while (TRUE) 
			{
				create_sector_coordinates();

				// Collision check
				$debug_query = $db->SelectLimit("SELECT sector_id from {$db_prefix}universe WHERE x=$sector[x] and y=$sector[y] and z=$sector[z] ", 1);
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();

				if ($debug_query->RecordCOunt() != 0) 
				{
					$collisions++;
				}
				else 
				{
					break;
				}
			}

			$stamp = date("Y-m-d H:i:s");
			$sectorname = $this->create_sector_number(chr(80 + $sector['spiral_arm']) . "1");

			$res = $db->Execute("INSERT INTO {$db_prefix}universe (zone_id, star_size, x, y, z, spiral_arm, port_type, creation_date, sector_name) VALUES (1, 1, $sector[x], $sector[y], $sector[z], $sector[spiral_arm], 'none', '$stamp', " . $db->qstr($sectorname) . ") ");
			db_op_result($res,__LINE__,__FILE__);
			$sector_id = $db->insert_id();
			$res->close();

			$debug_query = $db->Execute("INSERT INTO `aatrade_planets` (`sector_id`, `name`, `owner`, `team`, `base`, `defeated`, `fighter`, `fighter_normal`, `fighter_class`, `sensors`, `sensors_normal`, `beams`, `beams_normal`, `beam_class`, `torp_launchers`, `torp_launchers_normal`, `torp_class`, `shields`, `shields_normal`, `shield_class`, `jammer`, `jammer_normal`, `armor`, `armor_normal`, `armor_class`, `cloak`, `cloak_normal`, `sector_defense_weapons`, `sector_defense_weapons_normal`, `sector_defense_sensors`, `sector_defense_sensors_normal`, `sector_defense_cloak`, `sector_defense_cloak_normal`, `team_cash`, `colonists`, `organics`, `organics_planet`, `ore`, `ore_planet`, `goods`, `goods_planet`, `energy`, `energy_planet`, `fighters`, `torps`, `armor_pts`, `credits`, `max_credits`, `special_name`, `special_amount`, `special_goodevil`, `prod_special`, `prod_organics`, `prod_ore`, `prod_goods`, `prod_energy`, `prod_fighters`, `prod_torp`, `prod_research`, `prod_build`, `cargo_hull`, `cargo_power`, `mission_id`, `creation_date`, `last_visited`, `creator_id`, `use_age`, `hidden_credits`, `captured_countdown`, `persuasion_countdown`, `last_owner_rating`, `personality`) VALUES
										($sector_id, 'Mega Planet', $playerinfo[player_id], $playerinfo[team], 'Y', 'N', 400, 400, 'Planet_Fighter', 400, 400, 400, 400, 'Planet_Beam', 400, 400, 'Planet_Torpedo', 400, 400, 'Planet_Shield', 400, 400, 0, 0, 'Planet_Armor', 400, 400, 400, 400, 400, 400, 400, 400, 'Y', 0, 0, 1.00000, 0, 1.00000, 0, 1.00000, 0, 3.00000, 0, 0, 1, 0, 118956509006240, 'ship hulls', 0, 1, 0, 20, 20, 20, 20, 10, 10, 0, 0, 0, 0, 0, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 0, 0, 0, 0, 0, 0, 0);");
    		db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query->close();

			$findem = $db->Execute("SELECT sector_id FROM {$db_prefix}universe where sg_sector = 0 and sector_id > 3");
			$sector_list_total=$findem->RecordCount(); 
			$sector_list=$findem->GetArray();
			$findem->close();

			$numlinks = mt_rand(0,5);
			for ($j = 0; $j < $numlinks; $j++)
			{
				$randplay=mt_rand(0,($sector_list_total-1));
				$destination = $sector_list[$randplay]['sector_id'];

				$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES ($sector_id,$destination);");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
				$link_odds = mt_rand(0,100);
				if ($link_odds < 50)
				{
					$result4 = $db->Execute(" SELECT * FROM {$db_prefix}links where link_start=$destination");
					db_op_result($result4,__LINE__,__FILE__);

					$totalcount = $result4->RecordCount();
					$result4->close();
					if($totalcount <= 5){
						$debug_query = $db->Execute("INSERT INTO {$db_prefix}links (link_start, link_dest) VALUES ($destination,$sector_id);");
						db_op_result($debug_query,__LINE__,__FILE__);
						$debug_query->close();
					}
				}
			}
			$debug_query = $db->Execute("DELETE FROM {$db_prefix}navmap");
			db_op_result($debug_query,__LINE__,__FILE__);

			insert_news($this->classname . "|" . $playerinfo['character_name'], 1, "artifact");
   			$success = str_replace("[planet]" , "Mega Planet", $this->success);
   			$success = str_replace("[sector]" , $sectorname, $success);
   			return $success;
   		}
   		else
   		{
   			$incomplete = str_replace("[pieces]", $res->fields['total'], $this->incomplete);
   			$left = $this->pieces - $res->fields['total'];
   			$incomplete = str_replace("[left]", $left, $incomplete);
  			if($left == 1)
   			{
   				$incomplete = str_replace("[piece]", $this->singular, $incomplete);
   				$pieces = $this->singular;
   			}
   			else
   			{
   				$incomplete = str_replace("[piece]", $this->plural, $incomplete);
    			$pieces = $this->plural;
   			}
			insert_news($this->classname . "|" . $playerinfo['character_name'] . "|$left|$pieces", 1, "artifactfound");
   			return $incomplete;
   		}
	}

	function create_sector_number($prefix)
	{
		global $db, $db_prefix;

		$alphanumeric = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		$newname = $prefix . AAT_substr($alphanumeric, mt_rand(26, 35), 1) . AAT_substr($alphanumeric, mt_rand(0, 35), 1) . AAT_substr($alphanumeric, mt_rand(26, 35), 1) . AAT_substr($alphanumeric, mt_rand(0, 35), 1) . AAT_substr($alphanumeric, mt_rand(0, 35), 1);
		$sector_check = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr($newname), 1);
		db_op_result($sector_check,__LINE__,__FILE__);

		if($sector_check->RecordCount() != 0)
		{
			create_sector_number($prefix);
		} 
		else 
		{
			return $newname;
		}
	}

	function preprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo;
	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo;
	}
}

?>