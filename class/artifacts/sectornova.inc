<?php
class sectornova
{
	var $class = "sectornova";
	var $pieces = 10;
	var $min_cloak = 150; // Cloak value of each artifact piece
	var $max_cloak = 350; // Maximum Cloak value of each artifact piece
	var $scoremax = 0; // Any player with a score over this value will not be able to see the artifact. Set to 0 for everyone to see.
	var $schedinfo;
	var $delayedprocess = 1; // If the completed artifact can be processed at a different time after completion.  Player can execute the artifact from the Artifact List selection.  Set to 1 for delayed processing.
	var $maximum_in_galaxy = 5; // The maximum number of artifacts of this class in the galaxy.  Multiply this number by $pieces to get the total number of pieces in the galaxy.

	function sectornova()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Valdkond Nova Tehis";
				$this->description = "See Tehis on maha Sector Nova igal Warp seotud Mitte-Föderatsioon sektori mängija on külastanud voi skannitud, see holmab SG sektorid. Valdkond Nova hävitab suure hulga sektori keinojasi, kahju koik planeedid ja laevade suhtes. On kokku " . $this->pieces . " tükki, et tuleb leida. Kui koik nupud on leitud saate valida sektori rünnaku kaudu Tehis nimekiri käsk. Tehis tükki on salvestatud laeva. Kui teie laev on hävitatud Ründaja voib leida moningaid nuppe. Iga tükki ei ole püütud ründaja on juhuslikult jagatud ümber galaktika.";
				$this->success = "Sa ei leidnud koiki " . $this->pieces . " tükid " . $this->classname . ". Voite kasutada seda Artefakti igal ajal Tehis nimekiri leheküljel.";
				$this->incomplete = "Olete leidnud [pieces] tükki " . $this->classname . ". Peate [left] veel [piece] lopule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->waiting = "<div align=\"center\"> Andurid on ootel. <br><br> Ootel skaneerida valitud sektoris. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Te ei saa kasutada Sector Nova alates Föderatsiooni sektor.";
				$this->pretitle = "Valige sektor rünnaku sektoriga Nova";
				$this->nolink = "Warp Seos selles sektoris ei ole olemas.";
				$this->novisit = "Sa ei ole käinud suunatud sektoris.";
				$this->nofedtarget = "Sa ei saa suunata Föderatsiooni sektor.";
				$this->scanning = "<div align=\"center\"> Skaneerimine sektor </div>";
				$this->imtitle = "Sektor rünnaku all";
				$this->imbody = "[player] kasutab Sector Nova kohta [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">HOIATUS: Kui teil heldekäelisus ühe planeedi seda kasutades toote ja seal on rohkem planeete, mis ei ole tabanud veel, saad halastuse eest iga planeedil. Kui on 5 planeeti sektoris ja saad halastuse kohta 3. planeedi sa saada ka teine halastuse kohta 4. planeet ja teine halastuse kohta 5. planeeti kokku 3 erinevat bounties!</font></b>";
			break;

			case "french":
				$this->classname = "Secteur de la Nouvelle-artefact";
				$this->description = "Cet artefact déclenchera une Nouvelle secteur dans toute profession non lié Warp-fédération du secteur que le joueur a visité ou scannés, cela comprend les secteurs SG. La Nova secteur va détruire massivement du secteur Defenses, dommages toutes les planctes et des navires dans le secteur. Il ya un total de " . $this->pieces . " picces qui doivent etre trouvés. Une fois toutes les picces sont trouvés, vous pouvez sélectionner le secteur r l&#39;attaque r travers la commande Liste Artefact. Les morceaux d&#39;artefact seront stockées sur votre bateau. Si votre vaisseau est détruit r l&#39;attaquant mai trouver certaines des picces. Les morceaux non exploités par l&#39;attaquant seront distribuées au hasard autour de la galaxie.";
				$this->success = "Vous avez trouvé toutes les " . $this->pieces . " picces de la " . $this->classname . ". Vous pouvez utiliser cet objet r tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouvé [pieces] picces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "picces";
				$this->waiting = "<div align=\"center\"> Sensors au Attente. <br><br> En attente de numérisation secteur choisi. </div>";
				$this->fire = "Secteur de la Nouvelle-feu";
				$this->federation = "Vous ne pouvez pas utiliser la Nouvelle-secteur d&#39;un Secteur de la Fédération.";
				$this->pretitle = "Sélectionner le secteur d&#39;attaquer avec le Secteur de la Nouvelle -";
				$this->nolink = "A Link Warp r ce secteur n&#39;existe pas.";
				$this->novisit = "Vous n&#39;avez pas visité le secteur de la cible.";
				$this->nofedtarget = "Vous ne pouvez pas cibler un secteur Fédération.";
				$this->scanning = "<div align=\"center\"> Secteur de balayage </div>";
				$this->imtitle = "Secteur Under Attack";
				$this->imbody = "[player] est d&#39;utiliser un secteur de la Nouvelle-le [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ATTENTION: Si vous obtenez une prime sur une plancte pour l&#39;utilisation de cet artefact et il ya des planctes qui n&#39;ont pas encore été touché, vous recevrez une prime pour chaque plancte. S&#39;il ya 5 planctes dans le secteur et vous obtenez une prime sur la plancte 3cme étage on recevra également une autre prime sur la plancte 4cme et une autre prime sur la plancte 5cme année pour un total de 3 primes différents!</font></b>";
			break;

			case "german":
				$this->classname = "Sector Nova Artefakt";
				$this->description = "Dieses Artefakt wird abgereist, ein Sektor Nova in jedem Warp Linked Non-Föderation Sektor der Spieler besucht hat, oder gescannt werden, schließt dies SG Branche. Der Sektor Nova wird eine massive Anzahl von Sector Defenses, Schäden zu zerstören alle Planeten und Schiffe in der Branche. Es gibt insgesamt " . $this->pieces . " Stücke, die gefunden werden müssen. Wenn alle Teile gefunden sind, können Sie die Branche, um durch die Liste Artefakt Befehl Angriff auswählen. The Artifact Stücke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerstört wird der Angreifer einige der Stücke zu finden. Jedes Stück vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie können dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie müssen [left] mehr [piece], um das Artefakt abzuschließen.";
				$this->singular = "Stück";
				$this->plural = "Stück";
				$this->waiting = "<div align=\"center\"> Sensoren im Standby. <br><br> Warten auf ausgewählten Sektor scannen. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Sie können nicht mit dem Sektor Nova aus einer Föderation Sektor.";
				$this->pretitle = "Wählen Sie die Branche zum Angriff mit dem Sektor Nova";
				$this->nolink = "Ein Warp-Link zu diesem Sektor gibt es nicht.";
				$this->novisit = "Sie haben nicht besucht die angesprochenen Verkehrskreise.";
				$this->nofedtarget = "Sie können nicht auf einen Sektor Föderation.";
				$this->scanning = "<div align=\"center\"> Sector Scanning </div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] ist mit einem Sektor Nova auf [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">WARNUNG: Wenn Sie eine Prämie erhalten, auf einem Planeten bei der Verwendung dieses Artefakt und es gibt mehr Planeten, die bisher noch nicht getroffen, werden Sie eine Prämie für jeden Planeten zu erhalten. Wenn es 5 Planeten in diesem Sektor und Sie erhalten eine Prämie auf die 3. Planeten Sie erhalten auch eine andere Prämie auf die 4. Planeten und anderen Kopfgeld auf den 5. Planeten für insgesamt 3 verschiedenen Prämien!</font></b>";
			break;

			case "italian":
				$this->classname = "Settore Nova Artifact";
				$this->description = "Questo artefatto farr innescare una Nova Settore in ogni Warp Linked Non settore Federazione che il giocatore ha visitato o digitalizzate, questo include Settori SG. La Nova Settore distruggerr un numero massiccio di Settore difese, danno tutti i pianeti e le navi nel settore. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, c possibile selezionare il settore di attacco tramite il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave c distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". C possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->waiting = "<div align=\"center\"> Sensori in standby. <br><br> In attesa di eseguire la scansione del settore selezionato. </div>";
				$this->fire = "Fire Settore Nova";
				$this->federation = "Non c possibile utilizzare la Nova settore da un Settore della Federazione.";
				$this->pretitle = "Scegli il settore di attaccare con la Nova Settore";
				$this->nolink = "A Link Warp a tale settore non esiste.";
				$this->novisit = "Non avete visitato il settore di destinazione.";
				$this->nofedtarget = "Non c possibile di un settore della Federazione.";
				$this->scanning = "<div align=\"center\"> Scansione Settore </div>";
				$this->imtitle = "Settore Under Attack";
				$this->imbody = "[player] utilizza un Nova Settore su [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ATTENZIONE: Se si ottiene una taglia su un pianeta quando si utilizza questo artefatto e non ci sono piu pianeti che non sono stati ancora colpiti, si otterrr una taglia per ogni pianeta. Se ci sono 5 pianeti nel settore e si ottiene una taglia sul pianeta 3 sarr anche un altro bontr del pianeta e un altro 4 Bounty sul pianeta 5 per un totale di 3 premi diversi!</font></b> </font";
			break;

			case "spanish":
				$this->classname = "Sector de Nova Artefacto";
				$this->description = "Este artefacto se desató una Nova, en cualquier sector no relacionado Warp sector Federación que el jugador ha visitado o escaneadas, lo que incluye los sectores SG. El Nova Sector destruir un número masivo de Sector de defensas, el dano que todos los planetas y los buques en el sector. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el sector de atacar a través del comando Lista de Artefacto. Las piezas artefacto se almacenará en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la página Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] más [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->waiting = "<div align=\"center\"> Sensores en espera. <br><br> Lugar para escanear sector seleccionado. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Usted no puede utilizar la Nova Sector de un sector de la Federación.";
				$this->pretitle = "Seleccione el sector al ataque con el Sector de Nova";
				$this->nolink = "A Link Warp a este sector no existe.";
				$this->novisit = "Usted no ha visitado el sector de destino.";
				$this->nofedtarget = "Usted no puede con un sector de la Federación.";
				$this->scanning = "<div align=\"center\"> Escaneo Sector </div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] está utilizando un sector de Nova el [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ADVERTENCIA: Si usted recibe una recompensa por un planeta al utilizar este artefacto y hay más planetas que no han sido afectados, sin embargo, usted recibirá una recompensa por cada planeta. Si hay 5 planetas en el sector y se obtiene una recompensa en el planeta el 3 también recibirá otra recompensa en el planeta, y otro 4 de recompensa en el planeta 5 de un total de 3 diferentes recompensas!</font></b>";
			break;

			case "albanian":
				$this->classname = "Sektori Nova Objekti";
				$this->description = "Kjo Objekti do të shënoj një Nova Sektorit në çdo Jo Linked Warp sektorin Federata lojtar e ka vizituar ose e skanuar, kjo përfshin SG Sektoret. Nova Sektori do të shkatërrojë numër masiv i Sektorit mbrojtëse, dëme të gjitha planetet dhe anijet në sektor. Ka një numër të " . $this->pieces . " pjesë që duhet të gjendet. Pasi të gjitha këngët janë gjetur ju mund të zgjidhni të sektorit për të sulmuar përmes komandës Lista Objekti. Objekti do të jetë pjesë ruhet në anije tuaj. Nëse anija juaj është shkatërruar sulmues mund të gjeni disa nga copa. Çdo copë nuk kapur nga sulmuesit do të shpërndahen rreth rastësisht galaktikë.";
				$this->success = "Ju keni gjetur të gjithë " . $this->pieces . " copë " . $this->classname . ". Ju mund të përdorni këtë Objekti në çdo kohë nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] copë " . $this->classname . ". Ju duhet [left] më [piece] për të përfunduar Objekti.";
				$this->singular = "copë";
				$this->plural = "copë";
				$this->waiting = "<div align=\"center\"> Sensorë në pritje. <br><br> Pritje të scan sektorin e zgjedhur. </div>";
				$this->fire = "Zjarri Sektori Nova";
				$this->federation = "Ju nuk mund të përdorni Nova Sektori nga Sektori i Federatës.";
				$this->pretitle = "Zgjidhni Sektori për të sulmuar me Nova Sektori";
				$this->nolink = "Një Link Warp për këtë sektor nuk ekziston.";
				$this->novisit = "Ju nuk e keni vizituar sektorin e caktuar.";
				$this->nofedtarget = "Ju nuk mund të synojë një Sektorin e Federatës.";
				$this->scanning = "<div align=\"center\"> Duke analizuar Sektori </div>";
				$this->imtitle = "Sektori Under Attack";
				$this->imbody = "[player] është përdorur një Nova Sektori në [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">KUJDES: Nëse ju merrni një dhuratë nga një planet gjatë përdorimit të kësaj Objekti dhe ka më shumë planeteve që nuk janë goditur ende, ju do të merrni një dhuratë për SECILIN planetin. Nëse ka 5 planetet në sektor dhe që ju të merrni një dhuratë në planetin 3 ju do të merrni një dhuratë në planetin 4 dhe një tjetër dhuratë të planetit 5 për një total prej 3 mirësitë e ndryshme!</font></b>";
			break;

			case "catalan":
				$this->classname = "Sector de Nova Artefacte";
				$this->description = "Aquest artefacte es va desencadenar una Nova, en qualsevol sector no relacionat Warp sector Federació que el jugador ha visitat o escanejades, el que inclou els sectors SG. L&#39;Nova Sector destruir un nombre massiu de Sector de defenses, el dany que tots els planetes i els vaixells en el sector. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el sector d&#39;atacar a través de la comanda Llista de Artefacte. Les peces artefacte quedarr emmagatzemat al vaixell. Si el vaixell és destrudt l&#39;atacant pot trobar algunes de les peces. Qualsevol peça no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la galrxia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vostc pot usar aquest artefacte en qualsevol moment des de la prgina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vostc necessita [left] més [piece] per completar l&#39;artefacte.";
				$this->singular = "peça";
				$this->plural = "peces";
				$this->waiting = "<div align=\"center\"> Sensors en espera. <br><br> Lloc per escanejar sector seleccionat. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "No podeu utilitzar la Nova Sector d&#39;un sector de la Federació.";
				$this->pretitle = "Seleccioni el sector a l&#39;atac amb el Sector de Nova";
				$this->nolink = "A Link Warp a aquest sector no existeix.";
				$this->novisit = "Vostc no ha visitat el sector de destinació.";
				$this->nofedtarget = "Vostc no pot amb un sector de la Federació.";
				$this->scanning = "<div align=\"center\"> Escaneig Sector </div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] utilitzeu un sector de Nova el [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ADVERTIMENT: Si vostc rep una recompensa per un planeta a l&#39;utilitzar aquest artefacte i hi ha més planetes que no han estat afectats, pern, vostc rebrr una recompensa per cada planeta. Si hi ha 5 planetes en el sector i s&#39;obté una recompensa al planeta el 3 també rebrr una altra recompensa al planeta, i un 4 de recompensa al planeta 5 d&#39;un total de 3 diferents recompenses!</font></b>";
			break;

			case "danish":
				$this->classname = "Sektor Nova Artifact";
				$this->description = "Dette Artifact vil udlrse en sektor Nova i nogen Warp forbundet Ikke-Federation sektor spilleren har besrgt eller scannet, dette inkluderer SG Sectors. Sektoraftalen Nova vil rdelcgge massive antal af sektionen Defenses, skader alle planeter og skibe i sektoren. Der er i alt " . $this->pieces . " stykker, der skal findes. Nlr alle brikker er fundet, kan du vclge den sektor til at angribe gennem Artifact List kommando. Den Artifact stykker vil blive gemt pl dit skib. Hvis dit skib er rdelagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil vcre tilfcldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->waiting = "<div align=\"center\"> Sensorer pl standby. <br><br> Venter pl at scanne udvalgte sektor. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Du kan ikke bruge Sektor Nova fra en Frderation Sector.";
				$this->pretitle = "Vclg den sektor til at angribe med sektoren Nova";
				$this->nolink = "En Warp Link til denne sektor ikke eksisterer.";
				$this->novisit = "Du har ikke besrgt mllet sektor.";
				$this->nofedtarget = "Du kan ikke mllrette en Frderation Sector.";
				$this->scanning = "<div align=\"center\"> Scanning Sector </div>";
				$this->imtitle = "Sektor under angreb";
				$this->imbody = "[player] bruger en sektor Nova pl [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ADVARSEL: Hvis du flr en dusrr pl en planet, nlr du bruger denne Artifact og der er flere planeter, som endnu ikke blevet ramt endnu, vil du fl en dusrr for hver planet. Hvis der er 5 planeter i sektoren, og du flr en dusrr pl 3. planet, vil du ogsl fl en dusrr pl 4. planet, og en anden dusrr pl 5. planeten for i alt 3 forskellige praemier!</font></b> </font";
			break;

			case "dutch":
				$this->classname = "Sector Nova Artifact";
				$this->description = "Dit Artefact zal verrekend een sector Nova in een Warp Linked Non-Federatie sector van de speler heeft bezocht of gescand, omvat dit SG Sectoren. De sector Nova zal vernietigen massaal van de sector Defenses, schade alle planeten en schepen in de sector. Er zijn in totaal " . $this->pieces . " stukken die moeten worden gevonden. Zodra alle stukken zijn te vinden kunt u de sector aan te vallen via het Artefact opdracht Lijst. De Artefact stukken zal worden opgeslagen op uw schip. Als uw schip wordt vernietigd de aanvaller kan u enkele van de stukken. Elke stukken niet gevangen genomen door de aanvaller zal willekeurig worden verdeeld over de hele melkweg.";
				$this->success = "U hebt al gevonden " . $this->pieces . " stukken van " . $this->classname . ". U kunt deze artefact op elk moment van de Artefact Lijst pagina.";
				$this->incomplete = "U hebt gevonden [pieces] stukken van de " . $this->classname . ". Je moet [left] meer [piece] te voltooien het artefact.";
				$this->singular = "stuk";
				$this->plural = "stuks";
				$this->waiting = "<div align=\"center\"> Sensoren op stand-by. <br><br> Wachten om te scannen geselecteerde sector. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "U kunt geen gebruik maken van de Sector Nova van een Federatie Sector.";
				$this->pretitle = "Selecteer de sector aan te vallen met de sector Nova";
				$this->nolink = "Een Warp Link naar deze sector bestaat niet.";
				$this->novisit = "U hebt niet een bezoek aan de doelgroep.";
				$this->nofedtarget = "U kunt niet richten op een Federatie Sector.";
				$this->scanning = "<div align=\"center\"> Scanning Sector </div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] is met behulp van een sector Nova op [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">WAARSCHUWING: Als u een premie krijgen op een planeet bij gebruik van dit Artefact en er zijn meer planeten die nog niet zijn getroffen, krijgt u een premie voor elke planeet. Als er 5 planeten in de sector en je krijgt een premie op de 3e planeet u krijgt ook nog een premie op de 4e planeet en een bounty op de 5e planeet voor een totaal van 3 verschillende premies!</font></b>";
			break;

			case "finnish":
				$this->classname = "Sector Nova Teos";
				$this->description = "Tämä Teos asettaa pois Ala Nova joka Warp liittyy Ei-liitto alan pelaaja on käynyt tai skannattu, tähän sisältyy SG alat. Ala Nova tuhoavat valtava määrä Sector puolustuksemme vahingot planeetat ja laivojen alalla. On yhteensä " . $this->pieces . " kappaletta, jotka on löydettävä. Kun kaikki palaset löytyy voit valita alan hyökkäys Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hyökkääjä voi löytää joitakin paloja. Kaikki palaset eivät vangiksi hyökkääjän on satunnaisesti ympäri galaksia.";
				$this->success = "Olet löytänyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit käyttää tätä artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet löytänyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lisää [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->waiting = "<div align=\"center\"> Ilmaisinta valmiustilassa. <br><br> Odottavat skannata valitun alalla. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Et voi käyttää Ala Nova lähtien Federation Sector.";
				$this->pretitle = "Valitse ala hyökätä Sector Nova";
				$this->nolink = "Warp Linkki tällä alalla ei ole olemassa.";
				$this->novisit = "Et ole käynyt kohdealaksi.";
				$this->nofedtarget = "Et voi kohdistaa Federation Sector.";
				$this->scanning = "<div align=\"center\"> Skannaus Sector </div>";
				$this->imtitle = "Alan Under Attack";
				$this->imbody = "[player] on käytössä Ala Nova on [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">VAROITUS: Jos saat armo toisella planeetalla kun käytät tämän tuotteen ja on enemmän planeetoilla, jotka eivät ole kärsineet vielä, saat armollinen kunkin planeetan. Jos on 5 planeetat alan ja saat armo on the 3rd planeetan saat myös toinen palkkionmetsästäjä on the 4th planeetalla ja toinen armo on 5. planeetan yhteensä 3 eri palkkioita!</font></b>";
			break;

			case "indonesian":
				$this->classname = "Sektor Nova artifak";
				$this->description = "Artefak ini akan memicu Sektor Nova dalam setiap Warp Linked Non-sektor Federasi pemain telah mengunjungi atau dipindai, ini termasuk Sektor SG. Sektor Nova akan menghancurkan jumlah besar Sektor Pertahanan, merusak semua planet dan kapal-kapal di sektor ini. Ada total " . $this->pieces . " potongan-potongan yang perlu ditemukan. Setelah semua potongan yang ditemukan Anda dapat memilih sektor untuk menyerang melalui perintah Daftar artefak. Potongan artefak akan disimpan di kapal Anda. Jika Anda adalah menghancurkan kapal penyerang dapat menemukan beberapa bagian. Setiap potongan tidak tertangkap oleh penyerang akan didistribusikan secara acak di sekitar galaksi.";
				$this->success = "Anda telah menemukan semua " . $this->pieces . " potongan " . $this->classname . ". Anda dapat menggunakan artifak ini sewaktu-waktu dari halaman Daftar artefak.";
				$this->incomplete = "Anda telah menemukan [pieces] potongan " . $this->classname . ". Anda perlu [left] lebih [piece] untuk melengkapi artefak.";
				$this->singular = "potong";
				$this->plural = "potongan";
				$this->waiting = "<div align=\"center\"> Sensor di Siaga. <br><br> Menunggu untuk memindai sektor yang dipilih. </div>";
				$this->fire = "Sektor api Nova";
				$this->federation = "Anda tidak dapat menggunakan Sektor Nova dari Sektor Federasi.";
				$this->pretitle = "Pilih Sektor untuk menyerang dengan Sektor Nova";
				$this->nolink = "Sebuah Warp Link ke sektor yang tidak ada.";
				$this->novisit = "Anda belum mengunjungi sektor sasaran.";
				$this->nofedtarget = "Anda tidak dapat menargetkan Sektor Federasi.";
				$this->scanning = "<div align=\"center\"> Sektor scanning </div>";
				$this->imtitle = "Sektor Under Attack";
				$this->imbody = "[player] adalah menggunakan Sektor Nova pada [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">PERINGATAN: Jika anda mendapatkan hadiah pada satu planet ketika menggunakan artifak ini dan ada lebih banyak planet yang belum pernah terkena belum, Anda akan mendapatkan karunia untuk SETIAP planet. Jika terdapat 5 planet dalam sektor dan Anda mendapatkan karunia di planet ke-3 Anda juga akan mendapatkan hadiah lain di planet ke-4 dan karunia lain pada tanggal 5 planet total 3 nikmat yang berbeda!</font></b>";
			break;

			case "norwegian":
				$this->classname = "Sector Nova Artifact";
				$this->description = "Dette Artifact vil sette av en sektor Nova i noen Warp Linkede Non-Federation sektor spilleren har besrkt eller skannet, inkluderer dette SG Sectors. Sektoren Nova vil rdelegge store mengder Sector Defenses, skader alle planeter og skip i sektoren. Det er totalt " . $this->pieces . " stykker som trenger l bli funnet. Nlr alle brikkene er funnet kan du velge sektoren l angripe gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret pl skipet ditt. Hvis skipet ditt blir rdelagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand nlr som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for l fullfrre gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->waiting = "<div align=\"center\"> Sensorer pl Standby. <br><br> Venter pl l skanne valgte sektor. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Du kan ikke bruke Sector Nova fra en frderasjon sektor.";
				$this->pretitle = "Velg sektor til l angripe med sektoren Nova";
				$this->nolink = "En Warp Link til denne sektoren ikke eksisterer.";
				$this->novisit = "Du har ikke besrkt mllet sektor.";
				$this->nofedtarget = "Du kan ikke mllrette en frderasjon sektor.";
				$this->scanning = "<div align=\"center\"> Skanning Sector </div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] bruker en Sector Nova pl [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ADVARSEL: Hvis du flr en dusrr pl en planet nlr du bruker denne Artifact, og det er flere planeter som ikke har blitt truffet ennl, flr du en dusrr for hver planet. Hvis det er 5 planeter i sektoren, og fl deg en dusrr pl 3. planeten vil du ogsl fl en bounty on the 4th planeten og en skuddpremie pl den 5. planeten for totalt 3 forskjellige bounties!</font></b>";
			break;

			case "portuguese":
				$this->classname = "Setor Nova Artefato";
				$this->description = "Este artefato vai detonar uma Nova Setor de qualquer Linked Warp Non-Federaçao do sector, o jogador tem visitado ou digitalizados, isto inclui SG Setores. A Nova Setor vai destruir um número maciço de Setor defesas, os danos e os navios de todos os planetas no setor. Há um total de " . $this->pieces . " peças que precisam ser encontrados. Uma vez que todas as peças sao encontradas voce pode selecionar o setor de ataque através do comando List Artefato. As peças Artefato serao armazenados em seu navio. Se o seu navio é destruído o invasor pode encontrar algumas das peças. Todas as partes nao captadas pelo atacante serao distribuídos aleatoriamente em torno da galáxia.";
				$this->success = "Voce encontrou todos " . $this->pieces . " peças do " . $this->classname . ". Voce pode usar esse artefato, a qualquer momento a partir da página Lista de Artefato.";
				$this->incomplete = "Voce encontrou [pieces] peças do " . $this->classname . ". Voce precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "pedaço";
				$this->plural = "peças";
				$this->waiting = "<div align=\"center\"> Sensores de espera. <br><br> Esperando para fazer a varredura do setor selecionado. </div>";
				$this->fire = "Fire Setor Nova";
				$this->federation = "Voce nao pode usar a Nova Sector de um setor da Federaçao.";
				$this->pretitle = "Selecione o setor de ataque com o Setor Nova";
				$this->nolink = "A Link Warp para o setor nao existe.";
				$this->novisit = "Voce ainda nao visitou o setor de destino.";
				$this->nofedtarget = "Voce nao pode ter como alvo um setor da Federaçao.";
				$this->scanning = "<div align=\"center\"> Digitalizaçao Setor </div>";
				$this->imtitle = "Setor Under Attack";
				$this->imbody = "[player] está usando uma Nova Setor no [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">ATENÇAO: Se voce receber uma recompensa em um planeta quando usando este artefato e nao há mais planetas que nao foram atingidos, no entanto, voce receberá uma recompensa para cada planeta. Se existem 5 planetas no setor e voce terá uma recompensa no planeta 3 também vai ter outra graça no planeta 4 e outra recompensa do planeta 5 para um total de 3 prémios diferentes!</font></b>";
			break;

			case "swedish":
				$this->classname = "Sector Nova Artefakt";
				$this->description = "Detta Artefakt kommer att kvitta en sektor Nova i nlgon Warp Linked Icke-Federation sektor spelaren har besökt eller skannade omfattar detta SG Sectors. Sektorsöverenskommelsen Nova kommer att förstöra enorma mängder Sector försvaret, skada alla planeter och fartyg i sektorn. Finns totalt " . $this->pieces . " bitar som mlste hittas. När alla bitar finns kan du välja den sektorn att angripa genom den fiktiva List kommandot. Artefakten bitar sparas pl ditt skepp. Om ditt skepp förstörs Angriparen kan hitta nlgra av de bitar. Alla bitar som inte flngas upp av angriparen kommer att vara slumpmässigt fördelade över galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan använda denna artefakt som helst frln den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du behöver [left] mer [piece] för att genomföra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->waiting = "<div align=\"center\"> Sensorer pl Standby. <br><br> Väntar skanna vald sektor. </div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "Du kan inte använda Sector Nova frln en federation Sector.";
				$this->pretitle = "Välj sektorn att anfalla med sektorn Nova";
				$this->nolink = "En Warp Länk till denna sektor finns inte.";
				$this->novisit = "Du har inte besökt i mllgruppen.";
				$this->nofedtarget = "Du kan inte rikta en federation Sector.";
				$this->scanning = "<div align=\"center\"> Scanning Sector </div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] använder en Sector Nova [sector]";
				$this->warning = "<b><font size=\"4\" color=\"red\">VARNING: Om du flr en belöning pl en planet när denna Artefakt och det finns fler planeter som inte har drabbats än, sl flr du en belöning för varje planet. Om det finns 5 planeter i branschen och du flr en belöning pl 3: e planet kommer du ocksl fl en bounty pl 4: e planet och en bounty pl 5: e planet för sammanlagt 3 olika skottpengar!</font></b>";
			break;

			default:
				$this->classname = "Sector Nova Artifact";
				$this->description = "This Artifact will set off a Sector Nova in any Warp Linked Non-Federation sector the player has visited or scanned, this includes SG Sectors.  The Sector Nova will destroy massive numbers of Sector Defenses, damage all planets and ships in the sector.  There are a total of " . $this->pieces . " pieces that need to be found.  Once all pieces are found you can select the sector to attack through the Artifact List command.  The Artifact pieces will be stored on your ship.  If your ship is destroyed the attacker may find some of the pieces.  Any pieces not captured by the attacker will be randomly distributed around the galaxy.";
				$this->success = "You have found all " . $this->pieces . " pieces of the " . $this->classname . ".  You can use this artifact at any time from the Artifact List page.";
				$this->incomplete = "You have found [pieces] pieces of the " . $this->classname . ".  You need [left] more [piece] to complete the artifact.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->waiting = "<div align=\"center\">Sensors at Standby.<br><br>Waiting to scan selected sector.</div>";
				$this->fire = "Fire Sector Nova";
				$this->federation = "You cannot use the Sector Nova from a Federation Sector.";
				$this->pretitle = "Select the Sector to attack with the Sector Nova";
				$this->nolink = "A Warp Link to that sector does not exist.";
				$this->novisit = "You have not visited the target sector.";
				$this->nofedtarget = "You cannot target a Federation Sector.";
				$this->scanning = "<div align=\"center\">Scanning Sector</div>";
				$this->imtitle = "Sector Under Attack";
				$this->imbody = "[player] is using a Sector Nova on [sector]";
				$this->warning = "<font size=\"4\" color=\"red\"><b>WARNING: If you get a bounty on one planet when using this Artifact and there are more planets that haven't been hit yet, you will get a bounty for EACH planet.  If there are 5 planets in the sector and you get a bounty on the 3rd planet you will also get another bounty on the 4th planet and another bounty on the 5th planet for a total of 3 different bounties!</b></font>";
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
		global $db, $db_prefix, $playerinfo, $shipinfo, $sectorinfo, $template_object, $gameurl, $gamepath, $l_global_mmenu ;

		$output ="";

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

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

		$target_sectorid = $shipinfo["sector_id"];

		$res = $db->Execute("SELECT {$db_prefix}universe.zone_id, {$db_prefix}universe.sector_name, {$db_prefix}universe.sector_id, {$db_prefix}links.link_dest FROM {$db_prefix}links, {$db_prefix}universe WHERE {$db_prefix}links.link_start='$target_sectorid' and {$db_prefix}universe.sector_id ={$db_prefix}links.link_dest ORDER BY {$db_prefix}universe.sector_name ASC");
		db_op_result($res,__LINE__,__FILE__);

		$resultlist = "";
		if ($res > 0)
		{
			while (!$res->EOF)
			{
				$res_return = $db->Execute("SELECT source FROM {$db_prefix}sector_log WHERE player_id=$playerinfo[player_id] and (source='" . $res->fields['sector_id'] . "' or destination='" . $res->fields['sector_id'] . "')");
				db_op_result($res_return,__LINE__,__FILE__);
				$visitedcount = $res_return->RecordCount();
				$res_return->close();
				if($res->fields['zone_id'] != 2)
				{
					if($visitedcount > 0)
					{
						$resultlist .= "<input onClick=\"makeRequest('" . $res->fields['sector_name'] . "');\" type=\"radio\" name=\"attacksector\" value=\"" . $res->fields['sector_name'] . "\"> " . $res->fields['sector_name'] . "<br>";
					}
					else
					{
						$resultlist .= $res->fields['sector_name'] . "<br>";
					}
				}
				else
				{
					$resultlist .= "F>" . $res->fields['sector_name'] . "<br>";
				}
				$res->MoveNext();
			}
		}
		$res->close();

		$output .= "<script type=\"text/javascript\">
<!--
var xmlDoc = null ;
var returndata = '' ;
var sectorname = '' ;

function makeRequest(sectorname)
{
	if ( xmlDoc == null )
	{
		if (typeof window.ActiveXObject != 'undefined' ) {
			xmlDoc = new ActiveXObject(\"Microsoft.XMLHTTP\");
			xmlDoc.onreadystatechange = process ;
	}
		else
		{
			xmlDoc = new XMLHttpRequest();
			xmlDoc.onload = process ;
		}
	}
	document.getElementById('output').innerHTML = '" . $this->scanning . "';

	xmlDoc.open( \"GET\", \"http://" . $gameurl . $gamepath . ($gamepath == "/" ? "" : "/") . "sector_scan.php?ajax=1&command=scan&sector=\" + sectorname, true );
	xmlDoc.send( null );
}

function process() {
	if ( xmlDoc.readyState != 4 )
	{
		return ;
	}
	returndata = xmlDoc.responseText
//	document.write(returndata)

	document.getElementById('output').innerHTML = returndata;
}

//-->
</script>

<form action=\"artifact_process.php?process_type=post&artifact=" . $artifact_type ."\" method=\"post\" enctype=\"multipart/form-data\">
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td colspan=\"2\"><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->pretitle . "</b></font></div></td>
        </tr>
		<tr>
			<td align=\"center\">
				<font color=\"white\">" . $resultlist ."</font><br>
				<input type=\"submit\" id=\"" . $this->fire . "\" value=\"" . $this->fire . "\" name=\"" . $this->fire . "\" >
			</td>
			<td  id=\"output\">" . $this->waiting ."
			</td>
		</tr>
		<tr>
			<td colspan=\"2\"><div align=\"center\">" . $this->warning . "</div></td>
		</tr>
        <tr>
          <td colspan=\"2\"><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>
</form>";

		return $output;
	}

	function postprocess_artifact($artifact_type)
	{
		global $db, $db_prefix, $playerinfo, $l_unnamed, $shipinfo, $sectorinfo, $playerinfo, $l_global_mmenu, $langdir;

		$res = $db->Execute("SELECT count(artifact_id) total FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
   		db_op_result($res,__LINE__,__FILE__);
   		if($res->fields['total'] < $this->pieces)
   		{
   			return;
	  	}

		$res = $db->Execute("SELECT * FROM {$db_prefix}universe WHERE sector_name =" . $db->qstr($_POST['attacksector']));
		db_op_result($res,__LINE__,__FILE__);
		$sector = $res->fields['sector_id'];
		$zones['zone_id'] = $res->fields['zone_id'];
	  	$query96 = $res->fields;
		if($res->fields['zone_id'] == 2)
		{
			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->nofedtarget . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
			return $output;
		}

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

		$result = $db->Execute("SELECT * FROM {$db_prefix}links WHERE link_start='$shipinfo[sector_id]' AND link_dest=" . $db->qstr($sector));
		if($result->RecordCount() == 0)
		{
			$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->nolink . "</b></font></div></td>
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
			$res_return = $db->Execute("SELECT source FROM {$db_prefix}sector_log WHERE player_id=$playerinfo[player_id] and (source='" . $sector . "' or destination='" . $sector . "')");
			db_op_result($res_return,__LINE__,__FILE__);
			$visitedcount = $res_return->RecordCount();
			$res_return->close();
			if($visitedcount == 0)
			{
				$output ="
<div align=\"center\">
	<table border=\"1\" CELLSPACING=\"0\" CELLPADDING=\"2\" bgcolor=\"#000000\">
        <tr>
          <td><div align=\"center\"><font size=\"2\" color=\"lime\"><b>" . $this->novisit . "</b></font></div></td>
        </tr>
        <tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
	</table>
</div>";
				return $output;
			}
		}

		include("languages/$langdir/lang_novabomb.inc");
		include("languages/$langdir/lang_combat.inc");
	  	include ("globals/set_max_credits.inc");
	  	include ("globals/send_system_im.inc");
	  	include ("globals/planet_bounty_check.inc");

		$res = $db->Execute("DELETE FROM {$db_prefix}artifacts WHERE player_id=$playerinfo[player_id] and artifact_type='" . $this->class . "'");
		db_op_result($res,__LINE__,__FILE__);

	  	$output = "<TABLE BORDER=1 CELLSPACING=0 CELLPADDING=5 align=\"center\" bgcolor=\"#000000\">
		<tr><td><TABLE BORDER=0 CELLSPACING=0 CELLPADDING=5 align=\"center\" bgcolor=\"#000000\">";
	  	$output .= "<TR BGCOLOR=\"#23244F\"><TD><B><font color='#ff0000' size='4'>" . str_replace("[sector]", $query96['sector_name'], $l_novabomb_success) . "</font></B></TD></TR>";
	  	$output .= "<TR><TD>";

	  	$res = $db->Execute("SELECT * FROM {$db_prefix}sector_defense WHERE sector_id='$sector'");
	  	$qtyfighters = 0;
	  	$qtymines = 0;
	  	$i = 0;
	  	if ($res > 0)
	  	{
	  		while (!$res->EOF)
	  		{
	  			$defences = $res->fields;
	  			$defense_id = $defences['defense_id'];
	  			if ($defences['defense_type'] == 'fighters')
	  			{
	  				$fightersleft = floor($defences['quantity'] * (rand(35, 100) * 0.01));
	  				$qtyfighters += $defences['quantity'] - $fightersleft;
	  				$debug_query = $db->Execute("UPDATE {$db_prefix}sector_defense SET quantity=$fightersleft WHERE " .
	  											"defense_id = $defense_id");
	  				db_op_result($debug_query,__LINE__,__FILE__);
	  			}
		  		if ($defences['defense_type'] == 'mines')
	  			{
	  				$minesleft = floor($defences['quantity'] * (rand(35, 100) * 0.01));
	  				$qtymines += $defences['quantity'] - $minesleft;
	  				$debug_query = $db->Execute("UPDATE {$db_prefix}sector_defense SET quantity=$minesleft WHERE " .
	  											"defense_id = $defense_id");
	  				db_op_result($debug_query,__LINE__,__FILE__);
	  			}
	  			$i++;
	  			$res->MoveNext();
	  		}
	  	}

	  	$l_novabomb_fighters = str_replace("[fighters]", "<font color=white><b>" . NUMBER($qtyfighters) . "</b></font>", $l_novabomb_fighters);
	  	$l_novabomb_mines = str_replace("[mines]", "<font color=white><b>" . NUMBER($qtymines) . "</b></font>", $l_novabomb_mines);

	  	if($qtyfighters)
	  	{
	  		$output .= "<TR BGCOLOR=\"#3A3B6E\"><TD><B>$l_novabomb_fighters</B></TD></TR>";
	  	}

	  	if($qtymines)
	  	{
	  		$output .= "<TR BGCOLOR=\"#23244F\"><TD><B>$l_novabomb_mines</B></TD></TR>";
	  	}

	  	$result4 = $db->Execute("SELECT * FROM {$db_prefix}planets WHERE sector_id=$sector");
	  	$sectorplanets = $result4->RecordCount();

	  	$dev_nova_warpdamage = 70;

	  	if ($sectorplanets > 0)
	  	{
	  		$output .= "<TR BGCOLOR=\"#3A3B6E\"><TD>&nbsp;</TD></TR>";
	  		$output .= "<TR BGCOLOR=\"#585980\"><TD><B>$l_novabomb_planetsdamaged</b></TD></TR>";
	  		while (!$result4->EOF)
	  		{
	  			$sectorplanet = $result4->fields;
	  			if ($sectorplanet['owner'] != 0)
	  			{
		  			$result5 = $db->Execute("SELECT * FROM {$db_prefix}players WHERE player_id=". $sectorplanet['owner'] . "");
	  				$planet_owner = $result5->fields;
		  			send_system_im($sectorplanet['owner'], $this->imtitle, str_replace("[player]", $playerinfo['character_name'], str_replace("[sector]", $query96['sector_name'], $this->imbody)), $planet_owner['last_login']);

		  			$isfedbounty = planet_bounty_check($playerinfo, $sectorplanet['sector_id'], $planet_owner, 1, 0.1);

		  			if($isfedbounty > 0)
		  			{
			  			$output .= $l_by_fedbounty2 . "<BR><BR>";
		  			}
		  		}
	  			$afteractionplanettech['fighter'] = floor($sectorplanet['fighter'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['sensors'] = floor($sectorplanet['sensors'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['beams'] = floor($sectorplanet['beams'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['torp_launchers'] = floor($sectorplanet['torp_launchers'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['shields'] = floor($sectorplanet['shields'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['jammer'] = floor($sectorplanet['jammer'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['cloak'] = floor($sectorplanet['cloak'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['armor'] = floor($sectorplanet['armor'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['torps'] = floor($sectorplanet['torps'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['fighters'] = floor($sectorplanet['fighters'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['colonists'] = floor($sectorplanet['colonists'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['special_amount'] = $sectorplanet['special_amount'] * (rand($dev_nova_warpdamage, 100) * 0.01);
			  	$afteractionplanettech['organics'] = floor($sectorplanet['organics'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['ore'] = floor($sectorplanet['ore'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['goods'] = floor($sectorplanet['goods'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['credits'] = floor($sectorplanet['credits'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['energy'] = floor($sectorplanet['energy'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['sector_defense_weapons'] = floor($sectorplanet['sector_defense_weapons'] * (rand($dev_nova_warpdamage, 100) * 0.01));
			  	$afteractionplanettech['sector_defense_cloak'] = floor($sectorplanet['sector_defense_cloak'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionplanettech['sector_defense_sensors'] = floor($sectorplanet['sector_defense_sensors'] * (rand($dev_nova_warpdamage, 100) * 0.01));

				$build_log_entry = $l_cmb_planet_tech_drop;
				$build_log_entry=str_replace("[sector_defense_weapons]","<font color=\"#00ff00\">". $sectorplanet['sector_defense_weapons'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sector_defense_weapons_new]","<font color=\"#ff0000\">". $afteractionplanettech['sector_defense_weapons'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sector_defense_sensors]","<font color=\"#00ff00\">". $sectorplanet['sector_defense_sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sector_defense_sensors_new]","<font color=\"#ff0000\">". $afteractionplanettech['sector_defense_sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sector_defense_cloak]","<font color=\"#00ff00\">". $sectorplanet['sector_defense_cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sector_defense_cloak_new]","<font color=\"#ff0000\">". $afteractionplanettech['sector_defense_cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[fighter]","<font color=\"#00ff00\">". $sectorplanet['fighter'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionplanettech['fighter'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sensors]","<font color=\"#00ff00\">". $sectorplanet['sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionplanettech['sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[beams]","<font color=\"#00ff00\">". $sectorplanet['beams'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionplanettech['beams'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[torps]","<font color=\"#00ff00\">". $sectorplanet['torp_launchers'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionplanettech['torp_launchers'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[shields]","<font color=\"#00ff00\">". $sectorplanet['shields'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionplanettech['shields'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[cloak]","<font color=\"#00ff00\">". $sectorplanet['cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionplanettech['cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[jammer]","<font color=\"#00ff00\">". $sectorplanet['jammer'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[jammer_new]","<font color=\"#ff0000\">". $afteractionplanettech['jammer'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[armor]","<font color=\"#00ff00\">". $sectorplanet['armor'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionplanettech['armor'] . "</font>",$build_log_entry);
				playerlog($sectorplanet['owner'], "LOG5_AFTER_ACTION", $build_log_entry);

	  			if($sectorplanet['name'] == "")
	  			{
			  		$sectorplanet['name'] = $l_unnamed;
			  	}

			  	$output .= "<TR BGCOLOR='#23244F'><TD><B>" . str_replace("[name]", $sectorplanet['name'], $l_novabomb_planet) . "</B></TD></TR>";
	  			$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET 
			  	armor=$afteractionplanettech[armor], special_amount=$afteractionplanettech[special_amount], organics=$afteractionplanettech[organics], 
	  			ore=$afteractionplanettech[ore], goods=$afteractionplanettech[goods], 
			  	sector_defense_weapons=$afteractionplanettech[sector_defense_weapons], sector_defense_cloak=$afteractionplanettech[sector_defense_cloak], sector_defense_sensors=$afteractionplanettech[sector_defense_sensors], 
	  			torps=$afteractionplanettech[torps], fighters=$afteractionplanettech[fighters], colonists=$afteractionplanettech[colonists], 
	  			credits=$afteractionplanettech[credits], energy=$afteractionplanettech[energy], fighter=$afteractionplanettech[fighter], 
	  			sensors=$afteractionplanettech[sensors], beams=$afteractionplanettech[beams], torp_launchers=$afteractionplanettech[torp_launchers], 
	  			shields=$sectorplanet[shields], jammer=$afteractionplanettech[jammer], cloak=$afteractionplanettech[cloak] 
	  			WHERE planet_id=$sectorplanet[planet_id]");
		  		db_op_result($debug_query,__LINE__,__FILE__);
		  		set_max_credits($sectorplanet['planet_id']);

	  			$result4->MoveNext();
		  	}
	  	}

	  	$result4 = $db->Execute("SELECT * FROM {$db_prefix}ships LEFT JOIN {$db_prefix}players ON {$db_prefix}players.player_id = {$db_prefix}ships.player_id " .
	  							"WHERE {$db_prefix}players.currentship={$db_prefix}ships.ship_id and sector_id='$sector' AND on_planet='N'");
	  	$sectorships = $result4->RecordCount();

	  	if ($sectorships > 0)
	  	{
	   		$output .= "<TR BGCOLOR=\"#3A3B6E\"><TD>&nbsp;</TD></TR>";
		  	$output .= "<TR BGCOLOR=\"#585980\"><TD><B>$l_novabomb_shipsdamaged</b></TD></TR>";
	  		while (!$result4->EOF)
	  		{
	  			$sectorship = $result4->fields;
	  			$afteractionshiptech['hull'] = floor($sectorship['hull'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['engines'] = floor($sectorship['engines'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['power'] = floor($sectorship['power'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['fighter'] = floor($sectorship['fighter'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['sensors'] = floor($sectorship['sensors'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['beams'] = floor($sectorship['beams'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionshiptech['torp_launchers'] = floor($sectorship['torp_launchers'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['shields'] = floor($sectorship['shields'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionshiptech['cloak'] = floor($sectorship['cloak'] * (rand($dev_nova_warpdamage, 100) * 0.01));
	  			$afteractionshiptech['armor'] = floor($sectorship['armor'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['armor_pts'] = floor($sectorship['armor_pts'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['torps'] = floor($sectorship['torps'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['fighters'] = floor($sectorship['fighters'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['credits'] = floor($sectorship['credits'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['energy'] = floor($sectorship['energy'] * (rand($dev_nova_warpdamage, 100) * 0.01));
		  		$afteractionshiptech['ecm'] = floor($sectorship['ecm'] * (rand($dev_nova_warpdamage, 100) * 0.01));

				$build_log_entry = $l_cmb_attacker_tech_drop;
				$build_log_entry=str_replace("[hull]","<font color=\"#00ff00\">". $sectorship['hull'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[hull_new]","<font color=\"#ff0000\">". $afteractionshiptech['hull'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[engines]","<font color=\"#00ff00\">". $sectorship['engines'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[engines_new]","<font color=\"#ff0000\">". $afteractionshiptech['engines'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[power]","<font color=\"#00ff00\">". $sectorship['power'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[power_new]","<font color=\"#ff0000\">". $afteractionshiptech['power'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[fighter]","<font color=\"#00ff00\">". $sectorship['fighter'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[fighter_new]","<font color=\"#ff0000\">". $afteractionshiptech['fighter'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sensors]","<font color=\"#00ff00\">". $sectorship['sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[sensors_new]","<font color=\"#ff0000\">". $afteractionshiptech['sensors'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[beams]","<font color=\"#00ff00\">". $sectorship['beams'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[beams_new]","<font color=\"#ff0000\">". $afteractionshiptech['beams'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[torps]","<font color=\"#00ff00\">". $sectorship['torp_launchers'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[torps_new]","<font color=\"#ff0000\">". $afteractionshiptech['torp_launchers'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[shields]","<font color=\"#00ff00\">". $sectorship['shields'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[shields_new]","<font color=\"#ff0000\">". $afteractionshiptech['shields'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[cloak]","<font color=\"#00ff00\">". $sectorship['cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[cloak_new]","<font color=\"#ff0000\">". $afteractionshiptech['cloak'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[ecm]","<font color=\"#00ff00\">". $sectorship['ecm'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[ecm_new]","<font color=\"#ff0000\">". $afteractionshiptech['ecm'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[armor]","<font color=\"#00ff00\">". $sectorship['armor'] . "</font>",$build_log_entry);
				$build_log_entry=str_replace("[armor_new]","<font color=\"#ff0000\">". $afteractionshiptech['armor'] . "</font>",$build_log_entry);
				playerlog($sectorship['player_id'], "LOG5_AFTER_ACTION", $build_log_entry);

	  			$output .= "<TR BGCOLOR='#23244F'><TD><B>" . str_replace("[shipname]", $sectorship['name'], $l_novabomb_ship_damage) . "</B></TD></TR>";
	  			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET hull=$afteractionshiptech[hull], engines=$afteractionshiptech[engines], power=$afteractionshiptech[power], 
	  			fighter=$afteractionshiptech[fighter], sensors=$afteractionshiptech[sensors], beams=$afteractionshiptech[beams], torp_launchers=$afteractionshiptech[torp_launchers], 
		  		shields=$afteractionshiptech[shields], cloak=$afteractionshiptech[cloak], armor=$afteractionshiptech[armor], armor_pts=$afteractionshiptech[armor_pts], 
		  		torps=$afteractionshiptech[torps], fighters=$afteractionshiptech[fighters], energy=$afteractionshiptech[energy], ecm=$afteractionshiptech[ecm] WHERE ship_id=$sectorship[ship_id]");
	  			db_op_result($debug_query,__LINE__,__FILE__);

	  			$result4->MoveNext();
	  		}
	  	}
	  	$output .= "</table></td></tr>
	  	<tr>
          <td><div align=\"center\">$l_global_mmenu</div></td>
        </tr>
</table>";
	  	return $output;
	}
}

?>