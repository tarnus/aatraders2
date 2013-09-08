<?php
class basedplanet
{
	var $class = "basedplanet";
	var $pieces = 3;
	var $min_cloak = 0; // Cloak value of each artifact piece
	var $max_cloak = 150; // Maximum Cloak value of each artifact piece
	var $scoremax = 400000; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $scoremax_text = "400,000"; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 5; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.
	var $limitpercentage = 70; // The percentage of the maximum colonists allowed on a newly based planet to place on this planet.

	function basedplanet()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Based Planet Tehis";
				$this->description = "See Tehis loob põhjal planeeti " . $this->limitpercentage . "% Maksimaalsest kolonistid igal Realspace või müügi valdkonnas, mis on ei kuulu kellelegi teisele ja on ruumi planeedil. Kui sinu skoor jõuab " . $this->scoremax_text . " te ei näe või pikap see artefaktist. Kui teil on kaasas üks kaotate seda. On kokku. &quot;$ This-&gt; tükki.&quot; Tükki, et tuleb leida. Kui kõik nupud on leitud saate valida, kui ehitada planeedi kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->toomanyplanets = "Liiga palju on planeete selles sektoris.";
				$this->l_gns_forbid = "Loomine planeedi selles sektoris ei ole lubatud.";
				$this->l_gns_bforbid = "Aluseid selles valdkonnas on häiriv oma Genesis seade. Planet loomine ei ole võimalik.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Loo põhjal Planet Tehis</font></b>";
				$this->question = "Kas soovite luua planeedi selles sektoris?";
				$this->submit = "Vastus küsimusele";
			break;

			case "french":
				$this->classname = "Sur la base Planet Artefact";
				$this->description = "Cet artefact va créer une planète basée à " . $this->limitpercentage . "% Des colons maximale dans tout REALSPACE ou SG secteur qui n&#39;est pas possédé par quelqu&#39;un d&#39;autre et a de la place pour la planète. Une fois votre score atteint " . $this->scoremax_text . " vous ne serez pas en mesure de voir ou de ramassage cet artefact. Si vous transportez celle que vous allez perdre. Il ya un total de &quot;. $ This-&gt; pièces.&quot; Morceaux qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez choisir le moment de construire la planète par la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->toomanyplanets = "Il ya des planètes trop nombreux dans ce secteur.";
				$this->l_gns_forbid = "Création d&#39;une planète dans ce secteur n&#39;est pas permise.";
				$this->l_gns_bforbid = "Les bases de ce secteur sont interférer avec votre appareil genèse. Planet création n&#39;est pas possible.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Créer la base Planet Artefact</font></b>";
				$this->question = "Voulez-vous créer une planète dans ce secteur?";
				$this->submit = "Question Réponse";
			break;

			case "german":
				$this->classname = "Basierend Planet Artefakt";
				$this->description = "Dieses Artefakt wird eine Grundlage Planet mit " . $this->limitpercentage . "% Der maximalen Kolonisten in jedem Realspace oder SG Sektor, die nicht von jemand anderem gehört und hat Platz für den Planeten. Nachdem Sie Ihre Gäste erreicht " . $this->scoremax_text . " Sie werden nicht in der Lage sein zu sehen, oder dieses Artefakt Pickup. Wenn Sie sich tragen Sie ein, wird es verlieren. Es gibt insgesamt &quot;. $ This-&gt; Stück.&quot; Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie wählen, wenn auf dem Planeten durch das Artefakt Liste Befehl zu bauen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->toomanyplanets = "Es gibt zu viele Planeten in diesem Sektor.";
				$this->l_gns_forbid = "Erstellen eines Planeten in diesem Sektor ist nicht gestattet.";
				$this->l_gns_bforbid = "Die Basen sind in diesem Sektor beeinträchtigen Ihre Entstehung Gerät. Planet Einrichtung nicht möglich.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Erstellen der Grundlage Planet Artefakt</font></b>";
				$this->question = "Möchten Sie einen Planeten in diesem Sektor zu schaffen?";
				$this->submit = "Beantwortung der zweiten Frage";
			break;

			case "italian":
				$this->classname = "Basato Planet Artifact";
				$this->description = "Artefatto questo creerà un pianeta, basata con " . $this->limitpercentage . "% Dei coloni massimo in ogni mondo fisico o SG settore che non è di proprietà di qualcun altro e ha spazio per il pianeta. Una volta che il tuo punteggio raggiunge " . $this->scoremax_text . " non sarà in grado di vedere o pick-up questo artefatto. Se si stanno realizzando quello che la perderà. Ci sono un totale di &quot;. $ This-&gt; pezzi.&quot; Pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile scegliere se costruire il pianeta attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->toomanyplanets = "Ci sono troppi pianeti in questo settore.";
				$this->l_gns_forbid = "Creazione di un pianeta in questo settore non è consentito.";
				$this->l_gns_bforbid = "Le basi di questo settore stanno interferendo con il dispositivo Genesis. La creazione di Planet non è possibile.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crea Basato Planet Artefatto</font></b>";
				$this->question = "Vuoi creare un pianeta in questo settore?";
				$this->submit = "Risposta Interrogazione";
			break;

			case "spanish":
				$this->classname = "Basado Planet Artefacto";
				$this->description = "Este artefacto creará un planeta con base " . $this->limitpercentage . "% De los colonos máxima en cualquier espacio real o SG sector que no es propiedad de otra persona y tiene espacio para el planeta. Una vez que el marcador llega a " . $this->scoremax_text . " usted no será capaz de ver o de recolección de este artefacto. Si está llevando a que usted perderá. Hay un total de &quot;. $ This-&gt; partes.&quot; Piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran que puede seleccionar al crear el planeta a través del comando Lista de Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->toomanyplanets = "Hay demasiados planetas en este sector.";
				$this->l_gns_forbid = "Creación de un planeta en este sector no está permitido.";
				$this->l_gns_bforbid = "Las bases de este sector están interfiriendo con su dispositivo Génesis. La creación de Planeta no es posible.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crear la base Planet Artefacto</font></b>";
				$this->question = "¿Desea crear un planeta en este sector?";
				$this->submit = "Pregunta Respuesta";
			break;

			case "albanian":
				$this->classname = "Bazuar Planet Objekti";
				$this->description = "Kjo Objekti i do të krijojë një bazë Planet me " . $this->limitpercentage . "% E kolonistët maksimale në çdo Realspace ose SG Sektori që nuk është në pronësi nga dikush tjetër dhe ka vend për planetin. Pasi Rezultati juaj arrin " . $this->scoremax_text . " ju nuk do të jetë në gjendje për të parë ose përmirësim këtë Objekti. Qoftë se keni me vete një nga ju do të humbni atë. Ka një numër të përgjithshëm të &quot;. $ This-&gt; copë.&quot; Pjesë të cilat duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni kur për të ndërtuar planetin nëpërmjet komandës Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->toomanyplanets = "Ka shumë planetë në këtë sektor.";
				$this->l_gns_forbid = "Krijimi i një planet në këtë sektor nuk është e lejuar.";
				$this->l_gns_bforbid = "Bazat në këtë sektor janë të ndërhyrë me pajisjen tuaj gjenezë. Krijimin Planeti nuk është e mundshme.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Krijo Bazuar Planet Objekti</font></b>";
				$this->question = "A dëshironi të krijoni një planet në këtë sektor?";
				$this->submit = "Pyetje Përgjigje";
			break;

			case "catalan":
				$this->classname = "Basat Planet Artefacte";
				$this->description = "Aquest artefacte crearà un planeta amb base " . $this->limitpercentage . "% Dels colons màxima en qualsevol espai real o SG sector que no és propietat d&#39;una altra persona i té espai per al planeta. Una vegada que el marcador arriba a " . $this->scoremax_text . " vostè no serà capaç de veure o de recollida d&#39;aquest artefacte. Si està duent a que vostè perdrà. Hi ha un total de &quot;. $ This-&gt; parts.&quot; Peces que necessiten ser trobats. Un cop que totes les peces es troben que pot seleccionar en crear al planeta a través de la comanda Llista de Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->toomanyplanets = "Hi ha massa planetes en aquest sector.";
				$this->l_gns_forbid = "Creació d&#39;un planeta en aquest sector no està permès.";
				$this->l_gns_bforbid = "Les bases d&#39;aquest sector estan interferint amb el seu dispositiu Gènesi. La creació de Planeta no és possible.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Crear la base Planet Artefacte</font></b>";
				$this->question = "Voleu crear un planeta en aquest sector?";
				$this->submit = "Pregunta Resposta";
			break;

			case "danish":
				$this->classname = "Baseret Planet Artifact";
				$this->description = "Dette Artifact vil skabe en Baseret Planet med " . $this->limitpercentage . "% Af den maksimale kolonister i nogen Realspace eller SG sektor, der ikke ejes af en anden, og har plads til planeten. Når din score når " . $this->scoremax_text . " vil du ikke kunne se eller pickup denne artefakt. Hvis du medbringer en du vil miste det. Der er i alt &quot;. $ This-&gt; stykker.&quot; Stykker, der skal findes. Når alle brikker er fundet, kan du vælge, hvornår de skal bygge planeten gennem Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->toomanyplanets = "Der er for mange planeter i denne sektor.";
				$this->l_gns_forbid = "Oprettelse af en planet i denne sektor er ikke tilladt.";
				$this->l_gns_bforbid = "Baserne i denne sektor er at gribe ind med din tilblivelse enheden. Planet skabelse ikke muligt.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Opret Baseret Planet Artifact</font></b>";
				$this->question = "Ønsker du at oprette en planet i denne sektor?";
				$this->submit = "Svar Spørgsmål";
			break;

			case "dutch":
				$this->classname = "Gebaseerd Planet Artifact";
				$this->description = "Artefact Dit zal een Gebaseerd Planet met " . $this->limitpercentage . "% Van de maximale kolonisten in ieder Realspace of SG sector die niet het eigendom is van iemand anders en heeft ruimte voor de planeet. Zodra uw score bereikt " . $this->scoremax_text . " u zult niet in staat zijn om te zien of dit artefact pickup. Als je bij je hebt die je zal het verliezen. In totaal zijn er van &quot;. $ This-&gt; stukken.&quot; Stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u bij om de planeet te bouwen via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->toomanyplanets = "Er zijn te veel planeten in deze sector.";
				$this->l_gns_forbid = "Het creëren van een planeet in deze sector is niet toegestaan.";
				$this->l_gns_bforbid = "De bases in deze sector zijn ontstaan bemoeien met uw apparaat. Planet schepping niet mogelijk.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Maak Based Planet Artifact</font></b>";
				$this->question = "Wilt u een planeet in deze sector te creëren?";
				$this->submit = "Vraag Antwoord";
			break;

			case "finnish":
				$this->classname = "Perustuu Planet Teos";
				$this->description = "Tämä Teos luo perusteella maapallon " . $this->limitpercentage . "% Suurimmasta siirtolaisten missään Realspace tai SG ala, joka ei ole omistaa joku muu ja on tilaa planeetan. Kun pisteet saavuttaa " . $this->scoremax_text . " et voi nähdä tai pickup tämän artefakti. Jos olet, joilla on yksi menetät sen. On yhteensä &quot;. $ This-&gt; kappaletta.&quot; Kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita, kun rakentaa planeetan läpi Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->toomanyplanets = "On liian monia planeettoja tällä alalla.";
				$this->l_gns_forbid = "Luominen Planet tällä alalla ei ole sallittua.";
				$this->l_gns_bforbid = "Perustaa tällä alalla häiritsevät teidän Genesis laitteeseen. Planet luominen ei ole mahdollista.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Luo perusteella Planet Teos</font></b>";
				$this->question = "Haluatko luoda planeetan tällä alalla?";
				$this->submit = "Vastaus kysymykseen";
			break;

			case "indonesian":
				$this->classname = "Planet Berdasarkan artifak";
				$this->description = "Artefak ini akan menciptakan sebuah Berbasis Planet dengan " . $this->limitpercentage . "% Dari koloni maksimum dalam Realspace atau SG Sektor yang tidak dimiliki oleh orang lain dan memiliki ruangan untuk planet. Setelah Anda mencapai skor " . $this->scoremax_text . " Anda tidak akan dapat melihat atau pickup artifak ini. Jika Anda membawa salah satu Anda akan kehilangan itu. Ada total &quot;. $ This-&gt; keping.&quot; Potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan, Anda dapat memilih ketika untuk membangun planet melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->toomanyplanets = "Ada terlalu banyak planet di sektor ini.";
				$this->l_gns_forbid = "Menciptakan sebuah planet di sektor ini tidak diijinkan.";
				$this->l_gns_bforbid = "Base di sektor ini mengganggu perangkat asal Anda. Penciptaan planet tidak mungkin.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Buat Planet Berdasarkan artifak</font></b>";
				$this->question = "Apakah Anda ingin menciptakan sebuah planet di sektor ini?";
				$this->submit = "Jawab Pertanyaan";
			break;

			case "norwegian":
				$this->classname = "Basert Planet Artifact";
				$this->description = "Dette Artifact vil opprette en Basert Planet med " . $this->limitpercentage . "% Av maksimal kolonistene i noen Realspace eller SG sektor som ikke eies av noen andre, og har plass til planeten. Når score når " . $this->scoremax_text . " vil du ikke kunne se eller pickup denne gjenstand. Hvis du er bærer den du vil miste den. Det er totalt &quot;. $ This-&gt; stykker.&quot; Stykker som trenger å bli funnet. Når alle brikkene er funnet kan du velge når du skal bygge planeten gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->toomanyplanets = "Det er for mange planeter i denne sektoren.";
				$this->l_gns_forbid = "Opprette en planet i denne sektoren er ikke tillatt.";
				$this->l_gns_bforbid = "Den baser i denne sektoren er i konflikt med din genesis enheten. Planet etableringen ikke mulig.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lag Basert Planet Artifact</font></b>";
				$this->question = "Ønsker du å opprette en planet i denne sektoren?";
				$this->submit = "Svar på spørsmål";
			break;

			case "portuguese":
				$this->classname = "Baseado Planet Artefato";
				$this->description = "Este artefato vai criar um planeta com base " . $this->limitpercentage . "% Dos colonos máxima em qualquer Realspace ou Setor SG que não é propriedade de alguém e tem espaço para o planeta. Uma vez que sua pontuação atinge " . $this->scoremax_text . " você não será capaz de ver ou pickup este artefato. Se você estiver carregando um que você vai perdê-la. Há um total de &quot;. $ This-&gt; peças.&quot; Peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode selecionar quando construir o planeta através do comando List Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->toomanyplanets = "Há muitos planetas neste sector.";
				$this->l_gns_forbid = "Criando um planeta neste setor não é permitido.";
				$this->l_gns_bforbid = "As bases deste sector estão a interferir com o seu dispositivo gênese. Criação Planet não é possível.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Criar Baseado Planet Artefato</font></b>";
				$this->question = "Você deseja criar um planeta neste sector?";
				$this->submit = "Pergunta de Resposta";
			break;

			case "swedish":
				$this->classname = "Baserat Planet Artefakt";
				$this->description = "Detta Artefakt kommer att skapa en Baserat Planet med " . $this->limitpercentage . "% Av den maximala kolonisterna i någon Realspace eller SG sektor som inte ägs av någon annan och har plats för planeten. När din poäng når " . $this->scoremax_text . " Du kommer inte att kunna se eller pickup denna artefakt. Om du bär en du kommer att förlora det. Det finns totalt &quot;. $ This-&gt; bitar.&quot; Bitar som måste hittas. När alla bitar finns kan du välja när du ska bygga planeten genom Artefakt List kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->toomanyplanets = "Det finns alltför många planeter i denna sektor.";
				$this->l_gns_forbid = "Skapa en planet inom denna sektor är inte tillåten.";
				$this->l_gns_bforbid = "Serna i denna sektor stör din genesis enheten. Planet skapande not possible.";
				$this->title = "<b><font size=\"4\" color=\"lime\">Skapa Baserat Planet Artefakt</font></b>";
				$this->question = "Vill du skapa en planet i denna sektor?";
				$this->submit = "Svar Fråga";
			break;

			default:
				$this->classname = "Based Planet Artifact";
				$this->description = "This Artifact will create a Based Planet with " . $this->limitpercentage . "% of the maximum colonists in any Realspace or SG Sector that isn't owned by someone else and has room for the planet.  Once your score reaches " . $this->scoremax_text . " you will not be able to see or pickup this artifact.  If you are carrying one you will lose it.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select when to build the planet through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->toomanyplanets = "There are too many planets in this sector.";
				$this->l_gns_forbid = "Creating a planet in this sector is not permitted.";
				$this->l_gns_bforbid = "The bases in this sector are interfering with your genesis device. Planet creation not possible.";
				$this->title = "<font size=\"4\" color=\"lime\"><b>Create Based Planet Artifact</b></font>";
				$this->question = "Do you wish to create a planet in this sector?";
				$this->submit = "Answer Question";
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
		global $db, $db_prefix, $playerinfo, $l_yes, $l_no, $l_global_mmenu;

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
			<TD>" . $this->question . "</td>
			<TD><input type=\"radio\" name=\"doit\" value=\"yes\" checked> $l_yes
			<input type=\"radio\" name=\"doit\" value=\"no\"> $l_no</td>
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
		global $db, $db_prefix, $playerinfo, $sectorinfo, $shipinfo, $l_global_mmenu, $persuasion_countdown_max;
		global $colonist_limit, $planet_prod_low_percent, $planet_prod_high_percent, $planet_production_skew;
		global $base_credits, $default_prod_fighters, $default_prod_torp;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		if($_POST['doit'] == "yes")
		{
			include ("globals/myrand.inc");

			$persuasion_countdown = mt_rand(floor($persuasion_countdown_max / 3), $persuasion_countdown_max * 2);
			$old_owner_rating = 2;
			$colonistlimit = floor($colonist_limit * ($this->limitpercentage / 100));

			$res = $db->SelectLimit("SELECT {$db_prefix}universe.zone_id, {$db_prefix}zones.allow_planet, {$db_prefix}zones.team_zone, " .
									"{$db_prefix}zones.owner FROM {$db_prefix}zones,{$db_prefix}universe WHERE " .
									"{$db_prefix}zones.zone_id=$sectorinfo[zone_id] AND {$db_prefix}universe.sector_id = $shipinfo[sector_id]", 1);
			$query97 = $res->fields;

			$result3 = $db->Execute("SELECT COUNT(planet_id) AS total FROM {$db_prefix}planets WHERE sector_id='$shipinfo[sector_id]'");
			$num_planets = $result3->fields['total'];
			$result3->close();

			if ($num_planets >= $sectorinfo['star_size'])
			{
				$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->toomanyplanets . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
				return $output;
			}

			if ($query97['allow_planet'] == 'N')
			{
				$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->l_gns_forbid . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
				return $output;
			}
			elseif ($query97['allow_planet'] == 'L')
			{
				if ($query97['team_zone'] == 'N')
				{
					if ($playerinfo['team'] == 0 && $playerinfo['player_id'] != $query97['owner'])
					{
						$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->l_gns_bforbid . "</b></font></div></td>
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
						$res = $db->SelectLimit("SELECT team FROM {$db_prefix}players WHERE player_id=$query97[owner]", 1);
						$ownerinfo = $res->fields;
						if ($ownerinfo['team'] != $playerinfo['team'] && $playerinfo['player_id'] != $query97['owner'])
						{
							$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->l_gns_bforbid . "</b></font></div></td>
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
				elseif ($playerinfo['team'] != $query97['owner'])
				{
					$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->l_gns_bforbid . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
					return $output;
				}
			}

			$stamp = date("Y-m-d H:i:s");
			$defaultcargototal = 0;
			$extracargototal = 0;

			$cargo_query = $db->SelectLimit("SELECT * from {$db_prefix}class_modules_commodities where defaultcargoplanet!=1 and cargoplanet=1 order by default_create_percent DESC", 1);
			db_op_result($cargo_query,__LINE__,__FILE__);

			$p_create_ratio = 100 / $cargo_query->fields['default_create_percent'];

			$cargo_query = $db->Execute("SELECT default_create_percent, classname, cargoclass, default_prod, default_indy_prod, goodevil, defaultcargoplanet, cargoplanet from {$db_prefix}class_modules_commodities where defaultcargoplanet=1 or cargoplanet=1");
			db_op_result($cargo_query,__LINE__,__FILE__);
			while (!$cargo_query->EOF) 
			{
				$cargo_info = $cargo_query->fields;
				if($cargo_info['defaultcargoplanet'] == 1)
				{
					$dnewcargotype[$defaultcargototal] = $cargo_info['classname'];
					$dcargoclass[$defaultcargototal] = $cargo_info['cargoclass'];
					$ddefault_prod[$defaultcargototal] = $cargo_info['default_prod'];
					$ddefault_indy_prod[$defaultcargototal] = $cargo_info['default_indy_prod'];
					$dis_prod[$defaultcargototal] = ($cargo_info['cargoclass'] == "commodity") ? 1 : 0;
					$dgoodevil[$defaultcargototal] = $cargo_info['goodevil'];
					$defaultcargototal++;
				}
				else
				{
					if($cargo_info['cargoplanet'] == 1)
					{
						$newcargotype[$extracargototal] = $cargo_info['classname'];
						$cargoclass[$extracargototal] = $cargo_info['cargoclass'];
						$default_prod[$extracargototal] = $cargo_info['default_prod'];
						$default_indy_prod[$extracargototal] = $cargo_info['default_indy_prod'];
						$is_prod[$extracargototal] = ($cargo_info['cargoclass'] == "commodity") ? 1 : 0;
						$goodevil[$extracargototal] = $cargo_info['goodevil'];
						$p_create_percent[$extracargototal] = $cargo_info['default_create_percent'] * $p_create_ratio;
						$extracargototal++;
					}
				}
				$cargo_query->Movenext();
			}

			array_multisort($p_create_percent, $newcargotype, $cargoclass, $default_prod, $default_indy_prod, $is_prod, $goodevil);

			$insertlist = "";
			$insertlistprod = "";
			for($ii = 0; $ii < $defaultcargototal; $ii++)
			{
				if($ddefault_prod[$ii] > 0)
				{
					$insertlist .= ", prod_" . AAT_strtolower($dnewcargotype[$ii]);
					$insertlistprod .= ", '$ddefault_prod[$ii]'";
				}
			}

			if(mt_rand(0, 100) < 10 && $extracargototal != 0)
			{
				$specialcargo = mt_rand(0, 10000);
				for($checkcargo = $extracargototal - 1; $checkcargo >= 0; $checkcargo--)
				{
					if($specialcargo < floor($p_create_percent[$checkcargo] * 100))
					{
						$special_cargo = $newcargotype[$checkcargo];
						$special_goodevil = $goodevil[$checkcargo];
					}
				}
			}
			else
			{
				$special_cargo = '';
				$special_goodevil = 0;
			}

			if(mt_rand(1, 100) <= $planet_production_skew)
			{
				$organics_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
			}
			else
			{
				$organics_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
			}

			if(mt_rand(1, 100) <= $planet_production_skew)
			{
				$ore_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
			}
			else
			{
				$ore_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
			}

			if(mt_rand(1, 100) <= $planet_production_skew)
			{
				$goods_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
			}
			else
			{
				$goods_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
			}

			if(mt_rand(1, 100) <= $planet_production_skew)
			{
				$energy_planet = (float)sprintf("%01.4f", (myrand(0, floor(30000 * ($planet_prod_low_percent / 100)), 5.0) / 30000.0) + 1);
			}
			else
			{
				$energy_planet = (float)sprintf("%01.4f", 1 - (myrand(0, floor(30000 * ($planet_prod_high_percent / 100)), 5.0) / 30000.0));
			}

			$creation_date = date("Y-m-d H:i:s");
			$debug_query = $db->Execute("INSERT INTO {$db_prefix}planets 
										(sector_id, owner, base, colonists, last_owner_rating, persuasion_countdown, max_credits, prod_fighters, prod_torp, special_name, special_goodevil, organics_planet, ore_planet, goods_planet, energy_planet, creation_date" . $insertlist . ") 
										VALUES 
										('$shipinfo[sector_id]', $playerinfo[player_id], 'Y', $colonistlimit, $old_owner_rating, $persuasion_countdown, '$base_credits', '$default_prod_fighters', '$default_prod_torp', '$special_cargo', '$special_goodevil', '$organics_planet', '$ore_planet', '$goods_planet', '$energy_planet', '$creation_date'" . $insertlistprod . ")");
			db_op_result($debug_query,__LINE__,__FILE__);

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
			return $output;
		}
		else
		{
			$output ="<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0;URL=main.php\">";
			return $output;
		}
	}
}

?>