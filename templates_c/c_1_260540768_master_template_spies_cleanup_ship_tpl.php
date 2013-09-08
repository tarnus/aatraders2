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
  <B><?php echo $this->_vars['l_spy_cleanupshiptitle']; ?></B><BR>
  <?php if ($this->_vars['executecommand']): ?> 
	<FORM ACTION=spy.php METHOD=POST>
	<INPUT TYPE=hidden name=command value=cleanup_ship>
	<INPUT TYPE=hidden name=doit value=1>
	<INPUT TYPE=RADIO NAME=type VALUE=1 <?php echo $this->_vars['set1']; ?>> <?php echo $this->_vars['l_spy_cleanupshiptext1']; ?><BR>
	<INPUT TYPE=RADIO NAME=type VALUE=2 <?php echo $this->_vars['set2']; ?>> <?php echo $this->_vars['l_spy_cleanupshiptext2']; ?><BR>
	<INPUT TYPE=RADIO NAME=type VALUE=3 <?php echo $this->_vars['set3']; ?>> <?php echo $this->_vars['l_spy_cleanupshiptext3']; ?><BR><BR>
	
	<?php if ($this->_vars['disabled']): ?>
		<?php echo $this->_vars['cleanupstatus']; ?>
	<?php else: ?>
		<INPUT TYPE=submit value="<?php echo $this->_vars['cleanupstatus']; ?>">
	<?php endif; ?>
	
	</FORM>
  <?php else: ?>
	<B><?php echo $this->_vars['l_spy_cleanupshiptitle2']; ?></B><BR>

	<?php if ($this->_vars['disabled'] != "DISABLED"): ?>
		<?php extract($this->_vars, EXTR_REFS);  
	  	for($i = 0; $i < $spycount; $i++)
		{
			echo "$spyinfo[$i]<BR>";
		}
   		 ?>
		
	  <?php if (! $this->_vars['found']): ?>
		<?php echo $this->_vars['l_spy_spynotfoundonship']; ?><BR>
	  <?php endif; ?>
	<?php else: ?>
		<BR><?php echo $this->_vars['l_spy_notenough']; ?><BR>
	<?php endif; ?>
  <?php endif; ?>
	<a href=spy.php><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_spy_menu']; ?>

</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
