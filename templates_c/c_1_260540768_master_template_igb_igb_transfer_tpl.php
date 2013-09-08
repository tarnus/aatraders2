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

<tr><td colspan=2 align=center valign=top><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_transfertype']; ?><br>---------------------------------</td></tr>
<tr valign=top>
<form action=igb.php?command=transfer2 method=POST>
<td><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_toanothership']; ?> :<br><br>
<select class=term name=player_id>

<?php extract($this->_vars, EXTR_REFS);  
  for($i = 0; $i < $shipcount; $i++)
  {
	echo "<option value=$shipid[$i]>$playername[$i]</option>\n";
  }
 ?>

</select></td><td valign=center align=right>
<input class=term type=submit name=shipt value="<?php echo $this->_vars['l_igb_shiptransfer']; ?>">
</form>
</td></tr>
<tr valign=top>
<td><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_fromplanet']; ?> :<br><br>
<form action=igb.php?command=transfer2 method=POST>
<?php echo $this->_vars['l_igb_source']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<select class=term name=splanet_id>

  <?php if ($this->_vars['isplanets']): ?>
  	<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $planetcount; $i++)
	{
	  echo "<option value=$planetid[$i]>$planetname[$i] $l_igb_in $planetsector[$i]</option>\n";
	}
	 ?>
  <?php else: ?>
	 <option value=none><?php echo $this->_vars['l_igb_none']; ?></option>\n
  <?php endif; ?>

  </select><br>
  <?php echo $this->_vars['l_igb_destination']; ?> <select class=term name=dplanet_id>

  <?php if ($this->_vars['isplanets']): ?>
  	<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $planetcount; $i++)
	{
	  echo "<option value=$planetid[$i]>$planetname[$i] $l_igb_in $planetsector[$i]</option>\n";
	}
	 ?>
  <?php else: ?>
	 <option value=none><?php echo $this->_vars['l_igb_none']; ?></option>\n
  <?php endif; ?>

</select></td><td valign=center align=right>
<br><input class=term type=submit name=planett value="<?php echo $this->_vars['l_igb_planettransfer']; ?>">
</td></tr>
</form>

<tr valign=top>
<td><br><font size=2 face="courier new" color=#52ACEA><?php echo $this->_vars['l_igb_conspl']; ?> :<br><br>
<form action=igb.php?command=consolidate method=POST>

</td><td valign=top align=right>
<br><input class=term type=submit name=planetc value="<?php echo $this->_vars['l_igb_consolidate']; ?>">
</td></tr>
</form>

</form><tr valign=bottom>
<td><font size=2 face="courier new" color=#52ACEA><a href=igb.php><?php echo $this->_vars['l_igb_back']; ?></a></td><td align=right><font size=2 face="courier new" color=#52ACEA>&nbsp;<br><a href="main.php"><?php echo $this->_vars['l_igb_logout']; ?></a></td>
</tr>
	   
</table>
</td></tr>
</table>

</center>
