<h1><?php echo $this->_vars['title']; ?></h1>


<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<?php echo $this->_vars['l_new_charis']; ?> <font color="yellow"><b><?php echo $this->_vars['character']; ?></b></font><br><br>
<?php if ($this->_vars['display_password']): ?>
	<?php echo $this->_vars['l_new_pwis']; ?> <?php echo $this->_vars['makepass']; ?><br><br>
<?php endif; ?>

<?php if ($this->_vars['enable_profilesupport'] == 1): ?>
	<?php echo $this->_vars['message']; ?><br>
	<?php echo $this->_vars['message2']; ?><br><br>
<?php endif; ?>

<?php echo $this->_vars['emailresult']; ?><br><br>
<a href="index.php" class=nav><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_new_login']; ?><br><br>

</td></tr>
		</table>
	</td>
  </tr>
</table>
