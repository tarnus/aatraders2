<h1><?php echo $this->_vars['title']; ?></h1>

<?php echo $this->_vars['l_lrs_used']; ?> <?php echo $this->_vars['fullscan_cost']; ?> <?php echo $this->_vars['l_lrs_turns']; ?>, <?php echo $this->_vars['turnsleft']; ?> <?php echo $this->_vars['l_lrs_left']; ?>.
<BR><BR>
<?php echo $this->_vars['l_lrs_reach']; ?>
<BR><BR>

<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="0" WIDTH="100%" bgcolor="#000000">
	<TR BGCOLOR="#585980">
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_sector']; ?></B></TD>
		<td width="10%" align="center"><B><?php echo $this->_vars['l_scan']; ?></B></td>
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_lrs_links']; ?></B></TD>
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_lrs_ships']; ?></B></TD>
		<TD colspan="2" width="10%" align="center"><B><?php echo $this->_vars['l_port']; ?></B></TD>
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_planets']; ?></B></TD>
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_mines']; ?></B></TD>
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_fighters']; ?></B></TD>
		<TD width="10%" align="center"><B><?php echo $this->_vars['l_lss']; ?></B></TD>
	</TR>
	<?php $this->assign('color', "#3A3B6E"); ?>

	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['lr_sector']), 'iteration' => 0);
if (count((array)$this->_vars['lr_sector'])): foreach ((array)$this->_vars['lr_sector'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
		<TR BGCOLOR="<?php echo $this->_vars['color']; ?>">
			<TD align="center"><A HREF="main.php?move_method=warp&destination=<?php echo $this->_run_modifier($this->_vars['lr_sector'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lr_zonetype'][$this->_vars['key']];  echo $this->_vars['lr_sector'][$this->_vars['key']]; ?></A></TD>
			<TD align="center"><A HREF="sector_scan.php?command=scan&sector=<?php echo $this->_run_modifier($this->_vars['lr_sector'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['l_scan']; ?></A></TD>
			<TD align="center"><?php echo $this->_vars['lr_links'][$this->_vars['key']]; ?></TD>
			<TD align="center"><?php echo $this->_vars['lr_ships'][$this->_vars['key']]; ?></TD>
			<TD align="right" WIDTH=12><img align=absmiddle height=12 width=12 alt="<?php echo $this->_vars['lr_image_alt'][$this->_vars['key']]; ?>" src="images/ports/<?php echo $this->_vars['lr_image'][$this->_vars['key']]; ?>.png">&nbsp;</TD>
			<TD align="left"><?php echo $this->_vars['lr_port'][$this->_vars['key']]; ?></TD>
			<TD align="center"><?php echo $this->_vars['lr_planets'][$this->_vars['key']]; ?></TD>
			<TD align="center"><?php echo $this->_vars['lr_mines'][$this->_vars['key']]; ?></TD>
			<TD align="center"><?php echo $this->_vars['lr_fighters'][$this->_vars['key']]; ?></TD>
			<TD align="center"><?php echo $this->_vars['lr_lss'][$this->_vars['key']]; ?></TD>
		</tr>

		<?php if ($this->_vars['color'] == "#3A3B6E"): ?>
			<?php $this->assign('color', "#23244F"); ?>
		<?php else: ?>
			<?php $this->assign('color', "#3A3B6E"); ?>
		<?php endif; ?>
	<?php endforeach; endif; ?>

	<tr>
		<td colspan="10"><br><?php echo $this->_vars['l_lrs_scanedsector']; ?><br><BR><?php echo $this->_vars['l_lrs_click']; ?><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td>
	</tr>
</table>


