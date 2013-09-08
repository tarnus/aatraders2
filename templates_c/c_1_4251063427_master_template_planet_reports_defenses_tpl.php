<?php require_once('F:\aatrade\aatrade\backends\template_lite\src\plugins\function.math.php'); $this->register_function("math", "tpl_function_math"); ?><table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
		<tr><td>
	<?php if ($this->_vars['playerteam'] > 0): ?>
		<BR>
		<B><A HREF=team_planets.php><?php echo $this->_vars['l_pr_teamlink']; ?></A></B><BR>
		 <?php echo $this->_vars['l_pr_team_disp']; ?>
		 <BR>
		<BR>
		<B><A HREF=team_defenses.php><?php echo $this->_vars['l_pr_showtd']; ?></A></B><BR> <?php echo $this->_vars['l_pr_showd']; ?><BR>
	<?php endif; ?>
		</td></tr>
		</table>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>

<?php if ($this->_vars['num_planets'] < 1): ?>
	<BR><?php echo $this->_vars['l_pr_noplanet']; ?>
<?php else: ?>
	<BR>
	<?php echo $this->_vars['l_pr_clicktosort']; ?><BR><BR>
<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="planet_report.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="planet_report.php?commandpage=defenses&page=<?php echo $this->_vars['previouspage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_prev']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
		<TD align='center' width="33%">
	<?php echo tpl_function_math(array('equation' => "x + y",'x' => 1,'y' => $this->_vars['totalpages'],'assign' => "forpages"), $this);?>
	<?php echo $this->_vars['l_rpt_selectpage']; ?> <select name="page">
	<?php for($for1 = 1; ((1 < $this->_vars['forpages']) ? ($for1 < $this->_vars['forpages']) : ($for1 > $this->_vars['forpages'])); $for1 += ((1 < $this->_vars['forpages']) ? 1 : -1)):  $this->assign('i', $for1); ?>
		<option value="<?php echo $this->_vars['i']; ?>"
		<?php if ($this->_vars['currentpage'] == $this->_vars['i']): ?>
			selected
		<?php endif; ?>
		> <?php echo $this->_vars['l_rpt_page']; ?> <?php echo $this->_vars['i']; ?> </option>
	<?php endfor; ?>
	</select>
	&nbsp;<input type="submit" value="<?php echo $this->_vars['l_submit']; ?>">
	</TD>
		<td align="right" width="33%">
			<?php if ($this->_vars['currentpage'] != $this->_vars['totalpages']): ?>
				<a href="planet_report.php?commandpage=defenses&page=<?php echo $this->_vars['nextpage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_next']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
	</tr>
	<input type="hidden" name="sort" value="<?php echo $this->_vars['sort']; ?>">
	<input type="hidden" name="commandpage" value="defenses">
	</form>
	</table>
<?php endif; ?>
	<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="#585980" VALIGN=BOTTOM>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_id><?php echo $this->_vars['l_pr_sector']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=galaxy_id><?php echo $this->_vars['l_galaxy']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=name><?php echo $this->_vars['l_name']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=fighter><?php echo $this->_vars['l_fighter']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sensors><?php echo $this->_vars['l_sensors']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=beams><?php echo $this->_vars['l_beams']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=torp_launchers><?php echo $this->_vars['l_torp_launch']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=shields><?php echo $this->_vars['l_shields']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=jammer><?php echo $this->_vars['l_jammer']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=cloak><?php echo $this->_vars['l_cloak']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_defense_weapons><?php echo $this->_vars['l_planetary_SD_weapons']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_defense_sensors><?php echo $this->_vars['l_planetary_SD_sensors']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_defense_cloak><?php echo $this->_vars['l_planetary_SD_cloak']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=base><?php echo $this->_vars['l_base']; ?></a></B></TD>
	</TR>
	<?php extract($this->_vars, EXTR_REFS);  
	$color = "#3A3B6E";
	for($i=0; $i<$num_planets; $i++)
	{
		if($planetzone_id[$i] == 4)
		{
			$rowcolor = "#440000";
		}
		else
		{
			$rowcolor = $color;
		}
		echo "<TR BGCOLOR=\"$rowcolor\">";
		if ($currentgalaxy == $galaxylocationgalaxy[$i]){
			echo "<TD ALIGN=CENTER><A HREF=main.php?move_method=real&engage=1&destination=". $planetsector[$i] . ">". $planetsector[$i] ."</A></TD>";
		}
		else
		{
			echo "<TD ALIGN=CENTER>" . $planetsector[$i] . "</TD>";
		}
		echo "<TD ALIGN=CENTER>" . $galaxylocation[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetname[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetfighter[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetsensors[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetbeams[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planettorps[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetshields[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetjammer[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetcloak[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetsdweapons[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetsdsensors[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>" . $planetsdcloak[$i] . "</TD>";

		if ($planetbase[$i] == 'Y')
			echo "<TD ALIGN=CENTER>$l_yes</TD>";
		elseif ($planetbaseitems[$i])
			echo "<TD ALIGN=CENTER><A HREF=planet_report.php?commandpage=production_view&buildp=" . $planetid[$i] . "&builds=" . $planetsector[$i] . ">$l_pr_build</A></TD>";
		else
			echo "<TD ALIGN=CENTER>$l_no</TD>";

		echo "</TR>\n";

		if($color == "#3A3B6E")
		{
			$color = "#23244F";
		}
		else
		{
			$color = "#3A3B6E";
		}
	}
	echo "<TR BGCOLOR=$color>";
	 ?>
	<TD COLSPAN=14  ALIGN=CENTER><?php echo $this->_vars['l_pr_totals']; ?>: <?php echo $this->_vars['total_base']; ?> / <?php echo $this->_vars['totalplanets']; ?></TD>
	</TR>
	</TABLE>
<?php endif; ?>
</td></tr>

<tr><td><br><br><a href="planet_report.php"><?php echo $this->_vars['l_pr_menulink']; ?></a><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
