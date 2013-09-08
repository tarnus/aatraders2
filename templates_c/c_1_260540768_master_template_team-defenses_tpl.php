<?php require_once('/home/aatrader/public_html/aatrade_beta/backends/template_lite/src/plugins/function.math.php'); $this->register_function("math", "tpl_function_math"); ?><H1><?php echo $this->_vars['title']; ?></H1>
<table width="90%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>

<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="team_defenses.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="team_defenses.php?page=<?php echo $this->_vars['previouspage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_prev']; ?></a>
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
				<a href="team_defenses.php?page=<?php echo $this->_vars['nextpage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_next']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
	</tr>
	<input type="hidden" name="sort" value="<?php echo $this->_vars['sort']; ?>">
	</form>
	</table>
<?php endif; ?>

<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
<TR BGCOLOR="#585980" VALIGN=BOTTOM>
<TD><B><A HREF=team_defenses.php?sort=sector_id><?php echo $this->_vars['l_sector']; ?></A></B></TD>
<TD><B><A HREF=team_defenses.php?sort=galaxy_id><?php echo $this->_vars['l_galaxy']; ?></A></B></TD>
<TD><B><A HREF=team_defenses.php?sort=name><?php echo $this->_vars['l_name']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=fighter><?php echo $this->_vars['l_fighter']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=sensors><?php echo $this->_vars['l_sensors']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=beams><?php echo $this->_vars['l_beams']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=torp_launchers><?php echo $this->_vars['l_torp_launch']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=shields><?php echo $this->_vars['l_shields']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=jammer><?php echo $this->_vars['l_jammer']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=cloak><?php echo $this->_vars['l_cloak']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=sector_defense_weapons><?php echo $this->_vars['l_planetary_SD_weapons']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=sector_defense_sensors><?php echo $this->_vars['l_planetary_SD_sensors']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=sector_defense_cloak><?php echo $this->_vars['l_planetary_SD_cloak']; ?></A></B></TD>
<TD width="10%"><B><A HREF=team_defenses.php?sort=base><?php echo $this->_vars['l_base']; ?></a></B></TD>
<TD><B><A HREF=team_defenses.php?sort=owner><?php echo $this->_vars['l_teamplanet_owner']; ?></A></B></TD>
</TR>
<?php extract($this->_vars, EXTR_REFS);  
$color = "#3A3B6E";
for($i=0; $i<$num_planets; $i++)
{
	echo "<TR BGCOLOR=\"$color\">";
	if($currentgalaxy == $galaxylocationgalaxy[$i])
	{
		echo "<TD><A HREF=main.php?move_method=real&engage=1&destination=". $teamsector[$i] . ">". $teamsector[$i] ."</A></TD>";
	}
	else
	{
		echo "<TD>". $teamsector[$i] ."</TD>";
	}
	echo "<TD>" . $galaxylocation[$i] . "</TD>";
	echo "<TD>" . $planetname[$i] . "</TD>";
	echo "<TD>" . $planetfighter[$i] . "</TD>";
	echo "<TD>" . $planetsensors[$i] . "</TD>";
	echo "<TD>" . $planetbeams[$i] . "</TD>";
	echo "<TD>" . $planettorps[$i] . "</TD>";
	echo "<TD>" . $planetshields[$i] . "</TD>";
	echo "<TD>" . $planetjammer[$i] . "</TD>";
	echo "<TD>" . $planetcloak[$i] . "</TD>";
	echo "<TD>" . $planetsdweapons[$i] . "</TD>";
	echo "<TD>" . $planetsdsensors[$i] . "</TD>";
	echo "<TD>" . $planetsdcloak[$i] . "</TD>";
	echo "<TD>" . $planetbase[$i] . "</TD>";
	echo "<TD>" . $playername[$i] . "</TD>";
	echo "</TR>";

	if($color == "#3A3B6E")
	{
		$color = "#23244F";
	}
	else
	{
		$color = "#3A3B6E";
	}
}

if($color == "#3A3B6E")
{
	$color = "#23244F";
}
else
{
	$color = "#3A3B6E";
}

echo "<TR BGCOLOR=$color>";
 ?>

<TD COLSPAN=14  ALIGN=CENTER><?php echo $this->_vars['l_pr_totals']; ?>: <?php echo $this->_vars['total_base']; ?></TD>
</TR>
</table>
</td>
</tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
