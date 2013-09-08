<?php
class none {
	var $classname = "none";
	var $success = "5";	// Random value range
	var $trigger = "2";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_nothing;

	// fill language variables
	function none()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_nothing = "Teie insenerid on otsustanud, on mõttetu space junk.";
			break;

			case "french":
				$this->l_debris_nothing = "Vos ingénieurs décident qu'il s'agit de simples détritus.";
			break;

			case "german":
				$this->l_debris_nothing = "Ihre Ingenieure haben herausgefunden, dass es nur nutzloser Weltraumschrott ist.";
			break;

			case "italian":
				$this->l_debris_nothing = "I tuoi ingenieri hanno analizzato il rottame e non hanno trovato altro che inutilizzabili rifiuti spaziali.";
			break;

			case "spanish":
				$this->l_debris_nothing = "Sus ingenieros han determinado que es basura espacial inútil.";
			break;

			case "albanian":
				$this->l_debris_nothing = "Inxhinierë juaj kanë përcaktuar se është e padobishme junk hapësirë.";
			break;

			case "catalan":
				$this->l_debris_nothing = "Els seus enginyers han determinat que és deixalles espacials inútil.";
			break;

			case "danish":
				$this->l_debris_nothing = "Deres ingeniører har bestemt det er nytteløst space junk.";
			break;

			case "dutch":
				$this->l_debris_nothing = "Uw ingenieurs hebben vastgesteld dat het zinloos is ruimte junk.";
			break;

			case "finnish":
				$this->l_debris_nothing = "Sinun insinöörit ovat päättäneet, että on hyödytöntä tilaa roskaa.";
			break;

			case "indonesian":
				$this->l_debris_nothing = "Insinyur Anda telah menentukan ruang percuma sampah.";
			break;

			case "norwegian":
				$this->l_debris_nothing = "Din ingeniører har bestemt det er ubrukelig plass useriøs.";
			break;

			case "portuguese":
				$this->l_debris_nothing = "Seu engenheiros determinaram que é lixo espacial inútil.";
			break;

			case "swedish":
				$this->l_debris_nothing = "Din ingenjörer har fastställt att det är onödigt utrymme skräp.";
			break;

			default:
				$this->l_debris_nothing = "Your engineers have determined it is useless space junk.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		$debrismessage =  $this->l_debris_nothing;
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$debris_data = 0;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$debris_data = 0;
		return $debris_data;
	}
}

?>