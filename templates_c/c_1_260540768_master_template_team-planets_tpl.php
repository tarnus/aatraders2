<?php require_once('/home/aatrader/public_html/aatrade_beta/backends/template_lite/src/plugins/function.math.php'); $this->register_function("math", "tpl_function_math"); ?><H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>

<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="team_planets.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="team_planets.php?page=<?php echo $this->_vars['previouspage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_prev']; ?></a>
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
				<a href="team_planets.php?page=<?php echo $this->_vars['nextpage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_next']; ?></a>
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
<TR BGCOLOR="#585980">
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=sector><?php echo $this->_vars['l_sector']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=galaxy_id><?php echo $this->_vars['l_galaxy']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=name><?php echo $this->_vars['l_name']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=ore><?php echo $this->_vars['l_ore']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=organics><?php echo $this->_vars['l_organics']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=goods><?php echo $this->_vars['l_goods']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=energy><?php echo $this->_vars['l_energy']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=colonists><?php echo $this->_vars['l_colonists']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=credits><?php echo $this->_vars['l_credits']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=max_credits><?php echo $this->_vars['l_max']; ?><br><?php echo $this->_vars['l_credits']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=fighters><?php echo $this->_vars['l_fighters']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<A HREF=team_planets.php?sort=torp><?php echo $this->_vars['l_torps']; ?></A>&nbsp;</B></font></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<?php echo $this->_vars['l_base']; ?>?&nbsp;</B></TD>
<TD ALIGN=CENTER><font size=2><B>&nbsp;<?php echo $this->_vars['l_player']; ?>&nbsp;</B></TD>
</TR>

<?php extract($this->_vars, EXTR_REFS);  
$color = "#3A3B6E";
for($i = 0; $i < $num_planets; $i++){
	echo "<TR BGCOLOR=\"$color\">";
	if($currentgalaxy == $galaxylocationgalaxy[$i])
	{
		echo "<TD ALIGN=CENTER><font size=2>&nbsp;<A HREF=main.php?move_method=real&engage=1&destination=". $planetsector[$i] . ">". $planetsector[$i] ."</A>&nbsp;</font></TD>";
	}
	else
	{
		echo "<TD align=\"center\">". $planetsector[$i] ."</TD>";
	}
	echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $galaxylocation[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetname[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetore[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetorganics[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetgoods[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetenergy[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetcolonists[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetcredits[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetmaxcredits[$i] . "%&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planetfighters[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=RIGHT><font size=2>&nbsp;" . $planettorps[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetbase[$i] . "&nbsp;</font></TD>";
	echo "<TD ALIGN=CENTER><font size=2>&nbsp;" . $planetplayer[$i] . "&nbsp;</font></TD>";
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
echo "<TR BGCOLOR=\"$color\">";
 ?>

<TD ALIGN=CENTER>&nbsp;</TD>
<TD ALIGN=CENTER>&nbsp;<?php echo $this->_vars['l_pr_totals']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_ore']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_organics']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_goods']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_energy']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_colonists']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_credits']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_fighters']; ?>&nbsp;</TD>
<TD ALIGN=RIGHT>&nbsp;<?php echo $this->_vars['total_torp']; ?>&nbsp;</TD>
<TD ALIGN=CENTER>&nbsp;<?php echo $this->_vars['total_base']; ?>&nbsp;</TD>
<TD ALIGN=CENTER>&nbsp;</TD>
</TR>
</TABLE>

</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
