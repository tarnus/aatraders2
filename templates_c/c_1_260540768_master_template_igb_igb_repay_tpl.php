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

<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_payloan']; ?><br>---------------------------------</td></tr>
<tr valign=top>
<td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_loanthanks']; ?></td>
<tr valign=top>
<td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA>---------------------------------</td>
<tr valign=top>
<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_shipaccount']; ?> :</td><td nowrap align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['playercredits']; ?> C<br>
<tr valign=top>
<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_payloan']; ?> :</td><td nowrap align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['amount']; ?> C<br>
<tr valign=top>
<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_currentloan']; ?> :</td><td nowrap align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['accountloan']; ?> C<br>
<tr valign=top>
<td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA>---------------------------------</td>
<tr valign=top>
<td nowrap><font size=2 face="courier new" color=#52ACEA><a href=igb.php><?php echo $this->_vars['l_igb_back']; ?></a></td><td nowrap align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
</tr>

</table>
</td></tr>
</table>

</center>