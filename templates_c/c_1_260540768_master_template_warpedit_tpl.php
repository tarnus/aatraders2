<H1><?php echo $this->_vars['title']; ?></H1>

<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td colspan=2>
<?php echo $this->_vars['linkmessage']; ?>
<?php if ($this->_vars['linkcount'] != 0): ?>
:&nbsp;
	<?php extract($this->_vars, EXTR_REFS);  
			for($i = 0; $i < $linkcount; $i++){
			echo "$linklist[$i] ";
		}
	 ?>
<?php endif; ?>
<br><br></td></tr>

<form action="warpedit.php" method="post">
<input type="hidden" name="confirm" value="add">
<tr><td><?php echo $this->_vars['l_warp_query']; ?></td><td><input type="text" name="target_sector" size="6" maxlength="30" value=""></td></tr>
<tr><td><?php echo $this->_vars['l_warp_oneway']; ?></td><td><input type="checkbox" name="oneway" value="oneway"></td></tr>

<tr><td><input type="submit" value="<?php echo $this->_vars['l_submit']; ?>" ><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>"></td><tr>
</form>
<tr><td colspan=2><br><br><?php echo $this->_vars['l_warp_dest']; ?><br><br></td></tr>
<form action="warpedit.php" method="post">
<input type="hidden" name="confirm" value="delete">
<tr><td><?php echo $this->_vars['l_warp_destquery']; ?></td><td><input type="text" name="target_sector" size="6" maxlength="30" value=""></td></tr>
<tr><td><?php echo $this->_vars['l_warp_bothway']; ?>?</td><td><input type="checkbox" name="bothway" value="bothway"></td></tr>

<tr><td><input type="submit" value="<?php echo $this->_vars['l_submit']; ?>" ><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>"></td><tr>
</form>

<tr><td colspan=2><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
