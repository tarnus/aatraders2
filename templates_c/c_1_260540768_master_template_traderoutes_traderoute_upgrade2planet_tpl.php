<h1><?php echo $this->_vars['title']; ?></h1>

<table border=1 cellspacing=1 cellpadding=2 width="720" align=center bgcolor="#000000">
	<tr bgcolor="#400040">
		<td align="center" colspan=2><b><?php echo $this->_vars['l_tdr_tdrres']; ?></b></td>
	</tr>
	<tr align=center bgcolor="#400040">
		<td width="50%"><b><?php echo $this->_vars['source_port_type']; ?> <?php echo $this->_vars['l_tdr_portin']; ?> <?php echo $this->_vars['source_sector_name']; ?></b></td>
		<td width="50%"><b><?php echo $this->_vars['l_tdr_planet']; ?> <?php echo $this->_vars['destination_planet_name']; ?> <?php echo $this->_vars['l_tdr_within']; ?> <?php echo $this->_vars['destination_sector_name']; ?></b></td>
	</tr>
	<tr align=center bgcolor="#400040">
        <td width="50%" valign="top"><b><font color="green"><?php echo $this->_vars['l_tdr_starting_credits']; ?></font>: <?php echo $this->_vars['starting_player_credits']; ?></b></td>
        <td width="50%" valign="top"><b><font color="red"><?php echo $this->_vars['l_tdr_ending_credits']; ?></font>: <?php echo $this->_vars['ending_player_credits']; ?></b></td>
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
                <td width="50%" valign="top"><b><?php echo $this->_vars['total_fighters_bought']; ?> <?php echo $this->_vars['l_fighters']; ?> @ <?php echo $this->_vars['fighter_price']; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_fighters']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['total_fighters_dumped']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['total_torps_bought']; ?> <?php echo $this->_vars['l_torps']; ?> @ <?php echo $this->_vars['torpedo_price']; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_torps']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['total_torps_dumped']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_energy']; ?> <?php echo $this->_vars['l_tdr_scooped']; ?>: <?php echo $this->_vars['total_energy_scooped']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_energy']; ?> <?php echo $this->_vars['l_tdr_dumped']; ?>: <?php echo $this->_vars['total_energy_dumped']; ?></b></td>
              </tr>
            </table>
		</td>
	</tr>
	<tr align=center bgcolor="#400040">
        <td colspan="2"><div align="center"><b>
			<?php if ($this->_vars['profit_loss']): ?>
				<font color="red"><?php echo $this->_vars['l_tdr_totalcost']; ?></font>
			<?php else: ?>
				<font color="green"><?php echo $this->_vars['l_tdr_totalprofit']; ?></font>
			<?php endif; ?>: <?php echo $this->_vars['final_credits']; ?> </b></div></td>
        </tr>
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

