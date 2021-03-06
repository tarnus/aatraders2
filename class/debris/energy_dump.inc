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
				$this->l_debris_addenergy = "Sa ei leitud kantavate energiat sisaldab, et saab anda oma laeva korraga t�sta on [amount] �hikut energiat.";
				$this->l_debris_removeenergy = "Olete toonud abord energia valamu et k�ivitada nii kiiresti kui kunstlikku raskust oli lubatud ja see k�rvaldada, [amount] �hikut energiat.";
			break;

			case "french":
				$this->l_debris_addenergy = "Vous avez trouv� des contenants d'�nergie portatifs. Ils peuvent vous assurer une seule acc�l�ration temporaire de [amount] points d'�nergie.";
				$this->l_debris_removeenergy = "Vous avez malencontreusement ramen� un dissipateur d'�nergie qui s'est activ� d�s qu'il a d�tect� la gravit� artificielle. Vous avez perdu [amount] points d'�nergie.";
			break;

			case "german":
				$this->l_debris_addenergy = "Sie haben tragbare Energie gefunden. Ihr Fund bringt Ihnen einen einmaligen Energieschub von [amount].";
				$this->l_debris_removeenergy = "Sie haben eine Energie-Quelle an Bord gebracht, die Ihnen, als Sie das k�nstliche Schwerkraftfeld aktivierten [amount] Einheiten Energie abgezogen hat.";
			break;

			case "italian":
				$this->l_debris_addenergy = "Hai scoperto un modulo portatile di immagazzinamento dell'energia, che ti fornisce una carica aggiuntiva di [amount] unit� di energia, utilizzabile una volta sola.";
				$this->l_debris_removeenergy = "Hai portato a bordo un condotto d'energia che si � attivato appena subiti gli effetti della gravit� artificiale, sottraendo [amount] unit� di energia.";
			break;

			case "spanish":
				$this->l_debris_addenergy = "Se han encontrado de energ�a port�til que contiene puede dar un impulso a su barco una vez de [amount] unidades de energ�a.";
				$this->l_debris_removeenergy = "Usted ha tra�do abord un receptor de energ�a que provoc� tan pronto como la gravedad artificial fue habilitado y que se elimine [amount] unidades de energ�a.";
			break;

			case "albanian":
				$this->l_debris_addenergy = "Ju keni gjetur energji p�rmban portativ q� mund t� jap� nj� shtys� anije tuaj nj� koh� prej [amount] nj�sive t� energjis�.";
				$this->l_debris_removeenergy = "Ju keni sjell� abord nj� lavaman energjis� q� shkaktoi sa m� shpejt t� jet� gravitetit artificiale u mund�sua dhe ajo hiqet [amount] nj�sive t� energjis�.";
			break;

			case "catalan":
				$this->l_debris_addenergy = "S&#39;han trobat d&#39;energia port�til que cont� pot donar un impuls al seu vaixell un cop de [amount] unitats d&#39;energia.";
				$this->l_debris_removeenergy = "Vost� ha portat abord un receptor d&#39;energia que va provocar tan aviat com la gravetat artificial va ser habilitat i l&#39;eliminaci� [amount] unitats d&#39;energia.";
			break;

			case "danish":
				$this->l_debris_addenergy = "Du har fundet b�rbare energi rummer, som kan give dit skib �n gang skub i [amount] enheder af energi.";
				$this->l_debris_removeenergy = "Du har bragt abord en energi synke, der udl�ses, s� snart den kunstige tyngdekraft var aktiveret, og det fjernet [amount] enheder af energi.";
			break;

			case "dutch":
				$this->l_debris_addenergy = "U hebt gevonden draagbare energie bevat die uw schip geven een eenmalige impuls van [amount] eenheden van energie.";
				$this->l_debris_removeenergy = "Je hebt gebracht abord een energie zinken dat leverde zodra de kunstmatige zwaartekracht werd ingeschakeld en het verwijderd [amount] eenheden van energie.";
			break;

			case "finnish":
				$this->l_debris_addenergy = "Olet l�yt�nyt kannettavat energiaa on, ett� voit antaa aluksen kerran piristett� [amount] yksikk�� energiaa.";
				$this->l_debris_removeenergy = "Olette tuonut abord energiaa uppoaa joka k�ynnistyy heti keinotekoinen painovoima on k�yt�ss� ja se poistetaan [amount] yksikk�� energiaa.";
			break;

			case "indonesian":
				$this->l_debris_addenergy = "Anda telah menemukan mengandung energi portabel yang dapat memberikan anda satu kali kapal dorongan dari [amount] unit energi.";
				$this->l_debris_removeenergy = "Anda telah membawa energi abord tenggelam yang dipicu segera setelah gravitasi buatan ini diaktifkan dan menghapusnya [amount] unit energi.";
			break;

			case "norwegian":
				$this->l_debris_addenergy = "Du har funnet b�rbar inneholder energi som kan gi skipet en gang l�ft av [amount] enheter av energi.";
				$this->l_debris_removeenergy = "Du har brakt abord en energi synke som utl�ste straks kunstig gravitasjon var aktivert, og den fjernet [amount] enheter av energi.";
			break;

			case "portuguese":
				$this->l_debris_addenergy = "Voc� encontrou cont�m energia port�til que pode dar um impulso a sua nave um tempo de [amount] unidades de energia.";
				$this->l_debris_removeenergy = "Voc� trouxe abord um dissipador de energia que provocou logo a gravidade artificial foi habilitada e retir�-lo [amount] de unidades de energia.";
			break;

			case "swedish":
				$this->l_debris_addenergy = "Du har hittat b�rbara inneh�ller energi som kan ge ditt skepp en g�ng ett uppsving p� [amount] enheter av energi.";
				$this->l_debris_removeenergy = "Du har v�ckt abord en energi sjunker som utl�ses s� snart de konstgjorda allvar var aktiverat och det tas bort [amount] enheter av energi.";
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