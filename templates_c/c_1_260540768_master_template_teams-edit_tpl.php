<H1><?php echo $this->_vars['title']; ?></H1>

<table border="1" cellspacing="0" cellpadding="4" align="center" width="300">
	<tr>
		<td colspan=4>
			<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
				<tr>
					<td>	
						<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
							<tr bgcolor="black">
								<td valign="top" width=18><img src = "templates/master_template/images/spacer.gif" height="220" width="18"></TD>
								<td valign="top">
									<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<?php if ($this->_vars['teammatch']): ?>
	<?php if ($this->_vars['update']): ?>
		<FORM ACTION="teams.php" METHOD=POST>
		<?php echo $this->_vars['l_team_edname']; ?>: <BR>
		<INPUT TYPE=hidden name=command value=<?php echo $this->_vars['command']; ?>>
		<INPUT TYPE=hidden name=team_id value=<?php echo $this->_vars['team_id']; ?>>
		<INPUT TYPE=hidden name=update value=true>
		<INPUT TYPE=TEXT NAME=teamname SIZE=40 MAXLENGTH=40 VALUE="<?php echo $this->_vars['team_name']; ?>"><BR>
		<?php echo $this->_vars['l_team_eddesc']; ?>: <BR>
		<INPUT TYPE=TEXT NAME=teamdesc SIZE=40 MAXLENGTH=254 VALUE="<?php echo $this->_vars['description']; ?>"><BR>
		<INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_submit']; ?>><INPUT TYPE=RESET VALUE=<?php echo $this->_vars['l_reset']; ?>>
		</FORM>
		<BR>
	<?php else: ?>
		<?php if ($this->_vars['count'] == 0): ?>
			<?php echo $this->_vars['l_team']; ?> <B><?php echo $this->_vars['teamname']; ?></B> <?php echo $this->_vars['l_team_hasbeenr']; ?><BR>
		<?php else: ?>
			<?php echo $this->_vars['l_team_noupdatesamename']; ?><br>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
	<?php echo $this->_vars['l_team_error']; ?>
<?php endif; ?>
</td></tr>
<tr><td><BR><a href="teams.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_team_menu']; ?>.</td></tr>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td valign="top" width=18><img src = "templates/master_template/images/spacer.gif" height="220" width="18"></TD>
				</tr>
			</table>
		</td>
	</tr>
</table>

