<H1><?php echo $this->_vars['title']; ?></H1><br>
<table width="750" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD><p><b><?php echo $this->_vars['l_sector']; ?>:</b> <?php echo $this->_vars['destination']; ?></p> 
		<form action=main.php method=post>
		<?php echo $this->_vars['l_chf_therearetotalfightersindest']; ?><br>
		<?php echo $this->_vars['l_chf_therearetotalminesindest']; ?><br>
		<INPUT TYPE=RADIO NAME=response CHECKED VALUE=retreat><?php echo $this->_vars['l_chf_youcanretreat']; ?><BR>
		<INPUT TYPE=RADIO NAME=response VALUE=fight><?php echo $this->_vars['l_chf_inputfight']; ?><BR><?php echo $this->_vars['has_fighters']; ?>
<?php if ($this->_vars['sector_zone_id'] != 2 && $this->_vars['has_fighters'] > 0): ?>
		<INPUT TYPE=RADIO NAME=response VALUE=run><?php echo $this->_vars['l_chf_inputrun']; ?><BR>
<?php endif; ?>
		<INPUT TYPE=RADIO NAME=response VALUE=sneak><?php echo $this->_vars['l_chf_inputcloak']; ?><br><BR>
		<input type=submit value=<?php echo $this->_vars['l_chf_go']; ?>><br><br>
		<input type=hidden name=move_method value=<?php echo $this->_vars['move_method']; ?>>
		<input type=hidden name=move_defense_type value='perform'>
		<input type=hidden name=destination value=<?php echo $this->_run_modifier($this->_vars['destination'], 'urlencode', 'PHP', 1); ?>>
		</form>
</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
