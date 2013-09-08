<?php
class dreadnought
{
	var $class = "dreadnought";
	var $pieces = 30;
	var $min_cloak = 350; // Cloak value of each artifact piece
	var $max_cloak = 410; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 0; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 1; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function dreadnought()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Dreadnought Tehis";
				$this->description = "See Tehis saab kutsuda Riisuttu Föderatsiooni lahing Cruiser. Battle Cruiser on 400 tehnoloogiate tase ja saab uuendada 900. Battle Cruiser ei hõlma hävitajaid, miinid, armor, energeetika-, kaevandus deflectors, evakuatsiooni-pod või mõne muu seadmega. Kui kutsutud lahingu Cruiser ilmub ladustamine oma koduplaneedi. Kui sul ei ole koduplaneedi põhinevad planeedi on juhuslikult valitud säilitada lahing Cruiser. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud lahing Cruiser on kutsutud. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Laev on kutsutud ja salvestatud planeedi [planet] sektoris [sector].";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->noplanets = "Sul ei ole ise ühtegi planeeti säilitada Dreadnought. Sa kaotad Dreadnought ja kõik kogutakse Dreadnought Tehis tükki.";
			break;

			case "french":
				$this->classname = "Dreadnought Artefact";
				$this->description = "Cet artefact invoquera un stripped-down Fédération Battle Cruiser. Le croiseur de bataille a 400 niveaux de technologie et peuvent être mis à niveau à 900. La bataille ne sera pas Cruiser comprennent des chasseurs, des mines, des armures, de l&#39;énergie, de déflecteurs mine, Escape Pod ou tout autre appareil. Convoqué le croiseur de bataille apparaissent dans le stockage sur votre planète. Si vous n&#39;avez pas une planète à la maison une planète sera basée choisis aléatoirement pour stocker le croiseur de bataille. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvé le croiseur de bataille seront convoqués. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Le navire a été convoqué et stockées sur la planète [planet] dans le secteur [sector].";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->noplanets = "Vous ne possédez pas de planètes pour stocker le Dreadnought. Vous perdez le Dreadnought et toutes les pièces recueillies Dreadnought Artefact.";
			break;

			case "german":
				$this->classname = "Dreadnought Artefakt";
				$this->description = "Dieses Artefakt wird beschwören eine abgespeckte Föderation Battle Cruiser. Die Schlacht hat 400 Cruiser-Tech-Niveau und kann auf 900 aufgerüstet werden. Die Schlacht Cruiser umfassen keine Kämpfer, die Minen, Rüstung, Energie-, Bergbau Windabweiser, Rettungskapsel oder anderen Geräten. Wenn rief die Schlacht Cruiser wird im Speicher auf Ihrem Home-Planet erscheinen. Wenn Sie noch kein Heimatplaneten ein Basis Planeten werden nach dem Zufallsprinzip ausgewählt werden, die Speicherung der Battle Cruiser. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Stücke gefunden werden, die Schlacht Cruiser wird geladen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Das Schiff wurde gerufen und auf dem Planeten gespeichert [planet] im Bereich [sector].";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->noplanets = "Sie brauchen keine eigenen Planeten zu den Dreadnought speichern. Sie verlieren die Dreadnought und alle gesammelten Dreadnought Artefakt Stück.";
			break;

			case "italian":
				$this->classname = "Dreadnought Artifact";
				$this->description = "Questo artefatto si convocare un stripped-down Federazione Battle Cruiser. L&#39;incrociatore da battaglia ha 400 livelli di tecnologia e può essere aggiornato a 900. L&#39;incrociatore da battaglia non include i combattenti, le miniere, le armature, l&#39;energia, deflettori mia, di fuga pod o qualsiasi altro dispositivo. Quando chiamò il incrociatore da battaglia apparirà in deposito sul tuo Home Planet. Se non si dispone di un pianeta di origine di un pianeta in base sarà scelto a caso per memorizzare l&#39;incrociatore da battaglia. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi si trovano l&#39;incrociatore da battaglia sarà convocato. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". La nave è stato convocato e memorizzati sul pianeta [planet] nel settore [sector].";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->noplanets = "Tu non possiedono pianeti per memorizzare i Dreadnought. Si perde il Dreadnought e tutti i pezzi raccolti Dreadnought Artifact.";
			break;

			case "spanish":
				$this->classname = "Dreadnought Artefacto";
				$this->description = "Este artefacto será convocar a una pelada-abajo Federación Battle Cruiser. El crucero de batalla tiene 400 niveles de tecnología y se puede actualizar a 900. El crucero de batalla no se incluyen los combatientes, minas, vehículos blindados, la energía, deflectores de minas, pod de escape o cualquier otro dispositivo. Cuando fue llamado el Crucero de Batalla aparecerá en el almacenamiento de su casa Planeta. Si usted no tiene un planeta de origen de un planeta se basa elegidos al azar para almacenar el crucero de batalla. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran el crucero de batalla serán convocados. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". El barco ha sido convocado y se almacenan en el planeta [planet] en el sector [sector].";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->noplanets = "Usted no tiene ningún planetas para almacenar el Dreadnought. Se pierde la Dreadnought y todas las piezas coleccionadas Dreadnought artefacto.";
			break;

			case "albanian":
				$this->classname = "Luftanije e koracuar Objekti";
				$this->description = "Kjo Objekti do të thërrasë një hoqi-Down Federata Battle Cruiser. Beteja ka Cruiser 400 nivelet e teknologjisë dhe mund të çohej në 900. Cruiser Beteja nuk do të përfshijë luftëtarë, mina, shqyrtari, energji, deflectors minave, ikjes pod ose ndonjë pajisje tjetër. Kur thirri Cruiser Beteja do të shfaqen në ruajtje në Planet Faqja juaj. Nëse ju nuk keni një planet në shtëpi një planet me bazë do të jetë zgjedhur rastësisht për të ruajtur Cruiser Battle. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur Cruiser Beteja do të thirren. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Anija ka qenë të ftuar dhe do të ruhet në planetin [planet] në sektorin [sector].";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->noplanets = "Ju nuk zotërojnë asnjë planetet për të ruajtur luftanije e koracuar. Ju humbni luftanije e koracuar dhe të gjitha mbledhur copa Objekti luftanije e koracuar.";
			break;

			case "catalan":
				$this->classname = "Dreadnought Artefacte";
				$this->description = "Aquest artefacte serà convocar a una pelada a baix Federació Battle Cruiser. El creuer de batalla té 400 nivells de tecnologia i es pot actualitzar a 900. El creuer de batalla no s&#39;inclouen els combatents, mines, vehicles blindats, l&#39;energia, deflectors de mines, pod d&#39;escapament o qualsevol altre dispositiu. Quan va ser anomenat el Creuer de Batalla apareixerà en l&#39;emmagatzematge de casa Planeta. Si vostè no té un planeta d&#39;origen d&#39;un planeta es basa triats a l&#39;atzar per emmagatzemar el creuer de batalla. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben el creuer de batalla seran convocats. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". El vaixell ha estat convocat i s&#39;emmagatzemen al planeta [planet] en el sector [sector].";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->noplanets = "No té cap planetes per emmagatzemar el Dreadnought. Es perd la Dreadnought i totes les peces col · leccionades Dreadnought artefacte.";
			break;

			case "danish":
				$this->classname = "Dreadnought Artifact";
				$this->description = "Dette Artifact vil kalde en skrabet-Down Føderation Battle Cruiser. Slaget Cruiser har 400 tech-niveauer og kan opgraderes til 900. Slaget Cruiser vil ikke omfatte krigere, miner, rustning, energi-, mine ledes væk, flygte pod eller en anden enhed. Når indkaldt Slaget Cruiser vises i opbevaring på din hjemplanet. Hvis du ikke har et hjem planet en baseret planet vil blive tilfældigt udvalgt til at gemme Battle Cruiser. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet Slaget Cruiser vil blive indkaldt. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Skibet er blevet indkaldt, og lagret på planeten [planet] i sektor [sector].";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->noplanets = "Du behøver ikke eje nogen planeter at gemme Dreadnought. Du mister Dreadnought og alle indsamlede Dreadnought Artifact stykker.";
			break;

			case "dutch":
				$this->classname = "Dreadnought Artifact";
				$this->description = "Dit Artefact zal roepen een uitgeklede Federatie Battle Cruiser. The Battle Cruiser heeft 400 tech niveaus en kan worden uitgebreid tot 900. The Battle Cruiser zal geen deel uitmaken strijders, mijnen, armor, energie, mijn deflectoren, ontsnappen pod of een ander apparaat. Toen riep de Battle Cruiser verschijnt in opslag op je Home Planet. Als u niet over een planeet een basis planeet zal willekeurig worden afgehaald aan de Battle Cruiser te slaan. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden in de strijd Cruiser zal worden gedagvaard. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". Het schip is gedagvaard en opgeslagen op de planeet [planet] in de sector [sector].";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->noplanets = "U hoeft zelf geen planeten het opslaan van de Dreadnought. U verliest de Dreadnought en alle verzamelde Dreadnought Artifact stuks.";
			break;

			case "finnish":
				$this->classname = "Dreadnought Teos";
				$this->description = "Tämä Teos on kutsua riisuttu federaation Battle Cruiser. Battle Cruiser on 400 teknologian tasoa ja voidaan päivittää 900. Battle Cruiser eivät sisälly Fighters, miinat, panssari-, energia-, kaivos ohjaimet, escape pod tai muusta laitteesta. Kun kutsui taisteluristeilijä näkyvät varastoon kodin Planet. Jos sinulla ei ole kotona planeetta perustuu planeetta on satunnaisesti poimittu tallentaa Battle Cruiser. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset ovat löytäneet taisteluristeilijä haastetaan. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Aluksen on haastettu ja tallennetaan planeetalla [planet] sektori [sector].";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->noplanets = "Sinulla ei ole mitään planeettoja tallentaa Dreadnought. Menetät Dreadnought ja kaikki kerätty Dreadnought Teos kappaletta.";
			break;

			case "indonesian":
				$this->classname = "Dreadnought artifak";
				$this->description = "Artefak ini akan memanggil Federasi Stripped-Down Battle Cruiser. Pertempuran 400 Cruiser memiliki tingkat teknologi dan dapat ditingkatkan menjadi 900. Battle Cruiser akan TIDAK termasuk pejuang, tambang, baju zirah, energi, tambang deflectors, melarikan diri pod atau perangkat lain. Ketika memanggil Cruiser Pertempuran akan muncul di gudang di Rumah Planet. Jika Anda tidak memiliki rumah planet planet yang berbasis akan secara acak memilih untuk menyimpan Battle Cruiser. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan dalam Pertempuran Cruiser akan dipanggil. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Kapal telah dipanggil dan disimpan di planet [planet] di sektor [sector].";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->noplanets = "Anda tidak memiliki planet apapun untuk menyimpan Dreadnought. Anda kehilangan Dreadnought dan semua artefak yang dikumpulkan Dreadnought potong.";
			break;

			case "norwegian":
				$this->classname = "Dreadnought Artifact";
				$this->description = "Dette Artifact vil sammenkalle et nedstrippet Federation Battle Cruiser. The Battle Cruiser har 400 tech nivåer og kan oppgraderes til 900. The Battle Cruiser vil ikke inkludere jagerfly, miner, rustning, energi, gruve sidevindu, escape pod eller andre enheter. Da tilkalte slaget Cruiser vil vises i lagring på Hjem Planet. Hvis du ikke har et hjem planet en basert planet vil bli tilfeldig plukket ut til å lagre Battle Cruiser. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet slaget Cruiser vil bli innkalt. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Skipet har vært innkalt og lagres på planeten [planet] i sektor [sector].";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->noplanets = "Du eier ikke noen planeter å lagre Dreadnought. Du mister Dreadnought og alle samlet Dreadnought Artifact stykker.";
			break;

			case "portuguese":
				$this->classname = "Dreadnought Artefato";
				$this->description = "Este artefato irá convocar uma enxuta Federação Battle Cruiser. O cruzador tem 400 níveis de tecnologia e pode ser atualizado para 900. O cruzador de batalha não irá incluir os lutadores, minas, armas, energia, defletores de minas, Escape Pod ou qualquer outro dispositivo. Quando chamou o cruzador aparecerá no armazenamento em sua Home Planet. Se você não tiver um planeta um planeta com base serão escolhidos aleatoriamente para armazenar o cruzador de batalha. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas no cruzador serão convocados. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". O navio foi convocado e armazenados no planeta [planet] no sector [sector].";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->noplanets = "Você não possuem quaisquer planetas para armazenar a Dreadnought. Você perde a Dreadnought e todas as peças recolhidas Dreadnought Artefato.";
			break;

			case "swedish":
				$this->classname = "Dreadnought Artefakt";
				$this->description = "Detta Artefakt kommer att sammankalla en avskalad Federation Battle Cruiser. The Battle Cruiser har 400 tech nivåer och kan uppgraderas till 900. The Battle Cruiser kommer inte att omfatta fighters, gruvor, rustningar, energi, avvisare gruva, undkomma pod eller någon annan enhet. En kallelse slaget Cruiser kommer att finnas i lager på din hemplanet. Om du inte har ett hemplanet en dator planet kommer slumpmässigt valde att lagra stridsskepp. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns slaget Cruiser kommer att sammankallas. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Fartyget har kallats och lagrats på planeten [planet] i sektorn [sector].";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->noplanets = "Du äger inte några planeter för att lagra Dreadnought. Du förlorar Dreadnought och alla samlas Dreadnought Artefakt bitar.";
			break;

			default:
				$this->classname = "Dreadnought Artifact";
				$this->description = "This Artifact will summon a Stripped-Down Federation Battle Cruiser.  The Battle Cruiser has 400 tech levels and can be upgraded to 900.  The Battle Cruiser will NOT include fighters, mines, armor, energy, mine deflectors, escape pod or any other device.  When summoned the Battle Cruiser will appear in storage on your Home Planet.  If you don't have a home planet a based planet will be randomly picked to store the Battle Cruiser.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found the Battle Cruiser will be summoned.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  The ship has been summoned and stored on planet [planet] in sector [sector].";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->noplanets = "You do not own any planets to store the Dreadnought.  You lose the Dreadnought and all collected Dreadnought Artifact pieces.";
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
   			if($playerinfo['home_planet_id'] == 0)
   			{
				$findem = $db->SelectLimit("SELECT sector_id, planet_id, name FROM {$db_prefix}planets where owner = " . $playerinfo['player_id'] . " ORDER BY rand()", 1);
		   		db_op_result($findem,__LINE__,__FILE__);
				$home_sector = $findem->fields['sector_id'];
				$home_planet_id = $findem->fields['planet_id'];
				$home_planet_name = $findem->fields['name'];
				if($findem->RecordCount() == 0)
				{
					return $this->noplanets;
				}
   			}
   			else
   			{
 				$findem = $db->SelectLimit("SELECT sector_id, name FROM {$db_prefix}planets where planet_id = $playerinfo[home_planet_id]", 1);
		   		db_op_result($findem,__LINE__,__FILE__);
  				$home_planet_id = $playerinfo['home_planet_id'];
				$home_sector = $findem->fields['sector_id'];
				$home_planet_name = $findem->fields['name'];
   			}
			$findem = $db->SelectLimit("SELECT sector_name FROM {$db_prefix}universe where sector_id = $home_sector", 1);
	   		db_op_result($findem,__LINE__,__FILE__);
			$sector_name = $findem->fields['sector_name'];

			$res = $db->SelectLimit("SELECT basehull FROM {$db_prefix}ship_types WHERE type_id = 90", 1);
			db_op_result($res,__LINE__,__FILE__);
			$shipdata = $res->fields;
			$res->close();
			$debug_query = $db->Execute("INSERT INTO {$db_prefix}ships 
									(player_id,
									class,
									name,
									basehull,
									hull,
									engines,
									power,
									fighter,
									sensors,
									beams,
									torp_launchers,
									torps,
									shields,
									armor,
									armor_pts,
									cloak,
									ecm,
									sector_id,
									energy,
									fighters,
									on_planet,
									planet_id,
									cleared_defenses,
									hull_normal,
									engines_normal,
									power_normal,
									fighter_normal,
									sensors_normal,
									beams_normal,
									torp_launchers_normal,
									shields_normal,
									armor_normal,
									cloak_normal,
									ecm_normal,
									storage_planet_id
									)
									VALUES(" .
									"$playerinfo[player_id]," .		 // player_id
									"'100'," .					   // class
									$db->qstr($playerinfo['character_name'] . "'s Dreadnought") . "," .					// name
									"$shipdata[basehull]," .				// basehull
									"400," .				// hull
									"400," .			 // engines
									"400," .			   // power
									"400," .			// fighter
									"400," .			 // sensors
									"400," .			   // beams
									"400," .	  // torp_launchers
									"0," .							  // torps
									"400," .			 // shields
									"400," .			  // armor
									"$start_armor," .				  // armor_pts
									"0," .			   // cloak
									"400," .				// ecm
									"$home_sector," .		   // sector_id
									"$start_energy," .				  // energy
									"$start_fighters," .				// fighters
									"'Y'," .							// on_planet
									"0," .							  // planet_id
									"'', " .							 // cleared_defenses
									"400," .				// hull
									"400," .			 // engines
									"400," .			   // power
									"400," .			// fighter
									"400," .			 // sensors
									"400," .			   // beams
									"400," .	  // torp_launchers
									"400," .			 // shields
									"400," .			  // armor
									"0," .			   // cloak
									"400," .				// ecm
									"$home_planet_id" .
									")");

			db_op_result($debug_query,__LINE__,__FILE__);

			//get new ship_id
			$res = $db->SelectLimit("SELECT max(ship_id) as ship_id from {$db_prefix}ships WHERE player_id=$playerinfo[player_id]" .
								" AND class='100'", 1);
			$ship_id = $res->fields['ship_id'];
			$res->close();

			$filelist = get_dirlist($gameroot."class/devices/");
			for ($c=0; $c<count($filelist); $c++) {
				if($filelist[$c] != "index.html")
				{
					$device_classname =  str_replace(".inc", "", $filelist[$c]); 
					if(!class_exists($device_classname)){
						include ("class/devices/" . $device_classname . ".inc");
					}
					$device_object = new $device_classname();

					$debug_query = $db->Execute("INSERT INTO {$db_prefix}ship_devices (player_id, ".
												"ship_id, class, device_name, cargo_class, program, techmodify, ".
												"amount) VALUES(" .
												"'$playerinfo[player_id]'," .
												"'$ship_id'," .
												"'" . $device_classname . "'," .
												"'" . $device_object->classname . "'," .
												"'" . $device_object->cargoclass . "'," .
												"'" . $device_object->program . "'," .
												"'" . $device_object->techmodify . "'," .
												"'0'" .
												")");
					db_op_result($debug_query,__LINE__,__FILE__);
				}
			}

			$result2 = $db->Execute("SELECT * FROM {$db_prefix}class_modules_commodities");
			while (!$result2->EOF) 
			{
				$row2 = $result2->fields;
				$amount = 0;
				$debug_query = $db->Execute("INSERT INTO {$db_prefix}ship_holds (".
											"ship_id, class, cargo_name, cargo_class, hold_space,".
											"amount) VALUES(" .
											"'$ship_id'," .
											"'$row2[class]'," .
											"'$row2[classname]'," .
											"'$row2[cargoclass]'," .
											"'$row2[hold_space]'," .
											"'$amount'" .
											")");
				db_op_result($debug_query,__LINE__,__FILE__);
				$result2->Movenext();
			}
			$result2->close();

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);
			insert_news($this->classname . "|" . $playerinfo['character_name'], 1, "artifact");
   			$success = str_replace("[planet]" , $home_planet_name, $this->success);
   			$success = str_replace("[sector]" , $sector_name, $success);
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