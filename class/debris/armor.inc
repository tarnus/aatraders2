<?php
class armor {
	var $classname = "armor";
	var $success = "150";	// Random value range
	var $trigger = "75";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "1";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_addarmor;
	var $l_debris_removearmor;

	// fill language variables
	function armor()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addarmor = "Sa ei leitud mahajäetud laeva [amount] ühikut armor saate lisada oma laeva.";
				$this->l_debris_removearmor = "Nagu te lähenes praht see plahvatas termonukleaarseks Fireball et leherootsudega off [amount] üksused oma laevade armor.";
			break;

			case "french":
				$this->l_debris_addarmor = "Vous avez trouvé un bateau à l&#39;abandon avec [amount] unités de l&#39;armure vous pouvez ajouter à votre vaisseau.";
				$this->l_debris_removearmor = "Comme vous l&#39;avez abordé les débris il a explosé dans une explosion thermonucléaire qui a dépouillé [amount] Les unités de l&#39;armure de vos navires.";
			break;

			case "german":
				$this->l_debris_addarmor = "Sie haben eine verlassene Schiff mit [amount] Einheiten der Waffen die Sie hinzufügen können, um Ihr Schiff gefunden.";
				$this->l_debris_removearmor = "Wie man näherte sich den Trümmern sie explodierte in einem Feuerball, der thermonuklearen abgestreift [amount] Einheiten Ihrer Schiffe Rüstung.";
			break;

			case "italian":
				$this->l_debris_addarmor = "Hai trovato una nave abbandonata con [amount] unità di armatura è possibile aggiungere alla tua nave.";
				$this->l_debris_removearmor = "Come si avvicinava le macerie è esplosa in una palla di fuoco termonucleare che si tolse [amount] unità del tuo navi armatura.";
			break;

			case "spanish":
				$this->l_debris_addarmor = "Usted ha encontrado un barco abandonado con [amount] de unidades de armadura que puedes añadir a tu nave.";
				$this->l_debris_removearmor = "A medida que se acercó a los restos que explotó en una bola de fuego termonuclear que se despojó de [amount] unidades de la armadura de tus naves.";
			break;

			case "albanian":
				$this->l_debris_addarmor = "Ju keni gjetur një anije të braktisur me [amount] njësitë e forca të blinduara ju mund të shtoni në anije tuaj.";
				$this->l_debris_removearmor = "Si ju afrohej mbeturinat ajo shpërtheu në një fireball termobërthamor që vodhën off [amount] njësitë e anijeve forca të blinduara tuaj.";
			break;

			case "catalan":
				$this->l_debris_addarmor = "Vostè ha trobat un vaixell abandonat amb [amount] d&#39;unitats d&#39;armadura que pots afegir a la teva nau.";
				$this->l_debris_removearmor = "A mesura que es va acostar a les restes que va explotar en una bola de foc termonuclear que es va despullar de [amount] unitats de l&#39;armadura dels teus naus.";
			break;

			case "danish":
				$this->l_debris_addarmor = "Du har fundet en forladt skib med [amount] enheder rustning du kan føje til dit skib.";
				$this->l_debris_removearmor = "Som du nærmede efterladenskaberne det eksploderede i en termonuklear ildkugle, der fjernede [amount] enheder af dine skibe rustning.";
			break;

			case "dutch":
				$this->l_debris_addarmor = "U hebt gevonden een verlaten schip met [amount] eenheden van pantser u kunt toevoegen aan uw schip.";
				$this->l_debris_removearmor = "Zoals u benaderde het puin is ontplofte in een thermonucleaire vuurbal die ontdaan [amount] eenheden van je schepen harnas.";
			break;

			case "finnish":
				$this->l_debris_addarmor = "Olet löytänyt hylättyjen alukselle [amount] yksikköä panssarin voit lisätä oman laivan.";
				$this->l_debris_removearmor = "Te yhteyttä roskat se räjähti thermonuclear Fireball että riisuttu pois [amount] yksiköiden sinun alusten panssarin.";
			break;

			case "indonesian":
				$this->l_debris_addarmor = "Anda telah menemukan sebuah kapal telantar dengan [amount] unit zirah Anda dapat ditambahkan ke kapal.";
				$this->l_debris_removearmor = "Saat Anda mendekati puing-puing itu meledak dalam bola api yang termonuklir melepas [amount] unit kapal Anda baju besi.";
			break;

			case "norwegian":
				$this->l_debris_addarmor = "Du har funnet en forlatt skipet med [amount] enheter av rustning du kan legge til skipet ditt.";
				$this->l_debris_removearmor = "Som du nærmet seg vrakgods det eksploderte i en thermonuclear ildkule som strippet off [amount] enheter av skipene dine rustning.";
			break;

			case "portuguese":
				$this->l_debris_addarmor = "Você encontrou um navio abandonado com [amount] de unidades de armadura que você pode adicionar ao seu navio.";
				$this->l_debris_removearmor = "Como você se aproximou dos escombros que explodiu em uma bola de fogo termonuclear que despiu [amount] de unidades de sua armadura navios.";
			break;

			case "swedish":
				$this->l_debris_addarmor = "Du har hittat ett övergivet skepp med [amount] enheter rustning du kan lägga till ditt skepp.";
				$this->l_debris_removearmor = "Som ni närmade skräpet den exploderade i en termisk eldklot som klädde av sig [amount] enheter dina skepp rustning.";
			break;

			default:
				$this->l_debris_addarmor = "You have found a derelict ship with [amount] units of armor you can add to your ship.";
				$this->l_debris_removearmor = "As you approached the debris it exploded in a thermonuclear fireball that stripped off [amount] units of your ships armor.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo;

		if($row['debris_data'] > 0)
		{
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addarmor);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=armor_pts+$row[debris_data] WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			if(($shipinfo['armor_pts'] + $row['debris_data']) <= 0){
				$row['debris_data'] = 1 - $shipinfo['armor_pts'];
			}
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_removearmor);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET armor_pts=GREATEST(armor_pts+$row[debris_data], 1) WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$amount = mt_rand(50, 50 + $destroyed_ship_info['armor_pts']);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$amount = mt_rand(50, 50 + NUM_PER_LEVEL($max_list['armor_max']));
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}
}

?>