<H1><?php echo $this->_vars['title']; ?></H1>
<table width="50%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD colspan=2>
<img src = "templates/master_template/images/spacer.gif" width = "1" height = "10"></td>
								</tr><FORM ACTION=messageblockmanager.php METHOD=POST>
<TD align="center"><?php echo $this->_vars['l_block_receivefrom']; ?><br><br>
<?php if ($this->_vars['unblockcount'] != 0): ?>
	<SELECT NAME=to2 size="10">
	<?php extract($this->_vars, EXTR_REFS);  
		for($i = 0; $i < $unblockcount; $i++){
			echo "<OPTION>$unblockedplayers[$i]</option>\n";
		}
	 ?>
	</SELECT>
	<br><br>
	<input type="submit" name="<?php echo $this->_vars['l_block_block']; ?>" value="<?php echo $this->_vars['l_block_block']; ?>">
<?php else: ?>
	<?php echo $this->_vars['l_block_empty']; ?>
<?php endif; ?>
</TD>
<input type="hidden" name="command" value="block">
</FORM>
<FORM ACTION=messageblockmanager.php METHOD=POST>
<TD align="center"><?php echo $this->_vars['l_block_blockfrom']; ?><br><br>
<?php if ($this->_vars['blockcount'] != 0): ?>
	<SELECT NAME=to size="10">
	<?php extract($this->_vars, EXTR_REFS);  
		for($i = 0; $i < $blockcount; $i++){
			echo "<OPTION>$blockedplayers[$i]</option>\n";
		}
	 ?>
	</SELECT><br><br>
	<input type="submit" name="<?php echo $this->_vars['l_block_unblock']; ?>" value="<?php echo $this->_vars['l_block_unblock']; ?>">
<?php else: ?>
	<?php echo $this->_vars['l_block_empty']; ?>
<?php endif; ?>
</TD>
<input type="hidden" name="command" value="unblock">
</FORM>
</TR>
<tr><td colspan=2><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

