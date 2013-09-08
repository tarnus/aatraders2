<?php
class backdoor
{
	var $class = "backdoor";
	var $pieces = 15;
	var $min_cloak = 300; // Cloak value of each artifact piece
	var $max_cloak = 375; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 2; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function backdoor()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Backdoor helvetistä Tehis";
				$this->description = "See Tehis loob kahesuunaline lõime seost ühegi SG Sector kui tead nime. Kahesuunaline lõime-link luuakse isegi kui sektor on piirata seda saab tavaliselt abi. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud saate valida SG sektor luua kahesuunaline sulatada lingi kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->failurename = "Ei leia SG sektori järgi nime: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Loo Two-Way Warp Link SG sektor</font></b>";
				$this->sector = "Sisestage Sector Nimi jaoks warplink Sihtkoht:";
				$this->submit = "Loo Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">Two-Way Warp Link Loodud valdkondlike [sectorname].</font></b>";
				$this->federation = "Te ei saa kasutada seda Tehis aastal Föderatsiooni sektor.";
			break;

			case "french":
				$this->classname = "Backdoor from Hell Artefact";
				$this->description = "Cet artefact va créer un lien à double courbure moyen de n&#39;importe quel secteur SG si vous connaissez le nom. A two-way-warp lien sera créé, même si le secteur est à la limite on peut normalement soutien. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez choisir le secteur SG pour créer un lien à double courbure chemin à travers la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->failurename = "Impossible de localiser un secteur SG par ce nom: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Créer Two-Way Lien Warp to SG Secteur</font></b>";
				$this->sector = "Entrez Secteur de destination WarpLink:";
				$this->submit = "Créer Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp lien créé vers le secteur [sectorname].</font></b>";
				$this->federation = "Vous ne pouvez pas utiliser cet artefact dans un secteur de la Fédération.";
			break;

			case "german":
				$this->classname = "Backdoor Artefakt aus der Hölle";
				$this->description = "Dieses Artefakt wird ein Zwei-Wege-Warp-Link zu einer SG Sektor zu erstellen, wenn Sie den Namen wissen. Ein Zwei-Wege-Warp-Link erstellt werden, auch wenn der Sektor an der Grenze kann in der Regel unterstützen. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie die SG Sektor auswählen, um einen Zwei-Wege-Warp-Verbindung durch die Artefakt Liste Befehl zu erstellen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->failurename = "Konnte nicht lokalisiert ein SG Sektor mit diesem Namen: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Erstellen Two-Way Warp Link zur SG Sector</font></b>";
				$this->sector = "Geben Sie Sector Name für WarpLink Ziel:";
				$this->submit = "Warp Link erstellen";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link zum Sektor geschaffen [sectorname].</font></b>";
				$this->federation = "Sie können dieses Artefakt in einer Föderation Sektor.";
			break;

			case "italian":
				$this->classname = "Backdoor from Hell Artefatto";
				$this->description = "Questo artefatto creerà due link curvatura modo per qualsiasi settore SG, se si conosce il nome. A due warp modo-link verrà creato anche se il settore è al limite si può di norma di supporto. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile selezionare il Settore SG per creare un link a due curvatura strada attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->failurename = "Impossibile individuare un settore SG con questo nome: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Create Two-Way Link Warp a SG Settore</font></b>";
				$this->sector = "Inserisci il nome del settore di destinazione WarpLink:";
				$this->submit = "Crea Link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link Creato per settore [sectorname].</font></b>";
				$this->federation = "Non è possibile utilizzare questo artefatto in un settore della Federazione.";
			break;

			case "spanish":
				$this->classname = "Puerta trasera del infierno Artefacto";
				$this->description = "Este artefacto creará un vínculo en dos urdimbre manera de cualquier sector de SG si conoce el nombre. A las dos de la urdimbre forma de enlace, se creará incluso si el sector se encuentra en el límite que normalmente puede apoyar. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el Sector SG para crear un vínculo en dos urdimbre camino a través del comando Lista de Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->failurename = "No se pudo localizar a un sector de SG por este nombre: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crear Two-Way Link Warp a SG Sector</font></b>";
				$this->sector = "Introducir el nombre del Sector de destino WarpLink:";
				$this->submit = "Crear vínculo Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp vínculo creado al Sector [sectorname].</font></b>";
				$this->federation = "Usted no puede utilizar este artefacto en un sector de la Federación.";
			break;

			case "albanian":
				$this->classname = "Backdoor nga ferri Objekti";
				$this->description = "Kjo Objekti i do të krijojë një dy-prish mënyrë e lidhura me ndonjë Sektorin e SP nëse ju e dini emrin. Një dy-prish-link mënyrë do të krijohen edhe në qoftë se sektori është në kufi mund normalisht përkrahje. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni Sektori SG për të krijuar një dy-prish mënyrë lidhje me komandën Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->failurename = "Nuk mund të gjetur një Sektorin e SP me këtë emër: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Krijo Dy-Way Link Warp në Sektorin SG</font></b>";
				$this->sector = "Futni emrin Sektori për destinacion warplink:";
				$this->submit = "Krijo Link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">Dy-Një rrugë Warp Link Krijuar në Sektorin [sectorname].</font></b>";
				$this->federation = "Ju nuk mund të përdorni këtë Objekti në Sektorin e Federatës.";
			break;

			case "catalan":
				$this->classname = "Porta del darrere de l&#39;infern Artefacte";
				$this->description = "Aquest artefacte crearà un vincle en dues ordit manera de qualsevol sector de SG si coneix el nom. A les dues de l&#39;ordit forma d&#39;enllaç, es crearà fins i tot si el sector es troba en el límit que normalment pot donar suport. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar al Sector SG per crear un vincle en dues ordit camí a través de la comanda Llista de Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->failurename = "No es pot localitzar a un sector de SG per aquest nom: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crear Two-Way Link Warp a SG Sector</font></b>";
				$this->sector = "Introduir el nom del Sector de destinació WarpLink:";
				$this->submit = "Crear un vincle Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp vincle creat al Sector [sectorname].</font></b>";
				$this->federation = "No podeu utilitzar aquest artefacte en un sector de la Federació.";
			break;

			case "danish":
				$this->classname = "Backdoor fra helvede Artifact";
				$this->description = "Dette Artifact vil skabe en tovejs-kæde link til en SG sektor, hvis du kender navnet. En to-vejs warp-link vil blive oprettet, selv om sektoren er på grænsen det normalt kan støtte. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet, kan du vælge generalsekretæren Sektor for at oprette en to-vejs kæde link gennem Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->failurename = "Kunne ikke finde en SG Sektor med dette navn: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Opret To-vejs Warp Link til SG Sector</font></b>";
				$this->sector = "Indtast Sektor Navn for warplink destination:";
				$this->submit = "Opret Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">En to-vejs Warp Link Oprettet til sektor [sectorname].</font></b>";
				$this->federation = "Du kan ikke bruge denne Artifact i en Føderation Sector.";
			break;

			case "dutch":
				$this->classname = "Backdoor from Hell Artifact";
				$this->description = "Artefact Dit zal leiden tot een twee-weg warp link naar enige SG Sector als u de naam kent. Een twee-weg warp-link wordt gecreëerd, zelfs als de sector aan de grens kan normaliter steunen. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de SG sector een twee-weg warp verbinding maken via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->failurename = "Kan niet vinden een SG sector met deze naam: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Maak Two-Way Warp Link naar SG Sector</font></b>";
				$this->sector = "Voer Sector Naam voor warplink bestemming:";
				$this->submit = "Maak Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link Gemaakt naar Sector [sectorname].</font></b>";
				$this->federation = "U kunt deze niet gebruiken Artefact in een Federatie sector.";
			break;

			case "finnish":
				$this->classname = "Takaportti from Hell Teos";
				$this->description = "Tämä Teos luo kaksisuuntainen taivuttaa mihinkään SG-ala, jos tiedät nimen. Kaksisuuntainen loimi-yhteys luodaan, vaikka ala on raja se voi yleensä tue. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita SG alan luoda kaksisuuntainen taivuttaa linkin kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->failurename = "Ei löytänyt SG alan tämä nimi: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Luo Two-Way Warp Linkki SG Sector</font></b>";
				$this->sector = "Anna Ala nimi on warplink Kohde:";
				$this->submit = "Luo Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">Two-Way Warp Linkki Lähettänyt sektorille [sectorname].</font></b>";
				$this->federation = "Et voi käyttää tätä Teos on federaatiossa Sector.";
			break;

			case "indonesian":
				$this->classname = "Backdoor from Hell artifak";
				$this->description = "Artefak ini akan menciptakan dua arah warp link ke setiap SG Sektor jika anda tahu nama itu. Seorang dua arah warp-link akan diciptakan bahkan jika sektor di batas normal dapat dukungan. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat memilih SG Sektor untuk membuat dua arah warp link melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->failurename = "Tidak dapat menemukan suatu SG Sektor dengan nama ini: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Buat Two-Way Warp Link ke SG Sektor</font></b>";
				$this->sector = "Sektor Masukkan Nama untuk warplink tujuan:";
				$this->submit = "Buat Link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Link Warp Diciptakan untuk Sektor [sectorname].</font></b>";
				$this->federation = "Anda tidak dapat menggunakan artifak ini dalam Sektor Federasi.";
			break;

			case "norwegian":
				$this->classname = "Backdoor from Hell Artifact";
				$this->description = "Dette Artifact vil opprette en toveis deformere link til noen SG Sector hvis du kjenner navnet. En toveis warp-link vil bli opprettet selv om sektoren er på grensen kan det normalt støtte. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet kan du velge SG Sector å opprette en toveis deformere kobling gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->failurename = "Kunne ikke finne en SG sektor ved dette navnet: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lag Two-Way Warp Link til SG Sector</font></b>";
				$this->sector = "Skriv Sector navn for warplink destinasjon:";
				$this->submit = "Lag Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">En toveis Warp Link Opprettet å sektor [sectorname].</font></b>";
				$this->federation = "Du kan ikke bruke dette fører til en føderasjon sektor.";
			break;

			case "portuguese":
				$this->classname = "Backdoor from Hell Artefato";
				$this->description = "Este artefato irá criar uma ligação bidireccional de deformar a qualquer sector SG se você sabe o nome. Uma duas-warp-way link será criado, mesmo se o setor está no limite, pode normalmente apoio. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode selecionar o setor SG para criar uma ligação nos dois Warp caminho através do comando Lista Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->failurename = "Não foi possível localizar um Sector SG por este nome: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Criar Two-Way Link Warp para SG Setor</font></b>";
				$this->sector = "Digite o nome do Setor de destino WarpLink:";
				$this->submit = "Criar link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link Criado para o Sector [sectorname].</font></b>";
				$this->federation = "Você não pode usar este artefato em um setor da Federação.";
			break;

			case "swedish":
				$this->classname = "Backdoor from Hell Artefakt";
				$this->description = "Detta Artefakt kommer att skapa en tvåvägskommunikation varp länka till någon SG bransch om du känner till namnet. En ömsesidig warp-länken kommer att skapas, även om branschen är på gränsen att det normalt kan stödja. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns kan du välja generalsekreteraren gäller att skapa en ömsesidig varp länk via den fiktiva List kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->failurename = "Kunde inte hitta en SG sektor med detta namn: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Skapa Two-Way Warp Länk till SG Sector</font></b>";
				$this->sector = "Ange Sector Namn för warplink destination:";
				$this->submit = "Skapa Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Länk Skapad av sektorn [sectorname].</font></b>";
				$this->federation = "Du kan inte använda denna Artefakt i en federation Sector.";
			break;

			default:
				$this->classname = "Backdoor from Hell Artifact";
				$this->description = "This Artifact will create a two-way warp link to any SG Sector if you know the name.  A two-way warp-link will be created even if the sector is at the limit it can normally support.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select the SG Sector to create a two-way warp link through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->failurename = "Could not locate an SG Sector by this name: [sectorname]";
				$this->title = "<font size=\"4\" color=\"lime\"><b>Create Two-Way Warp Link to SG Sector</b></font>";
				$this->sector = "Enter Sector Name for warplink destination:";
				$this->submit = "Create Warp Link";
				$this->completedlinks = "<font size=\"4\" color=\"lime\"><b>A Two-Way Warp Link Created to Sector [sectorname].</b></font>";
				$this->federation = "You cannot use this Artifact in a Federation Sector.";
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
		global $db, $db_prefix, $playerinfo, $l_global_mmenu;

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
		global $db, $db_prefix, $playerinfo, $shipinfo, $sectorinfo, $l_global_mmenu;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

	  	$destination = $_POST['destination'];

		if($sectorinfo['zone_id'] == 2)
		{
			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->federation . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
			return $output;
		}

		$result  = $db->Execute("SELECT sector_id FROM {$db_prefix}universe WHERE sector_name=" . $db->qstr($destination) . " and sg_sector!=0");
		db_op_result($result,__LINE__,__FILE__);
		if($result->RecordCount() == 1)
		{
			$target_sector_id = $result->fields['sector_id'];
			$debug_query = $db->Execute ("INSERT INTO {$db_prefix}links SET link_start=$shipinfo[sector_id], 
										link_dest=$target_sector_id");
			db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query = $db->Execute ("INSERT INTO {$db_prefix}links SET link_start=$target_sector_id, 
										 link_dest=$shipinfo[sector_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . str_replace("[sectorname]", $destination, $this->completedlinks) . "</b></font></div></td>
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