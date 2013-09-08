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
	background-image: url(templates/';  echo $this->_vars['templatename'];  echo 'images/galactic_arm4.jpg);
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
	
input.groovybutton
{
   font-size:13px;
   font-family:Arial,sans-serif;
   font-weight: bold;
   height:23px;
   background-color:#779999;
   background-image:url(templates/';  echo $this->_vars['templatename'];  echo 'images/back03.gif);
   border-style:solid;
   border-color:#DDDDDD;
   border-width:1px;
}
    </style>

<script type="text/javascript">

function goLite(FRM,BTN)
{
   window.document.forms[FRM].elements[BTN].style.backgroundImage = "url(templates/';  echo $this->_vars['templatename'];  echo 'images/back02.gif)";
}

function goDim(FRM,BTN)
{
   window.document.forms[FRM].elements[BTN].style.backgroundImage = "url(templates/';  echo $this->_vars['templatename'];  echo 'images/back03.gif)";
}
</script>
<style type="text/css">

#dhtmltooltip{
position: absolute;
width: 150px;
border: 2px solid black;
padding: 2px;
background-color: white;
visibility: hidden;
z-index: 2000;
}

.tooltiptitle{COLOR: #FFFFFF; TEXT-DECORATION: none; CURSOR: Default; font-family: arial; font-weight: bold; font-size: 8pt}
.tooltipcontent{COLOR: #000000; TEXT-DECORATION: none; CURSOR: Default; font-family: arial; font-size: 8pt}
</style>

<div id="dhtmltooltip"></div>

<script type="text/javascript">

/***********************************************
* Cool DHTML tooltip script- © Dynamic Drive DHTML code library (www.dynamicdrive.com)
* This notice MUST stay intact for legal use
* Visit Dynamic Drive at http://www.dynamicdrive.com/ for full source code
***********************************************/

var offsetxpoint=30 //Customize x offset of tooltip
var offsetypoint=0 //Customize y offset of tooltip

var ie=document.all
var ns6=document.getElementById && !document.all
var enabletip=false
if (ie||ns6)
var tipobj=document.all? document.all["dhtmltooltip"] : document.getElementById? document.getElementById("dhtmltooltip") : ""

function ietruebody(){
return (document.compatMode && document.compatMode!="BackCompat")? document.documentElement : document.body
}


function ddrivetip(thetitle, thetext, thecolor, thewidth){
if (ns6||ie){
if (typeof thewidth!="undefined") tipobj.style.width=thewidth+"px"
if (typeof thecolor!="undefined" && thecolor!="") tipobj.style.backgroundColor=thecolor

	topColor = "#dddddd"
	subColor = "#eef6ed"
	ContentInfo = \'<table border="0" width="150" cellspacing="0" cellpadding="0">\'+
	\'<tr><td width="100%" bgcolor="#000000">\'+

	\'<table border="0" width="100%" cellspacing="1" cellpadding="0">\'+
	\'<tr><td width="100%" bgcolor=\'+topColor+\'>\'+

	\'<table border="0" width="90%" cellspacing="0" cellpadding="0" align="center">\'+
	\'<tr><td width="100%" align="center">\'+

	\'<font class="tooltiptitle">\'+thetitle+\'</font>\'+

	\'</td></tr>\'+
	\'</table>\'+

	\'</td></tr>\'+

	\'<tr><td width="100%" bgcolor=\'+subColor+\'>\'+

	\'<table border="0" width="90%" cellpadding="0" cellspacing="1" align="center">\'+

	\'<tr><td width="100%">\'+

	\'<font class="tooltipcontent">\'+thetext+\'</font>\'+

	\'</td></tr>\'+
	\'</table>\'+

	\'</td></tr>\'+
	\'</table>\'+

	\'</td></tr>\'+
	\'</table>\';

tipobj.innerHTML=ContentInfo
enabletip=true
return false
}
}

function positiontip(e){
if (enabletip){
var curX=(ns6)?e.pageX : event.clientX+ietruebody().scrollLeft;
var curY=(ns6)?e.pageY : event.clientY+ietruebody().scrollTop;
//Find out how close the mouse is to the corner of the window
var rightedge=ie&&!window.opera? ietruebody().clientWidth-event.clientX-offsetxpoint : window.innerWidth-e.clientX-offsetxpoint-20
var bottomedge=ie&&!window.opera? ietruebody().clientHeight-event.clientY-offsetypoint : window.innerHeight-e.clientY-offsetypoint-20

var leftedge=(offsetxpoint<0)? offsetxpoint*(-1) : -1000

//if the horizontal distance isn\'t enough to accomodate the width of the context menu
if (rightedge<tipobj.offsetWidth)
//move the horizontal position of the menu to the left by it\'s width
tipobj.style.left=ie? ietruebody().scrollLeft+event.clientX-tipobj.offsetWidth+"px" : window.pageXOffset+e.clientX-tipobj.offsetWidth+"px"
else if (curX<leftedge)
tipobj.style.left="5px"
else
//position the horizontal position of the menu where the mouse is positioned
tipobj.style.left=curX+offsetxpoint+"px"

//same concept with the vertical position
if (bottomedge<tipobj.offsetHeight)
tipobj.style.top=ie? ietruebody().scrollTop+event.clientY-tipobj.offsetHeight-offsetypoint+"px" : window.pageYOffset+e.clientY-tipobj.offsetHeight-offsetypoint+"px"
else
tipobj.style.top=curY+offsetypoint+"px"
tipobj.style.visibility="visible"
}
}

function hideddrivetip(){
if (ns6||ie){
enabletip=false
tipobj.style.visibility="hidden"
tipobj.style.left="-1000px"
tipobj.style.backgroundColor=\'\'
tipobj.style.width=\'\'
}
}

document.onmousemove=positiontip

//-->
</script>

<SCRIPT LANGUAGE="JavaScript">
	<!--

function MakeMax(name, val)
{
 if (document.forms[0].elements[name].value != val)
 {
	if (val != 0)
	{
	document.forms[0].elements[name].value = val;
	}
 }
}

function Comma(number) {
number = \'\' + Math.round(number);
if (number.length > 3) {
var mod = number.length % 3;
var output = (mod > 0 ? (number.substring(0,mod)) : \'\');
for (i=0 ; i < Math.floor(number.length / 3); i++) {
if ((mod == 0) && (i == 0))
output += number.substring(mod+ 3 * i, mod + 3 * i + 3);
else
output+= \',\' + number.substring(mod + 3 * i, mod + 3 * i + 3);
}
return (output);
}
else return number;
}

// changeDelta function //
function mypw(one,two)
{
	return Math.exp(two * Math.log(one));
}

'; ?>

<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['device_java_function']), 'iteration' => 0);
if (count((array)$this->_vars['device_java_function'])): foreach ((array)$this->_vars['device_java_function'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
  if ($this->_vars['device_java_function'][$this->_vars['key']] != ""):  echo $this->_vars['device_java_function'][$this->_vars['key']];  endif;  endforeach; endif;  echo '

function countTotal()
{
	// Here we cycle through all form values (other than buy, or full), and regexp out all non-numerics. (1,000 = 1000)
	// Then, if its become a null value (type in just a, it would be a blank value. blank is bad.) we set it to zero.
	clean_js()
	var form = document.forms[0];
	var i = form.elements.length;
	while (i > 0)
	{
		 if (form.elements[i-1].value == \'\')
		{
			form.elements[i-1].value =\'0\';
		}
		 i--;
	}

	// Here we set all \'Max\' items to 0 if they are over max - player amt.
'; ?>

<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['device_java2_countTotal']), 'iteration' => 0);
if (count((array)$this->_vars['device_java2_countTotal'])): foreach ((array)$this->_vars['device_java2_countTotal'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
  if ($this->_vars['device_java2_countTotal'][$this->_vars['key']] != ""):  echo $this->_vars['device_java2_countTotal'][$this->_vars['key']];  endif;  endforeach; endif;  echo '

	// Done with the bounds checking
	// Pluses must be first, or if empty will produce a javascript error
	form.total_cost.value ='; ?>

<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['device_java_countTotal']), 'iteration' => 0);
if (count((array)$this->_vars['device_java_countTotal'])): foreach ((array)$this->_vars['device_java_countTotal'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
  if ($this->_vars['device_java_countTotal'][$this->_vars['key']] != ""):  echo $this->_vars['device_java_countTotal'][$this->_vars['key']]; ?> +
<?php endif;  endforeach; endif;  echo ' 0;

	form.total_cost2.value = Comma(form.total_cost.value);

	if (form.total_cost.value > ';  echo $this->_vars['playerinfo']['credits'];  echo ')
	{
		form.total_cost.value = \'';  echo $this->_vars['l_no_credits'];  echo '\';
		form.total_cost2.value = form.total_cost.value;
//		form.total_cost.value = \'You are short \'+(form.total_cost.value - ';  echo $this->_vars['playerinfo']['credits'];  echo ') +\' credits\';
	}
	form.total_cost.length = form.total_cost.value.length;
}
	// -->
	</SCRIPT>

'; ?>

<?php echo $this->_vars['cleanjs']; ?>

<FORM name="devicesview" ACTION=port_purchase.php METHOD=POST>
<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="header"><h3><?php echo $this->_vars['l_port_welcome']; ?></h3></td>
  </tr>
  <tr>
    <td class="leftColumn"><div align="center"><img src="images/ports/port_devices.gif" alt="devices" /><br><b><?php echo $this->_vars['l_device']; ?></b></div></td>
</td>
  </tr>
  <tr>
    <td align="center" class="portfooter"><?php echo $this->_vars['l_creds_to_spend']; ?>
    	<?php if ($this->_vars['allow_ibank']): ?>
    		<br><?php echo $this->_vars['l_ifyouneedmore']; ?>
    	<?php endif; ?>
    </td>
  </tr>
</table>

<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
  <tr>
    <td class="leftBuyColumn" nowrap><b><?php echo $this->_vars['l_device']; ?></b></td>
    <td class="rightBuyColumn" nowrap><b><?php echo $this->_vars['l_cost']; ?></b></td>
    <td class="leftColumn" nowrap><b><?php echo $this->_vars['l_current']; ?></b></td>
    <td class="rightBuyColumn" nowrap><b><?php echo $this->_vars['l_max']; ?></b></td>
   <td class="leftColumn" nowrap><b><?php echo $this->_vars['l_qty']; ?></b></td>
  </tr>
<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['devicename']), 'iteration' => 0);
if (count((array)$this->_vars['devicename'])): foreach ((array)$this->_vars['devicename'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
  <tr>
    <td class="leftBuyColumn" nowrap><?php echo $this->_vars['devicename'][$this->_vars['key']]; ?></td>
    <td class="rightBuyColumn" nowrap><?php echo $this->_vars['deviceprice'][$this->_vars['key']]; ?></td>
    <td class="leftColumn" nowrap><?php echo $this->_vars['deviceamount'][$this->_vars['key']]; ?></td>
    <td class="rightBuyColumn" nowrap>
    	<?php if ($this->_vars['devicemaximum'][$this->_vars['key']] == 0): ?>
    		<?php echo $this->_vars['l_unlimited']; ?>
    	<?php else: ?>
    		<?php if ($this->_vars['shipinfo'][$this->_TPL['deviceclass']][$this->_vars['key']] != $this->_vars['devicemaximum'][$this->_vars['key']]): ?>
    			<?php if ($this->_vars['device_free'][$this->_vars['key']] != 0): ?>
	    			<a href="#" onClick="MakeMax('<?php echo $this->_vars['device_form_name'][$this->_vars['key']]; ?>', <?php echo $this->_vars['device_free'][$this->_vars['key']]; ?>); countTotal(); return false;"><?php extract($this->_vars, EXTR_REFS);  echo NUMBER($device_free[$key]);  ?></a>
	    		<?php else: ?>
	    			<?php extract($this->_vars, EXTR_REFS);  echo NUMBER($devicemaximum[$key]);  ?>
	    		<?php endif; ?>
	    	<?php endif; ?>
    	<?php endif; ?>
    </td>
	<td class="leftColumn" nowrap><?php echo $this->_vars['device_input'][$this->_vars['key']]; ?></td>
  </tr>
<?php endforeach; endif; ?>
  <tr><td colspan="5" align="center" class="portfooter"><input type="hidden" name="total_cost" value="0">
	<?php echo $this->_vars['l_totalcost']; ?>: <INPUT class="inputcss" TYPE="TEXT" style="text-align:right" NAME="total_cost2" SIZE="22" VALUE="0" <?php echo $this->_vars['onfocus']; ?> <?php echo $this->_vars['onblur']; ?> <?php echo $this->_vars['onchange']; ?> <?php echo $this->_vars['onclick']; ?>><br><br>
  	<input name="perform" type="button" class="groovybutton" value="<?php echo $this->_vars['l_buy']; ?>" ONCLICK="clean_js(); document:submit();" onMouseOver="goLite(this.form.name,this.name)" onMouseOut="goDim(this.form.name,this.name)"/>
	<?php if ($this->_vars['enable_spies'] == 1): ?>
		<BR><BR><?php echo $this->_vars['l_spy_cleanupship']; ?> <A HREF="spy.php?command=cleanup_ship"><?php echo $this->_vars['l_here']; ?></A>.
	<?php endif; ?>
  	<br><br><?php echo $this->_vars['gotomain']; ?></td></tr>
</table>

<?php if ($this->_vars['artifactcount'] > 0): ?>
	<table width="600" border="1" align="center" cellpadding="5" cellspacing="0">
		<tr>
		<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['artifactname']), 'iteration' => 0);
if (count((array)$this->_vars['artifactname'])): foreach ((array)$this->_vars['artifactname'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
			<td align="center" class="portfooter">
			<a href="artifact_grab.php?artifact_id=<?php echo $this->_vars['artifact_id'][$this->_vars['key']]; ?>" onMouseover="ddrivetip('<?php echo $this->_vars['artifactname'][$this->_vars['key']]; ?>','<?php echo $this->_vars['artifact_description'][$this->_vars['key']]; ?>');" onMouseout="hideddrivetip()">
			<img src="images/artifacts/<?php echo $this->_vars['artifactimage'][$this->_vars['key']]; ?>.gif" border=0></a><BR>
			<br><b>(<?php echo $this->_vars['artifactname'][$this->_vars['key']]; ?>)</b>
			<?php if ($this->_vars['key'] == 2 || $this->_vars['key'] == 5 || $this->_vars['key'] == 8 || $this->_vars['key'] == 11 || $this->_vars['key'] == 14): ?>
			</td></tr>
				<?php if ($this->_vars['key'] != $this->_vars['artifactcount'] - 1): ?>
					<tr>
				<?php endif; ?>
			<?php else: ?>
			</td>
			<?php endif; ?>
		<?php endforeach; endif; ?>
		<tr>
	</table>
<?php endif; ?>
</form>
</td></tr></table>
