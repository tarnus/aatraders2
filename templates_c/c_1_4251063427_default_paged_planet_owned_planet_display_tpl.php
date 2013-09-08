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


<FORM ACTION=planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=production METHOD=POST>
  
<table width="800" border="1" cellspacing="0" cellpadding="4" align="center" bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr> 
    <td colspan="2" align="right"><table border="1" width="250" cellspacing="0" cellpadding="0" bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td>
      <table width="250" height="42" border="0" cellspacing="0" cellpadding="0" >
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_fighter']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetfighter_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
          <td><?php echo $this->_vars['fighterbar_normal']; ?></td>
        </tr>
        <tr valign="top"> 
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetfighter']; ?></font></td>
          <td><?php echo $this->_vars['fighterbar']; ?></td>
        </tr>
      </table></td></tr></table>
    </td>
    <td rowspan="4" align="center" valign="middle"> 
      <table width="100%" border="0" cellspacing="0" cellpadding="0" height="100%" align="center">
        <tr> 
          <td align="center"> 
			<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/" . $this->_vars['templatename'] . "images/planet" . $this->_vars['planettype'] . ".png", 'alt' => "", 'width' => "100", 'height' => "100")); ?><br>
            <font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetname']; ?></font><br><br>
          </td>
        </tr>
		<tr>
		<td align="center">
		<font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['l_planet_name']; ?></font><br>
		  <font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php if ($this->_vars['allow_genesis_destroy'] == 1): ?>
			<A onclick="javascript: alert ('alert:<?php echo $this->_vars['l_planet_warning']; ?>');" HREF='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&destroy=1&command=destroy'><?php echo $this->_vars['l_planet_destroyplanet']; ?></a><br>
			<?php endif; ?>
			</font>
		</td>
		</tr>
      </table>
    </td>
    <td colspan="3" height="50"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td>
      <table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_sensors']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['sensorbar_normal']; ?></td>
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsensors_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['sensorbar']; ?></td>
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsensors']; ?></font></td>
        </tr>
      </table></td></tr></table>
    </td>
  </tr>
  <tr> 
    <td height="50"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td><table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_beams']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetbeams_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
          <td><?php echo $this->_vars['beambar_normal']; ?></td>
        </tr>
        <tr valign="top"> 
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetbeams']; ?></font></td>
          <td><?php echo $this->_vars['beambar']; ?></td>
        </tr>
      </table></td></tr></table>
    </td>
    <td rowspan="2" width="55" height="100"> 
      <table width="55" border="0" cellspacing="0" cellpadding="0">
        <tr> 
          <td align="center">
<font color="#FFFFFF" style="font-size:11px; font-weight:bold;">&nbsp;<?php echo $this->_vars['l_planet_transfer_link']; ?></font>
</td>
        </tr>
      </table>
    </td>
    <td rowspan="2" width="55" height="100"> 
      <table width="55" border="0" cellspacing="0" cellpadding="0">
        <tr> 
          <td align="center">
		  	<?php if ($this->_vars['planetbased'] == "Y"): ?>	 
				<font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><a href="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=upgrade"><?php echo $this->_vars['l_planet_upgrade']; ?></a></font><br><br>
				<font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><a href="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=repair"><?php echo $this->_vars['l_planet_repair']; ?></a></font>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
</td>
        </tr>
      </table>
    </td>
    <td colspan="2" height="50" align="right"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td>
      <table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_jammer']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['jammerbar_normal']; ?></td>
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetjammer_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['jammerbar']; ?></td>
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetjammer']; ?></font></td>
        </tr>
      </table></td></tr></table>
    </td>
  </tr>
  <tr> 
    <td height="50"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td><table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_torp_launch']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planettorps_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
          <td><?php echo $this->_vars['torpbar_normal']; ?></td>
        </tr>
        <tr valign="top"> 
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planettorps']; ?></font></td>
          <td><?php echo $this->_vars['torpbar']; ?></td>
        </tr>
      </table></td></tr></table>
    </td>
    <td colspan="2" height="50" align="right"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td><table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_cloak']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['cloakbar_normal']; ?></td>
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetcloak_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['cloakbar']; ?></td>
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetcloak']; ?></font></td>
        </tr>
      </table></td></tr></table>
    </td>
  </tr>
  <tr> 
    <td colspan="2" align="right"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td><table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_armor']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetarmor_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
          <td><?php echo $this->_vars['armorbar_normal']; ?></td>
        </tr>
        <tr valign="top"> 
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetarmor']; ?></font></td>
          <td><?php echo $this->_vars['armorbar']; ?></td>
        </tr>
      </table></td></tr></table>
    </td>
    <td colspan="3" height="50"><table border="1" width="250" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td>
      <table width="250" height="42" border="0" cellspacing="0" cellpadding="0">
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_shields']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['shieldbar_normal']; ?></td>
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetshields_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['shieldbar']; ?></td>
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetshields']; ?></font></td>
        </tr>
      </table></td></tr></table>
    </td>
  </tr>

  <tr> 
    <td colspan="1">
      <table width="250" height="42" border="1" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;">
        <tr align="center" valign="top"> 
          <td>
	      <table width="100%" border="0" cellspacing="0" cellpadding="0" >
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_SD_weapons']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsector_defense_weapons_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
          <td><?php echo $this->_vars['sector_defense_weaponsbar_normal']; ?></td>
        </tr>
        <tr valign="top"> 
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsector_defense_weapons']; ?></font></td>
          <td><?php echo $this->_vars['sector_defense_weaponsbar']; ?></td>
        </tr>
      </table>
	  </td>
	  </tr>
	  </table>
    </td>
    <td colspan="3" height="50" align="center">
      <table width="250" height="42" border="1" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;">
        <tr align="center" valign="top"> 
          <td>
	      <table width="100%" border="0" cellspacing="0" cellpadding="0" >
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_SD_sensors']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['sector_defense_sensorsbar_normal']; ?></td>
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsector_defense_sensors_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['sector_defense_sensorsbar']; ?></td>
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsector_defense_sensors']; ?></font></td>
        </tr>
      </table>
	  </td>
	  </tr>
	  </table>
    </td>
    <td colspan="1" height="50">
      <table width="250" height="42" border="1" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;">
        <tr align="center" valign="top"> 
          <td>
	      <table width="100%" border="0" cellspacing="0" cellpadding="0" >
        <tr align="center" valign="top"> 
          <td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_SD_cloak']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['sector_defense_cloakbar_normal']; ?></td>
          <td width="150" align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_normal']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsector_defense_cloak_normal']; ?></font><font color="white" style="font-size:11px; font-weight:bold;"> - <?php echo $this->_vars['l_max']; ?> <?php echo $this->_vars['max_tech_level']; ?></font></td>
        </tr>
        <tr valign="top"> 
          <td align="right"><?php echo $this->_vars['sector_defense_cloakbar']; ?></td>
          <td align="center"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_damaged']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetsector_defense_cloak']; ?></font></td>
        </tr>
      </table>
	  </td>
	  </tr>
	  </table>
    </td>
  </tr>

  <tr> 
    <td colspan="6">
&nbsp;
    </td>
  </tr>
  
  <tr> 
    <td colspan="6">
&nbsp;
    </td>
  </tr>
  <tr> 
    <td colspan="6">
      <table width="100%" border="0" cellspacing="0" cellpadding="0">
	  <tr>
	  	<td width="40%"><table border="1" align="center" cellspacing="0" cellpadding="0"  bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;"><tr><td><table align="center" border="1" cellspacing="0" cellpadding="0" bgcolor="#000000" bordercolorlight="#010101" bordercolordark="silver">
		<tr>
			<td colspan="2"><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_max_credits']; ?>: <font color="#87d8ec" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planet_ratio']; ?>%</font> - </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['max_credits']; ?></font></td>
</tr><tr>
<td><font color="white" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planetary_armorpts']; ?>: </font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['planetarmorpts']; ?></font></td>
</tr><tr>
<td><font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_colonists']; ?>: </font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['colonisttotal']; ?></font>
</td>
		</tr>
		<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=pfighters VALUE="<?php echo $this->_vars['fighterprod']; ?>" SIZE=3 MAXLENGTH=3><font color="white" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_fighters']; ?>:&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['fightertotal']; ?></font></td></tr>
<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=ptorp VALUE="<?php echo $this->_vars['torpprod']; ?>" SIZE=3 MAXLENGTH=3><font color="white" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_torps']; ?>:&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['torptotal']; ?></font></td></tr>
<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=penergy VALUE="<?php echo $this->_vars['energyprod']; ?>" SIZE=3 MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_energy']; ?> <?php echo $this->_vars['energypercent']; ?> :&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['energytotal']; ?></font></td></tr>
		<tr><td>
		<INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=pore VALUE="<?php echo $this->_vars['oreprod']; ?>" SIZE=3 MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_ore']; ?> <?php echo $this->_vars['orepercent']; ?> :&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['oretotal']; ?></font>
		</td></tr><tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=pgoods VALUE="<?php echo $this->_vars['goodsprod']; ?>" SIZE=3 MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_goods']; ?> <?php echo $this->_vars['goodspercent']; ?> :&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['goodstotal']; ?></font></td></tr>
<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=porganics VALUE="<?php echo $this->_vars['organicsprod']; ?>" SIZE=3 MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_organics']; ?> <?php echo $this->_vars['organicspercent']; ?> :&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['organicstotal']; ?></font></td></tr>

<?php if ($this->_vars['special_name'] != ""): ?>
	<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=pspecial VALUE="<?php echo $this->_vars['prod_special']; ?>" SIZE=3 MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['special_name']; ?> :&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['special_amount']; ?></font></td></tr>
<?php endif; ?>


<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=presearch VALUE="<?php echo $this->_vars['researchprod']; ?>" SIZE=3 MAXLENGTH=3 readonly><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_pr_research']; ?></font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;">&nbsp;</font></td></tr>
<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" NAME=pbuild VALUE="<?php echo $this->_vars['buildprod']; ?>" SIZE=3 readonly MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_pr_build']; ?></font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;">&nbsp;</font></td></tr>
<tr><td><INPUT TYPE=TEXT style="color:#52ACEA; font-size:10px; font-weight:bold; background-color:black; align:right;" readonly NAME=pcredits VALUE="<?php echo $this->_vars['creditprod']; ?>" SIZE=3 MAXLENGTH=3><font color="#FFFFFF" style="font-size:11px; font-weight:bold;">%&nbsp;<?php echo $this->_vars['l_credits']; ?>:&nbsp;</font></td><td><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['credittotal']; ?></font></td></tr>
<?php if ($this->_vars['captured_countdown'] != 0): ?>
<tr><td colspan="2" align="center" bgcolor="yellow"><font color="ff0000" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_planet_hidden_credits']; ?></font></td></tr>
<?php endif; ?>
<tr><td align="center"><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_planet_update']; ?> ONCLICK="clean_js()"></td> <td>&nbsp;</td></tr>
</table></td></tr></table>
</td><td width="60%" valign="middle">

<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
	<td><font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_turns_have']; ?> </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['playerturns']; ?></font></td><td><font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_dig']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['digtotal']; ?></font></td>
<td><font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['l_spy']; ?>: </font><font color="yellow" style="font-size:11px; font-weight:bold;"><?php echo $this->_vars['spytotal']; ?></font></td></tr>
</table>
<br>
<table width="100%" border="1" cellspacing="0" cellpadding="3" bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;">
		<tr>
			<td colspan="2">
			<table border="1" cellspacing="0" cellpadding="1" bordercolor="#52ACEA" style="border-color: 52ACEA; border-right-width: thin; border-left-width: thin; border-bottom-width: thin; border-top-width: thin;">
				<tr>
					<td align="center"><font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['l_planet_land']; ?>
			<?php if ($this->_vars['onplanet'] == 1): ?>
			&nbsp;&nbsp;<?php echo $this->_vars['logout_link']; ?>
			<?php endif; ?>
		</font></td><td align="center"><font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['l_planet_readlog']; ?></font></td><?php if ($this->_vars['igbplanet'] != 0): ?><td align="center">
			<font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><A HREF="igb.php?planet_id=<?php echo $this->_vars['igbplanet']; ?>"><?php echo $this->_vars['l_igb_term']; ?></A></font>
			</td><?php endif; ?><td align="center"><font color="#FFFFFF" style="font-size:11px; font-weight:bold;"><A HREF ="bounty.php"><?php echo $this->_vars['l_by_placebounty']; ?></A></font></td>
				</tr>
			</table>
<br>
		  <font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['l_planet_bbase']; ?></font><br>
		  <font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['l_planet_mteam']; ?></font><br>
		  <font color="#FFFFFF" style="font-size:10px; font-weight:bold;"> 
			<?php if ($this->_vars['spycleaner'] != 0): ?>
				<a href="spy.php?command=cleanup_planet&planet_id=<?php echo $this->_vars['spycleaner']; ?>"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_spy_cleanupplanet']; ?>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
			</font><br>
			<font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['cashstatus']; ?> <?php echo $this->_vars['l_planet_tcash']; ?></font><br>
		<?php if ($this->_vars['planetbased'] == "Y"): ?>
			<font color="#FFFFFF" style="font-size:10px; font-weight:bold;">
			<?php echo $this->_vars['l_main_shipyard2']; ?><a href="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=shipyard"><?php echo $this->_vars['l_main_shipyard1']; ?></a></font><br>
		<?php endif; ?>
			<br>
			<font color="#FFFFFF" style="font-size:10px; font-weight:bold;"><?php echo $this->_vars['l_planet_lastvisited']; ?></a></font><br>
			</td></tr>
		</table>
		
		</td>
	  </tr>
       
      </table>
		<table align="center">
			        <tr>
			<?php for($for1 = 0; ((0 < $this->_vars['artifactcount']) ? ($for1 < $this->_vars['artifactcount']) : ($for1 > $this->_vars['artifactcount'])); $for1 += ((0 < $this->_vars['artifactcount']) ? 1 : -1)):  $this->assign('myLoop', $for1); ?>
					<td align=center valign=top class=nav_title_12>
					<a href="artifact_grab.php?artifact_id=<?php echo $this->_vars['artifact_id'][$this->_vars['myLoop']]; ?>" onMouseover="ddrivetip('<?php echo $this->_vars['artifactname'][$this->_vars['myLoop']]; ?>','<?php echo $this->_vars['artifact_description'][$this->_vars['myLoop']]; ?>');" onMouseout="hideddrivetip()">
					<img src="images/artifacts/<?php echo $this->_vars['artifactimage'][$this->_vars['myLoop']]; ?>.gif" border=0></a><BR>
					<br><b>(<font color=#33ff00><?php echo $this->_vars['artifactname'][$this->_vars['myLoop']]; ?></font>)</b>
					</td>
				<?php if ($this->_vars['myLoop'] == 4 || $this->_vars['myLoop'] == 9 || $this->_vars['myLoop'] == 14 || $this->_vars['myLoop'] == 19 || $this->_vars['myLoop'] == 24): ?>
					</tr><tr>
				<?php endif; ?>
			<?php endfor; ?>
</tr>
</table>
    </td>
  </tr>
</table>
</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
</FORM>
