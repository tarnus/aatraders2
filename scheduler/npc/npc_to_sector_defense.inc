<?php

if (!function_exists('npc_to_sector_defense')) {

	function npc_to_sector_defense()
	{
		// **********************************
		// *** NPC TO SECTOR DEFENCE ***
		// **********************************

		// *********************************
		// *** SETUP GENERAL VARIABLES	****
		// *********************************
		global $playerinfo;
		global $targetlink;
		global $l_sf_sendlog;
		global $l_sf_sendlog2;
		global $l_chm_hehitminesinsector;
		global $l_chm_hewasdestroyedbyyourmines;
		global $NPCisdead;
		global $db, $dbtables;

		// *********************************
		// *** CHECK FOR SECTOR DEFENCE ****
		// *********************************
		if ($targetlink>0)
		{
			//echo "The target link for $playerinfo[character_name] is $targetlink<br>";
			$resultf = $db->Execute ("SELECT * FROM {$db_prefix}sector_defence WHERE sector_id='$targetlink' and defence_type ='F' ORDER BY quantity DESC");
			$i = 0;
			$total_sector_fighters = 0;
			if($resultf > 0)
			{
				while(!$resultf->EOF)
				{
					$defences[$i] = $resultf->fields;
					$total_sector_fighters += $defences[$i]['quantity'];
					$i++;
					$resultf->MoveNext();
				}
			}
			$resultm = $db->Execute ("SELECT * FROM {$db_prefix}sector_defence WHERE sector_id='$targetlink' and defence_type ='M'");
			$i = 0;
			$total_sector_mines = 0;
			if($resultm > 0)
			{
				while(!$resultm->EOF)
				{
					$defences[$i] = $resultm->fields;
					$total_sector_mines += $defences[$i]['quantity'];
					$i++;
					$resultm->MoveNext();
				}
			}
			if ($total_sector_fighters>0 || $total_sector_mines>0 || ($total_sector_fighters>0 && $total_sector_mines>0))
			//*** DEST LINK HAS DEFENCES SO LETS ATTACK THEM***
			{
				playerlog($playerinfo[ship_id], LOG_RAW, "ATTACKING SECTOR DEFENCES $total_sector_fighters fighters and $total_sector_mines mines."); 
				// ************************************
				// *** LETS GATHER COMBAT VARIABLES ***
				// ************************************
				$targetfighters = $total_sector_fighters;
				$playerbeams = NUM_BEAMS($playerinfo['beams']);
				if($playerbeams>$playerinfo['ship_energy']) 
				{
					$playerbeams=$playerinfo['ship_energy'];
				}
				$playerinfo['ship_energy']=$playerinfo['ship_energy']-$playerbeams;
				$playershields = NUM_SHIELDS($playerinfo['shields']);
				if($playershields>$playerinfo['ship_energy'])
				{
					$playershields=$playerinfo['ship_energy'];
				}
				$playertorpnum = round(mypw($level_factor,$playerinfo['torp_launchers']))*2;
				if($playertorpnum > $playerinfo['torps'])
				{
					$playertorpnum = $playerinfo['torps'];
				}
				$playertorpdmg = $torp_dmg_rate*$playertorpnum;
				$playerarmour = $playerinfo['armour_pts'];
				$playerfighters = $playerinfo['ship_fighters'];
				$totalmines = $total_sector_mines;
				if ($totalmines>1)
				{
					$roll = rand(1,$totalmines);
				}
				else
				{
					$roll = 1;
				}
				$totalmines = $totalmines - $roll;
				//$playerminedeflect = $playerinfo[ship_fighters]; // *** NPC keep as many deflectors as fighters ***
				$playerminedeflect = $playerinfo['dev_minedeflector'];

				// *****************************
				// *** LETS DO SOME COMBAT ! ***
				// *****************************
				// *** BEAMS VS FIGHTERS ***
				if($targetfighters > 0 && $playerbeams > 0)
				{
					if($playerbeams > round($targetfighters / 2))
					{
						$temp = round($targetfighters/2);
						$targetfighters = $temp;
						$playerbeams = $playerbeams-$temp;
					}
					else
					{
						$targetfighters = $targetfighters-$playerbeams;
						$playerbeams = 0;
					}	 
				}
				// *** TORPS VS FIGHTERS ***
				if($targetfighters > 0 && $playertorpdmg > 0)
				{
					if($playertorpdmg > round($targetfighters / 2))
					{
						$temp=round($targetfighters/2);
						$targetfighters=$temp;
						$playertorpdmg=$playertorpdmg-$temp;
					}
					else
					{
						$targetfighters=$targetfighters-$playertorpdmg;
						$playertorpdmg=0;
					}
				}
				// *** FIGHTERS VS FIGHTERS ***
				if($playerfighters > 0 && $targetfighters > 0)
				{
					if($playerfighters > $targetfighters)
					{
						echo $l_sf_destfightall;
						$temptargfighters=0;
					}
					else
					{
						$temptargfighters=$targetfighters-$playerfighters;
					}
					if($targetfighters > $playerfighters)
					{
						$tempplayfighters=0;
					}
					else
					{
						$tempplayfighters=$playerfighters-$targetfighters;
					}		 
					$playerfighters=$tempplayfighters;
					$targetfighters=$temptargfighters;
				}
				// *** OH NO THERE ARE STILL FIGHTERS **
				// *** ARMOUR VS FIGHTERS ***
				if($targetfighters > 0)
				{
					if($targetfighters > $playerarmour)
					{
						$playerarmour=0;
					}
					else
					{
						$playerarmour=$playerarmour-$targetfighters;
					} 
				}
				// *** GET RID OF THE SECTOR FIGHTERS THAT DIED ***
				$fighterslost = $total_sector_fighters - $targetfighters;
				destroy_fighters($targetlink,$fighterslost);

				// *** LETS LET DEFENCE OWNER KNOW WHAT HAPPENED *** 
				$l_sf_sendlog1 = str_replace("[player]", "NPC $playerinfo[character_name]", $l_sf_sendlog);
				$l_sf_sendlog2 = str_replace("[lost]", $fighterslost, $l_sf_sendlog1);
				$l_sf_sendlog3 = str_replace("[sector]", $targetlink, $l_sf_sendlog2);
				message_defence_owner($targetlink,$l_sf_sendlog3);

				// *** UPDATE NPC AFTER COMBAT ***
				$armour_lost=$playerinfo['armour_pts']-$playerarmour;
				$fighters_lost=$playerinfo['ship_fighters']-$playerfighters;
				$energy=$playerinfo['ship_energy'];
				$update1 = $db->Execute ("UPDATE {$db_prefix}ships SET ship_energy=$energy,ship_fighters=ship_fighters-$fighters_lost, armour_pts=armour_pts-$armour_lost, torps=torps-$playertorpnum WHERE ship_id=$playerinfo[ship_id]");

				// *** CHECK TO SEE IF NPC IS DEAD ***
				if($playerarmour < 1)
				{
					$l_sf_sendlog2 = str_replace("[player]", "NPC " . $playerinfo['character_name'], $l_sf_sendlog2);
					$l_sf_sendlog2 = str_replace("[sector]", $targetlink, $l_sf_sendlog2);
					message_defence_owner($targetlink,$l_sf_sendlog2);
					cancel_bounty($playerinfo['ship_id']);
					db_kill_player($playerinfo['ship_id']);
					$NPCisdead = 1;
					return;
				}

				// *** OK NPC MUST STILL BE ALIVE ***

				// *** NOW WE HIT THE MINES ***

				// *** LETS LOG THE FACT THAT WE HIT THE MINES ***
				//echo "before - $playerinfo[character_name] hit $roll mines in sector $targetlink<BR>";
				$l_chm_hehitminesinsector1 = str_replace("[chm_playerinfo_character_name]", "NPC " . $playerinfo['character_name'], $l_chm_hehitminesinsector);
				$l_chm_hehitminesinsector2 = str_replace("[chm_roll]", $roll, $l_chm_hehitminesinsector1);
				$l_chm_hehitminesinsector3 = str_replace("[chm_sector]", $targetlink, $l_chm_hehitminesinsector2);
				//echo "after - $l_chm_hehitminesinsector3<br>";
				message_defence_owner($targetlink,"$l_chm_hehitminesinsector3");

				// *** DEFLECTORS VS MINES ***
				if($playerminedeflect >= $roll)
				{
					$playerminedeflect = $playerminedeflect - $roll;
					$update2 = $db->Execute("UPDATE {$db_prefix}ships set dev_minedeflector=$playerminedeflect where ship_id=$playerinfo[ship_id]");
				}
				else
				{
					$mines_left = $roll - $playerminedeflect;
					if ($mines_left < 0)
					{
						$mines_left = 0;
					}
					// *** SHIELDS VS MINES ***
					if($playershields >= $mines_left)
					{
						$update2 = $db->Execute("UPDATE {$db_prefix}ships set ship_energy=ship_energy-$mines_left where ship_id=$playerinfo[ship_id]");
					}
					else
					{
						$mines_left = $mines_left - $playershields;

						// *** ARMOUR VS MINES ***
						if($playerarmour >= $mines_left)
						{
							$update2 = $db->Execute("UPDATE {$db_prefix}ships set armour_pts=armour_pts-$mines_left,ship_energy=0 where ship_id=$playerinfo[ship_id]");
						}
						else
						{
							// *** OH NO WE DIED ***
							// *** LETS LOG THE FACT THAT WE DIED *** 
							$l_chm_hewasdestroyedbyyourmines = str_replace("[chm_playerinfo_character_name]", "NPC " . $playerinfo['character_name'], $l_chm_hewasdestroyedbyyourmines);
							$l_chm_hewasdestroyedbyyourmines = str_replace("[chm_sector]", $targetlink, $l_chm_hewasdestroyedbyyourmines);
							message_defence_owner($targetlink,"$l_chm_hewasdestroyedbyyourmines");
							// *** LETS ACTUALLY KILL THE NPC NOW ***
							cancel_bounty($playerinfo[ship_id]);
							db_kill_player($playerinfo[ship_id]);
							$NPCisdead = 1;
							// *** LETS GET RID OF THE MINES NOW AND RETURN OUT OF THIS FUNCTION ***
							explode_mines($targetlink,$roll);
							return;
						}
					}
				}
				// *** LETS GET RID OF THE MINES NOW ***
				explode_mines($targetlink,$roll);
			}
			else
			{
				//*** FOR SOME REASON THIS WAS CALLED WITHOUT ANY SECTOR DEFENCES TO ATTACK ***
				return;
			}
		}
	}
}

?>
