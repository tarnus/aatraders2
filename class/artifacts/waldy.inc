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
				$this->description = "See Tehis annab koheselt ekraanile nimekiri Igal laeval kapten koos Tehis. Nimekiri n�itab, milliseid esemeid iga Kapten viib ja kui palju iga. On kokku " . $this->pieces . " t�kki, et tuleb leida. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ".";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">�kski Ship Kaptenid viivad tahes esemeid.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kaptenid Mis esemeid</font></b>";
				$this->completed = "L�petatud";
				$this->needs = "Vajadustele";
			break;

			case "french":
				$this->classname = "O� en Waldy Artefact";
				$this->description = "Cet artefact instantan�ment afficher une liste de chaque capitaine de navire avec un artefact. La liste indique quels artefacts chaque Capitaine porte et combien de chaque. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ".";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Aucun des capitaines de navires sont �quip� de tout type d&#39;artefacts.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Les capitaines et les art�facts</font></b>";
				$this->completed = "Termin�";
				$this->needs = "Besoins";
			break;

			case "german":
				$this->classname = "Wo ist Waldy Artefakt";
				$this->description = "Dieses Artefakt wird sofort eine Liste von jedem Schiff Kapit�n mit einem Artefakt. Die Liste wird zeigen, was Artefakte jeder Kapit�n tr�gt und wie viele von jedem. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ".";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Keiner der Kapit�ne sind die Durchf�hrung einer Artefakte.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Captains mit Artefakten</font></b>";
				$this->completed = "Fertiggestellt";
				$this->needs = "Needs";
			break;

			case "italian":
				$this->classname = "Where&#39;s Waldy Artefatto";
				$this->description = "Questo artefatto visualizza immediatamente l&#39;elenco di tutti il capitano della nave, con un artefatto. L&#39;elenco mostrer� ci� che Artifacts ogni capitano sta svolgendo e quanti di ciascuno. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
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
				$this->classname = "�D�nde est� Waldy Artefacto";
				$this->description = "Este artefacto inmediatamente mostrar� una lista de todos los capitanes de buques con un artefacto. La lista muestra qu� artefactos cada capit�n est� realizando y cu�ntos de cada uno. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ".";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ninguno de los capitanes de buques transporten artefactos.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capitanes con los artefactos</font></b>";
				$this->completed = "Completo";
				$this->needs = "Necesidades";
			break;

			case "albanian":
				$this->classname = "Ku e Waldy Objekti";
				$this->description = "Kjo Objekti menj�her� do t� shfaq� nj� list� t� �do kapiten i anijeve me nj� Objekti. Lista do t� tregoj� se �far� objekte �do kapiten �sht� q� mbante dhe sa e secilit. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ".";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Asnj� nga kapiten�t anijes jan� t� mbante ndonj� objekte.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Kapiten�t Me objekte</font></b>";
				$this->completed = "Kompletuar";
				$this->needs = "Needs";
			break;

			case "catalan":
				$this->classname = "On est� Waldy Artefacte";
				$this->description = "Aquest artefacte immediatament mostrar� una llista de tots els capitans de vaixells amb un artefacte. La llista mostra qu� artefactes cada capit� est� realitzant i quants de cada un. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ".";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Cap dels capitans de vaixells transportin artefactes.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capitans amb els artefactes</font></b>";
				$this->completed = "Complet";
				$this->needs = "Necessitats";
			break;

			case "danish":
				$this->classname = "Hvor er Waldy Artifact";
				$this->description = "Dette Artifact vil straks vise en liste over alle kaptajn med en artefakt. Listen vil vise, hvad Artifacts hver kaptajn er i f�rd med, og hvor mange af hver. Der er i alt " . $this->pieces . " stykker, der skal findes. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
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
				$this->classname = "Miss� Waldy Teos";
				$this->description = "T�m� Teos tulee heti n�ytt�� luettelon kaikista aluksen p��llik�n kanssa, Teos. Lista n�ytt�� mit� normaalit kukin Kapteeni tekee ja kuinka monta kutakin. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ".";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Yksik��n alusten kapteenit eiv�t kuljeta esineit�.</font></b>";
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
				$this->description = "Dette Artifact vil umiddelbart vise en liste over alle Ship kaptein med en gjenstand. Listen vil vise hva Artifacts hver kaptein b�rer og hvor mange av hver. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ".";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ingen av Ship Captains driver noen gjenstander.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Captains med gjenstander</font></b>";
				$this->completed = "Fullf�rt";
				$this->needs = "Needs";
			break;

			case "portuguese":
				$this->classname = "Where&#39;s Waldy Artefato";
				$this->description = "Este artefato ir� exibir instantaneamente uma lista de cada comandante de navio com um artefato. A lista ir� mostrar o que cada Artefatos Capit�o est� carregando e quantos de cada um. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ".";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Nenhum dos capit�es de navios est�o carregando qualquer artefatos.</font></b>";
				$this->title = "<b><font color=\"lime\" size=\"3\">Capit�es com artefatos</font></b>";
				$this->completed = "Conclu�do";
				$this->needs = "Necessidades";
			break;

			case "swedish":
				$this->classname = "Where&#39;s waldy Artefakt";
				$this->description = "Detta Artefakt kommer omedelbart att visa en lista p� varje fartyg som kapten med en artefakt. F�rteckningen kommer att visa vad Artifacts varje kapten transporterar och hur m�nga av varje. Finns totalt " . $this->pieces . " bitar som m�ste hittas. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ".";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->noonehasany = "<b><font color=\"red\" size=\"3\">Ingen av de fartyg Captains b�r n�gra artefakter.</font></b>";
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