<?php
if (!function_exists('get_commodity_name')) {
	function get_commodity_name($commodity)
	{
		global $l_none, $l_unknown, $l_upgrade_ports, $l_device_ports, $l_spacedock, $l_casino, $l_wormhole;

		if(strtolower($commodity) == "none")
		{
			return $l_none;
		}
		else if(strtolower($commodity) == "unknown")
		{
			return $l_unknown;
		}
		else if(strtolower($commodity) == "upgrades")
		{
			return $l_upgrade_ports;
		}
		else if(strtolower($commodity) == "devices")
		{
			return $l_device_ports;
		}
		else if(strtolower($commodity) == "spacedock")
		{
			return $l_spacedock;
		}
		else if(strtolower($commodity) == "casino")
		{
			return $l_casino;
		}
		else if(strtolower($commodity) == "wormhole")
		{
			return $l_wormhole;
		}
		else if(empty($commodity))
		{
			return;
		}
		else
		{
			$fixedportname = str_replace(" ", "", $commodity);
			if(!class_exists($fixedportname)){
				include ("class/commodities/" . $fixedportname . ".inc");
			}

			$commodity_object = new $fixedportname();

			return $commodity_object->l_commodityname;
		}
	}
}
?>
