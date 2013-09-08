<h1><?php echo $this->_vars['title']; ?></h1>

<?php echo $this->_vars['clean_javascript']; ?>
<?php echo '
<SCRIPT LANGUAGE="JavaScript">
<!--
	function MakeMax(name, val)
	{
	 if (document.forms[0].elements[name].value != val)
	 {
	  if (val != 0)
	  {
	  document.forms[0].elements[name].value = val;			  
	  }			  
	 }	 
	}
 
function Comma(number) {
	number = \'\' + Math.round(number);
	if (number.length > 3) {
		var output = \'\';
		var count = 0;
		for (i=number.length ; i > 0; i--) {
			count += 1;
			if ( count != 3)
			{
				output = number.substring(i - 1, i) + output;
			}
			else
			{
				if (i != 1)
				{
					output = \',\' + number.substring(i - 1, i) + output;
				}
				else
				{
					output = number.substring(i - 1, i) + output;
				}
				count = 0;
			}
		}
		return (output);
	}
	else return number;
}

// changeDelta function //
function mypw(one,two)
{
	return Math.exp(two * Math.log(one));
}

function changeDelta(desiredvalue,currentvalue)
{
	return (mypw(';  echo $this->_vars['upgrade_factor'];  echo ', desiredvalue) - mypw(';  echo $this->_vars['upgrade_factor'];  echo ', currentvalue)) * ';  echo $this->_vars['upgrade_cost'];  echo ';
}

function countTotal()
{
	// Here we cycle through all form values (other than buy, or full), and regexp out all non-numerics. (1,000 = 1000)
	// Then, if its become a null value (type in just a, it would be a blank value. blank is bad.) we set it to zero.
	clean_js()
	var form = document.forms[0];
	var i = form.elements.length;
	while (i > 0)
	{
		if (form.elements[i-1].value == \'\')
		{
			form.elements[i-1].value =\'0\';
		}
		i--;
	}
	// Pluses must be first, or if empty will produce a javascript error
	form.total_cost.value = Comma(changeDelta(form.sensors_upgrade.value,';  echo $this->_vars['probe_sensors'];  echo ')
	+ changeDelta(form.cloak_upgrade.value,';  echo $this->_vars['probe_cloak'];  echo ')
	+ changeDelta(form.engines_upgrade.value,';  echo $this->_vars['probe_engines'];  echo '));

	if (form.total_cost.value > ';  echo $this->_vars['player_credits'];  echo ')
	{
		form.total_cost.value = \'';  echo $this->_vars['l_no_credits'];  echo '\';
	}

	form.sensors_costper.value=Comma(changeDelta(form.sensors_upgrade.value,';  echo $this->_vars['probe_sensors'];  echo '));
	form.cloak_costper.value=Comma(changeDelta(form.cloak_upgrade.value,';  echo $this->_vars['probe_cloak'];  echo '));
	form.engines_costper.value=Comma(changeDelta(form.engines_upgrade.value,';  echo $this->_vars['probe_engines'];  echo '));
}
// -->
</SCRIPT>
'; ?>


<table border="1" cellspacing="0" cellpadding="0" width="500" align="center">
	<TR BGCOLOR="#585980">
		<TD colspan="8" align="center"><font color="white"><B><?php echo $this->_vars['l_probe_named']; ?></B></font></TD>
	</TR>
	<TR BGCOLOR="#23244F">
		<TD>
			<?php echo $this->_vars['l_creds_to_spend']; ?><br>
			<?php if ($this->_vars['allow_ibank']): ?>
				<?php echo $this->_vars['l_ifyouneedmore']; ?>
			<?php endif; ?>
		</TD>
	</TR>
	<TR BGCOLOR="#23244F">
		<TD>
			<FORM ACTION='probes_upgrade_finish.php?probe_id=<?php echo $this->_vars['probe_id']; ?>&probeupgrade=yes' METHOD=POST>
			<TABLE WIDTH="100%" BORDER="0" CELLSPACING="0" CELLPADDING="0">
				<TR BGCOLOR="#585980">
					<TD><B><?php echo $this->_vars['l_probe_defense_levels']; ?></B></TD>
					<TD><B><?php echo $this->_vars['l_cost']; ?></B></TD>
					<TD><B><?php echo $this->_vars['l_current_level']; ?></B></TD>
					<TD><B><?php echo $this->_vars['l_upgrade']; ?></B></TD>
				</TR>
				<TR BGCOLOR="#3A3B6E">
					<TD><?php echo $this->_vars['l_engine']; ?></TD>
					<td><input type="text" readonly class='portcosts1' name="engines_costper"  VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
					<TD><?php echo $this->_vars['probe_engines']; ?></TD>
					<TD><?php echo $this->_vars['dropdown_engines']; ?></TD>
				</TR>

				<TR BGCOLOR="#23244F">
					<TD><?php echo $this->_vars['l_sensors']; ?></TD>
					<td><input type="text" readonly class='portcosts2' name="sensors_costper"  VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
					<TD><?php echo $this->_vars['probe_sensors']; ?></TD>
					<TD><?php echo $this->_vars['dropdown_sensors']; ?></TD>
				</TR>

				<TR BGCOLOR="#3A3B6E">
					<TD><?php echo $this->_vars['l_cloak']; ?></TD>
					<td><input type="text" readonly class='portcosts1' name="cloak_costper"  VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
					<TD><?php echo $this->_vars['probe_cloak']; ?></TD>
					<TD><?php echo $this->_vars['dropdown_cloak']; ?></TD>
				</TR>
				<tr>
					<TD><INPUT TYPE="SUBMIT" VALUE="<?php echo $this->_vars['l_buy']; ?>" ONCLICK="countTotal()"></TD>
					<TD ALIGN="RIGHT"><?php echo $this->_vars['l_totalcost']; ?>: <INPUT TYPE="TEXT" style="text-align:right" NAME="total_cost" SIZE="28" VALUE="0" ONFOCUS="countTotal()" ONBLUR="countTotal()" ONCHANGE="countTotal()" ONCLICK="countTotal()"></td>
				</tr>
			</TABLE>
			</FORM>
		</TD>
	</TR>
</TABLE>
<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
	<tr>
		<td><br><a href="probes_upgrade.php?probe_id=<?php echo $this->_vars['probe_id']; ?>"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_probe_linkback']; ?>.
		</td>
	</tr>
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
</table>
