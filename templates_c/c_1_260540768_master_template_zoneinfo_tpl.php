<h1><?php echo $this->_vars['title']; ?></h1>
<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr><td>
<?php if ($this->_vars['zoneowner'] != -1): ?>

<table border=0 cellspacing=0 cellpadding=2 width="100%" align=center><tr><td>
	<center><?php echo $this->_vars['l_zi_control']; ?>. <a href="zoneedit.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_zi_tochange']; ?></center>
<br>
</td></tr>
</table>
<?php endif; ?>

<tr"><td align=center colspan=2 class="nav_title_16b"><font color="#00ff00"><?php echo $this->_vars['zone_name']; ?></font><br><br></td></tr>
<tr><td colspan=2>
<table border=0 cellspacing=0 cellpadding=2 width="100%" align=center>
<tr bgcolor="#000000"><td width="50%" class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_zi_owner']; ?></td><td width="50%" class="nav_title_14b"><font color="yellow"><?php echo $this->_vars['ownername']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_beacons']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['beacon']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_att_att']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['attack']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_md_title']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['defense']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_warpedit']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['warpedit']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_planets']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['planet']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_title_port']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['trade']; ?></font>&nbsp;</td></tr>
<tr bgcolor="#000000"><td class="nav_title_14b">&nbsp;<?php echo $this->_vars['l_zi_maxhull']; ?></td><td class="nav_title_14b"><font color="cyan"><?php echo $this->_vars['hull']; ?></font>&nbsp;</td></tr>
			
</table>
				</td>
			</tr>

<tr><td align="center"><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
