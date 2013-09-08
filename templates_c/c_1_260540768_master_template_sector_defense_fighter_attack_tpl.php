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
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.rightBuyColumn {
	background-color: #eef6ed;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
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
.centerColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.leftBuyColumn {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}

.rightColumnMini {
	background-color: #eef6ed;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.rightBuyColumnMini {
	background-color: #eef6ed;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.leftColumnMini {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.centerBuyColumnMini {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.centerColumnMini {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
	color: #000;
}
.leftBuyColumnMini {
	background-color: #fff;
	margin: 0 auto 0 auto; /* Sets the margin properties for an element using shorthand notation (top, right, bottom, left) */
	text-align: center; /* Redefines the text alignment defined by the body element. */
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
    <td class="header"><h3><?php echo $this->_vars['l_cmb_SD_attacking']; ?></h3></td>
  </tr>
	<?php if ($this->_vars['isfedbounty'] == 0): ?>
  		<tr><td colspan="3" align="center" class="portfooter"><b><?php echo $this->_vars['l_by_nofedbounty']; ?></b></td></tr>
	<?php else: ?>
		<tr><td colspan="3" align="center" class="portfooter"><b><span class="red"><?php echo $this->_vars['l_by_fedbounty2']; ?></span></b></td></tr>
	<?php endif; ?>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_fighters']; ?></b></br><?php echo $this->_vars['start_attacker_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_torps']; ?></b></br><?php echo $this->_vars['start_attacker_torps']; ?></td>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_armor']; ?></b></br><?php echo $this->_vars['start_attacker_armor']; ?></td>
  </tr>
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_fighters']; ?></b></br><?php echo $this->_vars['start_target_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_mines']; ?></b></br><?php echo $this->_vars['start_target_mines']; ?></td>
    <td class="rightBuyColumnMini" nowrap>&nbsp;</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr><td colspan="3" align="center" class="portfooter"><b><u><?php echo $this->_vars['l_cmb_SD_fighterFighter_exchange']; ?></u></b></td></tr>
  <tr>
    <td class="leftBuyColumn" >
    	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['attacker_fighter_result']), 'iteration' => 0);
if (count((array)$this->_vars['attacker_fighter_result'])): foreach ((array)$this->_vars['attacker_fighter_result'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<p><b><?php echo $this->_vars['attacker_fighter_result'][$this->_vars['key']]; ?></b></p>
		<?php endforeach; endif; ?>
	</td>
    <td class="rightBuyColumn" >
    	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['target_fighter_result']), 'iteration' => 0);
if (count((array)$this->_vars['target_fighter_result'])): foreach ((array)$this->_vars['target_fighter_result'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<p><b><?php echo $this->_vars['target_fighter_result'][$this->_vars['key']]; ?></b></p>
		<?php endforeach; endif; ?>
	</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_fighters']; ?></b></br><?php echo $this->_vars['stage1_attacker_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_torps']; ?></b></br><?php echo $this->_vars['stage1_attacker_torps']; ?></td>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_armor']; ?></b></br><?php echo $this->_vars['stage1_attacker_armor']; ?></td>
  </tr>
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_fighters']; ?></b></br><?php echo $this->_vars['stage1_target_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_mines']; ?></b></br><?php echo $this->_vars['stage1_target_mines']; ?></td>
    <td class="rightBuyColumnMini" nowrap>&nbsp;</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr><td colspan="3" align="center" class="portfooter"><b><u><?php echo $this->_vars['l_cmb_SD_torpFighter_exchange']; ?></u></b></td></tr>
  <tr>
    <td class="leftBuyColumn" >
    	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['attacker_torpmine_result']), 'iteration' => 0);
if (count((array)$this->_vars['attacker_torpmine_result'])): foreach ((array)$this->_vars['attacker_torpmine_result'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<p><b><?php echo $this->_vars['attacker_torpmine_result'][$this->_vars['key']]; ?></b></p>
		<?php endforeach; endif; ?>
	</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_fighters']; ?></b></br><?php echo $this->_vars['stage2_attacker_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_torps']; ?></b></br><?php echo $this->_vars['stage2_attacker_torps']; ?></td>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_armor']; ?></b></br><?php echo $this->_vars['stage2_attacker_armor']; ?></td>
  </tr>
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_fighters']; ?></b></br><?php echo $this->_vars['stage2_target_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_mines']; ?></b></br><?php echo $this->_vars['stage2_target_mines']; ?></td>
    <td class="rightBuyColumnMini" nowrap>&nbsp;</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr><td colspan="3" align="center" class="portfooter"><b><u><?php echo $this->_vars['l_cmb_SD_armor_exchange']; ?></u></b></td></tr>
  <tr>
    <td class="leftBuyColumn" >
    	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['target_armor_result']), 'iteration' => 0);
if (count((array)$this->_vars['target_armor_result'])): foreach ((array)$this->_vars['target_armor_result'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<p><b><?php echo $this->_vars['target_armor_result'][$this->_vars['key']]; ?></b></p>
		<?php endforeach; endif; ?>
	</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_fighters']; ?></b></br><?php echo $this->_vars['end_attacker_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_torps']; ?></b></br><?php echo $this->_vars['end_attacker_torps']; ?></td>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_attacker_armor']; ?></b></br><?php echo $this->_vars['end_attacker_armor']; ?></td>
  </tr>
  <tr>
    <td class="rightBuyColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_fighters']; ?></b></br><?php echo $this->_vars['end_target_fighters']; ?></td>
    <td class="leftColumnMini" nowrap><b><?php echo $this->_vars['l_cmb_target_mines']; ?></b></br><?php echo $this->_vars['end_target_mines']; ?></td>
    <td class="rightBuyColumnMini" nowrap>&nbsp;</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr><td colspan="3" align="center" class="portfooter"><b><u><?php echo $this->_vars['l_cmb_attack_exchange_results']; ?></u></b></td></tr>
  <tr>
    <td class="leftBuyColumn" >
    	<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['attacker_exchange_result']), 'iteration' => 0);
if (count((array)$this->_vars['attacker_exchange_result'])): foreach ((array)$this->_vars['attacker_exchange_result'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<p><b><?php echo $this->_vars['attacker_exchange_result'][$this->_vars['key']]; ?></b></p>
		<?php endforeach; endif; ?>
	</td>
  </tr>
  <tr><td colspan="5" align="center" class="portfooter"><?php echo $this->_vars['gotomain']; ?></td></tr>
</table>
