<H1><?php echo $this->_vars['title']; ?></H1>

<table width="400" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	<b>
	<form action="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=namefinal" method="post">
	<?php echo $this->_vars['l_planet_iname']; ?>:  
	<input type="text" name="new_name" size="20" maxlength="20" value="<?php echo $this->_vars['planetname']; ?>"><BR><BR>
	<input type="submit" value="<?php echo $this->_vars['l_submit']; ?>"><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>"><BR><BR>
	</form>

	<BR><a href='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>'><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><BR><BR>
	<?php if ($this->_vars['allow_ibank']): ?>
		<?php echo $this->_vars['l_ifyouneedplan']; ?> <A HREF="igb.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_igb_term']; ?></A>.<BR><BR>
	<?php endif; ?>

</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
