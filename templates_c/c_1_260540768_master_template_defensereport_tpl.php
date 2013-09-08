<?php require_once('/home/aatrader/public_html/aatrade_beta/backends/template_lite/src/plugins/function.math.php'); $this->register_function("math", "tpl_function_math"); ?><h1><?php echo $this->_vars['title']; ?></h1>

<table width="400" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
    	<?php if ($this->_vars['totalpages'] > 1): ?>
	<TABLE border=0 cellpadding=2 cellspacing=1 width="100%">
	<form action="defense_report.php" method="post">
	<TR>
		<td align="left" width="33%">
			<?php if ($this->_vars['currentpage'] != 1): ?>
				<a href="defense_report.php?page=<?php echo $this->_vars['previouspage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_prev']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
		<TD align='center' width="33%">
	<?php echo tpl_function_math(array('equation' => "x + y",'x' => 1,'y' => $this->_vars['totalpages'],'assign' => "forpages"), $this);?>
	<?php echo $this->_vars['l_rpt_selectpage']; ?> <select name="page">
	<?php for($for1 = 1; ((1 < $this->_vars['forpages']) ? ($for1 < $this->_vars['forpages']) : ($for1 > $this->_vars['forpages'])); $for1 += ((1 < $this->_vars['forpages']) ? 1 : -1)):  $this->assign('i', $for1); ?>
		<option value="<?php echo $this->_vars['i']; ?>"
		<?php if ($this->_vars['currentpage'] == $this->_vars['i']): ?>
			selected
		<?php endif; ?>
		> <?php echo $this->_vars['l_rpt_page']; ?> <?php echo $this->_vars['i']; ?> </option>
	<?php endfor; ?>
	</select>
	&nbsp;<input type="submit" value="<?php echo $this->_vars['l_submit']; ?>">
	</TD>
		<td align="right" width="33%">
			<?php if ($this->_vars['currentpage'] != $this->_vars['totalpages']): ?>
				<a href="defense_report.php?page=<?php echo $this->_vars['nextpage']; ?>&sort=<?php echo $this->_vars['sort']; ?>"><?php echo $this->_vars['l_rpt_next']; ?></a>
			<?php else: ?>
				&nbsp;
			<?php endif; ?>
		</td>
	</tr>
	<input type="hidden" name="sort" value="<?php echo $this->_vars['sort']; ?>">
	</form>
	</table>
<?php endif; ?>

		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
<TD align="center"><B><A HREF=defense_report.php?sort=galaxy_id><?php echo $this->_vars['l_galaxy']; ?></A></B></TD>
<TD align="center"><B><A HREF=defense_report.php?sort=sector><?php echo $this->_vars['l_sector']; ?></A></B></TD>
<TD align="center"><B><A HREF=defense_report.php?sort=quantity><?php echo $this->_vars['l_qty']; ?></A></B></TD>
<TD align="center"><B><A HREF=defense_report.php?sort=type><?php echo $this->_vars['l_sdf_type']; ?></A></B></TD>
</TR>
<?php extract($this->_vars, EXTR_REFS);  
	$curcolor = "#3A3B6E";
	for($i=0; $i<$num_sectors; $i++)
	{
		echo "<TR BGCOLOR=\"$curcolor\">";
		echo "<TD align=\"center\">" . $galaxylocation[$i] . "</TD>";
		if(currentgalaxy == $galaxylocationgalaxy[$i]){
			echo "<TD align=\"center\"><A HREF=main.php?move_method=real&engage=1&destination=". $dsector[$i] . ">". $dsector[$i] ."</A></TD>";
		}else{
			echo "<TD align=\"center\">" . $dsector[$i] ."</TD>";
		}
		echo "<TD align=\"center\">" . $dquantity[$i] . "</TD>";
		echo "<TD align=\"center\"> $defense_type[$i] </TD>";
		echo "</TR>";
		if ($curcolor == "#3A3B6E")
		{
			$curcolor = "#23244F";
		}else{
			$curcolor = "#3A3B6E";
		}
	}
 ?>
										<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

