<?php
class credits {
	var $classname = "credits";
	var $success = "250";	// Random value range
	var $trigger = "125";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "1";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $maximum_amount = "50000000";	// Set to maximum amount that can be stored in a debris item
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addcredits;
	var $l_debris_removecredits;

	// fill language variables
	function credits()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addcredits = "Olete stumbled upon peidetud piraat krediidipank ja see sisaldas [amount] krediiti.";
				$this->l_debris_removecredits = "Praht tegelikult varjatud Piraatlaeva. Nad peatatud oma laeva ja varastas [amount] krediiti.";
			break;

			case "french":
				$this->l_debris_addcredits = "La chance vous d�voile une banque de pirates cach�e! Elle contient [amount] cr�dits.";
				$this->l_debris_removecredits = "Les d�bris �taient r�ellement un vaisseau pirate cach�... Ils vous ont vol� [amount] cr�dits.";
			break;

			case "german":
				$this->l_debris_addcredits = "Sie sind zuf�llig auf ein Piraten-Konto auf der Bank gestossen, welches Ihnen [amount] Credits einbringt.";
				$this->l_debris_removecredits = "Der Schutt war in Wirklichkeit ein verstecktes Piratenschiff. Sie haben [amount] Credits gestohlen.";
			break;

			case "italian":
				$this->l_debris_addcredits = "Ti sei imbattuto in una banca pirata segreta contenente [amount] crediti.";
				$this->l_debris_removecredits = "I rottami non erano altro che una nave camuffata, dalla quale dei pirati hanno abbordato la tua nave, rubandoti [amount] crediti.";
			break;

			case "spanish":
				$this->l_debris_addcredits = "Ha tropezado con un banco oculto de cr�dito pirata y que conten�a [amount] cr�ditos.";
				$this->l_debris_removecredits = "Los escombros en realidad era un barco pirata disfrazado. Subieron a su barco y le robaron [amount] cr�ditos.";
			break;

			case "albanian":
				$this->l_debris_addcredits = "Ju keni ngecur mbi nj� bank� fshehur krediti pirat dhe p�rmbante [amount] kredi.";
				$this->l_debris_removecredits = "Mbeturinat ishte n� fakt nj� anije pirate maskuar. Ata hipi n� anije dhe vodhi [amount] credits.";
			break;

			case "catalan":
				$this->l_debris_addcredits = "Ha ensopegat amb un banc ocult de cr�dit pirata i que contenia [amount] cr�dits.";
				$this->l_debris_removecredits = "La runa en realitat era un vaixell pirata disfressat. Van pujar al seu vaixell i li van robar [amount] cr�dits.";
			break;

			case "danish":
				$this->l_debris_addcredits = "Du har snuble p� en skjult pirat kredit bank, og det indeholdt [amount] kreditter.";
				$this->l_debris_removecredits = "Resterne var faktisk en skjult piratskib. De gik ombord p� dit skib og stjal [amount] kreditter.";
			break;

			case "dutch":
				$this->l_debris_addcredits = "U hebt struikelde op een verborgen piraat krediet bank en bevatte [amount] credits.";
				$this->l_debris_removecredits = "Het puin was eigenlijk een verkapte piratenschip. Ze stapten je schip en stal [amount] credits.";
			break;

			case "finnish":
				$this->l_debris_addcredits = "Sinulla on luiskahtanut piilotettu merirosvo luotto pankki ja se sis�lsi [amount] opintoviikkoa.";
				$this->l_debris_removecredits = "Roskat oli itse asiassa peitelty merirosvolaiva. He nousivat oman aluksen ja oli [amount] opintoviikkoa.";
			break;

			case "indonesian":
				$this->l_debris_addcredits = "Anda telah menemukan sebuah bajak laut tersembunyi kredit bank dan berisi [amount] kredit.";
				$this->l_debris_removecredits = "Sebenarnya puing-puing kapal bajak laut yang menyamar. Mereka naik kapal anda dan mencuri [amount] kredit.";
			break;

			case "norwegian":
				$this->l_debris_addcredits = "Du har snublet over et skjult pirat kreditt banken og den inneholdt [amount] studiepoeng.";
				$this->l_debris_removecredits = "Vrakgodset var egentlig en forkledd sj�r�verskute. De ombord skipet ditt og stjal [amount] studiepoeng.";
			break;

			case "portuguese":
				$this->l_debris_addcredits = "Voc� trope�ou em um banco de cr�dito oculto pirata e conteve [amount] de cr�ditos.";
				$this->l_debris_removecredits = "Os restos foram realmente um navio pirata disfar�ado. Eles abordaram o navio e roubaram [amount] de cr�ditos.";
			break;

			case "swedish":
				$this->l_debris_addcredits = "Du har snubblat p� en dold pirat kredit bank och den inneh�ll [amount] krediter.";
				$this->l_debris_removecredits = "Skr�pet var egentligen en f�rt�ckt piratskepp. De bordade ditt skepp och vann [amount] krediter.";
			break;

			default:
				$this->l_debris_addcredits = "You have stumbled upon a hidden pirate credit bank and it contained [amount] credits.";
				$this->l_debris_removecredits = "The debris was actually a disguised pirate ship.  They boarded your ship and stole [amount] credits.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $playerinfo, $piratestealpercent;

		if($row['debris_data'] > 0)
		{
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addcredits);
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits+$row[debris_data] WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			$amount = round($playerinfo['credits'] * ($piratestealpercent / 100));

			$debrismessage = str_replace("[amount]", NUMBER($amount), $this->l_debris_removecredits);
			$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=GREATEST(credits-$amount, 0) WHERE player_id=$playerinfo[player_id]");
			db_op_result($debug_query,__LINE__,__FILE__);

			$findem = $db->SelectLimit("SELECT sector_id FROM {$db_prefix}universe ORDER BY rand()", 1);
			$targetlink = $findem->fields['sector_id'];

			$debug_query = $db->Execute("INSERT INTO {$db_prefix}debris (debris_type, debris_data, sector_id) values ('ship_credits','$amount', $targetlink)");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$amount = mt_rand(50, 50 + $this->maximum_amount);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$amount = mt_rand(50, 50 + $this->maximum_amount);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}
}

?>