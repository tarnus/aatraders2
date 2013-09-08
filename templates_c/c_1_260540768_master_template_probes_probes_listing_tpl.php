<h1><?php echo $this->_vars['title']; ?></h1>

<?php $this->assign('line_color', "#23244F"); ?>
<?php $this->assign('color_line1', "#23244F"); ?>
<?php $this->assign('color_line2', "#3A3B6E"); ?>

<table border="1" cellspacing="1" cellpadding="2" width="100%">
	<TR BGCOLOR="#585980">
		<TD colspan="8" align="center"><font color="white"><B><?php echo $this->_vars['l_probe_defaulttitle1']; ?></B></font></TD>
	</TR>
	<TR BGCOLOR="#23244F">
		<TD><B><A HREF="probes.php"><?php echo $this->_vars['l_probe_codenumber']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=type"><?php echo $this->_vars['l_probe_type']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=sector"><?php echo $this->_vars['l_probe_sector']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=tsector"><?php echo $this->_vars['l_probe_tsector']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=engines"><?php echo $this->_vars['l_probe_engine']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=sensors"><?php echo $this->_vars['l_probe_sensors']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=cloak"><?php echo $this->_vars['l_probe_cloak']; ?></A></B></TD>
		<TD><B><?php echo $this->_vars['l_probe_detect']; ?></B></TD>
	</TR>
	<?php if ($this->_vars['probes_in_space'] == 0): ?>
		<TR BGCOLOR="#3A3B6E">
			<td colspan="8"><?php echo $this->_vars['l_probe_no1']; ?></td>
		<tr>
	<?php else: ?>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['probe_id']), 'iteration' => 0);
if (count((array)$this->_vars['probe_id'])): foreach ((array)$this->_vars['probe_id'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<TR BGCOLOR="<?php echo $this->_vars['line_color']; ?>">
				<TD><font size=2 color=white><?php echo $this->_vars['probe_id'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['probe_type'][$this->_vars['key']]; ?></font>
					<?php if ($this->_vars['probe_display'][$this->_vars['key']] != ""): ?>
						<br><br><font size=2 color=white><?php echo $this->_vars['probe_display'][$this->_vars['key']]; ?></font>
					<?php endif; ?>
				</TD>
				<TD><font size=2 color=white><a href=main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['probe_current_sector'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>><?php echo $this->_vars['probe_current_sector'][$this->_vars['key']]; ?></a></font></TD>
				<TD><font size=2 color=white><a href=main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['probe_target_sector'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>><?php echo $this->_vars['probe_target_sector'][$this->_vars['key']]; ?></a></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['probe_engines'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['probe_sensors'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['probe_cloak'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2><a href="probes.php?command=detect&probe_id=<?php echo $this->_vars['probe_id'][$this->_vars['key']]; ?>"><?php echo $this->_vars['l_probe_view']; ?></a></font></TD>
			</TR>
			<?php if ($this->_vars['line_color'] == $this->_vars['color_line1']): ?>
				<?php $this->assign('line_color', $this->_vars['color_line2']); ?>
			<?php else: ?>
				<?php $this->assign('line_color', $this->_vars['color_line1']); ?>
			<?php endif; ?>
		<?php endforeach; endif; ?>
	<?php endif; ?>
</TABLE>
<BR><BR>

<?php $this->assign('line_color', "#23244F"); ?>
<table border="1" cellspacing="1" cellpadding="2" width="100%">
	<TR BGCOLOR="#585980">
		<TD colspan="8" align="center"><font color=white><B><?php echo $this->_vars['l_probe_defaulttitle2']; ?></B></font></TD>
	</TR>
	<TR BGCOLOR="#23244F">
		<TD><B><A HREF="probes.php"><?php echo $this->_vars['l_probe_codenumber']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=type"><?php echo $this->_vars['l_probe_type']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=engines"><?php echo $this->_vars['l_probe_engine']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=sensors"><?php echo $this->_vars['l_probe_sensors']; ?></A></B></TD>
		<TD><B><A HREF="probes.php?by1=cloak"><?php echo $this->_vars['l_probe_cloak']; ?></A></B></TD>
		<TD><B><?php echo $this->_vars['l_probe_launch']; ?></B></TD>
	</TR>
	<?php if ($this->_vars['probes_in_ship'] == 0): ?>
		<TR BGCOLOR="#3A3B6E">
			<td colspan="6"><?php echo $this->_vars['l_probe_no2']; ?></td>
		<tr>
	<?php else: ?>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['ship_probe_id']), 'iteration' => 0);
if (count((array)$this->_vars['ship_probe_id'])): foreach ((array)$this->_vars['ship_probe_id'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<TR BGCOLOR="<?php echo $this->_vars['line_color']; ?>">
				<TD><font size=2 color=white><?php echo $this->_vars['ship_probe_id'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['ship_probe_type'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['ship_probe_engines'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['ship_probe_sensors'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2 color=white><?php echo $this->_vars['ship_probe_cloak'][$this->_vars['key']]; ?></font></TD>
				<TD><font size=2><a href="probes.php?command=drop&probe_id=<?php echo $this->_vars['ship_probe_id'][$this->_vars['key']]; ?>"><?php echo $this->_vars['l_probe_launch']; ?></a></font></TD>
			</TR>
			<?php if ($this->_vars['line_color'] == $this->_vars['color_line1']): ?>
				<?php $this->assign('line_color', $this->_vars['color_line2']); ?>
			<?php else: ?>
				<?php $this->assign('line_color', $this->_vars['color_line1']); ?>
			<?php endif; ?>
		<?php endforeach; endif; ?>
	<?php endif; ?>
</TABLE>

<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
</table>
 