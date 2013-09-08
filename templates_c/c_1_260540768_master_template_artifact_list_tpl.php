<H1><?php echo $this->_vars['title']; ?></H1>

<table width="90%" border="1" cellspacing="0" cellpadding="4" align="center">
	<tr>
		<td bgcolor="#000000" valign="top" align="center" colspan=2>
			<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
				<tr>
					<td>
						<table border=1 cellspacing=0 cellpadding=5 width="100%" align=center>
							<tr bgcolor="#585980">
								<td align='center'><font color=white><B><?php echo $this->_vars['l_artifact_imagename']; ?></b></font></td>
								<td align='center'><font color=white><B><?php echo $this->_vars['l_artifact_classname']; ?></b></font></td>
								<td align='center'><font color=white><B><?php echo $this->_vars['l_artifact_description']; ?></b></font></td>
								<td align='center'><font color=white><B><?php echo $this->_vars['l_artifact_incomplete']; ?></b></font></td>
							</tr>
							<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['classname']), 'iteration' => 0);
if (count((array)$this->_vars['classname'])): foreach ((array)$this->_vars['classname'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
								<tr bgcolor=#000000>
									<td align='center'><font color="#ffffff"><b><img src="images/artifacts/<?php echo $this->_vars['imagename'][$this->_vars['key']]; ?>.gif" border=0></b></font></td>
									<td align='center'><font color="#ffffff"><b><?php echo $this->_vars['classname'][$this->_vars['key']]; ?></b></font></td>
									<td align='left'><font color="#ffffff"><b><?php echo $this->_vars['description'][$this->_vars['key']]; ?></b></font></td>
									<?php if ($this->_vars['completed'][$this->_vars['key']] == 1 && $this->_vars['delayedprocess'][$this->_vars['key']] == 1): ?>
										<td align='center'><font color="#ffffff"><b><a href="artifact_process.php?artifact=<?php echo $this->_vars['class'][$this->_vars['key']]; ?>"><?php echo $this->_vars['l_artifact_process']; ?></a></b></font></td>
									<?php else: ?>
										<td align='center'><font color="#ffffff"><b><?php echo $this->_vars['incomplete'][$this->_vars['key']]; ?></b></font></td>
									<?php endif; ?>
								</tr>
							<?php endforeach; endif; ?>
						</table>
					</td>
				</tr>
				<tr>
					<td>
						<br><br><?php echo $this->_vars['gotomain']; ?><br><br>
					</td>
				</tr>
			</table>
		</td>
	</tr>
</table>


