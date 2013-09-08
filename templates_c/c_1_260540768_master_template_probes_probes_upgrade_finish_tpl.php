<h1><?php echo $this->_vars['title']; ?></h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<?php if ($this->_vars['isprobe']): ?>
		<?php if ($this->_vars['total_cost'] > $this->_vars['playercredits']): ?>
			<?php echo $this->_vars['l_probe2_nocredits']; ?>
		<?php else: ?>
			<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=3 WIDTH="100%" ALIGN=CENTER>
			 <TR>
				<TD align=center ><font size=3 color=white><b><?php echo $this->_vars['l_trade_result']; ?></b></font></TD>
			 </TR>
			 <TR>
				<TD align=center><b><font color=red><?php echo $this->_vars['l_cost']; ?>: <?php echo $this->_vars['trade_credits']; ?> <?php echo $this->_vars['l_credits']; ?></font></b></TD>
			 </TR>

			<?php if ($this->_vars['isengineupgrade']): ?>
				<TR><TD align=left><?php echo $this->_vars['l_engines']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['engines_upgrade']; ?>.</TD></TR>
			<?php endif; ?>

			<?php if ($this->_vars['issensorupgrade']): ?>
				<TR><TD align=left><?php echo $this->_vars['l_sensors']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['sensors_upgrade']; ?>.</TD></TR>
			<?php endif; ?>

			<?php if ($this->_vars['iscloakupgrade']): ?>
				<TR><TD align=left><?php echo $this->_vars['l_cloak']; ?> <?php echo $this->_vars['l_trade_upgraded']; ?> <?php echo $this->_vars['cloak_upgrade']; ?>.</TD></TR>
			<?php endif; ?>

			</table>
			<BR><BR>
			<A HREF=probes_upgrade.php?probe_id=<?php echo $this->_vars['probe_id']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_toprobemenu']; ?><BR><BR>
		<?php endif; ?>
	<?php else: ?>
		<A HREF=probes_upgrade.php?probe_id=<?php echo $this->_vars['probe_id']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_toprobemenu']; ?><BR><BR>
	<?php endif; ?>
</td></tr>

<tr><td><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
