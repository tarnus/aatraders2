<H1><?php echo $this->_vars['title']; ?></H1>
<?php echo '
<script language="javascript" type="text/javascript">
function clean_js()
{
	// Here we cycle through all form values (other than buy, or full), and regexp out all non-numerics. (1,000 = 1000)
	// Then, if its become a null value (type in just a, it would be a blank value. blank is bad.) we set it to zero.
	var form = document.forms[0];
	var i = form.elements.length;
	while (i > 0)
	{
		if ((form.elements[i-1].type == \'text\') && (form.elements[i-1].name != \'\'))
		{
			var tmpval = form.elements[i-1].value.replace(/\\D+/g, "");
			if (tmpval != form.elements[i-1].value)
			{
				form.elements[i-1].value = form.elements[i-1].value.replace(/\\D+/g, "");
			}
		}
		if (form.elements[i-1].value == \'\')
		{
			form.elements[i-1].value =\'0\';
		}
		i--;
	}
}
</script>
'; ?>

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

function mypw(one,two)
{
	return Math.exp(two * Math.log(one));
}

function SDchangeDelta(desiredvalue,currentvalue)
{
	return (mypw(';  echo $this->_vars['planet_SD_upgrade_factor'];  echo ', desiredvalue) - mypw(';  echo $this->_vars['planet_SD_upgrade_factor'];  echo ', currentvalue)) * ';  echo $this->_vars['upgrade_cost'];  echo ';
}

function changeDelta(desiredvalue,currentvalue)
{
	return (mypw(';  echo $this->_vars['planet_upgrade_factor'];  echo ', desiredvalue) - mypw(';  echo $this->_vars['planet_upgrade_factor'];  echo ', currentvalue)) * ';  echo $this->_vars['upgrade_cost'];  echo ';
}

function MaxCreditsDelta(desiredvalue,currentvalue)
{
	return MaxCreditsPOW(';  echo $this->_vars['planet_upgrade_factor'];  echo ', desiredvalue) * ';  echo $this->_vars['upgrade_cost'];  echo ';
}

function MaxCreditsPOW($one,$two)
{
	var $oldvalue = 0;
	var $breakpoint = Math.floor(';  echo $this->_vars['max_tech_level'];  echo ' * 0.435);
	if($two > $breakpoint)
	{
		var $oldvalue = mypw($one,$breakpoint);
		var $multiplier = mypw($one,$breakpoint) - mypw($one,($breakpoint - 1));
		var $numberlevels = $two - $breakpoint;
		var $newvalue = $numberlevels * ($multiplier + mypw($one, ($two - $breakpoint)));

		var $breakpoint2 = Math.floor(';  echo $this->_vars['max_tech_level'];  echo ' * 0.62);
		if($two > $breakpoint2)
		{
			$numberlevels = $breakpoint2 - $breakpoint;
			$newvalue = $numberlevels * ($multiplier + mypw($one, ($breakpoint2 - $breakpoint)));
			$numberlevels = $breakpoint2 - $breakpoint + 1;
			$newvalue2 = $numberlevels * ($multiplier + mypw($one, ($breakpoint2 - $breakpoint)));
			$increment = $newvalue2 - $newvalue;
			$newvalue = ($increment * ($two - $breakpoint)) + (110000 * ($two - $breakpoint2));
			return $newvalue + $oldvalue;
		}
		else
		{
			return $newvalue + $oldvalue;
		}
	}
	else
	{
		return mypw($one,$two);
	}
}

function countTotal()
{
	clean_js()
	var form = document.forms[0];
	var i = form.elements.length;
	max_credits=0;
	while (i > 0)
	  {
	 if (form.elements[i-1].value == \'\')
	  {
	  form.elements[i-1].value =\'0\';
	  }
	 i--;
	}
	if (form.overall_upgrade.value > ';  echo $this->_vars['minoverall'];  echo '){
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_fighter'];  echo ' && ';  echo $this->_vars['java_fighter'];  echo ' == ';  echo $this->_vars['java_fighter_normal'];  echo '){
			form.fighter_upgrade.value=form.overall_upgrade.value;
		}else{
			form.fighter_upgrade.value=';  echo $this->_vars['java_fighter'];  echo ';
		}
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_sensors'];  echo ' && ';  echo $this->_vars['java_sensors'];  echo ' == ';  echo $this->_vars['java_sensors_normal'];  echo '){
			form.sensors_upgrade.value=form.overall_upgrade.value;
		}else{
			form.sensors_upgrade.value=';  echo $this->_vars['java_sensors'];  echo ';
		}
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_beams'];  echo ' && ';  echo $this->_vars['java_beams'];  echo ' == ';  echo $this->_vars['java_beams_normal'];  echo '){
			form.beams_upgrade.value=form.overall_upgrade.value;
		}else{
			form.beams_upgrade.value=';  echo $this->_vars['java_beams'];  echo ';
		}
			
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_cloak'];  echo ' && ';  echo $this->_vars['java_cloak'];  echo ' == ';  echo $this->_vars['java_cloak_normal'];  echo '){
			form.cloak_upgrade.value=form.overall_upgrade.value;
		}else{
			form.cloak_upgrade.value=';  echo $this->_vars['java_cloak'];  echo ';
		}
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_torps'];  echo ' && ';  echo $this->_vars['java_torps'];  echo ' == ';  echo $this->_vars['java_torps_normal'];  echo '){
			form.torp_launchers_upgrade.value=form.overall_upgrade.value;
		}else{
			form.torp_launchers_upgrade.value=';  echo $this->_vars['java_torps'];  echo ';
		}
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_shields'];  echo ' && ';  echo $this->_vars['java_shields'];  echo ' == ';  echo $this->_vars['java_shields_normal'];  echo '){
			form.shields_upgrade.value=form.overall_upgrade.value;
		}else{
			form.shields_upgrade.value=';  echo $this->_vars['java_shields'];  echo ';
		}	
		if (form.overall_upgrade.value > ';  echo $this->_vars['java_jammer'];  echo ' && ';  echo $this->_vars['java_jammer'];  echo ' == ';  echo $this->_vars['java_jammer_normal'];  echo '){
			form.jammer_upgrade.value=form.overall_upgrade.value;
		}else{
			form.jammer_upgrade.value=';  echo $this->_vars['java_jammer'];  echo ';
		}
		
	}
	
	form.max_credits.value =
	Comma(((MaxCreditsDelta(form.fighter_upgrade.value, 0)
	+ MaxCreditsDelta(form.sensors_upgrade.value, 0)
	+ MaxCreditsDelta(form.beams_upgrade.value, 0)
	+ MaxCreditsDelta(form.cloak_upgrade.value, 0)
	+ MaxCreditsDelta(form.torp_launchers_upgrade.value, 0)
	+ MaxCreditsDelta(form.shields_upgrade.value, 0)
	+ MaxCreditsDelta(form.jammer_upgrade.value, 0)) * ';  echo $this->_vars['planet_credit_multi'];  echo ') + ';  echo $this->_vars['base_credits'];  echo ')
	;

	form.planet_ratio.value =
	Math.round((';  echo $this->_vars['planet_credits'];  echo ' / (((MaxCreditsDelta(form.fighter_upgrade.value, 0)
	+ MaxCreditsDelta(form.sensors_upgrade.value, 0)
	+ MaxCreditsDelta(form.beams_upgrade.value, 0)
	+ MaxCreditsDelta(form.cloak_upgrade.value, 0)
	+ MaxCreditsDelta(form.torp_launchers_upgrade.value, 0)
	+ MaxCreditsDelta(form.shields_upgrade.value, 0)
	+ MaxCreditsDelta(form.jammer_upgrade.value, 0)) * ';  echo $this->_vars['planet_credit_multi'];  echo ') + ';  echo $this->_vars['base_credits'];  echo ')) * 100)
	;
	
	form.total_cost.value =
	Comma(changeDelta(form.fighter_upgrade.value,';  echo $this->_vars['java_fighter'];  echo ')
	+ changeDelta(form.sensors_upgrade.value,';  echo $this->_vars['java_sensors'];  echo ')
	+ changeDelta(form.beams_upgrade.value,';  echo $this->_vars['java_beams'];  echo ')
	+ changeDelta(form.cloak_upgrade.value,';  echo $this->_vars['java_cloak'];  echo ')
	+ changeDelta(form.torp_launchers_upgrade.value,';  echo $this->_vars['java_torps'];  echo ')
	+ changeDelta(form.shields_upgrade.value,';  echo $this->_vars['java_shields'];  echo ')
	+ changeDelta(form.jammer_upgrade.value,';  echo $this->_vars['java_jammer'];  echo ')
	+ SDchangeDelta(form.sector_defense_weapons_upgrade.value,';  echo $this->_vars['java_sector_defense_weapons'];  echo ')
	+ SDchangeDelta(form.sector_defense_sensors_upgrade.value,';  echo $this->_vars['java_sector_defense_sensors'];  echo ')
	+ SDchangeDelta(form.sector_defense_cloak_upgrade.value,';  echo $this->_vars['java_sector_defense_cloak'];  echo '))
	;
	  if (form.total_cost.value > ';  echo $this->_vars['java_credits'];  echo ')
	  {
		form.total_cost.value = \'';  echo $this->_vars['l_no_credits'];  echo '\';
	  }
	  form.total_cost.length = form.total_cost.value.length;
	
	form.fighter_costper.value=Comma(changeDelta(form.fighter_upgrade.value,';  echo $this->_vars['java_fighter'];  echo '));
	form.sensors_costper.value=Comma(changeDelta(form.sensors_upgrade.value,';  echo $this->_vars['java_sensors'];  echo '));
	form.beams_costper.value=Comma(changeDelta(form.beams_upgrade.value,';  echo $this->_vars['java_beams'];  echo '));
	form.cloak_costper.value=Comma(changeDelta(form.cloak_upgrade.value,';  echo $this->_vars['java_cloak'];  echo '));
	form.torp_launchers_costper.value=Comma(changeDelta(form.torp_launchers_upgrade.value,';  echo $this->_vars['java_torps'];  echo '));
	form.shields_costper.value=Comma(changeDelta(form.shields_upgrade.value,';  echo $this->_vars['java_shields'];  echo '));
	form.jammer_costper.value=Comma(changeDelta(form.jammer_upgrade.value,';  echo $this->_vars['java_jammer'];  echo '));
	form.sector_defense_weapons_costper.value=Comma(SDchangeDelta(form.sector_defense_weapons_upgrade.value,';  echo $this->_vars['java_sector_defense_weapons'];  echo '));
	form.sector_defense_sensors_costper.value=Comma(SDchangeDelta(form.sector_defense_sensors_upgrade.value,';  echo $this->_vars['java_sector_defense_sensors'];  echo '));
	form.sector_defense_cloak_costper.value=Comma(SDchangeDelta(form.sector_defense_cloak_upgrade.value,';  echo $this->_vars['java_sector_defense_cloak'];  echo '));
	
	
	
	}
	// -->
	</SCRIPT>
	'; ?>


	<FORM ACTION='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=upgradefinal' METHOD=POST>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=0 width="100%" align="center">
		<TR BGCOLOR="#585980">
			<TD align="center"><B><?php echo $this->_vars['l_planetary_credits']; ?></B></TD>
			<TD align="center"><B><?php echo $this->_vars['l_max_credits']; ?></B></TD>
			<TD align="center"><B><?php echo $this->_vars['l_overall']; ?></B></TD>
		</TR>
		<TR BGCOLOR="#3A3B6E">
			<TD align="center" ><?php echo $this->_vars['planet_creditsout']; ?> - <input type=text readonly class='portcosts_sm1' name=planet_ratio VALUE='<?php echo $this->_vars['planet_ratio']; ?>' tabindex='-1' ONBLUR="countTotal()">%</TD>
			<TD align="center"><input type=text readonly class='portcosts1' name=max_credits VALUE='<?php echo $this->_vars['planet_max_creditsout']; ?>' tabindex='-1' ONBLUR="countTotal()"></TD>
			<TD align="center"><?php echo $this->_vars['planet_overall']; ?></TD>
		</TR>
	</table>
	<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
		<tr>
			<td colspan = "2"><img src = "templates/master_template/images/spacer.gif" width = "1" height = "10"></td>
		</tr>
		<TR BGCOLOR="#585980">
		<TD><B><?php echo $this->_vars['l_planetary_defense_levels']; ?></B></TD><TD><B><?php echo $this->_vars['l_cost']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_current_level']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_upgrade']; ?></B></TD>
		</TR>

	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_fighter']; ?></TD>
	<td><input type=text readonly class='portcosts1' name=fighter_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetfighter']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetfighter_normal'] == $this->_vars['planetfighter']): ?>
		<?php echo $this->_vars['planet_fighter']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="fighter_upgrade" value="<?php echo $this->_vars['planetfighter']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_sensors']; ?></TD>
	<td><input type=text readonly class='portcosts2' name=sensors_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetsensors']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetsensors_normal'] == $this->_vars['planetsensors']): ?>
		<?php echo $this->_vars['planet_sensors']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="sensors_upgrade" value="<?php echo $this->_vars['planetsensors']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_beams']; ?></TD>
	<td><input type=text readonly class='portcosts1' name=beams_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetbeams']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetbeams_normal'] == $this->_vars['planetbeams']): ?>
		<?php echo $this->_vars['planet_beams']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="beams_upgrade" value="<?php echo $this->_vars['planetbeams']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_torp_launch']; ?></TD>
	<td><input type=text readonly class='portcosts2' name=torp_launchers_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planettorps']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planettorps_normal'] == $this->_vars['planettorps']): ?>
		<?php echo $this->_vars['planet_torps']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="torp_launchers_upgrade" value="<?php echo $this->_vars['planettorps']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_shields']; ?></TD>
	<td><input type=text readonly class='portcosts1' name=shields_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetshields']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetshields_normal'] == $this->_vars['planetshields']): ?>
		<?php echo $this->_vars['planet_shields']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="shields_upgrade" value="<?php echo $this->_vars['planetshields']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_jammer']; ?></TD>
	<td><input type=text readonly class='portcosts1' name=jammer_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetjammer']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetjammer_normal'] == $this->_vars['planetjammer']): ?>
		<?php echo $this->_vars['planet_jammer']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="jammer_upgrade" value="<?php echo $this->_vars['planetjammer']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_cloak']; ?></TD>
	<td><input type=text readonly class='portcosts2' name=cloak_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetcloak']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetcloak_normal'] == $this->_vars['planetcloak']): ?>
		<?php echo $this->_vars['planet_cloak']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="cloak_upgrade" value="<?php echo $this->_vars['planetcloak']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_planetary_SD_weapons']; ?></TD>
	<td><input type=text readonly class='portcosts2' name=sector_defense_weapons_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetsectordefenseweapons']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetsectordefenseweapons_normal'] == $this->_vars['planetsectordefenseweapons']): ?>
		<?php echo $this->_vars['planetsector_defense_weapons']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="sector_defense_weapons_upgrade" value="<?php echo $this->_vars['planetsectordefenseweapons']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_planetary_SD_sensors']; ?></TD>
	<td><input type=text readonly class='portcosts2' name=sector_defense_sensors_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetsectordefensesensors']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetsectordefensesensors_normal'] == $this->_vars['planetsectordefensesensors']): ?>
		<?php echo $this->_vars['planetsector_defense_sensors']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="sector_defense_sensors_upgrade" value="<?php echo $this->_vars['planetsectordefensesensors']; ?>">
	<?php endif; ?>
	</TD></TR>

	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_planetary_SD_cloak']; ?></TD>
	<td><input type=text readonly class='portcosts2' name=sector_defense_cloak_costper VALUE='0' tabindex='-1' ONBLUR="countTotal()"></td>
	<TD align="center"><?php echo $this->_vars['planetsectordefensecloak']; ?></TD>
	<TD align="center">
	<?php if ($this->_vars['planetsectordefensecloak_normal'] == $this->_vars['planetsectordefensecloak']): ?>
		<?php echo $this->_vars['planetsector_defense_cloak']; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_planet_repair']; ?>
		<input type="hidden" name="sector_defense_cloak_upgrade" value="<?php echo $this->_vars['planetsectordefensecloak']; ?>">
	<?php endif; ?>
	</TD></TR>

	<tr><TD><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_buy']; ?> <?php echo $this->_vars['onclick']; ?>></TD>
	<TD ALIGN=RIGHT><?php echo $this->_vars['l_totalcost']; ?>: <INPUT TYPE=TEXT style="text-align:right" NAME=total_cost SIZE=27 VALUE=0 ONFOCUS="countTotal()" ONBLUR="countTotal()" ONCHANGE="countTotal()" ONCLICK="countTotal()"></td>
	<tr>
</table>
</td></tr>
	</FORM>
<tr><td colspan=4>
	<br><?php echo $this->_vars['l_creds_to_spend']; ?><BR>
	<?php if ($this->_vars['allow_ibank']): ?>
		<?php echo $this->_vars['l_ifyouneedmore']; ?><BR>
	<?php endif; ?>
	<BR><a href='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>'><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><BR><BR>
</td></tr>

<tr><td colspan=4><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
