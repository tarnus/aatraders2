<h1><?php echo $this->_vars['title']; ?></h1>

<form action=zoneedit.php?command=change method=post>

<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_name']; ?> : &nbsp;</b></font></td>
<td><input type=text name=name size=30 maxlength=30 value="<?php echo $this->_vars['name']; ?>"></td>
</tr><tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_allow']; ?> <?php echo $this->_vars['l_beacons']; ?> : &nbsp;</b></font></td>
<td><input type=radio name=beacons value=Y <?php echo $this->_vars['ybeacon']; ?>>&nbsp;<?php echo $this->_vars['l_yes']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=beacons value=N <?php echo $this->_vars['nbeacon']; ?>>&nbsp;<?php echo $this->_vars['l_no']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=beacons value=L <?php echo $this->_vars['lbeacon']; ?>>&nbsp;<?php echo $this->_vars['l_zi_limit']; ?></td>
</tr><tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_attacks']; ?> : &nbsp;</b></font></td>
<td><input type=radio name=attacks value=Y <?php echo $this->_vars['yattack']; ?>>&nbsp;<?php echo $this->_vars['l_yes']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=attacks value=N <?php echo $this->_vars['nattack']; ?>>&nbsp;<?php echo $this->_vars['l_no']; ?></td>
</tr><tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_allow']; ?> <?php echo $this->_vars['l_warpedit']; ?> : &nbsp;</b></font></td>
<td><input type=radio name=warpedits value=Y <?php echo $this->_vars['ywarpedit']; ?>>&nbsp;<?php echo $this->_vars['l_yes']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=warpedits value=N <?php echo $this->_vars['nwarpedit']; ?>>&nbsp;<?php echo $this->_vars['l_no']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=warpedits value=L <?php echo $this->_vars['lwarpedit']; ?>>&nbsp;<?php echo $this->_vars['l_zi_limit']; ?></td>
</tr><tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_allow']; ?> <?php echo $this->_vars['l_sector_def']; ?> : &nbsp;</b></font></td>
<td><input type=radio name=defenses value=Y <?php echo $this->_vars['ydefense']; ?>>&nbsp;<?php echo $this->_vars['l_yes']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=defenses value=N <?php echo $this->_vars['ndefense']; ?>>&nbsp;<?php echo $this->_vars['l_no']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=defenses value=L <?php echo $this->_vars['ldefense']; ?>>&nbsp;<?php echo $this->_vars['l_zi_limit']; ?></td>
</tr><tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_genesis']; ?> : &nbsp;</b></font></td>
<td><input type=radio name=planets value=Y <?php echo $this->_vars['yplanet']; ?>>&nbsp;<?php echo $this->_vars['l_yes']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=planets value=N <?php echo $this->_vars['nplanet']; ?>>&nbsp;<?php echo $this->_vars['l_no']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=planets value=L <?php echo $this->_vars['lplanet']; ?>>&nbsp;<?php echo $this->_vars['l_zi_limit']; ?></td>
</tr><tr>
<td align=right><font size=2><b><?php echo $this->_vars['l_ze_allow']; ?> <?php echo $this->_vars['l_title_port']; ?> : &nbsp;</b></font></td>
<td><input type=radio name=trades value=Y <?php echo $this->_vars['ytrade']; ?>>&nbsp;<?php echo $this->_vars['l_yes']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=trades value=N <?php echo $this->_vars['ntrade']; ?>>&nbsp;<?php echo $this->_vars['l_no']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=radio name=trades value=L <?php echo $this->_vars['ltrade']; ?>>&nbsp;<?php echo $this->_vars['l_zi_limit']; ?></td>
</tr><tr>
<td colspan=2 align=center><br><input type=submit value=<?php echo $this->_vars['l_submit']; ?>></td></tr>

</form>
<tr><td colspan=2 >
<a href=zoneinfo.php><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_ze_return']; ?>.
</td></tr>
<tr><td colspan=2 ><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
