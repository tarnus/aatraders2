<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td><?php if ($this->_vars['planetowner'] != 3): ?>
			<?php echo $this->_vars['l_planet_scn']; ?> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<?php echo $this->_vars['l_planet_att']; ?><p></p>
		<?php endif; ?>
		
		<?php if ($this->_vars['novaavailible'] == 1): ?>
			<a href="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=nova"><?php echo $this->_vars['l_planet_firenova']; ?></a><BR>
		<?php endif; ?>

		<?php if ($this->_vars['sofaavailible'] == 1): ?> 
			<a href="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&command=sofa"><?php echo $this->_vars['l_sofa']; ?></a><BR>
		<?php endif; ?>
		
		<?php if ($this->_vars['enable_spies'] == 1): ?>
			<?php if ($this->_vars['numspies'] != 0): ?>
				<BR><table border=1 cellspacing=1 cellpadding=2 width="100%">
				<TR BGCOLOR="#000000"><TD colspan=99 align=center><font color=white><B><?php echo $this->_vars['l_spy_yourspies']; ?> </font> (<?php echo $this->_vars['numspies']; ?>)
				<?php if ($this->_vars['addaspy'] == 1): ?>
					<a href="spy.php?command=send&planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_spy_sendnew']; ?></a>
				<?php endif; ?>
				</B></TD></TR>
				<TR BGCOLOR="#000000">
				<TD><B><A HREF="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['ID']; ?></A></B></TD>
				<TD><B><A HREF="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&by=job_id"><?php echo $this->_vars['l_spy_job']; ?></A></B></TD>
				<TD><B><A HREF="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>&by=move_type"><?php echo $this->_vars['l_spy_move']; ?></A></B></TD>
				<TD><font color=white><B><a href="#"><?php echo $this->_vars['l_spy_action']; ?></a></B></font></TD>
				<TD><font color=white><B><a href="#"><?php echo $this->_vars['l_spy_changebutton']; ?></a></B></font></TD>
				</TR>
		
				<?php extract($this->_vars, EXTR_REFS);  
				for($i = 0; $i < $numspies; $i++){
					echo "<TR BGCOLOR=" . $color[$i] ."><TD><font size=2 color=white>$spyid[$i]</font></TD><TD><font size=2 color=white>$job[$i]</font></TD><TD><font size=2 color=white>$spymove[$i]</font></TD><TD><font size=2><a href=spy.php?command=comeback&spy_id=$spyid[$i]&planet_id=$planet_id>$l_spy_comeback</a></font></TD><TD><font size=2><a href=spy.php?command=change&spy_id=$spyid[$i]&planet_id=$planet_id>$l_spy_changejob</a></font></TD></TR>";
				}
				 ?>
				</TABLE><BR>

				<BR><TABLE BORDER=0 CELLSPACING=0 CELLPADDING=2 width="100%">
				<TR BGCOLOR="#000000"><TD>&nbsp;</TD><TD align="center"><B><?php echo $this->_vars['l_base']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_fighter']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_sensors']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_beams']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_torp_launch']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_shields']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_jammer']; ?></B></TD>
				<TD align="center"><B><?php echo $this->_vars['l_planetary_cloak']; ?></B></TD></TR>
				<TR BGCOLOR="#000000"><TD><?php echo $this->_vars['l_planetary_defense_levels']; ?>&nbsp;</TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetbased']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetfighter']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetsensors']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetbeams']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetlaunchers']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetshields']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetjammer']; ?>" SIZE=3 MAXLENGTH=3 ></TD>	  
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetcloak']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				</TR>
				</TABLE><BR>
				<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=2 width="100%">
				<TR BGCOLOR="#000000"><TD>&nbsp;</TD><TD align="center"><B><?php echo $this->_vars['l_planetary_SD_weapons']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_SD_sensors']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_planetary_SD_cloak']; ?></B></TD></TR>
				<TR BGCOLOR="#000000"><TD><?php echo $this->_vars['l_planetary_defense_levels']; ?>&nbsp;</TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['sector_defense_weapons']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['sector_defense_sensors']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['sector_defense_cloak']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				</TR>
				</TABLE><br><BR>
				<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=2>
				<TR BGCOLOR="#000000"><TD>&nbsp;</TD><TD align="center"><B><?php echo $this->_vars['l_ore']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_organics']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_goods']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_specialname']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_energy']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_colonists']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_credits']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_fighters']; ?></B></TD><TD align="center"><B><?php echo $this->_vars['l_torps']; ?></B></TD>
				</TR><TR BGCOLOR="#000000">
				<TD><?php echo $this->_vars['l_current_qty']; ?></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetore']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetorganics']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetgoods']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetspecial']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetenergy']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetcolonists']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetcredits']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planetfighters']; ?>" SIZE=14 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['planettorps']; ?>" SIZE=14 ></TD>
				</TR>
				<TR BGCOLOR="#000000"><TD><?php echo $this->_vars['l_planet_perc']; ?></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodore']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodorganics']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodgoods']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodspecial']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodenergy']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><?php echo $this->_vars['na']; ?></TD><TD align="center">*</TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodfighters']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				<TD align="center"><INPUT TYPE=TEXT VALUE="<?php echo $this->_vars['prodtorp']; ?>" SIZE=3 MAXLENGTH=3 ></TD>
				</TABLE><?php echo $this->_vars['l_planet_interest']; ?><BR><BR>
			<?php else: ?>
				<?php if ($this->_vars['planetowner'] != 3): ?>
					<?php echo $this->_vars['l_spy_nospieshere']; ?>. 
					<a href="spy.php?command=send&planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_spy_sendnew']; ?></a><BR>
				<?php endif; ?>
			<?php endif; ?>  
		<?php endif; ?>  

		<BR><a href="planet.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_toplanetmenu']; ?><BR><BR>

		<?php if ($this->_vars['allow_ibank'] == 1): ?>
			<?php echo $this->_vars['l_ifyouneedplan']; ?> <A HREF="igb.php?planet_id=<?php echo $this->_vars['planet_id']; ?>"><?php echo $this->_vars['l_igb_term']; ?></A>.<BR><BR>
		<?php endif; ?>

		<A HREF ="bounty.php"><?php echo $this->_vars['l_by_placebounty']; ?></A><p>
</td></tr>

<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
