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
<?php if ($this->_vars['confirmleave'] == 0): ?>
	<?php echo $this->_vars['l_team_confirmleave']; ?> <B><?php echo $this->_vars['teamname']; ?></B>? <a href="teams.php?command=<?php echo $this->_vars['command']; ?>&confirmleave=1&team_id=<?php echo $this->_vars['team_id']; ?>"><?php echo $this->_vars['l_yes']; ?></a> - <A HREF="teams.php"><?php echo $this->_vars['l_no']; ?></A><BR><BR>
<?php else: ?>
	<?php if ($this->_vars['confirmleave'] == 1): ?>
		<?php if ($this->_vars['number_of_members'] == 1): ?>
			<?php echo $this->_vars['l_team_onlymember']; ?><BR><BR>
		<?php else: ?>
			<?php if ($this->_vars['iscreator']): ?>
				<?php echo $this->_vars['l_team_youarecoord']; ?> <B><?php echo $this->_vars['teamname']; ?></B>. <?php echo $this->_vars['l_team_relinq']; ?><BR><BR>
	 			<FORM ACTION='teams.php' METHOD=POST>
		  		<TABLE><INPUT TYPE=hidden name=command value=<?php echo $this->_vars['command']; ?>>
				<INPUT TYPE=hidden name=confirmleave value=2>
				<INPUT TYPE=hidden name=team_id value=<?php echo $this->_vars['team_id']; ?>>
				<TR><TD><?php echo $this->_vars['l_team_newc']; ?></TD><TD><SELECT NAME=newcreator>
				<?php extract($this->_vars, EXTR_REFS);  
				for($i = 0; $i<$count; $i++){
					echo "<OPTION VALUE=$playerid[$i]>$playername[$i]</option>\n";
	 			}
				 ?>
		  		</SELECT></TD></TR>
				<TR><TD><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_submit']; ?>></TD></TR>
				</TABLE>
				</FORM>
			<?php else: ?>
				<?php echo $this->_vars['l_team_youveleft']; ?> <B><?php echo $this->_vars['teamname']; ?></B>.<BR><BR>
			<?php endif; ?>
		<?php endif; ?>
	<?php endif; ?>

	<?php if ($this->_vars['confirmleave'] == 2): ?>
		<?php echo $this->_vars['l_team_youveleft']; ?> <B><?php echo $this->_vars['teamname']; ?></B> <?php echo $this->_vars['l_team_relto']; ?> <?php echo $this->_vars['newcreator']; ?>.<BR><BR>
	<?php endif; ?>
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

