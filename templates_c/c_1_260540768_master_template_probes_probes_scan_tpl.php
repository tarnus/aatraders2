<h1><?php echo $this->_vars['title']; ?></h1>

<table border="1" cellspacing="1" cellpadding="2" width="100%">
	<TR BGCOLOR="#585980">
		<TD colspan="8" align="center"><font color="white"><B><?php echo $this->_vars['l_probe_scn_report']; ?></B></font></TD>
	</TR>
		<tr>
			<td BGCOLOR="#000000">
				<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="2" align="center">
					<TR BGCOLOR="#3A3B6E">
						<td>&nbsp;</td>
						<td>&nbsp;</td>
						<TD><B><?php echo $this->_vars['l_probe_engine']; ?></B></TD>
						<TD><B><?php echo $this->_vars['l_probe_sensors']; ?></B></TD>
						<TD><B><?php echo $this->_vars['l_probe_cloak']; ?></B></TD>
					</TR>
					<TR BGCOLOR="#23244F">
						<TD><?php echo $this->_vars['l_probe_defense_levels']; ?></TD>
						<td>&nbsp;</td>
						<TD><?php echo $this->_vars['probe_engines']; ?></TD>
						<TD><?php echo $this->_vars['probe_sensors']; ?></TD>
						<TD><?php echo $this->_vars['probe_cloak']; ?></TD>
					</TR>
				</TABLE>
			</td>
		</tr>
</TABLE>
<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
	<tr>
		<td><br><br><a href="probes.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_probe_linkback']; ?>.
		</td>
	</tr>
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
</table>
