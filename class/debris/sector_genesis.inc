<?php
class sector_genesis {
	var $classname = "sector_genesis";
	var $success = "500";	// Random value range
	var $trigger = "250";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addsg;
	var $l_debris_removesg;
	var $l_debris_nothing;

	// fill language variables
	function sector_genesis()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addsg = "Kuigi kergelt kahjustatud olete leidnud kasutatavad Sector Genesis seade.";
				$this->l_debris_removesg = "Elektromagnetilise impulsi äkki puhkeb alates praht hävitada ühe oma Sector Genesis Devices.";
				$this->l_debris_nothing = "Teie insenerid on otsustanud, on mõttetu space junk.";
			break;

			case "french":
				$this->l_debris_addsg = "Vous avez trouvé une torpille genesis fonctionnelle, bien que légèrement endommagée.";
				$this->l_debris_removesg = "Des impulsions électromagnétiques sont soudainement émises par les débris. Une de vos torpilles genesis est détruite.";
				$this->l_debris_nothing = "Vos ingénieurs décident qu'il s'agit de simples détritus.";
			break;

			case "german":
				$this->l_debris_addsg = "Obwohl sichtbar beschädigt haben Sie ein brauchbares Sektor-Genesis-Gerät gefunden.";
				$this->l_debris_removesg = "Ein elektormagnetsicher Puls vom Fund hat plötzlich eine Ihrer Sektor-Genesis-Geräte vernichtet.";
				$this->l_debris_nothing = "Ihre Ingenieure haben herausgefunden, dass es nur nutzloser Weltraumschrott ist.";
			break;

			case "italian":
				$this->l_debris_addsg = "Anche se leggermente danneggiato, hai trovato un Dispositivo Genesis di Settori utilizzabile.";
				$this->l_debris_removesg = "Un Impulso elettromagnetico erutta improvvisamente dai rottami, distruggendo uno dei tuoi Dispositivi Genesis di Settori.";
				$this->l_debris_nothing = "I tuoi ingenieri hanno analizzato il rottame e non hanno trovato altro che inutilizzabili rifiuti spaziali.";
			break;

			case "spanish":
				$this->l_debris_addsg = "Aunque ligeramente dañado que ha encontrado un dispositivo utilizable Sector Génesis.";
				$this->l_debris_removesg = "Un pulso electromagnético de repente entra en erupción de los restos de la destrucción de uno de sus dispositivos Sector Génesis.";
				$this->l_debris_nothing = "Sus ingenieros han determinado que es basura espacial inútil.";
			break;

			case "albanian":
				$this->l_debris_addsg = "Megjithëse dëmtuar pak keni gjetur një përdorshme Pajisja Sektori Zanafilla.";
				$this->l_debris_removesg = "Një Pulse elektromagnetike papritmas shpërthen nga mbeturinat shkatërruar një i Pajisjeve Sektorit tuaj Zanafilla.";
				$this->l_debris_nothing = "Inxhinierë juaj kanë përcaktuar se është e padobishme junk hapësirë.";
			break;

			case "catalan":
				$this->l_debris_addsg = "Encara que lleugerament danyat que ha trobat un dispositiu utilitzable Sector Gènesi.";
				$this->l_debris_removesg = "Un pols electromagnètic de sobte entra en erupció de les restes de la destrucció d&#39;un dels seus dispositius Sector Gènesi.";
				$this->l_debris_nothing = "Els seus enginyers han determinat que és deixalles espacials inútil.";
			break;

			case "danish":
				$this->l_debris_addsg = "Selv lettere beskadiget du har fundet en brugbar Sector Genesis Enhed.";
				$this->l_debris_removesg = "En elektromagnetisk Pulse pludselig bryder ud fra resterne ødelægge en af dine Sektor Genesis Devices.";
				$this->l_debris_nothing = "Deres ingeniører har bestemt det er nytteløst space junk.";
			break;

			case "dutch":
				$this->l_debris_addsg = "Hoewel licht beschadigd heb je een bruikbare Sector Genesis apparaat gevonden.";
				$this->l_debris_removesg = "Een Electromagnetic Pulse barst plotseling uit het puin vernietigen van een van uw sector Genesis Devices.";
				$this->l_debris_nothing = "Uw ingenieurs hebben vastgesteld dat het zinloos is ruimte junk.";
			break;

			case "finnish":
				$this->l_debris_addsg = "Vaikka hieman vahingoittunut olet löytänyt käyttökelpoista Ala Genesis laite.";
				$this->l_debris_removesg = "Sähkömagneettinen pulssi yhtäkkiä puhkeaa alkaen roskat tuhota joku Ala Genesis laitteet.";
				$this->l_debris_nothing = "Sinun insinöörit ovat päättäneet, että on hyödytöntä tilaa roskaa.";
			break;

			case "indonesian":
				$this->l_debris_addsg = "Meskipun sedikit rusak Anda telah menemukan Sektor yang dapat digunakan Kejadian Device.";
				$this->l_debris_removesg = "Sebuah Pulse elektromagnetik tiba-tiba meletus dari puing-puing menghancurkan salah satu Kejadian Sektor Devices.";
				$this->l_debris_nothing = "Insinyur Anda telah menentukan ruang percuma sampah.";
			break;

			case "norwegian":
				$this->l_debris_addsg = "Selv om noe er skadet du har funnet en brukbar Sector Genesis enhet.";
				$this->l_debris_removesg = "En elektromagnetisk puls utbrot plutselig fra vrakrestene ødelagt en av dine sektor Genesis Devices.";
				$this->l_debris_nothing = "Din ingeniører har bestemt det er ubrukelig plass useriøs.";
			break;

			case "portuguese":
				$this->l_debris_addsg = "Embora ligeiramente danificada que você tenha encontrado um dispositivo utilizável Setor Gênesis.";
				$this->l_debris_removesg = "Um pulso eletromagnético, de repente entra em erupção dos escombros destruir um de seus Setor Genesis Devices.";
				$this->l_debris_nothing = "Seu engenheiros determinaram que é lixo espacial inútil.";
			break;

			case "swedish":
				$this->l_debris_addsg = "Även lätt skadade du har hittat en användbar Sector Genesis Device.";
				$this->l_debris_removesg = "En elektromagnetisk puls bryter plötsligt fram ur ruinerna förstöra en av dina Sector Genesis Devices.";
				$this->l_debris_nothing = "Din ingenjörer har fastställt att det är onödigt utrymme skräp.";
			break;

			default:
				$this->l_debris_addsg = "Though slightly damaged you have found a usable Sector Genesis Device.";
				$this->l_debris_removesg = "An Electromagnetic Pulse suddenly erupts from the debris destroying one of your Sector Genesis Devices.";
				$this->l_debris_nothing = "Your engineers have determined it is useless space junk.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo, $shipdevice;

		if($row['debris_data'] == 1)
		{
			$debrismessage = $this->l_debris_addsg;
			$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+1 WHERE device_id=" . $shipdevice['dev_sectorgenesis']['device_id']);
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			if($shipdevice['dev_sectorgenesis']['amount'] == 0){
				if(($shipdevice['dev_sectorgenesis']['amount'] - 1) < 0){
					$amount = $shipdevice['dev_sectorgenesis']['amount'];
				}
				$debrismessage = $this->l_debris_removesg;
				$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=GREATEST(amount-1, 0) WHERE device_id=" . $shipdevice['dev_sectorgenesis']['device_id']);
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