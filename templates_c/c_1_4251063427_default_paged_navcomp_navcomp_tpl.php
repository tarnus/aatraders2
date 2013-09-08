<h1><?php echo $this->_vars['title']; ?></h1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php if (! $this->_vars['allow_navcomp']): ?>
$l_nav_nocomp<br><br>
<?php else: ?>
	<?php if ($this->_vars['state'] == 0): ?>
		<form action="navcomp.php" method=post>
		<?php echo $this->_vars['l_nav_query']; ?> <input name=stop_sector>
		<input type=submit value=<?php echo $this->_vars['l_submit']; ?>><br>
		<input name=state value=1 type=hidden>
		</form>
	<?php else: ?>
		<?php if ($this->_vars['found'] > 0): ?>
			<h3><?php echo $this->_vars['l_nav_pathfnd']; ?></h3>
			<?php echo $this->_vars['start_sector']; ?> <?php echo $this->_vars['search_results_echo']; ?><br>
			<?php echo $this->_vars['l_nav_answ1']; ?> <?php echo $this->_vars['search_depth']; ?> <?php echo $this->_vars['l_nav_answ2']; ?><br><br>
		<?php else: ?>
			<?php if ($this->_vars['found'] == 0): ?>
				<?php echo $this->_vars['l_nav_proper']; ?><br><br>
			<?php else: ?>
				(<?php echo $this->_vars['sectorname']; ?>) : <?php echo $this->_vars['l_nav_notinlogs']; ?><br><br>
			<?php endif; ?>
		<?php endif; ?>
	<?php endif; ?>
<?php endif; ?>

<?php if ($this->_vars['found'] > 0): ?>
	<form action='navcomp.php' enctype='multipart/form-data'>
	<?php echo $this->_vars['l_nav_autoroutename']; ?> <input type='text' name='name' value=''>
	<input type='hidden' name='state' value='create'>
	<input type='hidden' name='start_sector' value='<?php echo $this->_vars['start_sector']; ?>'>
	<input type='hidden' name='destination' value='<?php echo $this->_vars['destination']; ?>'>
	<input type='hidden' name='warp_list' value='<?php echo $this->_vars['warp_list']; ?>'>
	<input type='submit' value='<?php echo $this->_vars['l_autoroute_createroute']; ?>'>
	</form>
<?php endif; ?>
</td></tr>
<tr><td colspan=3><?php echo $this->_vars['l_autoroute_return']; ?> <a href='navcomp.php'><?php echo $this->_vars['l_clickme']; ?></a>.</td></tr>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

