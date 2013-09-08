<H1><?php echo $this->_vars['title']; ?></H1>

<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">

<?php if ($this->_vars['confirm'] == "add"): ?>
	<form action="warpedit_add.php" method="post">
	<input type="hidden" name="oneway" value=<?php echo $this->_vars['oneway']; ?>>
	<input type="hidden" name="target_sector" value=<?php echo $this->_vars['target_sector']; ?>>

	<tr><td><?php echo $this->_vars['l_player']; ?>&nbsp;<?php echo $this->_vars['l_credits']; ?>: <?php echo $this->_vars['playercredits']; ?></td></tr>
	<tr><td><?php echo $this->_vars['l_ship']; ?>&nbsp;<?php echo $this->_vars['l_energy']; ?>: <?php echo $this->_vars['shipenergy']; ?></td></tr>
	<tr><td>&nbsp;</td></tr>
	<?php if ($this->_vars['cost'] != 0): ?>
		<tr><td><?php echo $this->_vars['l_warp_create'];  echo $this->_vars['startsector'];  echo $this->_vars['l_warp_andsector'];  echo $this->_vars['target_sector'];  echo $this->_vars['l_warp_distance'];  echo $this->_vars['distance'];  echo $this->_vars['l_warp_lightyears']; ?>.<br><br>
		<?php echo $this->_vars['l_warp_costcreate']; ?>&nbsp;<?php echo $this->_vars['cost']; ?> credits<br><br><?php echo $this->_vars['l_warp_costenergy'];  echo $this->_vars['energycost']; ?><br><br></td></tr>
	<?php endif; ?>
	<tr><td><?php echo $this->_vars['l_warp_query']; ?>&nbsp;<?php echo $this->_vars['target_sector']; ?></td></tr>
	<tr><td><?php echo $this->_vars['l_warp_oneway']; ?>&nbsp;
	<?php if ($this->_vars['oneway'] == "oneway"): ?>
		<?php echo $this->_vars['l_yes']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_no']; ?>
	<?php endif; ?>
	<br><br></td></tr>

	<tr><td><input type="submit" value="<?php echo $this->_vars['l_submit']; ?>" onclick="clean_js()"><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>"></td><tr>
	</form>
<?php endif; ?>

<?php if ($this->_vars['confirm'] == "delete"): ?>
	<form action="warpedit_delete.php" method="post">
	<input type="hidden" name="bothway" value=<?php echo $this->_vars['bothway']; ?>>
	<input type="hidden" name="target_sector" value=<?php echo $this->_vars['target_sector']; ?>>

	<tr><td><?php echo $this->_vars['l_player']; ?>&nbsp;<?php echo $this->_vars['l_credits']; ?>: <?php echo $this->_vars['playercredits']; ?></td></tr>
	<tr><td><?php echo $this->_vars['l_ship']; ?>&nbsp;<?php echo $this->_vars['l_energy']; ?>: <?php echo $this->_vars['shipenergy']; ?></td></tr>
	<tr><td>&nbsp;</td></tr>
	<?php if ($this->_vars['cost'] != 0): ?>
		<tr><td><?php echo $this->_vars['l_warp_delete'];  echo $this->_vars['startsector'];  echo $this->_vars['l_warp_andsector'];  echo $this->_vars['target_sector'];  echo $this->_vars['l_warp_distance'];  echo $this->_vars['distance'];  echo $this->_vars['l_warp_lightyears']; ?>.<br><br>
		<?php echo $this->_vars['l_warp_costdelete']; ?>&nbsp;<?php echo $this->_vars['cost']; ?> credits<br><br><?php echo $this->_vars['l_warp_costenergy'];  echo $this->_vars['energycost']; ?><br><br></td></tr>
	<?php endif; ?>
	<tr><td><?php echo $this->_vars['l_warp_destquery']; ?>&nbsp;<?php echo $this->_vars['target_sector']; ?></td></tr>
	<tr><td><?php echo $this->_vars['l_warp_bothway']; ?>?&nbsp;<?php if ($this->_vars['bothway'] == "bothway"): ?>
		<?php echo $this->_vars['l_yes']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_no']; ?>
	<?php endif; ?>
	<br><br></td></tr>

	<tr><td><input type="submit" value="<?php echo $this->_vars['l_submit']; ?>" onclick="clean_js()"><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>"></td><tr>
	</form>
<?php endif; ?>
<tr><td colspan=2><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
