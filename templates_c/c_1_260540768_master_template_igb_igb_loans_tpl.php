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

<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_loanstatus']; ?><br>---------------------------------</td></tr>
<tr valign=top><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_shipaccount']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['playercredits']; ?> C</td></tr>
<tr valign=top><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_currentloan']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['accountloan']; ?> C</td></tr>

<?php if ($this->_vars['accountloan'] != 0): ?>
	<tr valign=top><td nowrap><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_loantimeleft']; ?> :</td>

	<?php if ($this->_vars['isloanlate']): ?>
	  <td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_loanlate']; ?></td>
	<?php else: ?>
	  echo "<td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['hours']; ?>h <?php echo $this->_vars['mins']; ?>m</td>
	<?php endif; ?>
	</tr>
	<form action=igb.php?command=repay method=POST>
	<tr valign=top>
	<td><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_repayamount']; ?> :</td>
	<td align=right><br><input class=term type=text size=15 maxlength=20 name=amount value='<?php echo $this->_vars['amount']; ?>'><br>
	<br><input class=term type=submit value=<?php echo $this->_vars['l_igb_repay']; ?>></td></tr>
	</form>
	<tr><td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA>
	<?php echo $this->_vars['l_igb_loanrates']; ?></td></tr>
<?php else: ?>
	<tr valign=top><td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_maxloanpercent']; ?> :</td><td align=right><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['maxloan']; ?> C</td></tr>

	<?php if ($this->_vars['iscollateral']): ?>
		<form action=igb.php?command=borrow method=POST>
		<tr valign=top>
		<td><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_loanamount']; ?> :</td>
		<td align=right><br><input class=term type=text size=15 maxlength=20 name=amount value=0><br>
		<br><input class=term type=submit value=<?php echo $this->_vars['l_igb_borrow']; ?>></td>
		</form>
		<tr><td colspan=2 align=center><font size=2 face="courier new" color=#52ACEA>
		<?php echo $this->_vars['l_igb_loanrates'];  echo $this->_vars['l_igb_loanrepaytime']; ?>
	<?php else: ?>
		<tr valign=top>
		<td colspan=2 align=center><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_nocollateral']; ?></font></td>
	<?php endif; ?>
<?php endif; ?>

<tr valign=bottom>
<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
</tr>

</table>
</td></tr>
</table>

</center>
