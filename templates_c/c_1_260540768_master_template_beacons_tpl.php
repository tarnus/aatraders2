<h1><?php echo $this->_vars['title']; ?></h1>

<form action=beacon.php method=post>
<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0">
			<TR>
				<TD colspan=2>
<?php echo $this->_vars['beacon_info']; ?><br><br></td></tr>
<tr><td><?php echo $this->_vars['l_beacon_enter']; ?>:</td><td><input type=text name=beacon_text size=40 maxlength=50><br><br></td></tr>
<tr><td align="center"><input type=submit value=<?php echo $this->_vars['l_submit']; ?>></td><td align="center"><input type=reset value=<?php echo $this->_vars['l_reset']; ?>>
				</td>
			</tr>
<tr><td colspan="2"><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

</form>

