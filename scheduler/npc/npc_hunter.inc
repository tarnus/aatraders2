<?php

include("scheduler/npc/npc_to_sector_defense.inc");
include("scheduler/npc/npc_to_planet.inc");
include("scheduler/npc/npc_to_ship.inc");

if (!function_exists('npc_hunter')) {

	function npc_hunter()
	{
		// *********************************
		// *** SETUP GENERAL VARIABLES	****
		// *********************************
		global $playerinfo;
		global $targetlink;
		global $NPCisdead;
		global $db, $dbtables;

		// JP: check if special killer NPC...
		if (strncasecmp("Attack ", $playerinfo['ship_name'], 7) == 0)
		{
			$killerNPC = true;
		}
		else
		{
			$killerNPC = false;
		}

		$rescount = $db->Execute("SELECT COUNT(*) AS num_players FROM {$db_prefix}ships WHERE ship_destroyed='N' and email NOT LIKE '%@NPC' and ship_id > 1");
		$rowcount = $rescount->fields;
		$topnum = min(10,$rowcount['num_players']);

		// *** IF WE HAVE KILLED ALL THE PLAYERS IN THE GAME THEN THERE IS LITTLE POINT IN PROCEEDING ***
		if ($topnum<1)
		{
			return;
		}

		// JP: check if special killer NPC...
		if ($killerNPC == true)
		{
			$name = str_replace("'", "\\'", substr($playerinfo['ship_name'], 7));
			$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE ship_destroyed='N' and character_name = '$name'");
			if ($res>0 && !$res->EOF)
			{
				$targetinfo=$res->fields;
				echo "*** Found target $name<br>\n";
				if ($targetinfo['on_planet'] == 'Y')
				{
					echo "*** Target $name is hiding on a planet in sector $targetinfo[sector]. I will wait.<br>\n";
					$targetinfo = 0;
				}
				else
				{
					echo "*** Attempting to attack $name<br>\n";
				}
			}
			else
			{
				echo "*** Could not find Target $name!<br>\n";
			}
		}
		else
		{
			$res = $db->Execute("SELECT * FROM {$db_prefix}ships WHERE ship_destroyed='N' and email NOT LIKE '%@NPC' and ship_id > 1 ORDER BY score DESC LIMIT $topnum");

			// *** LETS CHOOSE A TARGET FROM THE TOP PLAYER LIST ***
			$i=1;
			$targetnum=rand(1,$topnum);
			while (!$res->EOF)
			{
				if ($i==$targetnum)
				{ 
					$targetinfo=$res->fields;
					break;
				}
				$i++;
				$res->MoveNext();
			}
		}
		// *** Make sure we have a target ***
		if (!$targetinfo)
		{
			playerlog($playerinfo['ship_id'], LOG_RAW, "Hunt Failed: No Target ");
			return;
		}

		// *********************************
		// *** WORM HOLE TO TARGET SECTOR **
		// *********************************
		$sectres = $db->Execute ("SELECT sector_id,zone_id FROM {$db_prefix}universe WHERE sector_id='$targetinfo[sector]'");
		$sectrow = $sectres->fields;
		$zoneres = $db->Execute ("SELECT zone_id,allow_attack FROM {$db_prefix}zones WHERE zone_id=$sectrow[zone_id]");
		$zonerow = $zoneres->fields;
		// *** ONLY WORM HOLE TO TARGET IF WE CAN ATTACK IN TARGET SECTOR ***
		if ($zonerow['allow_attack']=="Y" && $targetinfo['on_planet'] == "N")
		{
			$stamp = date("Y-m-d H-i-s");
			$query="UPDATE {$db_prefix}ships SET turns_used=turns_used+1, sector=$targetinfo[sector] where ship_id=$playerinfo[ship_id]";
			$move_result = $db->Execute ("$query");
			playerlog($playerinfo[ship_id], LOG_RAW, "NPC used a wormhole to warp to sector $targetinfo[sector] where he is hunting player $targetinfo[character_name]."); 
			if (!$move_result)
			{
				$error = $db->ErrorMsg();
				playerlog($playerinfo['ship_id'], LOG_RAW, "Move failed with error: $error "); 
				return;
			}
			// *********************************
			// *** CHECK FOR SECTOR DEFENCE ****
			// *********************************
			$resultf = $db->Execute ("SELECT * FROM {$db_prefix}sector_defence WHERE sector_id=$targetinfo[sector] and defence_type ='F' ORDER BY quantity DESC");
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
			$resultm = $db->Execute ("SELECT * FROM {$db_prefix}sector_defence WHERE sector_id=$targetinfo[sector] and defence_type ='M'");
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
			//*** DEST LINK HAS DEFENCES ***
			{
				// *** ATTACK SECTOR DEFENCES ***
				$targetlink = $targetinfo['sector'];
				npc_to_sector_defense();
			}
			if ($NPCisdead>0)
			{
				// *** SECTOR DEFENSES KILLED US ***
				return;
			}

			// *** TIME TO ATTACK THE TARGET ***
			playerlog($playerinfo['ship_id'], LOG_RAW, "NPC launching an attack on $targetinfo[character_name]."); 
//			PlayerLogFile("NPC $playerinfo[character_name] attacked $targetinfo[character_name] in sector $targetinfo[sector].");

			// *** SEE IF TARGET IS ON A PLANET ***
			if ($targetinfo['on_planet'] == "Y")
			{
				// *** ON A PLANET ***
				npc_to_planet($targetinfo['planet_id'],$targetinfo['character_name']);
			}
			else
			{
				// *** NOT ON A PLANET ***
				npc_to_ship($targetinfo['ship_id']);
			}
		}
		else
		{
			echo "NPC hunt failed, target $targetinfo[character_name] was in a no attack zone (sector $targetinfo[sector]).<br>\n";
			playerlog($playerinfo['ship_id'], LOG_RAW, "NPC hunt failed, target $targetinfo[character_name] was in a no attack zone (sector $targetinfo[sector]).");
		}
	}
}

?>
