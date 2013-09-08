<h1><?php echo $this->_vars['title']; ?></h1>

<table width="400" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php if ($this->_vars['otherplayer_sector_id'] != $this->_vars['shipinfo_sector_id']):  echo $this->_vars['l_ship_the']; ?> <font color=white> <?php echo $this->_vars['otherplayer_name']; ?></font>, <?php echo $this->_vars['l_ship_nolonger']; ?> <?php echo $this->_vars['shipinfo_sector_id']; ?> <br>
<?php else:  echo $this->_vars['l_ship_youc']; ?> <font color=white> <?php echo $this->_vars['otherplayer_name']; ?></font>, <?php echo $this->_vars['l_ship_owned']; ?> <font color=white> <?php echo $this->_vars['otherplayer_character_name']; ?>. </font><br><br>
<?php echo $this->_vars['l_ship_perform']; ?><br><br>
</td></tr>
	<tr>
		<td><font color=white><a href=scan.php?ship_id=<?php echo $this->_vars['ship_id']; ?>><?php echo $this->_vars['l_planet_scn_link']; ?></a></font><br><br></td>
	</tr>
	<tr>
		<td><a href=attack.php?ship_id=<?php echo $this->_vars['ship_id']; ?>><?php echo $this->_vars['l_planet_att_link']; ?></a><br><br></td>
	</tr>
<tr>
	<td colspan="3"><a href=message_send.php?to=<?php echo $this->_vars['player_id']; ?>><?php echo $this->_vars['l_send_msg']; ?></a><br><br></td>
</tr>

<?php endif; ?>
<br>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
