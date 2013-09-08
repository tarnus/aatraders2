<H1><?php echo $this->_vars['title']; ?></H1>
<?php echo '
<STYLE TYPE="text/css">
<!--
	input.term {background-color: #000000; color: #52ACEA; font-family:Courier New; font-size:10pt; border-color:#52ACEA;}
	select.term {background-color: #000000; color: #52ACEA; font-family:Courier New; font-size:10pt; border-color:#52ACEA;}

-->
</STYLE>
'; ?>

<center>
<table width=604 height=354 border=1>
<tr><td align=center bgcolor="#000000">
<table width=520 height=300 border=0>

  <?php if ($this->_vars['igb_svalue']): ?>
	<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_shiptransfer']; ?><br>---------------------------------</td></tr>
	<tr valign=top><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_igbaccount']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['accountbalance']; ?> C</td></tr>

	<?php if ($this->_vars['igb_svalue'] == 0): ?>
	  <tr valign=top><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_maxtransfer']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_unlimited']; ?></td></tr>
	<?php else: ?>
	  <tr valign=top><td nowrap><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_maxtransferpercent']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['maxtrans']; ?> C</td></tr>
	<?php endif; ?>

	<tr valign=top><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_recipient']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['targetname']; ?>&nbsp;&nbsp;</td></tr>
	<form action=igb.php?command=transfer3 method=POST>
	<tr valign=top>
	<td><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_seltransferamount']; ?> :</td>
	<td align=right><br><input class=term type=text size=15 maxlength=20 name=amount value=0><br>
	<br><input class=term type=submit value=<?php echo $this->_vars['l_igb_transfer']; ?>></td>
	<input type=hidden name=player_id value=<?php echo $this->_vars['player_id']; ?>>
	</form>
	<tr><td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA>
	<?php echo $this->_vars['l_igb_transferrate']; ?>
	<tr valign=bottom>
	<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php?command=transfer><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
	</tr>
  <?php else: ?>
	<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_planettransfer']; ?><br>---------------------------------</td></tr>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_srcplanet']; ?> <?php echo $this->_vars['sourcename']; ?> <?php echo $this->_vars['l_igb_in']; ?> <?php echo $this->_vars['sourcesector']; ?> :
	<td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['sourcecredits']; ?> C
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_destplanet']; ?> <?php echo $this->_vars['destname']; ?> <?php echo $this->_vars['l_igb_in']; ?> <?php echo $this->_vars['destsector']; ?> :
	<td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['destcredits']; ?> C
	<form action=igb.php?command=transfer3 method=POST>
	<tr valign=top>
	<td><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_seltransferamount']; ?> :</td>
	<td align=right><br><input class=term type=text size=15 maxlength=20 name=amount value=0><br>
	<br><input class=term type=submit value=<?php echo $this->_vars['l_igb_transfer']; ?>></td>
	<input type=hidden name=splanet_id value=<?php echo $this->_vars['splanet_id']; ?>>
	<input type=hidden name=dplanet_id value=<?php echo $this->_vars['dplanet_id']; ?>>
	</form>
	<tr><td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA>
	<?php echo $this->_vars['l_igb_transferrate2']; ?><br><br><?php echo $this->_vars['l_igb_maxtransfer']; ?>: <?php echo $this->_vars['transfercredits']; ?> C
	<tr valign=bottom>
	<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php?command=transfer><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
	</tr>
  <?php endif; ?>

</table>
</td></tr>
</table>

</center>
