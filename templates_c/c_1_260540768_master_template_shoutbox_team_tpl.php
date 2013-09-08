<?php require_once('/home/aatrader/public_html/aatrade_beta/backends/template_lite/src/plugins/function.math.php'); $this->register_function("math", "tpl_function_math"); ?><table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
<TR BGCOLOR='#585980'>
<TH COLSPAN=2 NOWRAP><FONT COLOR=yellow><?php echo $this->_vars['l_shout_teamtitle']; ?></FONT></TH>
</TR>
  <tr>
    <td bgcolor="#000000" valign="top" align="center">
<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="shoutbox_team.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="shoutbox_team.php?page=<?php echo $this->_vars['previouspage']; ?>"><?php echo $this->_vars['l_shout_prev']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
		<TD align='center' width="33%">
	<?php echo tpl_function_math(array('equation' => "x + y",'x' => 1,'y' => $this->_vars['totalpages'],'assign' => "forpages"), $this);?>
	<?php echo $this->_vars['l_shout_selectpage']; ?> <select name="page">
	<?php for($for1 = 1; ((1 < $this->_vars['forpages']) ? ($for1 < $this->_vars['forpages']) : ($for1 > $this->_vars['forpages'])); $for1 += ((1 < $this->_vars['forpages']) ? 1 : -1)):  $this->assign('i', $for1); ?>
		<option value="<?php echo $this->_vars['i']; ?>"
		<?php if ($this->_vars['currentpage'] == $this->_vars['i']): ?>
			selected
		<?php endif; ?>
		> <?php echo $this->_vars['l_shout_page']; ?> <?php echo $this->_vars['i']; ?> </option>
	<?php endfor; ?>
	</select>
	&nbsp;<input type="submit" value="<?php echo $this->_vars['l_submit']; ?>">
	</TD>
		<td align="right" width="33%">
			<?php if ($this->_vars['currentpage'] != $this->_vars['totalpages']): ?>
				<a href="shoutbox_team.php?page=<?php echo $this->_vars['nextpage']; ?>"><?php echo $this->_vars['l_shout_next']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
	</tr>
	</form>
	</table>
<?php endif; ?>

<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<TR><TD COLSPAN=2 NOWRAP ALIGN=CENTER>
<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=2 width=100%>
	<?php extract($this->_vars, EXTR_REFS);  
	for ( $i = 0 ; $i < count($playernamea) ; $i++ )
	{
		echo "<tr> 
				<td rowspan=2 align=center valign=middle width=64 height=64><img src='images/$publicavatar[$i]'></td>
				<td ALIGN=LEFT width='50%'><FONT SIZE=-1><B>$playernamea[$i]</B></FONT></td>
				<td ALIGN=RIGHT width='50%'><FONT SIZE=-1><I>$datea[$i]</I></FONT></td>
			  </tr>
			  <tr> 
				<td colspan=2 ALIGN=LEFT width='100%'>$messagea[$i]</td>
			  </tr>";
		echo "<TR>";
		echo "<TD COLSPAN=3 ><IMG height=1 width=1 SRC='images/spacer.gif'><hr></TD>";
		echo "</TR>";
	}
	 ?>

</TABLE>
</TD></TR>

<TR BGCOLOR='#23244F'><TD COLSPAN=2 NOWRAP ALIGN=CENTER>
<FORM NAME='sb' ACTION='shoutbox_save.php'>
<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=2 width=100%>
<TR BGCOLOR='#3A3B6E'>
<TD NOWRAP ALIGN=LEFT>
<INPUT TYPE=TEXT NAME='sbt' Value='' MAXLENGTH=200></TD>
<TD NOWRAP ALIGN=RIGHT></TD>
</TR>
<TR BGCOLOR='#3A3B6E'>
<TD NOWRAP ALIGN=LEFT><INPUT TYPE=SUBMIT VALUE='SHOUT'>&nbsp;&nbsp;<A HREF='shoutbox_smilie.php?template=<?php echo $this->_vars['template']; ?>'><?php echo $this->_vars['l_shout_smiles']; ?></A></TD>
<TD NOWRAP ALIGN=RIGHT><INPUT TYPE=RESET VALUE='CLEAR'></TD>
</TR>
</TABLE>
</FORM>
</TD></TR>
<tr><td align="center"><a href="shoutbox_team.php"><?php echo $this->_vars['l_shout_refresh']; ?></a>&nbsp;&nbsp;&nbsp;<a href="javascript:window.close();"><?php echo $this->_vars['l_shout_close']; ?></a>
</td></tr>
		</table>
	</td>
  </tr>
</table>
