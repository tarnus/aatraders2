<h1><?php echo $this->_vars['title']; ?></h1>


<table border="1" cellspacing="1" cellpadding="2" width="80%" align="center">
	<TR BGCOLOR="#585980">
		<TD align="center"><font color="white"><B><?php echo $this->_vars['l_probe_named']; ?></B></font></TD>
	</TR>
	<TR BGCOLOR="#23244F">
		<TD align="center">
			<form action="probes_upgrade.php?probe_id=<?php echo $this->_vars['probe_id']; ?>&command=orders_finish" method="post">
			<table border="1" cellspacing="0" cellpadding="0" align="center">
				<tr>
					<td colspan="2"><div align="center"><?php echo $this->_vars['l_probe_type']; ?></div></td><td colspan="10"><div align="center">Probe Settings</div></td>
				</tr>
					<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['probetypeinfo']), 'iteration' => 0);
if (count((array)$this->_vars['probetypeinfo'])): foreach ((array)$this->_vars['probetypeinfo'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
<tr><td colspan="2"><div align="left">
<input type="radio" name="new_type" value="<?php echo $this->_vars['key']; ?>" 
	<?php if ($this->_vars['probe_type'] == $this->_vars['key']): ?>
		checked
	<?php endif; ?>
> <?php echo $this->_vars['probetypeinfo'][$this->_vars['key']]; ?><br><hr>
<?php echo $this->_vars['probedescription'][$this->_vars['key']]; ?> 
</div></td>
<?php extract($this->_vars, EXTR_REFS);  

for($i = 0; $i < $probeordercount[$key]; $i++){
	$newkey = $key . $i;
    echo"<td>\n";
         echo"<b><font color=\"#00ff00\"><i><b>$info[$newkey]</b></i></font> :</b>&nbsp;&nbsp;<br>\n";
		if($input_type[$newkey] == 'list')
		{
			$selections = explode(",", $input_selections[$newkey]);
			$selection_count = count($selections);
			echo "<select name=\"$variable_name[$newkey]\">";
			for($item = 0; $item < $selection_count; $item++)
			{
				$values = explode("=", $selections[$item]);
				$value = trim($values[0]);
				if($value == $variable_value[$newkey])
					$checked = "selected";
				else $checked = "";
				echo "<option value=\"$value\" $checked>" . trim($values[1]) . "</option>\n";
			}
			echo "</select>";
		}
		else
		if($input_type[$newkey] == 'radio')
		{
			$selections = explode(",", $input_selections[$newkey]);
			$selection_count = count($selections);
			for($item = 0; $item < $selection_count; $item++)
			{
				$values = explode("=", $selections[$item]);
				$value = trim($values[0]);
				if($value == $variable_value[$newkey])
					$checked = "checked";
				else $checked = "";
				echo"<input type=\"radio\" name=\"$variable_name[$newkey]\" value=\"" . $value . "\" $checked>" . trim($values[1]) . "<br>\n";
			}
		}
		else
		{
	      echo"<input type=\"text\" name=\"$variable_name[$newkey]\" value=\"$variable_value[$newkey]\" size=\"40\">\n";
		}
   echo" </td>\n";
}
 ?>
</tr>
<tr><td colspan="10">
	<hr>
</td>
</tr>
<?php endforeach; endif; ?>

				<tr>
					<td><input type="reset" value="<?php echo $this->_vars['l_reset']; ?>"></td>
					<td colspan="4">&nbsp;</td>
					<td align="right"><input type="submit" value="<?php echo $this->_vars['l_submit']; ?>"></td>
				</tr>
			</table>
			</form>
		</TD>
	</TR>
</TABLE>
<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
	<tr>
		<td><a href="probes_upgrade.php?probe_id=<?php echo $this->_vars['probe_id']; ?>"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_probe_linkback']; ?>.
		</td>
	</tr>
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
</table>
