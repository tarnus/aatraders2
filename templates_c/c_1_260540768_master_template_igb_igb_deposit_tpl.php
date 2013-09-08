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

<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_depositfunds']; ?><br>---------------------------------</td></tr>
<tr valign=top>
<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_accountholder']; ?> :<br><br><?php echo $this->_vars['l_igb_shipaccount']; ?> :<br><?php echo $this->_vars['l_igb_igbaccount']; ?>&nbsp;&nbsp;:</td>
<td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['playername']; ?>&nbsp;&nbsp;<br><br><?php echo $this->_vars['playercredits']; ?> <?php echo $this->_vars['l_igb_credit_symbol']; ?><br><?php echo $this->_vars['accountbalance']; ?> <?php echo $this->_vars['l_igb_credit_symbol']; ?><br></td>
</tr>
<tr valign=top>
<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_seldepositamount']; ?> :</td><td align=right>
<form action=igb.php?command=deposit2 method=POST>
<input class=term type=text size=15 maxlength=20 name=amount value=0>
<br><br><input class=term type=submit value=<?php echo $this->_vars['l_igb_deposit']; ?>>
</form></td></tr>
<?php if ($this->_vars['max_igb_storage'] > 0): ?>
	<tr><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_maximum']; ?> <?php echo $this->_vars['l_igb_igbaccount']; ?> <?php echo $this->_vars['l_credits']; ?>: </font><font size=2 face="courier new" color=#ffFF00><?php echo $this->_vars['max_igb_storage']; ?></font><td><tr>
<?php endif; ?>
<tr valign=bottom>
<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
</tr>

</table>
</td></tr>
</table>

</center>
