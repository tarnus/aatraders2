<?php
include("scheduler/npc/npc_to_sector_defense.inc");

if (!function_exists('npc_move')) {

	function npc_move()
	{
		// *********************************
		// *** SETUP GENERAL VARIABLES	****
		// *********************************
		global $playerinfo;
		global $sector_max;
		global $targetlink;
		global $NPCisdead;
		global $db, $dbtables;

		// *********************************
		// ***** OBTAIN A TARGET LINK ******
		// *********************************
		if ($targetlink==$playerinfo['sector'])
		{
			$targetlink=0;
		}
		$linkres = $db->Execute ("SELECT * FROM {$db_prefix}links WHERE link_start='$playerinfo[sector]'");
		if ($linkres>0)
		{
			while (!$linkres->EOF)
			{
				$row = $linkres->fields;
				// get number of NPC already in sector
				$res = $db->Execute ("SELECT COUNT(*) AS num FROM {$db_prefix}ships WHERE sector='$row[link_dest]' AND email LIKE '%@NPC'");
				// no more than two NPC in a sector
				if ($res->fields[num] < 2)
				{
					// *** OBTAIN SECTOR INFORMATION ***
					$sectres = $db->Execute ("SELECT sector_id,zone_id FROM {$db_prefix}universe WHERE sector_id='$row[link_dest]'");
					$sectrow = $sectres->fields;
					$zoneres = $db->Execute("SELECT zone_id,allow_attack FROM {$db_prefix}zones WHERE zone_id=$sectrow[zone_id]");
					$zonerow = $zoneres->fields;
					if ($zonerow['allow_attack']=="Y")												//*** DEST LINK MUST ALLOW ATTACKING ***
					{
						$setlink=rand(0,2);												//*** 33% CHANCE OF REPLACING DEST LINK WITH THIS ONE ***
						if ($setlink==0 || $targetlink <= 0)					//*** UNLESS THERE IS NO DEST LINK, CHHOSE THIS ONE ***
						{
							$targetlink=$row['link_dest'];
						}
					}
				}
				$linkres->MoveNext();
			}
		}

		// *********************************
		// ***** IF NO ACCEPTABLE LINK *****
		// *********************************
		// **** TIME TO USE A WORM HOLE ****
		// *********************************
		// jp: 30% of the time, use a wormhole to cut down on NPC traps
		if (($targetlink <= 0) || (rand(0,2) == 0))
		{
			// *** GENERATE A RANDOM SECTOR NUMBER ***
			$limitloop=1;												// *** LIMIT THE NUMBER OF LOOPS ***
			while ($targetlink <= 0 && $limitloop < 15)
			{
				$wormto=rand(1,$sector_max);
				$res = $db->Execute ("SELECT COUNT(*) AS num FROM {$db_prefix}ships WHERE sector='$wormto' AND email LIKE '%@NPC'");
				// no more than one NPC in a sector
				if ($res->fields['num'] <= 0)
				{
					// *** OBTAIN SECTOR INFORMATION ***
					$sectres = $db->Execute ("SELECT sector_id,zone_id FROM {$db_prefix}universe WHERE sector_id='$wormto'");
					$sectrow = $sectres->fields;
					$zoneres = $db->Execute ("SELECT zone_id,allow_attack FROM {$db_prefix}zones WHERE zone_id=$sectrow[zone_id]");
					$zonerow = $zoneres->fields;
					if ($zonerow['allow_attack']=="Y")
					{
						$targetlink=$wormto;
						//				playerlog($playerinfo[ship_id], LOG_RAW, "Used a wormhole to warp to a zone where attacks are allowed.");
						break;
					}
				}
				$limitloop++;
			}
		} 

		// *********************************
		// *** CHECK FOR SECTOR DEFENCE ****
		// *********************************
		if ($targetlink > 0)
		{
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
			//*** DEST LINK HAS DEFENCES ***
			{
				if ($playerinfo['aggression'] == 2 || $playerinfo['aggression'] == 1 || !(strstr($playerinfo['character_name'], 'Flag')))
				{
					// *** ATTACK SECTOR DEFENCES ***
					npc_to_sector_defense();
					return;
				}
				else
				{
					playerlog($playerinfo['ship_id'], LOG_RAW, "Move failed, the sector is defended by $total_sector_fighters fighters and $total_sector_mines mines."); 
					return;
				}
			}
		}

		// *********************************
		// **** DO MOVE TO TARGET LINK *****
		// *********************************
		if ($targetlink>0)
		{
			$stamp = date("Y-m-d H-i-s");
			$query="UPDATE {$db_prefix}ships SET turns_used=turns_used+1, turns=turns-1, sector=$targetlink where ship_id=$playerinfo[ship_id]";
			$move_result = $db->Execute ("$query");
			if (!$move_result)
			{
				$error = $db->ErrorMsg();
				playerlog($playerinfo['ship_id'], LOG_RAW, "Move failed with error: $error "); 
			}
			else
			{
				// playerlog($playerinfo['ship_id'], LOG_RAW, "Moved to $targetlink without incident."); 
			}
		}
		else
		{	//*** WE HAVE NO TARGET LINK FOR SOME REASON ***
			playerlog($playerinfo['ship_id'], LOG_RAW, "Move failed due to lack of target link.");
			$targetlink = $playerinfo['sector'];				 //*** RESET TARGET LINK SO IT IS NOT ZERO ***
		}
	}
}

?>
