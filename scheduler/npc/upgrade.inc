<?php

if (!function_exists('upgrade')) {

	function upgrade()
	{
		global $db, $db_prefix;
		// *******************************
		// *** LETS REGENERATE ARMOUR ****
		// *******************************
		$maxarmor = NUM_ARMOUR($playerinfo['armor']);
		if ($playerinfo['armor_pts'] <= ($maxarmor - 50))	// *** STOP REGEN WHEN WITHIN 50 OF MAX ***
		{																									// *** REGEN HALF OF REMAINING ARMOUR ***
			$playerinfo['armor_pts'] = $playerinfo['armor_pts'] + round($maxarmor - $playerinfo['armor_pts']);
			$gena = "regenerated Armor to $playerinfo[armor_pts] points,";
		}

		// *******************************
		// *** LETS BUY FIGHTERS/TORPS ***
		// *******************************

		// *******************************
		// *** NPC PAY 6/FIGHTER ****
		// *******************************
		$available_fighters = NUM_FIGHTERS($playerinfo['computer']) - $playerinfo['ship_fighters'];
		if (($playerinfo['credits']>5) && ($available_fighters>0))
		{
			if (round($playerinfo['credits']/6) > $available_fighters)
			{
				$purchase = ($available_fighters*6);
				$playerinfo['credits'] = $playerinfo['credits'] - $purchase;
				$playerinfo['ship_fighters'] = $playerinfo['ship_fighters'] + $available_fighters;
				$genf = "purchased $available_fighters fighters for $purchase credits,";
			}
			if (round($playerinfo['credits']/6)<=$available_fighters)
			{
				$purchase = (round($playerinfo['credits']/6));
				$playerinfo['ship_fighters'] = $playerinfo['ship_fighters'] + $purchase;
				$genf = "purchased $purchase fighters for $playerinfo[credits] credits,";
				$playerinfo['credits'] = 0;
			}
		} 

		// *******************************
		// *** NPC PAY 3/TORPEDO ****
		// *******************************
		$available_torpedoes = NUM_TORPEDOES($playerinfo['torp_launchers']) - $playerinfo['torps'];
		if (($playerinfo['credits']>2) && ($available_torpedoes>0))
		{
			if (round($playerinfo['credits']/3) > $available_torpedoes)
			{
				$purchase = ($available_torpedoes*3);
				$playerinfo['credits'] = $playerinfo['credits'] - $purchase;
				$playerinfo['torps'] = $playerinfo['torps'] + $available_torpedoes;
				$gent = "purchased $available_torpedoes torpedoes for $purchase credits,";
			}
			if (round($playerinfo['credits']/3)<=$available_torpedoes)
			{
				$purchase = (round($playerinfo['credits']/3));
				$playerinfo['torps'] = $playerinfo['torps'] + $purchase;
				$gent = "purchased $purchase torpedoes for $playerinfo[credits] credits,";
				$playerinfo['credits'] = 0;
			}
		} 

		// *********************************
		// *** UPDATE NPC RECORD ******
		// *********************************
		$db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$playerinfo[ship_energy], armor_pts=$playerinfo[armor_pts], ship_fighters=$playerinfo[ship_fighters], torps=$playerinfo[torps], credits=$playerinfo[credits] WHERE ship_id=$playerinfo[ship_id]");
		// JP - don't want to fill logs up with NPC info
		//	if (!$gene=='' || !$gena=='' || !$genf=='' || !$gent=='')
		//	{
		//		playerlog($playerinfo[ship_id], LOG_RAW, "NPC $gene $gena $genf $gent and has been updated."); 
		//	}
	}
}

?>
