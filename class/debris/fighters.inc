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
				$this->l_debris_addfighters = "Olete leidnud hulk vedaja ja see sisaldab [amount] kasutatav hävitajaid.";
				$this->l_debris_removefighters = "Kui teile tuua prügi oma riidepuu muutub ebastabiilseks ja plahvatab hävitada [amount] oma elud.";
			break;

			case "french":
				$this->l_debris_addfighters = "Vous avez trouvé la carcasse d'un porte-vaisseau. Elle contient [amount] chasseurs utilisables.";
				$this->l_debris_removefighters = "Le transport des débris instables dans votre hangar déclenche une explosion qui détruit [amount] chasseurs.";
			break;

			case "german":
				$this->l_debris_addfighters = "Sie haben den Koloss eines Trägerschiffes gefunden und es beinhaltet [amount] voll funktionsfähige Jäger.";
				$this->l_debris_removefighters = "Während Sie den Schutt in Ihren Hangar befördern wird er unstabil. Er explodiert und zerstört [amount] Ihrer Jäger.";
			break;

			case "italian":
				$this->l_debris_addfighters = "Hai scoperto la carcassa di un incrociatore, contenente [amount] Droni utilizzabili.";
				$this->l_debris_removefighters = "Mentre trasporti i rottami nel tuo hangar per analizzarli, essi esplodono distruggendo [amount] dei tuoi Droni.";
			break;

			case "spanish":
				$this->l_debris_addfighters = "Usted ha encontrado el casco de una compañía y contiene [amount] combatientes utilizable.";
				$this->l_debris_removefighters = "Cuando te llevas a la ruina en su percha se vuelve inestable y explota la destrucción de [amount] de sus combatientes.";
			break;

			case "albanian":
				$this->l_debris_addfighters = "Ju keni gjetur një anije karakatinë e transportuesit dhe përmban [amount] luftëtarë të përdorshme.";
				$this->l_debris_removefighters = "Kur ju sjellin mbeturinat në vegjë tuaj bëhet e paqëndrueshme dhe Shpërthen shkatërrimin [amount] të luftëtarëve tuaj.";
			break;

			case "catalan":
				$this->l_debris_addfighters = "Vostè ha trobat el casc d&#39;una companyia i conté [amount] combatents utilitzable.";
				$this->l_debris_removefighters = "Quan et portes a la ruïna en la seva perxa es torna inestable i explota la destrucció de [amount] dels seus combatents.";
			break;

			case "danish":
				$this->l_debris_addfighters = "Du har fundet Skroget af en transportør, og den indeholder [amount] brugbart krigere.";
				$this->l_debris_removefighters = "Når du bringer det snavs ind i din bøjle det bliver ustabilt, og eksploderer ødelægge [amount] af dine krigere.";
			break;

			case "dutch":
				$this->l_debris_addfighters = "Je hebt de hulk van een luchtvaartmaatschappij en het bevat [amount] bruikbaar strijders.";
				$this->l_debris_removefighters = "Wanneer je de rommel in je hanger wordt het onstabiel en explodeert vernietigen [amount] van je vechters.";
			break;

			case "finnish":
				$this->l_debris_addfighters = "Olet löytänyt Hulk on operaattorin ja se sisältää [amount] käytettävissä taistelijoita.";
				$this->l_debris_removefighters = "Kun tuo roskat omalle ripustin siitä tulee epävakaa ja räjähtää tuhoaa [amount] oman taistelijoita.";
			break;

			case "indonesian":
				$this->l_debris_addfighters = "Anda telah menemukan sebuah kapal induk raksasa dan berisi [amount] yang dapat digunakan pejuang.";
				$this->l_debris_removefighters = "Ketika Anda membawa puing-puing ke gantungan Anda menjadi tidak stabil dan meledak menghancurkan [amount] dari pejuang Anda.";
			break;

			case "norwegian":
				$this->l_debris_addfighters = "Du har funnet rusk av en operatør, og den inneholder [amount] brukbare jagerfly.";
				$this->l_debris_removefighters = "Når du bringer rusk inn i hengeren det blir ustabilt og eksploderer ødelegge [amount] av dine krigere.";
			break;

			case "portuguese":
				$this->l_debris_addfighters = "Você encontrou o casco de uma transportadora e que contém [amount] caças utilizáveis.";
				$this->l_debris_removefighters = "Quando você colocar os restos em seu hangar, torna-se instável e explode destruindo [amount] de seus combatentes.";
			break;

			case "swedish":
				$this->l_debris_addfighters = "Du har hittat Hulken av en transportör och det innehåller [amount] användbart fighters.";
				$this->l_debris_removefighters = "När du tar med skräp i din hanger det blir instabil och exploderar förstöra [amount] i din krigare.";
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