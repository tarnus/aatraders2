<?php

if (!function_exists('npc_to_ship')) {

	function npc_to_ship($ship_id)
	{
		// *********************************
		// *** SETUP GENERAL VARIABLES	****
		// *********************************
		global $attackerbeams;
		global $attackerfighters;
		global $attackershields;
		global $attackertorps;
		global $attackerarmor;
		global $attackertorpdamage;
		global $start_energy;
		global $playerinfo;
		global $rating_combat_factor;
		global $upgrade_cost;
		global $upgrade_factor;
		global $sector_max;
		global $NPCisdead;
		global $bounty_maxvalue;
		global $db, $dbtables;

		// *********************************
		// *** LOOKUP TARGET DETAILS		****
		// *********************************
		$resultt = $db->Execute ("SELECT * FROM {$db_prefix}ships WHERE ship_id='$ship_id'");
		$targetinfo=$resultt->fields;

		// JP: check if special killer NPC...
		if (strncasecmp("Attack ", $playerinfo['ship_name'], 7) == 0)
		{
			$killerNPC = true;
		}
		else
		{
			$killerNPC = false;
		}

		// *******************************************
		// ** VERIFY NOT ATTACKING ANOTHER NPC **
		// *******************************************
		//added because the NPC were killing each other off - rjordan
		if (strstr($targetinfo['email'], '@NPC')) //*** He's a NPC ***
		{
//	playerlog($playerinfo['ship_id'], LOG_RAW, "Attack failed, NPC cannot attack NPC."); - commented out to reduce log clutter and time - rjordan01
			return;
		}
		// *********************************
		// ** VERIFY SECTOR ALLOWS ATTACK **
		// *********************************
		$sectres = $db->Execute ("SELECT sector_id,zone_id FROM {$db_prefix}universe WHERE sector_id=$targetinfo[sector]");
		$sectrow = $sectres->fields;
		$zoneres = $db->Execute ("SELECT zone_id,allow_attack FROM {$db_prefix}zones WHERE zone_id=$sectrow[zone_id]");
		$zonerow = $zoneres->fields;
		if ($zonerow['allow_attack']=="N")												//*** DEST LINK MUST ALLOW ATTACKING ***
		{
//			playerlog($playerinfo['ship_id'], LOG_RAW, "Attack failed, you are in a sector that prohibits attacks."); // - commented out to reduce log clutter and time - rjordan
			//Add db unlocks to prevent lockups when multiple sched_NPCs are being run on each cron job - rjordan
			return;
		}

		// Made it this far, so I'm going to log the attack and give the NPC a bounty if he deserves it - rjordan
		// Moved the log attack here to clear log clutter and reduce scheduler time - rjordan

		playerlog($playerinfo['ship_id'], LOG_NPC_ATTACK, "$targetinfo[character_name]");

		//added bounty rountine because NPC should receive bounties like normal players

		$playerbountyscore = $targetinfo['score'] * $targetinfo['score'];

		// Check to see if there is Federation bounty on the player. If there is, NPC can attack regardless.
		$btyamount = 0;
		$hasbounty = $db->Execute("SELECT SUM(amount) AS btytotal FROM {$db_prefix}bounty WHERE bounty_on = $targetinfo[ship_id] AND placed_by = 0");
		if($hasbounty)
		{
			$resx = $hasbounty->fields;
			$btyamount = $resx['btytotal'];
		}
		if (($btyamount <= 0) && ($killerNPC == false))
		{
//			$reason = "Attacking $targetinfo[character_name] in sector $targetinfo[sector]";
			$reason = "Attacking $targetinfo[character_name]";
			$bounty = ROUND($playerbountyscore * $bounty_maxvalue);
			$insert = $db->Execute("INSERT INTO {$db_prefix}bounty (bounty_on,placed_by,amount,reason) ".
									"values ($playerinfo[ship_id], 0 ,$bounty, '$reason')");			
			playerlog($playerinfo['ship_id'],LOG_BOUNTY_FEDBOUNTY,"$bounty");
//			PlayerLogFile("Fed placed bounty on $playerinfo[character_name] of $bounty for attacking $targetinfo[character_name]");
		}

		// *********************************
		// *** USE EMERGENCY WARP DEVICE ***
		// *********************************
		if ($targetinfo['dev_emerwarp']>0)
		{
			if ($killerNPC == false)
			{
				playerlog($targetinfo['ship_id'], LOG_ATTACK_EWD, "NPC $playerinfo[character_name]");
				$dest_sector=rand(0,$sector_max);
				$result_warp = $db->Execute ("UPDATE {$db_prefix}ships SET sector=$dest_sector, dev_emerwarp=dev_emerwarp-1 WHERE ship_id=$targetinfo[ship_id]");
				return;
			}
			else
			{
				playerlog($targetinfo['ship_id'], LOG_ATTACK_EWDFAIL, $playerinfo['character_name']);
			}
		}
		// *********************************
		// *** SETUP ATTACKER VARIABLES ****
		// *********************************
		$attackerbeams = NUM_BEAMS($playerinfo['beams']);
		if ($attackerbeams > $playerinfo['ship_energy'])
		{
			$attackerbeams = $playerinfo['ship_energy'];
		}
		$playerinfo['ship_energy'] = $playerinfo['ship_energy'] - $attackerbeams;
		$attackershields = NUM_SHIELDS($playerinfo['shields']);
		if ($attackershields > $playerinfo['ship_energy'])
		{
			$attackershields = $playerinfo['ship_energy'];
		}
		$playerinfo['ship_energy'] = $playerinfo['ship_energy'] - $attackershields;
		$attackertorps = round(mypw($level_factor, $playerinfo['torp_launchers'])) * 2;
		if ($attackertorps > $playerinfo['torps'])
		{
			$attackertorps = $playerinfo['torps'];
		}
		$playerinfo['torps'] = $playerinfo['torps'] - $attackertorps;
		$attackertorpdamage = $torp_dmg_rate * $attackertorps;
		$attackerarmor = $playerinfo['armour_pts'];
		$attackerfighters = $playerinfo['ship_fighters'];
		$playerdestroyed = 0;

		// *********************************
		// **** SETUP TARGET VARIABLES *****
		// *********************************
		$targetbeams = NUM_BEAMS($targetinfo['beams']);
		if ($targetbeams>$targetinfo['ship_energy'])
		{
			$targetbeams=$targetinfo['ship_energy'];
		}
		$targetinfo['ship_energy']=$targetinfo['ship_energy']-$targetbeams;
		$targetshields = NUM_SHIELDS($targetinfo['shields']);
		if ($targetshields>$targetinfo['ship_energy'])
		{
			$targetshields=$targetinfo['ship_energy'];
		}
		$targetinfo['ship_energy']=$targetinfo['ship_energy']-$targetshields;
		$targettorpnum = round(mypw($level_factor,$targetinfo['torp_launchers']))*2;
		if ($targettorpnum > $targetinfo['torps'])
		{
			$targettorpnum = $targetinfo['torps'];
		}
		$targetinfo['torps'] = $targetinfo['torps'] - $targettorpnum;
		$targettorpdmg = $torp_dmg_rate*$targettorpnum;
		$targetarmor = $targetinfo['armour_pts'];
		$targetfighters = $targetinfo['ship_fighters'];
		$targetdestroyed = 0;

		// *********************************
		// **** BEGIN COMBAT PROCEDURES ****
		// *********************************

		if($attackerbeams > 0 && $targetfighters > 0)
		{												 //******** ATTACKER HAS BEAMS - TARGET HAS FIGHTERS - BEAMS VS FIGHTERS ********
			if($attackerbeams > round($targetfighters / 2))
			{																	//****** ATTACKER BEAMS GT HALF TARGET FIGHTERS ******
				$lost = $targetfighters-(round($targetfighters/2));
				$targetfighters = $targetfighters-$lost;								 //**** T LOOSES HALF ALL FIGHTERS ****
				$attackerbeams = $attackerbeams-$lost;									 //**** A LOOSES BEAMS EQ TO HALF T FIGHTERS ****
			}
			else
			{																	//****** ATTACKER BEAMS LE HALF TARGET FIGHTERS ******
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
		if($attackerbeams > 0)
		{												 //******** ATTACKER HAS BEAMS LEFT - CONTINUE COMBAT - BEAMS VS ARMOR ********
			if($attackerbeams > $targetarmor)
			{																	//****** ATTACKER BEAMS GT TARGET ARMOR ******
				$attackerbeams=$attackerbeams-$targetarmor;							//**** A LOOSES BEAMS EQ TO T ARMOR ****
				$targetarmor=0;																					//**** T LOOSES ALL ARMOR (T DESTROYED) ****
			}
			else
			{																	//****** ATTACKER BEAMS LE TARGET ARMOR ******
				$targetarmor=$targetarmor-$attackerbeams;								//**** T LOOSES ARMORS EQ TO A BEAMS ****
				$attackerbeams=0;																				//**** A LOOSES ALL BEAMS ****
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
			if($attackertorpdamage > round($targetfighters / 2))
			{																 //****** ATTACKER FIRED TORPS GT HALF TARGET FIGHTERS ******
				$lost=$targetfighters-(round($targetfighters/2));
				$targetfighters=$targetfighters-$lost;									 //**** T LOOSES HALF ALL FIGHTERS ****
				$attackertorpdamage=$attackertorpdamage-$lost;					 //**** A LOOSES FIRED TORPS EQ TO HALF T FIGHTERS ****
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
		if($attackertorpdamage > 0)
		{												//******** ATTACKER FIRES TORPS - CONTINUE COMBAT - TORPS VS ARMOR ********
			if($attackertorpdamage > $targetarmor)
			{																 //****** ATTACKER FIRED TORPS GT HALF TARGET ARMOR ******
				$attackertorpdamage=$attackertorpdamage-$targetarmor;		//**** A LOOSES FIRED TORPS EQ TO T ARMOR ****
				$targetarmor=0;																					//**** T LOOSES ALL ARMOR (T DESTROYED) ****
			}
			else
			{																 //****** ATTACKER FIRED TORPS LE HALF TARGET ARMOR ******
				$targetarmor=$targetarmor-$attackertorpdamage;					 //**** T LOOSES ARMOR EQ TO A TORPS FIRED ****
				$attackertorpdamage=0;																	 //**** A LOOSES ALL TORPS FIRED ****
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
		if($attackerfighters > 0)
		{												//******** ATTACKER HAS FIGHTERS - CONTINUE COMBAT - FIGHTERS VS ARMOR ********
			if($attackerfighters > $targetarmor)
			{																 //****** ATTACKER FIGHTERS GT TARGET ARMOR ******
				$targetarmor=0;																					//**** T LOOSES ALL ARMOR (T DESTROYED) ****
			}
			else
			{																 //****** ATTACKER FIGHTERS LE TARGET ARMOR ******
				$targetarmor=$targetarmor-$attackerfighters;						 //**** T LOOSES ARMOR EQ TO A FIGHTERS **** 
			}
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
		if ($targettorpnum < 0)
		{
			$targettorpnum = 0;
		}
		if ($targetshields < 0)
		{
			$targetshields = 0;
		}
		if ($targetbeams < 0)
		{
			$targetbeams = 0;
		}
		if ($targetarmor < 0)
		{
			$targetarmor = 0;
		}

		// *********************************
		// *** DEAL WITH DESTROYED SHIPS ***
		// *********************************

		// *********************************
		// *** TARGET SHIP WAS DESTROYED ***
		// *********************************
		if(!$targetarmor>0)
		{
			if($targetinfo['dev_escapepod'] == "Y")
			// ****** TARGET HAD ESCAPE POD ******
			{
				$rating=round($targetinfo['rating']/2);
				$db->Execute("UPDATE {$db_prefix}ships SET hull=0, engines=0, power=0, computer=0,sensors=0, beams=0, torp_launchers=0, torps=0, armour=0, armour_pts=100, cloak=0, shields=0, sector=0, ship_ore=0, ship_organics=0, ship_energy=1000, ship_colonists=0, ship_goods=0, ship_fighters=100, ship_damage='', on_planet='N', planet_id=0, dev_warpedit=0, dev_genesis=0, dev_beacon=0, dev_emerwarp=0, dev_escapepod='N', dev_fuelscoop='N', dev_minedeflector=0, ship_destroyed='N', rating='$rating',dev_lssd='N' where ship_id=$targetinfo[ship_id]");
				playerlog($targetinfo['ship_id'], LOG_ATTACK_LOSE, "NPC $playerinfo[character_name]|Y"); 
			}
			else
			// ****** TARGET HAD NO POD ******
			{
				playerlog($targetinfo['ship_id'], LOG_ATTACK_LOSE, "NPC $playerinfo[character_name]|N"); 
				db_kill_player($targetinfo['ship_id']);
			}	 
			if($attackerarmor>0)
			{
				// ****** ATTACKER STILL ALIVE TO SALVAGE TRAGET ******
				$rating_change=round($targetinfo['rating']*$rating_combat_factor);
				$free_ore = round($targetinfo['ship_ore']/2);
				$free_organics = round($targetinfo['ship_organics']/2);
				$free_goods = round($targetinfo['ship_goods']/2);
				$free_holds = NUM_HOLDS($playerinfo['hull']) - $playerinfo['ship_ore'] - $playerinfo['ship_organics'] - $playerinfo['ship_goods'] - $playerinfo['ship_colonists'];
				if($free_holds > $free_goods) 
				{																												//****** FIGURE OUT WHAT WE CAN CARRY ******
					$salv_goods=$free_goods;
					$free_holds=$free_holds-$free_goods;
				}
				elseif($free_holds > 0)
				{
					$salv_goods=$free_holds;
					$free_holds=0;
				}
				else
				{
					$salv_goods=0;
				}
				if($free_holds > $free_ore)
				{
					$salv_ore=$free_ore;
					$free_holds=$free_holds-$free_ore;
				}
				elseif($free_holds > 0)
				{
					$salv_ore=$free_holds;
					$free_holds=0;
				}
				else
				{
					$salv_ore=0;
				}
				if($free_holds > $free_organics)
				{
					$salv_organics=$free_organics;
					$free_holds=$free_holds-$free_organics;
				}
				elseif($free_holds > 0)
				{
					$salv_organics=$free_holds;
					$free_holds=0;
				}
				else
				{
					$salv_organics=0;
				}
				$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $targetinfo['hull']))+round(mypw($upgrade_factor, $targetinfo['engines']))+round(mypw($upgrade_factor, $targetinfo['power']))+round(mypw($upgrade_factor, $targetinfo['computer']))+round(mypw($upgrade_factor, $targetinfo['sensors']))+round(mypw($upgrade_factor, $targetinfo['beams']))+round(mypw($upgrade_factor, $targetinfo['torp_launchers']))+round(mypw($upgrade_factor, $targetinfo['shields']))+round(mypw($upgrade_factor, $targetinfo['armor']))+round(mypw($upgrade_factor, $targetinfo['cloak'])));
				$ship_salvage_rate=rand(10,20);
				$ship_salvage=$ship_value*$ship_salvage_rate/100;
				playerlog($playerinfo['ship_id'], LOG_RAW, "Attack successful, $targetinfo[character_name] was defeated and salvaged for $ship_salvage credits."); 
				$db->Execute ("UPDATE {$db_prefix}ships SET ship_ore=ship_ore+$salv_ore, ship_organics=ship_organics+$salv_organics, ship_goods=ship_goods+$salv_goods, credits=credits+$ship_salvage WHERE ship_id=$playerinfo[ship_id]");
				$armor_lost = $playerinfo['armour_pts'] - $attackerarmor;
				$fighters_lost = $playerinfo['ship_fighters'] - $attackerfighters;
				$energy=$playerinfo['ship_energy'];
				$db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$energy,ship_fighters=ship_fighters-$fighters_lost, torps=torps-$attackertorps,armour_pts=armour_pts-$armor_lost, rating=rating-$rating_change WHERE ship_id=$playerinfo[ship_id]");
			}
		}

		// *********************************
		// *** TARGET AND ATTACKER LIVE	***
		// *********************************
		if($targetarmor>0 && $attackerarmor>0)
		{
			$rating_change=round($targetinfo['rating']*.1);
			$armor_lost = $playerinfo['armour_pts'] - $attackerarmor;
			$fighters_lost = $playerinfo['ship_fighters'] - $attackerfighters;
			$energy=$playerinfo['ship_energy'];
			$target_rating_change=round($targetinfo['rating']/2);
			$target_armor_lost = $targetinfo['armour_pts'] - $targetarmor;
			$target_fighters_lost = $targetinfo['ship_fighters'] - $targetfighters;
			$target_energy=$targetinfo['ship_energy'];
			playerlog($playerinfo['ship_id'], LOG_RAW, "Attack failed, $targetinfo[character_name] survived."); 
			playerlog($targetinfo['ship_id'], LOG_ATTACK_WIN, "NPC $playerinfo[character_name]|$target_armor_lost|$target_fighters_lost");
			$db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$energy,ship_fighters=ship_fighters-$fighters_lost, torps=torps-$attackertorps,armour_pts=armour_pts-$armor_lost, rating=rating-$rating_change WHERE ship_id=$playerinfo[ship_id]");
			$db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$target_energy,ship_fighters=ship_fighters-$target_fighters_lost, armour_pts=armour_pts-$target_armor_lost, torps=torps-$targettorpnum, rating=$target_rating_change WHERE ship_id=$targetinfo[ship_id]");
		}

		// *********************************
		// *** ATTACKER SHIP DESTROYED	 ***
		// *********************************
		if(!$attackerarmor>0)
		{
			playerlog($playerinfo['ship_id'], LOG_RAW, "$targetinfo[character_name] destroyed your ship!"); 
			db_kill_player($playerinfo['ship_id']);
			$NPCisdead = 1;
			if($targetarmor>0)
			{
				// ****** TARGET STILL ALIVE TO SALVAGE ATTACKER ******
				$rating_change=round($playerinfo['rating']*$rating_combat_factor);
				$free_ore = round($playerinfo['ship_ore']/2);
				$free_organics = round($playerinfo['ship_organics']/2);
				$free_goods = round($playerinfo['ship_goods']/2);
				$free_holds = NUM_HOLDS($targetinfo['hull']) - $targetinfo['ship_ore'] - $targetinfo['ship_organics'] - $targetinfo['ship_goods'] - $targetinfo['ship_colonists'];
				if($free_holds > $free_goods) 
				{																												//****** FIGURE OUT WHAT TARGET CAN CARRY ******
					$salv_goods=$free_goods;
					$free_holds=$free_holds-$free_goods;
				}
				elseif($free_holds > 0)
				{
					$salv_goods=$free_holds;
					$free_holds=0;
				}
				else
				{
					$salv_goods=0;
				}
				if($free_holds > $free_ore)
				{
					$salv_ore=$free_ore;
					$free_holds=$free_holds-$free_ore;
				}
				elseif($free_holds > 0)
				{
					$salv_ore=$free_holds;
					$free_holds=0;
				}
				else
				{
					$salv_ore=0;
				}
				if($free_holds > $free_organics)
				{
					$salv_organics=$free_organics;
					$free_holds=$free_holds-$free_organics;
				}
				elseif($free_holds > 0)
				{
					$salv_organics=$free_holds;
					$free_holds=0;
				}
				else
				{
					$salv_organics=0;
				}
				$ship_value=$upgrade_cost*(round(mypw($upgrade_factor, $playerinfo['hull']))+round(mypw($upgrade_factor, $playerinfo['engines']))+round(mypw($upgrade_factor, $playerinfo['power']))+round(mypw($upgrade_factor, $playerinfo['computer']))+round(mypw($upgrade_factor, $playerinfo['sensors']))+round(mypw($upgrade_factor, $playerinfo['beams']))+round(mypw($upgrade_factor, $playerinfo['torp_launchers']))+round(mypw($upgrade_factor, $playerinfo['shields']))+round(mypw($upgrade_factor, $playerinfo['armor']))+round(mypw($upgrade_factor, $playerinfo['cloak'])));
				$ship_salvage_rate=rand(10,20);
				$ship_salvage=$ship_value*$ship_salvage_rate/100;
				playerlog($targetinfo['ship_id'], LOG_ATTACK_WIN, "NPC $playerinfo[character_name]|$armor_lost|$fighters_lost");
				playerlog($targetinfo['ship_id'], LOG_RAW, "You destroyed the NPC ship and salvaged $salv_ore units of ore, $salv_organics units of organics, $salv_goods units of goods, and salvaged $ship_salvage_rate% of the ship for $ship_salvage credits.");
				$db->Execute ("UPDATE {$db_prefix}ships SET ship_ore=ship_ore+$salv_ore, ship_organics=ship_organics+$salv_organics, ship_goods=ship_goods+$salv_goods, credits=credits+$ship_salvage WHERE ship_id=$targetinfo[ship_id]");
				$armor_lost = $targetinfo['armour_pts'] - $targetarmor;
				$fighters_lost = $targetinfo['ship_fighters'] - $targetfighters;
				$energy=$targetinfo['ship_energy'];
				$db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$energy,ship_fighters=ship_fighters-$fighters_lost, torps=torps-$targettorpnum,armour_pts=armour_pts-$armor_lost, rating=rating-$rating_change WHERE ship_id=$targetinfo[ship_id]");
			}
		}

		// *********************************
		// *** END OF npc_to_ship SUB ***
		// *********************************
	}
}

?>
