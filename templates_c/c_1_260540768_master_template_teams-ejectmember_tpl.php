<H1><?php echo $this->_vars['title']; ?></H1>


<table border="1" cellspacing="0" cellpadding="4" align="center" width="500">
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
<?php if ($this->_vars['isplayerteam']): ?>
	<?php if (! $this->_vars['confirmed']): ?>
		<?php echo $this->_vars['l_team_ejectsure']; ?> <?php echo $this->_vars['playername']; ?>? <A HREF="teams.php?command=<?php echo $this->_vars['command']; ?>&confirmed=1&who=<?php echo $this->_vars['who']; ?>"><?php echo $this->_vars['l_yes']; ?></A> - <a href="teams.php"><?php echo $this->_vars['l_no']; ?></a><BR>
	<?php else: ?>
		<?php echo $this->_vars['playername']; ?> <?php echo $this->_vars['l_team_ejected']; ?><BR>
	<?php endif; ?>
<?php else: ?>
	<?php echo $this->_vars['l_team_cheater']; ?> <BR><BR><?php echo $this->_vars['l_team_punishment']; ?>:<BR><BR>
	<?php echo $this->_vars['l_die_vapor']; ?><BR><BR>
	<?php echo $this->_vars['l_die_please']; ?>.<BR>
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
