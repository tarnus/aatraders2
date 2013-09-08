<H1>{$l_sn_title}</H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>


{if $num_notes < 1}

<FORM ACTION=sector_notes.php METHOD=POST>
	{$l_pr_clicktosort}<BR><BR>
	{$l_pr_warning}<BR><BR>
	<TABLE  BORDER=0 CELLSPACING=0 CELLPADDING=2 align="center">
	<TR BGCOLOR="{$color_header}" VALIGN=BOTTOM align="center">
	<td>&nbsp;</td><td>{$l_sn_hdtype}</td><td>&nbsp;</td><td>{$l_sn_hdowner}</td><td>&nbsp;</td><td>&nbsp;</td></tr><TR BGCOLOR="{$color_header}" VALIGN=BOTTOM align="center">
	<td>Search</td><td><select name=type>
	<option value="">N/A</option>
	{if $type=="Ally"}
	<option value="Ally" selected>{$l_sn_ally}</option>
	{else}
	<option value="Ally" >{$l_sn_ally}</option>
	{/if}
	{if $type=="Base"}
	<option value="Base" selected>{$l_sn_base}</option>
	{else}
	<option value="Base">{$l_sn_base}</option>
	{/if}
	{if $type=="Enemy"}
	<option value="Enemy" selected>{$l_sn_enemy}</option>
	{else}
	<option value="Enemy">{$l_sn_enemy}</option>
	{/if}
	{if $type=="Indy"}
	<option value="Indy" selected>{$l_sn_indy}</option>
	{else}
	<option value="Indy">{$l_sn_indy}</option>
	{/if}
	{if $type=="Port"}
	<option value="Port" selected>{$l_sn_port}</option>
	{else}
	<option value="Port">{$l_sn_port}</option>
	{/if}
	{if $type=="Team Base"}
	<option value="Team Base" selected>{$l_sn_teambase}</option>
	{else}
	<option value="Team Base">{$l_sn_teambase}</option>
	{/if}
	{if $type=="Minefield"}
	<option value="Minefield" selected>{$l_sn_minefield}</option>
	{else}
	<option value="Minefield">{$l_sn_minefield}</option>
	{/if}
	{if $type=="SG Entry"}
	<option value="SG Entry" selected>{$l_sn_sg_entry}</option>
	{else}
	<option value="SG Entry">{$l_sn_sg_entry}</option>
	{/if}
	{if $type=="Spy Sector"}
	<option value="Spy Sector" selected>{$l_sn_spysector}</option>
	{else}
	<option value="Spy Sector">{$l_sn_spysector}</option>
	{/if}	

	
</select></td><td>&nbsp;</td><td><input name=search type=text width="30" value="{$search}"></td><td>&nbsp;</td><td><input type="Submit" value="GO"></td>
	</tr>
	</table><br>
	<BR>{$l_sn_nonotes}
{else}
	<BR>
	
	
	<FORM ACTION=sector_notes.php METHOD=POST>

	<TABLE  BORDER=0 CELLSPACING=0 CELLPADDING=2 align="center">
	<TR BGCOLOR="{$color_header}" VALIGN=BOTTOM align="center">
	<td>&nbsp;</td><td>{$l_sn_hdtype}</td><td>&nbsp;</td><td>{$l_sn_hdowner}</td><td>&nbsp;</td><td>&nbsp;</td></tr><TR BGCOLOR="{$color_header}" VALIGN=BOTTOM align="center">
	<td>Search</td><td><select name=type>
	<option value="">N/A</option>
	{if $type=="Ally"}
	<option value="Ally" selected>{$l_sn_ally}</option>
	{else}
	<option value="Ally" >{$l_sn_ally}</option>
	{/if}
	{if $type=="Base"}
	<option value="Base" selected>{$l_sn_base}</option>
	{else}
	<option value="Base">{$l_sn_base}</option>
	{/if}
	{if $type=="Enemy"}
	<option value="Enemy" selected>{$l_sn_enemy}</option>
	{else}
	<option value="Enemy">{$l_sn_enemy}</option>
	{/if}
	{if $type=="Indy"}
	<option value="Indy" selected>{$l_sn_indy}</option>
	{else}
	<option value="Indy">{$l_sn_indy}</option>
	{/if}
	{if $type=="Port"}
	<option value="Port" selected>{$l_sn_port}</option>
	{else}
	<option value="Port">{$l_sn_port}</option>
	{/if}
	{if $type=="Team Base"}
	<option value="Team Base" selected>{$l_sn_teambase}</option>
	{else}
	<option value="Team Base">{$l_sn_teambase}</option>
	{/if}
	{if $type=="Minefield"}
	<option value="Minefield" selected>{$l_sn_minefield}</option>
	{else}
	<option value="Minefield">{$l_sn_minefield}</option>
	{/if}
	{if $type=="SG Entry"}
	<option value="SG Entry" selected>{$l_sn_sg_entry}</option>
	{else}
	<option value="SG Entry">{$l_sn_sg_entry}</option>
	{/if}
	{if $type=="Spy Sector"}
	<option value="Spy Sector" selected>{$l_sn_spysector}</option>
	{else}
	<option value="Spy Sector">{$l_sn_spysector}</option>
	{/if}	

	
</select></td><td>&nbsp;</td><td><input name=search type=text width="30" value="{$search}"></td><td>&nbsp;</td><td><input type="Submit" value="GO"></td>
	</tr>
	</table><br>
	<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="{$color_header}" VALIGN=BOTTOM>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=galaxyname>{$l_galaxy}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=date>{$l_sn_notedate}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=sector_id>{$l_sn_hdsector}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=type>{$l_sn_hdtype}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=owner>{$l_sn_hdowner}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=planets>{$l_sn_hdplanets}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=port>{$l_sn_hdport}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=fighters>{$l_sn_hdfighters}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=mines>{$l_sn_hdmines}</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type={$type}&sort=scanfrom>{$l_sn_hdscanfrom}</A>&nbsp;</B></font></TD>

<TD ALIGN=CENTER><font size=2><B>&nbsp;{$l_sn_hddetail}&nbsp;</B></font></TD>
	{if $playerteam > 0}
		<TD ALIGN=RIGHT><font size=2><B>&nbsp;{$l_sn_hdteam}&nbsp;</B></font></TD>
	{/if}
<TD ALIGN=CENTER><font size=2><B>&nbsp;{$l_sn_hddelete}&nbsp;</B></font></TD>	
	</TR>
	{php}
function strip_places($itemin){

$places = explode(",", $itemin);
if (count($places) <= 1){
	return $itemin;
}
else
{
	$places[1] = AAT_substr($places[1], 0, 2);
	$placecount=count($places);

	switch ($placecount){
		case 2:
			return "$places[0].$places[1] K";
			break;
		case 3:
			return "$places[0].$places[1] M";
			break;	
		case 4:
			return "$places[0].$places[1] B";
			break;	
		case 5:
			return "$places[0].$places[1] T";
			break;
		case 6:
			return "$places[0].$places[1] Qd";
			break;		
		case 7:
			return "$places[0].$places[1] Qn";
			break;
		case 8:
			return "$places[0].$places[1] Sx";
			break;
		case 9:
			return "$places[0].$places[1] Sp";
			break;
		case 10:
			return "$places[0].$places[1] Oc";
			break;
		}		
	
}

}
{/php}
	{php}
	$color = $color_line1;
	for($i=0; $i<$num_notes; $i++)
	{
		echo "<TR BGCOLOR=\"$color\">";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;$galaxy_name[$i]&nbsp;</font></TD>";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;$dateposted[$i]&nbsp;</font></TD>";
		if($shipgalaxyname == $galaxy_name[$i])
		{
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;<A HREF=main.php?move_method=real&engage=1&destination=". rawurlencode($sector[$i]) . ">". $sector[$i] ."</A>&nbsp;</font></TD>";
		}else{
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;". $sector[$i] ."&nbsp;</font></TD>";
		}
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $sector_type[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=center><font size=2>&nbsp;" . $sector_owner[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=center><font size=2>&nbsp;" . $sector_planets[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=center><font size=2>&nbsp;" . $sector_port[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;";
		echo strip_places($sector_fighters[$i] ) . "&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;";
		echo strip_places($sector_mines[$i]) . "&nbsp;</font></TD>";
		if ($sector_scanfrom[$i]!=""){
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;<A HREF=main.php?move_method=real&engage=1&destination=". rawurlencode($sector_scanfrom[$i]) . ">". $sector_scanfrom[$i] ."</A>&nbsp;</font></TD>";
		}else{
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;N/A&nbsp;</font></TD>";
		}
		
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;<A HREF=sector_notes.php?command=".$l_sn_view."&sector=". rawurlencode($sector[$i]) . ">{$l_sn_view}</a>&nbsp;</font></TD>";

		if ($playerteam > 0){
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . ($notes_team[$i] > 0 ? "$l_sn_yes" : "$l_sn_no") . "&nbsp;</font></TD>";
			
		}
			if ($note_player_id[$i]==$playerid || $playerid==$playerteam){
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;<INPUT TYPE=CHECKBOX NAME=Del[] VALUE=\"" . $notelistid[$i] . "\">" . "&nbsp;</font></TD>";
			}else{
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;<INPUT TYPE=CHECKBOX NAME=Del[] VALUE=\"" . $notelistid[$i] . "\" disabled>" . "&nbsp;</font></TD>";
			}
		echo "</TR>";

		if ($color == $color_line1)
		{
			$color = $color_line2;
		}
		else
		{
			$color = $color_line1;
		}
	}
{/php}
	<tr bgcolor="{$color_line2}">
	<td colspan="9">&nbsp;</td>
	{php}
		if ($playerteam > 0){
			echo "<TD ALIGN=CENTER>&nbsp;</TD>";
			
		}
	{/php}	
	<td align="center"><INPUT TYPE=SUBMIT VALUE="{$l_sn_delete}"></td>
</tr>
	</TABLE>
{/if}

</td></tr>

<tr><td><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
