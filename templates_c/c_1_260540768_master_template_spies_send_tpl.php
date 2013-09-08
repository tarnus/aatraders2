<h1><?php echo $this->_vars['title']; ?></h1>

<?php echo '
	<style type="text/css">
		.border {
			border-collapse: collapse; 
			border: 1px solid #ccc; 
		}
		.yellow { color: yellow; }
		.white { color: white; }
	</style>
'; ?>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	<?php if ($this->_vars['executecommand']): ?>
		<?php echo $this->_vars['bountystatus']; ?><BR><BR>

		<B><?php echo $this->_vars['l_spy_sendtitle']; ?></B><BR>
		<FORM ACTION=spy.php METHOD=POST>
		<INPUT TYPE=hidden name=command value=send>
		<INPUT TYPE=hidden name=doit value=1>
		<INPUT TYPE=hidden name=planet_id value=<?php echo $this->_vars['planet_id']; ?>>
		<INPUT TYPE=RADIO NAME=mode VALUE=none><?php echo $this->_vars['l_spy_type1']; ?><BR>
		<INPUT TYPE=RADIO NAME=mode VALUE=toship CHECKED><?php echo $this->_vars['l_spy_type2']; ?><BR>
		<INPUT TYPE=RADIO NAME=mode VALUE=toplanet><?php echo $this->_vars['l_spy_type3']; ?><BR><BR>
		
		<?php echo $this->_vars['l_spy_trytitle']; ?>:<BR>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['job_name']), 'iteration' => 0);
if (count((array)$this->_vars['job_name'])): foreach ((array)$this->_vars['job_name'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<?php if ($this->_vars['jobid'] == $this->_vars['key']): ?>
				<INPUT TYPE="radio" name="jobid" value="<?php echo $this->_vars['key']; ?>" CHECKED> <?php echo $this->_vars['job_name'][$this->_vars['key']]; ?> - <?php echo $this->_vars['description'][$this->_vars['key']]; ?><br>
			<?php else: ?>
				<INPUT TYPE="radio" name="jobid" value="<?php echo $this->_vars['key']; ?>"> <?php echo $this->_vars['job_name'][$this->_vars['key']]; ?> - <?php echo $this->_vars['description'][$this->_vars['key']]; ?><br>
			<?php endif; ?>
		<?php endforeach; endif; ?>
			<br>
		<INPUT TYPE=submit value="<?php echo $this->_vars['l_spy_sendbutton']; ?>">
		</FORM>
	<?php else: ?>
		<?php echo $this->_vars['playerbounty']; ?><br><br>
		<?php echo $this->_vars['sendstatus']; ?><br><br>
	<?php endif; ?>   
	<a href=planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><br>
	<a href=spy.php><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_spy_menu']; ?>

</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
