<h1><?php echo $this->_vars['title']; ?></h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php echo $this->_vars['error_msg']; ?><br><br>
<a href=log.php><?php echo $this->_vars['l_here']; ?></a><?php echo $this->_vars['l_login_blackbox']; ?><BR><BR><?php echo $this->_vars['l_login_newbie']; ?><BR><BR>
</td></tr>
<tr><td><p><?php echo $this->_vars['error_msg2']; ?><p>
</td></tr>
<tr><td><br><br><a href="index.php" class=nav><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_new_login']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
