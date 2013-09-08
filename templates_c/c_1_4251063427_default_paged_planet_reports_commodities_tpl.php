<?php require_once('F:\aatrade\aatrade\backends\template_lite\src\plugins\function.math.php'); $this->register_function("math", "tpl_function_math"); ?><table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
		<tr><td>
	<?php if ($this->_vars['playerteam'] > 0): ?>
		<BR>
		<B><A HREF="team_planets.php"><?php echo $this->_vars['l_pr_teamlink']; ?></A></B><BR>
		 <?php echo $this->_vars['l_pr_team_disp']; ?>
		 <BR>
		<BR>
		<B><A HREF="team_defenses.php"><?php echo $this->_vars['l_pr_showtd']; ?></A></B><BR> <?php echo $this->_vars['l_pr_showd']; ?><BR>
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
	<?php echo $this->_vars['l_pr_warning']; ?><BR><BR>
<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="planet_report.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="planet_report.php?commandpage=commodities&page=<?php echo $this->_vars['previouspage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_prev']; ?></a>
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
				<a href="planet_report.php?commandpage=commodities&page=<?php echo $this->_vars['nextpage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_next']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
	</tr>
	<input type="hidden" name="sort" value="<?php echo $this->_vars['sort']; ?>">
	<input type="hidden" name="PRepType" value="1">
	</form>
	</table>
<?php endif; ?>

	<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="#585980" VALIGN=BOTTOM>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=sector_id><?php echo $this->_vars['l_pr_sector']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=galaxy_id><?php echo $this->_vars['l_galaxy']; ?></A>&nbsp;</B></font></TD>
    <TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=name><?php echo $this->_vars['l_name']; ?></A>&nbsp;</B></font></TD>   
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=last_visited>LV</A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=ore><?php echo $this->_vars['l_ore']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=organics><?php echo $this->_vars['l_organics']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=goods><?php echo $this->_vars['l_goods']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=energy><?php echo $this->_vars['l_energy']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=special><?php echo $this->_vars['l_pr_special']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=colonists><?php echo $this->_vars['l_colonists']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=credits><?php echo $this->_vars['l_credits']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=max_credits><?php echo $this->_vars['l_max']; ?><br><?php echo $this->_vars['l_credits']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=fighters><?php echo $this->_vars['l_fighters']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=planet_report.php?commandpage=commodities&sort=torp><?php echo $this->_vars['l_torps']; ?></A>&nbsp;</B></font></TD>
	<TD ALIGN=CENTER><font size=2><B>&nbsp;<?php echo $this->_vars['l_base']; ?>?&nbsp;</B></font></TD>
	<?php if ($this->_vars['playerteam'] > 0): ?>
		<TD ALIGN=CENTER><font size=2><B>&nbsp;<?php echo $this->_vars['l_team']; ?>?&nbsp;</B></font></TD>
		<TD ALIGN=CENTER><B>&nbsp;<?php echo $this->_vars['l_teamcash']; ?>?&nbsp;</B></TD>
        
	<?php endif; ?>
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
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;<A HREF=main.php?move_method=real&engage=1&destination=". $planetsector[$i] . ">". $planetsector[$i] ."</A>&nbsp;</font></TD>";
		}
		else
		{
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetsector[$i] . "&nbsp;</font></TD>";
		}
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $galaxylocation[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetname[$i] . "&nbsp;</font></TD>";
        echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetlastvisited[$i] . "&nbsp;</font></TD>"; 
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetore[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetorganics[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetgoods[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetenergy[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=center><font size=2>&nbsp;";
			if ($planetspecialname[$i] == "")
			{
						echo "&nbsp;";
			}
			else
			{
				echo $planetspecialname[$i] . "<br>" . $planetspecial[$i];
			}
		echo "&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetcolonists[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetcredits[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetmaxcredits[$i] . "%&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetfighters[$i] . "&nbsp;</font></TD>";
		echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planettorps[$i] . "&nbsp;</font></TD>";
           

		if ($planetbase[$i] == 'Y')
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;$l_yes&nbsp;</font></TD>";
		elseif ($planetbaseitems[$i])
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;<A HREF=\"planet_report.php?commandpage=build_base&buildp=" . $planetid[$i] . "&builds=" . $planetsector[$i] . "\">$l_pr_build</A>&nbsp;</font></TD>";
		else
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;$l_no&nbsp;</font></TD>";

		if ($playerteam > 0){
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . ($planetteam[$i] > 0 ? "$l_yes" : "$l_no") . "&nbsp;</font></TD>";
			echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . ($planettcash[$i] == 'Y' ? "$l_yes" : "$l_no") . "&nbsp;</font></TD>";
		}
		echo "</TR>";

		if ($color == "#3A3B6E")
		{
			$color = "#23244F";
		}
		else
		{
			$color = "#3A3B6E";
		}
	}

	echo "<TR><TD></TD></TR><TR><TD></TD></TR><TR><TD></TD></TR><TR BGCOLOR=$color>";
	 ?>
      <TD ALIGN=CENTER><font size=2>&nbsp;&nbsp;</font></TD>   
	<TD COLSPAN=3 ALIGN=CENTER><font size=2>&nbsp;<?php echo $this->_vars['l_pr_totals']; ?>&nbsp;</font></TD>
	
    <TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_ore']; ?>&nbsp;</font></TD>    
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_organics']; ?>&nbsp;</font></TD>
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_goods']; ?>&nbsp;</font></TD>
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_energy']; ?>&nbsp;</font></TD>
	<TD ALIGN=RIGHT>&nbsp;</TD>
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_colonists']; ?>&nbsp;</font></TD>
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_credits']; ?>&nbsp;</font></TD>
	<TD ALIGN=RIGHT>&nbsp;</TD>
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_fighters']; ?>&nbsp;</font></TD>
	<TD ALIGN=RIGHT><font size=2>&nbsp;<?php echo $this->_vars['total_torp']; ?>&nbsp;</font></TD>
	<TD ALIGN=CENTER><font size=2>&nbsp;<?php echo $this->_vars['total_base']; ?>&nbsp;</font></TD>
	<?php if ($this->_vars['playerteam'] > 0): ?>
		<TD ALIGN=CENTER><font size=2>&nbsp;<?php echo $this->_vars['total_team']; ?>&nbsp;</font></TD>
		<TD ALIGN=CENTER><font size=2>&nbsp;<?php echo $this->_vars['total_teamcash']; ?>&nbsp;</font></TD>
	<?php endif; ?>
	</TR>
	</TABLE>
<?php endif; ?>

</td></tr>

<tr><td><br><br><a href="planet_report.php"><?php echo $this->_vars['l_pr_menulink']; ?></a><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
