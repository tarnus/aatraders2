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

  <?php if ($this->_vars['isplayer']): ?>
	<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transfersuccessful']; ?><br>---------------------------------</td></tr>
	<tr valign=top><td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['transfer']; ?> <?php echo $this->_vars['l_igb_creditsto']; ?> <?php echo $this->_vars['targetname']; ?>.</tr>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transferamount']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['amount']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transferfee']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['amount2']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_amounttransferred']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['transfer']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_igbaccount']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['accountbalance']; ?> C<br>
	<tr valign=bottom>
	<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php?command=login><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
	</tr>
  <?php else: ?>
	<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transfersuccessful']; ?><br>---------------------------------</td></tr>
	<tr valign=top><td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['transfer']; ?> <?php echo $this->_vars['l_igb_ctransferredfrom']; ?> <?php echo $this->_vars['sourcename']; ?> <?php echo $this->_vars['l_igb_to']; ?> <?php echo $this->_vars['destname']; ?>.</tr>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transferamount']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['amount']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transferfee']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['amount2']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_amounttransferred']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['transfer']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_srcplanet']; ?> <?php echo $this->_vars['sourcename']; ?> <?php echo $this->_vars['l_igb_in']; ?> <?php echo $this->_vars['sourcesector']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['sourcecredits']; ?> C<br>
	<tr valign=top>
	<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_destplanet']; ?> <?php echo $this->_vars['destname']; ?> <?php echo $this->_vars['l_igb_in']; ?> <?php echo $this->_vars['destsector']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['destcredits']; ?> C<br>
	<tr valign=bottom>
	<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
	</tr>
  <?php endif; ?>

</table>
</td></tr>
</table>

</center>
