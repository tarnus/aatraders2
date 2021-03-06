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
				$this->l_debris_addarmor = "Sa ei leitud mahaj�etud laeva [amount] �hikut armor saate lisada oma laeva.";
				$this->l_debris_removearmor = "Nagu te l�henes praht see plahvatas termonukleaarseks Fireball et leherootsudega off [amount] �ksused oma laevade armor.";
			break;

			case "french":
				$this->l_debris_addarmor = "Vous avez trouv� un bateau � l&#39;abandon avec [amount] unit�s de l&#39;armure vous pouvez ajouter � votre vaisseau.";
				$this->l_debris_removearmor = "Comme vous l&#39;avez abord� les d�bris il a explos� dans une explosion thermonucl�aire qui a d�pouill� [amount] Les unit�s de l&#39;armure de vos navires.";
			break;

			case "german":
				$this->l_debris_addarmor = "Sie haben eine verlassene Schiff mit [amount] Einheiten der Waffen die Sie hinzuf�gen k�nnen, um Ihr Schiff gefunden.";
				$this->l_debris_removearmor = "Wie man n�herte sich den Tr�mmern sie explodierte in einem Feuerball, der thermonuklearen abgestreift [amount] Einheiten Ihrer Schiffe R�stung.";
			break;

			case "italian":
				$this->l_debris_addarmor = "Hai trovato una nave abbandonata con [amount] unit� di armatura � possibile aggiungere alla tua nave.";
				$this->l_debris_removearmor = "Come si avvicinava le macerie � esplosa in una palla di fuoco termonucleare che si tolse [amount] unit� del tuo navi armatura.";
			break;

			case "spanish":
				$this->l_debris_addarmor = "Usted ha encontrado un barco abandonado con [amount] de unidades de armadura que puedes a�adir a tu nave.";
				$this->l_debris_removearmor = "A medida que se acerc� a los restos que explot� en una bola de fuego termonuclear que se despoj� de [amount] unidades de la armadura de tus naves.";
			break;

			case "albanian":
				$this->l_debris_addarmor = "Ju keni gjetur nj� anije t� braktisur me [amount] nj�sit� e forca t� blinduara ju mund t� shtoni n� anije tuaj.";
				$this->l_debris_removearmor = "Si ju afrohej mbeturinat ajo shp�rtheu n� nj� fireball termob�rthamor q� vodh�n off [amount] nj�sit� e anijeve forca t� blinduara tuaj.";
			break;

			case "catalan":
				$this->l_debris_addarmor = "Vost� ha trobat un vaixell abandonat amb [amount] d&#39;unitats d&#39;armadura que pots afegir a la teva nau.";
				$this->l_debris_removearmor = "A mesura que es va acostar a les restes que va explotar en una bola de foc termonuclear que es va despullar de [amount] unitats de l&#39;armadura dels teus naus.";
			break;

			case "danish":
				$this->l_debris_addarmor = "Du har fundet en forladt skib med [amount] enheder rustning du kan f�je til dit skib.";
				$this->l_debris_removearmor = "Som du n�rmede efterladenskaberne det eksploderede i en termonuklear ildkugle, der fjernede [amount] enheder af dine skibe rustning.";
			break;

			case "dutch":
				$this->l_debris_addarmor = "U hebt gevonden een verlaten schip met [amount] eenheden van pantser u kunt toevoegen aan uw schip.";
				$this->l_debris_removearmor = "Zoals u benaderde het puin is ontplofte in een thermonucleaire vuurbal die ontdaan [amount] eenheden van je schepen harnas.";
			break;

			case "finnish":
				$this->l_debris_addarmor = "Olet l�yt�nyt hyl�ttyjen alukselle [amount] yksikk�� panssarin voit lis�t� oman laivan.";
				$this->l_debris_removearmor = "Te yhteytt� roskat se r�j�hti thermonuclear Fireball ett� riisuttu pois [amount] yksik�iden sinun alusten panssarin.";
			break;

			case "indonesian":
				$this->l_debris_addarmor = "Anda telah menemukan sebuah kapal telantar dengan [amount] unit zirah Anda dapat ditambahkan ke kapal.";
				$this->l_debris_removearmor = "Saat Anda mendekati puing-puing itu meledak dalam bola api yang termonuklir melepas [amount] unit kapal Anda baju besi.";
			break;

			case "norwegian":
				$this->l_debris_addarmor = "Du har funnet en forlatt skipet med [amount] enheter av rustning du kan legge til skipet ditt.";
				$this->l_debris_removearmor = "Som du n�rmet seg vrakgods det eksploderte i en thermonuclear ildkule som strippet off [amount] enheter av skipene dine rustning.";
			break;

			case "portuguese":
				$this->l_debris_addarmor = "Voc� encontrou um navio abandonado com [amount] de unidades de armadura que voc� pode adicionar ao seu navio.";
				$this->l_debris_removearmor = "Como voc� se aproximou dos escombros que explodiu em uma bola de fogo termonuclear que despiu [amount] de unidades de sua armadura navios.";
			break;

			case "swedish":
				$this->l_debris_addarmor = "Du har hittat ett �vergivet skepp med [amount] enheter rustning du kan l�gga till ditt skepp.";
				$this->l_debris_removearmor = "Som ni n�rmade skr�pet den exploderade i en termisk eldklot som kl�dde av sig [amount] enheter dina skepp rustning.";
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