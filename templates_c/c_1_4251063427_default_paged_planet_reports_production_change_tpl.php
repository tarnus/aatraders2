<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<BR><A HREF="planet_report.php?commandpage=production_view"><?php echo $this->_vars['l_pr_changeprods']; ?></A><br><br>
	<BR>
	<?php echo $this->_vars['l_pr_ppupdated']; ?><BR><BR>
	<?php if ($this->_vars['exceeded'] > 0): ?>
		<?php echo $this->_vars['l_pr_prexeedcheck']; ?><BR><BR>
	<?php endif; ?>
	<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $exceeded; $i++){
		echo $planetexceeded[$i]."<br>";
	}
	 ?>

</td></tr>

<tr><td><br><br><A HREF="planet_report.php"><?php echo $this->_vars['l_pr_menulink']; ?></A><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
