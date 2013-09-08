<?php
class spyplanet
{
	var $class = "spyplanet";
	var $pieces = 7;
	var $min_cloak = 150; // Cloak value of each artifact piece
	var $max_cloak = 250; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 5; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function spyplanet()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Planeetide Spy Tehis";
				$this->description = "See Tehis paneb spioon iga vaenlase planeeti. See on täiesti ümbersõit planeedid andurid. Sa pead olema samas sektoris on planeet ja kõik heldekäelisus piiranguid kohaldatakse. Tehis saab näha mingit planeeti sektoris olenemata sellest, milline varjatud väärtus tal on. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui kõik nupud on leitud saate valida planeedi koht spioon kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja võib leida mõningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud kõiki " . $this->pieces . " tükid " . $this->classname . ". Võite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lõpule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->title = "<b><font size=\"4\" color=\"lime\">Koht Spy planeedil</font></b>";
				$this->select = "Valige planeedi koht spioon";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Valitud planeedil pole võimalik leida selles sektoris.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Föderatsioon ei kiida rünnata palju väiksemad turuosalised. See on paigutatud halastus teid.</font></b>";
				$this->placedspy = "Spioon õnnestus koht planeedil [planet].";
			break;

			case "french":
				$this->classname = "Planetary Spy Artefact";
				$this->description = "Cet artefact mettra un espion sur une planète ennemie. Il sera complètement contourner les capteurs planètes. Vous devez être dans le même secteur que la planète et toutes les restrictions Bounty sera applicable. L&#39;artefact sera en mesure de voir la planète TOUT dans le secteur peu importe ce manteau de valeur qu&#39;elle possède. Il ya un total de " . $this->pieces . " pièces qui doivent être trouvés. Une fois toutes les pièces sont trouvés, vous pouvez sélectionner la planète à l&#39;endroit de l&#39;espion grâce à la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit à l&#39;attaquant mai trouver certaines des pièces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " pièces de la " . $this->classname . ". Vous pouvez utiliser cet objet à tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] pièces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pièces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Place Spy sur la planète</font></b>";
				$this->select = "Sélectionnez une planète à placer l&#39;espion";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "La planète sélectionné ne peut être trouvé dans ce secteur.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Fédération n&#39;approuve pas d&#39;attaquer des acteurs beaucoup plus petits. Il a placé une prime sur vous.</font></b>";
				$this->placedspy = "Un espion a réussi à placer sur la planète [planet].";
			break;

			case "german":
				$this->classname = "Planetary Spy Artefakt";
				$this->description = "Dieses Artefakt wird ein Spion Platz auf jeden Feind Planeten. Es wird komplett umgehen die Planeten-Sensoren. Sie müssen in der gleichen Branche wie der Planet und alle Güte Beschränkungen gelten. Das Artefakt wird in der Lage, jedem Planeten in diesem Sektor, egal, was Mantel Wert besitzt. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie den Planeten auf der Spion durch das Artefakt List-Kommando zu stellen wählen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy Ort auf dem Planeten</font></b>";
				$this->select = "Wählen Sie einen Planeten, der Spion Ort";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Die ausgewählten Planeten kann nicht in diesem Bereich gefunden werden.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Die Föderation nicht billigen Angriff wesentlich kleinerer Unternehmen. Es hat ein Kopfgeld auf Sie gelegt.</font></b>";
				$this->placedspy = "Ein Spion wurde erfolgreich auf dem Planeten place [planet].";
			break;

			case "italian":
				$this->classname = "Planetari Spy Artifact";
				$this->description = "Questo artefatto metterà una spia su qualsiasi pianeta nemico. E &#39;completamente bypassare i sensori pianeti. Devi essere nello stesso settore, come il pianeta e tutte le restrizioni di taglie si applica. Il manufatto sarà in grado di vedere pianeta QUALSIASI nel settore, non importa cosa mantello valore che esso possiede. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, è possibile selezionare il pianeta al posto della spia attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave è distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". È possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy posto su Planet</font></b>";
				$this->select = "Selezionare un pianeta al posto della spia";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Il pianeta selezionato non può essere trovato in questo settore.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federazione non approva attaccanti molto più piccolo. Ha messo una taglia su di te.</font></b>";
				$this->placedspy = "Una spia è stato posto con successo sul pianeta [planet].";
			break;

			case "spanish":
				$this->classname = "Planetario espía Artefacto";
				$this->description = "Este artefacto colocará un espía en cualquier planeta enemigo. Se pasará por alto completamente los sensores de los planetas. Debe estar en el mismo sector que el planeta y todas las restricciones se aplicarán recompensa. El artefacto será capaz de ver cualquier planeta en el sector no importa lo que la capa de valor que posee. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el planeta para colocar el espía a través de la Lista de comandos Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lugar espía en el Planeta</font></b>";
				$this->select = "Seleccione un planeta a otro el espía";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "El planeta seleccionado no se puede encontrar en este sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federación no aprueba atacar a jugadores mucho más pequeños. Se ha puesto una recompensa por usted.</font></b>";
				$this->placedspy = "Un espía con éxito lugar en el planeta [planet].";
			break;

			case "albanian":
				$this->classname = "Planetare spiun Objekti";
				$this->description = "Kjo Objekti i do të vendos një spiun në ndonjë planet armikut. Ajo do të anashkalojë plotësisht sensorë planetet. Ju duhet të jetë në sektorin e njëjtë si të gjithë planetin dhe do të aplikohen kufizimet e mirësisë. Objekti do të jetë në gjendje të shohim planetin NDONJE në sektorin pa marrë parasysh çfarë mantel vlerë që ajo zotëron. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni planetit për të vendosur spiun përmes komandës Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->title = "<b><font size=\"4\" color=\"lime\">Vendi spiun në Planet</font></b>";
				$this->select = "Zgjidhni një planet në vendin e spiun";
				$this->l_bountyscan = "Mirat";
				$this->noplanet = "Planet e zgjedhur nuk mund të gjenden në këtë sektor.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federata nuk e miratojnë sulmuar lojtarë shumë më të vogël. Ajo ka vendosur një begati për ju.</font></b>";
				$this->placedspy = "Një spiun u zhvillua me sukses në planetin [planet].";
			break;

			case "catalan":
				$this->classname = "Planetari espia Artefacte";
				$this->description = "Aquest artefacte col.locarà un espia a qualsevol planeta enemic. Es passarà per alt completament els sensors dels planetes. Ha d&#39;estar en el mateix sector que el planeta i totes les restriccions s&#39;aplicaran recompensa. L&#39;artefacte serà capaç de veure qualsevol planeta en el sector no importa el que la capa de valor que té. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el planeta per col.locar el espia a través de la Llista de comandaments Artefacte. Les peces artefacte quedarà emmagatzemat al vaixell. Si el vaixell és destruït l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galàxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostè pot usar aquest artefacte en qualsevol moment des de la pàgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostè necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lloc espia al Planeta</font></b>";
				$this->select = "Seleccioneu un planeta a un altre l&#39;espia";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "El planeta seleccionat no es pot trobar en aquest sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federació no aprova atacar jugadors molt més petits. S&#39;ha col.locat una recompensa per vostè.</font></b>";
				$this->placedspy = "Un espia amb èxit lloc al planeta [planet].";
			break;

			case "danish":
				$this->classname = "Planetary Spy Artifact";
				$this->description = "Dette Artifact vil placere en spion på en fjendtlig planet. Det vil helt omgå planeter sensorer. Du skal være i den samme sektor som planeten og alle dusør restriktioner finder anvendelse. Den Artifact vil være i stand til at se nogen planet i sektoren uanset hvad kappen værdi den har. Der er i alt " . $this->pieces . " stykker, der skal findes. Når alle brikker er fundet, kan du vælge planeten for at placere spion gennem Artifact List kommando. Den Artifact stykker vil blive gemt på dit skib. Hvis dit skib er ødelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil være tilfældigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->title = "<b><font size=\"4\" color=\"lime\">Sted Spy på Planet</font></b>";
				$this->select = "Vælg en planet for at placere spion";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Den valgte planet kan ikke findes i denne sektor.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federation ikke godkender at angribe meget mindre aktører. Det har sat en dusør på dig.</font></b>";
				$this->placedspy = "En spion lykkedes sted på planeten [planet].";
			break;

			case "dutch":
				$this->classname = "Planetaire Spy Artifact";
				$this->description = "Dit zal plaatsvinden Artefact een spion op een vijandelijke planeet. Het zal volledig rondweg de planeten sensoren. Je moet in dezelfde sector als de planeet en alle bounty beperkingen van toepassing. De Artefact staat zullen zijn om alle planeten zien in de sector niet uit wat mantel waarde zij beschikt. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de planeet om de spion plaats via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->title = "<b><font size=\"4\" color=\"lime\">Plaats Spy op Planet</font></b>";
				$this->select = "Selecteer een planeet naar de plaats spion";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "De geselecteerde planeet kan niet gevonden worden in deze sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>De Federatie heeft geen goedkeuring van aanvallende veel kleinere spelers. Het heeft geplaatst een bounty op je.</font></b>";
				$this->placedspy = "Een spion is succesvol plaats op de planeet [planet].";
			break;

			case "finnish":
				$this->classname = "Planetaarista Spy Teos";
				$this->description = "Tämä Teos asettaa vakoilla tahansa vihollisen planeetalla. Se on kokonaan ohi planeetat anturit. Sinun täytyy olla samalla alalla kuin maapallon ja kaikki armo rajoituksia sovelletaan. Teos voi nähdä mitään Planet alalla riippumatta siitä, mitä piilo-arvo sillä on. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita planeetan saattaa vakooja kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->title = "<b><font size=\"4\" color=\"lime\">Paikka vakoilla Planet</font></b>";
				$this->select = "Valitse planeetan saattaa vakooja";
				$this->l_bountyscan = "Runsaudessaan";
				$this->noplanet = "Valitun planeetta ei löydy tällä alalla.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Liitto ei hyväksy hyökkää paljon pieniä toimijoita. Se on sijoitettu armo teitä.</font></b>";
				$this->placedspy = "Spy onnistuneesti paikka planeetalla [planet].";
			break;

			case "indonesian":
				$this->classname = "Planet Spy artifak";
				$this->description = "Artefak ini akan menempatkan mata-mata di planet musuh. Ini akan benar-benar melewati sensor planet. Anda harus berada dalam sektor yang sama seperti planet dan semua karunia-pembatasan akan berlaku. Artefak akan dapat melihat APAPUN planet di sektor apa pun nilai jubah yang dimilikinya. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat memilih planet untuk menempatkan mata-mata melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->title = "<b><font size=\"4\" color=\"lime\">Tempat Spy di Planet</font></b>";
				$this->select = "Pilih sebuah planet untuk menempatkan mata-mata";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Planet yang dipilih tidak dapat ditemukan di sektor ini.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federasi tidak menyetujui menyerang pemain jauh lebih kecil. Ini telah menempatkan karunia pada Anda.</font></b>";
				$this->placedspy = "Sebuah tempat mata-mata berhasil di planet [planet].";
			break;

			case "norwegian":
				$this->classname = "Planetary Spy Artifact";
				$this->description = "Dette Artifact vil plassere en spion på en fiende planet. Det vil helt utenom planetene sensorer. Du må være i samme sektor som planeten og alle skuddpremie restriksjoner gjelder. The Artifact vil kunne se noen planet i sektoren uansett hva kappen verdi det har. Det er totalt " . $this->pieces . " stykker som trenger å bli funnet. Når alle brikkene er funnet kan du velge planeten å plassere spion gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret på skipet ditt. Hvis skipet ditt blir ødelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand når som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for å fullføre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Plasser Spy on Planet</font></b>";
				$this->select = "Velg en planet for å plassere spy";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Den valgte Planeten kan ikke forekomme i denne sektoren.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Landsorganisasjonen godtar ikke å angripe mye mindre spillere. Det har plassert en dusør på deg.</font></b>";
				$this->placedspy = "En spion ble vellykket sted på planeten [planet].";
			break;

			case "portuguese":
				$this->classname = "Planetário Spy Artefato";
				$this->description = "Este artefato vai colocar um espião em qualquer planeta inimigo. Ele irá ignorar completamente os sensores de planetas. Você deve estar no mesmo sector, como o planeta e todas as restrições recompensa será aplicada. O artefato será capaz de ver de qualquer outro planeta do sector não importa o manto valor que possui. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças são encontradas você pode selecionar o planeta para colocar o espião através do comando List Artefato. As peças Artefato serão armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes não captadas pelo atacante serão distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Você encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Você pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Você encontrou [pieces] peças do " . $this->classname . ". Você precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy lugar no Planeta</font></b>";
				$this->select = "Selecione um planeta para colocar o espião";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "O planeta escolhido não pode ser encontrado neste sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>A Federação não aprovar de atacar jogadores muito menor. Colocou uma graça em você.</font></b>";
				$this->placedspy = "Um espião foi sucesso lugar no planeta [planet].";
			break;

			case "swedish":
				$this->classname = "Planetary Spy Artefakt";
				$this->description = "Detta Artefakt kommer att placera en spion på någon fiende planet. Det kommer helt förbi planeterna sensorer. Du måste vara i samma bransch som vår planet och alla begränsningar givmildhet kommer att gälla. Artefakten kommer att kunna se alla planeter i branschen oavsett mantel värde det har. Finns totalt " . $this->pieces . " bitar som måste hittas. När alla bitar finns kan du välja planeten att placera spionera genom den fiktiva List kommandot. Artefakten bitar sparas på ditt skepp. Om ditt skepp förstörs Angriparen kan hitta några av de bitar. Alla bitar som inte fångas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst från den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->title = "<b><font size=\"4\" color=\"lime\">Placera Spy på Planet</font></b>";
				$this->select = "Välj en planet att placera Spy";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "De utvalda planet kan inte hittas i denna sektor.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Förbundet godkänner inte att anfalla mycket mindre aktörer. Det har placerat en bounty på dig.</font></b>";
				$this->placedspy = "En spion har framgångsrikt plats på planeten [planet].";
			break;

			default:
				$this->classname = "Planetary Spy Artifact";
				$this->description = "This Artifact will place a spy on any enemy planet.  It will completely bypass the planets sensors. You must be in the same sector as the planet and all bounty restrictions will apply.  The Artifact will be able to see ANY planet in the sector no matter what cloak value it possesses.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select the planet to place the spy through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<font size=\"4\" color=\"lime\"><b>Place Spy on Planet</b></font>";
				$this->select = "Select a planet to place the spy";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "The selected planet cannot be found in this sector.";
				$this->l_fedbounty = "<font color='red' size='4'><b>The Federation does not approve of attacking much smaller players. It has placed a bounty on you.</b></font>";
				$this->placedspy = "A spy was successfully place on planet [planet].";
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
		global $db, $db_prefix, $playerinfo, $l_global_mmenu, $shipinfo, $templatename, $l_unowned, $l_ranks_evil, $l_ranks_good, $l_ranks_neutral;
		global $colonist_limit, $colonist_tech_add, $maximum_colonists, $max_tech_level, $l_unnamed;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		include ("globals/good_neutral_evil.inc");
		include ("globals/planet_bounty_check.inc");

		$res = $db->SelectLimit("SELECT * FROM {$db_prefix}planets WHERE sector_id='$shipinfo[sector_id]'", 5);
   		db_op_result($res,__LINE__,__FILE__);

		$output = "<table CELLSPACING=\"0\" CELLPADDING=\"2\" border=1 align=\"center\">
		<tr><td><div align=\"center\">" . $this->title . "</div></td></tr><tr><td align=\"center\"><table CELLSPACING=\"0\" CELLPADDING=\"2\" border=0 width=\"100%\" align=\"center\">
					<tr align=\"center\">";

		while (!$res->EOF)
		{
			$planets = $res->fields;

			$result5 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=". $planets['owner'] . "", 1);
			$planet_owner = $result5->fields;
			$result5->close();

			$planetavg = $planets['fighter'] + $planets['sensors'] + $planets['beams'] + $planets['torp_launchers'] + $planets['shields'] + $planets['cloak'];
			$maximum_colonists = $colonist_limit + floor($colonist_tech_add * floor($planetavg / 6));
			$planetavg += ($planets['colonists'] / $maximum_colonists) * $max_tech_level;
			$planetavg =  floor((($planetavg / 7) / $max_tech_level) * 10 );

			$planetlevel = max(0, min(9, $planetavg));
			$rating = good_neutral_evil($planet_owner['rating']);
			$planetrating = $rating[1];
			$planetratingnumber = $rating[0];

			if($planets['ore_planet'] >= 1 && $planets['organics_planet'] >= 1)
			{
				$planettype = "oo";
			}

			if($planets['ore_planet'] >= 1 && $planets['organics_planet'] < 1)
			{
				$planettype = "oo-";
			}

			if($planets['ore_planet'] < 1 && $planets['organics_planet'] >= 1)
			{
				$planettype = "o-o";
			}

			if($planets['ore_planet'] < 1 && $planets['organics_planet'] < 1)
			{
				$planettype = "o-o-";
			}

			$planetimg = $planettype . (string)($planetlevel + 1);
			if (empty($planets['name']))
			{
				$planetname = $l_unnamed;
			}
			else
			{
				$planetname = $planets['name'];
			}

			if ($planets['owner'] == 0)
			{
				$planetowner = "$l_unowned";
			}
			else
			{
				$planetowner = "$planet_owner[character_name]";
			}

			$output .= "	<td align=center valign=top>
	<a href=\"artifact_process.php?process_type=post&artifact=" . $this->class . "&planetid=" . $planets['planet_id'] . "\">
	<img src=\"templates/" . $templatename . "images/planet" . $planetimg . ".png\" alt=\"\" width=\"100\" height=\"100\"></a>
	<BR><font size=2 color=\"white\" face=\"arial\">
	$planetname
	<br>($planetowner)
				<br>";
			if ($planetratingnumber == -1)
			{
				$output .= "<font color=\"red\">$planetrating</font>";
			}
			elseif ($planetratingnumber == 0)
			{
				$output .= "<font color=\"yellow\">$planetrating</font>";
			}
			else
			{
				$output .= "<font color=\"lime\">$planetrating</font>";
			}
			$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $planet_owner, 0);
			if ($isfedbounty > 0)
			{
				$output .= "<br><font color=\"red\"><b>" . $this->l_bountyscan . "</b></font>";
			}
			$output .= "	</font></td>";
			$res->MoveNext();
		}

		$output .= "</tr><tr><td colspan=\"5\"><div align=\"center\">" . $this->select . "</div></td></tr></table></td></tr><tr><td align=\"center\"><br>$l_global_mmenu<br><br></td></tr>
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

	  	$planetid = $_GET['planetid'];

		$res = $db->SelectLimit("SELECT * FROM {$db_prefix}planets WHERE planet_id='$planetid'", 5);
   		db_op_result($res,__LINE__,__FILE__);
		$planets = $res->fields;

		$result5 = $db->SelectLimit("SELECT * FROM {$db_prefix}players WHERE player_id=". $planets['owner'] . "", 1);
		$planet_owner = $result5->fields;
   		db_op_result($result5,__LINE__,__FILE__);
		$result5->close();

		if($shipinfo['sector_id'] == $planets['sector_id'])
		{
			include ("globals/planet_bounty_check.inc");

			$isfedbounty = planet_bounty_check($playerinfo, $shipinfo['sector_id'], $planet_owner, 1);

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
			('','Y',$playerinfo[player_id],'$planetid','0','0','0.0','none', $shipinfo[cloak])");
			db_op_result($debug_query,__LINE__,__FILE__);

			$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
			db_op_result($res,__LINE__,__FILE__);

			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . str_replace("[planet]", $planets['name'], $this->placedspy) . "</b></font></div></td>
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
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->noplanet . "</b></font></div></td>
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