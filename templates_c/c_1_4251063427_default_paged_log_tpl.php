<h1><?php echo $this->_vars['title']; ?></h1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
	<tr>
		<td bgcolor="#000000" valign="top" align="center" colspan=2>
			<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
				<tr>
					<td align="center">
						<font size=4 color=#52ACEA><b>&nbsp;&nbsp;&nbsp;<?php echo $this->_vars['logline']; ?></b></font><br><br><br>
					</td>
				</tr>
				<TR>
					<TD>
						<center>
						<table width=100% border=0 cellspacing=0 cellpadding=0>
							<tr>
								<td align="left">
									<a href=log.php?loglist=<?php echo $this->_vars['loglist']; ?>&startdate=<?php echo $this->_vars['backlink']; ?>><font color=white size =3><b>«« <?php echo $this->_vars['backdate']; ?></b></font></a>
								</td>
								<td align="center">
								<?php if ($this->_vars['isadmin']): ?>
									<FORM action=admin.php method=POST>
									<input type=hidden name=md5admin_password value="<?php echo $this->_vars['md5admin_password']; ?>">
									<input type=hidden name=menu value="<?php echo $this->_vars['menu']; ?>">
									<input type=hidden name=dead_player value="<?php echo $this->_vars['dead_player']; ?>">
									<input type=submit value="Return to Admin">
									</form>
								<?php else: ?>
									<font size=2 face=arial><?php echo $this->_vars['l_log_click']; ?></font>
								<?php endif; ?>
								</td>
								<td align="right">
									<a href=log.php?loglist=<?php echo $this->_vars['loglist']; ?>&startdate=<?php echo $this->_vars['nextlink']; ?>><font color=white size=3><b><?php echo $this->_vars['nextdate']; ?> »»</b></font></a>
								</td>
							</tr>
						</table>
						<table width=100% border=0 cellspacing=0 cellpadding=0>
						<?php if (! $this->_vars['isadmin']): ?>
							<tr>
								<td>
									<table width=300 border=0 cellspacing=0 cellpadding=0 align=center>
										<tr>
											<td align=center>
												<font color=cyan size =2><b><?php echo $this->_vars['l_log_select']; ?></b></font><br><br>
												<a href=log.php?loglist=&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size =2><b><?php echo $this->_vars['l_log_general']; ?></b></font></a> - 
												<a href=log.php?loglist=1&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_dig']; ?></b></font></a><br>
												<a href=log.php?loglist=2&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_spy']; ?></b></font></a> - 
												<a href=log.php?loglist=3&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_disaster']; ?></b></font></a><br>
												<a href=log.php?loglist=4&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_nova']; ?></b></font></a> - 
												<a href=log.php?loglist=5&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_attack']; ?></b></font></a><br>
												<a href=log.php?loglist=6&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_scan']; ?></b></font></a> - 
												<a href=log.php?loglist=7&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_starv']; ?></b></font></a><br>
												<a href=log.php?loglist=9&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_probe']; ?></b></font></a> - 
												<a href=log.php?loglist=8&startdate=<?php echo $this->_vars['startdate']; ?>><font color=white size=2><b><?php echo $this->_vars['l_log_combined']; ?></b></font></a><br>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						<?php endif; ?>
							<tr>
								<td>
									<table border=0 width=100%>
										<tr>
											<td>
												<center>
												<br>
												<font size=2 color=#DEDEEF><b><?php echo $this->_vars['l_log_start']; ?> <?php echo $this->_vars['entry']; ?><br><br><?php echo $this->_vars['logtype']; ?><b></font>
												<hr width=80% size=1 NOSHADE style="color: #52ACEA">
												</center>
<?php extract($this->_vars, EXTR_REFS);  
for($i = 0; $i < $logcount; $i++)
{
	echo "<table border=0 cellspacing=5 width=100%>" .
		 "<tr>" .
		 "<td><font size=2 color=#52ACEA><b>$logtitle[$i]</b></td>" .
		 "<td align=right><font size=2 color=#52ACEA><b>$logtime[$i]</b></td>" .
		 "</tr><tr><td colspan=2>" .
		 "<font size=2 color=#DEDEEF>" .
		 "$logbody[$i]" .
		 "</td></tr>" .
		 "</table>" .
		 "<center><hr width=80% size=1 NOSHADE style=\"color: #52ACEA\"></center>";
}
 ?>
												<center>
												<br>
												<font size=2 color=#DEDEEF><b><?php echo $this->_vars['l_log_end']; ?> <?php echo $this->_vars['endentry']; ?><b></font>
												</center>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
						<table width=100% border=0 cellspacing=0 cellpadding=0>
							<tr>
								<td align="left">
									<a href=log.php?loglist=<?php echo $this->_vars['loglist']; ?>&startdate=<?php echo $this->_vars['backlink']; ?>><font color=white size =3><b>«« <?php echo $this->_vars['backdate']; ?></b></font></a>
								</td>
								<td align="center">
									<br><br>
								<?php if ($this->_vars['isadmin']): ?>
									<FORM action=admin.php method=POST>
									<input type=hidden name=md5admin_password value="<?php echo $this->_vars['md5admin_password']; ?>">
									<input type=hidden name=menu value="<?php echo $this->_vars['menu']; ?>">
									<input type=hidden name=dead_player value="<?php echo $this->_vars['dead_player']; ?>">
									<input type=submit value="Return to Admin">
									</form>
								<?php else: ?>
									<font size=2 face=arial><?php echo $this->_vars['l_log_click']; ?></font>
								<?php endif; ?>
								</td>
								<td align="right">
									<a href=log.php?loglist=<?php echo $this->_vars['loglist']; ?>&startdate=<?php echo $this->_vars['nextlink']; ?>><font color=white size=3><b><?php echo $this->_vars['nextdate']; ?> »»</b></font></a>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</td>
	</tr>
</table>
 