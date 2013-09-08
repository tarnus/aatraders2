<h1><?php echo $this->_vars['title']; ?></h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<?php if (( $this->_vars['account_creation_closed'] )): ?>
<tr>
	  <td><?php echo $this->_vars['l_new_closed_message']; ?>
</td></tr>
<?php else: ?>
<form action="new_player_process.php" method="post">
<tr>
	  <td><?php echo $this->_vars['l_login_email']; ?></td>
	  <td><input type="text" name="username" size="20" maxlength="40" value=""></td>
	</tr>
	<tr>
	  <td><?php echo $this->_vars['l_new_shipname']; ?></td>
	  <td><input type="text" name="shipname" size="20" maxlength="20" value=""></td>
	</tr>
	<tr>
	  <td><?php echo $this->_vars['l_new_pname']; ?></td>
	  <td><input type="text" name="character" size="20" maxlength="20" value=""></td>
	</tr>
<?php if ($this->_vars['enable_profilesupport'] == 1 || $this->_vars['tournament_setup_access'] == 1 || $this->_vars['tournament_mode'] == 1 || $this->_vars['profile_only_server'] == 1): ?>
	<tr>
	  <td colspan="2"><hr><?php echo $this->_vars['l_profile_description']; ?><br><br>
	  <input type="hidden" name="url" value="<?php echo $this->_vars['url']; ?>">
	  <input type="hidden" name="game" value="<?php echo $this->_vars['game']; ?>"></td>
	</tr>
	<tr>
	  <td><?php echo $this->_vars['l_profile_name']; ?></td>
	  <td><input type="text" name="profilename" size="30" maxlength="150"></td>
	</tr>
	<tr>
	  <td><?php echo $this->_vars['l_profile_password']; ?></td>
	  <td><input type="password" name="profilepassword" size="20" maxlength="20"></td>
	</tr>
	<?php if ($this->_vars['tournament_setup_access'] == 1 || $this->_vars['tournament_mode'] == 1 || $this->_vars['profile_only_server'] == 1): ?>
		<tr>
		  <td><?php echo $this->_vars['l_profile_required']; ?></td>
		</tr>
	<?php endif; ?>
	<tr>
	  <td colspan="2"><hr><br></td>
	</tr>
<?php else: ?>
	<input type="hidden" name="url" value="<?php echo $this->_vars['url']; ?>">
	<input type="hidden" name="game" value="<?php echo $this->_vars['game']; ?>">
	<input type="hidden" name="profilename" value="">
	<input type="hidden" name="profilepassword" value="">
<?php endif; ?>
<input type="hidden" name="game_number" value="<?php echo $this->_vars['game_number']; ?>">
	<tr><td colspan 2>					  <input type="submit" value="<?php echo $this->_vars['l_submit']; ?>">
  <input type="reset" value="<?php echo $this->_vars['l_reset']; ?>">
</td></tr>
<tr><td colspan 2>
  <br><br><?php echo $this->_vars['l_new_info']; ?><br>
</td></tr>
</form>
<?php endif; ?>
</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>