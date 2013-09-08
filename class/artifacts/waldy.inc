<?php
class waldy
{
	var $class = "waldy";
	var $pieces = 3;
	var $min_cloak = 175; // Cloak value of each artifact piece
	var $max_cloak = 250; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 0; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 15; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function waldy()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Kus Waldy Tehis";
				$this->description = "See Tehis annab koheselt ekraanile nimekiri Igal laeval kapten koos Tehis. Nimekiri näitab, milliseid esemeid iga Kapten viib ja kui palju iga. On kokku " . $this->pieces . " tükki, et tuleb leida. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ".";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ükski Ship Kaptenid viivad tahes esemeid.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kaptenid Mis esemeid</font></b>";
				$this->completed = "Lõpetatud";
				$this->needs = "Vajadustele";
			break;

			case "french":
				$this->classname = "Où en Waldy Artefact";
				$this->description = "Cet artefact instantanément afficher une liste de chaque capitaine de navire avec un artefact. La liste indique quels artefacts chaque Capitaine porte et combien de chaque. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ".";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Aucun des capitaines de navires sont équipé de tout type d&#39;artefacts.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Les capitaines et les artéfacts</font></b>";
				$this->completed = "Terminé";
				$this->needs = "Besoins";
			break;

			case "german":
				$this->classname = "Wo ist Waldy Artefakt";
				$this->description = "Dieses Artefakt wird sofort eine Liste von jedem Schiff Kapitän mit einem Artefakt. Die Liste wird zeigen, was Artefakte jeder Kapitän trägt und wie viele von jedem. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ".";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Keiner der Kapitäne sind die Durchführung einer Artefakte.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Captains mit Artefakten</font></b>";
				$this->completed = "Fertiggestellt";
				$this->needs = "Needs";
			break;

			case "italian":
				$this->classname = "Where&#39;s Waldy Artefatto";
				$this->description = "Questo artefatto visualizza immediatamente l&#39;elenco di tutti il capitano della nave, con un artefatto. L&#39;elenco mostrerà ciò che Artifacts ogni capitano sta svolgendo e quanti di ciascuno. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ".";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Nessuno dei capitani delle navi trasportano qualsiasi artefatto.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capitani di artefatti</font></b>";
				$this->completed = "Completato";
				$this->needs = "Esigenze";
			break;

			case "spanish":
				$this->classname = "¿Dónde está Waldy Artefacto";
				$this->description = "Este artefacto inmediatamente mostrará una lista de todos los capitanes de buques con un artefacto. La lista muestra qué artefactos cada capitán está realizando y cuántos de cada uno. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ".";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ninguno de los capitanes de buques transporten artefactos.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capitanes con los artefactos</font></b>";
				$this->completed = "Completo";
				$this->needs = "Necesidades";
			break;

			case "albanian":
				$this->classname = "Ku e Waldy Objekti";
				$this->description = "Kjo Objekti menjëherë do të shfaqë një listë të çdo kapiten i anijeve me një Objekti. Lista do të tregojë se çfarë objekte çdo kapiten është që mbante dhe sa e secilit. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ".";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Asnjë nga kapitenët anijes janë të mbante ndonjë objekte.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kapitenët Me objekte</font></b>";
				$this->completed = "Kompletuar";
				$this->needs = "Needs";
			break;

			case "catalan":
				$this->classname = "On està Waldy Artefacte";
				$this->description = "Aquest artefacte immediatament mostrarà una llista de tots els capitans de vaixells amb un artefacte. La llista mostra què artefactes cada capità està realitzant i quants de cada un. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ".";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Cap dels capitans de vaixells transportin artefactes.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capitans amb els artefactes</font></b>";
				$this->completed = "Complet";
				$this->needs = "Necessitats";
			break;

			case "danish":
				$this->classname = "Hvor er Waldy Artifact";
				$this->description = "Dette Artifact vil straks vise en liste over alle kaptajn med en artefakt. Listen vil vise, hvad Artifacts hver kaptajn er i færd med, og hvor mange af hver. Der er i alt " . $this->pieces . " stykker, der skal findes. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ".";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ingen af de skibe Kaptajner medtager nogen artefakter.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kaptajner med Artifacts</font></b>";
				$this->completed = "Afsluttet";
				$this->needs = "Needs";
			break;

			case "dutch":
				$this->classname = "Waar is Waldy Artifact";
				$this->description = "Dit Artefact zal onmiddellijk een lijst van elk schip kapitein met een artefact. De lijst zal laten zien wat Artifacts elk Captain is het uitvoeren en hoeveel van elk. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ".";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Geen van de kapiteins zijn die geen artefacten.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Captains Met Artifacts</font></b>";
				$this->completed = "Afgesloten";
				$this->needs = "Needs";
			break;

			case "finnish":
				$this->classname = "Missä Waldy Teos";
				$this->description = "Tämä Teos tulee heti näyttää luettelon kaikista aluksen päällikön kanssa, Teos. Lista näyttää mitä normaalit kukin Kapteeni tekee ja kuinka monta kutakin. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ".";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Yksikään alusten kapteenit eivät kuljeta esineitä.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kapteenit kanssa Artifacts</font></b>";
				$this->completed = "Valmistui";
				$this->needs = "Tarvitsee";
			break;

			case "indonesian":
				$this->classname = "Mana artifak Waldy";
				$this->description = "Artefak ini akan segera menampilkan daftar setiap Kapal Kapten dengan artefak. Daftar akan menunjukkan apa yang masing-masing Kapten Artifacts membawa dan berapa banyak dari masing-masing. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ".";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Tak satu pun dari Kapten Kapal yang membawa artefak apapun.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kapten Dengan Artifacts</font></b>";
				$this->completed = "Selesai";
				$this->needs = "Kebutuhan";
			break;

			case "norwegian":
				$this->classname = "Where&#39;s Waldy Artifact";
				$this->description = "Dette Artifact vil umiddelbart vise en liste over alle Ship kaptein med en gjenstand. Listen vil vise hva Artifacts hver kaptein bærer og hvor mange av hver. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ".";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ingen av Ship Captains driver noen gjenstander.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Captains med gjenstander</font></b>";
				$this->completed = "Fullført";
				$this->needs = "Needs";
			break;

			case "portuguese":
				$this->classname = "Where&#39;s Waldy Artefato";
				$this->description = "Este artefato irá exibir instantaneamente uma lista de cada comandante de navio com um artefato. A lista irá mostrar o que cada Artefatos Capitão está carregando e quantos de cada um. Há um total de " . $this->pieces . " peças que precisam ser encontrados. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ".";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Nenhum dos capitães de navios estão carregando qualquer artefatos.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capitães com artefatos</font></b>";
				$this->completed = "Concluído";
				$this->needs = "Necessidades";
			break;

			case "swedish":
				$this->classname = "Where&#39;s waldy Artefakt";
				$this->description = "Detta Artefakt kommer omedelbart att visa en lista på varje fartyg som kapten med en artefakt. Förteckningen kommer att visa vad Artifacts varje kapten transporterar och hur många av varje. Finns totalt " . $this->pieces . " bitar som måste hittas. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ".";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ingen av de fartyg Captains bär några artefakter.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kaptener med Artifacts</font></b>";
				$this->completed = "Avslutat";
				$this->needs = "Needs";
			break;

			default:
				$this->classname = "Where's Waldy Artifact";
				$this->description = "This Artifact will instantly display a list of every Ship Captain with an Artifact.  The list will show what Artifacts each Captain is carrying and how many of each.  There are a total of " . $this->pieces . " pieces that need to be found.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->noonehasany = "<font color=\"red\" size=\"3\"><b>None of the Ship Captains are carrying any artifacts.</b></font>";
				$this->title = "<font color=\"lime\" size=\"3\"><b>Captains With Artifacts</b></font>";
				$this->completed = "Completed";
				$this->needs = "Needs";
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
		global $db, $db_prefix, $playerinfo, $start_armor, $start_energy, $start_fighters;

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
			$res = $db->Execute("SELECT {$db_prefix}artifacts.artifact_type, count( {$db_prefix}artifacts.artifact_id ) AS total, {$db_prefix}players.character_name
								FROM {$db_prefix}artifacts, {$db_prefix}players 
								WHERE {$db_prefix}artifacts.player_id !=0 and {$db_prefix}artifacts.player_id = {$db_prefix}players.player_id
								GROUP BY {$db_prefix}artifacts.artifact_type, {$db_prefix}artifacts.player_id order by {$db_prefix}players.character_name, {$db_prefix}artifacts.artifact_type");
			db_op_result($res,__LINE__,__FILE__);

	   		if($res->RecordCount() == 0)
   			{
   				return $this->noonehasany;
   			}
   			else
   			{
  				$output = "<div align=\"center\"><table cellspacing = \"0\" cellpadding = \"0\" border = \"0\"><tr><td>" . $this->title . "</td></tr></table></div><br>\n";
   				$output .= "<table cellspacing = \"0\" cellpadding = \"2\" border = \"1\">\n";

				$oldname = "";
				while (!$res->EOF)
				{
					$msg = $res->fields;
					if($res->fields['character_name'] != $oldname)
					{
						$output .= "</table></div><br><div align=\"center\"><table cellspacing = \"0\" cellpadding = \"2\" border = \"1\">\n";
						$output .= "<tr><td><b><div align=\"center\"><font color=\"white\">" . $res->fields['character_name'] . "</font></div></b></td><tr>\n";
					}
					if($oldname == "")
					{
						$output .= "<tr><td><b><div align=\"center\"><font color=\"white\">" . $res->fields['character_name'] . "</font></div></b></td><tr>\n";
					}
					$oldname = $res->fields['character_name'];
		  			if($res->fields['total'] == 1)
   					{
   						$pieces = $this->singular;
   					}
		   			else
   					{
 		    			$pieces = $this->plural;
  					}
					if(!class_exists($res->fields['artifact_type'])){
						include ("class/artifacts/" . $res->fields['artifact_type'] . ".inc");
					}
					$artifacts_object = new $res->fields['artifact_type']();
					if($res->fields['total'] >= $artifacts_object->pieces)
					{
						$completed = "<font color=\"yellow\">" . $this->completed . "</font>";
					}
					else
					{
						$completed = "<font color=\"yellow\">" . $res->fields['total'] . "</font> <font color=\"lime\">$pieces</font> - ";
						if(($artifacts_object->pieces - $res->fields['total']) == 1)
						{
							$pieces =  $this->singular;
						}
						else
						{
			   				$pieces = $this->plural;
						}
						$completed .= "<font color=\"lime\">" . $this->needs . "</font> <font color=\"yellow\">" . ($artifacts_object->pieces - $res->fields['total']) . "</font> <font color=\"lime\">$pieces</font>";
					}
					$output .= "<tr><td><b><font color=\"#52ACEA\">" . $artifacts_object->classname . "</font> <font color=\"white\">(</font>$completed<font color=\"white\">)</font></b></td><tr>\n";
					$res->MoveNext();
				}
				$output .= "</table>\n";
   			}

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);
			insert_news($this->classname . "|" . $playerinfo['character_name'], 1, "artifact");
   			return $output;
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
		global $db, $db_prefix, $playerinfo;
	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo;
	}
}

?>