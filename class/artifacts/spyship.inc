<?php
class spyship
{
	var $class = "spyship";
	var $pieces = 7;
	var $min_cloak = 150; // Cloak value of each artifact piece
	var $max_cloak = 250; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 5; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function spyship()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Spy laevade Tehis";
				$this->description = "See Tehis paneb luurama kõik praegu katsetada laeva. See on täiesti ümbersõit laevade andurid. Spioon kantakse laeva ükskõik kus ta asub. Pea meeles, et kõik heldekäelisus piiranguid kohaldatakse. Tehis saab näha laeva olenemata sellest, milline varjatud väärtus tal on. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud saate valida planeedi koht spioon kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->title = "<b><font size=\"4\" color=\"lime\">Koht Spy laeval</font></b>";
				$this->select = "Valige Player koht Laev Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Föderatsioon ei kiida rünnata palju väiksemad turuosalised. See on paigutatud halastus teid.</font></b>";
				$this->placedspy = "Spioon edukalt kohas laeva juhivad [player].";
				$this->submit = "Koht Spy";
			break;

			case "french":
				$this->classname = "Espionner Ship Artefact";
				$this->description = "Cet artefact mettra un espion sur un navire actuellement en phase pilote. Il sera complètement contourner les capteurs de navires. L&#39;espion sera mis sur le navire, peu importe où il se trouve. Rappelez-vous, toutes les restrictions Bounty sera applicable. L&#39;artefact sera en mesure de voir tout navire, peu importe ce manteau valeur qu&#39;il possède. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez sélectionner la planète à l&#39;endroit de l&#39;espion grâce à la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Place espion sur le bateau</font></b>";
				$this->select = "Choisissez un lecteur de placer un navire espion";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Fédération n&#39;approuve pas d&#39;attaquer des acteurs beaucoup plus petits. Il a placé une prime sur vous.</font></b>";
				$this->placedspy = "Un espion a réussi à placer sur le navire piloté par [player].";
				$this->submit = "Place Spy";
			break;

			case "german":
				$this->classname = "Spy on Ship Artefakt";
				$this->description = "Dieses Artefakt wird ein Spion Ort, auf jedem Schiff derzeit erprobt. Es wird komplett umgehen die Schiffe Sensoren. Der Spion wird auf dem Schiff, egal wo sie sich befindet, platziert werden. Denken Sie daran, gelten alle Beschränkungen Prämie. Das Artefakt wird in der Lage sein zu sehen, jedes Schiff, egal was Mantel Wert besitzt. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie den Planeten auf der Spion durch das Artefakt List-Kommando zu stellen wählen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->title = "<b><font size=\"4\" color=\"lime\">Ort Spion auf Schiff</font></b>";
				$this->select = "Wählen Sie einen Player zu Ort ein Schiff Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Die Föderation nicht billigen Angriff wesentlich kleinerer Unternehmen. Es hat ein Kopfgeld auf Sie gelegt.</font></b>";
				$this->placedspy = "Ein Spion wurde erfolgreich auf dem Schiff gesteuert durch [player].";
				$this->submit = "Ort Spy";
			break;

			case "italian":
				$this->classname = "Spia sulla nave Artefatto";
				$this->description = "Questo artefatto metterà una spia su ogni nave attualmente pilota. E &#39;completamente bypassare i sensori delle navi. La spia sarà imbarcato sulla nave, non importa dove si trova. Ricordate, tutte le restrizioni si applicano Bounty. Il manufatto sarà in grado di vedere alcuna nave non importa quale mantello valore che esso possiede. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile selezionare il pianeta al posto della spia attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy posto sulla nave</font></b>";
				$this->select = "Seleziona un giocatore di inserire un Spy Ship";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federazione non approva attaccanti molto più piccolo. Ha messo una taglia su di te.</font></b>";
				$this->placedspy = "Una spia è stata correttamente posto a bordo della nave pilotata da [player].";
				$this->submit = "Luogo Spy";
			break;

			case "spanish":
				$this->classname = "Espiar Ship Artefacto";
				$this->description = "Este artefacto colocará un espía en un buque en la actualidad con carácter experimental. Se pasará por alto completamente los sensores de los buques. El espía se colocará en el barco, no importa donde se encuentre. Recuerde, todas las restricciones se aplicarán recompensa. El artefacto será capaz de ver cualquier buque, no importa lo que la capa de valor que posee. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el planeta para colocar el espía a través de la Lista de comandos Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lugar espía del Buque</font></b>";
				$this->select = "Seleccione un jugador para poner un espía de buques";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federación no aprueba atacar a jugadores mucho más pequeños. Se ha puesto una recompensa por usted.</font></b>";
				$this->placedspy = "Un espía con éxito lugar en la nave pilotada por [player].";
				$this->submit = "Lugar Spy";
			break;

			case "albanian":
				$this->classname = "Objekti i spiunuar Ship";
				$this->description = "Kjo Objekti i do të vendos një spiun për çdo anije aktualisht piloted. Ajo do të anashkalojë plotësisht sensorë anijet. Spiun do të vendosen në anije nuk ka rëndësi se ku ajo ndodhet. Mos harroni, të gjithë kufizimet e mirësisë do të aplikohen. Objekti do të jetë në gjendje të shoh ndonjë anije pa marrë parasysh se çfarë mantel vlerë që ajo zotëron. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni planetit për të vendosur spiun përmes komandës Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->title = "<b><font size=\"4\" color=\"lime\">Vendi spiun të anijes</font></b>";
				$this->select = "Zgjidhni një vend Player për të një spiun Ship";
				$this->l_bountyscan = "Mirat";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federata nuk e miratojnë sulmuar lojtarë shumë më të vogël. Ajo ka vendosur një begati për ju.</font></b>";
				$this->placedspy = "Një spiun u zhvillua me sukses në anije piloted nga [player].";
				$this->submit = "Vendi spiun";
			break;

			case "catalan":
				$this->classname = "Espiar Ship Artefacte";
				$this->description = "Aquest artefacte col.locarà un espia en un vaixell en l&#39;actualitat amb caràcter experimental. Es passarà per alt completament els sensors dels vaixells. L&#39;espia es col.locarà al vaixell, no importa on es trobi. Recordeu, totes les restriccions s&#39;aplicaran recompensa. L&#39;artefacte serà capaç de veure qualsevol vaixell, no importa el que la capa de valor que té. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el planeta per col.locar el espia a través de la Llista de comandaments Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lloc espia del Vaixell</font></b>";
				$this->select = "Seleccioneu un jugador per posar un espia de vaixells";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federació no aprova atacar jugadors molt més petits. S&#39;ha col.locat una recompensa per vostè.</font></b>";
				$this->placedspy = "Un espia amb èxit lloc a la nau pilotada per [player].";
				$this->submit = "Lloc Spy";
			break;

			case "danish":
				$this->classname = "Udspionere Ship Artifact";
				$this->description = "Dette Artifact vil placere en spion på nogen øjeblikket pilotforsøg skib. Det vil helt omgå skibe sensorer. Den spion vil blive placeret på skibet, uanset hvor den er placeret. Husk, at alle dusør restriktioner. Den Artifact vil være i stand til at se ethvert skib, uanset hvad kappen værdi den har. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet, kan du vælge planeten for at placere spion gennem Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->title = "<b><font size=\"4\" color=\"lime\">Sted Spy på Ship</font></b>";
				$this->select = "Vælg en spiller til at placere en Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federation ikke godkender at angribe meget mindre aktører. Det har sat en dusør på dig.</font></b>";
				$this->placedspy = "En spion lykkedes sted på skibet styres af [player].";
				$this->submit = "Sted Spy";
			break;

			case "dutch":
				$this->classname = "Spy op schepen Artifact";
				$this->description = "Dit zal plaatsvinden Artefact een spion op elk moment geloodst schip. Het zal volledig voorbijgaan aan de schepen sensoren. De spion zal worden gelegd op het schip, ongeacht waar deze zich bevindt. Vergeet niet, zullen alle bounty beperkingen van toepassing. De Artefact zal kunnen zien elk schip niet uit wat mantel waarde van het bezit. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de planeet om de spion plaats via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->title = "<b><font size=\"4\" color=\"lime\">Plaats Spy op schepen</font></b>";
				$this->select = "Selecteer een speler op een plaats Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>De Federatie heeft geen goedkeuring van aanvallende veel kleinere spelers. Het heeft geplaatst een bounty op je.</font></b>";
				$this->placedspy = "Een spion is met succes plaats op het schip bestuurd door [player].";
				$this->submit = "Plaats Spy";
			break;

			case "finnish":
				$this->classname = "Vakoilla Ship Teos";
				$this->description = "Tämä Teos asettaa vakoilla kaikki nyt kokeiltu alusta. Se on kokonaan ohi alusten anturit. Spy sijoitetaan aluksen missä se sijaitsee. Muista, kaikki Bounty rajoituksia sovelletaan. Teos on mahdollisuus nähdä kaikki alukset riippumatta siitä, missä piilo-arvo sillä on. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita planeetan saattaa vakooja kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->title = "<b><font size=\"4\" color=\"lime\">Paikka Spy Alusten</font></b>";
				$this->select = "Valitse pelaaja asettaa Laiva Spy";
				$this->l_bountyscan = "Runsaudessaan";
				$this->l_fedbounty = "<b><font color='red' size='4'>Liitto ei hyväksy hyökkää paljon pieniä toimijoita. Se on sijoitettu armo teitä.</font></b>";
				$this->placedspy = "Spy onnistuneesti paikka aluksen ohjaavat [player].";
				$this->submit = "Paikka Spy";
			break;

			case "indonesian":
				$this->classname = "Memata-matai Kapal artifak";
				$this->description = "Artefak ini akan menempatkan memata-matai setiap saat mengemudikan kapal. Akan benar-benar melewati sensor kapal. Mata-mata akan ditempatkan di kapal tidak peduli dimana dia berada. Ingat, semua karunia-pembatasan akan berlaku. Artefak akan dapat melihat kapal APAPUN jubah apa pun nilai yang dimilikinya. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat memilih planet untuk menempatkan mata-mata melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->title = "<b><font size=\"4\" color=\"lime\">Tempat Spy on Ship</font></b>";
				$this->select = "Pilih Player untuk menempatkan Kapal Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federasi tidak menyetujui menyerang pemain jauh lebih kecil. Ini telah menempatkan karunia pada Anda.</font></b>";
				$this->placedspy = "Sebuah tempat mata-mata berhasil di kapal dikemudikan oleh [player].";
				$this->submit = "Tempat Spy";
			break;

			case "norwegian":
				$this->classname = "Spionere på Ship Artifact";
				$this->description = "Dette Artifact vil plassere en spion på en foreløpig testet ut skipet. Det vil helt utenom skip sensorer. Spionen vil bli plassert på skip uansett hvor den ligger. Husk at alle Bounty begrensninger. The Artifact vil kunne se alle skip uansett hva kappen verdi det har. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet kan du velge planeten å plassere spion gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Plasser Spy on Ship</font></b>";
				$this->select = "Velg en spiller å plassere et Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Landsorganisasjonen godtar ikke å angripe mye mindre spillere. Det har plassert en dusør på deg.</font></b>";
				$this->placedspy = "En spion ble vellykket plass på skipet testet av [player].";
				$this->submit = "Place Spy";
			break;

			case "portuguese":
				$this->classname = "Espião sobre Ship Artefato";
				$this->description = "Este artefato vai colocar um espião em qualquer navio pilotado atualmente. Ele irá ignorar completamente os sensores de navios. O espião será colocado a bordo do navio, não importa onde ele está localizado. Lembre-se, todas as restrições recompensa será aplicada. O artefato será capaz de ver qualquer navio não importa o manto valor que possui. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode selecionar o planeta para colocar o espião através do comando List Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->title = "<b><font size=\"4\" color=\"lime\">Coloque Espião em navio</font></b>";
				$this->select = "Selecione um jogador para colocar um espião Ship";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>A Federação não aprovar de atacar jogadores muito menor. Colocou uma graça em você.</font></b>";
				$this->placedspy = "Um espião foi sucesso lugar na nave pilotada por [player].";
				$this->submit = "Coloque Spy";
			break;

			case "swedish":
				$this->classname = "Spionera på Ship Artefakt";
				$this->description = "Detta Artefakt kommer att placera en spion på någon nu lotsade fartyget. Det kommer helt förbi fartygen sensorer. Spionen kommer att placeras ombord på fartyget oavsett var den är belägen. Kom ihåg att alla frikostighet begränsningar gäller. Artefakten kommer att kunna se alla fartyg oavsett vad mantel värde det har. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns kan du välja planeten att placera spionera genom den fiktiva List kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->title = "<b><font size=\"4\" color=\"lime\">Placera Spy på Ship</font></b>";
				$this->select = "Välj en spelare att placera en Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Förbundet godkänner inte att anfalla mycket mindre aktörer. Det har placerat en bounty på dig.</font></b>";
				$this->placedspy = "En spion har framgångsrikt plats på fartyget som prövats [player].";
				$this->submit = "Place Spy";
			break;

			default:
				$this->classname = "Spy on Ship Artifact";
				$this->description = "This Artifact will place a spy on any currently piloted ship.  It will completely bypass the ships sensors. The spy will be placed on the ship no matter where it is located.  Remember, all bounty restrictions will apply.  The Artifact will be able to see ANY ship no matter what cloak value it possesses.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select the planet to place the spy through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<font size=\"4\" color=\"lime\"><b>Place Spy on Ship</b></font>";
				$this->select = "Select a Player to place a Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<font color='red' size='4'><b>The Federation does not approve of attacking much smaller players. It has placed a bounty on you.</b></font>";
				$this->placedspy = "A spy was successfully place on the ship piloted by [player].";
				$this->submit = "Place Spy";
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
		global $db, $db_prefix, $playerinfo, $l_global_mmenu, $shipinfo, $bounty_ratio, $planet_bounty_ratio;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		$output = "<table CELLSPACING=\"0\" CELLPADDING=\"4\" border=1 align=\"center\" bgcolor=\"#000000\">
		<tr><td><div align=\"center\">" . $this->title . "</div></td></tr><tr><td align=\"center\"><table CELLSPACING=\"0\" CELLPADDING=\"2\" border=0 width=\"100%\" align=\"center\">
					<tr align=\"center\"><td align=center valign=top>";

		$output .= "<form action=\"artifact_process.php?process_type=post&artifact=" . $this->class . "\" method=\"post\" enctype=\"multipart/form-data\">\n";

		$playerscore=$playerinfo['attackscore']*$playerinfo['attackscore'];
		$res = $db->Execute("SELECT * FROM {$db_prefix}players where player_id > 3 and player_id != $playerinfo[player_id] ORDER BY character_name");
   		db_op_result($res,__LINE__,__FILE__);
		while (!$res->EOF)
		{
			$row = $res->fields;

			$targetscore=$row['attackscore'] * $row['attackscore'];
			if ($targetscore==0){
				$targetscore=1;
			}
			if ($playerscore==0){
				$playerscore=1;
			}
			$bratio=$targetscore / $playerscore;

			$isfedbounty = 0;
			if(($bratio < $bounty_ratio) and ($bratio < $planet_bounty_ratio)){
				$isfedbounty = 1;	
			}
			if(($bratio < $bounty_ratio) and ($bratio > $planet_bounty_ratio)){
				$isfedbounty = 1;	
			}

			$option_echo .= "	<option value=\"$row[player_id]\">$row[character_name]" . (($isfedbounty == 1) ? " - " . $this->l_bountyscan : "") . "</option>\n";
			$res->MoveNext();
			$fun_temp++;
		}

		if ($fun_temp > 15)
		{
			$fun_temp = 15;
		}

		$output .= "  <select size=\"$fun_temp\" name=\"player_id\">\n";
		$output .= $option_echo;
		$output .= "  </select>\n";
		$output .= "<br><br>\n
		  <div align=\"center\"><input type=\"submit\" id=\"" . $this->submit . "\" value=\"" . $this->submit . "\" name=\"" . $this->submit . "\" ></div>\n</FORM>";

		$output .= "</td></tr><tr><td><div align=\"center\">" . $this->select . "</div></td></tr></table></td></tr><tr><td align=\"center\"><br>$l_global_mmenu<br><br></td></tr>
		</table>";
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

	  	$player_id = $_POST['player_id'];

		$result5 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=". $player_id . "", 1);
		$targetplayer = $result5->fields;
   		db_op_result($result5,__LINE__,__FILE__);
		$result5->close();

			include ("globals/ship_bounty_check.inc");

			$isfedbounty = ship_bounty_check($playerinfo, 1, $targetplayer, 1);

			if($isfedbounty > 0)
			{
				$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
				db_op_result($res,__LINE__,__FILE__);
				$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->l_fedbounty . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
				return $output;
			}

			$debug_query = $db->Execute("INSERT INTO {$db_prefix}spies 
			(spy_id, active, owner_id, planet_id, ship_id, job_id, spy_percent, move_type, spy_cloak) 
			values 
			('','Y',$playerinfo[player_id],'0','$targetplayer[currentship]','0','0.0','toship', $shipinfo[cloak])");
			db_op_result($debug_query,__LINE__,__FILE__);

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . str_replace("[player]", $targetplayer['character_name'], $this->placedspy) . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
			return $output;
	}
}

?>