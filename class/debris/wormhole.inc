<?php
class wormhole {
	var $classname = "wormhole";
	var $success = "350";	// Random value range
	var $trigger = "175";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_wormhole;

	// fill language variables
	function wormhole()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_wormhole = "Sa ei leitud Artefakti et käivitub nagu te pöördunud. On loodud uss augu ruumi ning saadetakse teile sektoris [sector].";
			break;

			case "french":
				$this->l_debris_wormhole = "Vous avez trouvé un artefact qui a déclenché comme vous approché. Il a créé un trou de ver dans l&#39;espace et vous a envoyés pour le secteur [sector].";
			break;

			case "german":
				$this->l_debris_wormhole = "Sie haben ein Artefakt, das, wie Sie passen gefunden näherte. Es erstellt ein Wurmloch im Raum und euch gesandt, zu Sektor [sector].";
			break;

			case "italian":
				$this->l_debris_wormhole = "Hai trovato un artefatto che ha attivato, come si avvicinava. Ha creato un buco verme nello spazio e inviato al settore [sector].";
			break;

			case "spanish":
				$this->l_debris_wormhole = "Se han encontrado un artefacto que ha disparado a medida que se acercaba. Se creó un agujero de gusano en el espacio y le envió al sector [sector].";
			break;

			case "albanian":
				$this->l_debris_wormhole = "Ju keni gjetur një Objekti që shkaktoi si ju afruar. Ai krijoi një vrimë rra në hapësirë dhe e dërgoi që të sektorit [sector].";
			break;

			case "catalan":
				$this->l_debris_wormhole = "S&#39;han trobat un artefacte que ha disparat a mesura que s&#39;acostava. Es va crear un forat de cuc en l&#39;espai i el va enviar al sector [sector].";
			break;

			case "danish":
				$this->l_debris_wormhole = "Du har fundet en genstand, der udløses, som du nærmede sig. Det skabte en orm hul i rummet og sendt dig til sektor [sector].";
			break;

			case "dutch":
				$this->l_debris_wormhole = "U hebt een artefact dat leverde als je gevonden benaderd. Het creëerde een worm gat in de ruimte en stuurde u naar sector [sector].";
			break;

			case "finnish":
				$this->l_debris_wormhole = "Olet löytänyt esineen, joka laukaisi kun lähestyi. Se loi mato reikä avaruudessa ja lähetti sinut alalle [sector].";
			break;

			case "indonesian":
				$this->l_debris_wormhole = "Anda telah menemukan sebuah artefak yang memicu seperti Anda mendekat. Ini menciptakan lubang cacing dalam ruang dan dikirim Anda untuk sektor [sector].";
			break;

			case "norwegian":
				$this->l_debris_wormhole = "Du har funnet en gjenstand som utløste mens du nærmet seg. Det skapte en orm hull i rommet og sendte deg til sektor [sector].";
			break;

			case "portuguese":
				$this->l_debris_wormhole = "Você encontrou um artefato que disparou à medida que se aproximava. É criado um buraco de minhoca no espaço e lhe enviou para o sector [sector].";
			break;

			case "swedish":
				$this->l_debris_wormhole = "Du har funnit en artefakt som utlöses när man närmade sig. Det skapade en mask hål i rymden och skickat till sektor [sector].";
			break;

			default:
				$this->l_debris_wormhole = "You have found an artifact that triggered as you approached.  It created a worm hole in space and sent you to sector [sector].";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo;
		$findem = $db->SelectLimit("SELECT sector_name, sector_id FROM {$db_prefix}universe where galaxy_id = $shipinfo[galaxy_id] ORDER BY rand()", 1);
		$targetlink = $findem->fields['sector_id'];
		$targetname = $findem->fields['sector_name'];

		$debrismessage = str_replace("[sector]", $targetname, $this->l_debris_wormhole);

		$query = "UPDATE {$db_prefix}ships SET sector_id=$targetlink WHERE ship_id=$shipinfo[ship_id]";
		$debug_query = $db->Execute("$query");
		db_op_result($debug_query,__LINE__,__FILE__);
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$debris_data = 1;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$debris_data = 1;
		return $debris_data;
	}
}

?>