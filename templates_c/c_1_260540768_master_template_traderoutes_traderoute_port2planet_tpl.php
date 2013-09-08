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
		<td width="50%" valign="top">
			<p><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_tdr_start']; ?></b><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="4" alt="px" />
			<img src="templates/master_template/images/white_dot.gif" width="50%" height="1" alt="px" /><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="7" alt="px" />
			<b><?php echo $this->_vars['l_tdr_selling']; ?> <?php echo $this->_vars['sourceport_sell_item_type']; ?> <?php echo $this->_vars['sourceport_sell_commodity_amount']; ?> <?php echo $this->_vars['l_tdr_units']; ?> @ <?php echo $this->_vars['sourceport_sell_item_price']; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b>
			</p>
			<p>
			<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['sourceport_buy_item_type']), 'iteration' => 0);
if (count((array)$this->_vars['sourceport_buy_item_type'])): foreach ((array)$this->_vars['sourceport_buy_item_type'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
				<b><?php echo $this->_vars['l_tdr_buying']; ?> <?php echo $this->_vars['item']; ?> <?php echo $this->_vars['sourceport_buy_commodity_amount'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_units']; ?> @ <?php echo $this->_vars['sourceport_buy_item_price'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b><br />
 			<?php endforeach; endif; ?>
			</p>
		</td>
		<td width="50%" valign="top">
			<p><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_tdr_start']; ?></b><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="4" alt="px" />
			<img src="templates/master_template/images/white_dot.gif" width="50%" height="1" alt="px" /><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="7" alt="px" />

                <b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['source_commodity']; ?>: <?php echo $this->_vars['destination_commodity_start']; ?></b><br>
                	<b><?php echo $this->_vars['l_tdr_start']; ?> <?php echo $this->_vars['destination_commodity']; ?>: <?php echo $this->_vars['destination_commodity2_start']; ?></b>
			</p>
		</td>
	</tr>
	<tr align=center bgcolor="#400040">
		<td width="50%" valign="top">
			<p><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_tdr_finish']; ?></b><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="4" alt="px" />
			<img src="templates/master_template/images/white_dot.gif" width="50%" height="1" alt="px" /><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="7" alt="px" />
			<b><?php echo $this->_vars['l_tdr_selling']; ?> <?php echo $this->_vars['sourceport_sell_item_type']; ?> <?php echo $this->_vars['final_source_sell_amount']; ?> <?php echo $this->_vars['l_tdr_units']; ?> @ <?php echo $this->_vars['final_source_sell_price']; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b>
			</p>
			<p>
			<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['final_source_buy_type']), 'iteration' => 0);
if (count((array)$this->_vars['final_source_buy_type'])): foreach ((array)$this->_vars['final_source_buy_type'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
				<b><?php echo $this->_vars['l_tdr_buying']; ?> <?php echo $this->_vars['item']; ?> <?php echo $this->_vars['final_source_buy_amount'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_units']; ?> @ <?php echo $this->_vars['final_source_buy_price'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b><br />
 			<?php endforeach; endif; ?>
			</p>
		</td>
		<td width="50%" valign="top">
			<p><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_tdr_finish']; ?></b><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="4" alt="px" />
			<img src="templates/master_template/images/white_dot.gif" width="50%" height="1" alt="px" /><br>
			<img src="templates/master_template/images/spacer.gif" width="100%" height="7" alt="px" />

			<b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['source_commodity']; ?>: <?php echo $this->_vars['destination_commodity_total']; ?></b><br>
                	<b><?php echo $this->_vars['l_tdr_finish']; ?> <?php echo $this->_vars['destination_commodity']; ?>: <?php echo $this->_vars['destination_commodity2_total']; ?></b>
			</p>
		</td>
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
                <td width="50%"><b><?php echo $this->_vars['l_tdr_energy']; ?> <?php echo $this->_vars['l_tdr_scooped']; ?>: <?php echo $this->_vars['total_energy_scooped']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_turnsused']; ?>: <?php echo $this->_vars['total_turns_used']; ?></b></td>
                <td width="50%" valign="top"><b><?php echo $this->_vars['l_tdr_turnsleft']; ?>: <?php echo $this->_vars['turns_left']; ?></b></td>
              </tr>
              <tr>
                <td width="50%" valign="top">
					<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['commodity_total_sold']), 'iteration' => 0);
if (count((array)$this->_vars['commodity_total_sold'])): foreach ((array)$this->_vars['commodity_total_sold'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
						<?php if ($this->_vars['commodity_total_sold'][$this->_vars['key']] > 0): ?>
							<b><?php echo $this->_vars['l_tdr_sold']; ?> <?php echo $this->_vars['key']; ?> <?php echo $this->_vars['commodity_total_sold'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_units']; ?>: <?php echo $this->_vars['commodity_total_credits_made'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b><br />
						<?php endif; ?>
 					<?php endforeach; endif; ?>				</td>
                <td width="50%" valign="top">
					<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['commodity_total_bought']), 'iteration' => 0);
if (count((array)$this->_vars['commodity_total_bought'])): foreach ((array)$this->_vars['commodity_total_bought'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
						<?php if ($this->_vars['commodity_total_bought'][$this->_vars['key']] > 0): ?>
							<b><?php echo $this->_vars['l_tdr_bought']; ?> <?php echo $this->_vars['key']; ?> <?php echo $this->_vars['commodity_total_bought'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_units']; ?>: <?php echo $this->_vars['commodity_total_credits_lost'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_tdr_credits']; ?></b><br />
						<?php endif; ?>
 					<?php endforeach; endif; ?>				</td>
              </tr>
              <tr>
                <td width="50%" valign="top"><b><font color="green"><?php echo $this->_vars['l_tdr_totalprofit']; ?></font>: <?php echo $this->_vars['total_credits_made']; ?></b></td>
                <td width="50%" valign="top"><b><font color="red"><?php echo $this->_vars['l_tdr_totalcost']; ?></font>: <?php echo $this->_vars['total_credits_lost']; ?></b></td>
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

