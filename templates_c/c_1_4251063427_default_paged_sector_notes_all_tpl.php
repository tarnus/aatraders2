<H1><?php echo $this->_vars['l_sn_title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>


<?php if ($this->_vars['num_notes'] < 1): ?>

<FORM ACTION=sector_notes.php METHOD=POST>
	<?php echo $this->_vars['l_pr_clicktosort']; ?><BR><BR>
	<?php echo $this->_vars['l_pr_warning']; ?><BR><BR>
	<TABLE  BORDER=0 CELLSPACING=0 CELLPADDING=2 align="center">
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=BOTTOM align="center">
	<td>&nbsp;</td><td><?php echo $this->_vars['l_sn_hdtype']; ?></td><td>&nbsp;</td><td><?php echo $this->_vars['l_sn_hdowner']; ?></td><td>&nbsp;</td><td>&nbsp;</td></tr><TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=BOTTOM align="center">
	<td>Search</td><td><select name=type>
	<option value="">N/A</option>
	<?php if ($this->_vars['type'] == "Ally"): ?>
	<option value="Ally" selected><?php echo $this->_vars['l_sn_ally']; ?></option>
	<?php else: ?>
	<option value="Ally" ><?php echo $this->_vars['l_sn_ally']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Base"): ?>
	<option value="Base" selected><?php echo $this->_vars['l_sn_base']; ?></option>
	<?php else: ?>
	<option value="Base"><?php echo $this->_vars['l_sn_base']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Enemy"): ?>
	<option value="Enemy" selected><?php echo $this->_vars['l_sn_enemy']; ?></option>
	<?php else: ?>
	<option value="Enemy"><?php echo $this->_vars['l_sn_enemy']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Indy"): ?>
	<option value="Indy" selected><?php echo $this->_vars['l_sn_indy']; ?></option>
	<?php else: ?>
	<option value="Indy"><?php echo $this->_vars['l_sn_indy']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Port"): ?>
	<option value="Port" selected><?php echo $this->_vars['l_sn_port']; ?></option>
	<?php else: ?>
	<option value="Port"><?php echo $this->_vars['l_sn_port']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Team Base"): ?>
	<option value="Team Base" selected><?php echo $this->_vars['l_sn_teambase']; ?></option>
	<?php else: ?>
	<option value="Team Base"><?php echo $this->_vars['l_sn_teambase']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Minefield"): ?>
	<option value="Minefield" selected><?php echo $this->_vars['l_sn_minefield']; ?></option>
	<?php else: ?>
	<option value="Minefield"><?php echo $this->_vars['l_sn_minefield']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "SG Entry"): ?>
	<option value="SG Entry" selected><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
	<?php else: ?>
	<option value="SG Entry"><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Spy Sector"): ?>
	<option value="Spy Sector" selected><?php echo $this->_vars['l_sn_spysector']; ?></option>
	<?php else: ?>
	<option value="Spy Sector"><?php echo $this->_vars['l_sn_spysector']; ?></option>
	<?php endif; ?>	

	
</select></td><td>&nbsp;</td><td><input name=search type=text width="30" value="<?php echo $this->_vars['search']; ?>"></td><td>&nbsp;</td><td><input type="Submit" value="GO"></td>
	</tr>
	</table><br>
	<BR><?php echo $this->_vars['l_sn_nonotes']; ?>
<?php else: ?>
	<BR>
	
	
	<FORM ACTION=sector_notes.php METHOD=POST>

	<TABLE  BORDER=0 CELLSPACING=0 CELLPADDING=2 align="center">
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=BOTTOM align="center">
	<td>&nbsp;</td><td><?php echo $this->_vars['l_sn_hdtype']; ?></td><td>&nbsp;</td><td><?php echo $this->_vars['l_sn_hdowner']; ?></td><td>&nbsp;</td><td>&nbsp;</td></tr><TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=BOTTOM align="center">
	<td>Search</td><td><select name=type>
	<option value="">N/A</option>
	<?php if ($this->_vars['type'] == "Ally"): ?>
	<option value="Ally" selected><?php echo $this->_vars['l_sn_ally']; ?></option>
	<?php else: ?>
	<option value="Ally" ><?php echo $this->_vars['l_sn_ally']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Base"): ?>
	<option value="Base" selected><?php echo $this->_vars['l_sn_base']; ?></option>
	<?php else: ?>
	<option value="Base"><?php echo $this->_vars['l_sn_base']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Enemy"): ?>
	<option value="Enemy" selected><?php echo $this->_vars['l_sn_enemy']; ?></option>
	<?php else: ?>
	<option value="Enemy"><?php echo $this->_vars['l_sn_enemy']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Indy"): ?>
	<option value="Indy" selected><?php echo $this->_vars['l_sn_indy']; ?></option>
	<?php else: ?>
	<option value="Indy"><?php echo $this->_vars['l_sn_indy']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Port"): ?>
	<option value="Port" selected><?php echo $this->_vars['l_sn_port']; ?></option>
	<?php else: ?>
	<option value="Port"><?php echo $this->_vars['l_sn_port']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Team Base"): ?>
	<option value="Team Base" selected><?php echo $this->_vars['l_sn_teambase']; ?></option>
	<?php else: ?>
	<option value="Team Base"><?php echo $this->_vars['l_sn_teambase']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Minefield"): ?>
	<option value="Minefield" selected><?php echo $this->_vars['l_sn_minefield']; ?></option>
	<?php else: ?>
	<option value="Minefield"><?php echo $this->_vars['l_sn_minefield']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "SG Entry"): ?>
	<option value="SG Entry" selected><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
	<?php else: ?>
	<option value="SG Entry"><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
	<?php endif; ?>
	<?php if ($this->_vars['type'] == "Spy Sector"): ?>
	<option value="Spy Sector" selected><?php echo $this->_vars['l_sn_spysector']; ?></option>
	<?php else: ?>
	<option value="Spy Sector"><?php echo $this->_vars['l_sn_spysector']; ?></option>
	<?php endif; ?>	

	
</select></td><td>&nbsp;</td><td><input name=search type=text width="30" value="<?php echo $this->_vars['search']; ?>"></td><td>&nbsp;</td><td><input type="Submit" value="GO"></td>
	</tr>
	</table><br>
	<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=BOTTOM>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=galaxyname><?php echo $this->_vars['l_galaxy']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=sector_id><?php echo $this->_vars['l_sn_hdsector']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=type><?php echo $this->_vars['l_sn_hdtype']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=owner><?php echo $this->_vars['l_sn_hdowner']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=planets><?php echo $this->_vars['l_sn_hdplanets']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=port><?php echo $this->_vars['l_sn_hdport']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=fighters><?php echo $this->_vars['l_sn_hdfighters']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=mines><?php echo $this->_vars['l_sn_hdmines']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=sector_notes.php?type=<?php echo $this->_vars['type']; ?>&sort=scanfrom><?php echo $this->_vars['l_sn_hdscanfrom']; ?></A>&nbsp;</B></font></TD>

<TD ALIGN=CENTER><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hddetail']; ?>&nbsp;</B></font></TD>


	<?php if ($this->_vars['playerteam'] > 0): ?>
		<TD ALIGN=RIGHT><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdteam']; ?>&nbsp;</B></font></TD>
		
        
	<?php endif; ?>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hddelete']; ?>&nbsp;</B></font></TD>	
	</TR>
	<?php extract($this->_vars, EXTR_REFS);  
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
 ?>
	<?php extract($this->_vars, EXTR_REFS);  
	$color = $color_line1;
	for($i=0; $i<$num_notes; $i++)
	{
		echo "<TR BGCOLOR=\"$color\">";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;$galaxy_name[$i]&nbsp;</font></TD>";
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
 ?>
	<tr bgcolor="<?php echo $this->_vars['color_line2']; ?>">
	<td colspan="9">&nbsp;</td>
	<?php extract($this->_vars, EXTR_REFS);  
		if ($playerteam > 0){
			echo "<TD ALIGN=CENTER>&nbsp;</TD>";
			
		}
	 ?>	
	<td align="center"><INPUT TYPE=SUBMIT VALUE="<?php echo $this->_vars['l_sn_delete']; ?>"></td>
</tr>
	</TABLE>
<?php endif; ?>

</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
