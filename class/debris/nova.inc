<?php
class nova {
	var $classname = "nova";
	var $success = "550";	// Random value range
	var $trigger = "275";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addnova;
	var $l_debris_nothing;
	var $l_debris_removenova;

	// fill language variables
	function nova()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addnova = "Olete leidnud ujuva rusude suure Starship ja leida kasutatavad Nova Bomb sees hulk.";
				$this->l_debris_removenova = "Nagu te l�henemine praht s�num j�uab �le side, �eldes, et planeedi tapja relvad ei tohi selles valdkonnas ruumi. Teie Nova Bomb kohe muutub kasutamisk�lbmatuks ilma n�htava p�hjuseta.";
				$this->l_debris_nothing = "Teie insenerid on otsustanud, on m�ttetu space junk.";
			break;

			case "french":
				$this->l_debris_addnova = "Vous avez trouv� la carcasse d'un grand vaisseau � la d�rive. Vous en ramenez une bombe Nova toujours utilisable.";
				$this->l_debris_removenova = "En approchant des d�bris, un message vous parvient indiquant que les armes antiplan�tes sont ill�gales dans cette r�gion de l'espace. Votre bombe Nova devient soudainement inutilisable!";
				$this->l_debris_nothing = "Vos ing�nieurs d�cident qu'il s'agit de simples d�tritus.";
			break;

			case "german":
				$this->l_debris_addnova = "Sie haben ein schwebendes Wrack eines gro�en Raumschiffs mit einer eingebauten voll funktionsf�higen Nova-Bombe gefunden.";
				$this->l_debris_removenova = "Als Sie sich den Tr�mmern n�hern empf�ngen Sie eine Nachricht, welche sagt, dass in dieser Gegend keine Planeten zerst�renden Waffen erlaubt sind. Ihre Nova-Bombe wurde sofort unbrauchbar gemacht.";
				$this->l_debris_nothing = "Ihre Ingenieure haben herausgefunden, dass es nur nutzloser Weltraumschrott ist.";
			break;

			case "italian":
				$this->l_debris_addnova = "Una Bomba Nova utilizzabile � stata individuata tra i rottami vaganti di una larga nave spaziale.";
				$this->l_debris_removenova = "Mentre ti avvicini ai rottami, ricevi un messaggio attraverso il sistema di comunicazione della nave che afferma che armi di distruzione planetaria non sono permesse in quest'area  di spazio. La tua Bomba Nova diviene inutilizzabile per nessuna ragione apparente..";
				$this->l_debris_nothing = "I tuoi ingenieri hanno analizzato il rottame e non hanno trovato altro che inutilizzabili rifiuti spaziali.";
			break;

			case "spanish":
				$this->l_debris_addnova = "Se han encontrado los restos flotantes de una nave grande y localizar una bomba utilizable Nova dentro de la mole.";
				$this->l_debris_removenova = "Al acercarse a los restos llega un mensaje sobre las comunicaciones diciendo que las armas asesinas planeta no est�n permitidos en esta �rea del espacio. Su Nova Bomb inmediatamente se torna inutilizable por ninguna raz�n aparente.";
				$this->l_debris_nothing = "Sus ingenieros han determinado que es basura espacial in�til.";
			break;

			case "albanian":
				$this->l_debris_addnova = "Ju keni gjetur rr�nojat e nj� lundrues Starship t� m�dha dhe gjeni nj� p�rdorsh�m Nova bomb� brenda kaba.";
				$this->l_debris_removenova = "Si ju qasje mbeturinat nj� mesazh vjen mbi t� komunikimit, duke th�n� se arm�t vras�sin e planetit nuk lejohen n� k�t� zon� e hap�sir�. Bomb� Nova juaj menj�her� b�het e pap�rdorshme p�r asnj� arsye t� dukshme.";
				$this->l_debris_nothing = "Inxhinier� juaj kan� p�rcaktuar se �sht� e padobishme junk hap�sir�.";
			break;

			case "catalan":
				$this->l_debris_addnova = "S&#39;han trobat les restes flotants d&#39;una nau gran i localitzar una bomba utilitzable Nova dins de la mola.";
				$this->l_debris_removenova = "En acostar a les restes arriba un missatge sobre les comunicacions dient que les armes assassines planeta no estan permesos en aquesta �rea de l&#39;espai. La seva Nova Bomb immediatament es torna inutilitzable per cap ra� aparent.";
				$this->l_debris_nothing = "Els seus enginyers han determinat que �s deixalles espacials in�til.";
			break;

			case "danish":
				$this->l_debris_addnova = "Du har fundet den flydende vraget af et stort Starship og finde en brugbar Nova Bomb inde Skroget.";
				$this->l_debris_removenova = "N�r du n�rmer dig efterladenskaberne en besked kommer over de meddelelser, der siger, at planeten killer v�ben ikke er tilladt i dette omr�de af rummet. Din Nova Bomb straks bliver ubrugelig uden synlig grund.";
				$this->l_debris_nothing = "Deres ingeni�rer har bestemt det er nyttel�st space junk.";
			break;

			case "dutch":
				$this->l_debris_addnova = "U hebt het drijvende wrak gevonden van een grote sterrenschip en zoek een bruikbare Nova Bomb binnen de hulk.";
				$this->l_debris_removenova = "Als je de aanpak van de brokstukken een bericht komt over de communicatie te zeggen dat planeet moordenaar wapens zijn niet toegestaan in dit gebied van de ruimte. Uw Nova Bomb wordt onmiddellijk onbruikbaar zonder duidelijke reden.";
				$this->l_debris_nothing = "Uw ingenieurs hebben vastgesteld dat het zinloos is ruimte junk.";
			break;

			case "finnish":
				$this->l_debris_addnova = "Olet l�yt�nyt kelluva raunioista suuri Starship ja etsi� k�ytt�kelpoinen Nova Bomb sis�ll� Hulk.";
				$this->l_debris_removenova = "Kun l�hestyt roskat viesti tulee yli viestinn�n sanoa, ett� planeetan tappaja aseet eiv�t ole sallittuja t�ll� alueella tilaa. Sinun Nova Bomb heti tulee k�ytt�kelvottomia ilman selv�� syyt�.";
				$this->l_debris_nothing = "Sinun insin��rit ovat p��tt�neet, ett� on hy�dyt�nt� tilaa roskaa.";
			break;

			case "indonesian":
				$this->l_debris_addnova = "Anda telah menemukan puing-puing yang mengambang kapal luar angkasa yang besar dan lokasi yang dapat digunakan di dalam Bomb Nova Hulk.";
				$this->l_debris_removenova = "Saat Anda mendekati puing-puing sebuah pesan datang melalui komunikasi mengatakan bahwa senjata pembunuh planet tidak diperbolehkan dalam ruang wilayah ini. Bom Nova Anda segera menjadi tidak dapat digunakan tanpa alasan yang jelas.";
				$this->l_debris_nothing = "Insinyur Anda telah menentukan ruang percuma sampah.";
			break;

			case "norwegian":
				$this->l_debris_addnova = "Du har funnet flytende vraket av et stort starship og finne en brukbar Nova Bomb inni hulk.";
				$this->l_debris_removenova = "N�r du n�rmer vrakrestene en melding kommer over kommunikasjon og sa at planeten killer v�pen er ikke tillatt i dette omr�det av plass. Din Nova Bomb umiddelbart blir ubrukelig uten noen �penbar grunn.";
				$this->l_debris_nothing = "Din ingeni�rer har bestemt det er ubrukelig plass useri�s.";
			break;

			case "portuguese":
				$this->l_debris_addnova = "Voc� encontrou os destro�os de uma nave flutuante grande e localizar um utiliz�veis Nova bomba dentro do casco.";
				$this->l_debris_removenova = "Como voc� se aproximar dos escombros uma mensagem vem sobre as comunica��es dizendo que as armas assassino planeta n�o s�o permitidos nessa �rea do espa�o. Seu Nova Bomb imediatamente se torna in�til, sem raz�o aparente.";
				$this->l_debris_nothing = "Seu engenheiros determinaram que � lixo espacial in�til.";
			break;

			case "swedish":
				$this->l_debris_addnova = "Du har hittat flytande vrak av en stor rymdskeppet och hitta en anv�ndbar Nova Bomb inuti Hulk.";
				$this->l_debris_removenova = "N�r du n�rmar dig skr�pet ett meddelande kommer �ver de meddelanden som s�ger att planet d�dliga vapen �r inte till�tna i detta omr�de av rymden. Din Nova Bomb omedelbart blir obrukbart utan synbar anledning.";
				$this->l_debris_nothing = "Din ingenj�rer har fastst�llt att det �r on�digt utrymme skr�p.";
			break;

			default:
				$this->l_debris_addnova = "You have found the floating wreckage of a large starship and locate a usable Nova Bomb inside the hulk.";
				$this->l_debris_removenova = "As you approach the debris a message comes over the communications saying that planet killer weapons are not allowed in this area of space.  Your Nova Bomb immediately becomes unusable for no apparent reason.";
				$this->l_debris_nothing = "Your engineers have determined it is useless space junk.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo, $shipdevice, $dev_nova_shiplimit;

		if($row['debris_data'] == 1)
		{
			if($shipdevice['dev_nova']['amount'] == "0" && $dev_nova_shiplimit <= $shipinfo['class']){
				$debrismessage = $this->l_debris_addnova;
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=10 WHERE device_id=" . $shipdevice['dev_nova']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
			}else{
				$debrismessage = $this->l_debris_nothing;
			}
		}else{
			if($shipdevice['dev_nova']['amount'] != "0"){
				$debrismessage = $this->l_debris_removenova;
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=0 WHERE device_id=" . $shipdevice['dev_nova']['device_id']);
				db_op_result($debug_query,__LINE__,__FILE__);
			}else{
				$debrismessage = $this->l_debris_nothing;
			}
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$debris_data = (mt_rand(0, 1) == 1) ? -1 : 1;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$debris_data = (mt_rand(0, 1) == 1) ? -1 : 1;
		return $debris_data;
	}
}

?>