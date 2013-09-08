<?php
class energy_dump {
	var $classname = "energy_dump";
	var $success = "200";	// Random value range
	var $trigger = "100";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "1";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addenergy;
	var $l_debris_removeenergy;

	// fill language variables
	function energy_dump()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addenergy = "Sa ei leitud kantavate energiat sisaldab, et saab anda oma laeva korraga tõsta on [amount] ühikut energiat.";
				$this->l_debris_removeenergy = "Olete toonud abord energia valamu et käivitada nii kiiresti kui kunstlikku raskust oli lubatud ja see kõrvaldada, [amount] ühikut energiat.";
			break;

			case "french":
				$this->l_debris_addenergy = "Vous avez trouvé des contenants d'énergie portatifs. Ils peuvent vous assurer une seule accélération temporaire de [amount] points d'énergie.";
				$this->l_debris_removeenergy = "Vous avez malencontreusement ramené un dissipateur d'énergie qui s'est activé dès qu'il a détecté la gravité artificielle. Vous avez perdu [amount] points d'énergie.";
			break;

			case "german":
				$this->l_debris_addenergy = "Sie haben tragbare Energie gefunden. Ihr Fund bringt Ihnen einen einmaligen Energieschub von [amount].";
				$this->l_debris_removeenergy = "Sie haben eine Energie-Quelle an Bord gebracht, die Ihnen, als Sie das künstliche Schwerkraftfeld aktivierten [amount] Einheiten Energie abgezogen hat.";
			break;

			case "italian":
				$this->l_debris_addenergy = "Hai scoperto un modulo portatile di immagazzinamento dell'energia, che ti fornisce una carica aggiuntiva di [amount] unità di energia, utilizzabile una volta sola.";
				$this->l_debris_removeenergy = "Hai portato a bordo un condotto d'energia che si è attivato appena subiti gli effetti della gravità artificiale, sottraendo [amount] unità di energia.";
			break;

			case "spanish":
				$this->l_debris_addenergy = "Se han encontrado de energía portátil que contiene puede dar un impulso a su barco una vez de [amount] unidades de energía.";
				$this->l_debris_removeenergy = "Usted ha traído abord un receptor de energía que provocó tan pronto como la gravedad artificial fue habilitado y que se elimine [amount] unidades de energía.";
			break;

			case "albanian":
				$this->l_debris_addenergy = "Ju keni gjetur energji përmban portativ që mund të japë një shtysë anije tuaj një kohë prej [amount] njësive të energjisë.";
				$this->l_debris_removeenergy = "Ju keni sjellë abord një lavaman energjisë që shkaktoi sa më shpejt të jetë gravitetit artificiale u mundësua dhe ajo hiqet [amount] njësive të energjisë.";
			break;

			case "catalan":
				$this->l_debris_addenergy = "S&#39;han trobat d&#39;energia portàtil que conté pot donar un impuls al seu vaixell un cop de [amount] unitats d&#39;energia.";
				$this->l_debris_removeenergy = "Vostè ha portat abord un receptor d&#39;energia que va provocar tan aviat com la gravetat artificial va ser habilitat i l&#39;eliminació [amount] unitats d&#39;energia.";
			break;

			case "danish":
				$this->l_debris_addenergy = "Du har fundet bærbare energi rummer, som kan give dit skib én gang skub i [amount] enheder af energi.";
				$this->l_debris_removeenergy = "Du har bragt abord en energi synke, der udløses, så snart den kunstige tyngdekraft var aktiveret, og det fjernet [amount] enheder af energi.";
			break;

			case "dutch":
				$this->l_debris_addenergy = "U hebt gevonden draagbare energie bevat die uw schip geven een eenmalige impuls van [amount] eenheden van energie.";
				$this->l_debris_removeenergy = "Je hebt gebracht abord een energie zinken dat leverde zodra de kunstmatige zwaartekracht werd ingeschakeld en het verwijderd [amount] eenheden van energie.";
			break;

			case "finnish":
				$this->l_debris_addenergy = "Olet löytänyt kannettavat energiaa on, että voit antaa aluksen kerran piristettä [amount] yksikköä energiaa.";
				$this->l_debris_removeenergy = "Olette tuonut abord energiaa uppoaa joka käynnistyy heti keinotekoinen painovoima on käytössä ja se poistetaan [amount] yksikköä energiaa.";
			break;

			case "indonesian":
				$this->l_debris_addenergy = "Anda telah menemukan mengandung energi portabel yang dapat memberikan anda satu kali kapal dorongan dari [amount] unit energi.";
				$this->l_debris_removeenergy = "Anda telah membawa energi abord tenggelam yang dipicu segera setelah gravitasi buatan ini diaktifkan dan menghapusnya [amount] unit energi.";
			break;

			case "norwegian":
				$this->l_debris_addenergy = "Du har funnet bærbar inneholder energi som kan gi skipet en gang løft av [amount] enheter av energi.";
				$this->l_debris_removeenergy = "Du har brakt abord en energi synke som utløste straks kunstig gravitasjon var aktivert, og den fjernet [amount] enheter av energi.";
			break;

			case "portuguese":
				$this->l_debris_addenergy = "Você encontrou contém energia portátil que pode dar um impulso a sua nave um tempo de [amount] unidades de energia.";
				$this->l_debris_removeenergy = "Você trouxe abord um dissipador de energia que provocou logo a gravidade artificial foi habilitada e retirá-lo [amount] de unidades de energia.";
			break;

			case "swedish":
				$this->l_debris_addenergy = "Du har hittat bärbara innehåller energi som kan ge ditt skepp en gång ett uppsving på [amount] enheter av energi.";
				$this->l_debris_removeenergy = "Du har väckt abord en energi sjunker som utlöses så snart de konstgjorda allvar var aktiverat och det tas bort [amount] enheter av energi.";
			break;

			default:
				$this->l_debris_addenergy = "You have found portable energy contains that can give your ship a one time boost of [amount] units of energy.";
				$this->l_debris_removeenergy = "You have brought abord an energy sink that triggered as soon as the artificial gravity was enabled and it removed [amount] units of energy.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo;

		if($row['debris_data'] > 1)
		{
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addenergy);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET energy=energy+$row[debris_data] WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			if(($shipinfo['energy'] + $row['debris_data']) <= 0){
				$row['debris_data'] = 1 - $shipinfo['energy'];
			}
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_removeenergy);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET energy=GREATEST(energy+$row[debris_data], 0) WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$amount = mt_rand(50, 50 + $destroyed_ship_info['energy']);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$amount = mt_rand(50, 50 + NUM_ENERGY($max_list['power_max']));
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}
}

?>