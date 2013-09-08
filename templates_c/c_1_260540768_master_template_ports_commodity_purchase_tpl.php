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
	background-image: url(templates/master_template/images/galactic_arm4.jpg);
}
	h3 {
	margin:0;
	text-align: center;
	color: #000;
    }

	h4 {
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
	text-align: center; /* Redefines the text alignment defined by the body element. */
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
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.centerBuyColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.leftBuyColumn {
	background-color: #333;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.portfooter {
	background-color: #eef6ed;
	border-top: solid 1px #8ab573; /* Sets the top border properties for an element using shorthand notation */
	padding: 10px 10px 10px 10px; /* Sets the padding properties for an element using shorthand notation (top, right, bottom, left) */
	color: #000;
	text-align: center;
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
    <td colspan="3" class="header"><h3><?php echo $this->_vars['l_port_welcome']; ?></h3><br>
    	<h4><?php echo $this->_vars['l_trade_result']; ?></h4></td>
  </tr>
  <tr>
    <td class="leftColumn" width="100"><img src="images/ports/big_<?php echo $this->_vars['buycommodity']; ?>.jpg" width="100" height="99" alt="sellcargo" /></td>
    <td class="leftColumn"><?php echo $this->_vars['youbought']; ?>:<br><?php echo $this->_vars['buyamount']; ?> @ <?php echo $this->_vars['buyprice']; ?> <?php echo $this->_vars['l_credits']; ?></td>
    <td class="rightColumn" width="200">	  <p><?php echo $this->_vars['buycost']; ?> <?php echo $this->_vars['l_credits']; ?> <?php echo $this->_vars['l_cost']; ?></p>
</td>
  </tr>
  <tr>
    <td colspan="3" class="portfooter"><b><font color="<?php echo $this->_vars['trade_color']; ?>"><?php echo $this->_vars['trade_result']; ?> </font></b> <font color="<?php echo $this->_vars['trade_color']; ?>"><b><?php echo $this->_vars['trade_result_total']; ?> <?php echo $this->_vars['l_credits']; ?></font></b></td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">

<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['commodity_name']), 'iteration' => 0);
if (count((array)$this->_vars['commodity_name'])): foreach ((array)$this->_vars['commodity_name'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
  <tr>
    <td class="leftBuyColumn" width="12"><img src="images/ports/<?php echo $this->_vars['commodity_image'][$this->_vars['key']]; ?>.png" width="12" height="12" alt="sellcargo" /></td>
    <td class="centerBuyColumn"> <?php echo $this->_vars['commodity_boughtsold'][$this->_vars['key']]; ?>: <?php echo $this->_run_modifier($this->_vars['commodity_name'][$this->_vars['key']], 'ucwords', 'PHP', 1); ?> <?php echo $this->_vars['commodity_total'][$this->_vars['key']]; ?> @ <?php echo $this->_vars['commodity_value'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_credits']; ?></td>
    <td class="rightBuyColumn" width="200">	 
	    <?php echo $this->_vars['sellcost'][$this->_vars['key']]; ?> <?php echo $this->_vars['l_credits']; ?> <?php echo $this->_vars['l_profit']; ?>
</td>
  </tr>
<?php endforeach; endif; ?>
  <tr><td colspan="3" align="center" class="portfooter"><?php echo $this->_vars['l_trade_complete']; ?>
  	<br><br><?php echo $this->_vars['gotomain']; ?></td></tr>
</table>
</td></tr></table>
