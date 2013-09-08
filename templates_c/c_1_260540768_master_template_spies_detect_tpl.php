<h1><?php echo $this->_vars['title']; ?></h1>

<?php echo '
	<style type="text/css">
		.border {
			border-collapse: collapse; 
			border: 1px solid #ccc; 
		}
		.yellow { color: yellow; }
		.white { color: white; }
	</style>
'; ?>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	<?php if (! $this->_vars['isinfoid']): ?>
		<?php if ($this->_vars['infocount']): ?>
			<font color=red size='4'><?php echo $this->_vars['l_spy_infodeleted']; ?><BR><BR></font>
		<?php else: ?>
			<B><?php echo $this->_vars['l_spy_infonotyours']; ?></B><BR><BR>
		<?php endif; ?>
	<?php endif; ?>

	<?php if (! $this->_vars['isinfoidall']): ?>
		<font color=red size='4'><?php echo $this->_vars['l_spy_messagesdeleted']; ?><br><br></font>
	<?php endif; ?>
	
	<br>
	<table border="0" cellpadding="2" cellspacing="0" width="100%" class="border">
		<tr>
			<td bgcolor="#000000" colspan="4" align=center><font color=white><b><?php echo $this->_vars['l_spy_infotitle']; ?></b></font></td>
		</tr>
		<tr>
			<td bgcolor="#000000"><b><a href="spy.php?command=detect"><?php echo $this->_vars['l_spy_time']; ?></a></b></td>
			<td bgcolor="#000000"><b><a href="spy.php?command=detect&by=type"><?php echo $this->_vars['l_spy_type']; ?></a></b></td>
			<td bgcolor="#000000"><b><a href="spy.php?command=detect&by=data"><?php echo $this->_vars['l_spy_info']; ?></a></b></td>
			<td bgcolor="#000000" align="right"><b><a href="spy.php?command=detect&info_id_all=1"><?php echo $this->_vars['l_spy_deleteall']; ?></a></b></td>
		</tr>
		<?php extract($this->_vars, EXTR_REFS);  
		$line_color = "#000000";
		for($i = 0; $i < $detectcount; $i++)
		{
			if($line_color == "#000000")   
				$line_color = "#000000"; 
			else
				$line_color = "#000000"; 

			echo "<tr><td bgcolor=" . $line_color . "class=\"white\">$det_time[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$datatype[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$datainfo[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\" align=\"right\">
						<a href=\"spy.php?command=detect&info_id=$det_id[$i]&by=$by\">$l_spy_delete</a></td>
					</tr>";
		}
		 ?>
  </table>&nbsp;<br>
	<a href=spy.php><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_spy_menu']; ?>

</td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
