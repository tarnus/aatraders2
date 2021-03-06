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
				$this->l_debris_removesg = "Elektromagnetilise impulsi �kki puhkeb alates praht h�vitada �he oma Sector Genesis Devices.";
				$this->l_debris_nothing = "Teie insenerid on otsustanud, on m�ttetu space junk.";
			break;

			case "french":
				$this->l_debris_addsg = "Vous avez trouv� une torpille genesis fonctionnelle, bien que l�g�rement endommag�e.";
				$this->l_debris_removesg = "Des impulsions �lectromagn�tiques sont soudainement �mises par les d�bris. Une de vos torpilles genesis est d�truite.";
				$this->l_debris_nothing = "Vos ing�nieurs d�cident qu'il s'agit de simples d�tritus.";
			break;

			case "german":
				$this->l_debris_addsg = "Obwohl sichtbar besch�digt haben Sie ein brauchbares Sektor-Genesis-Ger�t gefunden.";
				$this->l_debris_removesg = "Ein elektormagnetsicher Puls vom Fund hat pl�tzlich eine Ihrer Sektor-Genesis-Ger�te vernichtet.";
				$this->l_debris_nothing = "Ihre Ingenieure haben herausgefunden, dass es nur nutzloser Weltraumschrott ist.";
			break;

			case "italian":
				$this->l_debris_addsg = "Anche se leggermente danneggiato, hai trovato un Dispositivo Genesis di Settori utilizzabile.";
				$this->l_debris_removesg = "Un Impulso elettromagnetico erutta improvvisamente dai rottami, distruggendo uno dei tuoi Dispositivi Genesis di Settori.";
				$this->l_debris_nothing = "I tuoi ingenieri hanno analizzato il rottame e non hanno trovato altro che inutilizzabili rifiuti spaziali.";
			break;

			case "spanish":
				$this->l_debris_addsg = "Aunque ligeramente da�ado que ha encontrado un dispositivo utilizable Sector G�nesis.";
				$this->l_debris_removesg = "Un pulso electromagn�tico de repente entra en erupci�n de los restos de la destrucci�n de uno de sus dispositivos Sector G�nesis.";
				$this->l_debris_nothing = "Sus ingenieros han determinado que es basura espacial in�til.";
			break;

			case "albanian":
				$this->l_debris_addsg = "Megjith�se d�mtuar pak keni gjetur nj� p�rdorshme Pajisja Sektori Zanafilla.";
				$this->l_debris_removesg = "Nj� Pulse elektromagnetike papritmas shp�rthen nga mbeturinat shkat�rruar nj� i Pajisjeve Sektorit tuaj Zanafilla.";
				$this->l_debris_nothing = "Inxhinier� juaj kan� p�rcaktuar se �sht� e padobishme junk hap�sir�.";
			break;

			case "catalan":
				$this->l_debris_addsg = "Encara que lleugerament danyat que ha trobat un dispositiu utilitzable Sector G�nesi.";
				$this->l_debris_removesg = "Un pols electromagn�tic de sobte entra en erupci� de les restes de la destrucci� d&#39;un dels seus dispositius Sector G�nesi.";
				$this->l_debris_nothing = "Els seus enginyers han determinat que �s deixalles espacials in�til.";
			break;

			case "danish":
				$this->l_debris_addsg = "Selv lettere beskadiget du har fundet en brugbar Sector Genesis Enhed.";
				$this->l_debris_removesg = "En elektromagnetisk Pulse pludselig bryder ud fra resterne �del�gge en af dine Sektor Genesis Devices.";
				$this->l_debris_nothing = "Deres ingeni�rer har bestemt det er nyttel�st space junk.";
			break;

			case "dutch":
				$this->l_debris_addsg = "Hoewel licht beschadigd heb je een bruikbare Sector Genesis apparaat gevonden.";
				$this->l_debris_removesg = "Een Electromagnetic Pulse barst plotseling uit het puin vernietigen van een van uw sector Genesis Devices.";
				$this->l_debris_nothing = "Uw ingenieurs hebben vastgesteld dat het zinloos is ruimte junk.";
			break;

			case "finnish":
				$this->l_debris_addsg = "Vaikka hieman vahingoittunut olet l�yt�nyt k�ytt�kelpoista Ala Genesis laite.";
				$this->l_debris_removesg = "S�hk�magneettinen pulssi yht�kki� puhkeaa alkaen roskat tuhota joku Ala Genesis laitteet.";
				$this->l_debris_nothing = "Sinun insin��rit ovat p��tt�neet, ett� on hy�dyt�nt� tilaa roskaa.";
			break;

			case "indonesian":
				$this->l_debris_addsg = "Meskipun sedikit rusak Anda telah menemukan Sektor yang dapat digunakan Kejadian Device.";
				$this->l_debris_removesg = "Sebuah Pulse elektromagnetik tiba-tiba meletus dari puing-puing menghancurkan salah satu Kejadian Sektor Devices.";
				$this->l_debris_nothing = "Insinyur Anda telah menentukan ruang percuma sampah.";
			break;

			case "norwegian":
				$this->l_debris_addsg = "Selv om noe er skadet du har funnet en brukbar Sector Genesis enhet.";
				$this->l_debris_removesg = "En elektromagnetisk puls utbrot plutselig fra vrakrestene �delagt en av dine sektor Genesis Devices.";
				$this->l_debris_nothing = "Din ingeni�rer har bestemt det er ubrukelig plass useri�s.";
			break;

			case "portuguese":
				$this->l_debris_addsg = "Embora ligeiramente danificada que voc� tenha encontrado um dispositivo utiliz�vel Setor G�nesis.";
				$this->l_debris_removesg = "Um pulso eletromagn�tico, de repente entra em erup��o dos escombros destruir um de seus Setor Genesis Devices.";
				$this->l_debris_nothing = "Seu engenheiros determinaram que � lixo espacial in�til.";
			break;

			case "swedish":
				$this->l_debris_addsg = "�ven l�tt skadade du har hittat en anv�ndbar Sector Genesis Device.";
				$this->l_debris_removesg = "En elektromagnetisk puls bryter pl�tsligt fram ur ruinerna f�rst�ra en av dina Sector Genesis Devices.";
				$this->l_debris_nothing = "Din ingenj�rer har fastst�llt att det �r on�digt utrymme skr�p.";
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