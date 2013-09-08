<?php extract($this->_vars, EXTR_REFS);  
function strip_places($itemin){

$places = explode(",", $itemin);
if (count($places) <= 1){
	return $itemin;
}
else
{
	$places[1] = AAT_substr($places[1], 0, 2);
	$placecount=count($places);

	switch ($placecount){
		case 2:
			return "$places[0].$places[1] K";
			break;
		case 3:
			return "$places[0].$places[1] M";
			break;	
		case 4:
			return "$places[0].$places[1] B";
			break;	
		case 5:
			return "$places[0].$places[1] T";
			break;
		case 6:
			return "$places[0].$places[1] Qd";
			break;		
		case 7:
			return "$places[0].$places[1] Qn";
			break;
		case 8:
			return "$places[0].$places[1] Sx";
			break;
		case 9:
			return "$places[0].$places[1] Sp";
			break;
		case 10:
			return "$places[0].$places[1] Oc";
			break;
		}		
	
}

}
 ?>
<center>

<table width="60%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
  <tr>
		<?php if ($this->_vars['avatar'] != "default_avatar.gif"): ?>
		<td width="64" align="center" valign=top>
			<img src="images/avatars/<?php echo $this->_vars['avatar']; ?>" border="1">
		</td>
		<td width="5" align="center" valign=middle>
			<img src="images/spacer.gif" width="5">
		</td>
		<?php endif; ?>
	<td width=65%>
	  <font size=5 color=white><b><?php echo $this->_vars['shipname']; ?><br>
	  <font size=3>
	  <?php echo $this->_vars['classname']; ?></b></font></font><p>
	  <font size=2><b>
	  <?php echo $this->_vars['classdescription']; ?>
	  <br><br>
	  </b></font>
	</td>
	<td width=35% align=center valign=center><img src="<?php echo $this->_vars['classimage']; ?>.gif"></td>
  </tr>
		</table>
	</td>
  </tr>
</table>
<br>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr>
	<td align="center" colspan="2">
	<font size=3 color=white><b><?php echo $this->_vars['l_ship_levels']; ?></b></font>
	<br>
	</td>
  </tr>

  <tr>
	<td align="right">

	<table cellspacing=0 cellpadding=3>
	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_hull_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_hull_normal']; ?> / <?php echo $this->_vars['classinfo_maxhull']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_hull']; ?> / <?php echo $this->_vars['classinfo_maxhull']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['hull_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['hull_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_engines_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_engines_normal']; ?> / <?php echo $this->_vars['classinfo_maxengines']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_engines']; ?> / <?php echo $this->_vars['classinfo_maxengines']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['engines_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['engines_bars']; ?>&nbsp;</td>
	 </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_power_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_power_normal']; ?> / <?php echo $this->_vars['classinfo_maxpower']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_power']; ?> / <?php echo $this->_vars['classinfo_maxpower']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['power_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['power_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_fighter_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_fighter_normal']; ?> / <?php echo $this->_vars['classinfo_maxfighter']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_fighter']; ?> / <?php echo $this->_vars['classinfo_maxfighter']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['fighter_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['fighter_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_sensors_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_sensors_normal']; ?> / <?php echo $this->_vars['classinfo_maxsensors']; ?>)&nbsp;&nbsp;</font>	  
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_sensors']; ?> / <?php echo $this->_vars['classinfo_maxsensors']; ?>)&nbsp;&nbsp;</font>	  
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['sensors_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['sensors_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  &nbsp;<br><font size=2 color=yellow><b>
	  <?php echo $this->_vars['l_avg_stats']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['average_stats']; ?> / <?php echo $this->_vars['average_stats_max']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  &nbsp;<br><?php echo $this->_vars['average_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

  </table>
  </td>

  <td align="left">

  <table cellspacing=0 cellpadding=3>
	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_armor_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_armor_normal']; ?> / <?php echo $this->_vars['classinfo_maxarmor']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_armor']; ?> / <?php echo $this->_vars['classinfo_maxarmor']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['armor_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['armor_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_shields_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_shields_normal']; ?> / <?php echo $this->_vars['classinfo_maxshields']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_shields']; ?> / <?php echo $this->_vars['classinfo_maxshields']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['shields_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['shields_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_beams_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_beams_normal']; ?> / <?php echo $this->_vars['classinfo_maxbeams']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_beams']; ?> / <?php echo $this->_vars['classinfo_maxbeams']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['beams_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['beams_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_torp_launch_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_torp_launchers_normal']; ?> / <?php echo $this->_vars['classinfo_maxtorp_launchers']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_torp_launchers']; ?> / <?php echo $this->_vars['classinfo_maxtorp_launchers']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['torp_launchers_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['torp_launchers_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_cloak_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_cloak_normal']; ?> / <?php echo $this->_vars['classinfo_maxcloak']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_cloak']; ?> / <?php echo $this->_vars['classinfo_maxcloak']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['cloak_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['cloak_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td>
	  <font size=2><b>
	  <?php echo $this->_vars['l_ecm_normal']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_ecm_normal']; ?> / <?php echo $this->_vars['classinfo_maxecm']; ?>)&nbsp;&nbsp;</font>
	  </b></font><br><font size=2><b>
	  <?php echo $this->_vars['l_damaged']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['shipinfo_ecm']; ?> / <?php echo $this->_vars['classinfo_maxecm']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['ecm_normal_bars']; ?>&nbsp;<br><?php echo $this->_vars['ecm_bars']; ?>&nbsp;</td>
	 </td>
	</tr>

  </table>
  </td></tr>
		</table>
	</td>
  </tr>
</table>

<br>
<table width="90%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr>
	<td width=33%><font size=3 color=white><b><?php echo $this->_vars['l_holds']; ?></b></font>
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
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($shipinfo_credits);  ?>
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
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($hold_space);  ?> / <?php extract($this->_vars, EXTR_REFS);  echo strip_places($holds_max);  ?>
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
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($shipinfo_energy);  ?> / <?php extract($this->_vars, EXTR_REFS);  echo strip_places($energy_max);  ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/tfighter.png>&nbsp;<a href=defense_deploy.php><?php echo $this->_vars['l_fighters']; ?></a>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($shipinfo_fighters);  ?> / <?php extract($this->_vars, EXTR_REFS);  echo strip_places($ship_fighters_max);  ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=templates/master_template/images/torp.png>&nbsp;<a href=defense_deploy.php><?php echo $this->_vars['l_torps']; ?></a>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($shipinfo_torps);  ?> / <?php extract($this->_vars, EXTR_REFS);  echo strip_places($torps_max);  ?>
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
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($shipinfo_armor_pts);  ?> / <?php extract($this->_vars, EXTR_REFS);  echo strip_places($armor_pts_max);  ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src="images/spacer.gif" width="12">&nbsp;<?php echo $this->_vars['l_beams']; ?> <?php echo $this->_vars['l_class']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_beams_class']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src="images/spacer.gif" width="12">&nbsp;<?php echo $this->_vars['l_fighters']; ?> <?php echo $this->_vars['l_class']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_fighter_class']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src="images/spacer.gif" width="12">&nbsp;<?php echo $this->_vars['l_torps']; ?> <?php echo $this->_vars['l_class']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_torp_launchers_class']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src="images/spacer.gif" width="12">&nbsp;<?php echo $this->_vars['l_shields']; ?> <?php echo $this->_vars['l_class']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_shields_class']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src="images/spacer.gif" width="12">&nbsp;<?php echo $this->_vars['l_armor']; ?> <?php echo $this->_vars['l_class']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['shipinfo_armor_class']; ?>
		</b></font>
		</td>
	  </tr>

	</table>

  <td valign=top>

	<table border=0 cellspacing=0 cellpadding=3>
<?php extract($this->_vars, EXTR_REFS);  
for($i = 0; $i < count($deviceclass); $i++)
{
echo"
	  <tr>
		<td>
		<font size=2><b>";
		if($deviceprogram[$i] != '')
			echo "<a href=" . $deviceprogram[$i] . ">";
		echo $devicename[$i] . "</a>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		$deviceamount[$i]$deviceinfo[$i]
		</b></font>
		</td>
	  </tr>";
}
 ?>


	</table>
</td></tr>
<?php if ($this->_vars['spycheck']): ?>
	<tr><td><BR><a href=spy.php><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_spy_linkback']; ?><BR></td></tr>
<?php endif; ?>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
