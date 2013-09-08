<?php
// 2: Sector
// This tool will allow you to change information about any sector.

get_post_ifset("sg_sector, sector, operation, sector_name, zone_id, x, y, z, beacon, port_type");

echo "<tr><td>";
echo "<FORM ACTION=\"admin.php\" METHOD=\"POST\">";
if (empty($sector))
{
	echo "<TABLE BORDER=\"1\" CELLSPACING=\"2\" CELLPADDING=\"2\" width=\"100%\" align=\"center\">";
	echo "<TR><TD align=\"center\" nowrap>";
	echo "<SELECT SIZE=\"20\" NAME=\"sector\">";
	$res = $db->Execute("SELECT sector_id, sector_name FROM {$db_prefix}universe ORDER BY sector_name ASC");
	while (!$res->EOF)
	{
		$row = $res->fields;
		if ($row['sector_id'] > 2)
		{
			echo "<OPTION VALUE=\"$row[sector_id]\"> $row[sector_name] </option>";
		}
		$res->MoveNext();
	}
	echo "</SELECT>";
	echo "<br><div align=\"center\"><INPUT TYPE=\"SUBMIT\" VALUE=\"Edit\"></div>";
	echo "</td></tr></TABLE>";
}
else
{
	if (empty($operation))
	{
		$res = $db->Execute("SELECT * FROM {$db_prefix}universe WHERE sector_id=$sector");
		$row = $res->fields;
		echo "<TABLE BORDER=\"1\" CELLSPACING=\"2\" CELLPADDING=\"2\" width=\"100%\" align=\"center\">";
		echo "<TR><TD align=\"center\" nowrap>Sector ID</TD><TD align=\"center\"><FONT COLOR=\"#66FF00\">$sector</FONT></TD>";
		echo "<TD ALIGN=\"center\" nowrap>Sector Name</TD><TD><INPUT TYPE=\"TEXT\" SIZE=\"30\" NAME=\"sector_name\" VALUE=\"$row[sector_name]\"></TD>";
		echo "<TD ALIGN=\"center\" nowrap>Zone ID</TD><TD>";
		echo "<SELECT SIZE=\"1\" NAME=\"zone_id\">";
		$ressubb = $db->Execute("SELECT zone_id,zone_name FROM {$db_prefix}zones ORDER BY zone_name");
		while (!$ressubb->EOF)
		{
			$rowsubb = $ressubb->fields;
			if ($rowsubb['zone_id'] == $row['zone_id'])
			{ 
				echo "<OPTION VALUE=\"$rowsubb[zone_id]\" SELECTED>$rowsubb[zone_name]</option>";
			} 
			else 
			{ 
				echo "<OPTION VALUE=\"$rowsubb[zone_id]\">$rowsubb[zone_name]</option>";
			}

			$ressubb->MoveNext();
		}

		echo "</SELECT></TD></TR>";
		echo "<TR><TD ALIGN=\"center\">Beacon</TD><TD COLSPAN=3><INPUT TYPE=\"TEXT\" SIZE=\"55\" NAME=\"beacon\" VALUE=\"$row[beacon]\"></TD>";
		echo "<TD ALIGN=\"center\" nowrap>SG Sector</TD><TD><INPUT TYPE=\"TEXT\" SIZE=\"10\" NAME=\"sg_sector\" VALUE=\"$row[sg_sector]\"></TD></TR>";
		echo "<TR><TD ALIGN=\"center\">X</TD><TD><INPUT TYPE=\"TEXT\" SIZE=\"9\" NAME=\"x\" VALUE=\"$row[x]\"></TD>";
		echo "<TD ALIGN=\"center\">Y</TD><TD><INPUT TYPE=\"TEXT\" SIZE=\"9\" NAME=\"y\" VALUE=\"$row[y]\"></TD>";
		echo "<TD ALIGN=\"center\">Z</TD><TD><INPUT TYPE=\"TEXT\" SIZE=\"9\" NAME=\"z\" VALUE=\"$row[z]\"></TD></TR>";
		echo "</TABLE>";

		echo "<TABLE BORDER=\"1\" CELLSPACING=\"2\" CELLPADDING=\"2\" width=\"100%\">";
		echo "<TR><TD ALIGN=\"center\" nowrap>Port Type</TD><TD>";
		echo "<SELECT SIZE=\"1\" NAME=\"port_type\">";

		$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 and cargosellbuy != 1 order by defaultcargoplanet DESC");
		db_op_result($cargo_query,__LINE__,__FILE__);

		while (!$cargo_query->EOF) 
		{
			$cargo_info = $cargo_query->fields;
			$selected = "";
			if($cargo_info['classname'] == $row['port_type'])
			{
				$selected = "selected";
			}
			echo "<OPTION value=\"" . $cargo_info['classname'] . "\" $selected>" . ucwords($cargo_info['classname']) . "</option>";

			$cargo_query->Movenext();
		}
		$cargo_query->close();

		$oportnon = $oportcasino = $oportdevices = $oportupgrades = $oportspacedock = ""; 

		if ($row['port_type'] == "upgrades") $oportupgrades = "SELECTED";
		if ($row['port_type'] == "devices") $oportdevices = "SELECTED";
		if ($row['port_type'] == "spacedock") $oportspacedock = "SELECTED";
		if ($row['port_type'] == "casino") $oportcasino = "SELECTED";

		echo "<OPTION value=\"upgrades\" $oportupgrades>upgrades</option>";
		echo "<OPTION value=\"devices\" $oportdevices>devices</option>";
		echo "<OPTION value=\"spacedock\" $oportspacedock>spacedock</option>";
		echo "<OPTION value=\"casino\" $oportcasino>casino</option>";
		echo "</SELECT></TD></tr>";
		echo "<tr><td colspan=\"2\"><BR>";
		echo "<INPUT TYPE=\"HIDDEN\" NAME=\"sector\" VALUE=\"$sector\">";
		echo "<INPUT TYPE=\"HIDDEN\" NAME=\"operation\" VALUE=\"save\">";
		echo "<div align=\"center\"><INPUT TYPE=\"SUBMIT\" SIZE=\"1\" VALUE=\"Save\"></div>";
		echo "</td></tr></TABLE>";
	}
	elseif ($operation == "save")
	{
		// update database
		$debug_query = $db->Execute("UPDATE {$db_prefix}universe SET sector_name=" . $db->qstr($sector_name) . ",zone_id='$zone_id',beacon='$beacon',port_type='$port_type',z='$z',x='$x',y='$y', sg_sector='$sg_sector' WHERE sector_id=$sector");
		db_op_result($debug_query,__LINE__,__FILE__);
		echo "<INPUT TYPE=\"SUBMIT\" VALUE=\"Return to Sector editor\">";
		$button_main = false;
	}
	else
	{
		echo "Invalid operation";
	}
}
echo "<INPUT TYPE=\"HIDDEN\" NAME=\"menu\" VALUE=\"Editor_Sector\">";
echo "  <input type=\"hidden\" name=\"game_number\" value=\"$game_number\">\n";
echo "<INPUT TYPE=\"HIDDEN\" NAME=\"admin_password\" VALUE=\"$admin_password\">";
echo "</FORM></td></tr>";
?>
