<?php
class lowport
{
	var $class = "lowport";
	var $pieces = 5;
	var $min_cloak = 0; // Cloak value of each artifact piece
	var $max_cloak = 200; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 0; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 10; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function lowport()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Madal Port Tehis";
				$this->description = "See Tehis leiate Port madalaima müügi valitud kauba suhtes realspace kiiresti Artefakti on lõpetatud. Kapten valib Kauba Port nad sooviksid leida madalaima müüa hind Realspace. Valdkond Nimi praeguse Kauba Müük Hind kuvatakse. On kokku " . $this->pieces . " tükki, et tuleb leida. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ".";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->l_commodity = "Kaup Müüdud";
				$this->l_amount = "Kogus";
				$this->l_price = "Müügihind";
				$this->l_sector = "Sektor";
				$this->title = "<b><font color=\"lime\" size=\"3\">Valige Kauba leida Madalaim Müük Port</font></b>";
				$this->submit = "Leia Madalaim hind Port";
				$this->commodity = "Valige Kaup:";
				$this->useorlose = "Te peate kasutama seda Artefakti KOHE. Kui sulgete ekraani või kasutama back-nupule kaotate artefaktist.";
			break;

			case "french":
				$this->classname = "Low Port Artefact";
				$this->description = "Cet artefact se trouve le port avec le plus bas de vente sélectionnés produits de base dans REALSPACE dès que l&#39;artefact est terminée. Le capitaine choisit le port des produits de base qu&#39;ils aimeraient trouver les meilleurs prix de vente dans REALSPACE. Le nom de Secteur sur les prix actuels des matières premières Vends sera affiché. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ".";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->l_commodity = "Marchandise vendue";
				$this->l_amount = "Montant";
				$this->l_price = "Sell Price";
				$this->l_sector = "Secteur";
				$this->title = "<b><font color=\"lime\" size=\"3\">Sélectionnez le produit pour y trouver les meilleurs ventes Port</font></b>";
				$this->submit = "Trouver le plus bas Prix Port";
				$this->commodity = "Sélectionnez des produits de base:";
				$this->useorlose = "Vous devez utiliser cet artefact NOW. Si vous fermez l&#39;écran ou utiliser le bouton &quot;retour&quot; vous allez perdre l&#39;artefact.";
			break;

			case "german":
				$this->classname = "Low Port Artefakt";
				$this->description = "Dieses Artefakt wird der Port mit der niedrigsten Verkauf finden Sie ausgewählte Ware in realspace, sobald das Artefakt ist abgeschlossen. Der Kapitän wird die Commodity Port wählen sie möchte den niedrigsten Verkaufspreis in Realspace finden. Die Branche Name mit der aktuellen Commodity Verkaufspreis wird angezeigt. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ".";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->l_commodity = "Ware verkauft";
				$this->l_amount = "Betrag";
				$this->l_price = "Verkaufspreis";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Wählen Sie die Ware an der Suche nach den günstigsten Selling Port</font></b>";
				$this->submit = "Finden Sie Niedrigster Preis Port";
				$this->commodity = "Wählen Sie Commodity:";
				$this->useorlose = "Sie müssen dieses Artefakt ist jetzt betriebsbereit. Wenn Sie nahe dem Bildschirm oder verwenden Sie die Schaltfläche &quot;Zurück&quot; Sie wird das Artefakt zu verlieren.";
			break;

			case "italian":
				$this->classname = "Low Port Artifact";
				$this->description = "Questo artefatto si trova il Porto con la vendita più bassi delle materie prime selezionate nel mondo fisico non appena il manufatto è stato completato. Il capitano sarà selezionare la porta delle merci che vorrebbero trovare il prezzo più basso vendere nel mondo fisico. Nome del settore con l&#39;attuale Commodity Prezzo Vendita sarà visualizzato. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ".";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->l_commodity = "Merce venduta";
				$this->l_amount = "Quantità";
				$this->l_price = "Prezzo Vendita";
				$this->l_sector = "Settore";
				$this->title = "<b><font color=\"lime\" size=\"3\">Selezionare la merce per trovare il minimo di vendita Porto</font></b>";
				$this->submit = "Trova più basso Prezzo Port";
				$this->commodity = "Seleziona Commodity:";
				$this->useorlose = "È necessario utilizzare questo artefatto NOW. Se si chiude lo schermo o utilizzare il pulsante Indietro si perde il manufatto.";
			break;

			case "spanish":
				$this->classname = "Bajo Puerto Artefacto";
				$this->description = "Este artefacto se encuentra el puerto con el más bajo de venta de los productos básicos seleccionados en el espacio real tan pronto como el artefacto se ha completado. El Capitán del Puerto, seleccione los productos básicos que les gustaría encontrar el precio más bajo vender en el espacio real. El nombre del sector con el de los productos básicos Precio de Venta será mostrada. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ".";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->l_commodity = "Mercancía que se vende";
				$this->l_amount = "Cantidad";
				$this->l_price = "Precio de Venta";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Seleccione el producto para encontrar el puerto de venta más bajo</font></b>";
				$this->submit = "Buscar Precio Más Bajo Puerto";
				$this->commodity = "Seleccione los productos básicos:";
				$this->useorlose = "Usted debe usar este artefacto AHORA. Si cierra la pantalla o utilizar el botón Atrás perderá el artefacto.";
			break;

			case "albanian":
				$this->classname = "Objekti i ulët Port";
				$this->description = "Kjo do të gjeni Objekti i Portit me shitjen e mallrave të zgjedhura të ulët në realspace sa më shpejt që Objekti është përfunduar. Kapiteni do të zgjedhin Portit Mallrave ata do të doja të gjeni çmimin më të ulët të shitur në Realspace. Emri Sektori me mall shitet Çmimi aktual do të shfaqet. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ".";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->l_commodity = "Commodity shitur";
				$this->l_amount = "Shuma";
				$this->l_price = "Shitet Çmimi";
				$this->l_sector = "Sektori";
				$this->title = "<b><font color=\"lime\" size=\"3\">Zgjidhni Mallrave për të gjetur Selling uleta Portit</font></b>";
				$this->submit = "Gjej më të ulët Çmimi Port";
				$this->commodity = "Zgjidh Commodity:";
				$this->useorlose = "Ju duhet të përdorni këtë Objekti TANI. Nëse ju ngushtë ekran ose përdorni butonin prapa ju do të humbasin Objekti.";
			break;

			case "catalan":
				$this->classname = "Baix Port Artefacte";
				$this->description = "Aquest artefacte es troba el port amb el més baix de venda dels productes bàsics seleccionats en un espai real tan aviat com l&#39;artefacte s&#39;ha completat. El Capità del Port, seleccioneu els productes bàsics que els agradaria trobar el preu més baix vendre a l&#39;espai real. El nom del sector amb el dels productes bàsics Preu de Venda serà mostrada. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ".";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->l_commodity = "Mercaderia que es ven";
				$this->l_amount = "Quantitat";
				$this->l_price = "Preu de Venda";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Seleccioneu el producte per trobar el port de venda més baix</font></b>";
				$this->submit = "Cerca Preu Més Baix Port";
				$this->commodity = "Seleccioni els productes bàsics:";
				$this->useorlose = "Vostè ha d&#39;usar aquest artefacte ARA. Si tanca la pantalla o utilitzar el botó Enrere perdrà l&#39;artefacte.";
			break;

			case "danish":
				$this->classname = "Lav Port Artifact";
				$this->description = "Dette Artifact vil finde Port med det laveste salg af udvalgte produkter i realspace så snart genstand er afsluttet. Kaptajnen vil vælge Commodity Port de gerne vil finde den laveste salgskurs i Realspace. Sektoraftalen Navn med den nuværende Commodity salgskurs vil blive vist. Der er i alt " . $this->pieces . " stykker, der skal findes. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ".";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->l_commodity = "Handelsvare Solgt";
				$this->l_amount = "Mængde";
				$this->l_price = "Sælge Pris";
				$this->l_sector = "Sektor";
				$this->title = "<b><font color=\"lime\" size=\"3\">Vælg Commodity at finde den laveste salgskurs Port</font></b>";
				$this->submit = "Find Laveste pris Port";
				$this->commodity = "Vælg Vare:";
				$this->useorlose = "Du skal bruge denne genstand NU. Hvis du lukker skærmen eller brug tilbage-knappen vil du miste artefakt.";
			break;

			case "dutch":
				$this->classname = "Laag Port Artifact";
				$this->description = "Dit Artefact vindt u de haven met de laagste verkoopprijs geselecteerde grondstof in realspace zodra het artefact is voltooid. De kapitein kiest de Commodity Port zij zouden willen verkopen aan de laagste prijs in Realspace vinden. De sector Naam met de huidige Commodity verkoopprijs zal worden weergegeven. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ".";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->l_commodity = "Commodity Verkocht";
				$this->l_amount = "Hoeveelheid";
				$this->l_price = "Verkoop Prijs";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Selecteer de Commodity voor de laagste Verkopen Port</font></b>";
				$this->submit = "Vind Laagste prijs Port";
				$this->commodity = "Selecteer Goederencode:";
				$this->useorlose = "U moet dit artefact NU. Als u dichtbij het scherm of gebruik de back-knop verliest u het artefact.";
			break;

			case "finnish":
				$this->classname = "Low Port Teos";
				$this->description = "Tämä Artifact löytää satamaan vähimmäismyyntihinnan valitut raaka-aineiden ja realspace heti artefakti on valmis. Kapteeni valitsee Commodity Port he haluaisivat löytää alin myydä hinta Realspace. Ala nimi nykyisen Commodity myyntihinnan tulee näkyviin. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ".";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->l_commodity = "Commodity Myyty";
				$this->l_amount = "Määrä";
				$this->l_price = "Myyntihinnan";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Valitse Commodity löytää vähimmäismyyntihinnan Port</font></b>";
				$this->submit = "Etsi Alin hinta Port";
				$this->commodity = "Valitse Commodity:";
				$this->useorlose = "Sinun on käytettävä tätä artefakti NYT. Jos suljet näytön tai käytä back-painiketta menetät artefakti.";
			break;

			case "indonesian":
				$this->classname = "Rendah Port artifak";
				$this->description = "Artefak ini akan menemukan Port dengan penjualan terendah yang dipilih komoditi dalam realspace segera setelah selesai artefak. Kapten akan memilih Komoditi Port mereka ingin menemukan harga jual terendah di Realspace. Nama Sektor dengan arus Jual Harga Komoditi akan ditampilkan. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ".";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->l_commodity = "Komoditi Terjual";
				$this->l_amount = "Jumlah";
				$this->l_price = "Harga Jual";
				$this->l_sector = "Sektor";
				$this->title = "<b><font color=\"lime\" size=\"3\">Pilih komoditi untuk menemukan Penjualan Terendah Port</font></b>";
				$this->submit = "Cari Harga Terendah Port";
				$this->commodity = "Pilih Komoditi:";
				$this->useorlose = "Anda harus menggunakan artefak ini SEKARANG. Jika Anda menutup layar atau menggunakan tombol belakang Anda akan kehilangan artefak.";
			break;

			case "norwegian":
				$this->classname = "Low Port Artifact";
				$this->description = "Dette Artifact finner Port med lavest selger valgte vare i realspace så snart gjenstand er fullført. Kapteinen vil velge Commodity Port de ønsker å finne den laveste prisen selger i Realspace. Sektoren Navn med gjeldende Commodity Sell Price vil bli vist. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ".";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->l_commodity = "Commodity Selges";
				$this->l_amount = "Beløp";
				$this->l_price = "Sell Price";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Velg Commodity å finne laveste salgskurs Port</font></b>";
				$this->submit = "Finn lavest pris Port";
				$this->commodity = "Velg Commodity:";
				$this->useorlose = "Du må bruke denne gjenstand NÅ. Hvis du lukker skjermen eller bruke tilbake-knappen, vil du miste gjenstand.";
			break;

			case "portuguese":
				$this->classname = "Baixa do Porto Artefato";
				$this->description = "Este artefato encontra-se o Porto com a menor venda de mercadoria selecionada em Realspace logo que o artefato seja concluída. O capitão irá selecionar a porta de mercadorias que gostaria de encontrar o menor preço de venda no Realspace. O Nome do setor com a atual Commodity Preço de venda será exibida. Há um total de " . $this->pieces . " peças que precisam ser encontrados. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ".";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->l_commodity = "Mercadorias Vendidas";
				$this->l_amount = "Valor";
				$this->l_price = "Preço de venda";
				$this->l_sector = "Setor";
				$this->title = "<b><font color=\"lime\" size=\"3\">Selecione a mercadoria para encontrar a mais baixa venda Porto</font></b>";
				$this->submit = "Pesquisar Menor Preço do Porto";
				$this->commodity = "Selecione Commodity:";
				$this->useorlose = "Você deve utilizar este artefato AGORA. Se você fechar a tela ou use o botão Voltar você vai perder o artefato.";
			break;

			case "swedish":
				$this->classname = "Låg Port Artefakt";
				$this->description = "Detta Artefakt hittar hamnen med den lägsta säljkurs utvalda råvaran i realspace så snart artefakt är klar. Kaptenen kommer att välja Commodity Port de skulle vilja att hitta de lägsta säljkurs i Realspace. Sektorsöverenskommelsen namn med nuvarande Vara försäljningspriset kommer att visas. Finns totalt " . $this->pieces . " bitar som måste hittas. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ".";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->l_commodity = "Commodity Såld";
				$this->l_amount = "Belopp";
				$this->l_price = "Säljkurs";
				$this->l_sector = "Sector";
				$this->title = "<b><font color=\"lime\" size=\"3\">Markera Commodity att hitta det lägsta säljkurs Port</font></b>";
				$this->submit = "Hitta Lägsta pris Port";
				$this->commodity = "Välj Commodity:";
				$this->useorlose = "Du måste använda denna artefakt NOW. Om du stänger skärmen eller använda knappen Tillbaka kommer du att förlora artefakt.";
			break;

			default:
				$this->classname = "Low Port Artifact";
				$this->description = "This Artifact will find the Port with the lowest selling selected commodity in realspace as soon as the artifact is completed.  The Captain will select the Commodity Port they would like to find the lowest sell price in Realspace.  The Sector Name with the current Commodity Sell Price will be displayed.  There are a total of " . $this->pieces . " pieces that need to be found.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->l_commodity = "Commodity Sold";
				$this->l_amount = "Amount";
				$this->l_price = "Sell Price";
				$this->l_sector = "Sector";
				$this->title = "<font color=\"lime\" size=\"3\"><b>Select the Commodity to find the Lowest Selling Port</b></font>";
				$this->submit = "Find Lowest Price Port";
				$this->commodity = "Select Commodity: ";
				$this->useorlose = "You must use this artifact NOW.  If you close the screen or use the back button you will lose the artifact.";
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

			$output ="
<form action=\"artifact_process.php?process_type=post&artifact=" . $this->class ."\" method=\"post\" enctype=\"multipart/form-data\">
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
		<tr BGCOLOR=\"#585980\">
			<td colspan=\"2\"><div align=\"center\">" . $this->title . "</div></td>
		</tr>
		<tr BGCOLOR=\"#3A3B6E\">
			<TD>" . $this->commodity . "</td>
			<TD><select size=\"20\" name=\"port_type\">";

			$cargo_query = $db->Execute("SELECT classname from {$db_prefix}class_modules_commodities WHERE cargosellbuy=0 order by classname ASC");
			db_op_result($cargo_query,__LINE__,__FILE__);
			while (!$cargo_query->EOF)
			{
				$row = $cargo_query->fields;
				$output .= "				<option value=\"$row[classname]\">" . ucwords($row['classname']) . "</option>\n";
				$cargo_query->MoveNext();
			}

			$output .= "</select></td>
		</tr>
		<tr BGCOLOR=\"#000000\">
			<td colspan=\"2\"><div align=\"center\"><font color=\"pink\"><b>" . $this->useorlose . "</b></font></div></td>
		</tr>
 		<tr BGCOLOR=\"#23244F\">
			<td colspan=\"2\"><div align=\"center\"><input type=\"submit\" id=\"" . $this->submit . "\" value=\"" . $this->submit . "\" name=\"" . $this->submit . "\" ></div></td>
		</tr>
	</table>
</div>
</form>";
			if($_SESSION['artifact'] == 0)
			{
				$_SESSION['artifact'] = strtotime(date("Y-m-d H:i:s"));
			}
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
		global $db, $db_prefix, $playerinfo, $inventory_factor, $l_global_mmenu;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces || $_SESSION['artifact'] == 0)
   		{
   			return;
	  	}

		$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
		db_op_result($res,__LINE__,__FILE__);

		$res = $db->SelectLimit("SELECT {$db_prefix}universe.sector_name, {$db_prefix}universe.port_type, {$db_prefix}universe_ports.commodity_price, {$db_prefix}universe_ports.commodity_amount
								FROM {$db_prefix}universe , {$db_prefix}universe_ports 
								WHERE {$db_prefix}universe.port_type = " . $db->qstr(rawurldecode($_POST['port_type'])) . "
								AND {$db_prefix}universe_ports.sector_id = {$db_prefix}universe.sector_id
								AND {$db_prefix}universe.port_type = {$db_prefix}universe_ports.commodity_type
								AND {$db_prefix}universe.sg_sector = 0
								ORDER BY {$db_prefix}universe_ports.commodity_price ASC", 1);
		db_op_result($res,__LINE__,__FILE__);

		$commodity_query = $db->Execute("SELECT delta, itemlimit FROM {$db_prefix}class_modules_commodities WHERE classname=" . $db->qstr(rawurldecode($_POST['port_type'])));
		db_op_result($commodity_query,__LINE__,__FILE__);

		$offered_sell_price = max($res->fields['commodity_price'] - $commodity_query->fields['delta'] * $res->fields['commodity_amount'] / $commodity_query->fields['itemlimit'] * $inventory_factor, 0.01);

		$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"4\" bgcolor=\"#000000\">
		<tr BGCOLOR=\"#585980\">
			<td><b>" . $this->l_sector . "</b></td>
			<td><B>" . $this->l_commodity . "</B></td>
			<td><B>" . $this->l_amount . "</B></td>
			<td><B>" . $this->l_price . "</B></td>
		</tr>
		<tr BGCOLOR=\"#3A3B6E\">
			<td><a href=\"main.php?move_method=real&engage=1&destination=" . rawurldecode($res->fields['sector_name']) . "\">" . $res->fields['sector_name'] . "</a></td>
			<TD>" . ucwords($res->fields['port_type']) . "</td>
			<TD>" . NUMBER($res->fields['commodity_amount']) . "</td>
			<TD>" . NUMBER(floor($offered_sell_price)) . "</td>
		</tr>
        <tr>
          <td colspan=\"4\"><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
		return $output;
	}
}
?>