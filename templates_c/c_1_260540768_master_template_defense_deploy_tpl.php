<H1><?php echo $this->_vars['title']; ?></H1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<FORM ACTION=defense_deploy.php METHOD=POST>
<?php echo $this->_vars['l_defense_deploy_max_fighters']; ?><BR><BR>
<?php echo $this->_vars['l_defense_deploy_max_mines']; ?><BR><BR>
<?php echo $this->_vars['l_defense_deploy_info1']; ?><BR><BR>
<?php echo $this->_vars['l_defense_deploy_info2']; ?><BR>
<?php echo $this->_vars['l_defense_deploy_deploy']; ?> <INPUT TYPE=TEXT NAME=nummines SIZE=10 MAXLENGTH=10 VALUE=<?php echo $this->_vars['shiptorps']; ?>> <?php echo $this->_vars['l_mines']; ?>.<BR>
<?php echo $this->_vars['l_defense_deploy_deploy']; ?> <INPUT TYPE=TEXT NAME=numfighters SIZE=10 MAXLENGTH=10 VALUE=<?php echo $this->_vars['shipfighters']; ?>> <?php echo $this->_vars['l_fighters']; ?>.<BR>
<INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_submit']; ?>></INPUT><INPUT TYPE=RESET VALUE=<?php echo $this->_vars['l_reset']; ?>></INPUT><BR><BR>
</FORM>
</td></tr>

<tr><td><?php echo $this->_vars['gotomain']; ?><br><br>				</td>
			</tr>
		</table>
	</td>
  </tr>
</table>
