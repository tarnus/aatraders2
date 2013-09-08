<?php if ($this->_vars['ajax'] != 1): ?>
<h1><?php echo $this->_vars['title']; ?></h1>
<?php endif; ?>
<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="0" WIDTH="100%" BGCOLOR="<?php echo $this->_vars['color_header']; ?>">
	<tr>
		<td valign="top" width="49%">
			<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="0" WIDTH="100%" bgcolor="#000000">
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>">
					<TD><B><?php echo $this->_vars['l_sector']; ?>  <?php echo $this->_vars['sector']; ?></B></TD>
				</TR>
				<TR BGCOLOR="#23244F">
					<TD><B><?php echo $this->_vars['l_links']; ?></B></TD>
				</TR>
				<TR>
					<TD><?php echo $this->_vars['link_list']; ?></TD>
				</TR>
				<TR BGCOLOR="#23244F">
					<TD><B><?php echo $this->_vars['l_ships']; ?></B></TD>
				</TR>
				<TR>
					<TD>
						<?php if ($this->_vars['sectornum'] == 1): ?>
							<?php echo $this->_vars['l_lrs_zero']; ?>
						<?php else: ?>
							<?php if ($this->_vars['num_detected'] == 0): ?>
								<?php echo $this->_vars['l_none']; ?>
							<?php else: ?>
								<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['ship_name']), 'iteration' => 0);
if (count((array)$this->_vars['ship_name'])): foreach ((array)$this->_vars['ship_name'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
									<?php echo $this->_vars['ship_name'][$this->_vars['key']]; ?> (<?php echo $this->_vars['player_name'][$this->_vars['key']]; ?>)
										<?php if ($this->_vars['sector_zone'] != 2 && $this->_vars['sector_missile'] != 0): ?>
											<?php if ($this->_vars['ship_bounty'][$this->_vars['key']] > 0): ?>
												 <font color='red'><b><?php echo $this->_vars['l_by_bountyscan']; ?></b></font>
											<?php endif; ?>
											 - <a href="combat_sector_missile.php?sector=<?php echo $this->_run_modifier($this->_vars['sector'], 'urlencode', 'PHP', 1); ?>&ship_id=<?php echo $this->_vars['ship_id'][$this->_vars['key']]; ?>"><?php echo $this->_vars['l_clickme']; ?></a><?php echo $this->_vars['l_lrs_sectormissile_question']; ?>
										<?php endif; ?>
										 - 
										<?php if ($this->_vars['shipratingnumber'][$this->_vars['key']] == -1): ?>
												<font color="red"><?php echo $this->_vars['shiprating'][$this->_vars['key']]; ?></font>
										<?php elseif ($this->_vars['shipratingnumber'][$this->_vars['key']] == 0): ?>
											<font color="yellow"><?php echo $this->_vars['shiprating'][$this->_vars['key']]; ?></font>
										<?php else: ?>
											<font color="lime"><?php echo $this->_vars['shiprating'][$this->_vars['key']]; ?></font>
										<?php endif; ?>
										<br>
								<?php endforeach; endif; ?>
							<?php endif; ?>
						<?php endif; ?>
					</TD>
				</TR>
				<TR BGCOLOR="#23244F">
					<TD><B><?php echo $this->_vars['l_port']; ?></B></TD>
				</TR>
				<TR>
					<TD>
						<?php if ($this->_vars['port_type'] != "none"): ?>
							<img align="absmiddle" height="12" width="12" alt="<?php echo $this->_vars['icon_alt_text']; ?>" src="images/ports/<?php echo $this->_vars['icon_port_type_name']; ?>.png">
						<?php endif; ?>
						<?php echo $this->_vars['icon_alt_text']; ?>
					</TD>
				</TR>
				<TR BGCOLOR="#23244F">
					<TD><B><?php echo $this->_vars['l_planets']; ?></B></TD>
				</TR>
				<TR>
					<TD>
						<TABLE bgcolor="#000000">
							<tr>
								<?php if ($this->_vars['planetsfound'] == 0): ?>
									<td><?php echo $this->_vars['l_none']; ?></td>
								<?php else: ?>
									<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['planetid']), 'iteration' => 0);
if (count((array)$this->_vars['planetid'])): foreach ((array)$this->_vars['planetid'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
										<td align="center" valign="top" style="text-align:center;margin:0 auto;">
											<?php if ($this->_vars['planetbounty'][$this->_vars['key']] > 0): ?>
												<font color='red' size='4'><p align="center"><b><?php echo $this->_vars['l_by_bountyscan']; ?></b></p></font></br>
											<?php endif; ?>
											<A HREF="planet.php?planet_id=<?php echo $this->_vars['planetid'][$this->_vars['key']]; ?>">
											<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/master_template/images/planet" . $this->_vars['planetimg'][$this->_vars['key']] . ".png", 'alt' => "", 'width' => "100", 'height' => "100")); ?>
											</a><BR><font size="2" color="white" face="arial">
											<?php echo $this->_vars['planetname'][$this->_vars['key']]; ?>
											<br>(<?php echo $this->_vars['planetowner'][$this->_vars['key']]; ?>)
											</font>
											<br><?php if ($this->_vars['planetratingnumber'][$this->_vars['key']] == -1): ?>
												<font color="red"><?php echo $this->_vars['planetrating'][$this->_vars['key']]; ?></font>
											<?php elseif ($this->_vars['planetratingnumber'][$this->_vars['key']] == 0): ?>
												<font color="yellow"><?php echo $this->_vars['planetrating'][$this->_vars['key']]; ?></font>
											<?php else: ?>
												<font color="lime"><?php echo $this->_vars['planetrating'][$this->_vars['key']]; ?></font>
											<?php endif; ?>
										</td>
									<?php endforeach; endif; ?>
								<?php endif; ?>
							</tr>
						</TABLE>
					</TD>
				</TR>
				<TR BGCOLOR="#23244F">
					<TD><B><?php echo $this->_vars['l_fighters']; ?></B></TD>
				</TR>
				<TR>
					<TD>
						<?php if ($this->_vars['mines_count'] > 0): ?>
							<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['fighter_owner']), 'iteration' => 0);
if (count((array)$this->_vars['fighter_owner'])): foreach ((array)$this->_vars['fighter_owner'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
								<?php echo $this->_vars['fighter_amount'][$this->_vars['key']]; ?> (<?php echo $this->_vars['item']; ?>)
								<?php if ($this->_vars['fighter_bounty'][$this->_vars['key']] > 0): ?>
									<?php echo $this->_vars['l_by_bountyscan']; ?>
								<?php endif; ?>
								<br>
							<?php endforeach; endif; ?>
						<?php else: ?>
							0
						<?php endif; ?>
					</TD>
				</TR>
				<TR BGCOLOR="#23244F">
					<TD><B><?php echo $this->_vars['l_mines']; ?></B></TD>
				</TR>
				<TR>
					<TD>
						<?php if ($this->_vars['mines_count'] > 0): ?>
							<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['mines_owner']), 'iteration' => 0);
if (count((array)$this->_vars['mines_owner'])): foreach ((array)$this->_vars['mines_owner'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
								<?php echo $this->_vars['mines_amount'][$this->_vars['key']]; ?> (<?php echo $this->_vars['item']; ?>)
								<?php if ($this->_vars['mines_bounty'][$this->_vars['key']] > 0): ?>
									<?php echo $this->_vars['l_by_bountyscan']; ?>
								<?php endif; ?>
								<br>
							<?php endforeach; endif; ?>
						<?php else: ?>
							0
						<?php endif; ?>
					</TD>
				</TR>
				<?php if ($this->_vars['sectornum'] != '1'): ?>
					<TR BGCOLOR="#23244F">
						<TD><B><?php echo $this->_vars['l_lss']; ?></B></TD>
					</TR>
					<TR>
						<TD><?php echo $this->_vars['lss_info']; ?><br><br></TD>
					</tr>
				<?php endif; ?>
			</TABLE>
<?php if ($this->_vars['ajax'] != 1): ?>
			<BR>
			<a href="main.php?move_method=warp&destination=<?php echo $this->_run_modifier($this->_vars['sector'], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_lrs_moveto']; ?> <?php echo $this->_vars['sector']; ?>.
<?php endif; ?>
			<BR><BR>
		</td>
<?php if ($this->_vars['ajax'] != 1): ?>
		<td width="2%">&nbsp;</td>
		<td valign="top"><b><?php echo $this->_vars['l_sn_addnote']; ?></b><br>
			<FORM ACTION="sector_notes.php" METHOD="POST">
			<input type="Hidden" name="command" value="<?php echo $this->_vars['l_sn_addnote']; ?>">	
			<input type="Hidden" name="sectornum" value="<?php echo $this->_vars['sector']; ?>">
			<input type="Hidden" name="sectornumber" value="<?php echo $this->_vars['sectornum']; ?>">
            <input type="Hidden" name="limit" value="<?php echo $this->_vars['limit']; ?>">
            

<input type="Hidden" name="galaxy_name" value="<?php echo $this->_vars['galaxy_name']; ?>">
<input type="Hidden" name="port_name" value="<?php echo $this->_vars['icon_alt_text']; ?>">
<input type="Hidden" name="port" value="<?php echo $this->_vars['icon_alt_text']; ?>">

            
			<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="2" BGCOLOR="#23244F">
			<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
				<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdscanfrom']; ?>&nbsp;</B></font></TD>
				<td>&nbsp;</td>
				<TD ALIGN="left"><font size="2"><input type="Text" name="scanfrom" width="10" value="<?php echo $this->_vars['scanfromname']; ?>">&nbsp;</font></TD>
			</tr>
			<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
				<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdtype']; ?>&nbsp;</B></font></TD>
				<td>&nbsp;</td>
				<TD ALIGN="left"><font size="2"><select name=stype>
					<option value="">N/A</option>
					<option value="Ally" ><?php echo $this->_vars['l_sn_ally']; ?></option>
					<option value="Base"><?php echo $this->_vars['l_sn_base']; ?></option>
					<option value="Enemy"><?php echo $this->_vars['l_sn_enemy']; ?></option>
					<option value="Indy"><?php echo $this->_vars['l_sn_indy']; ?></option>
					<option value="Port"><?php echo $this->_vars['l_sn_port']; ?></option>
					<option value="Team Base"><?php echo $this->_vars['l_sn_teambase']; ?></option>
					<option value="Minefield"><?php echo $this->_vars['l_sn_minefield']; ?></option>
					<option value="SG Entry"><?php echo $this->_vars['l_sn_sg_entry']; ?></option>
					<option value="Spy Sector"><?php echo $this->_vars['l_sn_spysector']; ?></option>
					</select>
					&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdowner']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2"><input type="Text" name="owner" width="10" >&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdplanets']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2"><input type="Text" name="planets" width="10" value="<?php echo $this->_vars['planetsfound']; ?>">&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdport']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2"><input type="Text" name="port" width="10" value="<?php if ($this->_vars['port_type'] == "wormhole"):  echo $this->_vars['icon_alt_text'];  else:  echo $this->_vars['port_type'];  endif; ?>">&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdfighters']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2"><input type="Text" name="fighters" width="10" value="<?php echo $this->_vars['has_fighters']; ?>">&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdmines']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size=2><input type="Text" name="mines" width="10" value="<?php echo $this->_vars['has_mines']; ?>">&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdteam']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2">
						<?php if ($this->_vars['team_note'] == 0): ?>
							<input type="checkbox" name="team" disabled>
						<?php else: ?>
							<input type="checkbox" name="team" >
						<?php endif; ?>
						&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hddetail']; ?>&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2"><textarea name="note" cols="20" rows="5"></textarea>&nbsp;</font></TD>
				</tr>
				<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="top">
					<TD ALIGN="left"><font size="2"><B>&nbsp;&nbsp;</B></font></TD>
					<td>&nbsp;</td>
					<TD ALIGN="left"><font size="2"><INPUT TYPE=SUBMIT VALUE="<?php echo $this->_vars['l_sn_addnote']; ?>">&nbsp;</font></TD>	
				</tr>
			</TABLE>
			</form>
		</td>
	<?php endif; ?>
	</tr>
</table>
<?php if ($this->_vars['notelistcount'] > 0): ?>
	<?php $this->assign('color_line1', "#000000"); ?>
	<?php $this->assign('color_line2', "#454560"); ?>
	<?php $this->assign('color_header', "#454560"); ?>

	<b><?php echo $this->_vars['l_sn_title']; ?></b><br>
	<FORM ACTION="sector_notes.php" METHOD="POST">
	<input type="hidden" name="limit" value="1">
	<input type="hidden" name="lrscan" value="<?php echo $this->_vars['sector']; ?>">
    
<input type="Hidden" name="galaxy_name" value="<?php echo $this->_vars['galaxy_name']; ?>">
<input type="Hidden" name="port_name" value="<?php echo $this->_vars['icon_alt_text']; ?>">
<input type="Hidden" name="port" value="<?php echo $this->_vars['icon_alt_text']; ?>">
	<TABLE WIDTH="100%" BORDER="0" CELLSPACING="0" CELLPADDING="2">
		<TR BGCOLOR="<?php echo $this->_vars['color_header']; ?>" VALIGN="BOTTOM">
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdsector']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdtype']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdowner']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdplanets']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdport']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdfighters']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdmines']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdscanfrom']; ?>&nbsp;</B></font></TD>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hddetail']; ?>&nbsp;</B></font></TD>
			<?php if ($this->_vars['team_note'] > 0): ?>
				<TD ALIGN="RIGHT"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hdteam']; ?>&nbsp;</B></font></TD>
			<?php endif; ?>
			<TD ALIGN="CENTER"><font size="2"><B>&nbsp;<?php echo $this->_vars['l_sn_hddelete']; ?>&nbsp;</B></font></TD>	
		</TR>
		<?php $this->assign('color', $this->_vars['color_line1']); ?>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['sectorlist']), 'iteration' => 0);
if (count((array)$this->_vars['sectorlist'])): foreach ((array)$this->_vars['sectorlist'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<TR BGCOLOR="<?php echo $this->_vars['color']; ?>">
				<TD ALIGN="CENTER"><font size="2">&nbsp;<A HREF="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['sectorlist'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['sectorlist'][$this->_vars['key']]; ?></A>&nbsp;</font></TD>
				<TD ALIGN="CENTER"><font size="2">&nbsp;<?php echo $this->_vars['sector_type'][$this->_vars['key']]; ?>&nbsp;</font></TD>
				<TD ALIGN="center"><font size="2">&nbsp;<?php echo $this->_vars['sector_owner'][$this->_vars['key']]; ?>&nbsp;</font></TD>
				<TD ALIGN="center"><font size="2">&nbsp;<?php echo $this->_vars['sector_planets'][$this->_vars['key']]; ?>&nbsp;</font></TD>
				<TD ALIGN="center"><font size="2">&nbsp;<?php echo $this->_vars['sector_port'][$this->_vars['key']]; ?>&nbsp;</font></TD>
				<TD ALIGN="center"><font size="2">&nbsp;<?php echo $this->_vars['sector_fighters'][$this->_vars['key']]; ?>&nbsp;</font></TD>
				<TD ALIGN="center"><font size="2">&nbsp;<?php echo $this->_vars['sector_mines'][$this->_vars['key']]; ?>&nbsp;</font></TD>
				<?php if ($this->_vars['sector_scanfrom'][$this->_vars['key']] != ""): ?>
					<TD ALIGN="CENTER"><font size="2">&nbsp;<A HREF="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['sector_scanfrom'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['sector_scanfrom'][$this->_vars['key']]; ?></A>&nbsp;</font></TD>
				<?php else: ?>
					<TD ALIGN="CENTER"><font size="2">&nbsp;N/A&nbsp;</font></TD>
				<?php endif; ?>
				<TD ALIGN="CENTER"><font size="2">&nbsp;<A HREF="sector_notes.php?command=<?php echo $this->_vars['l_sn_view']; ?>&sector=<?php echo $this->_run_modifier($this->_vars['sectorlist'][$this->_vars['key']], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['l_sn_view']; ?></a>&nbsp;</font></TD>
				<?php if ($this->_vars['team_note'] > 0): ?>
					<TD ALIGN="CENTER"><font size="2">&nbsp;
						<?php if ($this->_vars['notes_team'][$this->_vars['key']] > 0): ?>
							<?php echo $this->_vars['l_sn_yes']; ?>
						<?php else: ?>
							<?php echo $this->_vars['l_sn_no']; ?>
						<?php endif; ?>
					&nbsp;</font></TD>";
				<?php endif; ?>
				<?php if ($this->_vars['note_player_id'][$this->_vars['key']] == $this->_vars['player_id'] || $this->_vars['player_id'] == $this->_vars['team_note']): ?>
					<TD ALIGN="CENTER"><font size="2">&nbsp;<INPUT TYPE=CHECKBOX NAME=Del[] VALUE="<?php echo $this->_vars['notelistid'][$this->_vars['key']]; ?>">&nbsp;</font></TD>
				<?php else: ?>
					<TD ALIGN="CENTER"><font size="2">&nbsp;<INPUT TYPE=CHECKBOX NAME=Del[] VALUE="<?php echo $this->_vars['notelistid'][$this->_vars['key']]; ?>" disabled>&nbsp;</font></TD>
				<?php endif; ?>
			</TR>
			<?php if ($this->_vars['color'] == $this->_vars['color_line1']): ?>
				<?php $this->assign('color', $this->_vars['color_line2']); ?>
			<?php else: ?>
				<?php $this->assign('color', $this->_vars['color_line1']); ?>
			<?php endif; ?>
		<?php endforeach; endif; ?>
		<tr bgcolor="<?php echo $this->_vars['color']; ?>">
			<td colspan="9">&nbsp;</td>
				<?php if ($this->_vars['team_note'] > 0): ?>
					<TD ALIGN="CENTER">&nbsp;</TD>
				<?php endif; ?>

				<td align="center"><INPUT TYPE="SUBMIT" VALUE="<?php echo $this->_vars['l_sn_delete']; ?>"></td>
			</tr>
		</TABLE>
	<?php endif; ?>
	</form>
<?php if ($this->_vars['ajax'] != 1): ?>
	<tr>
		<td colspan="10"><BR><?php echo $this->_vars['l_lrs_click']; ?><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td>
	</tr>
<?php endif; ?>
</table>
