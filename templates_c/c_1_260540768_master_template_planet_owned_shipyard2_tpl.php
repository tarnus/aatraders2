<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	<font size=4 color=white><b><?php echo $this->_vars['l_ship2_buying']; ?></b></font><p>
	<table border=0 cellpadding=5>
	<tr><td align=center><font color=white size=4><b><?php echo $this->_vars['shipname']; ?></b><br><img src="<?php echo $this->_vars['shipimage']; ?>.gif"></font></td>
	<td><font size=2><b><?php echo $this->_vars['shipinfo']; ?></b></font>
	</table>
	<p>
	<table border=0>
		<tr>
		<td colspan=2> <font size=4><?php echo $this->_vars['l_player']; ?> <?php echo $this->_vars['l_credits']; ?>:</font> <font size=4 color=#00FF00><?php echo $this->_vars['numbercredits']; ?></font><br><br></td>
	</tr>		<tr>
		<td colspan=2> <font size=4><?php echo $this->_vars['l_ship2_tradein']; ?></font></td>
	</tr>
	<tr><td><font size=4><?php echo $this->_vars['l_ship2_value']; ?>&nbsp;&nbsp;&nbsp;</font></td>
	<td align=right><font size=4 color=#00FF00><b><?php echo $this->_vars['shipvalue']; ?></b></font></td></tr>
	<tr><td>
	<font size=4><?php echo $this->_vars['l_ship2_newvalue']; ?>&nbsp;&nbsp;&nbsp;</font></td>
	<td align=right><font size=4 color=#FF0000><b><?php echo $this->_vars['newshipvalue']; ?></b></font></td></tr>
	<tr><td><td><hr></td></tr>
	<tr><td>
	<font size=4><?php echo $this->_vars['l_ship2_totalcost']; ?>&nbsp;&nbsp;&nbsp;</font></td>
	<td align=right><font size=4 color=#FF0000><b><?php echo $this->_vars['totalcost']; ?></b></font></td></tr></table>
	<p>

	<?php if ($this->_vars['numbertotalcost'] > $this->_vars['credits']): ?>
		<br><font size=3 color=white><b>&nbsp;<?php echo $this->_vars['l_ship2_nomoney']; ?></b></font><p><br>
	<?php else: ?>
		<form action=planet.php method=POST>
		<input type=hidden name=stype value=<?php echo $this->_vars['stype']; ?>>
		<input type=hidden name=hull_upgrade value=<?php echo $this->_vars['hull_upgrade']; ?>>
		<input type=hidden name=engine_upgrade value=<?php echo $this->_vars['engine_upgrade']; ?>>
		<input type=hidden name=beams_upgrade value=<?php echo $this->_vars['beams_upgrade']; ?>>
		<input type=hidden name=fighter_upgrade value=<?php echo $this->_vars['fighter_upgrade']; ?>>
		<input type=hidden name=torp_launchers_upgrade value=<?php echo $this->_vars['torp_launchers_upgrade']; ?>>
		<input type=hidden name=shields_upgrade value=<?php echo $this->_vars['shields_upgrade']; ?>>
		<input type=hidden name=sensors_upgrade value=<?php echo $this->_vars['sensors_upgrade']; ?>>
		<input type=hidden name=cloak_upgrade value=<?php echo $this->_vars['cloak_upgrade']; ?>>
		<input type=hidden name=ecm_upgrade value=<?php echo $this->_vars['ecm_upgrade']; ?>>
		<input type=hidden name=armor_upgrade value=<?php echo $this->_vars['armor_upgrade']; ?>>
		<input type=hidden name=power_upgrade value=<?php echo $this->_vars['power_upgrade']; ?>>
		
		<input type=hidden name=confirm value=yes>
		<input type=hidden name=planet_id value=<?php echo $this->_vars['planet_id']; ?>>
		<input type=hidden name=command value=shipyard_purchase>
		<input type=submit value="<?php echo $this->_vars['l_ship2_purchase']; ?>">
		</form><p>
	<?php endif; ?>

	<?php if ($this->_vars['class'] != 10): ?>
		<table border=0>
		<tr>
			<td colspan=2> <font size=4><?php echo $this->_vars['l_ship2_buynstore']; ?>:</font></td>
		</tr>
		<tr><td><font size=4><?php echo $this->_vars['l_ship2_newvalue']; ?>&nbsp;&nbsp;&nbsp;</font></td>
		<td align=right><font size=4 color=#FF0000><b><?php echo $this->_vars['newshipvalue']; ?></b></font></td></tr>
		<tr><td><td><hr></td></tr>
		<tr><td>
		<font size=4><?php echo $this->_vars['l_ship2_totalcost']; ?>&nbsp;&nbsp;&nbsp;</font></td>
		<td align=right><font size=4 color=#FF0000><b><?php echo $this->_vars['newshipvalue']; ?></b></font></td></tr></table>
		<p>
		
		<?php if ($this->_vars['newshipcheck'] > $this->_vars['credits']): ?>
			<br><font size=3 color=white><b>&nbsp;<?php echo $this->_vars['l_ship2_nomoney']; ?></b></font><p><br>
		<?php else: ?>
			<form action=planet.php method=POST>
			<input type=hidden name=stype value=<?php echo $this->_vars['stype']; ?>>
		<input type=hidden name=hull_upgrade value=<?php echo $this->_vars['hull_upgrade']; ?>>
		<input type=hidden name=engine_upgrade value=<?php echo $this->_vars['engine_upgrade']; ?>>
		<input type=hidden name=beams_upgrade value=<?php echo $this->_vars['beams_upgrade']; ?>>
		<input type=hidden name=fighter_upgrade value=<?php echo $this->_vars['fighter_upgrade']; ?>>
		<input type=hidden name=torp_launchers_upgrade value=<?php echo $this->_vars['torp_launchers_upgrade']; ?>>
		<input type=hidden name=shields_upgrade value=<?php echo $this->_vars['shields_upgrade']; ?>>
		<input type=hidden name=sensors_upgrade value=<?php echo $this->_vars['sensors_upgrade']; ?>>
		<input type=hidden name=cloak_upgrade value=<?php echo $this->_vars['cloak_upgrade']; ?>>
		<input type=hidden name=ecm_upgrade value=<?php echo $this->_vars['ecm_upgrade']; ?>>
		<input type=hidden name=armor_upgrade value=<?php echo $this->_vars['armor_upgrade']; ?>>
		<input type=hidden name=power_upgrade value=<?php echo $this->_vars['power_upgrade']; ?>>
			<input type=hidden name=keep value=yes>
			<input type=hidden name=confirm value=yes>
			<input type=hidden name=planet_id value=<?php echo $this->_vars['planet_id']; ?>>
			<input type=hidden name=command value=shipyard_purchase>
			<input type=submit value="<?php echo $this->_vars['l_ship2_purchase']; ?>">
			</form><p>
		<?php endif; ?>
	<?php endif; ?>
</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
