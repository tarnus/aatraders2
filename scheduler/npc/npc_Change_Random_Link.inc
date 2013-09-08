<?
if (!function_exists('npc_Change_Random_Link')) {

	function npc_Change_Random_Link()
	{
		global $playerinfo;
		global $db, $dbtables;
		global $link_max;
		global $sector_max;

		// actions:
		// 1 = change random link
		// 2 = add new random link
		// 3 = delete random link

		$res = $db->Execute("SELECT allow_warpedit,{$db_prefix}universe.zone_id FROM {$db_prefix}zones,{$db_prefix}universe WHERE sector_id=$playerinfo[sector] AND {$db_prefix}universe.zone_id={$db_prefix}zones.zone_id");
		$zoneinfo = $res->fields;
		if($zoneinfo['allow_warpedit'] != 'Y')
		{
			return;
		}

		$action = rand(1,3);
		$res = $db->Execute("SELECT * FROM {$db_prefix}links WHERE link_start='$playerinfo[sector]'");
		$prev = $playerinfo[sector]-1;
		$next = $playerinfo[sector]+1;
		if ($res>0)
		{
			if ($res->RecordCount() >= $link_max)
			{
				$action = 3; // delete link if there is the max.
			}
			if ($res->RecordCount() == 0)
			{ // add link if there are none.
				$action = 2;
			}

			switch ($action)
			{
				 default: // not needed, but just in case.
				 case 1: // change link
					$linktochange = rand(1, $res->RecordCount());
					$i = 1;
					while (!$res->EOF)
					{
						if ($i == $linktochange)
						{
							$row = $res->fields;
							if (($row['link_dest'] == $prev) || ($row['link_dest'] == $next))
							{
								break;
							}
							$newdest = rand(0,$sector_max);
							$db->Execute("UPDATE {$db_prefix}links SET link_dest=$newdest WHERE link_id = $row[link_id]");
							echo "$playerinfo[character_name] changing warp to $row[link_dest] to $newdest in sector $playerinfo[sector]<br>\n";
							adminlog(LOG_RAW, "$playerinfo[character_name] CHANGED a warp path from $row[link_dest] to $newdest in sector $playerinfo[sector]");
							break;
						}
						$i++;
						$res->MoveNext();
					}
				break;

				case 2: // add new link
					$newdest = rand(0,$sector_max);
					$db->Execute("INSERT INTO {$db_prefix}links SET link_start=$playerinfo[sector], link_dest=$newdest");
					echo "$playerinfo[character_name] adding warp to $newdest in sector $playerinfo[sector]<br>\n";
					adminlog(LOG_RAW, "$playerinfo[character_name] CREATED a warp path to $newdest in sector $playerinfo[sector]");
				break;

				case 3: // delete link
					$i = 1;
					$linktodelete = rand(1, $res->RecordCount());
					while (!$res->EOF)
					{
						if ($i == $linktodelete)
						{
							$row = $res->fields;
							// don't delete links to prev or next sectors
							if (($row['link_dest'] == $prev) || ($row['link_dest'] == $next))
							{
								break;
							}
							$newdest = rand(0,$sector_max);
							$db->Execute("DELETE FROM {$db_prefix}links WHERE link_id = $row[link_id]");
							echo "$playerinfo[character_name] deleting warp to $row[link_dest] in sector $playerinfo[sector]<br>\n";
							adminlog(LOG_RAW, "$playerinfo[character_name] DELETED a warp path to $row[link_dest] in sector $playerinfo[sector]");
							break;
						}
						$i++;
						$res->MoveNext();
					}
				break;
			}
		}
	}
}


?>
