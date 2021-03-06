<?php
class portbuilder
{
	var $class = "portbuilder";
	var $pieces = 10;
	var $min_cloak = 225; // Cloak value of each artifact piece
	var $max_cloak = 350; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 5; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function portbuilder()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Port Ehitaja Tehis";
				$this->description = "See Tehis ehitab sadama valitud �htegi sektorit. See Tehis saab asendada sadama �htegi sektorit. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud saate luua sadamate kaudu Tehis nimekiri k�sk. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". V�ite kasutada seda Artefakti igal ajal Tehis nimekiri lehek�ljel.";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->title = "<b><font size=\"4\" color=\"lime\">Ehitamine Port</font></b>";
				$this->select = "Valige Port Type ehitada:";
				$this->submit = "Ehitamine Port";
			break;

			case "french":
				$this->classname = "Port Builder Artefact";
				$this->description = "Cet artefact va construire un port de votre choix dans n&#39;importe quel secteur. Cet artefact peut �tre utilis� pour remplacer le port dans n&#39;importe quel secteur. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont trouv�s, vous pouvez cr�er le port gr�ce � la commande Liste Artefact. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". Vous pouvez utiliser cet objet � tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "S�lectionnez le type de port � construire:";
				$this->submit = "Build Port";
			break;

			case "german":
				$this->classname = "Port Builder Artefakt";
				$this->description = "Dieses Artefakt wird in einen Hafen Ihrer Wahl zu bauen in jedem Sektor. Dieses Artefakt kann genutzt werden, um den Hafen in jedem Bereich zu ersetzen. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle Teile gefunden sind, k�nnen Sie den Hafen durch die Artefakt Liste Befehl zu erstellen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie k�nnen dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "W�hlen Sie den Anschluss-Typ zu bauen:";
				$this->submit = "Build Port";
			break;

			case "italian":
				$this->classname = "Port Builder Artifact";
				$this->description = "Questo artefatto sar� costruire un porto a vostra scelta in qualsiasi settore. Questo artefatto pu� essere utilizzato per sostituire la porta in qualsiasi settore. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, � possibile creare la porta attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". � possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Selezionare il tipo di porta a costruire:";
				$this->submit = "Build Port";
			break;

			case "spanish":
				$this->classname = "Puerto Builder Artefacto";
				$this->description = "Este artefacto ser� construir un puerto de su elecci�n en ning�n sector. Este artefacto puede ser utilizado para reemplazar el puerto en cualquier sector. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede crear el puerto a trav�s del comando Lista de Artefacto. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la p�gina Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->title = "<b><font size=\"4\" color=\"lime\">Construir el Puerto de</font></b>";
				$this->select = "Seleccione el tipo de puerto para construir:";
				$this->submit = "Construir el Puerto de";
			break;

			case "albanian":
				$this->classname = "Port Builder Objekti";
				$this->description = "Kjo Objekti do t� nd�rtoj� nj� port p�r zgjedhjen tuaj n� �do sektor. Kjo Objekti i mund t� p�rdoret p�r t� z�vend�suar portin n� �do sektor. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur ju mund t� krijoni portit p�rmes komand�s Lista Objekti. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ". Ju mund t� p�rdorni k�t� Objekti n� �do koh� nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Zgjidhni Lloji i portit t� nd�rtuar:";
				$this->submit = "Build Port";
			break;

			case "catalan":
				$this->classname = "Port Builder Artefacte";
				$this->description = "Aquest artefacte �s construir un port de la seva elecci� en cap sector. Aquest artefacte pot ser utilitzat per substituir el port en qualsevol sector. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot crear el port a trav�s de la comanda Llista de Artefacte. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vost� pot usar aquest artefacte en qualsevol moment des de la p�gina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Construir el Port de</font></b>";
				$this->select = "Seleccioneu el tipus de port per a construir:";
				$this->submit = "Construir el Port de";
			break;

			case "danish":
				$this->classname = "Port Builder Artifact";
				$this->description = "Dette Artifact vil bygge en havn i dit valg i enhver sektor. Dette Artifact kan bruges til at erstatte den havn i en sektor. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle brikker er fundet kan du oprette havnen gennem Artifact List kommando. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "V�lg Port Type at bygge:";
				$this->submit = "Build Port";
			break;

			case "dutch":
				$this->classname = "Port Builder Artifact";
				$this->description = "Dit Artefact zal een poort van uw keuze in elke sector. Dit Artefact kan gebruikt worden om de haven te vervangen in een sector. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de poort te cre�ren door het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Selecteer de poort type te bouwen:";
				$this->submit = "Build Port";
			break;

			case "finnish":
				$this->classname = "Port Builder Teos";
				$this->description = "T�m� Artifact rakentaa sataman valintasi mill��n alalla. T�m� Teos voidaan korvata satama mill��n alalla. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset l�ytyy voit luoda sataman kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit k�ytt�� t�t� artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->title = "<b><font size=\"4\" color=\"lime\">Rakenna Port</font></b>";
				$this->select = "Valitse Port Type rakentaa:";
				$this->submit = "Rakenna Port";
			break;

			case "indonesian":
				$this->classname = "Port Builder artifak";
				$this->description = "Artefak ini akan membangun pelabuhan pilihan Anda dalam setiap sektor. Artefak ini dapat digunakan untuk menggantikan pelabuhan di setiap sektor. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat membuat pelabuhan melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->title = "<b><font size=\"4\" color=\"lime\">Bangun Pelabuhan</font></b>";
				$this->select = "Pilih Jenis Port untuk membangun:";
				$this->submit = "Bangun Pelabuhan";
			break;

			case "norwegian":
				$this->classname = "Port Builder Artifact";
				$this->description = "Dette Artifact skal bygge en port av ditt valg i enhver sektor. Dette Artifact kan brukes til � erstatte porten i en hvilken som helst sektor. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet kan du lage havnen gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand n�r som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Bygg Port</font></b>";
				$this->select = "Velg Port Type bygge:";
				$this->submit = "Bygg Port";
			break;

			case "portuguese":
				$this->classname = "Port Builder Artefato";
				$this->description = "Este artefato vai construir um porto de sua escolha em qualquer setor. Este artefato pode ser utilizado para substituir o porto em qualquer setor. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas voc� pode criar a porta atrav�s do comando List Artefato. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". Voc� pode usar esse artefato, a qualquer momento a partir da p�gina Lista de Artefato.";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->title = "<b><font size=\"4\" color=\"lime\">Construir Porto</font></b>";
				$this->select = "Selecione o tipo de porta para construir:";
				$this->submit = "Construir Porto";
			break;

			case "swedish":
				$this->classname = "Port Builder Artefakt";
				$this->description = "Detta Artefakt kommer att bygga en hamn i ditt val i alla sektorer. Detta Artefakt kan anv�ndas f�r att ers�tta den hamn i n�gon sektor. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar finns du kan skapa porten genom den fiktiva List kommandot. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan anv�nda denna artefakt som helst fr�n den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "V�lj hamn Typ att bygga:";
				$this->submit = "Build Port";
			break;

			default:
				$this->classname = "Port Builder Artifact";
				$this->description = "This Artifact will build a port of your choice in any sector.  This Artifact can be used to replace the port in any sector.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can create the port through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<font size=\"4\" color=\"lime\"><b>Build Port</b></font>";
				$this->select = "Select the Port Type to build:";
				$this->submit = "Build Port";
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
		global $db, $db_prefix, $playerinfo, $l_global_mmenu;

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
		global $db, $db_prefix, $playerinfo, $l_global_mmenu;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		$output = "<table CELLSPACING=\"0\" CELLPADDING=\"4\" border=1 align=\"center\" bgcolor=\"#000000\">
		<tr><td><div align=\"center\">" . $this->title . "</div></td></tr><tr><td align=\"center\"><table CELLSPACING=\"0\" CELLPADDING=\"2\" border=0 width=\"100%\" align=\"center\">
					<tr><td><div align=\"center\"><b>" . $this->select . "</b></div></td></tr><tr><td>";

		$output .= "<form action=\"artifact_process.php?process_type=post&artifact=" . $this->class . "\" method=\"post\" enctype=\"multipart/form-data\">\n";

		$output .= "<input type=\"radio\" name=\"port_type\" value=\"upgrades\" checked>&nbsp;&nbsp;&nbsp;Upgrades<br>";
		$output .= "<input type=\"radio\" name=\"port_type\" value=\"devices\">&nbsp;&nbsp;&nbsp;Devices<br>";
		$output .= "<input type=\"radio\" name=\"port_type\" value=\"spacedock\">&nbsp;&nbsp;&nbsp;Spacedock<br>";

		$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 order by classname ASC");
		db_op_result($cargo_query,__LINE__,__FILE__);

		while (!$cargo_query->EOF) 
		{
			if ($cargo_query->fields['cargosellbuy'] != 1)
			{
				$output .= "<input type=\"radio\" name=\"port_type\" value=\"" . $cargo_query->fields['classname'] . "\">&nbsp;&nbsp;&nbsp;" . ucwords($cargo_query->fields['classname']) . "<br>";
			}
			$cargo_query->Movenext();
		}

		$output .= "<br><br>\n
		  <div align=\"center\"><input type=\"submit\" id=\"" . $this->submit . "\" value=\"" . $this->submit . "\" name=\"" . $this->submit . "\" ></div>\n</FORM>";

		$output .= "</form></td></tr></table>
</td></tr>
<tr><td align=\"center\"><br>$l_global_mmenu<br><br></td></tr>
		</table>";
		return $output;

	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo, $shipinfo, $l_global_mmenu, $max_port_buy_commodities;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

	  	$port_type = $_POST['port_type'];

		if ($port_type == "upgrades" || $port_type == "devices" || $port_type == "spacedock")
		{
			$debug_query = $db->Execute ("UPDATE {$db_prefix}universe SET port_type=" . $db->qstr($port_type) . " WHERE sector_id=$shipinfo[sector_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
			$res = $db->Execute("DELETE FROM {$db_prefix}universe_ports WHERE sector_id=$shipinfo[sector_id]");
			db_op_result($res,__LINE__,__FILE__);
			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
			return $output;
		}

		$cargototal = 0;

		$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 order by classname ASC");
		db_op_result($cargo_query,__LINE__,__FILE__);

		$default_create_ratio = 100 / $cargo_query->fields['default_create_percent'];
		$default_create_ratio_new = 1;

		while (!$cargo_query->EOF) 
		{
			if($port_type == $cargo_query->fields['classname'])
			{
				$a_fixed_start_price = $cargo_query->fields['fixed_start_price'];
				$a_increaserate = $cargo_info['increaserate'];
				$a_limitamount = $cargo_query->fields['itemlimit'];
				$a_goodevil = $cargo_query->fields['goodevil'];
				$random_port = $cargototal;
			}
			$newcargotype[$cargototal] = $cargo_query->fields['classname'];
			$limitamount[$cargototal] = $cargo_query->fields['itemlimit'];
			$initialamount[$cargototal] = $cargo_query->fields['itemlimit'] * $_POST['initscommod'] / 100.0;
			$fixed_start_price[$cargototal] = $cargo_query->fields['fixed_start_price'];
			$increaserate[$cargototal] = $cargo_info['increaserate'];
			$goodevil[$cargototal] = $cargo_query->fields['goodevil'];
			$cargosellbuy[$cargototal] = $cargo_info['cargosellbuy'];
			$default_create_percent[$cargototal] = $cargo_info['default_create_percent'] * $default_create_ratio;
			if($cargo_info['defaultcargoplanet'] == 0 && $default_create_ratio_new == 1)
			{
				$default_create_ratio_new = 200 / $cargo_info['default_create_percent'];
			}
			$default_create_percent_new[$cargototal] = $cargo_info['default_create_percent'] * $default_create_ratio_new;
			$hold_space[$cargototal] = $cargo_info['hold_space'];
			$cargototal++;
			$cargo_query->Movenext();
		}

		$debug_query = $db->Execute ("UPDATE {$db_prefix}universe SET port_type=" . $db->qstr($port_type) . " WHERE sector_id=$shipinfo[sector_id]");
		db_op_result($debug_query,__LINE__,__FILE__);
		$res = $db->Execute("DELETE FROM {$db_prefix}universe_ports WHERE sector_id=$shipinfo[sector_id]");
		db_op_result($res,__LINE__,__FILE__);

		$randompoint = mt_rand(500000, 1000000) / 1000000;
		$prices = floor($a_fixed_start_price * $randompoint);
		if($a_increaserate == 0)
		{
			$prices = $a_fixed_start_price;
		}

		$maxcommodities = $max_port_buy_commodities;
		$insertlist = "";
		for($ii = 0; $ii < $cargototal; $ii++)
		{
			if($maxcommodities > 0)
			{
				if($ii != $random_port && mt_rand(1, 100) < 50 && $cargosellbuy[$ii] != 2)
				{
					$randompoint = mt_rand(500000, 1000000) / 1000000;
					$buyprices = floor($fixed_start_price[$ii] * $randompoint) * 3;
					$buyprices += $fixed_start_price[$ii] * $ratio;
					if($increaserate[$ii] == 0)
					{
						$buyprices = $fixed_start_price[$ii] / 2;
					}
					$insertlist .= ", ($shipinfo[sector_id], '" . $newcargotype[$ii] . "', $limitamount[$ii], " . $buyprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$ii])";
					$maxcommodities--;
				}
			}
		}

		$debug_query = $db->Execute("INSERT INTO {$db_prefix}universe_ports 
			(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
			VALUES 
			($shipinfo[sector_id], '" . $port_type . "', $a_limitamount, $prices, '" . date("Y-m-d H:i:s") . "', $a_goodevil) 
			$insertlist");
		db_op_result($debug_query,__LINE__,__FILE__);

		$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
		db_op_result($res,__LINE__,__FILE__);

		$output ="<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
		return $output;
	}
}

?>