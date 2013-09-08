<h1><?php echo $this->_vars['title']; ?></h1>

<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<FORM ACTION=profile.php METHOD=POST>
	<?php echo $this->_vars['l_profile_name']; ?> <input type="text" name="profilename" size="30" maxlength="150"><br>
	<?php echo $this->_vars['l_profile_password']; ?> <input type="password" name="profilepassword" size="20" maxlength="20">&nbsp;&nbsp;
	<input type="hidden" name="command" value="Register">
	<input type="hidden" name="url" value="<?php echo $this->_vars['url']; ?>">
	<input type="hidden" name="game" value="<?php echo $this->_vars['game']; ?>">
	<INPUT TYPE=SUBMIT VALUE="Register">
	</form>
</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
