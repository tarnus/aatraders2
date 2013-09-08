<H1><?php echo $this->_vars['title']; ?></H1>

<form action="sectorgenesis.php" method="post">
<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td colspan=2><?php echo $this->_vars['l_sgns_shipcredits']; ?> <?php echo $this->_vars['credits']; ?><br><?php echo $this->_vars['l_sgns_createcost']; ?> <?php echo $this->_vars['sgcostnumber']; ?></td></tr>
<tr><td colspan=2><br><br><?php echo $this->_vars['l_sgcreate']; ?></td></tr>
<tr><td colspan=2><br><br><?php echo $this->_vars['l_sgns_sectorname']; ?>&nbsp;<input type="text" name="sectorname" maxlength="30"></td></tr>
<tr><td><input type="hidden" name="sglink" value="1">
<input type="submit" value="<?php echo $this->_vars['l_submit']; ?>" ><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>">
</td></tr>
</form>
<?php if ($this->_vars['sector_type'] != 0): ?>
	<form action="sectorgenesis.php" method="post">
	<tr><td valign="middle" colspan="2"><br><br><?php echo $this->_vars['l_sgcreatens']; ?>:&nbsp;<input type="text" name="target_sector" size="10" maxlength="30" value="">
	</td><tr><tr><td colspan=2><input type="hidden" name="rslink" value="1">
	<input type="submit" value="<?php echo $this->_vars['l_submit']; ?>" onclick="clean_js()"><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>">
	</td></tr>
	</form>
<?php endif; ?>
</td></tr>

<tr><td colspan=2><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table> 
