<?php
class ship_credits {
	var $classname = "ship_credits";
	var $success = "0";	// Random value range
	var $trigger = "0";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "1";	// Set to 1 if this debris can be created when a ship is destroyed
	var $autoadd_debris = "0"; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addcredits;

	// fill language variables
	function ship_credits()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addcredits = "Olete stumbled upon peidetud piraat krediidipank ja see sisaldas [amount] krediiti.";
			break;

			case "french":
				$this->l_debris_addcredits = "La chance vous fait trouver une banque de pirates cach�e! Elle contient [amount] cr�dits.";
			break;

			case "german":
				$this->l_debris_addcredits = "Sie sind zuf�llig auf ein Piraten-Konto auf der Bank gestossen, welches Ihnen [amount] Credits einbringt.";
			break;

			case "italian":
				$this->l_debris_addcredits = "Ti sei imbattuto in una banca pirata segreta contenente [amount] crediti.";
			break;

			case "spanish":
				$this->l_debris_addcredits = "Ha tropezado con un banco oculto de cr�dito pirata y que conten�a [amount] cr�ditos.";
			break;

			case "albanian":
				$this->l_debris_addcredits = "Ju keni ngecur mbi nj� bank� fshehur krediti pirat dhe p�rmbante [amount] kredi.";
			break;

			case "catalan":
				$this->l_debris_addcredits = "Ha ensopegat amb un banc ocult de cr�dit pirata i que contenia [amount] cr�dits.";
			break;

			case "danish":
				$this->l_debris_addcredits = "Du har snuble p� en skjult pirat kredit bank, og det indeholdt [amount] kreditter.";
			break;

			case "dutch":
				$this->l_debris_addcredits = "U hebt struikelde op een verborgen piraat krediet bank en bevatte [amount] credits.";
			break;

			case "finnish":
				$this->l_debris_addcredits = "Sinulla on luiskahtanut piilotettu merirosvo luotto pankki ja se sis�lsi [amount] opintoviikkoa.";
			break;

			case "indonesian":
				$this->l_debris_addcredits = "Anda telah menemukan sebuah bajak laut tersembunyi kredit bank dan berisi [amount] kredit.";
			break;

			case "norwegian":
				$this->l_debris_addcredits = "Du har snublet over et skjult pirat kreditt banken og den inneholdt [amount] studiepoeng.";
			break;

			case "portuguese":
				$this->l_debris_addcredits = "Voc� trope�ou em um banco de cr�dito oculto pirata e conteve [amount] de cr�ditos.";
			break;

			case "swedish":
				$this->l_debris_addcredits = "Du har snubblat p� en dold pirat kredit bank och den inneh�ll [amount] krediter.";
			break;

			default:
				$this->l_debris_addcredits = "You have stumbled upon a hidden pirate credit bank and it contained [amount] credits.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $playerinfo;

		$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addcredits);
		$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits+$row[debris_data] WHERE player_id=$playerinfo[player_id]");
		db_op_result($debug_query,__LINE__,__FILE__);
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		global $db, $db_prefix, $amount, $flag, $totrecs, $getit;
		$debris_data = $amount;
		$randplay=mt_rand(0,($totrecs-1));
		$targetlink = $getit[$randplay]['sector_id'];
		$debug_query = $db->Execute("INSERT INTO {$db_prefix}debris (debris_type, debris_data, sector_id) values ('ship_credits','$debris_data', $targetlink)");
		db_op_result($debug_query,__LINE__,__FILE__);
		$flag = 1;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
	}
}

?>