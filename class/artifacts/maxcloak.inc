<?php
class maxcloak
{
	var $class = "maxcloak";
	var $pieces = 10;
	var $min_cloak = 200; // Cloak value of each artifact piece
	var $max_cloak = 250; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 3; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.
	var $cloak_limit = 400;  // The max allowed value to upgrade cloak

	function maxcloak()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Max varjatud Tehis";
				$this->description = "See Tehis lisab Max varjatud Device iga üksiku laeva. Käesolev seade aitab suurendada laevade Cloaking Tech maksimaalse lubatud laeva klass maksimaalselt 400. Kui teie varjatud on kahjustatud erinevus maha Max varjatud väärtus. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud saate valida laeva versiooniuuenduse kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->upgrade = "Install Device";
				$this->noship = "Sa ei oma laeva.";
				$this->newcloak = "Väljavalitud laev on nüüd Max varjatud seade.";
			break;

			case "french":
				$this->classname = "Max Cloak Artefact";
				$this->description = "Cet artefact va ajouter un max Cloak Device tout navire à simple. Ce dispositif va augmenter les navires Cloaking Tech pour le maximum autorisé pour cette classe de navire à un maximum de 400. Si votre manteau est endommagé la différence sera déduite de la valeur Cloak Max. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez sélectionner le navire pour mettre à niveau grâce à la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->upgrade = "Installation de périphériques";
				$this->noship = "Vous ne possédez pas ce navire.";
				$this->newcloak = "Le navire sélectionné a maintenant un appareil Max capes.";
			break;

			case "german":
				$this->classname = "Max Umhang Artefakt";
				$this->description = "Dieses Artefakt wird fügen Sie ein Max Cloak Device jedem einzelnen Schiff. Dieses Gerät wird sich die Schiffe Cloaking Tech, um die maximale Klasse für dieses Schiff zu einem Höchstbetrag von 400 erlaubt. Wenn Ihr Mantel ist der Unterschied beschädigt wird vom Max-Umhang abgezogen werden müssten. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie das Schiff durch das Artefakt Liste aktualisieren-Befehl auszuwählen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->upgrade = "Gerät installieren";
				$this->noship = "Sie nicht besitzen, dass von Schiffen.";
				$this->newcloak = "Die ausgewählten Schiff hat nun eine Max Cloak Device.";
			break;

			case "italian":
				$this->classname = "Max Mantello Artifact";
				$this->description = "Questo artefatto si aggiunge un dispositivo Max Mantello di una nave unica. Questo dispositivo aumenta le navi Cloaking Tech al massimo consentito per quella classe di navi per un massimo di 400. Se il mantello è danneggiato, la differenza sarà dedotta dal valore max mantello. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile selezionare la nave per l&#39;aggiornamento tramite il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->upgrade = "Installare periferiche";
				$this->noship = "Non è proprio quella nave.";
				$this->newcloak = "La nave selezionata è ora di un dispositivo Max mantello.";
			break;

			case "spanish":
				$this->classname = "Max Cloak Artefacto";
				$this->description = "Este artefacto se agrega un dispositivo de máxima Capa de un buque único. Este dispositivo se incrementará los barcos de encubrimiento del Tech para el máximo permitido para esa clase de buques a un máximo de 400. Si la capa se daña la diferencia se deducirá de la Capa de máximo valor. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el buque para actualizar a través del comando Lista de Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->upgrade = "Instalación de dispositivos";
				$this->noship = "Usted no posee ese buque.";
				$this->newcloak = "El barco elegido ahora tiene un dispositivo de Max Cloak.";
			break;

			case "albanian":
				$this->classname = "Max mantel Objekti";
				$this->description = "Kjo Objekti do të shtojë një mantel Device Max çdo anije të vetme. Kjo pajisje do të rritet anijet Cloaking Teknike për maksimale e lejuar për atë klasë anija në një maksimum prej 400. Nëse mantel juaj është dëmtuar ndryshimi do të zbritet nga vlera e gunë Max. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni anije për të përmirësuar përmes komandës Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->upgrade = "Device Install";
				$this->noship = "Ju nuk zotërojnë atë anije.";
				$this->newcloak = "Anija zgjedhur tani ka një mantel Device Max.";
			break;

			case "catalan":
				$this->classname = "Max Cloak Artefacte";
				$this->description = "Aquest artefacte es afegeix un dispositiu de màxima Capa d&#39;un vaixell únic. Aquest dispositiu es incrementarà els vaixells d&#39;encobriment del Tech per al màxim permès per a aquesta classe de vaixells a un màxim de 400. Si la capa es danya la diferència es deduirà de la Capa d&#39;màxim valor. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el vaixell per actualitzar a través de la comanda Llista de Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->upgrade = "Instal lació de dispositius";
				$this->noship = "No té aquest vaixell.";
				$this->newcloak = "El vaixell escollit ara té un dispositiu de Max Cloak.";
			break;

			case "danish":
				$this->classname = "Max Cloak Artifact";
				$this->description = "Dette Artifact vil tilføje en Max Cloak Enhed et enkelt skib. Denne enhed vil øge de skibe Tilsløring Tech til det maksimalt tilladte for det pågældende skib klasse til maksimalt 400. Hvis din kappe er beskadiget forskellen vil blive trukket fra Max Cloak værdi. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet, kan du vælge at skibet for at opgradere gennem Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->upgrade = "Install Device";
				$this->noship = "Du behøver ikke selv at skibet.";
				$this->newcloak = "Den valgte Skibet har nu en Max Cloak Enhed.";
			break;

			case "dutch":
				$this->classname = "Max Cloak Artifact";
				$this->description = "Dit Artefact voegt een Max Cloak apparaat een enkel schip. Dit apparaat zal de schepen Cloaking Tech aan de maximaal toegestane voor dat schip klasse tot een maximum van 400. Als uw mantel is het verschil beschadigd zal worden afgetrokken van het Max Cloak waarde. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u het schip te upgraden via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->upgrade = "Installeer Device";
				$this->noship = "Je hoeft niet zelf dat schip.";
				$this->newcloak = "De geselecteerde schip heeft nu een Max Cloak apparaat.";
			break;

			case "finnish":
				$this->classname = "Max Viitta Teos";
				$this->description = "Tämä Artifact lisää Max Viitta Laitteen yksittäisen aluksen. Tämä laite lisää aluksia peittäminen Tech on enimmillään kyseisen aluksen luokan enintään 400. Jos viitta on vaurioitunut erotus vähennetään enintään Viitta arvoa. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita aluksen päivittää kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->upgrade = "Asenna laite";
				$this->noship = "Sinulla ei ole, että alus.";
				$this->newcloak = "Valitun alus on nyt enintään Viitta laite.";
			break;

			case "indonesian":
				$this->classname = "Max Jubah artifak";
				$this->description = "Artefak ini akan menambahkan Max Jubah Device setiap satu kapal. Perangkat ini akan meningkatkan Cloaking Tech untuk kapal-kapal maksimum yang diperbolehkan untuk kelas kapal maksimum 400. Jika Anda rusak jubah perbedaan akan dipotong dari nilai Jubah Max. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat memilih untuk meng-upgrade kapal melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->upgrade = "Install Device";
				$this->noship = "Anda tidak memiliki kapal itu.";
				$this->newcloak = "Kapal yang dipilih sekarang memiliki Jubah Max Device.";
			break;

			case "norwegian":
				$this->classname = "Max Cloak Artifact";
				$this->description = "Dette Artifact vil legge til en Max Cloak Enhet ett enkelt skip. Denne enheten vil øke skip Maskering Tech til maksimalt for at skipet klassen til maksimalt 400. Hvis kappen er skadet forskjellen vil bli trukket fra Max Cloak verdi. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet kan du velge å oppgradere skipet gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->upgrade = "Install Device";
				$this->noship = "Du eier ikke at skipet.";
				$this->newcloak = "Den valgte skipet har nå et Maks Cloak enhet.";
			break;

			case "portuguese":
				$this->classname = "Max Cloak Artefato";
				$this->description = "Este artefato irá adicionar um dispositivo Max Cloak qualquer único navio. Este dispositivo irá aumentar os navios Cloaking Tech para o máximo permitido para essa classe de navio até um máximo de 400. Se o seu manto está danificado, a diferença será deduzida do valor Cloak máx. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode selecionar o navio a atualização através do comando Lista Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->upgrade = "Instale o dispositivo";
				$this->noship = "Você não é dono do navio que.";
				$this->newcloak = "O navio selecionado agora tem um máximo de dispositivos Cloak.";
			break;

			case "swedish":
				$this->classname = "Max Cloak Artefakt";
				$this->description = "Detta Artefakt kommer att lägga en Max Cloak Device något enskilt fartyg. Denna enhet kommer att öka fartygen Cloaking Tech till den maximalt tillåtna för detta fartyg klass till högst 400. Om din kappa är skadad skillnaden kommer att dras från Max mantel värde. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns kan du välja fartyget att uppgradera genom den fiktiva List kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->upgrade = "Installera Device";
				$this->noship = "Som du inte äger fartyget.";
				$this->newcloak = "De utvalda fartyg har nu en Max mantel Device.";
			break;

			default:
				$this->classname = "Max Cloak Artifact";
				$this->description = "This Artifact will add a Max Cloak Device any single ship.  This device will increase the ships Cloaking Tech to the maximum allowed for that ship class to a maximum of 400.  If your cloak is damaged the difference will be deducted from the Max Cloak value.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select the ship to upgrade through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->upgrade = "Install Device";
				$this->noship = "You do not own that ship.";
				$this->newcloak = "The selected ship now has a Max Cloak Device.";
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
		global $db, $db_prefix, $playerinfo;

		include ("globals/insert_news.inc");

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
 			insert_news($this->classname . "|" . $playerinfo['character_name'], 1, "artifact");

   			return $this->success;
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

	function preprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo, $max_tech_level, $langdir;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		include("languages/$langdir/lang_common.inc");
		include("languages/$langdir/lang_report.inc");

		for($iz=0; $iz <= 900; $iz++){
			if($iz < floor($max_tech_level/4))
				$colorarray[$iz] = "#FFADAD";
			if($iz >= floor($max_tech_level/4) and $iz < (floor($max_tech_level/4) * 2))
				$colorarray[$iz] = "#FFFF00";
			if($iz >= (floor($max_tech_level/4) * 2) and $iz < (floor($max_tech_level/4) * 3))
				$colorarray[$iz] = "#0CD616";
			if($iz >= (floor($max_tech_level/4) * 3))
				$colorarray[$iz] = "#ffffff";
		}

		$result  = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE player_id=$playerinfo[player_id] order by class ASC");
		db_op_result($result,__LINE__,__FILE__);

		$shipcount = 0;
		while (!$result->EOF) {
			$member = $result->fields;

			$debug_query = $db->SelectLimit("SELECT * FROM {$db_prefix}ship_types WHERE type_id=$member[class]", 1);
			db_op_result($debug_query,__LINE__,__FILE__);
			$classstuff = $debug_query->fields;
			$ship_id[$shipcount] = $member['ship_id'];
			$hull[$shipcount] = $member['hull'];
			$engines[$shipcount] = $member['engines'];
			$power[$shipcount] = $member['power'];
			$fighter[$shipcount] = $member['fighter'];
			$sensors[$shipcount] = $member['sensors'];
			$armor[$shipcount] = $member['armor'];
			$shields[$shipcount] = $member['shields'];
			$beams[$shipcount] = $member['beams'];
			$torps[$shipcount] = $member['torp_launchers'];
			$cloak[$shipcount] = $member['cloak'];
			$ecm[$shipcount] = $member['ecm'];
			$shipname[$shipcount] = $member['name'];
			$shipclassname[$shipcount] = $classstuff['name'];
			$maxcloak[$shipcount] = ($classstuff['maxcloak'] <= $this->cloak_limit) ? $classstuff['maxcloak'] : $this->cloak_limit;
			$memberclass[$shipcount] = $member['class'];
			$colorhull[$shipcount] = $colorarray[$member['hull']];
			$colorengines[$shipcount] = $colorarray[$member['engines']];
			$colorpower[$shipcount] = $colorarray[$member['power']];
			$colorfighter[$shipcount] = $colorarray[$member['fighter']];
			$colorsensors[$shipcount] = $colorarray[$member['sensors']];
			$colorarmor[$shipcount] = $colorarray[$member['armor']];
			$colorshields[$shipcount] = $colorarray[$member['shields']];
			$colorbeams[$shipcount] = $colorarray[$member['beams']];
			$colortorps[$shipcount] = $colorarray[$member['torp_launchers']];
			$colorcloak[$shipcount] = $colorarray[$member['cloak']];
			$colorecm[$shipcount] = $colorarray[$member['ecm']];
			$shipcount++;
			$result->MoveNext();
		}

		$output = "<table width=\"90%\" border=\"1\" cellspacing=\"0\" cellpadding=\"4\" align=\"center\">
  <tr>
    <td bgcolor=\"#000000\" valign=\"top\" align=\"center\" colspan=2>
		<table cellspacing = \"0\" cellpadding = \"0\" border = \"0\" width=\"100%\">
<tr><td>
	<div align=center>
	<h3><font color=\"white\"><B>$team_name</B>
	<br><font size=2><i>" . $this->description . "</i></font></H3>
	</div> 
	<table border=1 cellspacing=0 cellpadding=0 width=\"100%\" align=center>
	<tr bgcolor=\"#585980\">
	<td align=\"center\"><font color=\"white\"><B>$l_ships</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_hull</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_engines</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_power</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_fighter</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_sensors</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_armor</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_shields</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_beams</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_torp_launch</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_cloak</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>$l_ecm</b></font></td>
	<td align=\"center\"><font color=\"white\"><B>" . $this->upgrade . "</b></font></td>

	</tr><tr bgcolor=#000000>";

	for($i = 0; $i < $shipcount; $i++){
		$output .= "<td align=\"center\" valign=\"middle\">";

		$output .= "<font face=\"verdana\" size=\"1\" color=\"#9ff4f8\"><b>SS $shipname[$i]</b></font><br>
		<font face=\"verdana\" size=\"1\" color=\"#FFD161\"><b>$shipclassname[$i]</b></font>
		<font face=\"verdana\" size=\"1\" color=\"#ffffff\"><b> - </b></font>
		<font face=\"verdana\" size=\"1\" color=\"#ffffff\"><b>$memberclass[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorhull[$i]\"><b>$hull[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorengines[$i]\"><b>$engines[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorpower[$i]\"><b>$power[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorfighter[$i]\"><b>$fighter[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorsensors[$i]\"><b>$sensors[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorarmor[$i]\"><b>$armor[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorshields[$i]\"><b>$shields[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorbeams[$i]\"><b>$beams[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colortorps[$i]\"><b>$torps[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorcloak[$i]\"><b>$cloak[$i]</b></font></td>
		<td align=\"center\"><font color=\"$colorecm[$i]\"><b>$ecm[$i]</b></font></td>
		<td align=\"center\"><b><a href=\"artifact_process.php?process_type=post&artifact=$artifact_type&ship_id=$ship_id[$i]\">" . $this->upgrade . " (" . $maxcloak[$i] . ")</a></b></td>";
		$output .= "</tr><tr bgcolor=#000000>";
	}

	$output .= "</tr></table>

</td></tr>
<tr><td align=\"center\"><br>$l_global_mmenu<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>";
		return $output;

	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo, $l_global_mmenu;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

	  	$ship_id = $_GET['ship_id'];

		$result  = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE player_id=$playerinfo[player_id] and ship_id=$ship_id");
		db_op_result($result,__LINE__,__FILE__);
		if($result->RecordCount() == 1)
		{
			$result  = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=1 WHERE player_id=$playerinfo[player_id] and ship_id=$ship_id and class='dev_maxcloak'");
			db_op_result($result,__LINE__,__FILE__);

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->newcloak . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
			return $output;
		}
		else
		{
			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->noship . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
			return $output;
		}
	}
}

?>