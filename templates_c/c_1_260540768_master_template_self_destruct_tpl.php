<H1><?php echo $this->_vars['title']; ?></H1>

<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>

<?php if ($this->_vars['sure'] == 0): ?>
	<FONT COLOR=RED><B><?php echo $this->_vars['l_die_rusure']; ?></B></FONT><BR><BR>
	<A HREF=main.php><?php echo $this->_vars['l_die_nonono']; ?></A> <?php echo $this->_vars['l_die_what']; ?><BR><BR>
	<A HREF=self_destruct.php?sure=1><?php echo $this->_vars['l_yes']; ?>!</A> <?php echo $this->_vars['l_die_goodbye']; ?><BR><BR>
<?php endif; ?>

<?php if ($this->_vars['sure'] == 1): ?>
	<FONT COLOR=RED><B><?php echo $this->_vars['l_die_check']; ?></B></FONT><BR><BR>
	<A HREF=main.php><?php echo $this->_vars['l_die_nonono']; ?></A> <?php echo $this->_vars['l_die_what']; ?><BR><BR>
	<A HREF=self_destruct.php?sure=2><?php echo $this->_vars['l_yes']; ?>!</A> <?php echo $this->_vars['l_die_goodbye']; ?><BR><BR>
<?php endif; ?>

<?php if ($this->_vars['sure'] == 2): ?>
	<?php echo $this->_vars['l_die_count']; ?><BR>
	<?php echo $this->_vars['l_die_vapor']; ?><BR><BR>
	<?php echo $this->_vars['l_die_please2']; ?><BR>
<?php endif; ?>

</td></tr>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?></td></tr>
		</table>
	</td>
  </tr>
</table>
