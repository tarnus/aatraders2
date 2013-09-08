<?php require_once('F:\aatrade\aatrade\backends\template_lite\src\plugins\function.math.php'); $this->register_function("math", "tpl_function_math"); ?><H1><?php echo $this->_vars['title']; ?>: <?php echo $this->_vars['l_pr_production']; ?></H1>
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

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
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
	<?php echo $this->_vars['l_pr_clicktosort']; ?><BR><BR>
<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="planet_report.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="planet_report.php?commandpage=production_view&page=<?php echo $this->_vars['previouspage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_prev']; ?></a>
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
				<a href="planet_report.php?commandpage=production_view&page=<?php echo $this->_vars['nextpage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_next']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
	</tr>
	<input type="hidden" name="sort" value="<?php echo $this->_vars['sort']; ?>">
	<input type="hidden" name="commandpage" value="production_view">
	</form>
	</table>
<?php endif; ?>

	<FORM ACTION="planet_report.php?commandpage=production_change" METHOD="POST">
	<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="#585980" VALIGN=BOTTOM>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=sector_id><?php echo $this->_vars['l_pr_sector']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=galaxy_id><?php echo $this->_vars['l_galaxy']; ?></A></B></font></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=name><?php echo $this->_vars['l_name']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=ore><?php echo $this->_vars['l_ore']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=organics><?php echo $this->_vars['l_organics']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=goods><?php echo $this->_vars['l_goods']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=energy><?php echo $this->_vars['l_energy']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=special><?php echo $this->_vars['l_pr_special']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=colonists><?php echo $this->_vars['l_colonists']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=credits><?php echo $this->_vars['l_credits']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=fighters><?php echo $this->_vars['l_fighters']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=torp><?php echo $this->_vars['l_torps']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=research><?php echo $this->_vars['l_pr_research']; ?></A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=production_view&sort=build><?php echo $this->_vars['l_pr_build']; ?></A></B></TD>
	<?php if ($this->_vars['playerteam'] > 0): ?>
		<TD ALIGN=CENTER><B><?php echo $this->_vars['l_team']; ?>?</B></TD>
		<TD ALIGN=CENTER><B><?php echo $this->_vars['l_teamcash']; ?>?</B></TD>
	<?php endif; ?>
	</TR>
	<?php extract($this->_vars, EXTR_REFS);  
	$color = "#3A3B6E";
	for($i=0; $i<$num_planets; $i++)
	{
		if($planetzone_id[$i] != 4)
		{
		echo "<TR BGCOLOR=\"$color\">";
		if ($currentgalaxy == $galaxylocationgalaxy[$i]){
			echo "<TD ALIGN=CENTER><A HREF=main.php?move_method=real&engage=1&destination=". $planetsector[$i] . "><input type=hidden name=\"planetsector[". $planetid[$i] . "]\" value=\"" . $planetsector[$i] . "\">". $planetsector[$i] ."</A></TD>";
		}
		else
		{
			echo "<TD ALIGN=CENTER><input type=hidden name=\"planetsector[". $planetid[$i] . "]\" value=\"" . $planetsector[$i] . "\">". $planetsector[$i] ."</TD>";
		}
		echo "<TD ALIGN=CENTER>" . $galaxylocation[$i] . "</TD>";
		echo "<TD ALIGN=CENTER><input type=hidden name=\"planetname[". $planetid[$i] . "]\" value=\"" . $planetname[$i] . "\">" . $planetname[$i] . "</TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_ore[". $planetid[$i] . "]\" value=\"" . $planetore[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_organics[" . $planetid[$i] . "]\" value=\"" . $planetorganics[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_goods["	. $planetid[$i] . "]\" value=\"" . $planetgoods[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_energy[" . $planetid[$i] . "]\" value=\"" . $planetenergy[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER>";
			if ($planetspecialname[$i] == "")
			{
						echo "<input type=hidden name=\"prod_special[" . $planetid[$i] . "]\" value=\"0\"></td>";
			}
			else
			{
				echo $planetspecialname[$i] . "<br><input size=3 type=text name=\"prod_special[" . $planetid[$i] . "]\" value=\"" . $planetspecial[$i] . "\"></TD>";
			}
		echo "<TD ALIGN=CENTER>"	. $planetcolonists[$i] . "</TD>";
		echo "<TD ALIGN=CENTER>"	. $planetcredits[$i] . "</TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_fighters[" . $planetid[$i] . "]\" value=\"" . $planetfighters[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_torp[" . $planetid[$i] . "]\" value=\"" . $planettorps[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_research[" . $planetid[$i] . "]\" value=\"" . $planetresearch[$i] . "\"></TD>";
		echo "<TD ALIGN=CENTER><input size=3 type=text name=\"prod_build[" . $planetid[$i] . "]\" value=\"" . $planetbuild[$i] . "\"></TD>";
		if ($playerteam > 0){
			if ($planetteam[$i] <= 0){
				$selected1 = "";
				$selected2 = "checked";
			}else{
				$selected1 = "checked";
				$selected2 = "";
			}
				echo "<TD ALIGN=CENTER><INPUT TYPE=radio NAME=team[" . $planetid[$i] . "] VALUE=\"1\" $selected1>Yes<br>";
				echo "<INPUT TYPE=radio NAME=team[" . $planetid[$i] . "] VALUE=\"0\" $selected2>No</TD>";
			if ($planettcash[$i] == 'Y'){
				$selected1 = "checked";
				$selected2 = "";
			}else{
				$selected1 = "";
				$selected2 = "checked";
			}
				echo "<TD ALIGN=CENTER><INPUT TYPE=radio NAME=team_cash[" . $planetid[$i] . "] VALUE=\"1\" $selected1>Yes<br>";
				echo "<INPUT TYPE=radio NAME=team_cash[" . $planetid[$i] . "] VALUE=\"0\" $selected2>No</TD>";
		}
		echo "</TR>";
		echo "<input type=hidden name=\"prod_done[" . $planetid[$i] . "]\" value=\"$planetid[$i]\">";

		if ($color == "#3A3B6E")
		{
			$color = "#23244F";
		}
		else
		{
			$color = "#3A3B6E";
		}
		}
	}
	echo "<TR BGCOLOR=$color>";
	 ?>

	<TD COLSPAN=3 ALIGN=CENTER><?php echo $this->_vars['l_pr_totals']; ?></TD>
	<TD></TD>
	<TD></TD>
	<TD></TD>
	<TD></TD>
	<TD></TD>
	<TD ALIGN=CENTER><?php echo $this->_vars['total_colonists']; ?></TD>
	<TD ALIGN=CENTER><?php echo $this->_vars['total_credits']; ?></TD>
	<TD></TD>
	<TD></TD>
	<?php if ($this->_vars['playerteam'] > 0): ?>
		<TD></TD>
	<?php endif; ?>
	<TD></TD>
	<TD></TD>
	</TR>
	</TABLE>

	<BR>
	<INPUT TYPE=SUBMIT VALUE="<?php echo $this->_vars['l_submit']; ?>" ONCLICK="clean_js()">
	<INPUT TYPE=RESET VALUE="<?php echo $this->_vars['l_reset']; ?>">
	</FORM>
<?php endif; ?>

</td></tr>

<table border=0 cellspacing=0 cellpadding=2 width="100%">
<tr><td><br><br><a href="planet_report.php"><?php echo $this->_vars['l_pr_menulink']; ?></a><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
