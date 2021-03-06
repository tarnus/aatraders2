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
				$this->classname = "Backdoor helvetist� Tehis";
				$this->description = "See Tehis loob kahesuunaline l�ime seost �hegi SG Sector kui tead nime. Kahesuunaline l�ime-link luuakse isegi kui sektor on piirata seda saab tavaliselt abi. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud saate valida SG sektor luua kahesuunaline sulatada lingi kaudu Tehis nimekiri k�sk. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". V�ite kasutada seda Artefakti igal ajal Tehis nimekiri lehek�ljel.";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->failurename = "Ei leia SG sektori j�rgi nime: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Loo Two-Way Warp Link SG sektor</font></b>";
				$this->sector = "Sisestage Sector Nimi jaoks warplink Sihtkoht:";
				$this->submit = "Loo Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">Two-Way Warp Link Loodud valdkondlike [sectorname].</font></b>";
				$this->federation = "Te ei saa kasutada seda Tehis aastal F�deratsiooni sektor.";
			break;

			case "french":
				$this->classname = "Backdoor from Hell Artefact";
				$this->description = "Cet artefact va cr�er un lien � double courbure moyen de n&#39;importe quel secteur SG si vous connaissez le nom. A two-way-warp lien sera cr��, m�me si le secteur est � la limite on peut normalement soutien. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont trouv�s, vous pouvez choisir le secteur SG pour cr�er un lien � double courbure chemin � travers la commande Liste Artefact. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". Vous pouvez utiliser cet objet � tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->failurename = "Impossible de localiser un secteur SG par ce nom: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Cr�er Two-Way Lien Warp to SG Secteur</font></b>";
				$this->sector = "Entrez Secteur de destination WarpLink:";
				$this->submit = "Cr�er Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp lien cr�� vers le secteur [sectorname].</font></b>";
				$this->federation = "Vous ne pouvez pas utiliser cet artefact dans un secteur de la F�d�ration.";
			break;

			case "german":
				$this->classname = "Backdoor Artefakt aus der H�lle";
				$this->description = "Dieses Artefakt wird ein Zwei-Wege-Warp-Link zu einer SG Sektor zu erstellen, wenn Sie den Namen wissen. Ein Zwei-Wege-Warp-Link erstellt werden, auch wenn der Sektor an der Grenze kann in der Regel unterst�tzen. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle Teile gefunden sind, k�nnen Sie die SG Sektor ausw�hlen, um einen Zwei-Wege-Warp-Verbindung durch die Artefakt Liste Befehl zu erstellen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie k�nnen dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->failurename = "Konnte nicht lokalisiert ein SG Sektor mit diesem Namen: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Erstellen Two-Way Warp Link zur SG Sector</font></b>";
				$this->sector = "Geben Sie Sector Name f�r WarpLink Ziel:";
				$this->submit = "Warp Link erstellen";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link zum Sektor geschaffen [sectorname].</font></b>";
				$this->federation = "Sie k�nnen dieses Artefakt in einer F�deration Sektor.";
			break;

			case "italian":
				$this->classname = "Backdoor from Hell Artefatto";
				$this->description = "Questo artefatto creer� due link curvatura modo per qualsiasi settore SG, se si conosce il nome. A due warp modo-link verr� creato anche se il settore � al limite si pu� di norma di supporto. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, � possibile selezionare il Settore SG per creare un link a due curvatura strada attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". � possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->failurename = "Impossibile individuare un settore SG con questo nome: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Create Two-Way Link Warp a SG Settore</font></b>";
				$this->sector = "Inserisci il nome del settore di destinazione WarpLink:";
				$this->submit = "Crea Link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link Creato per settore [sectorname].</font></b>";
				$this->federation = "Non � possibile utilizzare questo artefatto in un settore della Federazione.";
			break;

			case "spanish":
				$this->classname = "Puerta trasera del infierno Artefacto";
				$this->description = "Este artefacto crear� un v�nculo en dos urdimbre manera de cualquier sector de SG si conoce el nombre. A las dos de la urdimbre forma de enlace, se crear� incluso si el sector se encuentra en el l�mite que normalmente puede apoyar. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el Sector SG para crear un v�nculo en dos urdimbre camino a trav�s del comando Lista de Artefacto. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la p�gina Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->failurename = "No se pudo localizar a un sector de SG por este nombre: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crear Two-Way Link Warp a SG Sector</font></b>";
				$this->sector = "Introducir el nombre del Sector de destino WarpLink:";
				$this->submit = "Crear v�nculo Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp v�nculo creado al Sector [sectorname].</font></b>";
				$this->federation = "Usted no puede utilizar este artefacto en un sector de la Federaci�n.";
			break;

			case "albanian":
				$this->classname = "Backdoor nga ferri Objekti";
				$this->description = "Kjo Objekti i do t� krijoj� nj� dy-prish m�nyr� e lidhura me ndonj� Sektorin e SP n�se ju e dini emrin. Nj� dy-prish-link m�nyr� do t� krijohen edhe n� qoft� se sektori �sht� n� kufi mund normalisht p�rkrahje. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur ju mund t� zgjidhni Sektori SG p�r t� krijuar nj� dy-prish m�nyr� lidhje me komand�n Lista Objekti. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ". Ju mund t� p�rdorni k�t� Objekti n� �do koh� nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->failurename = "Nuk mund t� gjetur nj� Sektorin e SP me k�t� em�r: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Krijo Dy-Way Link Warp n� Sektorin SG</font></b>";
				$this->sector = "Futni emrin Sektori p�r destinacion warplink:";
				$this->submit = "Krijo Link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">Dy-Nj� rrug� Warp Link Krijuar n� Sektorin [sectorname].</font></b>";
				$this->federation = "Ju nuk mund t� p�rdorni k�t� Objekti n� Sektorin e Federat�s.";
			break;

			case "catalan":
				$this->classname = "Porta del darrere de l&#39;infern Artefacte";
				$this->description = "Aquest artefacte crear� un vincle en dues ordit manera de qualsevol sector de SG si coneix el nom. A les dues de l&#39;ordit forma d&#39;enlla�, es crear� fins i tot si el sector es troba en el l�mit que normalment pot donar suport. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar al Sector SG per crear un vincle en dues ordit cam� a trav�s de la comanda Llista de Artefacte. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vost� pot usar aquest artefacte en qualsevol moment des de la p�gina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->failurename = "No es pot localitzar a un sector de SG per aquest nom: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crear Two-Way Link Warp a SG Sector</font></b>";
				$this->sector = "Introduir el nom del Sector de destinaci� WarpLink:";
				$this->submit = "Crear un vincle Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp vincle creat al Sector [sectorname].</font></b>";
				$this->federation = "No podeu utilitzar aquest artefacte en un sector de la Federaci�.";
			break;

			case "danish":
				$this->classname = "Backdoor fra helvede Artifact";
				$this->description = "Dette Artifact vil skabe en tovejs-k�de link til en SG sektor, hvis du kender navnet. En to-vejs warp-link vil blive oprettet, selv om sektoren er p� gr�nsen det normalt kan st�tte. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle brikker er fundet, kan du v�lge generalsekret�ren Sektor for at oprette en to-vejs k�de link gennem Artifact List kommando. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->failurename = "Kunne ikke finde en SG Sektor med dette navn: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Opret To-vejs Warp Link til SG Sector</font></b>";
				$this->sector = "Indtast Sektor Navn for warplink destination:";
				$this->submit = "Opret Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">En to-vejs Warp Link Oprettet til sektor [sectorname].</font></b>";
				$this->federation = "Du kan ikke bruge denne Artifact i en F�deration Sector.";
			break;

			case "dutch":
				$this->classname = "Backdoor from Hell Artifact";
				$this->description = "Artefact Dit zal leiden tot een twee-weg warp link naar enige SG Sector als u de naam kent. Een twee-weg warp-link wordt gecre�erd, zelfs als de sector aan de grens kan normaliter steunen. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de SG sector een twee-weg warp verbinding maken via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
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
				$this->description = "T�m� Teos luo kaksisuuntainen taivuttaa mihink��n SG-ala, jos tied�t nimen. Kaksisuuntainen loimi-yhteys luodaan, vaikka ala on raja se voi yleens� tue. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset l�ytyy voit valita SG alan luoda kaksisuuntainen taivuttaa linkin kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit k�ytt�� t�t� artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->failurename = "Ei l�yt�nyt SG alan t�m� nimi: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Luo Two-Way Warp Linkki SG Sector</font></b>";
				$this->sector = "Anna Ala nimi on warplink Kohde:";
				$this->submit = "Luo Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">Two-Way Warp Linkki L�hett�nyt sektorille [sectorname].</font></b>";
				$this->federation = "Et voi k�ytt�� t�t� Teos on federaatiossa Sector.";
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
				$this->description = "Dette Artifact vil opprette en toveis deformere link til noen SG Sector hvis du kjenner navnet. En toveis warp-link vil bli opprettet selv om sektoren er p� grensen kan det normalt st�tte. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet kan du velge SG Sector � opprette en toveis deformere kobling gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand n�r som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->failurename = "Kunne ikke finne en SG sektor ved dette navnet: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lag Two-Way Warp Link til SG Sector</font></b>";
				$this->sector = "Skriv Sector navn for warplink destinasjon:";
				$this->submit = "Lag Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">En toveis Warp Link Opprettet � sektor [sectorname].</font></b>";
				$this->federation = "Du kan ikke bruke dette f�rer til en f�derasjon sektor.";
			break;

			case "portuguese":
				$this->classname = "Backdoor from Hell Artefato";
				$this->description = "Este artefato ir� criar uma liga��o bidireccional de deformar a qualquer sector SG se voc� sabe o nome. Uma duas-warp-way link ser� criado, mesmo se o setor est� no limite, pode normalmente apoio. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas voc� pode selecionar o setor SG para criar uma liga��o nos dois Warp caminho atrav�s do comando Lista Artefato. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". Voc� pode usar esse artefato, a qualquer momento a partir da p�gina Lista de Artefato.";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->failurename = "N�o foi poss�vel localizar um Sector SG por este nome: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Criar Two-Way Link Warp para SG Setor</font></b>";
				$this->sector = "Digite o nome do Setor de destino WarpLink:";
				$this->submit = "Criar link Warp";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp Link Criado para o Sector [sectorname].</font></b>";
				$this->federation = "Voc� n�o pode usar este artefato em um setor da Federa��o.";
			break;

			case "swedish":
				$this->classname = "Backdoor from Hell Artefakt";
				$this->description = "Detta Artefakt kommer att skapa en tv�v�gskommunikation varp l�nka till n�gon SG bransch om du k�nner till namnet. En �msesidig warp-l�nken kommer att skapas, �ven om branschen �r p� gr�nsen att det normalt kan st�dja. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar finns kan du v�lja generalsekreteraren g�ller att skapa en �msesidig varp l�nk via den fiktiva List kommandot. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan anv�nda denna artefakt som helst fr�n den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->failurename = "Kunde inte hitta en SG sektor med detta namn: [sectorname]";
				$this->title = "<b><font size=\"4\" color=\"lime\">Skapa Two-Way Warp L�nk till SG Sector</font></b>";
				$this->sector = "Ange Sector Namn f�r warplink destination:";
				$this->submit = "Skapa Warp Link";
				$this->completedlinks = "<b><font size=\"4\" color=\"lime\">A Two-Way Warp L�nk Skapad av sektorn [sectorname].</font></b>";
				$this->federation = "Du kan inte anv�nda denna Artefakt i en federation Sector.";
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