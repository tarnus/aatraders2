<h1><?php echo $this->_vars['title']; ?></h1>

<?php echo '
	<style type="text/css">
		.border {
			border-collapse: collapse; 
			border: 1px solid #ccc; 
		}
		.yellow { color: yellow; }
		.white { color: white; }
	</style>
'; ?>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
  <a href=spy.php?command=detect><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_spy_messages']; ?><BR><BR>
  
	<?php if ($this->_vars['spycount']): ?>
		<table width="100%" border="0" cellspacing="0" cellpadding="1" class="border">
		<TR BGCOLOR="#000000"><td><font color=white><b><?php echo $this->_vars['l_dig_legend']; ?></b></font></td><TD><font color=white><B><?php echo $this->_vars['l_dig_description']; ?></B></font></TD></TR>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['job_name']), 'iteration' => 0);
if (count((array)$this->_vars['job_name'])): foreach ((array)$this->_vars['job_name'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<TR BGCOLOR="#000000"><td><font color=white><?php echo $this->_vars['job_name'][$this->_vars['key']]; ?></font></td><TD><font color=white><?php echo $this->_vars['description'][$this->_vars['key']]; ?></font></TD></TR>
		<?php endforeach; endif; ?>
	</table>
	<br>
		<table border="0" cellpadding="0" cellspacing="0" width="100%" class="border">
			<tr>
				<td bgcolor="#000000"><font color=white><b>&nbsp;
					<?php if ($this->_vars['shipspycount']): ?>
						<?php echo $this->_vars['l_spy_defaulttitle4']; ?>: <span class="yellow"><?php echo $this->_vars['shipspytotal']; ?></span>
					<?php else: ?> 
						<?php echo $this->_vars['l_spy_no4']; ?> 
					<?php endif; ?>
					</b></font>
				</td>
			</tr>
		</table>
		&nbsp;<br>
		<?php if ($this->_vars['enemyshipspycount']): ?>
			<table border="0" cellpadding="2" cellspacing="0" width="100%" class="border">
				<tr>
					<td bgcolor="#000000" colspan=7 align=center><font color=white><b><?php echo $this->_vars['l_spy_defaulttitle1']; ?></b></font></td>
				</tr>
				<tr>
					<td bgcolor="#000000"><b><a href="spy.php?by2=<?php echo $this->_vars['by2']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_codenumber']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by1=character_name&by2=<?php echo $this->_vars['by2']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_shipowner']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by1=ship_name&by2=<?php echo $this->_vars['by2']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_shipname']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by1=ship_type&by2=<?php echo $this->_vars['by2']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_shiptype']; ?></a></b></td>
					<td bgcolor="#000000"><span class="white"><b><u><?php echo $this->_vars['l_galaxy']; ?></u></b></span></td>
					<td bgcolor="#000000"><span class="white"><b><u><?php echo $this->_vars['l_spy_shiplocation']; ?></u></b></span></td>
					<td bgcolor="#000000"><b><a href="spy.php?by1=move_type&by2=<?php echo $this->_vars['by2']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_move']; ?></a></b></td>
				</tr>
			<?php extract($this->_vars, EXTR_REFS);  
			for ($i = 0; $i < $enemyshipcount; $i++)
			{
				if($line_color == "#000000")   
					$line_color = "#000000"; 
				else
					$line_color = "#000000"; 
				echo "<tr>
					<td bgcolor=" . $line_color . " class=\"white\">$spy_id[$i]</td>
					<td bgcolor=" . $line_color . " class=\"white\">$playername[$i]</td>
					<td bgcolor=" . $line_color . " class=\"white\"><a href=report.php?sid=$shipid[$i]>$shipname[$i]</a></td>
					<td bgcolor=" . $line_color . " class=\"white\">$shipclass[$i]</td>
					<td bgcolor=" . $line_color . " class=\"white\">$galaxylocationships[$i]</td>
					<td bgcolor=" . $line_color . " class=\"white\">$spysector[$i]</td>
					<td bgcolor=" . $line_color . " class=\"white\"><a href=spy.php?command=change&spy_id=$spy_id[$i]>$movetype[$i]</a></td>
				</tr>";
			}
			 ?>
			</table>&nbsp;<br>
		<?php else: ?>
			<b><?php echo $this->_vars['l_spy_no1']; ?></b><br><br>
		<?php endif; ?>

		<?php if ($this->_vars['planetspycount']): ?>
			<table border="0" cellpadding="2" cellspacing="0" width="100%" class="border">
				<tr>
					<td bgcolor="#000000" colspan="8" align=center><font color=white><b><?php echo $this->_vars['l_spy_defaulttitle2']; ?></b></font></td>
				</tr>
				<tr>
					<td bgcolor="#000000"><b><a href="spy.php?by2=id&by1=<?php echo $this->_vars['by1']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_codenumber']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by2=owner&by1=<?php echo $this->_vars['by1']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_planetowner']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by1=<?php echo $this->_vars['by1']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_planetname']; ?></a></b></td>
					<td bgcolor="#000000"><b><u><?php echo $this->_vars['l_galaxy']; ?></u></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by2=sector&by1=<?php echo $this->_vars['by1']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_sector']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by2=job_id&by1=<?php echo $this->_vars['by1']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_job']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by2=move_type&by1=<?php echo $this->_vars['by1']; ?>&by3=<?php echo $this->_vars['by3']; ?>"><?php echo $this->_vars['l_spy_move']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="#"><?php echo $this->_vars['l_spy_changebutton']; ?></a></b></td>
				</tr>
			<?php extract($this->_vars, EXTR_REFS);  
			for ($i = 0; $i < $enemyplanetcount; $i++)
			{
				if($line_color == "#000000")   
					$line_color = "#000000"; 
				else
					$line_color = "#000000"; 
				echo "<tr>
						<td bgcolor=" . $line_color . " class=\"white\">$pspy_id[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$pplayername[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$pname[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$galaxylocationplanets[$i]</td>";
				if ($galaxylocationgalaxyplanets[$i] == $currentgalaxy)
				{
					echo "	<td bgcolor=" . $line_color . " class=\"white\"><a href=\"main.php?move_method=real&engage=1&destination=$psector[$i]\">$psector[$i]</a></td>";
				}
				else
				{
					echo "	<td bgcolor=" . $line_color . " class=\"white\">$psector[$i]</td>";
				}
				echo"	<td bgcolor=" . $line_color . " class=\"white\">$pjob[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$pmovetype[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\"><a href=\"spy.php?command=change&spy_id=$pspy_id[$i]\">$l_spy_changejob</a></td>
				</tr>";
			}
			 ?>
		  </table>&nbsp;<br>
		<?php else: ?>
			<B><?php echo $this->_vars['l_spy_no2']; ?></B><BR><BR>
		<?php endif; ?>

		<?php if ($this->_vars['myplanetspycount']): ?>
			<table border="0" cellpadding="2" cellspacing="0" width="100%" class="border">
				<tr>
					<td bgcolor="#000000" colspan=4 align=center><font color=white><b><?php echo $this->_vars['l_spy_defaulttitle3']; ?></b></font></td>
				</tr>
				<tr>
					<td bgcolor="#000000"><b><u><?php echo $this->_vars['l_galaxy']; ?></u></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by3=sector"><?php echo $this->_vars['l_spy_sector']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by3=plnname"><?php echo $this->_vars['l_spy_planetname']; ?></a></b></td>
					<td bgcolor="#000000"><b><a href="spy.php?by3=spycnt"><?php echo $this->_vars['l_spy_onplanet']; ?></a></b></td>
				</tr>
			<?php extract($this->_vars, EXTR_REFS);  
			for ($i = 0; $i < $ownplanetspycount; $i++)
			{
				if($line_color == "#000000")   
					$line_color = "#000000"; 
				else
					$line_color = "#000000"; 
				echo "<tr>
					<td bgcolor=" . $line_color . " class=\"white\">$galaxylocationownplanets[$i]</td>";
				if($galaxylocationgalaxyownplanets[$i] == $currentgalaxy)
				{
					echo "<td bgcolor=" . $line_color . " class=\"white\"><a href=\"main.php?move_method=real&engage=1&destination=$mpsector[$i]\">$mpsector[$i]</a></td>";
				}
				else
				{
					echo "<td bgcolor=" . $line_color . " class=\"white\">$mpsector[$i]</td>";
				}
				echo "<td bgcolor=" . $line_color . " class=\"white\">$mpname[$i]</td>
					<td bgcolor=" . $line_color . " class=\"white\"><b>$mpcount[$i]</b></td>
				</tr>";
			}
			 ?>
		 	</table>&nbsp;<BR>
		<?php else: ?>
		  <B><?php echo $this->_vars['l_spy_no3']; ?></B><BR><BR>
		<?php endif; ?>
	<?php else: ?>
		<?php echo $this->_vars['l_spy_nospiesatall']; ?><BR>
	<?php endif; ?>


</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
