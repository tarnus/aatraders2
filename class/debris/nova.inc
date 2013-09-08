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
				$this->l_debris_removenova = "Nagu te lähenemine praht sõnum jõuab üle side, öeldes, et planeedi tapja relvad ei tohi selles valdkonnas ruumi. Teie Nova Bomb kohe muutub kasutamiskõlbmatuks ilma nähtava põhjuseta.";
				$this->l_debris_nothing = "Teie insenerid on otsustanud, on mõttetu space junk.";
			break;

			case "french":
				$this->l_debris_addnova = "Vous avez trouvé la carcasse d'un grand vaisseau à la dérive. Vous en ramenez une bombe Nova toujours utilisable.";
				$this->l_debris_removenova = "En approchant des débris, un message vous parvient indiquant que les armes antiplanètes sont illégales dans cette région de l'espace. Votre bombe Nova devient soudainement inutilisable!";
				$this->l_debris_nothing = "Vos ingénieurs décident qu'il s'agit de simples détritus.";
			break;

			case "german":
				$this->l_debris_addnova = "Sie haben ein schwebendes Wrack eines großen Raumschiffs mit einer eingebauten voll funktionsfähigen Nova-Bombe gefunden.";
				$this->l_debris_removenova = "Als Sie sich den Trümmern nähern empfängen Sie eine Nachricht, welche sagt, dass in dieser Gegend keine Planeten zerstörenden Waffen erlaubt sind. Ihre Nova-Bombe wurde sofort unbrauchbar gemacht.";
				$this->l_debris_nothing = "Ihre Ingenieure haben herausgefunden, dass es nur nutzloser Weltraumschrott ist.";
			break;

			case "italian":
				$this->l_debris_addnova = "Una Bomba Nova utilizzabile è stata individuata tra i rottami vaganti di una larga nave spaziale.";
				$this->l_debris_removenova = "Mentre ti avvicini ai rottami, ricevi un messaggio attraverso il sistema di comunicazione della nave che afferma che armi di distruzione planetaria non sono permesse in quest'area  di spazio. La tua Bomba Nova diviene inutilizzabile per nessuna ragione apparente..";
				$this->l_debris_nothing = "I tuoi ingenieri hanno analizzato il rottame e non hanno trovato altro che inutilizzabili rifiuti spaziali.";
			break;

			case "spanish":
				$this->l_debris_addnova = "Se han encontrado los restos flotantes de una nave grande y localizar una bomba utilizable Nova dentro de la mole.";
				$this->l_debris_removenova = "Al acercarse a los restos llega un mensaje sobre las comunicaciones diciendo que las armas asesinas planeta no están permitidos en esta área del espacio. Su Nova Bomb inmediatamente se torna inutilizable por ninguna razón aparente.";
				$this->l_debris_nothing = "Sus ingenieros han determinado que es basura espacial inútil.";
			break;

			case "albanian":
				$this->l_debris_addnova = "Ju keni gjetur rrënojat e një lundrues Starship të mëdha dhe gjeni një përdorshëm Nova bombë brenda kaba.";
				$this->l_debris_removenova = "Si ju qasje mbeturinat një mesazh vjen mbi të komunikimit, duke thënë se armët vrasësin e planetit nuk lejohen në këtë zonë e hapësirë. Bombë Nova juaj menjëherë bëhet e papërdorshme për asnjë arsye të dukshme.";
				$this->l_debris_nothing = "Inxhinierë juaj kanë përcaktuar se është e padobishme junk hapësirë.";
			break;

			case "catalan":
				$this->l_debris_addnova = "S&#39;han trobat les restes flotants d&#39;una nau gran i localitzar una bomba utilitzable Nova dins de la mola.";
				$this->l_debris_removenova = "En acostar a les restes arriba un missatge sobre les comunicacions dient que les armes assassines planeta no estan permesos en aquesta àrea de l&#39;espai. La seva Nova Bomb immediatament es torna inutilitzable per cap raó aparent.";
				$this->l_debris_nothing = "Els seus enginyers han determinat que és deixalles espacials inútil.";
			break;

			case "danish":
				$this->l_debris_addnova = "Du har fundet den flydende vraget af et stort Starship og finde en brugbar Nova Bomb inde Skroget.";
				$this->l_debris_removenova = "Når du nærmer dig efterladenskaberne en besked kommer over de meddelelser, der siger, at planeten killer våben ikke er tilladt i dette område af rummet. Din Nova Bomb straks bliver ubrugelig uden synlig grund.";
				$this->l_debris_nothing = "Deres ingeniører har bestemt det er nytteløst space junk.";
			break;

			case "dutch":
				$this->l_debris_addnova = "U hebt het drijvende wrak gevonden van een grote sterrenschip en zoek een bruikbare Nova Bomb binnen de hulk.";
				$this->l_debris_removenova = "Als je de aanpak van de brokstukken een bericht komt over de communicatie te zeggen dat planeet moordenaar wapens zijn niet toegestaan in dit gebied van de ruimte. Uw Nova Bomb wordt onmiddellijk onbruikbaar zonder duidelijke reden.";
				$this->l_debris_nothing = "Uw ingenieurs hebben vastgesteld dat het zinloos is ruimte junk.";
			break;

			case "finnish":
				$this->l_debris_addnova = "Olet löytänyt kelluva raunioista suuri Starship ja etsiä käyttökelpoinen Nova Bomb sisällä Hulk.";
				$this->l_debris_removenova = "Kun lähestyt roskat viesti tulee yli viestinnän sanoa, että planeetan tappaja aseet eivät ole sallittuja tällä alueella tilaa. Sinun Nova Bomb heti tulee käyttökelvottomia ilman selvää syytä.";
				$this->l_debris_nothing = "Sinun insinöörit ovat päättäneet, että on hyödytöntä tilaa roskaa.";
			break;

			case "indonesian":
				$this->l_debris_addnova = "Anda telah menemukan puing-puing yang mengambang kapal luar angkasa yang besar dan lokasi yang dapat digunakan di dalam Bomb Nova Hulk.";
				$this->l_debris_removenova = "Saat Anda mendekati puing-puing sebuah pesan datang melalui komunikasi mengatakan bahwa senjata pembunuh planet tidak diperbolehkan dalam ruang wilayah ini. Bom Nova Anda segera menjadi tidak dapat digunakan tanpa alasan yang jelas.";
				$this->l_debris_nothing = "Insinyur Anda telah menentukan ruang percuma sampah.";
			break;

			case "norwegian":
				$this->l_debris_addnova = "Du har funnet flytende vraket av et stort starship og finne en brukbar Nova Bomb inni hulk.";
				$this->l_debris_removenova = "Når du nærmer vrakrestene en melding kommer over kommunikasjon og sa at planeten killer våpen er ikke tillatt i dette området av plass. Din Nova Bomb umiddelbart blir ubrukelig uten noen åpenbar grunn.";
				$this->l_debris_nothing = "Din ingeniører har bestemt det er ubrukelig plass useriøs.";
			break;

			case "portuguese":
				$this->l_debris_addnova = "Você encontrou os destroços de uma nave flutuante grande e localizar um utilizáveis Nova bomba dentro do casco.";
				$this->l_debris_removenova = "Como você se aproximar dos escombros uma mensagem vem sobre as comunicações dizendo que as armas assassino planeta não são permitidos nessa área do espaço. Seu Nova Bomb imediatamente se torna inútil, sem razão aparente.";
				$this->l_debris_nothing = "Seu engenheiros determinaram que é lixo espacial inútil.";
			break;

			case "swedish":
				$this->l_debris_addnova = "Du har hittat flytande vrak av en stor rymdskeppet och hitta en användbar Nova Bomb inuti Hulk.";
				$this->l_debris_removenova = "När du närmar dig skräpet ett meddelande kommer över de meddelanden som säger att planet dödliga vapen är inte tillåtna i detta område av rymden. Din Nova Bomb omedelbart blir obrukbart utan synbar anledning.";
				$this->l_debris_nothing = "Din ingenjörer har fastställt att det är onödigt utrymme skräp.";
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