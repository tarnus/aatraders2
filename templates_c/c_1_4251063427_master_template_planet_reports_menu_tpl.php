<H1><?php echo $this->_vars['title']; ?>: <?php echo $this->_vars['l_pr_menu']; ?></H1>

<table width="600" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<B><A HREF="planet_report.php?commandpage=commodities" NAME="Planet Status"><?php echo $this->_vars['l_pr_planetstatus']; ?></A></B><BR>
		 <?php echo $this->_vars['l_pr_comm_disp']; ?><BR>
		 <BR>
		<B><A HREF="planet_report.php?commandpage=defenses" NAME="Planet Defense"><?php echo $this->_vars['l_pr_pdefense']; ?></A></B><BR>
		 <?php echo $this->_vars['l_pr_display']; ?><BR>
		<BR>
		<B><A HREF="planet_report.php?commandpage=production_view" NAME="Planet Status"><?php echo $this->_vars['l_pr_changeprods']; ?></A></B> &nbsp;&nbsp; <?php echo $this->_vars['l_pr_baserequired']; ?> <?php echo $this->_vars['l_pr_prod_disp']; ?><BR>

	<?php if ($this->_vars['playerteam'] > 0): ?>
		<BR>
		<B><A HREF=team_planets.php><?php echo $this->_vars['l_pr_teamlink']; ?></A></B><BR>
		 <?php echo $this->_vars['l_pr_team_disp']; ?>
		 <BR>
		<BR>
		<B><A HREF=team_defenses.php><?php echo $this->_vars['l_pr_showtd']; ?></A></B><BR> <?php echo $this->_vars['l_pr_showd']; ?><BR>
	<?php endif; ?>
</td></tr>
										<tr><td><br><?php echo $this->_vars['gotomain']; ?><br></td></tr>
		</table>
	</td>
  </tr>
</table>

