<?php
class level_all {
	var $classname = "level_all";
	var $success = "450";	// Random value range
	var $trigger = "225";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_upgradeall;
	var $l_debris_degradeall;

	// fill language variables
	function level_all()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_upgradeall = "Olete leidnud s�jalise Hinne versiooniuuenduse paketi uuendamine k�ik oma tehnoloogia taset [level].";
				$this->l_debris_degradeall = "Massiline antimatter plahvatus ilmneb siis, kui l�henemine praht ja see kahjustab kogu oma tehnoloogia taset [level].";
			break;

			case "french":
				$this->l_debris_upgradeall = "Vous trouvez un ensemble de mise � jour de qualit� militaire. Il peut ajouter [level] niveaux � toutes vos technologies.";
				$this->l_debris_degradeall = "Une gigantesque explosion d'antimati�re se produit lorsque vous approchez des d�bris. Toute votre technologie est endommag�e et r�duite de [level] niveaux.";
			break;

			case "german":
				$this->l_debris_upgradeall = "Sie haben ein milit�risches Aufr�stpaket gefunden, dass alle Ihre Tech-Levels um [level] erh�ht.";
				$this->l_debris_degradeall = "Eine massive Antimaterie-Explosion w�hrend Sie den Fund bergen. All Ihre Tech-Levels wurden um [level] verbraucht.";
			break;

			case "italian":
				$this->l_debris_upgradeall = "Hai trovato un set di potenziamento militare che potenzia tutti i tuoi sistemi di [level] livelli.";
				$this->l_debris_degradeall = "Una grande esplosione di antimateria mentre ti stai avvicinando ai rottami danneggia tutti i tuoi sistemi di [level] livelli.";
			break;

			case "spanish":
				$this->l_debris_upgradeall = "Usted ha encontrado un paquete de actualizaci�n de grado militar de que las actualizaciones de todos los niveles de tecnolog�a por parte de [level].";
				$this->l_debris_degradeall = "Una explosi�n de antimateria masiva se produce cuando se acerque a los escombros y da�a a todos los niveles de tecnolog�a por parte de [level].";
			break;

			case "albanian":
				$this->l_debris_upgradeall = "Ju keni gjetur nj� ushtarak upgrade paket� klas�n q� p�rmir�simet t� gjitha nivelet tuaj teknologjis� nga [level].";
				$this->l_debris_degradeall = "Nj� shp�rthim masiv antimatter ndodh kur ju qasje mbeturinat dhe d�meve t� gjitha nivelet tuaj teknologjis� nga [level].";
			break;

			case "catalan":
				$this->l_debris_upgradeall = "Vost� ha trobat un paquet d&#39;actualitzaci� de grau militar de les actualitzacions de tots els nivells de tecnologia per part de [level].";
				$this->l_debris_degradeall = "Una explosi� d&#39;antimat�ria massiva es produeix quan s&#39;apropi a la runa i danya a tots els nivells de tecnologia per part de [level].";
			break;

			case "danish":
				$this->l_debris_upgradeall = "Du har fundet en milit�r grad opgradering pakke, opgraderinger alle dine tech-niveauet [level].";
				$this->l_debris_degradeall = "En massiv antistof eksplosion opst�r, n�r du n�rmer dig efterladenskaberne, og det skader alle dine tech-niveauet [level].";
			break;

			case "dutch":
				$this->l_debris_upgradeall = "U hebt gevonden van een militaire rang upgrade pakket dat upgrades van al uw tech niveaus door [level].";
				$this->l_debris_degradeall = "Een enorme antimaterie explosie plaatsvindt wanneer u de aanpak van de brokstukken en het schade al uw tech niveaus door [level].";
			break;

			case "finnish":
				$this->l_debris_upgradeall = "Olet l�yt�nyt sotilaallinen luokan p�ivityksen paketti p�ivitt�� kaikki teid�n teknologian tasosta vuoteen [level].";
				$this->l_debris_degradeall = "Massiivinen Antimatter R�j�hdys tapahtuu, kun l�hestyt roskat ja se vahingoittaa kaikkia teid�n teknologian tasosta vuoteen [level].";
			break;

			case "indonesian":
				$this->l_debris_upgradeall = "Anda telah menemukan sebuah paket upgrade kelas militer bahwa upgrade semua tingkat teknologi oleh [level].";
				$this->l_debris_degradeall = "Antimateri Sebuah ledakan besar terjadi ketika Anda mendekati puing-puing dan kerusakan semua tingkat teknologi oleh [level].";
			break;

			case "norwegian":
				$this->l_debris_upgradeall = "Du har funnet en milit�r karakter oppgradering pakke som oppgraderinger alle tekniske niv�er av [level].";
				$this->l_debris_degradeall = "En massiv antimaterie eksplosjon oppst�r n�r du n�rmer deg rusk og den skader alle tekniske niv�er av [level].";
			break;

			case "portuguese":
				$this->l_debris_upgradeall = "Voc� encontrou um pacote de atualiza��o que atualiza grau militar de todos os seus n�veis de tecnologia por [level].";
				$this->l_debris_degradeall = "Uma explos�o de antimat�ria maci�o ocorre quando se aproximar dos destro�os e danos todos os seus n�veis de tecnologia por [level].";
			break;

			case "swedish":
				$this->l_debris_upgradeall = "Du har hittat en milit�r paket grad uppgradering som uppgraderingar alla dina tekniska niv�er [level].";
				$this->l_debris_degradeall = "En massiv antimateria explosion intr�ffar n�r du n�rmar dig skr�p och det skadar alla dina tekniska niv�er [level].";
			break;

			default:
				$this->l_debris_upgradeall = "You have found a military grade upgrade package that upgrades all of your tech levels by [level].";
				$this->l_debris_degradeall = "A massive antimatter explosion occurs when you approach the debris and it damages all of your tech levels by [level].";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo;

		$amount = 1;
		if($row['debris_data'] == 1)
		{
			$debrismessage = str_replace("[level]", NUMBER($amount), $this->l_debris_upgradeall);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET hull_normal=hull_normal+1, engines_normal=engines_normal+1, power_normal=power_normal+1, fighter_normal=fighter_normal+1, sensors_normal=sensors_normal+1, beams_normal=beams_normal+1, torp_launchers_normal=torp_launchers_normal+1, shields_normal=shields_normal+1, armor_normal=armor_normal+1, cloak_normal=cloak_normal+1, ecm_normal=ecm_normal+1, hull=hull+1, engines=engines+1, power=power+1, fighter=fighter+1, sensors=sensors+1, beams=beams+1, torp_launchers=torp_launchers+1, shields=shields+1, armor=armor+1, cloak=cloak+1, ecm=ecm+1 WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			$debrismessage = str_replace("[level]", NUMBER($amount), $this->l_debris_degradeall);
			$query = "hull_normal=GREATEST(hull_normal - $amount, 0), hull=GREATEST(hull - $amount, 0),";
			$query .= "engines_normal=GREATEST(engines_normal - $amount, 0), engines=GREATEST(engines - $amount, 0),";
			$query .= "power_normal=GREATEST(power_normal - $amount, 0), power=GREATEST(power - $amount, 0),";
			$query .= "fighter_normal=GREATEST(fighter_normal - $amount, 0), fighter=GREATEST(fighter - $amount, 0),";
			$query .= "sensors_normal=GREATEST(sensors_normal - $amount, 0), sensors=GREATEST(sensors - $amount, 0),";
			$query .= "beams_normal=GREATEST(beams_normal - $amount, 0), beams=GREATEST(beams - $amount, 0),";
			$query .= "torp_launchers_normal=GREATEST(torp_launchers_normal - $amount, 0), torp_launchers=GREATEST(torp_launchers - $amount, 0),";
			$query .= "shields_normal=GREATEST(shields_normal - $amount, 0), shields=GREATEST(shields - $amount, 0),";
			$query .= "armor_normal=GREATEST(armor_normal - $amount, 0), armor=GREATEST(armor - $amount, 0),";
			$query .= "cloak_normal=GREATEST(cloak_normal - $amount, 0), cloak=GREATEST(cloak - $amount, 0),";
			$query .= "ecm_normal=GREATEST(ecm_normal - $amount, 0), ecm=GREATEST(ecm - $amount, 0)";

			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET $query WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$techdamage = ($shipinfo['hull'] - $amount) / $shipinfo['hull'];
			$debug_query = $db->Execute("UPDATE {$db_prefix}ship_holds SET amount=amount * $techdamage WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
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