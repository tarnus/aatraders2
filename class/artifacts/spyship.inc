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
				$this->description = "See Tehis paneb luurama k�ik praegu katsetada laeva. See on t�iesti �mbers�it laevade andurid. Spioon kantakse laeva �ksk�ik kus ta asub. Pea meeles, et k�ik heldek�elisus piiranguid kohaldatakse. Tehis saab n�ha laeva olenemata sellest, milline varjatud v��rtus tal on. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud saate valida planeedi koht spioon kaudu Tehis nimekiri k�sk. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". V�ite kasutada seda Artefakti igal ajal Tehis nimekiri lehek�ljel.";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->title = "<b><font size=\"4\" color=\"lime\">Koht Spy laeval</font></b>";
				$this->select = "Valige Player koht Laev Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>F�deratsioon ei kiida r�nnata palju v�iksemad turuosalised. See on paigutatud halastus teid.</font></b>";
				$this->placedspy = "Spioon edukalt kohas laeva juhivad [player].";
				$this->submit = "Koht Spy";
			break;

			case "french":
				$this->classname = "Espionner Ship Artefact";
				$this->description = "Cet artefact mettra un espion sur un navire actuellement en phase pilote. Il sera compl�tement contourner les capteurs de navires. L&#39;espion sera mis sur le navire, peu importe o� il se trouve. Rappelez-vous, toutes les restrictions Bounty sera applicable. L&#39;artefact sera en mesure de voir tout navire, peu importe ce manteau valeur qu&#39;il poss�de. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont trouv�s, vous pouvez s�lectionner la plan�te � l&#39;endroit de l&#39;espion gr�ce � la commande Liste Artefact. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". Vous pouvez utiliser cet objet � tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Place espion sur le bateau</font></b>";
				$this->select = "Choisissez un lecteur de placer un navire espion";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La F�d�ration n&#39;approuve pas d&#39;attaquer des acteurs beaucoup plus petits. Il a plac� une prime sur vous.</font></b>";
				$this->placedspy = "Un espion a r�ussi � placer sur le navire pilot� par [player].";
				$this->submit = "Place Spy";
			break;

			case "german":
				$this->classname = "Spy on Ship Artefakt";
				$this->description = "Dieses Artefakt wird ein Spion Ort, auf jedem Schiff derzeit erprobt. Es wird komplett umgehen die Schiffe Sensoren. Der Spion wird auf dem Schiff, egal wo sie sich befindet, platziert werden. Denken Sie daran, gelten alle Beschr�nkungen Pr�mie. Das Artefakt wird in der Lage sein zu sehen, jedes Schiff, egal was Mantel Wert besitzt. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle Teile gefunden sind, k�nnen Sie den Planeten auf der Spion durch das Artefakt List-Kommando zu stellen w�hlen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie k�nnen dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->title = "<b><font size=\"4\" color=\"lime\">Ort Spion auf Schiff</font></b>";
				$this->select = "W�hlen Sie einen Player zu Ort ein Schiff Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Die F�deration nicht billigen Angriff wesentlich kleinerer Unternehmen. Es hat ein Kopfgeld auf Sie gelegt.</font></b>";
				$this->placedspy = "Ein Spion wurde erfolgreich auf dem Schiff gesteuert durch [player].";
				$this->submit = "Ort Spy";
			break;

			case "italian":
				$this->classname = "Spia sulla nave Artefatto";
				$this->description = "Questo artefatto metter� una spia su ogni nave attualmente pilota. E &#39;completamente bypassare i sensori delle navi. La spia sar� imbarcato sulla nave, non importa dove si trova. Ricordate, tutte le restrizioni si applicano Bounty. Il manufatto sar� in grado di vedere alcuna nave non importa quale mantello valore che esso possiede. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, � possibile selezionare il pianeta al posto della spia attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". � possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy posto sulla nave</font></b>";
				$this->select = "Seleziona un giocatore di inserire un Spy Ship";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federazione non approva attaccanti molto pi� piccolo. Ha messo una taglia su di te.</font></b>";
				$this->placedspy = "Una spia � stata correttamente posto a bordo della nave pilotata da [player].";
				$this->submit = "Luogo Spy";
			break;

			case "spanish":
				$this->classname = "Espiar Ship Artefacto";
				$this->description = "Este artefacto colocar� un esp�a en un buque en la actualidad con car�cter experimental. Se pasar� por alto completamente los sensores de los buques. El esp�a se colocar� en el barco, no importa donde se encuentre. Recuerde, todas las restricciones se aplicar�n recompensa. El artefacto ser� capaz de ver cualquier buque, no importa lo que la capa de valor que posee. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el planeta para colocar el esp�a a trav�s de la Lista de comandos Artefacto. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la p�gina Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lugar esp�a del Buque</font></b>";
				$this->select = "Seleccione un jugador para poner un esp�a de buques";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federaci�n no aprueba atacar a jugadores mucho m�s peque�os. Se ha puesto una recompensa por usted.</font></b>";
				$this->placedspy = "Un esp�a con �xito lugar en la nave pilotada por [player].";
				$this->submit = "Lugar Spy";
			break;

			case "albanian":
				$this->classname = "Objekti i spiunuar Ship";
				$this->description = "Kjo Objekti i do t� vendos nj� spiun p�r �do anije aktualisht piloted. Ajo do t� anashkaloj� plot�sisht sensor� anijet. Spiun do t� vendosen n� anije nuk ka r�nd�si se ku ajo ndodhet. Mos harroni, t� gjith� kufizimet e mir�sis� do t� aplikohen. Objekti do t� jet� n� gjendje t� shoh ndonj� anije pa marr� parasysh se �far� mantel vler� q� ajo zot�ron. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur ju mund t� zgjidhni planetit p�r t� vendosur spiun p�rmes komand�s Lista Objekti. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ". Ju mund t� p�rdorni k�t� Objekti n� �do koh� nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->title = "<b><font size=\"4\" color=\"lime\">Vendi spiun t� anijes</font></b>";
				$this->select = "Zgjidhni nj� vend Player p�r t� nj� spiun Ship";
				$this->l_bountyscan = "Mirat";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federata nuk e miratojn� sulmuar lojtar� shum� m� t� vog�l. Ajo ka vendosur nj� begati p�r ju.</font></b>";
				$this->placedspy = "Nj� spiun u zhvillua me sukses n� anije piloted nga [player].";
				$this->submit = "Vendi spiun";
			break;

			case "catalan":
				$this->classname = "Espiar Ship Artefacte";
				$this->description = "Aquest artefacte col.locar� un espia en un vaixell en l&#39;actualitat amb car�cter experimental. Es passar� per alt completament els sensors dels vaixells. L&#39;espia es col.locar� al vaixell, no importa on es trobi. Recordeu, totes les restriccions s&#39;aplicaran recompensa. L&#39;artefacte ser� capa� de veure qualsevol vaixell, no importa el que la capa de valor que t�. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el planeta per col.locar el espia a trav�s de la Llista de comandaments Artefacte. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vost� pot usar aquest artefacte en qualsevol moment des de la p�gina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lloc espia del Vaixell</font></b>";
				$this->select = "Seleccioneu un jugador per posar un espia de vaixells";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federaci� no aprova atacar jugadors molt m�s petits. S&#39;ha col.locat una recompensa per vost�.</font></b>";
				$this->placedspy = "Un espia amb �xit lloc a la nau pilotada per [player].";
				$this->submit = "Lloc Spy";
			break;

			case "danish":
				$this->classname = "Udspionere Ship Artifact";
				$this->description = "Dette Artifact vil placere en spion p� nogen �jeblikket pilotfors�g skib. Det vil helt omg� skibe sensorer. Den spion vil blive placeret p� skibet, uanset hvor den er placeret. Husk, at alle dus�r restriktioner. Den Artifact vil v�re i stand til at se ethvert skib, uanset hvad kappen v�rdi den har. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle brikker er fundet, kan du v�lge planeten for at placere spion gennem Artifact List kommando. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->title = "<b><font size=\"4\" color=\"lime\">Sted Spy p� Ship</font></b>";
				$this->select = "V�lg en spiller til at placere en Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federation ikke godkender at angribe meget mindre akt�rer. Det har sat en dus�r p� dig.</font></b>";
				$this->placedspy = "En spion lykkedes sted p� skibet styres af [player].";
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
				$this->description = "T�m� Teos asettaa vakoilla kaikki nyt kokeiltu alusta. Se on kokonaan ohi alusten anturit. Spy sijoitetaan aluksen miss� se sijaitsee. Muista, kaikki Bounty rajoituksia sovelletaan. Teos on mahdollisuus n�hd� kaikki alukset riippumatta siit�, miss� piilo-arvo sill� on. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset l�ytyy voit valita planeetan saattaa vakooja kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit k�ytt�� t�t� artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->title = "<b><font size=\"4\" color=\"lime\">Paikka Spy Alusten</font></b>";
				$this->select = "Valitse pelaaja asettaa Laiva Spy";
				$this->l_bountyscan = "Runsaudessaan";
				$this->l_fedbounty = "<b><font color='red' size='4'>Liitto ei hyv�ksy hy�kk�� paljon pieni� toimijoita. Se on sijoitettu armo teit�.</font></b>";
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
				$this->classname = "Spionere p� Ship Artifact";
				$this->description = "Dette Artifact vil plassere en spion p� en forel�pig testet ut skipet. Det vil helt utenom skip sensorer. Spionen vil bli plassert p� skip uansett hvor den ligger. Husk at alle Bounty begrensninger. The Artifact vil kunne se alle skip uansett hva kappen verdi det har. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet kan du velge planeten � plassere spion gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand n�r som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Plasser Spy on Ship</font></b>";
				$this->select = "Velg en spiller � plassere et Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>Landsorganisasjonen godtar ikke � angripe mye mindre spillere. Det har plassert en dus�r p� deg.</font></b>";
				$this->placedspy = "En spion ble vellykket plass p� skipet testet av [player].";
				$this->submit = "Place Spy";
			break;

			case "portuguese":
				$this->classname = "Espi�o sobre Ship Artefato";
				$this->description = "Este artefato vai colocar um espi�o em qualquer navio pilotado atualmente. Ele ir� ignorar completamente os sensores de navios. O espi�o ser� colocado a bordo do navio, n�o importa onde ele est� localizado. Lembre-se, todas as restri��es recompensa ser� aplicada. O artefato ser� capaz de ver qualquer navio n�o importa o manto valor que possui. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas voc� pode selecionar o planeta para colocar o espi�o atrav�s do comando List Artefato. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". Voc� pode usar esse artefato, a qualquer momento a partir da p�gina Lista de Artefato.";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->title = "<b><font size=\"4\" color=\"lime\">Coloque Espi�o em navio</font></b>";
				$this->select = "Selecione um jogador para colocar um espi�o Ship";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>A Federa��o n�o aprovar de atacar jogadores muito menor. Colocou uma gra�a em voc�.</font></b>";
				$this->placedspy = "Um espi�o foi sucesso lugar na nave pilotada por [player].";
				$this->submit = "Coloque Spy";
			break;

			case "swedish":
				$this->classname = "Spionera p� Ship Artefakt";
				$this->description = "Detta Artefakt kommer att placera en spion p� n�gon nu lotsade fartyget. Det kommer helt f�rbi fartygen sensorer. Spionen kommer att placeras ombord p� fartyget oavsett var den �r bel�gen. Kom ih�g att alla frikostighet begr�nsningar g�ller. Artefakten kommer att kunna se alla fartyg oavsett vad mantel v�rde det har. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar finns kan du v�lja planeten att placera spionera genom den fiktiva List kommandot. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan anv�nda denna artefakt som helst fr�n den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->title = "<b><font size=\"4\" color=\"lime\">Placera Spy p� Ship</font></b>";
				$this->select = "V�lj en spelare att placera en Ship Spy";
				$this->l_bountyscan = "Bounty";
				$this->l_fedbounty = "<b><font color='red' size='4'>F�rbundet godk�nner inte att anfalla mycket mindre akt�rer. Det har placerat en bounty p� dig.</font></b>";
				$this->placedspy = "En spion har framg�ngsrikt plats p� fartyget som pr�vats [player].";
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