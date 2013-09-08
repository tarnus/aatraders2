<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
		<tr><td>
	{if $playerteam > 0}
		<BR>
		<B><A HREF=team_planets.php>{$l_pr_teamlink}</A></B><BR>
		 {$l_pr_team_disp}
		 <BR>
		<BR>
		<B><A HREF=team_defenses.php>{$l_pr_showtd}</A></B><BR> {$l_pr_showd}<BR>
	{/if}
		</td></tr>
		</table>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>

{if $num_planets < 1}
	<BR>{$l_pr_noplanet}
{else}
	<BR>
	{$l_pr_clicktosort}<BR><BR>
{if $totalpages > 1}
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="planet_report.php" method="post">
	<TR>
		<td align="left" width="33%">
			{if $currentpage != 1}
				<a href="planet_report.php?commandpage=defenses&page={$previouspage}&sort={$sort}">{$l_rpt_prev}</a>
			{else}
				&nbsp;
			{/if}
		</td>
		<TD align='center' width="33%">
	{ math equation="x + y" x=1 y=$totalpages assign="forpages" }
	{$l_rpt_selectpage} <select name="page">
	{ for start=1 stop=$forpages step=1 value=i }
		<option value="{$i}"
		{if $currentpage == $i}
			selected
		{/if}
		> {$l_rpt_page} {$i} </option>
	{/for}
	</select>
	&nbsp;<input type="submit" value="{$l_submit}">
	</TD>
		<td align="right" width="33%">
			{if $currentpage != $totalpages}
				<a href="planet_report.php?commandpage=defenses&page={$nextpage}&sort={$sort}">{$l_rpt_next}</a>
			{else}
				&nbsp;
			{/if}
		</td>
	</tr>
	<input type="hidden" name="sort" value="{$sort}">
	<input type="hidden" name="commandpage" value="defenses">
	</form>
	</table>
{/if}
	<TABLE WIDTH="100%" BORDER=0 CELLSPACING=0 CELLPADDING=2>
	<TR BGCOLOR="#585980" VALIGN=BOTTOM>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_id>{$l_pr_sector}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=galaxy_id>{$l_galaxy}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=name>{$l_name}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=fighter>{$l_fighter}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sensors>{$l_sensors}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=beams>{$l_beams}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=torp_launchers>{$l_torp_launch}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=shields>{$l_shields}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=jammer>{$l_jammer}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=cloak>{$l_cloak}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_defense_weapons>{$l_planetary_SD_weapons}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_defense_sensors>{$l_planetary_SD_sensors}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=sector_defense_cloak>{$l_planetary_SD_cloak}</A></B></TD>
	<TD ALIGN=CENTER><B><A HREF=planet_report.php?commandpage=defenses&sort=base>{$l_base}</a></B></TD>
	</TR>
	{php}
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
	{/php}
	<TD COLSPAN=14  ALIGN=CENTER>{$l_pr_totals}: {$total_base} / {$totalplanets}</TD>
	</TR>
	</TABLE>
{/if}
</td></tr>

<tr><td><br><br><a href="planet_report.php">{$l_pr_menulink}</a><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
