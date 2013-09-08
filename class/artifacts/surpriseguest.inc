<?php
class surpriseguest
{
	var $class = "surpriseguest";
	var $pieces = 10;
	var $min_cloak = 300; // Cloak value of each artifact piece
	var $max_cloak = 400; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 3; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function surpriseguest()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Üllatus Külaline Tehis";
				$this->description = "See Tehis loob Wormhole ükskõik SG Sector kui tead nime ja koheselt transpordi sa seal mööda kõiki valdkondi keinojasi. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud saate valida SG sektori Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->failurename = "Ei leia SG sektori järgi nime: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Tehis Wormhole et SG sektor</font></b>";
				$this->sector = "Sisestage Sector Nimi jaoks Wormhole Sihtkoht:";
				$this->submit = "Loo Wormhome";
			break;

			case "french":
				$this->classname = "Surprise de l&#39;utilisateur Artefact";
				$this->description = "Cet artefact va créer un trou de ver à tout secteur SG si vous connaissez le nom et instantanément vous y transporter en contournant toutes les défenses du secteur. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez choisir le secteur SG de la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->failurename = "Impossible de localiser un secteur SG par ce nom: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artifact Wormhole à SG Secteur</font></b>";
				$this->sector = "Entrez Secteur de destination Wormhole:";
				$this->submit = "Créer Wormhome";
			break;

			case "german":
				$this->classname = "Surprise Guest Artefakt";
				$this->description = "Dieses Artefakt wird ein Wurmloch alle SG Sektor zu erstellen, wenn Sie den Namen und wissen sofort transportieren Sie es unter Umgehung aller Sector Defenses. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie die SG aus dem Sektor Artefakt Liste Befehl auszuwählen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->failurename = "Konnte nicht lokalisiert ein SG Sektor mit diesem Namen: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefakt Wurmloch zu SG Sector</font></b>";
				$this->sector = "Geben Sie Sector Name für Wurmloch Ziel:";
				$this->submit = "Erstellen Wormhome";
			break;

			case "italian":
				$this->classname = "Surprise Guest Artifact";
				$this->description = "Artefatto questo creerà un wormhole a qualsiasi settore SG, se si conosce il nome e subito il trasporto ci si bypassa tutte le difese del settore. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile selezionare il Settore SG del comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->failurename = "Impossibile individuare un settore SG con questo nome: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefatto Wormhole a SG Settore</font></b>";
				$this->sector = "Inserisci il nome del settore di destinazione Wormhole:";
				$this->submit = "Crea Wormhome";
			break;

			case "spanish":
				$this->classname = "Invitado sorpresa Artefacto";
				$this->description = "Este artefacto creará un agujero de gusano a cualquier sector SG si conoce el nombre y de inmediato el transporte que no pasando por alto todas las defensas del sector. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el Sector SG desde el comando Lista de Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->failurename = "No se pudo localizar a un sector de SG por este nombre: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefacto Wormhole a la Secretaría General del Sector</font></b>";
				$this->sector = "Introducir el nombre del Sector de destino Wormhole:";
				$this->submit = "Crear Wormhome";
			break;

			case "albanian":
				$this->classname = "Objekti i habit Guest";
				$this->description = "Kjo Objekti i do të krijojë një Wormhole për çdo Sektorin SG nëse ju e dini emrin dhe menjëherë të transportit ju ka anashkaluar të gjithë mbrojtëse sektorit. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni nga Sektori SG komandën Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->failurename = "Nuk mund të gjetur një Sektorin e SP me këtë emër: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Objekti i Wormhole në Sektorin SG</font></b>";
				$this->sector = "Futni emrin Sektori për destinacion Wormhole:";
				$this->submit = "Krijo Wormhome";
			break;

			case "catalan":
				$this->classname = "Convidat sorpresa Artefacte";
				$this->description = "Aquest artefacte crearà un forat de cuc a qualsevol sector SG si coneix el nom i immediatament el transport que no passant per alt totes les defenses del sector. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el Sector SG des de la comanda Llista de Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->failurename = "No es pot localitzar a un sector de SG per aquest nom: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefacte Wormhole a la Secretaria General del Sector</font></b>";
				$this->sector = "Introduir el nom del Sector de destinació Wormhole:";
				$this->submit = "Crea Wormhome";
			break;

			case "danish":
				$this->classname = "Surprise Guest Artifact";
				$this->description = "Dette Artifact vil skabe et ormehul til enhver SG sektor, hvis du kender navnet, og straks transport dig der omgår alle Sector Defenses. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet, kan du vælge SG sektor fra Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->failurename = "Kunne ikke finde en SG Sektor med dette navn: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artifact Ormehul til SG Sector</font></b>";
				$this->sector = "Indtast Sektor Navn for Ormehul destination:";
				$this->submit = "Opret Wormhome";
			break;

			case "dutch":
				$this->classname = "Surprise Guest Artifact";
				$this->description = "Artefact Dit zal leiden tot een Wormhole elke SG Sector als u de naam kent en er direct vervoer je het omzeilen van alle Sector Defenses. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de SG sector van de Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->failurename = "Kan niet vinden een SG sector met deze naam: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefact Wormhole aan SG Sector</font></b>";
				$this->sector = "Voer Sector Naam voor Wormhole bestemming:";
				$this->submit = "Maak Wormhome";
			break;

			case "finnish":
				$this->classname = "Yllätyksen Guest Teos";
				$this->description = "Tämä Teos luo Madonreikä mitään SG-ala, jos tiedät nimen ja heti liikenne siellä ohittaa kaikki Sector puolustuksemme. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita SG alaa Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->failurename = "Ei löytänyt SG alan tämä nimi: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Teos Madonreikä edustajille Sector</font></b>";
				$this->sector = "Anna Ala nimi on Wormhole Kohde:";
				$this->submit = "Luo Wormhome";
			break;

			case "indonesian":
				$this->classname = "Surprise Guest artifak";
				$this->description = "Artefak ini akan menciptakan sebuah lubang cacing untuk setiap SG Sektor jika Anda mengetahui nama dan transportasi langsung ke sana melewati semua Sektor Pertahanan. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan, Anda dapat memilih dari Sektor DC Daftar artefak perintah. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->failurename = "Tidak dapat menemukan suatu SG Sektor dengan nama ini: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artifak lubang cacing untuk SG Sektor</font></b>";
				$this->sector = "Masukkan Nama untuk lubang cacing Sektor tujuan:";
				$this->submit = "Buat Wormhome";
			break;

			case "norwegian":
				$this->classname = "Surprise Guest Artifact";
				$this->description = "Dette Artifact vil lage et ormehull til enhver SG Sector hvis du kjenner navnet og kjapt å transportere deg dit omgåelsen alle Sector Defenses. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet kan du velge SG sektor fra Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->failurename = "Kunne ikke finne en SG sektor ved dette navnet: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Gjenstand ormehullet til SG Sector</font></b>";
				$this->sector = "Skriv Sector navn for ormehullet destinasjon:";
				$this->submit = "Lag Wormhome";
			break;

			case "portuguese":
				$this->classname = "Surprise Guest Artefato";
				$this->description = "Este artefato criará um Wormhole a qualquer sector SG se você sabe o nome e imediatamente o transporte até lá ignorando todas as defesas do Setor. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode selecionar o setor SG a partir do comando List Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->failurename = "Não foi possível localizar um Sector SG por este nome: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefato Wormhole a SG Setor</font></b>";
				$this->sector = "Digite o nome do Setor de destino Wormhole:";
				$this->submit = "Criar Wormhome";
			break;

			case "swedish":
				$this->classname = "Surprise Guest Artefakt";
				$this->description = "Detta Artefakt kommer att skapa ett maskhål till någon SG bransch om du känner till namnet och omedelbart transportera dig där förbi alla Sector försvaret. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns kan du välja SG sektorn från den fiktiva lista kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->failurename = "Kunde inte hitta en SG sektor med detta namn: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Artefakt Wormhole till SG Sector</font></b>";
				$this->sector = "Ange Sector Namn för Wormhole destination:";
				$this->submit = "Skapa Wormhome";
			break;

			default:
				$this->classname = "Surprise Guest Artifact";
				$this->description = "This Artifact will create a Wormhole to any SG Sector if you know the name and instantly transport you there bypassing all Sector Defenses.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select the SG Sector from the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->failurename = "Could not locate an SG Sector by this name: [sectorname]";
				$this->title = "<font size=\"4\" color=\"lime\"><b>Artifact Wormhole to SG Sector</b></font>";
				$this->sector = "Enter Sector Name for Wormhole destination:";
				$this->submit = "Create Wormhome";
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
		global $db, $db_prefix, $playerinfo, $langdir, $l_global_mmenu;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

			$output ="
<form action=\"artifact_process.php?process_type=post&artifact=" . $this->class ."\" method=\"post\" enctype=\"multipart/form-data\">
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
		<tr BGCOLOR=\"#585980\">
			<td colspan=\"2\"><div align=\"center\"><b>" . $this->title . "</div></td>
		</tr>
		<tr BGCOLOR=\"#3A3B6E\">
			<TD>" . $this->sector . "</td>
			<TD><input type=\"text\" name=\"destination\" maxlength=\"30\" size=\"8\"></td>
		</tr>
 		<tr BGCOLOR=\"#23244F\">
			<td colspan=\"2\"><div align=\"center\"><input type=\"submit\" id=\"" . $this->submit . "\" value=\"" . $this->submit . "\" name=\"" . $this->submit . "\" ></div></td>
		</tr>
		<tr><td colspan=\"2\" align=\"center\"><br>$l_global_mmenu<br><br></td></tr>
	</table>
</div>
</form>";
		return $output;

	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo, $shipinfo, $l_global_mmenu;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

	  	$destination = $_POST['destination'];

		$result  = $db->Execute("SELECT sector_id FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr($destination) . " and sg_sector!=0");
		db_op_result($result,__LINE__,__FILE__);
		if($result->RecordCount() == 1)
		{
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET sector_id=" . $result->fields['sector_id'] . " WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
			return $output;
		}
		else
		{
			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . str_replace("[sectorname]", $destination, $this->failurename) . "</b></font></div></td>
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