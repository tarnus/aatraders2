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
				$this->description = "See Tehis ehitab sadama valitud ühtegi sektorit. See Tehis saab asendada sadama ühtegi sektorit. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud saate luua sadamate kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->title = "<b><font size=\"4\" color=\"lime\">Ehitamine Port</font></b>";
				$this->select = "Valige Port Type ehitada:";
				$this->submit = "Ehitamine Port";
			break;

			case "french":
				$this->classname = "Port Builder Artefact";
				$this->description = "Cet artefact va construire un port de votre choix dans n&#39;importe quel secteur. Cet artefact peut être utilisé pour remplacer le port dans n&#39;importe quel secteur. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez créer le port grâce à la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Sélectionnez le type de port à construire:";
				$this->submit = "Build Port";
			break;

			case "german":
				$this->classname = "Port Builder Artefakt";
				$this->description = "Dieses Artefakt wird in einen Hafen Ihrer Wahl zu bauen in jedem Sektor. Dieses Artefakt kann genutzt werden, um den Hafen in jedem Bereich zu ersetzen. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie den Hafen durch die Artefakt Liste Befehl zu erstellen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Wählen Sie den Anschluss-Typ zu bauen:";
				$this->submit = "Build Port";
			break;

			case "italian":
				$this->classname = "Port Builder Artifact";
				$this->description = "Questo artefatto sarà costruire un porto a vostra scelta in qualsiasi settore. Questo artefatto può essere utilizzato per sostituire la porta in qualsiasi settore. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile creare la porta attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Selezionare il tipo di porta a costruire:";
				$this->submit = "Build Port";
			break;

			case "spanish":
				$this->classname = "Puerto Builder Artefacto";
				$this->description = "Este artefacto será construir un puerto de su elección en ningún sector. Este artefacto puede ser utilizado para reemplazar el puerto en cualquier sector. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede crear el puerto a través del comando Lista de Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->title = "<b><font size=\"4\" color=\"lime\">Construir el Puerto de</font></b>";
				$this->select = "Seleccione el tipo de puerto para construir:";
				$this->submit = "Construir el Puerto de";
			break;

			case "albanian":
				$this->classname = "Port Builder Objekti";
				$this->description = "Kjo Objekti do të ndërtojë një port për zgjedhjen tuaj në çdo sektor. Kjo Objekti i mund të përdoret për të zëvendësuar portin në çdo sektor. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të krijoni portit përmes komandës Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Zgjidhni Lloji i portit të ndërtuar:";
				$this->submit = "Build Port";
			break;

			case "catalan":
				$this->classname = "Port Builder Artefacte";
				$this->description = "Aquest artefacte és construir un port de la seva elecció en cap sector. Aquest artefacte pot ser utilitzat per substituir el port en qualsevol sector. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot crear el port a través de la comanda Llista de Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Construir el Port de</font></b>";
				$this->select = "Seleccioneu el tipus de port per a construir:";
				$this->submit = "Construir el Port de";
			break;

			case "danish":
				$this->classname = "Port Builder Artifact";
				$this->description = "Dette Artifact vil bygge en havn i dit valg i enhver sektor. Dette Artifact kan bruges til at erstatte den havn i en sektor. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet kan du oprette havnen gennem Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Vælg Port Type at bygge:";
				$this->submit = "Build Port";
			break;

			case "dutch":
				$this->classname = "Port Builder Artifact";
				$this->description = "Dit Artefact zal een poort van uw keuze in elke sector. Dit Artefact kan gebruikt worden om de haven te vervangen in een sector. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de poort te creëren door het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
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
				$this->description = "Tämä Artifact rakentaa sataman valintasi millään alalla. Tämä Teos voidaan korvata satama millään alalla. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit luoda sataman kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
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
				$this->description = "Dette Artifact skal bygge en port av ditt valg i enhver sektor. Dette Artifact kan brukes til å erstatte porten i en hvilken som helst sektor. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet kan du lage havnen gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Bygg Port</font></b>";
				$this->select = "Velg Port Type bygge:";
				$this->submit = "Bygg Port";
			break;

			case "portuguese":
				$this->classname = "Port Builder Artefato";
				$this->description = "Este artefato vai construir um porto de sua escolha em qualquer setor. Este artefato pode ser utilizado para substituir o porto em qualquer setor. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode criar a porta através do comando List Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->title = "<b><font size=\"4\" color=\"lime\">Construir Porto</font></b>";
				$this->select = "Selecione o tipo de porta para construir:";
				$this->submit = "Construir Porto";
			break;

			case "swedish":
				$this->classname = "Port Builder Artefakt";
				$this->description = "Detta Artefakt kommer att bygga en hamn i ditt val i alla sektorer. Detta Artefakt kan användas för att ersätta den hamn i någon sektor. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns du kan skapa porten genom den fiktiva List kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->title = "<b><font size=\"4\" color=\"lime\">Build Port</font></b>";
				$this->select = "Välj hamn Typ att bygga:";
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