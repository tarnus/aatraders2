<H1><?php echo $this->_vars['title']; ?></H1>
<center>

<table width="50%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
  <tr align="center">
		<?php if ($this->_vars['avatar'] != "default_avatar.gif"): ?>
		<td width="64" align="center" valign=top>
			<img src="images/avatars/<?php echo $this->_vars['avatar']; ?>" border="1">
		</td>
		<td width="5" align="center" valign=middle>
			<img src="images/spacer.gif" width="5">
		</td>
		<?php endif; ?>
	<td width=65%>
  <font size=4 color=white><b><?php echo $this->_vars['l_scan_ron']; ?> <?php echo $this->_vars['shipname']; ?><br><?php echo $this->_vars['l_scan_capt']; ?>  <?php echo $this->_vars['targetinfoname']; ?></font>
	</td>
  </tr>
<tr><td colspan="3" align="center"><br>
	<?php if ($this->_vars['scanbounty'] != 1): ?>
	<?php echo $this->_vars['l_scan_bounty']; ?><BR>
<?php endif; ?>
<?php if ($this->_vars['scanfedbounty'] != 1): ?>
	<?php echo $this->_vars['l_scan_fedbounty']; ?><BR>
<?php endif; ?>
<?php echo $this->_vars['fedcheckbounty']; ?><br>
</td></tr>
		</table>
	</td>
    <td >&nbsp;</td>
  </tr>
</table>
<br>
<table width="80%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
    <td >&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr>
	<td align="center" colspan="2">
	<font size=3 color=white><b><?php echo $this->_vars['l_ship_levels']; ?></b></font>
	<br>
	</td>
  </tr>
			<TR>
				<TD>
  <table border=0 cellspacing=0 cellpadding=3>
								<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_hull_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_hull_normal']; ?> / <?php echo $this->_vars['classinfo_maxhull']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['hull_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_engines_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_engines_normal']; ?> / <?php echo $this->_vars['classinfo_maxengines']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['engines_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_power_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_power_normal']; ?> / <?php echo $this->_vars['classinfo_maxpower']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['power_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_fighter_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_fighter_normal']; ?> / <?php echo $this->_vars['classinfo_maxfighter']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['fighter_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_sensors_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_sensors_normal']; ?> / <?php echo $this->_vars['classinfo_maxsensors']; ?>)&nbsp;&nbsp;</font>	  
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['sensors_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
<font size=2 color=yellow><b>
	  <?php echo $this->_vars['l_avg_stats']; ?>&nbsp;<font color=white><?php echo $this->_vars['average_stats']; ?>&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['average_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

  </table>
  </td>

  <td align="left">

  <table border=0 cellspacing=0 cellpadding=3>
	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_armor_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_armor_normal']; ?> / <?php echo $this->_vars['classinfo_maxarmor']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['armor_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_shields_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_shields_normal']; ?> / <?php echo $this->_vars['classinfo_maxshields']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['shields_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_beams_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_beams_normal']; ?> / <?php echo $this->_vars['classinfo_maxbeams']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['beams_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_torp_launch_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_torp_launchers_normal']; ?> / <?php echo $this->_vars['classinfo_maxtorp_launchers']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['torp_launchers_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_cloak_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_cloak_normal']; ?> / <?php echo $this->_vars['classinfo_maxcloak']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['cloak_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_ecm_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_ecm_normal']; ?> / <?php echo $this->_vars['classinfo_maxecm']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['ecm_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>
</table>
				</td>
			</tr>
		</table>
	</td>
  </tr>
</table>
<br>
<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr>
	<td width=33%>
	<font size=3 color=white><b><?php echo $this->_vars['l_holds']; ?></b></font>
	<br>
	</td>
	<td width=33%>
	<font size=3 color=white><b><?php echo $this->_vars['l_arm_weap']; ?></b></font>
	<br></td>
	</td>
	<td width=33%>
	<font size=3 color=white><b><?php echo $this->_vars['l_devices']; ?></b></font>
	<br></td>
	</td>
  </tr>   

  <tr>
	<td valign=top>

	<table border=0 cellspacing=0 cellpadding=3>
	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/credits.png>&nbsp;<?php echo $this->_vars['l_credits']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_credits']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		<?php echo $this->_vars['l_total_cargo']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['holds_used']; ?> / <?php echo $this->_vars['holds_max']; ?>
		</b></font>
		</td>
	  </tr>

<?php if ($this->_vars['cargo_items'] > 0): ?>
<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $cargo_items; $i++)
	{
		if ($cargo_amount[$i] != "0")
		{
			echo "	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=\"images/ports/" . $cargo_name[$i] . ".png\">&nbsp;" . ucfirst($cargo_name[$i]) . "&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>";
			$places = explode(",", $cargo_amount[$i]);
			if (count($places) <= 3){
				echo $cargo_amount[$i];
			}
			else
			{
				$places[1] = AAT_substr($places[1], 0, 2);
				if(count($places) == 4){
					echo "$places[0].$places[1] B";
				}
				if(count($places) == 5){
					echo "$places[0].$places[1] T";
				}
				if(count($places) == 6){
					echo "$places[0].$places[1] Qd";
				}
				if(count($places) == 7){
					echo "$places[0].$places[1] Qn";
				}
			}
			echo " x $cargo_holds[$i]</b></font>
		</td>
	  </tr>";
		}
	}
 ?>
<?php endif; ?>

	  </table>

  </td><td valign=top>

	<table border=0 cellspacing=0 cellpadding=3>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/energy.png>&nbsp;<?php echo $this->_vars['l_energy']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_energy']; ?> / <?php echo $this->_vars['energy_max']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/tfighter.png>&nbsp;<?php echo $this->_vars['l_fighters']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_fighters']; ?> / <?php echo $this->_vars['ship_fighters_max']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/torp.png>&nbsp;<?php echo $this->_vars['l_torps']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_torps']; ?> / <?php echo $this->_vars['torps_max']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/armor.png>&nbsp;<?php echo $this->_vars['l_armorpts']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_armor_pts']; ?> / <?php echo $this->_vars['armor_pts_max']; ?>
		</b></font>
		</td>
	  </tr>
		</table>

  <td valign=top>

	<table border=0 cellspacing=0 cellpadding=3>

	</table>

  </td></tr>

<tr><td colspan=4><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
