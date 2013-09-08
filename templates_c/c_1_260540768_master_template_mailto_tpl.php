<H1><?php echo $this->_vars['title']; ?></H1>
<FORM ACTION=message_send.php METHOD=POST>
<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php echo $this->_vars['l_mt_to']; ?></TD><TD><SELECT NAME=to>
<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $count; $i++){
		echo "<OPTION value=\"$sendid[$i]\" $selected[$i]>$sendname[$i]</option>\n";
	}
 ?>

</SELECT></TD></TR>
<TR><TD><?php echo $this->_vars['l_mt_from']; ?></TD><TD><INPUT DISABLED TYPE=TEXT NAME=dummy SIZE=40 MAXLENGTH=40 VALUE="<?php echo $this->_vars['playername']; ?>"></TD></TR>
<TR><TD><?php echo $this->_vars['l_mt_subject']; ?></TD><TD><INPUT TYPE=TEXT NAME=subject SIZE=50 MAXLENGTH=80 VALUE="<?php echo $this->_vars['subject']; ?>"></TD></TR>
<TR><TD><?php echo $this->_vars['l_mt_message']; ?></TD><TD><TEXTAREA NAME=content ROWS=10 COLS=50><?php echo $this->_vars['message']; ?></TEXTAREA></TD></TR>
<TR><TD></TD><TD><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_mt_send']; ?>><INPUT TYPE=RESET VALUE=<?php echo $this->_vars['l_reset']; ?>></TD>
				</td>
			</tr>
<tr><td colspan="2"><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
</FORM>

