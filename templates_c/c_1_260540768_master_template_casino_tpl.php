<h1><?php echo $this->_vars['title']; ?></h1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	<center><font size=2 color=white><b><?php echo $this->_vars['l_casino_welcome']; ?></font></center><p>
  <table width=100% border=0 cellpadding=3 cellspacing=0>
	<tr><td width=10% align=center>
	<font size=2 color=white><b><?php echo $this->_vars['l_casino_option']; ?></b></font>
	</td>
	<td width=* align=center>
	<font size=2 color=white><b><?php echo $this->_vars['l_casino_detail']; ?></b></font>
	</tr>
<tr><td colspan=2>&nbsp;</td></tr>
<?php extract($this->_vars, EXTR_REFS);  
		for($i = 1; $i <= $item_count; $i++){
			if($online_status_array[$i] == 'Y')
			{
				echo "<tr><td align=center>" .
				 "<a style=\"text-decoration: none\" href=$casino_link_array[$i]><img style=\"border: none\" src=\"templates/master_template/images/casino/$image_array[$i]\"><br>" .
				 "<font size=2 color=white><b>$name_array[$i]</a></b></font>";
				echo "</td><td valign=top><b>$description_array[$i]</b></td></tr><tr><td colspan=2><hr></td></tr>";
			}
		}
 ?>
</table>
				</td>
			</tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>