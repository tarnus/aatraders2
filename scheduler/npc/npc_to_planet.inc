<?php
include("scheduler/npc/npc_to_ship.inc");
include("scheduler/npc/calc_ownership.inc");

if (!function_exists('npc_to_planet')) {

	function npc_to_planet($planet_id, $charactername)
	{
		// ***********************************
		// *** NPC Planet Attack Code ***
		// ***********************************

		// *********************************
		// *** SETUP GENERAL VARIABLES	****
		// *********************************
		global $playerinfo;
		global $planetinfo;
		global $torp_dmg_rate;
		global $level_factor;
		global $rating_combat_factor;
		global $upgrade_cost;
		global $upgrade_factor;
		global $sector_max;
		global $NPCisdead;
		global $db, $dbtables;

		return; // JP - for now disable attacking planets since it doesn't work well (just give away free credits)

		// ********************************
		// *** LOOKUP PLANET DETAILS	 ****
		// ********************************
		$resultp = $db->Execute ("SELECT * FROM {$db_prefix}planets WHERE planet_id='$planet_id'");
		$planetinfo=$resultp->fields;

		if ($planetinfo['owner'] == 0)
		{
			playerlog($playerinfo['ship_id'], LOG_RAW, "Planet is not owned by anyone, so not attacking.");
			return;
		}
		// ********************************
		// *** LOOKUP OWNER DETAILS		****
		// ********************************
		$resulto = $db->Execute ("SELECT * FROM {$db_prefix}ships WHERE ship_id='$planetinfo[owner]'");
		$ownerinfo=$resulto->fields;

		//Checking if flag NPC
		if (strstr($playerinfo['character_name'], 'Flag'))											 //*** He's the flag ***
		{
			playerlog($playerinfo['ship_id'], LOG_RAW, "Attack failed, The Flag NPC cannot attack a planet.");
			return;
		}

		// Made it this far, so I'm going to log the attack and give the NPC a bounty if he deserves it - rjordan
		// Moved the log attack here to clear log clutter and reduce scheduler time - rjordan

		playerlog($playerinfo['ship_id'], LOG_NPC_ATTACK, "$character_name");
//		PlayerLogFile("$playerinfo[character_name] attacked $character_name in sector $playerinfo[sector]");
		// **********************************
		// *** SETUP PLANETARY VARIABLES ****
		// **********************************
		$base_factor = ($planetinfo['base'] == 'Y') ? $basedefense : 0;

		// *** PLANET BEAMS ***
		$targetbeams = NUM_BEAMS($ownerinfo['beams'] + $base_factor);
		if ($targetbeams > $planetinfo['energy'])
		{
			$targetbeams = $planetinfo['energy'];
		}
		$planetinfo['energy'] -= $targetbeams;

		// *** PLANET SHIELDS ***
		$targetshields = NUM_SHIELDS($ownerinfo['shields'] + $base_factor);
		if ($targetshields > $planetinfo['energy'])
		{
			$targetshields = $planetinfo['energy'];
		}
		$planetinfo['energy'] -= $targetshields;

		// *** PLANET TORPS ***
		$torp_launchers = round(mypw($level_factor, ($ownerinfo['torp_launchers'])+ $base_factor)) * 10;
		$torps = $planetinfo['torps'];
		$targettorps = $torp_launchers;
		if ($torp_launchers > $torps)
		{
			$targettorps = $torps;
		}
		$planetinfo['torps'] -= $targettorps;
		$targettorpdmg = $torp_dmg_rate * $targettorps;

		// *** PLANET FIGHTERS ***
		$targetfighters = $planetinfo['fighters'];

		// *********************************
		// *** SETUP ATTACKER VARIABLES ****
		// *********************************

		// *** ATTACKER BEAMS ***
		$attackerbeams = NUM_BEAMS($playerinfo['beams']);
		if ($attackerbeams > $playerinfo['ship_energy'])
		{
			$attackerbeams = $playerinfo['ship_energy'];
		}
		$playerinfo['ship_energy'] -= $attackerbeams;

		// *** ATTACKER SHIELDS ***
		$attackershields = NUM_SHIELDS($playerinfo['shields']);
		if ($attackershields > $playerinfo['ship_energy'])
		{
			$attackershields = $playerinfo['ship_energy'];
		}
		$playerinfo['ship_energy'] -= $attackershields;

		// *** ATTACKER TORPS ***
		$attackertorps = round(mypw($level_factor, $playerinfo['torp_launchers'])) * 2;
		if ($attackertorps > $playerinfo['torps'])
		{
			$attackertorps = $playerinfo['torps'];
		} 
		$playerinfo['torps'] -= $attackertorps;
		$attackertorpdamage = $torp_dmg_rate * $attackertorps;

		// *** ATTACKER FIGHTERS ***
		$attackerfighters = $playerinfo['ship_fighters'];

		// *** ATTACKER ARMOUR ***
		$attackerarmor = $playerinfo['armour_pts'];

		// *********************************
		// **** BEGIN COMBAT PROCEDURES ****
		// *********************************
		if($attackerbeams > 0 && $targetfighters > 0)
		{												 //******** ATTACKER HAS BEAMS - TARGET HAS FIGHTERS - BEAMS VS FIGHTERS ********
			if($attackerbeams > $targetfighters)
			{																	//****** ATTACKER BEAMS GT TARGET FIGHTERS ******
				$lost = $targetfighters;
				$targetfighters = 0;																		 //**** T LOOSES ALL FIGHTERS ****
				$attackerbeams = $attackerbeams-$lost;									 //**** A LOOSES BEAMS EQ TO T FIGHTERS ****
			}
			else
			{																	//****** ATTACKER BEAMS LE TARGET FIGHTERS ******
				$targetfighters = $targetfighters-$attackerbeams;				//**** T LOOSES FIGHTERS EQ TO A BEAMS ****
				$attackerbeams = 0;																			//**** A LOOSES ALL BEAMS ****
			} 
		}
		if($attackerfighters > 0 && $targetbeams > 0)
		{												 //******** TARGET HAS BEAMS - ATTACKER HAS FIGHTERS - BEAMS VS FIGHTERS ********
			if($targetbeams > round($attackerfighters / 2))
			{																	//****** TARGET BEAMS GT HALF ATTACKER FIGHTERS ******
				$lost=$attackerfighters-(round($attackerfighters/2));
				$attackerfighters=$attackerfighters-$lost;							 //**** A LOOSES HALF ALL FIGHTERS ****
				$targetbeams=$targetbeams-$lost;												 //**** T LOOSES BEAMS EQ TO HALF A FIGHTERS ****
			}
			else
			{																	//****** TARGET BEAMS LE HALF ATTACKER FIGHTERS ******
				$attackerfighters=$attackerfighters-$targetbeams;				//**** A LOOSES FIGHTERS EQ TO T BEAMS **** 
				$targetbeams=0;																					//**** T LOOSES ALL BEAMS ****
			}
		}
		if($attackerbeams > 0)
		{												 //******** ATTACKER HAS BEAMS LEFT - CONTINUE COMBAT - BEAMS VS SHIELDS ********
			if($attackerbeams > $targetshields)
			{																	//****** ATTACKER BEAMS GT TARGET SHIELDS ******
				$attackerbeams=$attackerbeams-$targetshields;						//**** A LOOSES BEAMS EQ TO T SHIELDS ****
				$targetshields=0;																				//**** T LOOSES ALL SHIELDS ****
			}
			else
			{																	//****** ATTACKER BEAMS LE TARGET SHIELDS ******
				$targetshields=$targetshields-$attackerbeams;						//**** T LOOSES SHIELDS EQ TO A BEAMS ****
				$attackerbeams=0;																				//**** A LOOSES ALL BEAMS ****
			}
		}
		if($targetbeams > 0)
		{												 //******** TARGET HAS BEAMS LEFT - CONTINUE COMBAT - BEAMS VS SHIELDS ********
			if($targetbeams > $attackershields)
			{																	//****** TARGET BEAMS GT ATTACKER SHIELDS ******
				$targetbeams=$targetbeams-$attackershields;							//**** T LOOSES BEAMS EQ TO A SHIELDS ****
				$attackershields=0;																			//**** A LOOSES ALL SHIELDS ****
			}
			else
			{																	//****** TARGET BEAMS LE ATTACKER SHIELDS ****** 
				$attackershields=$attackershields-$targetbeams;					//**** A LOOSES SHIELDS EQ TO T BEAMS ****
				$targetbeams=0;																					//**** T LOOSES ALL BEAMS ****
			}
		}
		if($targetbeams > 0)
		{												//******** TARGET HAS BEAMS LEFT - CONTINUE COMBAT - BEAMS VS ARMOR ******** 
			if($targetbeams > $attackerarmor)
			{																 //****** TARGET BEAMS GT ATTACKER ARMOR ******
				$targetbeams=$targetbeams-$attackerarmor;								//**** T LOOSES BEAMS EQ TO A ARMOR ****
				$attackerarmor=0;																				//**** A LOOSES ALL ARMOR (A DESTROYED) ****
			}
			else
			{																 //****** TARGET BEAMS LE ATTACKER ARMOR ******
				$attackerarmor=$attackerarmor-$targetbeams;							//**** A LOOSES ARMOR EQ TO T BEAMS ****
				$targetbeams=0;																					//**** T LOOSES ALL BEAMS ****
			} 
		}
		if($targetfighters > 0 && $attackertorpdamage > 0)
		{												//******** ATTACKER FIRES TORPS - TARGET HAS FIGHTERS - TORPS VS FIGHTERS ********
			if($attackertorpdamage > $targetfighters)
			{																 //****** ATTACKER FIRED TORPS GT TARGET FIGHTERS ******
				$lost=$targetfighters;
				$targetfighters=0;																			 //**** T LOOSES ALL FIGHTERS ****
				$attackertorpdamage=$attackertorpdamage-$lost;					 //**** A LOOSES FIRED TORPS EQ TO T FIGHTERS ****
			}
			else
			{																 //****** ATTACKER FIRED TORPS LE HALF TARGET FIGHTERS ******
				$targetfighters=$targetfighters-$attackertorpdamage;		 //**** T LOOSES FIGHTERS EQ TO A TORPS FIRED ****
				$attackertorpdamage=0;																	 //**** A LOOSES ALL TORPS FIRED ****
			}
		}
		if($attackerfighters > 0 && $targettorpdmg > 0)
		{												//******** TARGET FIRES TORPS - ATTACKER HAS FIGHTERS - TORPS VS FIGHTERS ********
			if($targettorpdmg > round($attackerfighters / 2))
			{																 //****** TARGET FIRED TORPS GT HALF ATTACKER FIGHTERS ******
				$lost=$attackerfighters-(round($attackerfighters/2));
				$attackerfighters=$attackerfighters-$lost;							 //**** A LOOSES HALF ALL FIGHTERS ****
				$targettorpdmg=$targettorpdmg-$lost;										 //**** T LOOSES FIRED TORPS EQ TO HALF A FIGHTERS ****
			}
			else
			{																 //****** TARGET FIRED TORPS LE HALF ATTACKER FIGHTERS ******
				$attackerfighters=$attackerfighters-$targettorpdmg;			//**** A LOOSES FIGHTERS EQ TO T TORPS FIRED ****
				$targettorpdmg=0;																				//**** T LOOSES ALL TORPS FIRED ****
			}
		}
		if($targettorpdmg > 0)
		{												//******** TARGET FIRES TORPS - CONTINUE COMBAT - TORPS VS ARMOR ********
			if($targettorpdmg > $attackerarmor)
			{																 //****** TARGET FIRED TORPS GT HALF ATTACKER ARMOR ******
				$targettorpdmg=$targettorpdmg-$attackerarmor;						//**** T LOOSES FIRED TORPS EQ TO A ARMOR ****
				$attackerarmor=0;																				//**** A LOOSES ALL ARMOR (A DESTROYED) ****
			}
			else
			{																 //****** TARGET FIRED TORPS LE HALF ATTACKER ARMOR ******
				$attackerarmor=$attackerarmor-$targettorpdmg;						//**** A LOOSES ARMOR EQ TO T TORPS FIRED ****
				$targettorpdmg=0;																				//**** T LOOSES ALL TORPS FIRED ****
			} 
		}
		if($attackerfighters > 0 && $targetfighters > 0)
		{												//******** ATTACKER HAS FIGHTERS - TARGET HAS FIGHTERS - FIGHTERS VS FIGHTERS ********
			if($attackerfighters > $targetfighters)
			{																 //****** ATTACKER FIGHTERS GT TARGET FIGHTERS ******
				$temptargfighters=0;																		 //**** T WILL LOOSE ALL FIGHTERS ****
			}
			else
			{																 //****** ATTACKER FIGHTERS LE TARGET FIGHTERS ******
				$temptargfighters=$targetfighters-$attackerfighters;		 //**** T WILL LOOSE FIGHTERS EQ TO A FIGHTERS ****
			}
			if($targetfighters > $attackerfighters)
			{																 //****** TARGET FIGHTERS GT ATTACKER FIGHTERS ******
				$tempplayfighters=0;																		 //**** A WILL LOOSE ALL FIGHTERS ****
			}
			else
			{																 //****** TARGET FIGHTERS LE ATTACKER FIGHTERS ******
				$tempplayfighters=$attackerfighters-$targetfighters;		 //**** A WILL LOOSE FIGHTERS EQ TO T FIGHTERS ****
			}		 
			$attackerfighters=$tempplayfighters;
			$targetfighters=$temptargfighters;
		}
		if($targetfighters > 0)
		{												//******** TARGET HAS FIGHTERS - CONTINUE COMBAT - FIGHTERS VS ARMOR ********
			if($targetfighters > $attackerarmor)
			{																 //****** TARGET FIGHTERS GT ATTACKER ARMOR ******
				$attackerarmor=0;																				//**** A LOOSES ALL ARMOR (A DESTROYED) ****
			}
			else
			{																 //****** TARGET FIGHTERS LE ATTACKER ARMOR ******
				$attackerarmor=$attackerarmor-$targetfighters;					 //**** A LOOSES ARMOR EQ TO T FIGHTERS ****
			}
		}

		// *********************************
		// **** FIX NEGATIVE VALUE VARS ****
		// *********************************
		if ($attackerfighters < 0)
		{
			$attackerfighters = 0;
		}
		if ($attackertorps < 0)
		{
			$attackertorps = 0;
		}
		if ($attackershields < 0)
		{
			$attackershields = 0;
		}
		if ($attackerbeams < 0)
		{
			$attackerbeams = 0;
		}
		if ($attackerarmor < 0)
		{
			$attackerarmor = 0;
		}
		if ($targetfighters < 0)
		{
			$targetfighters = 0;
		}
		if ($targettorps < 0)
		{
			$targettorps = 0;
		}
		if ($targetshields < 0)
		{
			$targetshields = 0;
		}
		if ($targetbeams < 0)
		{
			$targetbeams = 0;
		}

		// ******************************************
		// *** CHECK IF ATTACKER SHIP DESTROYED	 ***
		// ******************************************
		if(!$attackerarmor>0)
		{
			playerlog($playerinfo['ship_id'], LOG_RAW, "Ship destroyed by planetary defenses on planet $planetinfo[name]");
			db_kill_player($playerinfo['ship_id']);
			$NPCisdead = 1;

			$free_ore = round($playerinfo['ship_ore']/2);
			$free_organics = round($playerinfo['ship_organics']/2);
			$free_goods = round($playerinfo['ship_goods']/2);
			$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $playerinfo['hull']))+round(mypw($upgrade_factor, $playerinfo['engines']))+round(mypw($upgrade_factor, $playerinfo['power']))+round(mypw($upgrade_factor, $playerinfo['computer']))+round(mypw($upgrade_factor, $playerinfo['sensors']))+round(mypw($upgrade_factor, $playerinfo['beams']))+round(mypw($upgrade_factor, $playerinfo['torp_launchers']))+round(mypw($upgrade_factor, $playerinfo['shields']))+round(mypw($upgrade_factor, $playerinfo['armor']))+round(mypw($upgrade_factor, $playerinfo['cloak'])));
			$ship_salvage_rate=rand(10,20);
			$ship_salvage=$ship_value*$ship_salvage_rate/100;
			$fighters_lost = $planetinfo['fighters'] - $targetfighters;

			// *** LOG ATTACK TO PLANET OWNER ***
			playerlog($planetinfo['owner'], LOG_PLANET_NOT_DEFEATED, "$planetinfo[name]|$planetinfo[sector_id]|NPC $playerinfo[character_name]|$free_ore|$free_organics|$free_goods|$ship_salvage_rate|$ship_salvage");
//			PlayerLogFile("NPC $playerinfo[character_name] was killed attacking planet $planetinfo[name] in sector $planetinfo[sector_id].");

			// *** UPDATE PLANET ***
			$db->Execute("UPDATE {$db_prefix}planets SET energy=$planetinfo[energy],fighters=fighters-$fighters_lost, torps=torps-$targettorps, ore=ore+$free_ore, goods=goods+$free_goods, organics=organics+$free_organics, credits=credits+$ship_salvage WHERE planet_id=$planetinfo[planet_id]");
		}
		// **********************************************
		// *** MUST HAVE MADE IT PAST PLANET DEFENSES ***
		// **********************************************
		else
		{
			$armor_lost = $playerinfo['armour_pts'] - $attackerarmor;
			$fighters_lost = $playerinfo['ship_fighters'] - $attackerfighters;
			$target_fighters_lost = $planetinfo['ship_fighters'] - $targetfighters;
			playerlog($playerinfo['ship_id'], LOG_RAW, "Made it past defenses on planet $planetinfo[name]");

			// *** UPDATE ATTACKER ***
			$db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$playerinfo[ship_energy], ship_fighters=ship_fighters-$fighters_lost, torps=torps-$attackertorps, armour_pts=armour_pts-$armor_lost WHERE ship_id=$playerinfo[ship_id]");
			$playerinfo['ship_fighters'] = $attackerfighters;
			$playerinfo['torps'] = $attackertorps;
			$playerinfo['armour_pts'] = $attackerarmor;

			// *** UPDATE PLANET ***
			$db->Execute ("UPDATE {$db_prefix}planets SET energy=$planetinfo[energy], fighters=$targetfighters, torps=torps-$targettorps WHERE planet_id=$planetinfo[planet_id]");
			$planetinfo['fighters'] = $targetfighters;
			$planetinfo['torps'] = $targettorps;

			// *** NOW WE MUST ATTACK ALL SHIPS ON THE PLANET ONE BY ONE ***
			$resultps = $db->Execute("SELECT ship_id,ship_name FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
			$shipsonplanet = $resultps->RecordCount();
			if ($shipsonplanet > 0)
			{
				while (!$resultps->EOF && $NPCisdead < 1)
				{
					$onplanet = $resultps->fields;
					npc_to_ship($onplanet['ship_id']);
					$resultps->MoveNext();
				}
			}
			$resultps = $db->Execute("SELECT ship_id,ship_name FROM {$db_prefix}ships WHERE planet_id=$planetinfo[planet_id] AND on_planet='Y'");
			$shipsonplanet = $resultps->RecordCount();
			if ($shipsonplanet == 0 && $NPCisdead < 1)
			{
				// *** MUST HAVE KILLED ALL SHIPS ON PLANET ***
				playerlog($playerinfo['ship_id'], LOG_RAW, "Defeated all ships on planet $planetinfo[name]");
				// *** LOG ATTACK TO PLANET OWNER ***
				playerlog($planetinfo['owner'], LOG_PLANET_DEFEATED, "$planetinfo[name]|$planetinfo[sector_id]|$playerinfo[character_name]");
//					PlayerLogFile("NPC $playerinfo[character_name] defeated planet $planetinfo[name] ($planetinfo[planet_id]) in sector $planetinfo[sector_id] trying to kill $charactername.");
				// *** UPDATE PLANET ***
				$db->Execute("UPDATE {$db_prefix}planets SET fighters=0, torps=0, base='N', owner=0, corp=0 WHERE planet_id=$planetinfo[planet_id]"); 
				calc_ownership($planetinfo['sector_id']);
			}
			else
			{
				// *** MUST HAVE DIED TRYING ***
				playerlog($playerinfo['ship_id'], LOG_RAW, "We were KILLED by ships defending planet $planetinfo[name]");
				// *** LOG ATTACK TO PLANET OWNER ***
				playerlog($planetinfo['owner'], LOG_PLANET_NOT_DEFEATED, "$planetinfo[name]|$playerinfo[sector]|NPC $playerinfo[character_name]|0|0|0|0|0");
//				PlayerLogFile("NPC $playerinfo[character_name] was killed by ships while attacking planet $planetinfo[name] in sector $planetinfo[sector_id] trying to kill $charactername.");
				// *** NO SALVAGE FOR PLANET BECAUSE WENT TO SHIP WHO WON **
			}
		}
	}
}

?>
