<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">

	<FORM ACTION='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=transferfinal' METHOD=POST>

	<TR BGCOLOR="#585980"><TD><B><?php echo $this->_vars['l_commodity']; ?></B></TD><TD><B><?php echo $this->_vars['l_planet']; ?></B></TD><TD><B><?php echo $this->_vars['l_ship']; ?></B></TD><TD><B><?php echo $this->_vars['l_planet_transfer_link']; ?></B></TD><TD><B><?php echo $this->_vars['l_planet_toplanet']; ?></B></TD><TD><B><?php echo $this->_vars['l_all']; ?>?</B></TD></TR>
	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_ore']; ?></TD><TD><?php echo $this->_vars['planetore']; ?></TD><TD><?php echo $this->_vars['shipore']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_ore SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpore VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allore VALUE=-1></TD></TR>
	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_organics']; ?></TD><TD><?php echo $this->_vars['planetorganics']; ?></TD><TD><?php echo $this->_vars['shiporganics']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_organics SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tporganics VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allorganics VALUE=-1></TD></TR>
	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_goods']; ?></TD><TD><?php echo $this->_vars['planetgoods']; ?></TD><TD><?php echo $this->_vars['shipgoods']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_goods SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpgoods VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allgoods VALUE=-1></TD></TR>
	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_energy']; ?></TD><TD><?php echo $this->_vars['planetenergy']; ?></TD><TD><?php echo $this->_vars['shipenergy']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_energy SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpenergy VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allenergy VALUE=-1></TD></TR>

	<?php if ($this->_vars['special_name'] != "" && $this->_vars['isplanetowner']): ?>
		<TR BGCOLOR="#4A2B4E"><TD><?php echo $this->_vars['special_name']; ?><br><?php echo $this->_vars['l_port_hold_unit']; ?>: <?php echo $this->_vars['special_holds']; ?></TD><TD><?php echo $this->_vars['planetspecial']; ?></TD><TD><?php echo $this->_vars['shipspecial']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_special SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpspecial VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allspecial VALUE=-1></TD></TR>
	<?php else: ?>
		<INPUT TYPE="hidden" NAME="transfer_special" value="0">
	<?php endif; ?>
	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_colonists']; ?></TD><TD><?php echo $this->_vars['planetcolonists']; ?></TD><TD><?php echo $this->_vars['shipcolonists']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_colonists SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpcolonists VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allcolonists VALUE=-1></TD></TR>
	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_fighters']; ?></TD><TD><?php echo $this->_vars['planetfighters']; ?></TD><TD><?php echo $this->_vars['shipfighters']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_fighters SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpfighters VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allfighters VALUE=-1></TD></TR>
	<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_torps']; ?></TD><TD><?php echo $this->_vars['planettorps']; ?></TD><TD><?php echo $this->_vars['shiptorps']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_torps SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tptorps VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=alltorps VALUE=-1></TD></TR>
<?php if (( $this->_vars['team_cash_countdown'] == 0 && $this->_vars['maxtransfercredits'] != 0 ) || $this->_vars['maxtransfercredits'] == 0): ?>
	<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_credits']; ?> <?php echo $this->_vars['planetmaxcredit']; ?> <?php echo $this->_vars['l_max']; ?><br><?php echo $this->_vars['l_planet_max_transfer']; ?> <?php if ($this->_vars['maxtransfercredits'] == 0):  echo $this->_vars['l_planet_unlimited'];  else:  echo $this->_vars['maxtransfercredits_formatted'];  endif; ?></TD><TD><?php echo $this->_vars['planetcredits']; ?></TD><TD><?php echo $this->_vars['playercredits']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_credits SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpcredits VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allcredits VALUE=-1></TD></TR>
<?php else: ?>
	<input type=hidden name=allcredits value=0>
	<input type=hidden name=tpcredits value=0>
	<input type=hidden name=transfer_credits value=0>
<?php endif; ?>
	<?php if ($this->_vars['spytransfer'] == 1): ?>
		<TR BGCOLOR="#3A3B6E"><TD><?php echo $this->_vars['l_spy']; ?></TD><TD><?php echo $this->_vars['n_pl']; ?></TD><TD><?php echo $this->_vars['n_sh']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_spies SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpspies VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=allspies VALUE=-1></TD></TR>
	<?php endif; ?>
	<?php if ($this->_vars['digtransfer'] == 1): ?>
		<TR BGCOLOR="#23244F"><TD><?php echo $this->_vars['l_dig']; ?></TD><TD><?php echo $this->_vars['n_pld']; ?></TD><TD><?php echo $this->_vars['n_shd']; ?></TD><TD><INPUT TYPE=TEXT NAME=transfer_dignitary SIZE=10 MAXLENGTH=20></TD><TD><INPUT TYPE=CHECKBOX NAME=tpdigs VALUE=-1></TD><TD><INPUT TYPE=CHECKBOX NAME=alldigs VALUE=-1></TD></TR>
	<?php endif; ?>

</tr><td colspan=6>
								
								<BR>
	<INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_planet_transfer_link']; ?>>&nbsp;<INPUT TYPE=RESET VALUE=<?php echo $this->_vars['l_reset']; ?>>
	</FORM>	

	<BR><br><?php echo $this->_vars['l_planet_cinfo']; ?><BR>
	<BR><a href='planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>'><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><BR><BR>
	<?php if ($this->_vars['allow_ibank']): ?>
		<?php echo $this->_vars['l_ifyouneedplan']; ?> <A HREF="igb.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_igb_term']; ?></A>.<BR><BR>
	<?php endif; ?>

</td></tr>

<tr><td colspan=6><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

