<h1><?php echo $this->_vars['title']; ?></h1>

<table border=1 cellspacing=1 cellpadding=2 width="720" align=center bgcolor="#000000">
	<tr bgcolor="#400040">
		<td align="center" colspan=2><b><?php echo $this->_vars['l_tdr_tdrres']; ?></b></td>
	</tr>
	<tr align=center bgcolor="#400040">
		<td width="50%"><b><?php echo $this->_vars['l_tdr_planet']; ?> <?php echo $this->_vars['source_planet_name']; ?> <?php echo $this->_vars['l_tdr_within']; ?> <?php echo $this->_vars['source_sector_name']; ?></b></td>
		<td width="50%"><b><?php echo $this->_vars['l_tdr_planet']; ?> <?php echo $this->_vars['destination_planet_name']; ?> <?php echo $this->_vars['l_tdr_within']; ?> <?php echo $this->_vars['destination_sector_name']; ?></b></td>
	</tr>
	<tr bgcolor="#400040">
		<td colspan=2 align="center" valign="top">
			<table width="100%" border="0" cellspacing="3">
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['source_commodity']; ?>: <?php echo $this->_vars['source_commodity_start']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['source_commodity']; ?>: <?php echo $this->_vars['destination_commodity_start']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['destination_commodity']; ?>: <?php echo $this->_vars['source_commodity2_start']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['destination_commodity']; ?>: <?php echo $this->_vars['destination_commodity2_start']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['l_fighters']; ?>: <?php echo $this->_vars['source_start_fighters']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['l_fighters']; ?>: <?php echo $this->_vars['destination_start_fighters']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['l_torps']; ?>: <?php echo $this->_vars['source_start_torps']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['l_torps']; ?>: <?php echo $this->_vars['destination_start_torps']; ?></b></td>
              </tr>
            </table>
		</td>
	</tr>
	<tr bgcolor="#400040">
		<td colspan=2 align="center" valign="top">
			<table width="100%" border="0" cellspacing="3">
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['source_commodity']; ?> <?php echo $this->_vars['l_tdr_loaded']; ?>: <?php echo $this->_vars['source_commodity_loaded']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['source_commodity']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['source_commodity_dumped']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['destination_commodity']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['destination_commodity_dumped']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['destination_commodity']; ?> <?php echo $this->_vars['l_tdr_loaded']; ?>: <?php echo $this->_vars['destination_commodity_loaded']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_fighters']; ?> <?php echo $this->_vars['l_tdr_loaded']; ?>: <?php echo $this->_vars['total_fighters_bought']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_fighters']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['total_fighters_dumped']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_torps']; ?> <?php echo $this->_vars['l_tdr_loaded']; ?>: <?php echo $this->_vars['total_torps_bought']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_torps']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['total_torps_dumped']; ?></b></td>
              </tr>
            </table>
		</td>
	</tr>
	<tr bgcolor="#400040">
		<td colspan=2 align="center" valign="top">
			<table width="100%" border="0" cellspacing="3">
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['source_commodity']; ?>: <?php echo $this->_vars['source_commodity_total']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['source_commodity']; ?>: <?php echo $this->_vars['destination_commodity_total']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['destination_commodity']; ?>: <?php echo $this->_vars['source_commodity2_total']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['destination_commodity']; ?>: <?php echo $this->_vars['destination_commodity2_total']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['l_fighters']; ?>: <?php echo $this->_vars['source_total_fighters']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['l_fighters']; ?>: <?php echo $this->_vars['destination_total_fighters']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['l_torps']; ?>: <?php echo $this->_vars['source_total_torps']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['l_torps']; ?>: <?php echo $this->_vars['destination_total_torps']; ?></b></td>
              </tr>
            </table>
		</td>
	</tr>
	<tr bgcolor="#400040">
		<td colspan=2 align="center" valign="top">
			<table width="100%" border="0" cellspacing="3">
              <tr>
                <td width="50%"><b><?php echo $this->_vars['l_tdr_runscompleted']; ?>: <?php echo $this->_vars['tr_repeat']; ?></b></td>
                <td width="50%"><b>&nbsp;</b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_turnsused']; ?>: <?php echo $this->_vars['total_turns_used']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_turnsleft']; ?>: <?php echo $this->_vars['turns_left']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_energy']; ?> <?php echo $this->_vars['l_tdr_scooped']; ?>: <?php echo $this->_vars['total_energy_scooped']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_energy']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['total_energy_dumped']; ?></b></td>
              </tr>
            </table>
		</td>
	</tr>
	<tr bgcolor="#400040">
		<td align="center" colspan=2><b>
			<?php echo $this->_vars['l_tdr_engageagain']; ?>
			<form action="traderoute_engage.php?engage=<?php echo $this->_vars['engage']; ?>" method=post>
			<?php echo $this->_vars['l_tdr_timestorep']; ?> <input type=text name=tr_repeat value=1 size=3> <input type=submit value=<?php echo $this->_vars['l_submit']; ?>>
			</form>
			<?php echo $this->_vars['l_global_mmenu']; ?>
			</b>
		</td>
	</tr>
</table>

