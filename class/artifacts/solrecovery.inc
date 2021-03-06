<?php
class solrecovery
{
	var $class = "solrecovery";
	var $pieces = 1;
	var $min_cloak = 0; // Cloak value of each artifact piece
	var $max_cloak = 0; // Maximum Cloak value of each artifact piece
	var $scoremax = 100000; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $scoremax_text = "100,000"; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 40; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function solrecovery()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Sol taastamise Tehis";
				$this->description = "See Tehis loob Wormhole mis tahes sektoris (realspace v�i SG), et Sol ja transpordi sa seal koheselt. Kui sinu skoor j�uab " . $this->scoremax_text . " te ei n�e v�i pikap see artefaktist. Kui teil on kaasas �ks kaotate seda. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud saate luua Wormhole kaudu Tehis nimekiri k�sk. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". V�ite kasutada seda Artefakti igal ajal Tehis nimekiri lehek�ljel.";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->upgrade = "Upgrade varjatud";
			break;

			case "french":
				$this->classname = "Sol de r�cup�ration d&#39;artefact";
				$this->description = "Cet artefact va cr�er un trou de ver de tous les secteurs (REALSPACE ou SG) � Sol et le transport de vous y instantan�ment. Une fois votre score atteint " . $this->scoremax_text . " vous ne serez pas en mesure de voir ou de ramassage cet artefact. Si vous transportez celle que vous allez perdre. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont trouv�s, vous pouvez cr�er le trou de ver � travers la commande Liste Artefact. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". Vous pouvez utiliser cet objet � tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->upgrade = "Upgrade Cloak";
			break;

			case "german":
				$this->classname = "Sol Recovery Artefakt";
				$this->description = "Dieses Artefakt wird ein Wurmloch von jedem Sektor (realspace oder SG) bis Sol erstellen und transportieren Sie es sofort. Nachdem Sie Ihre G�ste erreicht " . $this->scoremax_text . " Sie werden nicht in der Lage sein zu sehen, oder dieses Artefakt Pickup. Wenn Sie sich tragen Sie ein, wird es verlieren. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle Teile gefunden sind, k�nnen Sie das Wurmloch durch das Artefakt Liste Befehl zu erstellen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie k�nnen dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->upgrade = "Upgrade Cloak";
			break;

			case "italian":
				$this->classname = "Sol Recovery Artifact";
				$this->description = "Artefatto questo creer� un Wormhole da qualsiasi settore (mondo fisico o SG) a Sol e trasporti l� all&#39;istante. Una volta che il tuo punteggio raggiunge " . $this->scoremax_text . " non sar� in grado di vedere o pick-up questo artefatto. Se si stanno realizzando quello che la perder�. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, � possibile creare il Wormhole tramite il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". � possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->upgrade = "Upgrade Cloak";
			break;

			case "spanish":
				$this->classname = "Sol de recuperaci�n Artefacto";
				$this->description = "Este artefacto crear� un agujero de gusano, de cualquier sector (espacio real o SG) de Sol y de transporte que hay al instante. Una vez que el marcador llega a " . $this->scoremax_text . " usted no ser� capaz de ver o de recolecci�n de este artefacto. Si est� llevando a que usted perder�. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede crear a trav�s del agujero de gusano el comando Lista Artefacto. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la p�gina Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->upgrade = "Capa de actualizaci�n";
			break;

			case "albanian":
				$this->classname = "Sol Recovery Objekti";
				$this->description = "Kjo Objekti i do t� krijoj� nj� Wormhole nga �do sektori (realspace ose SG) n� Sol dhe transportit ju atje menj�her�. Pasi Rezultati juaj arrin " . $this->scoremax_text . " ju nuk do t� jet� n� gjendje p�r t� par� ose p�rmir�sim k�t� Objekti. Qoft� se keni me vete nj� nga ju do t� humbni at�. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur ju mund t� krijoni Wormhole p�rmes komand�s Lista Objekti. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = " " . $this->pieces . " cop� " . $this->classname . ". Ju mund t� p�rdorni k�t� Objekti n� �do koh� nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->upgrade = "Upgrade mantel";
			break;

			case "catalan":
				$this->classname = "Sol de recuperaci� Artefacte";
				$this->description = "Aquest artefacte crear� un forat de cuc, de qualsevol sector (espai real o SG) de Sol i de transport que hi ha a l&#39;instant. Una vegada que el marcador arriba a " . $this->scoremax_text . " vost� no ser� capa� de veure o de recollida d&#39;aquest artefacte. Si est� duent a que vost� perdr�. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es pot crear a trav�s del forat de cuc la comanda Llista Artefacte. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vost� pot usar aquest artefacte en qualsevol moment des de la p�gina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->upgrade = "Capa d&#39;actualitzaci�";
			break;

			case "danish":
				$this->classname = "Sol Recovery Artifact";
				$this->description = "Dette Artifact vil skabe et ormehul fra alle sektorer (realspace eller SG) til Sol og transport dig der straks. N�r din score n�r " . $this->scoremax_text . " vil du ikke kunne se eller pickup denne artefakt. Hvis du medbringer en du vil miste det. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle brikker er fundet kan du oprette Ormehul gennem Artifact List kommando. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->upgrade = "Upgrade Cloak";
			break;

			case "dutch":
				$this->classname = "Sol Recovery Artifact";
				$this->description = "Artefact Dit zal leiden tot een Wormhole uit alle sectoren (realspace of SG) naar Sol en daar vervoer u direct. Zodra uw score bereikt " . $this->scoremax_text . " u zult niet in staat zijn om te zien of dit artefact pickup. Als je bij je hebt die je zal het verliezen. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u het wormgat te cre�ren door het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->upgrade = "Upgrade Cloak";
			break;

			case "finnish":
				$this->classname = "Sol Recovery Teos";
				$this->description = "T�m� Teos luo Madonreik� mist� tahansa alalla (realspace tai SG) on Sol ja liikenne siell� hetkess�. Kun pisteet saavuttaa " . $this->scoremax_text . " et voi n�hd� tai pickup t�m�n artefakti. Jos olet, joilla on yksi menet�t sen. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset l�ytyy voit luoda Madonreik� kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit k�ytt�� t�t� artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->upgrade = "Upgrade Viitta";
			break;

			case "indonesian":
				$this->classname = "Sol Pemulihan artifak";
				$this->description = "Artefak ini akan menciptakan sebuah lubang cacing dari sektor apapun (realspace atau SG) untuk Sol dan transportasi Anda ke sana langsung. Setelah Anda mencapai skor " . $this->scoremax_text . " Anda tidak akan dapat melihat atau pickup artifak ini. Jika Anda membawa salah satu Anda akan kehilangan itu. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat menciptakan lubang cacing melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->upgrade = "Upgrade Jubah";
			break;

			case "norwegian":
				$this->classname = "Sol Recovery Artifact";
				$this->description = "Dette Artifact vil lage et ormehull fra hvilken som helst sektor (realspace eller SG) til Sol og transportere deg dit umiddelbart. N�r score n�r " . $this->scoremax_text . " vil du ikke kunne se eller pickup denne gjenstand. Hvis du er b�rer den du vil miste den. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet kan du lage ormehull gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand n�r som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->upgrade = "Oppgrader Cloak";
			break;

			case "portuguese":
				$this->classname = "Sol Recupera��o Artefato";
				$this->description = "Este artefato criar� um Wormhole de qualquer setor (Realspace ou SG) ao Sol e transporte at� l� imediatamente. Uma vez que sua pontua��o atinge " . $this->scoremax_text . " voc� n�o ser� capaz de ver ou pickup este artefato. Se voc� estiver carregando um que voc� vai perd�-la. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas voc� pode criar o Wormhole atrav�s do comando List Artefato. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". Voc� pode usar esse artefato, a qualquer momento a partir da p�gina Lista de Artefato.";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->upgrade = "Upgrade Cloak";
			break;

			case "swedish":
				$this->classname = "Sol Recovery Artefakt";
				$this->description = "Detta Artefakt skapar ett maskh�l fr�n n�gon sektor (realspace eller SG) till Sol och transportera dig dit direkt. N�r din po�ng n�r " . $this->scoremax_text . " Du kommer inte att kunna se eller pickup denna artefakt. Om du b�r en du kommer att f�rlora det. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar finns du kan skapa Wormhole genom den fiktiva List kommandot. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan anv�nda denna artefakt som helst fr�n den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->upgrade = "Upgrade Cloak";
			break;

			default:
				$this->classname = "Sol Recovery Artifact";
				$this->description = "This Artifact will create a Wormhole from any sector (realspace or SG) to Sol and transport you there instantly.  Once your score reaches " . $this->scoremax_text . " you will not be able to see or pickup this artifact.  If you are carrying one you will lose it.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can create the Wormhole through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->upgrade = "Upgrade Cloak";
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
		global $db, $db_prefix, $playerinfo, $shipinfo;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET sector_id=1 WHERE ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
		db_op_result($res,__LINE__,__FILE__);

		$output ="<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
		return $output;

	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo, $l_global_mmenu;

	}
}

?>