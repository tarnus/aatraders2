<?php echo '
	<style type="text/css">

body {
	color: #2d2e2e;
	font-family: Arial, Helvetica, sans-serif;
	font-size: 11px;
	line-height: 14px;
	margin: 0 0 0 0; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	padding: 0 0 0 0; /* Sets the padding properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Centers the page content container in IE 5 browsers. */
}
	h3 {
	margin:0;
	text-align: center;
	color: #000;
    }
	.header {
    	padding:5px 10px;
		background:#ddd;
	}
.rightColumn {
	background-color: #eef6ed;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: left; /* Redefines the text alignment defined by the body element. */
	width: 200px;
	color: #000;
}
.rightBuyColumn {
	background-color: #eef6ed;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	width: 200px;
	color: #000;
}
.leftColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: left; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.centerBuyColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: left; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.centerColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.leftBuyColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: left; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.portfooter {
	background-color: #eef6ed;
	border-top: solid 1px #8ab573; /* Sets the top border properties for an element using shorthand notation */
	padding: 10px 10px 10px 10px; /* Sets the padding properties for an element using shorthand notation (top, right, bottom, left) */
	color: #000;
}
	.inputcss {
		font-family: Verdana, Geneva, sans-serif;
		font-size: 10px;
	}

 	a:link {
		color: #542764;
	}
	
   </style>

'; ?>


<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="header"><h3><?php echo $this->_vars['l_port_welcome']; ?></h3></td>
  </tr>
  <tr>
    <td class="leftColumn"><div align="center"><img src="images/ports/port_devices.gif" alt="spacedock" /><br><b><?php echo $this->_vars['l_device']; ?></b></div></td>
</td>
  </tr>
  <tr>
    <td align="center" class="portfooter"><?php echo $this->_vars['l_trade_result']; ?>
    	<br><b><font color="red"><?php echo $this->_vars['l_cost']; ?> : <?php echo $this->_vars['total_cost']; ?> <?php echo $this->_vars['l_credits']; ?></font></b>
    </td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="leftBuyColumn" nowrap><b><?php echo $this->_vars['l_device']; ?></b></td>
    <td class="centerColumn" nowrap><b><?php echo $this->_vars['l_amount']; ?></b></td>
    <td class="rightBuyColumn"><b><?php echo $this->_vars['l_cost']; ?></b></td>
  </tr>
<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['devicename']), 'iteration' => 0);
if (count((array)$this->_vars['devicename'])): foreach ((array)$this->_vars['devicename'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
  <tr>
    <td class="leftBuyColumn" nowrap><?php echo $this->_vars['devicename'][$this->_vars['key']]; ?></td>
    <td class="centerColumn" nowrap><?php echo $this->_vars['device_amount'][$this->_vars['key']]; ?></td>
    <td class="rightBuyColumn"><?php echo $this->_vars['device_total_cost'][$this->_vars['key']]; ?></td>
  </tr>
<?php endforeach; endif; ?>

  <tr><td colspan="3" align="center" class="portfooter">
  	<a href="port.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_port_returntospecial']; ?>
  	<br><br><?php echo $this->_vars['gotomain']; ?></td></tr>
</table>

</td></tr></table>
