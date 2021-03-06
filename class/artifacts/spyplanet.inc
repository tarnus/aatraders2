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
				$this->description = "See Tehis paneb spioon iga vaenlase planeeti. See on t�iesti �mbers�it planeedid andurid. Sa pead olema samas sektoris on planeet ja k�ik heldek�elisus piiranguid kohaldatakse. Tehis saab n�ha mingit planeeti sektoris olenemata sellest, milline varjatud v��rtus tal on. On kokku " . $this->pieces . " t�kki, et tuleb leida. Kui k�ik nupud on leitud saate valida planeedi koht spioon kaudu Tehis nimekiri k�sk. Tehis t�kki on salvestatud laeva. Kui teie laev on h�vitatud R�ndaja v�ib leida m�ningaid nuppe. Iga t�kki ei ole p��tud r�ndaja on juhuslikult jagatud �mber galaktika.";
				$this->success = "Sa ei leidnud k�iki " . $this->pieces . " t�kid " . $this->classname . ". V�ite kasutada seda Artefakti igal ajal Tehis nimekiri lehek�ljel.";
				$this->incomplete = "Olete leidnud [pieces] t�kki " . $this->classname . ". Peate [left] veel [piece] l�pule artefaktist.";
				$this->singular = "tk";
				$this->plural = "tk";
				$this->title = "<b><font size=\"4\" color=\"lime\">Koht Spy planeedil</font></b>";
				$this->select = "Valige planeedi koht spioon";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Valitud planeedil pole v�imalik leida selles sektoris.";
				$this->l_fedbounty = "<b><font color='red' size='4'>F�deratsioon ei kiida r�nnata palju v�iksemad turuosalised. See on paigutatud halastus teid.</font></b>";
				$this->placedspy = "Spioon �nnestus koht planeedil [planet].";
			break;

			case "french":
				$this->classname = "Planetary Spy Artefact";
				$this->description = "Cet artefact mettra un espion sur une plan�te ennemie. Il sera compl�tement contourner les capteurs plan�tes. Vous devez �tre dans le m�me secteur que la plan�te et toutes les restrictions Bounty sera applicable. L&#39;artefact sera en mesure de voir la plan�te TOUT dans le secteur peu importe ce manteau de valeur qu&#39;elle poss�de. Il ya un total de " . $this->pieces . " pi�ces qui doivent �tre trouv�s. Une fois toutes les pi�ces sont trouv�s, vous pouvez s�lectionner la plan�te � l&#39;endroit de l&#39;espion gr�ce � la commande Liste Artefact. Les morceaux d&#39;artefact seront stock�es sur votre bateau. Si votre vaisseau est d�truit � l&#39;attaquant mai trouver certaines des pi�ces. Les morceaux non exploit�s par l&#39;attaquant seront distribu�es au hasard autour de la galaxie.";
				$this->success = "Vous avez trouv� toutes les " . $this->pieces . " pi�ces de la " . $this->classname . ". Vous pouvez utiliser cet objet � tout moment sur la page Liste Artefact.";
				$this->incomplete = "Vous avez trouv� [pieces] pi�ces de la " . $this->classname . ". Vous devez vous [left] plus [piece] pour terminer l&#39;artefact.";
				$this->singular = "morceau";
				$this->plural = "pi�ces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Place Spy sur la plan�te</font></b>";
				$this->select = "S�lectionnez une plan�te � placer l&#39;espion";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "La plan�te s�lectionn� ne peut �tre trouv� dans ce secteur.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La F�d�ration n&#39;approuve pas d&#39;attaquer des acteurs beaucoup plus petits. Il a plac� une prime sur vous.</font></b>";
				$this->placedspy = "Un espion a r�ussi � placer sur la plan�te [planet].";
			break;

			case "german":
				$this->classname = "Planetary Spy Artefakt";
				$this->description = "Dieses Artefakt wird ein Spion Platz auf jeden Feind Planeten. Es wird komplett umgehen die Planeten-Sensoren. Sie m�ssen in der gleichen Branche wie der Planet und alle G�te Beschr�nkungen gelten. Das Artefakt wird in der Lage, jedem Planeten in diesem Sektor, egal, was Mantel Wert besitzt. Es gibt insgesamt " . $this->pieces . " St�cke, die gefunden werden m�ssen. Wenn alle Teile gefunden sind, k�nnen Sie den Planeten auf der Spion durch das Artefakt List-Kommando zu stellen w�hlen. The Artifact St�cke werden auf dem Schiff gelagert werden. Wenn Ihr Schiff zerst�rt wird der Angreifer einige der St�cke zu finden. Jedes St�ck vom Angreifer nicht erfasst werden nach dem Zufallsprinzip auf der ganzen Galaxie verteilt werden.";
				$this->success = "Sie haben festgestellt, alle " . $this->pieces . " Teile des " . $this->classname . ". Sie k�nnen dieses Artefakt Nutzung jederzeit aus der Liste Artefakt Seite.";
				$this->incomplete = "Sie haben sie gefunden [pieces] Teile des " . $this->classname . ". Sie m�ssen [left] mehr [piece], um das Artefakt abzuschlie�en.";
				$this->singular = "St�ck";
				$this->plural = "St�ck";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy Ort auf dem Planeten</font></b>";
				$this->select = "W�hlen Sie einen Planeten, der Spion Ort";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Die ausgew�hlten Planeten kann nicht in diesem Bereich gefunden werden.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Die F�deration nicht billigen Angriff wesentlich kleinerer Unternehmen. Es hat ein Kopfgeld auf Sie gelegt.</font></b>";
				$this->placedspy = "Ein Spion wurde erfolgreich auf dem Planeten place [planet].";
			break;

			case "italian":
				$this->classname = "Planetari Spy Artifact";
				$this->description = "Questo artefatto metter� una spia su qualsiasi pianeta nemico. E &#39;completamente bypassare i sensori pianeti. Devi essere nello stesso settore, come il pianeta e tutte le restrizioni di taglie si applica. Il manufatto sar� in grado di vedere pianeta QUALSIASI nel settore, non importa cosa mantello valore che esso possiede. Ci sono un totale di " . $this->pieces . " pezzi che devono essere trovati. Una volta che tutti i pezzi sono trovati, � possibile selezionare il pianeta al posto della spia attraverso il comando Artefatto List. I pezzi Artifact verranno memorizzati sulla tua nave. Se la tua nave � distrutta l&#39;utente malintenzionato potrebbe trovare alcuni dei pezzi. I pezzi non catturato da un aggressore saranno distribuiti a caso intorno alla galassia.";
				$this->success = "Hai trovato tutti " . $this->pieces . " pezzi del " . $this->classname . ". � possibile utilizzare questo artefatto in qualsiasi momento dalla pagina Artefatto List.";
				$this->incomplete = "Hai trovato [pieces] pezzi del " . $this->classname . ". Avete bisogno di [left] continua [piece] per completare l&#39;artefatto.";
				$this->singular = "pezzo";
				$this->plural = "pezzi";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy posto su Planet</font></b>";
				$this->select = "Selezionare un pianeta al posto della spia";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Il pianeta selezionato non pu� essere trovato in questo settore.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federazione non approva attaccanti molto pi� piccolo. Ha messo una taglia su di te.</font></b>";
				$this->placedspy = "Una spia � stato posto con successo sul pianeta [planet].";
			break;

			case "spanish":
				$this->classname = "Planetario esp�a Artefacto";
				$this->description = "Este artefacto colocar� un esp�a en cualquier planeta enemigo. Se pasar� por alto completamente los sensores de los planetas. Debe estar en el mismo sector que el planeta y todas las restricciones se aplicar�n recompensa. El artefacto ser� capaz de ver cualquier planeta en el sector no importa lo que la capa de valor que posee. Hay un total de " . $this->pieces . " piezas que necesitan ser encontrados. Una vez que todas las piezas se encuentran se puede seleccionar el planeta para colocar el esp�a a trav�s de la Lista de comandos Artefacto. Las piezas artefacto se almacenar� en su barco. Si el barco es destruido el atacante puede encontrar algunas de las piezas. Cualquier pieza no capturados por el atacante se distribuyen al azar alrededor de la galaxia.";
				$this->success = "Se han encontrado todos los " . $this->pieces . " piezas de la " . $this->classname . ". Usted puede usar este artefacto en cualquier momento desde la p�gina Lista de Artefacto.";
				$this->incomplete = "Se han encontrado [pieces] piezas de la " . $this->classname . ". Usted necesita [left] m�s [piece] para completar el artefacto.";
				$this->singular = "pieza";
				$this->plural = "piezas";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lugar esp�a en el Planeta</font></b>";
				$this->select = "Seleccione un planeta a otro el esp�a";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "El planeta seleccionado no se puede encontrar en este sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federaci�n no aprueba atacar a jugadores mucho m�s peque�os. Se ha puesto una recompensa por usted.</font></b>";
				$this->placedspy = "Un esp�a con �xito lugar en el planeta [planet].";
			break;

			case "albanian":
				$this->classname = "Planetare spiun Objekti";
				$this->description = "Kjo Objekti i do t� vendos nj� spiun n� ndonj� planet armikut. Ajo do t� anashkaloj� plot�sisht sensor� planetet. Ju duhet t� jet� n� sektorin e nj�jt� si t� gjith� planetin dhe do t� aplikohen kufizimet e mir�sis�. Objekti do t� jet� n� gjendje t� shohim planetin NDONJE n� sektorin pa marr� parasysh �far� mantel vler� q� ajo zot�ron. Ka nj� num�r t� " . $this->pieces . " pjes� q� duhet t� gjendet. Pasi t� gjitha k�ng�t jan� gjetur ju mund t� zgjidhni planetit p�r t� vendosur spiun p�rmes komand�s Lista Objekti. Objekti do t� jet� pjes� ruhet n� anije tuaj. N�se anija juaj �sht� shkat�rruar sulmues mund t� gjeni disa nga copa. �do cop� nuk kapur nga sulmuesit do t� shp�rndahen rreth rast�sisht galaktik�.";
				$this->success = "Ju keni gjetur t� gjith� " . $this->pieces . " cop� " . $this->classname . ". Ju mund t� p�rdorni k�t� Objekti n� �do koh� nga faqe Lista Objekti.";
				$this->incomplete = "Ju keni gjetur [pieces] cop� " . $this->classname . ". Ju duhet [left] m� [piece] p�r t� p�rfunduar Objekti.";
				$this->singular = "cop�";
				$this->plural = "cop�";
				$this->title = "<b><font size=\"4\" color=\"lime\">Vendi spiun n� Planet</font></b>";
				$this->select = "Zgjidhni nj� planet n� vendin e spiun";
				$this->l_bountyscan = "Mirat";
				$this->noplanet = "Planet e zgjedhur nuk mund t� gjenden n� k�t� sektor.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federata nuk e miratojn� sulmuar lojtar� shum� m� t� vog�l. Ajo ka vendosur nj� begati p�r ju.</font></b>";
				$this->placedspy = "Nj� spiun u zhvillua me sukses n� planetin [planet].";
			break;

			case "catalan":
				$this->classname = "Planetari espia Artefacte";
				$this->description = "Aquest artefacte col.locar� un espia a qualsevol planeta enemic. Es passar� per alt completament els sensors dels planetes. Ha d&#39;estar en el mateix sector que el planeta i totes les restriccions s&#39;aplicaran recompensa. L&#39;artefacte ser� capa� de veure qualsevol planeta en el sector no importa el que la capa de valor que t�. Hi ha un total de " . $this->pieces . " peces que necessiten ser trobats. Un cop que totes les peces es troben es pot seleccionar el planeta per col.locar el espia a trav�s de la Llista de comandaments Artefacte. Les peces artefacte quedar� emmagatzemat al vaixell. Si el vaixell �s destru�t l&#39;atacant pot trobar algunes de les peces. Qualsevol pe�a no capturats per l&#39;atacant es distribueixen a l&#39;atzar al voltant de la gal�xia.";
				$this->success = "S&#39;han trobat tots els " . $this->pieces . " peces de la " . $this->classname . ". Vost� pot usar aquest artefacte en qualsevol moment des de la p�gina Llista de Artefacte.";
				$this->incomplete = "S&#39;han trobat [pieces] peces de la " . $this->classname . ". Vost� necessita [left] m�s [piece] per completar l&#39;artefacte.";
				$this->singular = "pe�a";
				$this->plural = "peces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Lloc espia al Planeta</font></b>";
				$this->select = "Seleccioneu un planeta a un altre l&#39;espia";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "El planeta seleccionat no es pot trobar en aquest sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>La Federaci� no aprova atacar jugadors molt m�s petits. S&#39;ha col.locat una recompensa per vost�.</font></b>";
				$this->placedspy = "Un espia amb �xit lloc al planeta [planet].";
			break;

			case "danish":
				$this->classname = "Planetary Spy Artifact";
				$this->description = "Dette Artifact vil placere en spion p� en fjendtlig planet. Det vil helt omg� planeter sensorer. Du skal v�re i den samme sektor som planeten og alle dus�r restriktioner finder anvendelse. Den Artifact vil v�re i stand til at se nogen planet i sektoren uanset hvad kappen v�rdi den har. Der er i alt " . $this->pieces . " stykker, der skal findes. N�r alle brikker er fundet, kan du v�lge planeten for at placere spion gennem Artifact List kommando. Den Artifact stykker vil blive gemt p� dit skib. Hvis dit skib er �delagt hacker kan finde nogle af brikkerne. Nogen stykker, ikke opfanges af angriberen vil v�re tilf�ldigt fordelt over hele galaksen.";
				$this->success = "Du har fundet alle " . $this->pieces . " stykker af " . $this->classname . ". Du kan bruge denne genstand som helst fra Artifact List side.";
				$this->incomplete = "Du har fundet [pieces] stykker af " . $this->classname . ". Du har brug for [left] mere [piece] for at afslutte artefakt.";
				$this->singular = "brik";
				$this->plural = "stykker";
				$this->title = "<b><font size=\"4\" color=\"lime\">Sted Spy p� Planet</font></b>";
				$this->select = "V�lg en planet for at placere spion";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Den valgte planet kan ikke findes i denne sektor.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Federation ikke godkender at angribe meget mindre akt�rer. Det har sat en dus�r p� dig.</font></b>";
				$this->placedspy = "En spion lykkedes sted p� planeten [planet].";
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
				$this->description = "T�m� Teos asettaa vakoilla tahansa vihollisen planeetalla. Se on kokonaan ohi planeetat anturit. Sinun t�ytyy olla samalla alalla kuin maapallon ja kaikki armo rajoituksia sovelletaan. Teos voi n�hd� mit��n Planet alalla riippumatta siit�, mit� piilo-arvo sill� on. On yhteens� " . $this->pieces . " kappaletta, jotka on l�ydett�v�. Kun kaikki palaset l�ytyy voit valita planeetan saattaa vakooja kautta Artifact List-komentoa. Teos kappaleet on tallennettu aluksella. Jos alus on tuhoutunut hy�kk��j� voi l�yt�� joitakin paloja. Kaikki palaset eiv�t vangiksi hy�kk��j�n on satunnaisesti ymp�ri galaksia.";
				$this->success = "Olet l�yt�nyt kaikki " . $this->pieces . " palaset " . $this->classname . ". Voit k�ytt�� t�t� artefakti milloin tahansa Artifact-sivulta.";
				$this->incomplete = "Olet l�yt�nyt [pieces] paloja " . $this->classname . ". Tarvitset [left] lis�� [piece] loppuun artefakti.";
				$this->singular = "palan";
				$this->plural = "palaset";
				$this->title = "<b><font size=\"4\" color=\"lime\">Paikka vakoilla Planet</font></b>";
				$this->select = "Valitse planeetan saattaa vakooja";
				$this->l_bountyscan = "Runsaudessaan";
				$this->noplanet = "Valitun planeetta ei l�ydy t�ll� alalla.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Liitto ei hyv�ksy hy�kk�� paljon pieni� toimijoita. Se on sijoitettu armo teit�.</font></b>";
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
				$this->description = "Dette Artifact vil plassere en spion p� en fiende planet. Det vil helt utenom planetene sensorer. Du m� v�re i samme sektor som planeten og alle skuddpremie restriksjoner gjelder. The Artifact vil kunne se noen planet i sektoren uansett hva kappen verdi det har. Det er totalt " . $this->pieces . " stykker som trenger � bli funnet. N�r alle brikkene er funnet kan du velge planeten � plassere spion gjennom Artifact Liste-kommandoen. The Artifact brikkene vil bli lagret p� skipet ditt. Hvis skipet ditt blir �delagt angriperen kan finne noen av bitene. Eventuelle brikkene ikke fanges opp av angriperen vil bli tilfeldig fordelt rundt om i galaksen.";
				$this->success = "Du har funnet alle " . $this->pieces . " stykker av " . $this->classname . ". Du kan bruke denne gjenstand n�r som helst fra Artifact-siden.";
				$this->incomplete = "Du har funnet [pieces] stykker av " . $this->classname . ". Du trenger [left] mer [piece] for � fullf�re gjenstand.";
				$this->singular = "piece";
				$this->plural = "pieces";
				$this->title = "<b><font size=\"4\" color=\"lime\">Plasser Spy on Planet</font></b>";
				$this->select = "Velg en planet for � plassere spy";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "Den valgte Planeten kan ikke forekomme i denne sektoren.";
				$this->l_fedbounty = "<b><font color='red' size='4'>Landsorganisasjonen godtar ikke � angripe mye mindre spillere. Det har plassert en dus�r p� deg.</font></b>";
				$this->placedspy = "En spion ble vellykket sted p� planeten [planet].";
			break;

			case "portuguese":
				$this->classname = "Planet�rio Spy Artefato";
				$this->description = "Este artefato vai colocar um espi�o em qualquer planeta inimigo. Ele ir� ignorar completamente os sensores de planetas. Voc� deve estar no mesmo sector, como o planeta e todas as restri��es recompensa ser� aplicada. O artefato ser� capaz de ver de qualquer outro planeta do sector n�o importa o manto valor que possui. H� um total de " . $this->pieces . " pe�as que precisam ser encontrados. Uma vez que todas as pe�as s�o encontradas voc� pode selecionar o planeta para colocar o espi�o atrav�s do comando List Artefato. As pe�as Artefato ser�o armazenados em seu navio. Se o seu navio � destru�do o invasor pode encontrar algumas das pe�as. Todas as partes n�o captadas pelo atacante ser�o distribu�dos aleatoriamente em torno da gal�xia.";
				$this->success = "Voc� encontrou todos " . $this->pieces . " pe�as do " . $this->classname . ". Voc� pode usar esse artefato, a qualquer momento a partir da p�gina Lista de Artefato.";
				$this->incomplete = "Voc� encontrou [pieces] pe�as do " . $this->classname . ". Voc� precisa [left] mais [piece] para completar o artefato.";
				$this->singular = "peda�o";
				$this->plural = "pe�as";
				$this->title = "<b><font size=\"4\" color=\"lime\">Spy lugar no Planeta</font></b>";
				$this->select = "Selecione um planeta para colocar o espi�o";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "O planeta escolhido n�o pode ser encontrado neste sector.";
				$this->l_fedbounty = "<b><font color='red' size='4'>A Federa��o n�o aprovar de atacar jogadores muito menor. Colocou uma gra�a em voc�.</font></b>";
				$this->placedspy = "Um espi�o foi sucesso lugar no planeta [planet].";
			break;

			case "swedish":
				$this->classname = "Planetary Spy Artefakt";
				$this->description = "Detta Artefakt kommer att placera en spion p� n�gon fiende planet. Det kommer helt f�rbi planeterna sensorer. Du m�ste vara i samma bransch som v�r planet och alla begr�nsningar givmildhet kommer att g�lla. Artefakten kommer att kunna se alla planeter i branschen oavsett mantel v�rde det har. Finns totalt " . $this->pieces . " bitar som m�ste hittas. N�r alla bitar finns kan du v�lja planeten att placera spionera genom den fiktiva List kommandot. Artefakten bitar sparas p� ditt skepp. Om ditt skepp f�rst�rs Angriparen kan hitta n�gra av de bitar. Alla bitar som inte f�ngas upp av angriparen kommer att vara slumpm�ssigt f�rdelade �ver galaxen.";
				$this->success = "Du har hittat alla " . $this->pieces . " bitar av " . $this->classname . ". Du kan anv�nda denna artefakt som helst fr�n den fiktiva List sida.";
				$this->incomplete = "Du har hittat [pieces] bitar av " . $this->classname . ". Du beh�ver [left] mer [piece] f�r att genomf�ra artefakt.";
				$this->singular = "piece";
				$this->plural = "bitar";
				$this->title = "<b><font size=\"4\" color=\"lime\">Placera Spy p� Planet</font></b>";
				$this->select = "V�lj en planet att placera Spy";
				$this->l_bountyscan = "Bounty";
				$this->noplanet = "De utvalda planet kan inte hittas i denna sektor.";
				$this->l_fedbounty = "<b><font color='red' size='4'>F�rbundet godk�nner inte att anfalla mycket mindre akt�rer. Det har placerat en bounty p� dig.</font></b>";
				$this->placedspy = "En spion har framg�ngsrikt plats p� planeten [planet].";
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