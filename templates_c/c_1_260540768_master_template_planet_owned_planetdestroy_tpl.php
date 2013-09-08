<H1><?php echo $this->_vars['title']; ?></H1>

<table width="400" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
		<?php if ($this->_vars['destroy'] == 1 && $this->_vars['allow_genesis_destroy'] == 1): ?>
			<?php echo $this->_vars['planetname']; ?><br><font color=red><?php echo $this->_vars['l_planet_confirm']; ?></font><br><A HREF="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&destroy=2&command=destroy"><?php echo $this->_vars['l_yes']; ?></A><br>
			<A HREF="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_no']; ?>!</A><BR><br>
		<?php else: ?>
			<?php if ($this->_vars['destroy'] == 2 && $this->_vars['allow_genesis_destroy'] == 1): ?>
				<?php if ($this->_vars['shipgenesis'] < 1): ?>
					<?php echo $this->_vars['l_gns_nogenesis']; ?><br>
				<?php endif; ?>
				<?php if ($this->_vars['turns'] < 1): ?>
					<?php echo $this->_vars['l_gns_turn']; ?><br>
				<?php endif; ?>
			<?php endif; ?>
		<?php endif; ?>
</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
