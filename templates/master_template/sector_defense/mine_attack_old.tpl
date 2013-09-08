{literal}
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

{/literal}

<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="header"><h3>{$l_cmb_SD_attacking}</h3></td>
  </tr>
	{if $isfedbounty == 0}
  		<tr><td colspan="3" align="center" class="portfooter"><b>{$l_by_nofedbounty}</b></td></tr>
	{else}
		<tr><td colspan="3" align="center" class="portfooter"><b><span class="red">{$l_by_fedbounty2}</span></b></td></tr>
	{/if}
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="rightBuyColumnMini" nowrap><b>{$l_cmb_attacker_shields}</b></br>{$start_attacker_shields}</td>
    <td class="leftColumnMini" nowrap><b>{$l_cmb_attacker_armor}</b></br>{$start_attacker_armor}</td>
    <td class="rightBuyColumnMini" nowrap><b>{$l_cmb_attacker_minedeflectors}</b></br>{$start_attacker_minedeflectors}</td>
  </tr>
  <tr>
    <td class="leftColumnMini" nowrap colspan="3"><b>{$l_cmb_target_mines}</b></br>{$start_target_mines}</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr><td colspan="3" align="center" class="portfooter"><b><u>{$l_cmb_SD_minedeflector_exchange}</u></b></td></tr>
  <tr>
    <td class="leftBuyColumn" >
    	{foreach key=key value=item from=$attacker_minedeflector_result}
			<p><b>{$attacker_minedeflector_result[$key]}</b></p>
		{/foreach}
	</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="rightBuyColumnMini" nowrap><b>{$l_cmb_attacker_shields}</b></br>{$end_attacker_shields}</td>
    <td class="leftColumnMini" nowrap><b>{$l_cmb_attacker_armor}</b></br>{$end_attacker_armor}</td>
    <td class="rightBuyColumnMini" nowrap><b>{$l_cmb_attacker_minedeflectors}</b></br>{$end_attacker_minedeflectors}</td>
  </tr>
  <tr>
    <td class="leftColumnMini" nowrap colspan="3"><b>{$l_cmb_target_mines}</b></br>{$end_target_mines}</td>
  </tr>
</table>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr><td colspan="3" align="center" class="portfooter"><b><u>{$l_cmb_attack_exchange_results}</u></b></td></tr>
  <tr>
    <td class="leftBuyColumn" >
    	{foreach key=key value=item from=$attacker_exchange_result}
			<p><b>{$attacker_exchange_result[$key]}</b></p>
		{/foreach}
	</td>
  </tr>
  <tr><td colspan="5" align="center" class="portfooter">{$gotomain}</td></tr>
</table>
