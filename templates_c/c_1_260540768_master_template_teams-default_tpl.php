<H1><?php echo $this->_vars['title']; ?></H1>

<?php if ($this->_vars['playerteamid'] == 0): ?>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<?php echo $this->_vars['l_team_notmember']; ?>
	<?php if (! $this->_vars['teaminvite']): ?>
		<br><br><font color=blue size=2><b><?php echo $this->_vars['l_team_noinvite']; ?></b></font><BR><br>
		<?php if ($this->_vars['playerteamid'] == 0): ?>
			<?php echo $this->_vars['l_team_ifyouwant']; ?><BR>
			<a href="teams.php?command=6"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_team_tocreate']; ?><BR><BR>
		<?php endif; ?>
	<?php else: ?>
		<br><br><font color=blue size=2><b><?php echo $this->_vars['l_team_injoin']; ?> 
		<a href=teams.php?command=1&team_id=<?php echo $this->_vars['teaminvite']; ?>><?php echo $this->_vars['inviteinfo']; ?></A>.</b></font><BR>
		<A HREF=teams.php?command=3&team_id=<?php echo $this->_vars['teaminvite']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_team_tojoin']; ?> <B><?php echo $this->_vars['inviteinfo']; ?></B> <?php echo $this->_vars['l_team_or']; ?> <A HREF=teams.php?command=8&team_id=<?php echo $this->_vars['teaminvite']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_team_reject']; ?><BR><BR>
	<?php endif; ?>
</td><tr>
		</table>
	</td>
  </tr>
</table>
<?php else: ?>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<div align=center>
	<img src="images/icons/<?php echo $this->_vars['teamicon']; ?>"><br>
	<h3><font color=white><B><?php echo $this->_vars['teamname']; ?></B>
	<br><font size=2>"<i><?php echo $this->_vars['teamdescription']; ?></i>"</font></H3>
	
	<?php if ($this->_vars['playerteammatch']): ?>
		<font color=white>
		<?php if ($this->_vars['isplayercreator']): ?>
			<?php echo $this->_vars['l_team_coord']; ?>&nbsp;
		<?php else: ?>
			<?php echo $this->_vars['l_team_member']; ?>&nbsp;
		<?php endif; ?>
		<?php echo $this->_vars['l_options']; ?><br><font size=2>
		<?php if ($this->_vars['playerteammatch']): ?>
			[<a href='teams.php?command=9&team_id=<?php echo $this->_vars['playerteamid']; ?>'><?php echo $this->_vars['l_team_ed']; ?></a>] - 
		<?php endif; ?>
		[<a href=teams.php?command=7&team_id=<?php echo $this->_vars['playerteamid']; ?>><?php echo $this->_vars['l_team_inv']; ?></a>] - [<a href=teams.php?command=4&team_id=<?php echo $this->_vars['playerteamid']; ?>><?php echo $this->_vars['l_team_cancelinv']; ?></a>] - [<a href=teams.php?command=2&team_id=<?php echo $this->_vars['playerteamid']; ?>><?php echo $this->_vars['l_team_leave']; ?></a>]</font></font>
	<?php endif; ?>
	<?php if ($this->_vars['teaminvite'] == 0): ?>
		<br><br><font color=blue size=2><b><?php echo $this->_vars['l_team_noinvite']; ?></b></font><BR><br>
		<?php if ($this->_vars['playerteamid'] == 0): ?>
			<?php echo $this->_vars['l_team_ifyouwant']; ?><BR>
	 		<a href="teams.php?command=6"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_team_tocreate']; ?><BR><BR>
		<?php endif; ?>
	<?php else: ?>
		<br><br><font color=blue size=2><b><?php echo $this->_vars['l_team_injoin']; ?> 
		<a href=teams.php?command=1&team_id=<?php echo $this->_vars['teaminvite']; ?>><?php echo $this->_vars['inviteinfo']; ?></A>.</b></font><BR>
		<A HREF=teams.php?command=3&team_id=<?php echo $this->_vars['teaminvite']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_team_tojoin']; ?> <B><?php echo $this->_vars['inviteinfo']; ?></B> <?php echo $this->_vars['l_team_or']; ?> <A HREF=teams.php?command=8&team_id=<?php echo $this->_vars['teaminvite']; ?>><?php echo $this->_vars['l_clickme']; ?></A> <?php echo $this->_vars['l_team_reject']; ?><BR><BR>
	<?php endif; ?>

	</div>
	</td></tr>
		</table>
	</td>
  </tr>
</table>
<br>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr>
	<td><font color=white><?php echo $this->_vars['l_team_members']; ?></font></td>
	</tr>
	<tr bgcolor=<?php echo $this->_vars['zonecolor']; ?>>
	<td bgcolor=<?php echo $this->_vars['zonecolor']; ?>>&nbsp;</td>
	</tr><tr>
	<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i<$teamcount; $i++) {
		echo "<td> - $teammember[$i] ($l_score $memberscore[$i]])";
		if ($memberowner[$i]) {
			echo " - <font size=2>[<a href=\"teams.php?command=5&who=$memberid[$i]\">$l_team_eject</A>]</font></td>";
		} else {
			if ($iscreator[$i])
			{
				echo " - $l_team_coord</td>";
			}
		}
		echo "</tr><tr>";
	}
	 ?>
	<td}><font color=white><?php echo $this->_vars['l_team_pending']; ?> <B><?php echo $this->_vars['teamname']; ?></B></font></td>
	</tr><tr>
	<?php if ($this->_vars['membercount'] != 0): ?>
		</tr><tr>
	<?php extract($this->_vars, EXTR_REFS);  
		for($i = 0; $i<$membercount; $i++) {
			echo "<td> - $membername[$i]</td>";
			echo "</tr><tr>";
		}
	 ?>
	<?php else: ?>
		<td><?php echo $this->_vars['l_team_noinvites']; ?> <B><?php echo $this->_vars['teamname']; ?></B>.</td>
		</tr><tr>
	<?php endif; ?>
	</tr>
		</table>
	</td>
  </tr>
</table>
	
<?php endif; ?>

<?php if ($this->_vars['teams_count'] > 0): ?>
<br>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<TR BGCOLOR="#000000">
<TD colspan=4><font size="2" color=white>
<?php echo $this->_vars['l_team_galax']; ?><BR><BR></font></td></tr>
	<tr>
	<TD><B><A HREF=teams.php?order=team_name&type=<?php echo $this->_vars['type']; ?>><?php echo $this->_vars['l_name']; ?></A></B></TD>
	<TD><B>&nbsp;<A HREF=teams.php?order=number_of_members&type=<?php echo $this->_vars['type']; ?>><?php echo $this->_vars['l_team_members']; ?></A></B></TD>
	<TD><B>&nbsp;<A HREF=teams.php?order=character_name&type=<?php echo $this->_vars['type']; ?>><?php echo $this->_vars['l_team_coord']; ?></A></B></TD>
	<TD><B>&nbsp;<A HREF=teams.php?order=total_score&type=<?php echo $this->_vars['type']; ?>><?php echo $this->_vars['l_score']; ?></A></B></TD>
	</TR>
	<?php extract($this->_vars, EXTR_REFS);  
	$color = "#000000";
	for($i = 0; $i < $totalteamcount; $i++) {
		echo "<TR BGCOLOR=\"$color\">";
		echo "<TD><img src=\"images/icons/$teamlisticon[$i]\" width=16 height=16><a href=teams.php?command=1&team_id=".$teamlistid[$i].">".$teamlistname[$i]."</A></TD>";
		echo "<TD>&nbsp;".$teamlistnumber[$i]."</TD>";
		echo "<TD>&nbsp;<a href=message_send.php?name=".$teamlistcname[$i].">".$teamlistcname[$i]."</A></TD>";
		echo "<TD>&nbsp;" . $teamlistscore[$i] . "</TD>";
		echo "</TR>";
		if ($color == "#000000")
		{
			$color = "#000000";
		}
		else
		{
			$color = "#000000";
		}
	}
	 ?>
			<tr>
		</table>
	</td>
  </tr>
</table>
<BR>
<?php else: ?>
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
	<?php echo $this->_vars['l_team_noteams']; ?>
</td></tr>
		</table>
	</td>
  </tr>
</table>
<?php endif; ?>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<?php if ($this->_vars['team_join_count'] < $this->_vars['max_team_changes']): ?>
	<?php echo $this->_vars['l_team_allowedfront']; ?> 
	<?php extract($this->_vars, EXTR_REFS);  
		echo $max_team_changes - $team_join_count;
	 ?>
	<?php echo $this->_vars['l_team_allowedback']; ?><br><br>
<?php else: ?>
	<?php echo $this->_vars['l_team_reachedlimit']; ?><br><br>
<?php endif; ?>
</td></tr>

<tr><td><BR><a href="teams.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_team_menu']; ?>.<BR></td></tr>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
