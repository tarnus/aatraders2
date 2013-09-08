<h1><?php echo $this->_vars['title']; ?></h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php echo $this->_vars['l_login_4gotpw1']; ?> <A HREF=email_player.php?mail=<?php echo $this->_vars['playeremail']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_login_4gotpw2']; ?> <a href=index.php><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_login_4gotpw3']; ?> <?php echo $this->_vars['ip']; ?>...
</td></tr>

<tr><td><br><br><a href="index.php" class=nav><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_new_login']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
