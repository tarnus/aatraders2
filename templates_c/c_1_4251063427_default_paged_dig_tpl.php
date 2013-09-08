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

<script language="javascript">

function changed_dig(name)
{
	document.forms[0].elements[name].value = 1;
}

</script>
'; ?>


<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
	<?php if ($this->_vars['totaldigs']): ?>
		<TR BGCOLOR="#000000"><td><font color=white><b><?php echo $this->_vars['l_dig_legend']; ?></b></font></td><td><font color=white><b><?php echo $this->_vars['l_dig_max']; ?></b></font></td><TD><font color=white><B><?php echo $this->_vars['l_dig_description']; ?></B></font></TD></TR>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['job_name']), 'iteration' => 0);
if (count((array)$this->_vars['job_name'])): foreach ((array)$this->_vars['job_name'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<TR BGCOLOR="#000000"><td><font color=white><?php echo $this->_vars['job_name'][$this->_vars['key']]; ?></font></td><td><font color=white><?php echo $this->_vars['max_digs'][$this->_vars['key']]; ?></font></td><TD><font color=white><?php echo $this->_vars['description'][$this->_vars['key']]; ?></font></TD></TR>
		<?php endforeach; endif; ?>
	</table>
	<br>
		<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
		<?php if ($this->_vars['totaldigsbyplanet']): ?>
			<TR BGCOLOR="#000000"><TD colspan=5 align=center><font color=white><B><?php echo $this->_vars['l_dig_defaulttitle2']; ?></B></font></TD></TR>
			<TR BGCOLOR="#000000">
			<TD><B><A HREF=dig.php?by2=id><?php echo $this->_vars['l_dig_codenumber']; ?></A></B></TD>
			<TD><B><A HREF=dig.php?by2=planet><?php echo $this->_vars['l_dig_planetname']; ?></A></B></TD>
			<TD><B><u><?php echo $this->_vars['l_galaxy']; ?></u></B></TD>
			<TD><B><A HREF=dig.php?by2=sector><?php echo $this->_vars['l_dig_sector']; ?></A></B></TD>
			<TD><B><A HREF=dig.php?by2=job_id><?php echo $this->_vars['l_dig_job']; ?></A></B></TD>
			<TD width="50%"><font color=white><B><?php echo $this->_vars['l_dig_changeerror']; ?></B></font></TD>
			</TR>
			<FORM ACTION="dig.php" METHOD="POST">
			<INPUT TYPE="hidden" name="command" value="update">
			<?php extract($this->_vars, EXTR_REFS);  
			$line_color = "#000000";
			for($i = 0; $i < $digcount; $i++)
			{
				if($line_color == "#000000")
				{   
					$line_color = "#000000"; 
				}
				else
				{
					$line_color = "#000000"; 
				}

				echo "<TR BGCOLOR=\"$line_color\">
					<TD><font size=\"2\" color=\"white\">$digid[$i]</font></TD>
					<TD><font size=\"2\" color=\"white\">$digname[$i]</font></TD>
					<TD><font size=\"2\" color=\"white\">$galaxylocation[$i]</font></TD>";
				if($galaxylocationgalaxy[$i] == $currentgalaxy)
				{
					echo "<TD><font size=\"2\"><a href=\"main.php?move_method=real&engage=1&destination=$digsector[$i]\">$digsector[$i]</a></font></TD>\n";
				}
				else
				{
					echo "<TD><font size=\"2\">$digsector[$i]</font></TD>\n";
				}
				echo "<TD><font size=\"2\"><select onChange=\"changed_dig('digchanged[" . $i . "]')\" name=\"changedig[$i]\">\n";
				for($type = 0; $type < $classcount; $type++)
				{
					if($digjob[$i] == $job_type[$type])
					{
						echo "<option value=\"$job_type[$type]\" selected>" . $job_name[$job_type[$type]] . "</option>\n";
					}
					else
					{
						echo "<option value=\"$job_type[$type]\">" . $job_name[$job_type[$type]] . "</option>\n";
					}
				}
				echo "</select></font></TD>\n";
				echo "<td>" . $digerrorresult[$i] . "</td>\n";
				echo "<INPUT TYPE=\"hidden\" name=\"planet_id[$i]\" value=\"$digplanetid[$i]\"><INPUT TYPE=\"hidden\" name=\"dig_id[$i]\" value=\"$digid[$i]\"><INPUT TYPE=\"hidden\" name=\"digchanged[$i]\" value=\"0\"></TR>\n";
			}
			 ?>
			<TR BGCOLOR="#000000">
			<TD colspan=5 align=center><INPUT TYPE="hidden" name="digcount" value="<?php echo $this->_vars['digcount']; ?>">
			<INPUT TYPE="submit" value="<?php echo $this->_vars['l_dig_changebutton']; ?>"></td></tr>
			</FORM>
			</TABLE><BR><BR>
		<?php else: ?>
			<B><?php echo $this->_vars['l_dig_no2']; ?></B><BR><BR>
		<?php endif; ?>

		<table border="0" cellpadding="0" cellspacing="0" width="100%">
			<tr>
				<td bgcolor="#000000"><font color=white><b>&nbsp;
					<?php if ($this->_vars['digonship']): ?>
						<?php echo $this->_vars['l_dig_defaulttitle4']; ?>:  <span class="yellow"><?php echo $this->_vars['digshiptotal']; ?></span>
					<?php else: ?> 
						<?php echo $this->_vars['l_dig_no4']; ?>
					<?php endif; ?>
					</b></font>
				</td>
			</tr>

		&nbsp;<br>
	<?php else: ?>
		<tr><td><?php echo $this->_vars['l_dig_nodignitaryatall']; ?>.</td><tr>
	<?php endif; ?>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
