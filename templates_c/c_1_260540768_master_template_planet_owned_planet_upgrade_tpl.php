<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
	<td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<TABLE BORDER=0 CELLSPACING=1 CELLPADDING=6 WIDTH="100%" ALIGN=CENTER>
<TR>
<TD align=center><font size=3 color=white><b><?php echo $this->_vars['l_trade_result']; ?></b></font></TD>
</TR>
<TR>
<TD align=center><b><font color=red><?php echo $this->_vars['l_cost']; ?> : <?php echo $this->_vars['trade_credits']; ?> <?php echo $this->_vars['l_credits']; ?></font></b></TD>
</TR>

<?php if ($this->_vars['upgradefighter'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_fighter']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['fighter_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradesensors'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_sensors']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['sensors_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradebeams'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_beams']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['beams_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradetorps'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_torp_launch']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['torp_launchers_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradeshields'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_shields']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['shields_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradejammer'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_jammer']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['jammer_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradecloak'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_cloak']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['cloak_upgrade']; ?>.</TD></TR>
<?php endif; ?>

<?php if ($this->_vars['upgradesdweapons'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_planetary_SD_weapons']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['sector_defense_weapons_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradesdsensors'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_planetary_SD_sensors']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['sector_defense_sensors_upgrade']; ?>.</TD></TR>
<?php endif; ?>
<?php if ($this->_vars['upgradesdcloak'] == 1): ?>
<TR><TD align=left><?php echo $this->_vars['l_planetary_SD_cloak']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['sector_defense_cloak_upgrade']; ?>.</TD></TR>
<?php endif; ?>

</table>
<BR><BR>
<A HREF=planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_toplanetmenu']; ?>
</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
