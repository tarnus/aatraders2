<?php
class fighters {
	var $classname = "fighters";
	var $success = "100";	// Random value range
	var $trigger = "50";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "1";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addfighters;
	var $l_debris_removefighters;

	// fill language variables
	function fighters()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addfighters = "Olete leidnud hulk vedaja ja see sisaldab [amount] kasutatav h�vitajaid.";
				$this->l_debris_removefighters = "Kui teile tuua pr�gi oma riidepuu muutub ebastabiilseks ja plahvatab h�vitada [amount] oma elud.";
			break;

			case "french":
				$this->l_debris_addfighters = "Vous avez trouv� la carcasse d'un porte-vaisseau. Elle contient [amount] chasseurs utilisables.";
				$this->l_debris_removefighters = "Le transport des d�bris instables dans votre hangar d�clenche une explosion qui d�truit [amount] chasseurs.";
			break;

			case "german":
				$this->l_debris_addfighters = "Sie haben den Koloss eines Tr�gerschiffes gefunden und es beinhaltet [amount] voll funktionsf�hige J�ger.";
				$this->l_debris_removefighters = "W�hrend Sie den Schutt in Ihren Hangar bef�rdern wird er unstabil. Er explodiert und zerst�rt [amount] Ihrer J�ger.";
			break;

			case "italian":
				$this->l_debris_addfighters = "Hai scoperto la carcassa di un incrociatore, contenente [amount] Droni utilizzabili.";
				$this->l_debris_removefighters = "Mentre trasporti i rottami nel tuo hangar per analizzarli, essi esplodono distruggendo [amount] dei tuoi Droni.";
			break;

			case "spanish":
				$this->l_debris_addfighters = "Usted ha encontrado el casco de una compa��a y contiene [amount] combatientes utilizable.";
				$this->l_debris_removefighters = "Cuando te llevas a la ruina en su percha se vuelve inestable y explota la destrucci�n de [amount] de sus combatientes.";
			break;

			case "albanian":
				$this->l_debris_addfighters = "Ju keni gjetur nj� anije karakatin� e transportuesit dhe p�rmban [amount] luft�tar� t� p�rdorshme.";
				$this->l_debris_removefighters = "Kur ju sjellin mbeturinat n� vegj� tuaj b�het e paq�ndrueshme dhe Shp�rthen shkat�rrimin [amount] t� luft�tar�ve tuaj.";
			break;

			case "catalan":
				$this->l_debris_addfighters = "Vost� ha trobat el casc d&#39;una companyia i cont� [amount] combatents utilitzable.";
				$this->l_debris_removefighters = "Quan et portes a la ru�na en la seva perxa es torna inestable i explota la destrucci� de [amount] dels seus combatents.";
			break;

			case "danish":
				$this->l_debris_addfighters = "Du har fundet Skroget af en transport�r, og den indeholder [amount] brugbart krigere.";
				$this->l_debris_removefighters = "N�r du bringer det snavs ind i din b�jle det bliver ustabilt, og eksploderer �del�gge [amount] af dine krigere.";
			break;

			case "dutch":
				$this->l_debris_addfighters = "Je hebt de hulk van een luchtvaartmaatschappij en het bevat [amount] bruikbaar strijders.";
				$this->l_debris_removefighters = "Wanneer je de rommel in je hanger wordt het onstabiel en explodeert vernietigen [amount] van je vechters.";
			break;

			case "finnish":
				$this->l_debris_addfighters = "Olet l�yt�nyt Hulk on operaattorin ja se sis�lt�� [amount] k�ytett�viss� taistelijoita.";
				$this->l_debris_removefighters = "Kun tuo roskat omalle ripustin siit� tulee ep�vakaa ja r�j�ht�� tuhoaa [amount] oman taistelijoita.";
			break;

			case "indonesian":
				$this->l_debris_addfighters = "Anda telah menemukan sebuah kapal induk raksasa dan berisi [amount] yang dapat digunakan pejuang.";
				$this->l_debris_removefighters = "Ketika Anda membawa puing-puing ke gantungan Anda menjadi tidak stabil dan meledak menghancurkan [amount] dari pejuang Anda.";
			break;

			case "norwegian":
				$this->l_debris_addfighters = "Du har funnet rusk av en operat�r, og den inneholder [amount] brukbare jagerfly.";
				$this->l_debris_removefighters = "N�r du bringer rusk inn i hengeren det blir ustabilt og eksploderer �delegge [amount] av dine krigere.";
			break;

			case "portuguese":
				$this->l_debris_addfighters = "Voc� encontrou o casco de uma transportadora e que cont�m [amount] ca�as utiliz�veis.";
				$this->l_debris_removefighters = "Quando voc� colocar os restos em seu hangar, torna-se inst�vel e explode destruindo [amount] de seus combatentes.";
			break;

			case "swedish":
				$this->l_debris_addfighters = "Du har hittat Hulken av en transport�r och det inneh�ller [amount] anv�ndbart fighters.";
				$this->l_debris_removefighters = "N�r du tar med skr�p i din hanger det blir instabil och exploderar f�rst�ra [amount] i din krigare.";
			break;

			default:
				$this->l_debris_addfighters = "You have found the hulk of a carrier and it contains [amount] usable fighters.";
				$this->l_debris_removefighters = "When you bring the debris into your hanger it becomes unstable and explodes destroying [amount] of your fighters.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo;

		if($row['debris_data'] > 1)
		{
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addfighters);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET fighters=fighters+$row[debris_data] WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			if(($shipinfo['fighters'] + $row['debris_data']) <= 0){
				$row['debris_data'] = 1 - $shipinfo['fighters'];
			}
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_removefighters);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET fighters=GREATEST(fighters+$row[debris_data], 0) WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$amount = mt_rand(50, 50 + $destroyed_ship_info['fighters']);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$amount = mt_rand(50, 50 + NUM_PER_LEVEL($max_list['fighter_max']));
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}
}

?>