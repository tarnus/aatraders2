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
				$this->description = "See Tehis lisab Max varjatud Device iga �ksiku laeva. K�esolev seade aitab suurendada laevade Cloaking Tech maksimaalse lubatud laeva klass maksimaalselt 400. Kui teie varjatud on kahjustatud erinevus maha Max varjatud v��rtus. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud saate valida laeva versiooniuuenduse kaudu Tehis nimekiri k�sk. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". V�ite kasutada seda Artefakti igal ajal Tehis nimekiri lehek�ljel.";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->upgrade = "Install Device";
				$this->noship = "Sa ei oma laeva.";
				$this->newcloak = "V�ljavalitud laev on n��d Max varjatud seade.";
			break;

			case "french":
				$this->classname = "Max Cloak Artefact";
				$this->description = "Cet artefact va ajouter un max Cloak Device tout navire � simple. Ce dispositif va augmenter les navires Cloaking Tech pour le maximum autoris� pour cette classe de navire � un maximum de 400. Si votre manteau est endommag� la diff�rence sera d�duite de la valeur Cloak Max. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont trouv�s, vous pouvez s�lectionner le navire pour mettre � niveau gr�ce � la commande Liste Artefact. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". Vous pouvez utiliser cet objet � tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->upgrade = "Installation de p�riph�riques";
				$this->noship = "Vous ne poss�dez pas ce navire.";
				$this->newcloak = "Le navire s�lectionn� a maintenant un appareil Max capes.";
			break;

			case "german":
				$this->classname = "Max Umhang Artefakt";
				$this->description = "Dieses Artefakt wird f�gen Sie ein Max Cloak Device jedem einzelnen Schiff. Dieses Ger�t wird sich die Schiffe Cloaking Tech, um die maximale Klasse f�r dieses Schiff zu einem H�chstbetrag von 400 erlaubt. Wenn Ihr Mantel ist der Unterschied besch�digt wird vom Max-Umhang abgezogen werden m�ssten. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle Teile gefunden sind, k�nnen Sie das Schiff durch das Artefakt Liste aktualisieren-Befehl auszuw�hlen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie k�nnen dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->upgrade = "Ger�t installieren";
				$this->noship = "Sie nicht besitzen, dass von Schiffen.";
				$this->newcloak = "Die ausgew�hlten Schiff hat nun eine Max Cloak Device.";
			break;

			case "italian":
				$this->classname = "Max Mantello Artifact";
				$this->description = "Questo artefatto si aggiunge un dispositivo Max Mantello di una nave unica. Questo dispositivo aumenta le navi Cloaking Tech al massimo consentito per quella classe di navi per un massimo di 400. Se il mantello � danneggiato, la differenza sar� dedotta dal valore max mantello. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, � possibile selezionare la nave per l&#39;aggiornamento tramite il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". � possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->upgrade = "Installare periferiche";
				$this->noship = "Non � proprio quella nave.";
				$this->newcloak = "La nave selezionata � ora di un dispositivo Max mantello.";
			break;

			case "spanish":
				$this->classname = "Max Cloak Artefacto";
				$this->description = "Este artefacto se agrega un dispositivo de m�xima Capa de un buque �nico. Este dispositivo se incrementar� los barcos de encubrimiento del Tech para el m�ximo permitido para esa clase de buques a un m�ximo de 400. Si la capa se da�a la diferencia se deducir� de la Capa de m�ximo valor. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el buque para actualizar a trav�s del comando Lista de Artefacto. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la p�gina Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->upgrade = "Instalaci�n de dispositivos";
				$this->noship = "Usted no posee ese buque.";
				$this->newcloak = "El barco elegido ahora tiene un dispositivo de Max Cloak.";
			break;

			case "albanian":
				$this->classname = "Max mantel Objekti";
				$this->description = "Kjo Objekti do t� shtoj� nj� mantel Device Max �do anije t� vetme. Kjo pajisje do t� rritet anijet Cloaking Teknike p�r maksimale e lejuar p�r at� klas� anija n� nj� maksimum prej 400. N�se mantel juaj �sht� d�mtuar ndryshimi do t� zbritet nga vlera e gun� Max. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur ju mund t� zgjidhni anije p�r t� p�rmir�suar p�rmes komand�s Lista Objekti. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ". Ju mund t� p�rdorni k�t� Objekti n� �do koh� nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->upgrade = "Device Install";
				$this->noship = "Ju nuk zot�rojn� at� anije.";
				$this->newcloak = "Anija zgjedhur tani ka nj� mantel Device Max.";
			break;

			case "catalan":
				$this->classname = "Max Cloak Artefacte";
				$this->description = "Aquest artefacte es afegeix un dispositiu de m�xima Capa d&#39;un vaixell �nic. Aquest dispositiu es incrementar� els vaixells d&#39;encobriment del Tech per al m�xim perm�s per a aquesta classe de vaixells a un m�xim de 400. Si la capa es danya la difer�ncia es deduir� de la Capa d&#39;m�xim valor. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el vaixell per actualitzar a trav�s de la comanda Llista de Artefacte. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vost� pot usar aquest artefacte en qualsevol moment des de la p�gina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->upgrade = "Instal laci� de dispositius";
				$this->noship = "No t� aquest vaixell.";
				$this->newcloak = "El vaixell escollit ara t� un dispositiu de Max Cloak.";
			break;

			case "danish":
				$this->classname = "Max Cloak Artifact";
				$this->description = "Dette Artifact vil tilf�je en Max Cloak Enhed et enkelt skib. Denne enhed vil �ge de skibe Tilsl�ring Tech til det maksimalt tilladte for det p�g�ldende skib klasse til maksimalt 400. Hvis din kappe er beskadiget forskellen vil blive trukket fra Max Cloak v�rdi. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle brikker er fundet, kan du v�lge at skibet for at opgradere gennem Artifact List kommando. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->upgrade = "Install Device";
				$this->noship = "Du beh�ver ikke selv at skibet.";
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
				$this->description = "T�m� Artifact lis�� Max Viitta Laitteen yksitt�isen aluksen. T�m� laite lis�� aluksia peitt�minen Tech on enimmill��n kyseisen aluksen luokan enint��n 400. Jos viitta on vaurioitunut erotus v�hennet��n enint��n Viitta arvoa. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset l�ytyy voit valita aluksen p�ivitt�� kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit k�ytt�� t�t� artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->upgrade = "Asenna laite";
				$this->noship = "Sinulla ei ole, ett� alus.";
				$this->newcloak = "Valitun alus on nyt enint��n Viitta laite.";
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
				$this->description = "Dette Artifact vil legge til en Max Cloak Enhet ett enkelt skip. Denne enheten vil �ke skip Maskering Tech til maksimalt for at skipet klassen til maksimalt 400. Hvis kappen er skadet forskjellen vil bli trukket fra Max Cloak verdi. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet kan du velge � oppgradere skipet gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand n�r som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->upgrade = "Install Device";
				$this->noship = "Du eier ikke at skipet.";
				$this->newcloak = "Den valgte skipet har n� et Maks Cloak enhet.";
			break;

			case "portuguese":
				$this->classname = "Max Cloak Artefato";
				$this->description = "Este artefato ir� adicionar um dispositivo Max Cloak qualquer �nico navio. Este dispositivo ir� aumentar os navios Cloaking Tech para o m�ximo permitido para essa classe de navio at� um m�ximo de 400. Se o seu manto est� danificado, a diferen�a ser� deduzida do valor Cloak m�x. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas voc� pode selecionar o navio a atualiza��o atrav�s do comando Lista Artefato. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". Voc� pode usar esse artefato, a qualquer momento a partir da p�gina Lista de Artefato.";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->upgrade = "Instale o dispositivo";
				$this->noship = "Voc� n�o � dono do navio que.";
				$this->newcloak = "O navio selecionado agora tem um m�ximo de dispositivos Cloak.";
			break;

			case "swedish":
				$this->classname = "Max Cloak Artefakt";
				$this->description = "Detta Artefakt kommer att l�gga en Max Cloak Device n�got enskilt fartyg. Denna enhet kommer att �ka fartygen Cloaking Tech till den maximalt till�tna f�r detta fartyg klass till h�gst 400. Om din kappa �r skadad skillnaden kommer att dras fr�n Max mantel v�rde. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar finns kan du v�lja fartyget att uppgradera genom den fiktiva List kommandot. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan anv�nda denna artefakt som helst fr�n den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->upgrade = "Installera Device";
				$this->noship = "Som du inte �ger fartyget.";
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