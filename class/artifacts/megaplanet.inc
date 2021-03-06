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
				$this->description = "See Tehis loob Mega Planet �he planeedi Realspace sektor. Planeet on 400 tasemetega techs 60% maksimaalse arvu toetas kolonistide ja 300% energia tootmiseks. Neljas kaup on laeva kere. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud Mega Planet luuakse. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". Mega planeet on loodud sektoris [sector].";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
			break;

			case "french":
				$this->classname = "Mega Planet Artefact";
				$this->description = "Cet artefact se cr�er une plan�te en un seul Mega plan�te REALSPACE Secteur. La plan�te aura 400 niveaux sur les techniciens, 60% du nombre maximum de colons soutenus et la production de 300% d&#39;�nergie. Le quatri�me produit sera coques de navires. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont a trouv� la plan�te Mega sera cr��. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". The Planet Mega a �t� cr�� dans le secteur [sector].";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
			break;

			case "german":
				$this->classname = "Mega Planet Artefakt";
				$this->description = "Dieses Artefakt wird ein Mega Planet in einem einzigen Planeten Realspace Sektor. Der Planet wird 400 Stufen auf Techniker, 60% der maximalen Anzahl der unterst�tzten Siedler und 300% der Energieerzeugung. Die vierte Ware wird Schiffsr�mpfen. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle St�cke fanden die Mega Planeten geschaffen werden. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Das Mega-Planet wurde im Sektor geschaffen [sector].";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
			break;

			case "italian":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Artefatto questo creer� un Planet Mega in un pianeta unico settore mondo fisico. Il pianeta avranno 400 livelli su tech, il 60% del numero massimo di coloni sostenuto e 300% la produzione di energia. La merce quarto saranno gli scafi delle navi. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi si trovano il Planet Mega sar� creato. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". Il Mega Planet � stato creato nel settore [sector].";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
			break;

			case "spanish":
				$this->classname = "Mega Planet Artefacto";
				$this->description = "Este artefacto crear� un planeta Mega en un solo planeta espacio real del sector. El planeta tendr� 400 niveles de t�cnicos, el 60% del n�mero m�ximo de colonos apoy� la producci�n de energ�a y 300%. La mercanc�a de sesiones se cascos de los barcos. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran el planeta Mega ser� creado. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". El planeta Mega se ha creado en el sector [sector].";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
			break;

			case "albanian":
				$this->classname = "Mega Planet Objekti";
				$this->description = "Kjo Objekti i do t� krijoj� nj� Planeti Mega n� nj� t� vetme Sektorin e planetit Realspace. Planet do t� ket� 400 nivelet m� techs, 60% t� numrit maksimal t� kolon� mb�shtetur dhe 300% t� prodhimit t� energjis�. Mall i kat�rt do t� jet� Hulls anijes. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur Planeti Mega do t� jet� krijuar. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ". Planet Mega �sht� krijuar n� sektorin [sector].";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
			break;

			case "catalan":
				$this->classname = "Mega Planet Artefacte";
				$this->description = "Aquest artefacte crear� un planeta Mega en un sol planeta espai real del sector. El planeta tindr� 400 nivells de t�cnics, el 60% del nombre m�xim de colons va recolzar la producci� d&#39;energia i 300%. La mercaderia de sessions es cascs de vaixells. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben el planeta Mega ser� creat. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". El planeta Mega s&#39;ha creat en el sector [sector].";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
			break;

			case "danish":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Dette Artifact vil skabe et Mega Planet i en enkelt planet Realspace Sector. Planeten vil have 400 niveauer p� techs, 60% af det maksimale antal st�ttede kolonisterne og 300% energi produktion. Den fjerde r�vare vil blive skibsskrog. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle stykker er fundet Mega Planet vil blive oprettet. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". The Mega Planet er blevet oprettet i sektor [sector].";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
			break;

			case "dutch":
				$this->classname = "Mega Planet Artifact";
				$this->description = "Artefact Dit zal leiden tot een Mega Planet in een enkele planeet Realspace Sector. De planeet zal hebben 400 niveaus op techs, 60% van het maximale aantal ondersteunde kolonisten en 300% energie productie. De vierde grondstoffen zal worden scheepsrompen. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn de Mega Planet gevonden zal worden gecre�erd. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". De Mega Planet is opgericht in de sector [sector].";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
			break;

			case "finnish":
				$this->classname = "Mega Planet Teos";
				$this->description = "T�m� Teos luo Mega Planet on yksi planeetan Realspace Sector. Planet on 400 tasoa tech, 60% enimm�ism��r�n tukea uudisasukkaita ja 300% energian tuotannosta. Nelj�s hy�dyke on Ship runkoa. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset ovat l�yt�neet Mega Planet luodaan. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Mega Planet on luotu alalla [sector].";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
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
				$this->description = "Dette Artifact vil opprette en Mega planet i et enkelt planet Realspace sektor. Planeten vil ha 400 niv� p� teknikken, 60% av det maksimale antallet st�ttede kolonister og 300% energiproduksjon. Den fjerde varen vil bli Ship Skrog. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet Mega Planet vil bli opprettet. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". The Mega Planet har blitt opprettet i sektor [sector].";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
			break;

			case "portuguese":
				$this->classname = "Mega Planet Artefato";
				$this->description = "Este artefato vai criar um Planet Mega num �nico planeta Realspace Setor. O planeta ter� 400 em n�veis t�cnicos, 60% do n�mero m�ximo de colonos apoiados e 300% da produ��o de energia. A mercadoria ser� quarta cascos dos navios. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas no Planeta Mega ser� criada. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". O Planet Mega foi criado no sector [sector].";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
			break;

			case "swedish":
				$this->classname = "Mega Planet Artefakt";
				$this->description = "Detta Artefakt kommer att skapa en Mega Planet i en enda planet Realspace Sector. Planeten kommer att ha 400 v�ningar p� teknologier, 60% av det h�gsta antal som st�ds kolonister och 300% energi. Den fj�rde r�vara kommer att fartygsskrov. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar �terfinns Mega Planet kommer att skapas. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Mega Planet har skapats inom sektorn [sector].";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
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