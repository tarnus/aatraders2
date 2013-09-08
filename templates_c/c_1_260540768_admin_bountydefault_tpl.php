<H1><?php echo $this->_vars['title']; ?></H1>

<FORM ACTION=admin.php METHOD=POST>

<table width="50%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
<!--		<table cellspacing = "0" cellpadding = "0" border = "0">
			<TR>
				<TD>
<?php echo $this->_vars['l_by_bountyon']; ?></TD><TD><SELECT NAME=bounty_on>
<?php extract($this->_vars, EXTR_REFS);  
for($i = 0; $i <$playerlist; $i++){
			echo "<OPTION VALUE=$playerid[$i] $playerselect[$i]>$playernamelist[$i]</option>\n";
}
 ?>
</SELECT></TD></TR>
<TR><TD><?php echo $this->_vars['l_by_amount']; ?>:</TD><TD><INPUT TYPE=TEXT NAME=amount SIZE=20 MAXLENGTH=20></TD></TR>
<TR><TD></TD><TD><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_by_place']; ?>><INPUT TYPE=RESET VALUE=Clear></TD>
<tr><td>
<input type=hidden name="response" value="place">
<input type="hidden" name="game_number" value="<?php echo $this->_vars['game_number']; ?>">
<input type=hidden name=md5admin_password value=<?php echo $this->_vars['md5admin_password']; ?>>
<input type="hidden" name="menu" value="Editor_Bounties"></td></tr>
</td></tr></TABLE>
</FORM>
-->
<FORM ACTION=admin.php METHOD=POST>
<table border=0 cellspacing=0 cellpadding=2 width="100%">
<tr><td>
<?php extract($this->_vars, EXTR_REFS);  
		if ($num_bounties < 1)
		{
			echo "$l_by_nobounties<BR>";
		}
		else
		{
			echo "<TABLE WIDTH=\"100%\" BORDER=0 CELLSPACING=0 CELLPADDING=2>";
			echo "<TR BGCOLOR=\"#585980\">";
			echo "<TD><B>$l_by_bountyon</B></TD>";
			echo "<TD><B>$l_amount</TD>";
			echo "</TR>";
			$color = "#3A3B6E";
			for ($i=0; $i<$num_bounties; $i++)
			{
				echo "<TR BGCOLOR=\"$color\">";
				echo "<TD><input type=\"radio\" name=\"bounty_on\" value=\"" . $bountyon[$i] . "\">" . $bountyname[$i] ."</TD>";
				echo "<TD>&nbsp;" . $bountyamount[$i] . "&nbsp;</TD>";
				echo "</TR>";

				if ($color == "#3A3B6E")
				{
				   $color = "#23244F";
				}
				else
				{
				   $color = "#3A3B6E";
				}
			}
		echo "</TABLE>";
		}
 ?>
</td></tr>
<tr><td><INPUT TYPE=SUBMIT VALUE="View Details"></td></tr>
		</table>
	</td>
  </tr>
</table>
<input type=hidden name="response" value="display">
<input type="hidden" name="game_number" value="<?php echo $this->_vars['game_number']; ?>">
<input type=hidden name=md5admin_password value=<?php echo $this->_vars['md5admin_password']; ?>>
<input type="hidden" name="menu" value="Editor_Bounties"></td></tr>
</form>