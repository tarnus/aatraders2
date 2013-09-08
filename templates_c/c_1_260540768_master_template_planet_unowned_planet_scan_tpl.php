<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<table border=0 cellspacing=0 cellpadding=0 width=90% align="center">
  <tr>
		<td align="center" valign=top>
			<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/master_template/images/planet" . $this->_vars['planettype'] . ".png", 'alt' => "", 'width' => "100", 'height' => "100", 'border' => "1")); ?>
		</td></tr><tr>
	<td align="center">
	<?php if ($this->_vars['sc_base'] != "N"): ?>
		<font size=4 color="#00ff00"><b><?php echo $this->_vars['sc_base']; ?></font><br>
	<?php endif; ?>
  <font size=4 color=white><b><?php echo $this->_vars['l_scan_ron']; ?> <?php echo $this->_vars['planetname']; ?></font>
</td></tr>
<tr><td align="center">
	<?php if ($this->_vars['scanbounty'] != 1): ?>
	<?php echo $this->_vars['l_scan_bounty']; ?><BR>
<?php endif; ?>
<?php if ($this->_vars['scanfedbounty'] != 1): ?>
	<?php echo $this->_vars['l_scan_fedbounty']; ?><BR>
<?php endif; ?>
<?php echo $this->_vars['fedcheckbounty']; ?><br><br>
</td></tr>
</table>
<p>

<table border=0 cellspacing=0 cellpadding=0 width=90% align="center">
  <tr>
	<td align="center" colspan="2">
	<font size=3 color=white><b><?php echo $this->_vars['l_planetary_defense_levels']; ?></b></font>
	<br>
	</td>
  </tr>

  <tr>
	<td align="right" width=50% valign="top">

	<table border=1 cellspacing=0 cellpadding=3>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_beams']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_beams_normal']; ?> / <?php echo $this->_vars['classinfo_maxbeams']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['beams_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_torp_launch']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_torp_launchers_normal']; ?> / <?php echo $this->_vars['classinfo_maxtorp_launchers']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['torp_launchers_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_fighter']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_fighter_normal']; ?> / <?php echo $this->_vars['classinfo_maxfighter']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['fighter_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_sensors']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_sensors_normal']; ?> / <?php echo $this->_vars['classinfo_maxsensors']; ?>)&nbsp;&nbsp;</font>	  
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['sensors_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
<font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_SD_weapons']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_sdweapons_normal']; ?> / <?php echo $this->_vars['classinfo_maxsdweapons']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['sdweapons_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
<font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_SD_cloak']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_sdcloak_normal']; ?> / <?php echo $this->_vars['classinfo_maxsdcloak']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['sdcloak_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

  </table>
  </td>

  <td align="left" width=50% valign="top">

  <table border=1 cellspacing=0 cellpadding=3>
	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_armor']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_armor_normal']; ?> / <?php echo $this->_vars['classinfo_maxarmor']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['armor_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_shields']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_shields_normal']; ?> / <?php echo $this->_vars['classinfo_maxshields']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['shields_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_cloak']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_cloak_normal']; ?> / <?php echo $this->_vars['classinfo_maxcloak']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['cloak_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
	  <font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_jammer']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_jammer_normal']; ?> / <?php echo $this->_vars['classinfo_maxjammer']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['jammer_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
<font size=2 color=#00ff00><b>
	  <?php echo $this->_vars['l_planetary_SD_sensors']; ?>&nbsp;<font color=white>(<?php echo $this->_vars['planetinfo_sdsensors_normal']; ?> / <?php echo $this->_vars['classinfo_maxsdsensors']; ?>)&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['sdsensors_normal_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

	<tr>
	  <td width=225>
<font size=2 color=yellow><b>
	  <?php echo $this->_vars['l_avg_stats']; ?>&nbsp;<font color=white><?php echo $this->_vars['average_stats']; ?>&nbsp;&nbsp;</font>
	  </b></font><td valign=bottom>
	  <?php echo $this->_vars['average_bars']; ?>&nbsp;</td>
	  </td>
	</tr>

  </table>

  </td>
</tr>
</table>

<p>

<table border=0 cellspacing=0 cellpadding=0 width=90%>
  <tr>
	<td width=50% align="center">
	<font size=3 color=white><b><?php echo $this->_vars['l_holds']; ?></b></font>
	<br>
	</td>
	<td width=50% align="center">
	<font size=3 color=white><b><?php echo $this->_vars['l_arm_weap']; ?></b></font>
	<br></td>
	</td>
  </tr>   

  <tr>
	<td valign=top width=50% align="center">

	<table border=0 cellspacing=0 cellpadding=3 >
	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/master_template/images/credits.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_credits']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_credits']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "images/ports/ore.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_ore']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_ore']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "images/ports/organics.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_organics']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_organics']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "images/ports/goods.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_goods']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_goods']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "images/ports/colonists.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_colonists']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_colonists']; ?>
		</b></font>
		</td>
	  </tr>
	  
<?php if ($this->_vars['l_specialname'] != ''): ?>
	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "images/ports/" . $this->_vars['l_special_image'] . ".png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_specialname']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_special']; ?>
		</b></font>
		</td>
	  </tr>
<?php endif; ?>
	  </table>

  </td><td valign=top width=50% align="center">

	<table border=0 cellspacing=0 cellpadding=3>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "images/ports/energy.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_energy']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_energy']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/master_template/images/tfighter.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_fighters']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_fighters']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/master_template/images/torp.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_torps']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_torps']; ?>
		</b></font>
		</td>
	  </tr>

	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/master_template/images/armor.png", 'alt' => "", 'width' => "12", 'height' => "12", 'border' => "0")); ?>&nbsp;<?php echo $this->_vars['l_armorpts']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php echo $this->_vars['planetinfo_armor_pts']; ?>
		</b></font>
		</td>
	  </tr>
		</table>

  </td></tr>

</table>

<table border=1 cellspacing=0 cellpadding=2 align="center">
  <tr>
	<td align="center">
	<?php if ($this->_vars['shipcount'] != 0): ?>
	<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $shipcount; $i++){
		echo "<font size=2 color=white><b>$playeronplanet[$i] $l_planet_ison</b></font><br>";
	}
	 ?>
	<?php else: ?>
		<font size=2 color=white><b><?php echo $this->_vars['l_planet_noone']; ?> <?php echo $this->_vars['l_planet_ison']; ?></b></font>
	<?php endif; ?>
	</td>
  </tr> </table>

<tr><td>
<BR><a href='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>'><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><BR><BR>

<?php if ($this->_vars['allow_ibank']): ?>
	<?php echo $this->_vars['l_ifyouneedplan']; ?> <A HREF="igb.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_igb_term']; ?></A>.<BR><BR>
<?php endif; ?>

</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
