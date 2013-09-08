<H1><?php echo $this->_vars['title']; ?></H1>


<table border="1" cellspacing="0" cellpadding="4" align="center" width="600">
	<tr>
		<td colspan=4>
			<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
				<tr>
					<td>	
						<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
							<tr bgcolor="black">
								<td valign="top" width=18><img src = "templates/master_template/images/spacer.gif" height="200" width="18"></TD>
								<td valign="top">
									<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<?php if ($this->_vars['team_join_count'] < $this->_vars['max_team_changes']): ?>
	<?php if ($this->_vars['playerteam'] == 0): ?>
		<?php if ($this->_vars['isteamname']): ?>
			<FORM ACTION="teams.php" METHOD=POST>
	 		<?php echo $this->_vars['l_team_entername']; ?>: 
			<INPUT TYPE=hidden name=command value=<?php echo $this->_vars['command']; ?>>
			<INPUT TYPE=TEXT NAME=teamname SIZE=40 MAXLENGTH=40><BR>
			<?php echo $this->_vars['l_team_enterdesc']; ?>: 
	 		<INPUT TYPE=TEXT NAME=teamdesc SIZE=40 MAXLENGTH=254><BR>
		  	<INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_submit']; ?>><INPUT TYPE=RESET VALUE=<?php echo $this->_vars['l_reset']; ?>>
			</FORM>
			<BR><BR>
	 	<?php else: ?>
			<?php if ($this->_vars['count'] == 0): ?>
				<?php echo $this->_vars['l_team']; ?> <B><?php echo $this->_vars['teamname']; ?></B> <?php echo $this->_vars['l_team_hcreated']; ?>.<BR><BR>
			<?php else: ?>
				<?php echo $this->_vars['l_team_nocreatesamename']; ?><br>
			<?php endif; ?>
		<?php endif; ?>
	<?php else: ?>
		<br><?php echo $this->_vars['l_team_leavefirst']; ?><br><br>
	<?php endif; ?>
<?php else: ?>
	<?php echo $this->_vars['l_team_cantcreate']; ?>
<?php endif; ?>
</td></tr>
<tr><td><BR><a href="teams.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_team_menu']; ?>.<BR></td></tr>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td valign="top" width=18><img src = "templates/master_template/images/spacer.gif" height="200" width="18"></TD>
				</tr>
			</table>
		</td>
	</tr>
</table>