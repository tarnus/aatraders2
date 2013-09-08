<H1><?php echo $this->_vars['title']; ?>: <?php echo $this->_vars['l_pr_menu']; ?></H1>

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

	<?php if ($this->_vars['transfer_ore1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_ore']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_ore1']; ?> <?php echo $this->_vars['l_units']; ?> <?php echo $this->_vars['l_ore']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_organics1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_organics']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_organics1']; ?> <?php echo $this->_vars['l_units']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_goods1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_goods']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_goods1']; ?> <?php echo $this->_vars['l_units']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_energy1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_energy']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_energy1']; ?> <?php echo $this->_vars['l_units']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_colonists1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_colonists']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_colonists1']; ?> <?php echo $this->_vars['l_colonists']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_credits1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_credits']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_credits1']; ?> <?php echo $this->_vars['l_credits']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_credits1a'] != 0): ?>
		$l_planet2_baseexceeded <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_credits1a']; ?> <?php echo $this->_vars['l_credits']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_torps1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_torps']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_torps1']; ?> <?php echo $this->_vars['l_torps']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_fighters1'] != 0): ?>
		<?php echo $this->_vars['l_planet2_noten']; ?> <?php echo $this->_vars['l_fighters']; ?>. <?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_fighters1']; ?> <?php echo $this->_vars['l_fighters']; ?>.<BR>
	<?php endif; ?>
	
	<?php if ($this->_vars['transfer_ore2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_ore2']; ?> <?php echo $this->_vars['l_units']; ?> <?php echo $this->_vars['l_ore']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_organics2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_organics2']; ?> <?php echo $this->_vars['l_units']; ?> <?php echo $this->_vars['l_organics']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_goods2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_goods2']; ?> <?php echo $this->_vars['l_units']; ?> <?php echo $this->_vars['l_goods']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_energy2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_energy2']; ?> <?php echo $this->_vars['l_units']; ?> <?php echo $this->_vars['l_energy']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_colonists2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_colonists2']; ?> <?php echo $this->_vars['l_colonists']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_credits2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_credits2']; ?> <?php echo $this->_vars['l_credits']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_torps2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_torps2']; ?> <?php echo $this->_vars['l_torps']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_fighters2'] != 0): ?>
		<?php echo $this->_vars['l_planet2_losup']; ?> <?php echo $this->_vars['transfer_fighters2']; ?> <?php echo $this->_vars['l_fighters']; ?>.<BR>
	<?php endif; ?>

	<?php if ($this->_vars['transfer_ore3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_ore3']; ?> <?php echo $this->_vars['l_ore']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_organics3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_organics3']; ?> <?php echo $this->_vars['l_organics']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_goods3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_goods3']; ?> <?php echo $this->_vars['l_goods']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_colonists3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_colonists3']; ?> <?php echo $this->_vars['l_colonists']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_energy3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_energy3']; ?> <?php echo $this->_vars['l_energy']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_torps3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_torps3']; ?> <?php echo $this->_vars['l_torps']; ?>.<BR>
	<?php endif; ?>
	<?php if ($this->_vars['transfer_fighters3'] != 0): ?>
		<?php echo $this->_vars['l_planet2_settr']; ?> <?php echo $this->_vars['transfer_fighters3']; ?> <?php echo $this->_vars['l_fighters']; ?>.<BR>
	<?php endif; ?>

	<?php echo $this->_vars['l_planet2_noteamtransfer']; ?><p>
	<A HREF=planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_toplanetmenu']; ?><BR><BR>

</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
