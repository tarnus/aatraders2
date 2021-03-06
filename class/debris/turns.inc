<?php
class turns {
	var $classname = "turns";
	var $success = "80";	// Random value range
	var $trigger = "40";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $maximum_amount = "450";	// Set to maximum amount that can be stored in a debris item
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addturns;
	var $l_debris_removeturns;

	// fill language variables
	function turns()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addturns = "Olete leidnud ekstra korduva moodulit, mis teile [amount] p��rete liikumine.";
				$this->l_debris_removeturns = "Prahti oli boobytrapped ja p�hjustas ulatusliku elektriseadmete kahju, mis on [amount] kordam��da parandada.";
			break;

			case "french":
				$this->l_debris_addturns = "Vous trouvez des modules acc�l�rateurs qui vous donnent [amount] tours de plus.";
				$this->l_debris_removeturns = "Les d�bris �taient pi�g�s! Votre vaisseau subit d'importants dommages �lectriques qui prennent [amount] tours avant d'�tre r�par�s.";
			break;

			case "german":
				$this->l_debris_addturns = "Sie haben eine Extre-Boost-Modul gefunden, dass Ihnen [amount] Turns einbringt.";
				$this->l_debris_removeturns = "Der Schutt wurde anf�ngerhaft eingefangen und hat massiven Schaden in der Elektrik hervorgerufen, der Sie [amount] Turns f�r die Reparatur kostet.";
			break;

			case "italian":
				$this->l_debris_addturns = "Hai individuato un modulo extra di alimentazione che ti permette [amount] turni aggiuntivi.";
				$this->l_debris_removeturns = "I rottami erano in effetti una trappola che causa un guasto elettrico generale. PEr ripararlo impieghi [amount] turni.";
			break;

			case "spanish":
				$this->l_debris_addturns = "Se han encontrado m�dulos de refuerzo extra que le dan [amount] se convierte de movimiento.";
				$this->l_debris_removeturns = "Los escombros se boobytrapped y caus� da�os el�ctricos masiva que lleva a [amount] se convierte en la reparaci�n.";
			break;

			case "albanian":
				$this->l_debris_addturns = "Ju keni gjetur modulet shtes� p�rforcues q� t� ju jap [amount] kthehet e l�vizjes.";
				$this->l_debris_removeturns = "Mbeturinat u boobytrapped dhe shkaktoi d�me masive elektrike q� merr [amount] kthehet p�r t� riparuar.";
			break;

			case "catalan":
				$this->l_debris_addturns = "S&#39;han trobat m�duls de refor� extra que li donen [amount] canvia de moviment.";
				$this->l_debris_removeturns = "La runa es boobytrapped i va causar danys el�ctrics massiva que porta a [amount] es converteix en la reparaci�.";
			break;

			case "danish":
				$this->l_debris_addturns = "Du har fundet ekstra booster-moduler, der giver dig [amount] vender bev�gelighed.";
				$this->l_debris_removeturns = "Resterne blev boobytrapped og for�rsagede massive elektriske skader, der tager [amount] vender sig at reparere.";
			break;

			case "dutch":
				$this->l_debris_addturns = "U hebt extra booster modules waarmee u [amount] gevonden bochten van beweging.";
				$this->l_debris_removeturns = "Het puin werd boobytrapped en veroorzaakte enorme schade die elektrische neemt [amount] blijkt te repareren.";
			break;

			case "finnish":
				$this->l_debris_addturns = "Olet l�yt�nyt ylim��r�isi� Booster moduulit, jotka antavat sinulle [amount] kierrosta liikkuvuutta.";
				$this->l_debris_removeturns = "Roskat oli boobytrapped ja aiheutti valtavia s�hk� vahinkoa, joka vie [amount] muuttuu korjata.";
			break;

			case "indonesian":
				$this->l_debris_addturns = "Anda telah menemukan penguat tambahan modul yang memberikan Anda [amount] mengubah gerakan.";
				$this->l_debris_removeturns = "Puing-puing itu boobytrapped listrik besar-besaran dan menyebabkan kerusakan yang mengambil [amount] berubah untuk memperbaiki.";
			break;

			case "norwegian":
				$this->l_debris_addturns = "Du har funnet ekstra booster moduler som gir deg [amount] svinger av bevegelse.";
				$this->l_debris_removeturns = "Vrakgodset var boobytrapped og for�rsaket enorme elektriske skader som f�rer [amount] snur � reparere.";
			break;

			case "portuguese":
				$this->l_debris_addturns = "Voc� encontrou m�dulos de refor�o extra que lhe d� [amount] voltas do movimento.";
				$this->l_debris_removeturns = "Os restos foram boobytrapped e causou danos el�tricos em massa que leva [amount] de volta para reparos.";
			break;

			case "swedish":
				$this->l_debris_addturns = "Du har hittat extra booster moduler som ger dig [amount] v�nder r�rlighet.";
				$this->l_debris_removeturns = "Skr�pet var boobytrapped och orsakade massiva elektriska skador som tar [amount] visar att reparera.";
			break;

			default:
				$this->l_debris_addturns = "You have found extra booster modules that give you [amount] turns of movement.";
				$this->l_debris_removeturns = "The debris was boobytrapped and caused massive electrical damage that takes [amount] turns to repair.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $playerinfo;

		if($row['debris_data'] > 1)
		{
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addturns);
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns+$row[debris_data] WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			if(($playerinfo['turns'] + $row['debris_data']) < 0){
				$row['debris_data'] = 1 - $playerinfo['turns'];
			}
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_removeturns);
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=turns+$row[debris_data] WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$amount = mt_rand(1, $this->maximum_amount);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$amount = mt_rand(1, $this->maximum_amount);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}
}

?>