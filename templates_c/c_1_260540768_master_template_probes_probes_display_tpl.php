<h1><?php echo $this->_vars['title']; ?></h1>

<table border="1" cellspacing="1" cellpadding="2" width="500" align="center">
	<TR BGCOLOR="#585980">
		<TD align="center"><font color="white"><B><?php echo $this->_vars['l_probe_named']; ?></B></font></TD>
	</TR>
	<?php if ($this->_vars['player_id'] == $this->_vars['probe_owner_id'] && $this->_vars['probe_owner_id'] > 0): ?>
		<TR BGCOLOR="#23244F">
			<TD>
				<?php echo $this->_vars['l_probe_ordersout']; ?><p>
				<?php echo $this->_vars['l_probe_pickup']; ?><p>
				<?php echo $this->_vars['l_probe_orders']; ?><p>
				<?php echo $this->_vars['l_probe_upgrade']; ?></p>
				<?php echo $this->_vars['l_turns_have']; ?> <?php echo $this->_vars['player_turns']; ?>
			</td>
		</tr>
		<tr>
			<td BGCOLOR="#000000">
				<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="2" align="center">
					<TR BGCOLOR="#3A3B6E">
						<td>&nbsp;</td>
						<td>&nbsp;</td>
						<TD><B><?php echo $this->_vars['l_probe_engine']; ?></B></TD>
						<TD><B><?php echo $this->_vars['l_probe_sensors']; ?></B></TD>
						<TD><B><?php echo $this->_vars['l_probe_cloak']; ?></B></TD>
					</TR>
					<TR BGCOLOR="#23244F">
						<TD><?php echo $this->_vars['l_probe_defense_levels']; ?></TD>
						<td>&nbsp;</td>
						<TD><?php echo $this->_vars['probe_engines']; ?></TD>
						<TD><?php echo $this->_vars['probe_sensors']; ?></TD>
						<TD><?php echo $this->_vars['probe_cloak']; ?></TD>
					</TR>
				</TABLE>
			</td>
		</tr>
	<?php else: ?>
		<?php if ($this->_vars['probe_owner_id'] != 3): ?>
			<tr BGCOLOR="#23244F">
				<td>
					<?php echo $this->_vars['l_probe_att']; ?>
				</td>
			</tr>
		<?php endif; ?>
		<tr BGCOLOR="#3A3B6E">
			<td>
				<?php echo $this->_vars['l_probe_scn']; ?>
			</td>
		</tr>
	<?php endif; ?>
	<?php if ($this->_vars['player_id'] == $this->_vars['probe_owner_id']): ?>
		<TR BGCOLOR="#23244F">
			<TD><A onclick="javascript: alert ('alert:<?php echo $this->_vars['l_probe_warning']; ?>');" HREF="probes_upgrade.php?probe_id=<?php echo $this->_vars['probe_id']; ?>&destroy=1"><?php echo $this->_vars['l_probe_destroyprobe']; ?></a></td>
		</tr>
	<?php endif; ?>
</TABLE>
<BR><BR>

<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
</table>
 