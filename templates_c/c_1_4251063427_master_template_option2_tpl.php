<h1><?php echo $this->_vars['title']; ?></h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php if ($this->_vars['l_opt2_playernamechanged'] != ''): ?>
<?php echo $this->_vars['l_opt2_playernamechanged']; ?>
<?php endif; ?>

<?php if ($this->_vars['newpass1'] == "" && $this->_vars['newpass2'] == ""): ?>
<?php echo $this->_vars['l_opt2_passunchanged']; ?>
<?php elseif ($this->_vars['password'] != $this->_vars['oldpass']): ?>
<?php echo $this->_vars['l_opt2_srcpassfalse']; ?>
<?php elseif ($this->_vars['newpass1'] != $this->_vars['newpass2']): ?>
<?php echo $this->_vars['l_opt2_newpassnomatch']; ?>
<?php elseif (( $this->_vars['oldpass'] == $this->_vars['password'] ) && $this->_vars['debug_query']): ?>
<?php echo $this->_vars['l_opt2_passchanged']; ?>
<?php else: ?>
<?php echo $this->_vars['l_opt2_passchangeerr']; ?>
<?php endif; ?>

<?php if ($this->_vars['allow_shipnamechange'] == 1): ?>
<?php echo $this->_vars['l_opt2_shipnamechanged']; ?>
<?php endif; ?>

<?php echo $this->_vars['l_home_planet']; ?>: <?php echo $this->_vars['home_planet_name']; ?><br><br>

<?php if ($this->_vars['l_opt2_chlang'] != ''): ?>
<?php echo $this->_vars['l_opt2_chlang']; ?>
<?php endif; ?>

<?php if ($this->_vars['l_opt2_chtemplate'] != ''): ?>
<?php echo $this->_vars['l_opt2_chtemplate']; ?>
<?php endif; ?>

<?php echo $this->_vars['l_opt2_mapwidth']; ?> <?php echo $this->_vars['map_width']; ?><br><br>
</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br>				</td>
			</tr>
		</table>
	</td>
  </tr>
</table>
