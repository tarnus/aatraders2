<h1><?php echo $this->_vars['title']; ?></h1>

<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
  <tr ">
	<td colspan="3" align="center"><?php echo $this->_vars['l_device_expl']; ?><br><br></td>
  </tr>
  <tr">
	<td><b><?php echo $this->_vars['l_device']; ?></b></td>
	<td><b><?php echo $this->_vars['l_qty']; ?></b></td>
  </tr>

<!-- mines/torpedoes section -->
  <tr>
	<td><a href=defense_deploy.php><?php echo $this->_vars['l_mines']; ?>/ <?php echo $this->_vars['l_fighters']; ?></a></td>
	<td><?php echo $this->_vars['dev_torps']; ?> / <?php echo $this->_vars['dev_fighters']; ?></td>
  </tr>
<!-- mines/torpedoes section end -->
<?php extract($this->_vars, EXTR_REFS);  
for($i = 0; $i < count($deviceclass); $i++)
{
echo"
  <tr>
	<td>";
	if($deviceprogram[$i] != '')
		echo "<a href=" . $deviceprogram[$i] . ">";
	echo $devicename[$i] . "</a></td>
	<td>" . $deviceamount[$i] . "</td>
  </tr>";
}
 ?>
										<tr><td colspan="3"><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
