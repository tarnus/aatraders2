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
	table {
		-moz-opacity:0.9;
		filter:alpha(opacity=90);
		opacity:0.9;
	}

 	a:link {
		color: #542764;
	}
	
   </style>

'; ?>


<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="header"><h3><?php echo $this->_vars['title']; ?></h3></td>
  </tr>

</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
<?php if ($this->_vars['part1'] == 1): ?>
  <tr>
    <td class="leftBuyColumn" nowrap><b><?php echo $this->_vars['startmovetype']; ?> <?php echo $this->_vars['sectorstart']; ?></b></td>
    <td class="rightBuyColumn"><b><?php echo $this->_vars['start_result'][0]; ?></b></td>
  </tr>
<?php endif;  if ($this->_vars['part2'] == 1): ?>
	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['warp_list_movetype']), 'iteration' => 0);
if (count((array)$this->_vars['warp_list_movetype'])): foreach ((array)$this->_vars['warp_list_movetype'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
  <tr>
    <td class="leftBuyColumn" nowrap><?php echo $this->_vars['warp_list_movetype'][$this->_vars['key']]; ?> <?php echo $this->_vars['warp_list_sector'][$this->_vars['key']]; ?></td>
    <td class="rightBuyColumn"><?php echo $this->_vars['move_result'][$this->_vars['key']]; ?></td>
  </tr>
	<?php endforeach; endif;  endif;  if ($this->_vars['part3'] == 1): ?>
  <tr>
    <td class="leftBuyColumn" nowrap><b><?php echo $this->_vars['endmovetype']; ?> <?php echo $this->_vars['endsector']; ?></b></td>
    <td class="rightBuyColumn"><b><?php echo $this->_vars['endmove_result'][0]; ?></b></td>
  </tr>
<?php endif; ?>
  <tr><td colspan="3" align="center" class="portfooter">
  	<a style="color: #542764;" href="navcomp.php"><?php echo $this->_vars['l_autoroute_return']; ?></a>
  	<br><br><?php echo $this->_vars['gotomain']; ?></td></tr>
</table>

</td></tr></table>
