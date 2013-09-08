<H1><?php echo $this->_vars['title']; ?></H1>

<table border="1" cellspacing="0" cellpadding="4" align="center" width="500">
	<tr>
		<td colspan=4>
			<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
				<tr>
					<td>	
						<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
							<tr bgcolor="black">
								<td valign="top" width=18><img src = "templates/master_template/images/spacer.gif" height="160" width="18"></TD>
								<td valign="top">
									<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<?php if ($this->_vars['notteamlimit']): ?>
	<?php if ($this->_vars['invited']): ?>
		<FORM ACTION='teams.php' METHOD=POST>
		<TABLE><INPUT TYPE=hidden name=command value=<?php echo $this->_vars['command']; ?>>
		<INPUT TYPE=hidden name=invited value=1>
		<INPUT TYPE=hidden name=team_id value=<?php echo $this->_vars['team_id']; ?>>
		<TR><TD><?php echo $this->_vars['l_team_selectp']; ?>:</TD><TD>
		<SELECT NAME=who>
		<?php extract($this->_vars, EXTR_REFS);  
		for($i = 0; $i < $count; $i++){
			echo "<OPTION VALUE=$playerid[$i]>$playername[$i]</option>";
		}
		 ?>
		</SELECT></TD></TR>
		<TR><TD><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_submit']; ?>></TD></TR>
		</TABLE>
		</FORM>
	<?php else: ?>
		<?php if ($this->_vars['team_join_count'] < $this->_vars['max_team_changes']): ?>
			<?php if ($this->_vars['issameteam']): ?>
				<?php if ($this->_vars['team_invite']): ?>
					<?php echo $this->_vars['l_team_isorry']; ?><BR><BR>
				<?php else: ?>
					<?php echo $this->_vars['l_team_plinvted']; ?><BR>
				<?php endif; ?>
			<?php else: ?>
				<?php echo $this->_vars['l_team_notyours']; ?><BR>
			<?php endif; ?>
		<?php else: ?>
			<?php echo $this->_vars['l_team_cantinvite']; ?>
		<?php endif; ?>
	<?php endif; ?>
<?php else: ?>
	<?php echo $this->_vars['l_team_full']; ?><BR>
<?php endif; ?>
</td></tr>
<tr><td><BR><a href="teams.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_team_menu']; ?>.<BR></td></tr>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td valign="top" width=18><img src = "templates/master_template/images/spacer.gif" height="160" width="18"></TD>
				</tr>
			</table>
		</td>
	</tr>
</table>

