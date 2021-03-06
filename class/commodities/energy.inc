<?php
class energy {
	var $classname = "energy";
	var $cargoclass = "commodity";	// the class of cargo (commodity, generic, shipweapon, planetweapon, sectordefense, ect)
	var $upgradeport = "0";	// is this a port item that can be bought and sold (yes or no)
	var $deviceport = "0";	// is this a port item that can be bought and sold (yes or no)
	var $cargoport = "1";	// is this a port item that can be bought and sold (yes or no)
	var $cargosellbuy = "0";	// 0 = sell and buy at ports, 1 = ports buy only, 2 = ports sell only
	var $cargoplanet = "1";	// is this an item that can be from a planet (yes or no)
	var $defaultcargoplanet = "1";	// is this a default item from a planet (yes or no)
	var $defaultcargoship = "1";	// is this a default item always carried by a ship (yes or no)
	var $shipdevice = "0";	// can this be used as a ship device (yes or no)
	var $planetdevice = "0";	// can this be used as a planet device (yes or no)
	var $shipdevicemax = "0";	// maximum number of this device a ship can carry
	var $planetdevicemax = "0";	// maximum number of this device a planet can hold
	var $researchonly = "0";	// this item can only be built at a research station if set to 1
	var $goodevil = "1"; // 1 - good or -1 - evil commodity
	var $price = 6; // Default Price
	var $delta = 1; // Price modifier - reduce port sell price by this amount and increase port buy price by this amount
	var $rate = 75000; // Replenishment rate
	var $reducerate = 0.0000004; // Price reduces per item traded (calculated from (price * multiplier / itemlimit) multiplier between 1-25 lower value higher the price)
	var $increaserate = 0.00025; // Percentage prices will increase per trade schedule tick
	var $limit = 100000000000; // Maximum amount of commodity port can hold
	var $prate = 0.008; // Planetary Production Rate
	var $default_prod = 20; // Planet production percentage
	var $default_indy_prod = 20; // Planet production percentage
	var $default_create_percent = 10; // Percentage of item to create during Create Game
	var $fixed_start_price = 10; // this is the max fixed start price for this item 

	var $damage_shields = 0; // amount of damage to enemy shield hit points per torp
	var $damage_all = 0; // amount of damage to all enemy items except shields per torp
	var $deflector_damage = 0; // amound of damage to mines when each mine deflector hits
	var $hit_pts = 0; // the amount of damage a mine take before it is destroyed
	var $price_modifier = 0; // The cost of each torp is multiplied by this number
	var $energy_usage = 0; // How many units of energy is used

	var $researchcredits = 0; // How many credits to use per tick to research an item
	var $researchore = 0; // How much ore to use per tick to research an item
	var $researchorganics = 0; // How much organics to use per tick to research an item
	var $researchgoods = 0; // How many goods to use per tick to research an item
	var $researchenergy = 0; // How much energy to use per tick to research an item
	var $researchticks = 0; // How many ticks it takes to complete the researching of an item
	var $buildcredits = 0; // How many credits to use per tick to research an item
	var $buildore = 0; // How much ore to use per tick to research an item
	var $buildorganics = 0; // How much organics to use per tick to research an item
	var $buildgoods = 0; // How many goods to use per tick to research an item
	var $buildenergy = 0; // How much energy to use per tick to research an item
	var $buildticks = 0; // How many ticks it takes to complete building an item
	var $program = ""; // program to execute when player selects item
	var $hold_space = 1; // the amount of hold space each item requires for storage

	var $image_location = 0; // 0 = inside each template image file, 1 = inside /images/classes

	var $l_commodityname;
	// return language
	function energy()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_commodityname = "Energia";
			break;

			case "french":
				$this->l_commodityname = "�nergie";
			break;

			case "german":
				$this->l_commodityname = "Energie";
			break;

			case "italian":
				$this->l_commodityname = "Energia";
			break;

			case "spanish":
				$this->l_commodityname = "Energ�a";
			break;

			case "albanian":
				$this->l_commodityname = "Energjis�";
			break;

			case "catalan":
				$this->l_commodityname = "Energia";
			break;

			case "danish":
				$this->l_commodityname = "Energi";
			break;

			case "dutch":
				$this->l_commodityname = "Energie";
			break;

			case "finnish":
				$this->l_commodityname = "Energiahuollon";
			break;

			case "indonesian":
				$this->l_commodityname = "Energi";
			break;

			case "norwegian":
				$this->l_commodityname = "Energi";
			break;

			case "portuguese":
				$this->l_commodityname = "Energia";
			break;

			case "swedish":
				$this->l_commodityname = "Energi";
			break;

			default:
				$this->l_commodityname = "Energy";
			break;
		}
	}
}
?>
