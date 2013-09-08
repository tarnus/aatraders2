<H1><?php echo $this->_vars['l_sn_tntitle']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<B><A HREF=planet_report.php?PRepType=0><?php echo $this->_vars['l_pr_menulink']; ?></A></B><BR>
<?php if ($this->_vars['count'] < 1): ?>
	<BR><?php echo $this->_vars['l_sn_nonotes']; ?>
<?php else: ?>
	<BR>
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
<FORM ACTION=sector_notes.php METHOD=POST>
<?php extract($this->_vars, EXTR_REFS);  
if ($command==$l_sn_editnote){
	echo "<b>".$l_sn_editnote."</b><p>";
	echo "<input type=\"Hidden\" name=\"command\" value=\"$l_sn_editnote\">";
}else{
	echo "<b>".$l_sn_addnote."</b><p>";
	echo "<input type=\"Hidden\" name=\"command\" value=\"$l_sn_addnote\">";
}
 ?>
<input type="Hidden" name="limit" value="<?php echo $this->_vars['limit']; ?>">
<input type="Hidden" name="sectornum" value="<?php echo $this->_vars['sector']; ?>">
<input type="Hidden" name="galaxy_name" value="<?php echo $this->_vars['galaxy_name']; ?>">
<input type="Hidden" name="note_id" value="<?php echo $this->_vars['notelistid']; ?>">
	
<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_galaxy']; ?>&nbsp;</B></font></TD><td width="5">&nbsp;</td>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['galaxy_name']; ?>&nbsp;</B></font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdsector']; ?>&nbsp;</B></font></TD><td width="5">&nbsp;</td>
		<TD ALIGN=left><font size=2><?php echo $this->_vars['sector']; ?>&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdscanfrom']; ?>&nbsp;</B></font></TD><td width="5">&nbsp;</td>
		<TD ALIGN=left><font size=2><input type="Text" name="scanfrom" width="10" value="<?php echo $this->_vars['sector_scanfrom']; ?>">&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdtype']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><select name=stype>
		<option value="">N/A</option>
		<?php if ($this->_vars['sector_type'] == "Ally"): ?>
			<option value="Ally" selected><?php echo $this->_vars['l_sn_ally']; ?></option>
		<?php else: ?>
			<option value="Ally" ><?php echo $this->_vars['l_sn_ally']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Base"): ?>
			<option value="Base" selected><?php echo $this->_vars['l_sn_base']; ?></option>
		<?php else: ?>
			<option value="Base"><?php echo $this->_vars['l_sn_base']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Enemy"): ?>
			<option value="Enemy" selected><?php echo $this->_vars['l_sn_enemy']; ?></option>
		<?php else: ?>
			<option value="Enemy"><?php echo $this->_vars['l_sn_enemy']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Indy"): ?>
			<option value="Indy" selected><?php echo $this->_vars['l_sn_indy']; ?></option>
		<?php else: ?>
			<option value="Indy"><?php echo $this->_vars['l_sn_indy']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Port"): ?>
			<option value="Port" selected><?php echo $this->_vars['l_sn_port']; ?></option>
		<?php else: ?>
			<option value="Port"><?php echo $this->_vars['l_sn_port']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Team Base"): ?>
			<option value="Team Base" selected><?php echo $this->_vars['l_sn_teambase']; ?></option>
		<?php else: ?>
			<option value="Team Base"><?php echo $this->_vars['l_sn_teambase']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Minefield"): ?>
			<option value="Minefield" selected><?php echo $this->_vars['l_sn_minefield']; ?></option>
		<?php else: ?>
			<option value="Minefield"><?php echo $this->_vars['l_sn_minefield']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "SG Entry"): ?>
			<option value="SG Entry" selected><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
		<?php else: ?>
			<option value="SG Entry"><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
		<?php endif; ?>
		<?php if ($this->_vars['sector_type'] == "Spy Sector"): ?>
			<option value="Spy Sector" selected><?php echo $this->_vars['l_sn_spysector']; ?></option>
		<?php else: ?>
			<option value="Spy Sector"><?php echo $this->_vars['l_sn_spysector']; ?></option>
		<?php endif; ?>	
		</select>&nbsp;</font></TD>
	</tr>

	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdowner']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><input type="Text" name="owner" width="10" value="<?php echo $this->_vars['sector_owner']; ?>">&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdplanets']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><input type="Text" name="planets" width="10" value="<?php echo $this->_vars['sector_planets']; ?>">&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdport']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><input type="Text" name="port" width="10" value="<?php echo $this->_vars['sector_port']; ?>">&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdfighters']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><input type="Text" name="fighters" width="10" value="<?php echo $this->_vars['sector_fighters']; ?>">&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdmines']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><input type="Text" name="mines" width="10" value="<?php echo $this->_vars['sector_mines']; ?>">&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hdteam']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2>
		<?php extract($this->_vars, EXTR_REFS);  
		if ($notes_team >0){
			if ($noteplayerid==$playerid){
				if ($playerteam==0){
					echo "<input type=\"checkbox\" name=\"team\" disabled>";
				}else{
					echo "<input type=\"checkbox\" name=\"team\" >";
				}
			}else{
				echo "<input type=\"checkbox\" name=\"team\" checked disabled>";
			}
		}else{
			if ($playerteam==0){
				echo "<input type=\"checkbox\" name=\"team\" disabled>";
			}else{
				echo "<input type=\"checkbox\" name=\"team\" >";
			}
		}
		 ?>
		&nbsp;</font></TD>
		</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;<?php echo $this->_vars['l_sn_hddetail']; ?>&nbsp;</B></font></TD><td>&nbsp;</td>
		<TD ALIGN=left><font size=2><textarea name="note" cols="30" rows="5"><?php echo $this->_vars['notelistnote']; ?></textarea>&nbsp;</font></TD>
	</tr>
	<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN=top>
		<TD ALIGN=left><font size=2><B>&nbsp;&nbsp;</B></font></TD><td>&nbsp;</td>
		<?php if ($this->_vars['command'] == $this->_vars['l_sn_editnote']): ?>
			<TD ALIGN=left><font size=2><INPUT TYPE=SUBMIT VALUE="<?php echo $this->_vars['l_sn_editnote']; ?>">&nbsp;</font></TD>
		<?php else: ?>
			<TD ALIGN=left><font size=2><INPUT TYPE=SUBMIT VALUE="<?php echo $this->_vars['l_sn_addnote']; ?>">&nbsp;</font></TD>	
		<?php endif; ?>
	</tr>
</TABLE>
<?php endif; ?>

</td></tr>
<tr><td><br><br><a href="sector_notes.php"><?php echo $this->_vars['l_sn_list']; ?></a><br><br></td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
