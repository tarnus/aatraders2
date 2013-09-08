<?php
// 1
// 0
// 5
// 0
// Y
// How often NPC Players play the game.

// enable schedule - 0 disable schedule, 1 enable schedule
// execution order - the order of execution
// ticks full - how many minues between each execution
// loop_count - the number of times to execute schedule before deleting
// is_loop - "Y" loop enlessly, "N" - execute the number of times indocated by spawn value
// extra info - description of the schedule

if($alliance_enabled == 1)
{
	TextFlush ( "<b>NPC Characters Playing</b><br>\n");
	include("scheduler/npc/npc_move.inc");
	include("scheduler/npc/searchSector.inc");
	// Grab active NPC Players with intact ships from database
	$res = $db->Execute("SELECT * FROM {$db_prefix}players LEFT JOIN {$db_prefix}npc_player ON " .
						"{$db_prefix}players.player_id = {$db_prefix}npc_player.npc_id LEFT JOIN " .
						"{$db_prefix}ships ON {$db_prefix}players.currentship = {$db_prefix}ships.ship_id " .
						"WHERE {$db_prefix}npc_player.active='Y' ORDER BY {$db_prefix}ships.sector_id");
	db_op_result($res,__LINE__,__FILE__);
	$totalnpc = $res->RecordCount();
     
	if($totalnpc < $alliance_minimum)
	{
		include("scheduler/npc/generate_new_npc.inc");
		for($i = 1; $i <= ($alliance_minimum - $totalnpc); $i++)
		{
			generate_new_npc();
			$totalnpc++;
		}
	}

	if($totalnpc < $alliance_maximum)
	{
		include("scheduler/npc/generate_new_npc.inc");
		for($i = 1; $i <= ($alliance_maximum - $totalnpc); $i++)
		{
			if(mt_rand(1, 1000) < 10)
			{
				generate_new_npc();
				$totalnpc++;
			}
		}
	}

/*
	npc_regeneration();

	// Clear Counter Variables
	$count = array(
		sentinal=>0,
		roam=>0,
		trader=>0,
		hunter=>0,
		moodchange=>0,
		upgrade=>0,
		planet_upgrade=>0,
		disobeyed=>0,
		total=>0
	);

	// Loop through each NPC Player
	while(!$res->EOF)
	{
		$npc_isdead = 0;
	    $playerinfo = $res->fields;
		$shipres = $db->Execute("SELECT * FROM {$db_prefix}ships, {$db_prefix}npc_player " .
						"WHERE {$db_prefix}npc_player.npc_id=$playerinfo[player_id] AND {$db_prefix}npc_player.active='Y' AND {$db_prefix}players.ships=$playerinfo[currentship]");
		db_op_result($shipres,__LINE__,__FILE__);

	    $shipinfo = $shipres->fields;

		$result2 = $db->SelectLimit("SELECT {$db_prefix}universe.* FROM {$db_prefix}universe WHERE sector_id='$shipinfo[sector_id]'", 1);
		db_op_result($result2,__LINE__,__FILE__);
		$sectorinfo = $result2->fields;
		$result2->close();

		$basename = $sectorinfo['port_type'];

		if($basename == "spacedock")
		{
			$portname = $l_spacedock;
// no function yet			npc_repair();
		}
		else if ($basename == "devices")
		{
// no function yet			npc_device_buy();
		}
		else if ($basename == "upgrades")
		{
			// 5% chance of visiting a special to upgrade
			if (rand(1,20) == 1)
			{
//				include("scheduler/npc/upgrade.inc");
//				upgrade($playerinfo);
				$count['upgrade']++;
			}
		}
		else
		{
			$portname = get_commodity_name($sectorinfo['port_type']);
		}

		// 1% chance of upgrading their planets
		if (rand(1,100) == 1)
		{
//			include("scheduler/npc/planet_upgrade.inc");
//			planet_upgrade($playerinfo);
			$count['planet_upgrade']++;
		}

		// 1% chance of disobeying orders for this turn
		if (rand(1,100) == 1)
		{
			$playerinfo['orders']=rand(0,3);
			$count['disobeyed']++;
		}

		// 1% chance of a mood change
		if (rand(1,100) == 1)
		{
			$playerinfo['aggression']=rand(0,2);
			$count['moodchange']++;		
		}

		switch($playerinfo['orders'])
		{
			case"0": // SENTINAL NPC
				$count['sentinal']++;
//				searchSector();
			break;		

			case"1": // ROAMING NPC
				$count['roam']++;
				// Move to a new sector
				$targetlink = $playerinfo['sector_id'];
//				npc_move();
				// Search if we're still alive
				if ($npc_isdead==0)
				{
//					searchSector();
				}
			break;

			case"2": // TRADER NPC
//				include("scheduler/npc/npc_trade.inc");
				$count['trader']++;
				// Move to a new sector
				$targetlink = $playerinfo['sector_id'];
//				npc_move();
				// Trade and Search if we're still alive
				if ($npc_isdead==0)
				{
//					npc_trade();
//					searchSector();
				}
			break;

			case"3": // HUNTER NPC
//				include("scheduler/npc/npc_hunter.inc");
				$count['hunter']++;
				// Are we hunting this turn? (20% Chance)
				$hunt=rand(0,3);
				if ($hunt==0)
				{
//					npc_hunter();
					if ($npc_isdead>0)
					{
					  $res->MoveNext();
					  continue;
					}
				}
				else
				{
					// Move to a new sector
					$targetlink = $playerinfo['sector'];
//					npc_move();
					// Search if we're still alive
					if ($npc_isdead==0)
					{
//						searchSector();
					}
				}
			break;
	    }
		$res->MoveNext();
	}
	$res->close();
*/
	TextFlush ( "$totalnpc Active NPC Players<br>");
	TextFlush ( "$count[sentinal] NPC had Sentinal orders<br>");
	TextFlush ( "$count[roam] NPC had Roam orders<br>");
	TextFlush ( "$count[trader] NPC had Trade orders<br>");
	TextFlush ( "$count[hunter] NPC had Hunter orders<br>");
	TextFlush ( "$count[moodchange] NPC had mood changes<br>");
	TextFlush ( "$count[disobeyed] NPC disobeyed their normal orders<br>");
	TextFlush ( "$count[upgrade] NPC upgraded their spaceships<br>");
	TextFlush ( "$count[planet_upgrade] NPC upgraded their planets<br>");
	TextFlush ( "<br>");
}
?>
