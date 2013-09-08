<H1><?php echo $this->_vars['title']; ?></H1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td><br>
<?php if ($this->_vars['enable_spies'] == 1 && $this->_vars['spytotal'] != 0): ?>
	<?php echo $this->_vars['spytotal']; ?> <?php echo $this->_vars['l_spy_transferred']; ?>.<BR>
<?php endif; ?>
<?php if ($this->_vars['enable_dignitaries'] == 1 && $this->_vars['digtotal'] != 0): ?>
	<?php echo $this->_vars['digtotal']; ?> <?php echo $this->_vars['l_dig_transferred']; ?>.<BR>
<?php endif; ?>
<br>
<?php if ($this->_vars['s_special'] != ''): ?>
<?php echo $this->_vars['s_special']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_ore'] != ''): ?>
<?php echo $this->_vars['s_ore']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_goods'] != ''): ?>
<?php echo $this->_vars['s_goods']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_organics'] != ''): ?>
<?php echo $this->_vars['s_organics']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_colonists'] != ''): ?>
<?php echo $this->_vars['s_colonists']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_energy'] != ''): ?>
<?php echo $this->_vars['s_energy']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_torps'] != ''): ?>
<?php echo $this->_vars['s_torps']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_fighters'] != ''): ?>
<?php echo $this->_vars['s_fighters']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['s_credits'] != ''): ?>
<?php echo $this->_vars['s_credits']; ?><br>
<?php endif; ?>
<br>
<?php if ($this->_vars['p_special'] != ''): ?>
<?php echo $this->_vars['p_special']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_ore'] != ''): ?>
<?php echo $this->_vars['p_ore']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_goods'] != ''): ?>
<?php echo $this->_vars['p_goods']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_organics'] != ''): ?>
<?php echo $this->_vars['p_organics']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_colonists'] != ''): ?>
<?php echo $this->_vars['p_colonists']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_energy'] != ''): ?>
<?php echo $this->_vars['p_energy']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_torps'] != ''): ?>
<?php echo $this->_vars['p_torps']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_fighters'] != ''): ?>
<?php echo $this->_vars['p_fighters']; ?><br>
<?php endif; ?>
<?php if ($this->_vars['p_credits'] != ''): ?>
<?php echo $this->_vars['p_credits']; ?><br>
<?php endif; ?>
	<BR>
	<?php echo $this->_vars['l_planet2_compl']; ?>
	<br><BR>
<?php if ($this->_vars['mineteam'] == 1): ?>
	<a href=planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=transfer><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_planet_transfer_return']; ?><BR><BR>
	<a href=planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><BR>
<?php else: ?>
	<?php echo $this->_vars['l_planet2_notowner']; ?><BR>
<?php endif; ?>
<br>
</td></tr>

<tr><td><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
