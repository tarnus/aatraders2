<?php echo '
<script type="text/javascript">
<!--
var xmlDoc = null ;
var target_sector = \'\' ;
var returndata = \'\' ;
var returnmessage = "';  echo $this->_vars['l_mininavinfo'];  echo '";
var elementlist;

function fillrealspace(target_sector)
{
	document.getElementById(\'destination\').value = target_sector;
}

function makeRequest()
{
	target_sector = document.getElementById(\'destination\').value;

	if ( xmlDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlDoc.onreadystatechange = process ;
	}
		else
		{
			xmlDoc = new XMLHttpRequest();
			xmlDoc.onload = process ;
		}
	}
	xmlDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=mininav_autoroute_find&endsector=" + target_sector, false );
	xmlDoc.send( null );

}

function process() {
	if ( xmlDoc.readyState != 4 )
	{
		return ;
	}
	returndata = xmlDoc.responseText

	if (returndata.indexOf("-1") != -1)
	{
		ddrivetip("';  echo $this->_vars['l_noroutetosectortitle'];  echo '","';  echo $this->_vars['l_noroutetosectorbody'];  echo '");
		setInterval("hideddrivetip()",5000)
		return;
	}

	elementlist=returndata.split(\'^\');
	var sectorlist=elementlist[0].split(\'|\');
//	returnmessage = \'<br><br>';  echo $this->_vars['l_autoroutelist'];  echo '<br>\';

	for (var x = 0; x < sectorlist.length; x++)
	{
		var sectorname = sectorlist[x];
//		returnmessage = returnmessage + sectorname + \'<br>\'
	}
//	returnmessage = returnmessage + elementlist[1] + \'<br><br>\'
	document.location.href = \'';  echo $this->_vars['full_url'];  echo 'navcomp.php?state=immediatestart&destination=\' + elementlist[1] + "&forward_warp_list=" + elementlist[0];
}

//-->
</script>

<style type="text/css">

#dhtmltooltip{
position: absolute;
width: 200px;
border: 2px solid black;
padding: 2px;
background-color: lightyellow;
visibility: hidden;
z-index: 2000;
/*Remove below line to remove shadow. Below line should always appear last within this CSS*/
filter: progid:DXImageTransform.Microsoft.Shadow(color=gray,direction=135);
}

.tooltiptitle{COLOR: #FFFFFF; TEXT-DECORATION: none; CURSOR: Default; font-family: arial; font-weight: bold; font-size: 8pt}
.tooltipcontent{COLOR: #000000; TEXT-DECORATION: none; CURSOR: Default; font-family: arial; font-size: 8pt}
</style>

<div id="dhtmltooltip"></div>

<script type="text/javascript">

/***********************************************
* Cool DHTML tooltip script- � Dynamic Drive DHTML code library (www.dynamicdrive.com)
* This notice MUST stay intact for legal use
* Visit Dynamic Drive at http://www.dynamicdrive.com/ for full source code
***********************************************/

var offsetxpoint=-60 //Customize x offset of tooltip
var offsetypoint=40 //Customize y offset of tooltip

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

	topColor = "#7D92A9"
	subColor = "#A5B4C4"
	ContentInfo = \'<table border="0" width="200" cellspacing="0" cellpadding="0">\'+
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
//if (bottomedge<tipobj.offsetHeight)
//tipobj.style.top=ie? ietruebody().scrollTop+event.clientY-tipobj.offsetHeight-offsetypoint+"px" : window.pageYOffset+e.clientY-tipobj.offsetHeight-offsetypoint+"px"
//Else
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

<script type="text/javascript" language="JavaScript1.2">
var key = new Array();  // Define key launcher pages here
key[\'a\'] = "traderoute_create.php";
key[\'b\'] = "global_chat.php";
key[\'B\'] = "beacon.php";
key[\'c\'] = "genesis.php";
key[\'C\'] = "sectorgenesis.php";
key[\'D\'] = "device.php";
key[\'d\'] = "defense_report.php";
key[\'e\'] = "emerwarp.php"; 
key[\'f\'] = "long_range_scan.php";
key[\'G\'] = "galaxy_local.php";
key[\'g\'] = "galaxy_map.php";
key[\'i\'] = "igb.php";
key[\'L\'] = "logout.php";
key[\'l\'] = "log.php";
key[\'m\'] = "message_read.php";
key[\'M\'] = "defense_deploy.php";
key[\'n\'] = "news.php";
key[\'N\'] = "sector_notes.php";
key[\'o\'] = "options.php";
'; ?>

<?php if ($this->_vars['allow_probes'] == 1): ?>
<?php echo '
key[\'P\'] = "probes.php"; 
'; ?>

<?php endif; ?>
<?php echo '
key[\'p\'] = "planet_report.php?PRepType=1"; 
key[\'r\'] = "ranking.php"; 
key[\'R\'] = "report.php"; 
key[\'s\'] = "message_send.php";
key[\'t\'] = "traderoute_listroutes.php";
key[\'T\'] = "team_defense_report.php";
key[\'u\'] = "galaxy_map3d.php";
key[\'w\'] = "warpedit.php";
key[\'z\'] = "stored_ship_report.php";
key[\'[\'] = "dig.php";
key[\']\'] = "spy.php";
key[\'.\'] = "galaxy_local.php";

var newwindow = new Array();  // Define key launcher pages here
newwindow[\'a\'] = 0;
newwindow[\'b\'] = 0;
newwindow[\'B\'] = 0;
newwindow[\'c\'] = 0;
newwindow[\'C\'] = 0;
newwindow[\'D\'] = 0;
newwindow[\'d\'] = 0;
newwindow[\'e\'] = 0;
newwindow[\'f\'] = 0;
newwindow[\'G\'] = 0;
newwindow[\'g\'] = 0;
newwindow[\'i\'] = 0;
newwindow[\'L\'] = 0;
newwindow[\'l\'] = 0;
newwindow[\'m\'] = 0;
newwindow[\'M\'] = 0;
newwindow[\'n\'] = 0;
newwindow[\'N\'] = 0;
newwindow[\'o\'] = 0;
newwindow[\'P\'] = 0;
newwindow[\'p\'] = 0;
newwindow[\'R\'] = 0;
newwindow[\'r\'] = 0;
newwindow[\'s\'] = 0;
newwindow[\'t\'] = 0;
newwindow[\'T\'] = 0;
newwindow[\'u\'] = 0;
newwindow[\'w\'] = 0;
newwindow[\'z\'] = 0;
newwindow[\'[\'] = 0;
newwindow[\']\'] = 0;
newwindow[\'.\'] = 1;

function getKey(e) {
if(!e) var e = window.event;
if(e.which) {
which = String.fromCharCode(e.which);
}
if(e.keyCode){
which = String.fromCharCode(e.keyCode);
}

	if(e.keyCode || e.which){
		for (var i in key){ 
		if (which == i){
			if (newwindow[i])
				window.open(key[i],\'\',\'\');
			else
				window.location = key[i];
			}
		}	
	}		
	
}

document.onkeypress = getKey;

</script>
 '; ?>

 
<table border="0" cellspacing="0" cellpadding="0" width="100%">
  <tr>
    <td width="31" height="18"><img src="templates/default_menu_classic/images/topbar-tl.gif" width="31" height="18"></td>
    <td  background="templates/default_menu_classic/images/topbar-top-bg.gif" colspan="4"><img src="templates/default_menu_classic/images/topbar-top-bg.gif" width="250" height="19"></td>
    
    <td width="12" height="18"><img src="templates/default_menu_classic/images/topbar-tr.gif" width="12" height="18"></td>

  </tr>
  <tr>
    <td bgcolor="#000000" align="right" width="31" height="20"><img src="templates/default_menu_classic/images/topbar-midleft.gif" width="31" height="20"></td>
    <td background="templates/default_menu_classic/images/topbar-mid-bg.gif"  align="left" colspan="2" ID="IEshout1"><img src="templates/master_template/images/spacer.gif" width="250" height="1"><br><div style="border-style: dotted1none; border-color:white" id=scroll3 dir=rtl ;overflow:auto>
<?php echo '
<script language="javascript" type="text/javascript">
 	function OpenSB()
		{
			f2 = open("shoutbox.php","f2","width=700,height=400,scrollbars=yes");
		}
</script>	
<SCRIPT LANGUAGE="JavaScript1.2" TYPE="text/javascript">
<!--
prefix1=\' \';

'; ?>

<?php extract($this->_vars, EXTR_REFS);  
$stuff="";
$stuff2="";
for($i = 0; $i < $shoutcount; $i++){ 
$stuff2.="\"global_chat.php\",";
$stuff.="\"".$shoutmessage[$i]."\",";
}
$stuff.="\"End of Shouts\"";
$stuff2.="\"global_chat.php\"";
 ?>
<?php echo '
arURL1 = new Array(';  extract($this->_vars, EXTR_REFS);  echo $stuff2;  echo ');
arTXT1 = new Array(';  extract($this->_vars, EXTR_REFS);  echo $stuff;  echo ');


document.write(\'<LAYER ID=shout1><\\/LAYER>\');
NS4 = (document.layers);
IE4 = (document.all);

FDRblendInt1 = 5; // seconds between flips
FDRmaxLoops1 = 20; // max number of loops (full set of headlines each loop)
FDRendWithFirst1 = true;

FDRfinite1 = (FDRmaxLoops1 > 0);
blendTimer1 = null;

arTopNews1 = [];
for (i1=0;i1<arTXT1.length;i1++)
{
 arTopNews1[arTopNews1.length] = arTXT1[i1];
 arTopNews1[arTopNews1.length] = arURL1[i1];
}
TopPrefix1 = prefix1;

if(NS4)
{
	shout1 = document.shout1;
	shout1.visibility="hide";

	pos11 = document.images[\'pht1\'];
	pos1E1 = document.images[\'ph1E1\'];
	shout1.left = pos11.x;
	shout1.top = pos11.y;
	shout1.clip.width = 350;
	shout1.clip.height = pos1E1.y - shout1.top;
}
else 
{
	document.getElementById(\'IEshout1\').style.pixelHeight = document.getElementById(\'IEshout1\').offsetHeight;
}

function FDRredo1()
{
	if (innerWidth==origWidth1 && innerHeight==origHeight1) return;
	location.reload();
}

function FDRcountLoads1() 
{
	if (NS4)
	{
		origWidth1 = innerWidth;
		origHeight1 = innerHeight;
		window.onresize = FDRredo1;
	}

	TopnewsCount1 = 0;
	TopLoopCount1 = 0;

	FDRdo1();
	blendTimer1 = setInterval("FDRdo1()",FDRblendInt1*1000)
}

function FDRdo1() 
{
	if (FDRfinite1 && TopLoopCount1>=FDRmaxLoops1) 
	{
		FDRend1();
		return;
	}
	FDRfade1();

	if (TopnewsCount1 >= arTopNews1.length) 
	{
		TopnewsCount1 = 0;
		if (FDRfinite1) TopLoopCount1++;
	}
}

function FDRfade1(){
	if(TopLoopCount1 < FDRmaxLoops1) {
		TopnewsStr1 = "";
		for (var i=0;i<1;i++)
		{
			if(TopnewsCount1 < arTopNews1.length) 
			{
				TopnewsStr1 += "<P><A CLASS=headlines HREF=\'#\' onClick=\'OpenSB();\'>"
							+ arTopNews1[TopnewsCount1] + "</" + "A><img src=\'/images/spacer.gif\' width=1 height=15></" + "P>"
				TopnewsCount1 += 2;
			}
		}
		if (NS4) 
		{
			shout1.document.write(TopnewsStr1);
			shout1.document.close();
			shout1.visibility="show";
		}
		else 
		{
			document.getElementById(\'IEshout1\').innerHTML = TopnewsStr1;
		}
	}
}

function FDRend1(){
	clearInterval(blendTimer1);
	if (FDRendWithFirst1) 
	{
		TopnewsCount1 = 0;
		TopLoopCount1 = 0;
		FDRfade1();
	}
}

window.onload = FDRcountLoads1;
//-->
</SCRIPT>
'; ?>

</td>
    <td background="templates/default_menu_classic/images/topbar-mid-bg.gif" ID="IEfad1" align="right" colspan="2"><img src="templates/master_template/images/spacer.gif" width="250" height="1"><br><div style="border-style: dotted1none; border-color:white" id=scroll3 dir=rtl ;overflow:auto>
<?php echo '
<SCRIPT LANGUAGE="JavaScript1.2" TYPE="text/javascript">
<!--

prefix=\' \';

'; ?>

<?php extract($this->_vars, EXTR_REFS);  
$stuff="";
$stuff2="";
for($i = 0; $i < $newscount; $i++){ 
$stuff2.="\"news.php\",";
if (AAT_strlen($newsmessage[$i])>40){
	$stuff.="\"".AAT_substr($newsmessage[$i],0,40)."...\",";
	}else{
	$stuff.="\"".$newsmessage[$i]."\",";
	}
}
$stuff.="\"End of News\"";
$stuff2.="\"news.php\"";
 ?>
<?php echo '
arURL = new Array(';  extract($this->_vars, EXTR_REFS);  echo $stuff2;  echo ');
arTXT = new Array(';  extract($this->_vars, EXTR_REFS);  echo $stuff;  echo ');

document.write(\'<LAYER ID=fad1><\\/LAYER>\');
NS4 = (document.layers);
IE4 = (document.all);

FDRblendInt = 5; // seconds between flips
FDRmaxLoops = 20; // max number of loops (full set of headlines each loop)
FDRendWithFirst = true;

FDRfinite = (FDRmaxLoops > 0);
blendTimer = null;

arTopNews = [];
for (i=0;i<arTXT.length;i++)
{
 arTopNews[arTopNews.length] = arTXT[i];
 arTopNews[arTopNews.length] = arURL[i];
}
TopPrefix = prefix;

if(NS4)
{
	fad1 = document.fad1;
	fad1.visibility="hide";

	pos1 = document.images[\'pht\'];
	pos1E = document.images[\'ph1E\'];
	fad1.left = pos1.x;
	fad1.top = pos1.y;
	fad1.clip.width = 300;
	fad1.clip.height = pos1E.y - fad1.top;
}
else 
{
	document.getElementById(\'IEfad1\').style.pixelHeight = document.getElementById(\'IEfad1\').offsetHeight;
}

function FDRredo()
{
	if (innerWidth==origWidth && innerHeight==origHeight) return;
	location.reload();
}

function FDRcountLoads() 
{
	if (NS4)
	{
		origWidth = innerWidth;
		origHeight = innerHeight;
		window.onresize = FDRredo;
	}

	TopnewsCount = 0;
	TopLoopCount = 0;

	FDRdo();
	blendTimer = setInterval("FDRdo()",FDRblendInt*1000)
		if (NS4)
	{
		origWidth1 = innerWidth;
		origHeight1 = innerHeight;
		window.onresize = FDRredo1;
	}

	TopnewsCount1 = 0;
	TopLoopCount1 = 0;

	FDRdo1();
	blendTimer1 = setInterval("FDRdo1()",FDRblendInt1*1000)
}

function FDRdo() 
{
	if (FDRfinite && TopLoopCount>=FDRmaxLoops) 
	{
		FDRend();
		return;
	}
	FDRfade();

	if (TopnewsCount >= arTopNews.length) 
	{
		TopnewsCount = 0;
		if (FDRfinite) TopLoopCount++;
	}
}

function FDRfade(){
	if(TopLoopCount < FDRmaxLoops) {
		TopnewsStr = "";
		for (var i=0;i<1;i++)
		{
			if(TopnewsCount < arTopNews.length) 
			{
				TopnewsStr += "<P><A CLASS=headlines "
							+ "HREF=\'" + TopPrefix + arTopNews[TopnewsCount+1] + "\'>"
							+ arTopNews[TopnewsCount] + "</" + "A></" + "P>"
				TopnewsCount += 2;
			}
		}
		if (NS4) 
		{
			fad1.document.write(TopnewsStr);
			fad1.document.close();
			fad1.visibility="show";
		}
		else 
		{
			document.getElementById(\'IEfad1\').innerHTML = TopnewsStr;
		}
	}
}

function FDRend(){
	clearInterval(blendTimer);
	if (FDRendWithFirst) 
	{
		TopnewsCount = 0;
		TopLoopCount = 0;
		FDRfade();
	}
}

window.onload = FDRcountLoads;
//-->
</SCRIPT>
'; ?>

	</td>
    <td><img src="templates/default_menu_classic/images/topbar-midright.gif" width="12" height="20"></td>
  </tr>
  <tr>
    <td bgcolor="3A3A3A">&nbsp;</td>
    <td bgcolor="3A3A3A" valign="middle" colspan="3"><?php echo '
<style type="text/css">
/*Credits: Dynamic Drive CSS Library */
/*URL: http://www.dynamicdrive.com/style/ */
.suckertreemenu ul{
	margin: 0;
	padding: 0;
	list-style-type: none;
	z-index: 2000; 
}

/*Top level list items*/
.suckertreemenu ul li{
	position: relative;
	display: inline;
	float: left;
	background-color: #3a3a3a; /*overall menu background color*/
	z-index: 2000; 
}

/*Top level menu link items style*/
.suckertreemenu ul li a{
	display: block;
	width: auto; /*Width of top level menu link items*/
	padding: 3px 15px 3px 10px;
	text-decoration: none;
	color: white;
	font-family: Verdana, Arial, sans-serif;
	font-size: 12px;
}
	
/*1st sub level menu*/
.suckertreemenu ul li ul{
	left: 0;
	position: absolute;
	top: 1em; /* no need to change, as true value set by script */
	display: block;
	visibility: hidden;
}

/*Sub level menu list items (undo style from Top level List Items)*/
.suckertreemenu ul li ul li{
	display: list-item;
	float: none;
}

/*All subsequent sub menu levels offset after 1st level sub menu */
.suckertreemenu ul li ul li ul{ 
	left: auto; /* no need to change, as true value set by script */
	top: 0;
}

/* Sub level menu links style */
.suckertreemenu ul li ul li a{
	display: block;
	width: 160px; /*width of sub menu levels*/
	color: white;
	text-decoration: none;
	padding: 3px 15px 3px 10px;
}

.suckertreemenu ul li a:hover{
	background-color: #000000;
	color: white;
}

/*Background image for top level menu list links */
.suckertreemenu .mainfoldericon{
	background: #3a3a3a url(templates/default_menu_classic/images/arrow_down.gif) no-repeat center right;
}

/*Background image for subsequent level menu list links */
.suckertreemenu .subfoldericon{
	background: #3a3a3a url(templates/default_menu_classic/images/arrow_right.gif) no-repeat center right;
}

/* Holly Hack for IE \\*/
* html .suckertreemenu ul li { float: left; height: 1%; }
* html .suckertreemenu ul li a { height: 1%; width: 1px;}
* html .suckertreemenu ul li ul li { float: left;}
/* End */

</style>

<script type="text/javascript">

//SuckerTree Horizontal Menu (Sept 14th, 06)
//By Dynamic Drive: http://www.dynamicdrive.com/style/

var menuid="treemenu"

function buildsubmenus_horizontal()
{
	var ultags=document.getElementById(menuid).getElementsByTagName("ul")
	for (var t=0; t<ultags.length; t++)
	{
		if (ultags[t].parentNode.parentNode.id==menuid)
		{ //if this is a first level submenu
			ultags[t].style.top=ultags[t].parentNode.offsetHeight+"px" //dynamically position first level submenus to be height of main menu item
			ultags[t].parentNode.getElementsByTagName("a")[0].className="mainfoldericon"
		}
		else
		{ //else if this is a sub level menu (ul)
			ultags[t].style.left=ultags[t-1].getElementsByTagName("a")[0].offsetWidth+"px" //position menu to the right of menu item that activated it
			ultags[t].parentNode.getElementsByTagName("a")[0].className="subfoldericon"
		}
		ultags[t].parentNode.onmouseover=function()
		{
			this.getElementsByTagName("ul")[0].style.visibility="visible"
		}
		ultags[t].parentNode.onmouseout=function()
		{
			this.getElementsByTagName("ul")[0].style.visibility="hidden"
		}
	}
}

if (window.addEventListener)
	window.addEventListener("load", buildsubmenus_horizontal, false)
else if (window.attachEvent)
	window.attachEvent("onload", buildsubmenus_horizontal)


</script>
'; ?>

<div class="suckertreemenu">
<ul id="treemenu">
	<li><a href="device.php"><?php echo $this->_vars['l_device_ports']; ?></a>
		<ul>
			<li><a href="navcomp.php"><?php echo $this->_vars['l_navcomp']; ?></a></li>
			<li><a href="beacon.php"><?php echo $this->_vars['l_spacebeacon']; ?></a></li>
<?php if ($this->_vars['allow_probes'] == 1): ?>
			<li><a href="probes.php?command=drop"><?php echo $this->_vars['l_spaceprobes']; ?></a></li>
<?php endif; ?>
			<li><a href="warpedit.php"><?php echo $this->_vars['l_warpeditors']; ?></a></li>
			<li><a href="genesis.php"><?php echo $this->_vars['l_genesistorps']; ?></a></li>
			<li><a href="sectorgenesis.php"><?php echo $this->_vars['l_sgtorps']; ?></a></li>
			<li><a href="defense_deploy.php"><?php echo $this->_vars['l_minesfighters']; ?></a></li>
			<li><a href="emerwarp.php"><?php echo $this->_vars['l_ewarp']; ?></a></li>
		</ul>
	</li>
	<li><a href="report.php"><?php echo $this->_vars['l_reports']; ?></a>
		<ul>
			<li><a href="report.php"><?php echo $this->_vars['l_shipinfo']; ?></a></li>
			<li><a href="ranking.php"><?php echo $this->_vars['l_rankings']; ?></a></li>
			<li><a href="igb.php">IGB</a></li>
			<li><a href="planet_report.php"><?php echo $this->_vars['planets']; ?></a>
			<ul>
				<li><a href="planet_report.php?PRepType=1"><?php echo $this->_vars['l_planetstatus']; ?></a></li>
				<li><a href="planet_report.php?PRepType=3"><?php echo $this->_vars['l_planetdefenses']; ?></a></li>
				<li><a href="planet_report.php?PRepType=2"><?php echo $this->_vars['l_changeproduction']; ?></a></li>
			</ul>
			</li>
			<li><a href="stored_ship_report.php"><?php echo $this->_vars['l_storedshipreport']; ?></a></li>
<?php if ($this->_vars['enable_spies'] == 1): ?>
			<li><a href="spy.php"><?php echo $this->_vars['l_spy']; ?></a></li>
<?php endif; ?>
<?php if ($this->_vars['enable_dignitaries'] == 1): ?>
			<li><a href="dig.php"><?php echo $this->_vars['l_dig']; ?></a></li>
<?php endif; ?>
<?php if ($this->_vars['allow_probes'] == 1): ?>
			<li><a href="probes.php"><?php echo $this->_vars['l_probe']; ?></a></li>
<?php endif; ?>
			<li><a href="defense_report.php"><?php echo $this->_vars['l_sector_def']; ?></a></li>
			<li><a href="sector_notes.php"><?php echo $this->_vars['l_sectornotes']; ?></a></li>
			<li><a href="log.php"><?php echo $this->_vars['l_log']; ?></a></li>
		</ul>
	</li>
	<li><a href="#"><?php echo $this->_vars['l_maps']; ?></a>
		<ul>
			<li><a href="galaxy_map.php"><?php echo $this->_vars['l_map']; ?></a></li>
			<li><a href="galaxy_local.php"><?php echo $this->_vars['l_localmap']; ?></a></li>
<?php if ($this->_vars['galaxy_map_enabled'] == true && $this->_vars['gd_enabled'] == true): ?>
			<li><a href="galaxy_map3d.php"><?php echo $this->_vars['l_3dmap']; ?></a></li>
<?php endif; ?>
		</ul>
	</li>
	<li><a href="#"><?php echo $this->_vars['l_teams']; ?></a>
		<ul>
			<li><a href="teams.php"><?php echo $this->_vars['l_teams']; ?></a></li>
<?php if ($this->_vars['team_id'] != 0): ?>
			<li><a href="team_forum.php?command=showtopics"><?php echo $this->_vars['l_teamforum']; ?> - New:<?php echo $this->_vars['newposts']; ?></a></li>
			<li><a href="team_report.php"><?php echo $this->_vars['l_teamships']; ?></a></li>
			<li><a href="team_defenses.php"><?php echo $this->_vars['l_teamdefenses']; ?></a></li>
			<li><a href="team_defense_report.php"><?php echo $this->_vars['l_teams']; ?> <?php echo $this->_vars['l_sector_def']; ?></a></li>
			<li><a href="team_planets.php"><?php echo $this->_vars['l_teamplanets']; ?></a></li>
			<li><a href="shoutbox_team.php" target="team_shoutbox"><?php echo $this->_vars['l_team_shoutbox']; ?></a></li>
<?php endif; ?>
		</ul>
	</li>
	<li><a href="#"><?php echo $this->_vars['l_messages']; ?></a>
		<ul>
			<li><a href="message_read.php"><?php echo $this->_vars['l_read_msg']; ?></a></li>
			<li><a href="message_send.php"><?php echo $this->_vars['l_send_msg']; ?></a></li>
			<li><a href="messageblockmanager.php"><?php echo $this->_vars['l_block_msg']; ?></a></li>
			<li><a href="main.php?lobby_mode=start"><?php echo $this->_vars['l_lobby']; ?></a></li>
		</ul>
	</li>
	<li><a href="options.php"><?php echo $this->_vars['l_options']; ?></a>
		<ul>
			<li><a href="options.php"><?php echo $this->_vars['l_options']; ?></a></li>
			<li><a href="self_destruct.php"><?php echo $this->_vars['l_ohno']; ?></a></li>
		</ul>
	</li>
	<li><a href="#"><?php echo $this->_vars['l_help']; ?></a>
		<ul>
			<li><a href="#"><?php echo $this->_vars['l_help_title']; ?> #1</a>
				<ul>
					<li><a href="#"><?php echo $this->_vars['l_help_subtitle']; ?></a></li>
					<li><a href="#"></a></li>
					<li><a href="#">a = <?php echo $this->_vars['l_help_addtraderoute']; ?></a></li>
					<li><a href="#">b = <?php echo $this->_vars['l_help_globalchat']; ?></a></li>
					<li><a href="#">B = <?php echo $this->_vars['l_help_beacon']; ?></a></li>
					<li><a href="#">c = <?php echo $this->_vars['l_help_genesisdevice']; ?></a></li>
					<li><a href="#">C = <?php echo $this->_vars['l_help_sectorgenesis']; ?></a></li>
					<li><a href="#">D = <?php echo $this->_vars['l_help_devicemenu']; ?></a></li>
					<li><a href="#">d = <?php echo $this->_vars['l_help_SDreport']; ?></a></li>
					<li><a href="#">e = <?php echo $this->_vars['l_help_Ewarp']; ?></a></li>
					<li><a href="#">f = <?php echo $this->_vars['l_help_fullLRscan']; ?></a></li>
					<li><a href="#">g = <?php echo $this->_vars['l_help_galaxymap']; ?></a></li>
					<li><a href="#">G = <?php echo $this->_vars['l_help_localmap']; ?></a></li>
				</ul>
			</li>
			<li><a href="#"><?php echo $this->_vars['l_help_title']; ?> #2</a>
				<ul>
					<li><a href="#"><?php echo $this->_vars['l_help_subtitle']; ?></a></li>
					<li><a href="#"></a></li>
					<li><a href="#">i = <?php echo $this->_vars['l_help_IGB']; ?></a></li>
					<li><a href="#">l = <?php echo $this->_vars['l_help_log']; ?></a></li>
					<li><a href="#">L = <?php echo $this->_vars['l_help_logout']; ?></a></li>
					<li><a href="#">m = <?php echo $this->_vars['l_help_readmessages']; ?></a></li>
					<li><a href="#">M = <?php echo $this->_vars['l_help_deploymines']; ?></a></li>
					<li><a href="#">n = <?php echo $this->_vars['l_help_news']; ?></a></li>
					<li><a href="#">N = <?php echo $this->_vars['l_help_sectornotes']; ?></a></li>
					<li><a href="#">o = <?php echo $this->_vars['l_help_options']; ?></a></li>
					<li><a href="#">p = <?php echo $this->_vars['l_help_planetreport']; ?></a></li>
					<li><a href="#">P = <?php echo $this->_vars['l_help_probemenu']; ?></a></li>
					<li><a href="#">r = <?php echo $this->_vars['l_help_ranking']; ?></a></li>
				</ul>
			</li>
			<li><a href="#"><?php echo $this->_vars['l_help_title']; ?> #3</a>
				<ul>
					<li><a href="#"><?php echo $this->_vars['l_help_subtitle']; ?></a></li>
					<li><a href="#"></a></li>
					<li><a href="#">R = <?php echo $this->_vars['l_help_shipreport']; ?></a></li>
					<li><a href="#">s = <?php echo $this->_vars['l_help_sendmessage']; ?></a></li>
					<li><a href="#">t = <?php echo $this->_vars['l_help_listTRroutes']; ?></a></li>
					<li><a href="#">T = <?php echo $this->_vars['l_help_teamSD']; ?></a></li>
					<li><a href="#">u = <?php echo $this->_vars['l_help_3Dmap']; ?></a></li>
					<li><a href="#">w = <?php echo $this->_vars['l_help_warpeditor']; ?></a></li>
					<li><a href="#">z = <?php echo $this->_vars['l_help_storeshipreport']; ?></a></li>
					<li><a href="#">[ = <?php echo $this->_vars['l_help_dignitarymenu']; ?></a></li>
					<li><a href="#">] = <?php echo $this->_vars['l_help_spymenu']; ?></a></li>
					<li><a href="#">. = <?php echo $this->_vars['l_help_galaxylocalwindow']; ?></a></li>
				</ul>
			</li>
			<li><a href="feedback.php" target="_blank"><?php echo $this->_vars['l_feedback']; ?></a></li>
			<li><a href="<?php echo $this->_vars['forum_link']; ?>" target="_blank""><?php echo $this->_vars['l_forums']; ?></a></li>
			<li><a href="http://www.aatraders.com" target="_blank">$l_profiles</a></li>
		</ul>
	</li>
<?php if ($this->_vars['newcommands'] != 0): ?>
	<li><a href="#"><?php echo $this->_vars['l_commands']; ?></a>
		<ul>
			<?php for($for1 = 0; ((0 < $this->_vars['newcommands']) ? ($for1 < $this->_vars['newcommands']) : ($for1 > $this->_vars['newcommands'])); $for1 += ((0 < $this->_vars['newcommands']) ? 1 : -1)):  $this->assign('current', $for1); ?>
				<li><a href="<?php echo $this->_vars['newcommandlink'][$this->_vars['current']]; ?>"><?php echo $this->_vars['newcommandname'][$this->_vars['current']]; ?></a></li>
			<?php endfor; ?>
		</ul>
	</li>
<?php endif; ?>
<?php if ($this->_vars['tournament_mode'] == 0): ?>
	<li><a href="logout.php"><?php echo $this->_vars['l_logout']; ?></a>
		<ul>
			<li><a href="logout.php"><?php echo $this->_vars['l_logout']; ?></a></li>
		</ul>
	</li>
<?php endif; ?>
</ul>
</div>
</td>
<?php extract($this->_vars, EXTR_REFS);  
function strip_places($itemin){

$places = explode(",", $itemin);
if (count($places) <= 1){
	return $itemin;
}
else
{
	$places[1] = AAT_substr($places[1], 0, 2);
	$placecount=count($places);

	switch ($placecount){
		case 2:
			return "$places[0].$places[1] K";
			break;
		case 3:
			return "$places[0].$places[1] M";
			break;	
		case 4:
			return "$places[0].$places[1] B";
			break;	
		case 5:
			return "$places[0].$places[1] T";
			break;
		case 6:
			return "$places[0].$places[1] Qd";
			break;		
		case 7:
			return "$places[0].$places[1] Qn";
			break;
		case 8:
			return "$places[0].$places[1] Sx";
			break;
		case 9:
			return "$places[0].$places[1] Sp";
			break;
		case 10:
			return "$places[0].$places[1] Oc";
			break;
		}		
	
}

}
 ?>

    <td bgcolor="3A3A3A" valign="middle" align="right"><?php echo $this->_vars['l_shiptype']; ?>:<a href="report.php"><b><?php echo $this->_vars['classname']; ?></b></a></td>
    <td bgcolor="3A3A3A"></td>
	
	
  </tr>

</table>
<table width="100%" cellpadding=0 cellspacing=0 border=0 align=center>

<tr>
    <td width="31" height="15" ><img src="templates/default_menu_classic/images/topbar-ll.gif" width="31" height="15"></td>
    <td background="templates/default_menu_classic/images/topbar-low-bg.gif" colspan="3">&nbsp;</td>
    <td width="12" height="15"><img src="templates/default_menu_classic/images/topbar-lr.gif" width="12" height="15"></td>
  </tr>
</table>
<div style="background: no-repeat top  right url(templates/default_menu_classic/images/<?php echo $this->_vars['startypes']; ?>.gif) ;vertical-align: top; text-align: left; /*border: 1px solid white;*/">
<table width="100%" cellpadding=0 cellspacing=0 border=0 align=center>
<tr>
<td>&nbsp;</td>
<td>
<font color="silver" size=2 face="arial">&nbsp;<?php if ($this->_vars['sg_sector']): ?>
SG&nbsp;
<?php endif;  echo $this->_vars['l_sector']; ?>: </font><font color="white"><b><?php echo $this->_vars['sector']; ?></b></font><br>
<?php echo $this->_vars['l_planetmax']; ?> <b><?php echo $this->_vars['starsize']; ?></b><br><span class=mnu><?php echo $this->_vars['ship_coordinates']; ?></span>
</td><td align=center>
<font color="white" size="2" face="arial"><b><?php echo $this->_vars['galaxy_name'];  if ($this->_vars['beacon'] != ""): ?><br><?php echo $this->_vars['beacon'];  endif; ?></b></font>
</td><td align=right>
<a href="zoneinfo.php"><b><font size=2 face="arial"><?php echo $this->_vars['zonename']; ?></font></b></a>&nbsp;</td>
<td>&nbsp;</td>
</tr>
</table>
<table width="100%" border=0 align=center cellpadding=0 cellspacing=0>

<tr>
<td valign=top>

<table border="0" cellpadding="0" cellspacing="0" align="left"><tr valign="top">
<td>
<tr><td>
<table width="195" border="0" cellspacing="0" cellpadding="0" align="left">
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-lt1.gif" width="23" height="13"></td>
    <td align="right" background="templates/default_menu_classic/images/b-tbar-bg.gif"><img src="templates/default_menu_classic/images/b-tbar-cnt.gif" width="143" height="13"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rt.gif" width="29" height="13"></td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-ls.gif" width="23" height="21"></td>
    <td bgcolor="#000000"><img src="templates/master_template/images/spacer.gif" width="143" height="21"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rs.gif" width="29" height="21"></td>
  </tr>
  <tr>
    <td background="templates/default_menu_classic/images/b-lbar-bg.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center"><table cellspacing = "0" cellpadding = "0" border = "0"><TR align="center"><TD NOWRAP>
<?php if ($this->_vars['avatar'] != "default_avatar.gif"): ?>
<p align="center"><img src="images/avatars/<?php echo $this->_vars['avatar']; ?>"></p>
		<?php endif; ?>
</td></tr>
<tr><td class=normal><?php echo $this->_vars['l_rank']; ?>: <img src="templates/default_menu_classic/images/rank/<?php echo $this->_vars['insignia']; ?>"></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_name']; ?>: <span class=mnu><?php echo $this->_vars['player_name']; ?></font></span></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_ship']; ?> <?php echo $this->_vars['l_name']; ?>:<span class=mnu><a href="report.php"><?php echo $this->_vars['shipname']; ?></a></span></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_shiptype']; ?>:<span class=mnu><?php echo $this->_vars['classname']; ?></span></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_turns_have']; ?><span class=mnu><?php echo $this->_vars['turns']; ?></span></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_turns_used']; ?><span class=mnu><?php echo $this->_vars['turnsused']; ?></span></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_score']; ?><span class=mnu><?php extract($this->_vars, EXTR_REFS);  
echo strip_places($score);
 ?>
</span></td></tr>
<tr><td class=normal><?php echo $this->_vars['l_home_planet']; ?>: <span class=mnu><?php echo $this->_vars['home_planet_name']; ?></span></td></tr>
</table>
</td>
    <td background="templates/default_menu_classic/images/b-rbar.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-bar-ls_01.gif" width="23" height="12"></td>
    <td background="templates/default_menu_classic/images/b-bar-bg.gif"></td>
    <td><img src="templates/default_menu_classic/images/b-bar-rs_03.gif" width="29" height="12"></td>
  </tr>
</table>
</td></tr>
<tr><td><br>

		
<table width="195" border="0" cellspacing="0" cellpadding="0" align="left">
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-lt1.gif" width="23" height="13"></td>
    <td align="right" background="templates/default_menu_classic/images/b-tbar-bg.gif"><img src="templates/default_menu_classic/images/b-tbar-cnt.gif" width="143" height="13"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rt.gif" width="29" height="13"></td>
  </tr>

  <tr>
    <td background="templates/default_menu_classic/images/b-lbar-bg.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center"><table cellspacing = "0" cellpadding = "0" border = "0"><TR align="center"><TD NOWRAP><img src="templates/master_template/images/spacer.gif" width="165" height="1">
<table border="0" cellspacing="0" cellpadding="0" align="left">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" width="100%" ><table cellspacing = "0" cellpadding = "0" border = "0" width="100%" >
<tr><td align="left" colspan=2><span class=mnu>&nbsp;&nbsp;&nbsp;<?php echo $this->_vars['l_cargo']; ?></span><br><br></td></tr>
<?php if ($this->_vars['cargo_items'] > 0): ?>
<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $cargo_items; $i++)
	{
		if ($cargo_amount[$i] != "0")
		{
			echo "<tr><td width=\"50%\" nowrap align='left' class=normal><img height=12 width=12 alt=\"$cargo_name[$i]\" src=\"images/ports/" . $cargo_name[$i] . ".png\">&nbsp;" . ucfirst($cargo_name[$i]) . "</td><td width=\"50%\" nowrap align='right'><span class=mnu>&nbsp;";
            echo strip_places($cargo_amount[$i]);
			
			echo "</span></td></tr>";
		}
	}
 ?>
<?php endif; ?>

<?php if ($this->_vars['shipinfo_energy'] != "0"): ?>
<tr><td width="50%" nowrap align='left' class=normal><img height=12 width=12 alt="<?php echo $this->_vars['l_energy']; ?>" src="templates/default_menu_classic/images/energy.png">&nbsp;<?php echo $this->_vars['l_energy']; ?></td><td width="50%" nowrap align='right'><span class=mnu>&nbsp;
<?php extract($this->_vars, EXTR_REFS);  
echo strip_places($shipinfo_energy);
 ?>
</span></td></tr>
<?php endif; ?>

<?php if ($this->_vars['shipinfo_fighters'] != "0"): ?>
<tr><td width="50%" nowrap align='left' class=normal><img height=12 width=12 alt="<?php echo $this->_vars['l_fighters']; ?>" src="templates/default_menu_classic/images/tfighter.png">&nbsp;<a href=defense_deploy.php><?php echo $this->_vars['l_fighters']; ?></a></td><td width="50%" nowrap align='right'><span class=mnu>&nbsp;
<?php extract($this->_vars, EXTR_REFS);  
echo strip_places($shipinfo_fighters);
 ?>
</span></td></tr>
<?php endif; ?>

<?php if ($this->_vars['shipinfo_torps'] != "0"): ?>
<tr><td width="50%" nowrap align='left' class=normal><img height=12 width=12 alt="<?php echo $this->_vars['l_torps']; ?>" src="templates/default_menu_classic/images/torp.png">&nbsp;<a href=defense_deploy.php><?php echo $this->_vars['l_torps']; ?></a></td><td width="50%" nowrap align='right'><span class=mnu>&nbsp;
<?php extract($this->_vars, EXTR_REFS);  
echo strip_places($shipinfo_torps);
 ?>
</span></td></tr>
<?php endif; ?>

<?php if ($this->_vars['shipinfo_armor'] != "0"): ?>
<tr><td width="50%" nowrap align='left' class=normal><img height=12 width=12 alt="<?php echo $this->_vars['l_armorpts']; ?>" src="templates/default_menu_classic/images/armor.png">&nbsp;<?php echo $this->_vars['l_armor']; ?></td><td width="50%" nowrap align='right'><span class=mnu>&nbsp;
<?php extract($this->_vars, EXTR_REFS);  
echo strip_places($shipinfo_armor);
 ?>
</span></td></tr>
<?php endif; ?>

<tr><td width="50%" nowrap align='left' class=normal><img height=12 width=12 alt="<?php echo $this->_vars['l_credits']; ?>" src="templates/default_menu_classic/images/credits.png">&nbsp;<?php echo $this->_vars['l_credits']; ?></td><td width="50%" nowrap align='right' colspan=2><span class=mnu>&nbsp;
<?php extract($this->_vars, EXTR_REFS);  
echo strip_places($playerinfo_credits);
 ?>
</span></td></tr>
	
	</td></tr></table>
</td>
  </tr>
</table>



</td></tr></table>
</td>
    <td background="templates/default_menu_classic/images/b-rbar.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-bar-ls_01.gif" width="23" height="12"></td>
    <td background="templates/default_menu_classic/images/b-bar-bg.gif"></td>
    <td><img src="templates/default_menu_classic/images/b-bar-rs_03.gif" width="29" height="12"></td>
  </tr>
</table>
</td></tr>
<tr><td><br>
				
<table width="195" border="0" cellspacing="0" cellpadding="0" align="left">
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-lt1.gif" width="23" height="13"></td>
    <td align="right" background="templates/default_menu_classic/images/b-tbar-bg.gif"><img src="templates/default_menu_classic/images/b-tbar-cnt.gif" width="143" height="13"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rt.gif" width="29" height="13"></td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-ls.gif" width="23" height="21"></td>
    <td bgcolor="#000000"><img src="templates/default_menu_classic/images/b-tbar-tr-title.gif" width="143" height="21"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rs.gif" width="29" height="21"></td>
  </tr>
  <tr>
    <td background="templates/default_menu_classic/images/b-lbar-bg.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center"><table cellspacing = "0" cellpadding = "0" border = "0"><TR align="center"><TD NOWRAP>

<?php if ($this->_vars['num_traderoutes'] == 0): ?>
<TR><TD NOWRAP>
<div class=mnu><center><div class=dis>&nbsp;<?php echo $this->_vars['l_none']; ?> &nbsp;</div></center><br>
</div>
</td></tr>
<?php elseif ($this->_vars['num_traderoutes'] == 1): ?>
<?php extract($this->_vars, EXTR_REFS);  
echo "<tr><td class=\"nav_title_12\">&nbsp;<a class=mnu href=traderoute_engage.php?engage=" . $traderoute_links[0] . ">" . $traderoute_display[0] . "</a><br>&nbsp;</td><tr>";
 ?>
<?php else: ?>
<?php extract($this->_vars, EXTR_REFS);  
	echo "<tr><td class=\"nav_title_12\" align=center>\n";
	echo "<form name=\"traderoutes\"><select name=\"menu\" onChange=\"location=document.traderoutes.menu.options[document.traderoutes.menu.selectedIndex].value;\" value=\"GO\" class=\"rsform\"><option value=\"\">Select Traderoute</option>\n";
	for($i = 0; $i < count($traderoute_links); $i++){
		echo "<option value=\"traderoute_engage.php?engage=" . $traderoute_links[$i] . "\">$traderoute_display[$i]</option>\n";
	}
	echo "</select></form>";
	echo "</td></tr>\n";
 ?>

<?php endif; ?>
<tr><td nowrap align="center">
<div class=mnu>
[<a class=mnu href=traderoute_create.php><?php echo $this->_vars['l_add']; ?></a>]&nbsp;&nbsp;<a class=mnu href=traderoute_listroutes.php><?php echo $this->_vars['l_trade_control']; ?></a>&nbsp;<br>

</div></td></tr></table>
</td>
    <td background="templates/default_menu_classic/images/b-rbar.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-bar-ls_01.gif" width="23" height="12"></td>
    <td background="templates/default_menu_classic/images/b-bar-bg.gif"></td>
    <td><img src="templates/default_menu_classic/images/b-bar-rs_03.gif" width="29" height="12"></td>
  </tr>
</table>
</td></tr>

<tr><td><br><table  border="0" cellspacing="0" cellpadding="0" align="left">
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-lt1.gif" width="23" height="13"></td>
    <td align="right" background="templates/default_menu_classic/images/b-tbar-bg.gif"><img src="templates/default_menu_classic/images/b-tbar-cnt.gif" width="143" height="13"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rt.gif" width="29" height="13"></td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-ls.gif" width="23" height="21"></td>
    <td bgcolor="#000000"><img src="templates/default_menu_classic/images/b-tbar-sbtitle.gif" width="143" height="21"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rs.gif" width="29" height="21"></td>
  </tr>
  <tr>
    <td background="templates/default_menu_classic/images/b-lbar-bg.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center"><table cellpadding="0" align="left" cellspacing="0"><tr></tr>
	<form method="post" action="shoutbox_save.php">
	<input type="Hidden" name="" value="1"><td NOWRAP class="shoutform">
	<textarea class="shoutform" wrap cols="26" rows="3"><?php echo $this->_vars['quickshout']; ?></textarea><br>
	<input type="Text" name="sbt"  class="shoutform" size="20" maxlength="250" ONBLUR="document.onkeypress = getKey;" ONFOCUS="document.onkeypress = null;" ><input type="submit" name="go" value="Go" class="shoutform"><br><?php echo $this->_vars['l_public']; ?>&nbsp;
	<input type="Hidden" name="returntomain" value="1">
<?php if ($this->_vars['team_id'] > 0): ?>
	<INPUT TYPE=CHECKBOX NAME=SBPB class="shoutform" >
<?php else: ?>
	<INPUT TYPE=CHECKBOX NAME=SBPB class="shoutform" checked>
<?php endif; ?>
</td></form></tr></table>
	</td>
    <td background="templates/default_menu_classic/images/b-rbar.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-bar-ls_01.gif" width="23" height="12"></td>
    <td background="templates/default_menu_classic/images/b-bar-bg.gif"></td>
    <td><img src="templates/default_menu_classic/images/b-bar-rs_03.gif" width="29" height="12"></td>
  </tr>
</table>
</td></tr>

</table>
</td>

<td valign=top align="center">
&nbsp;<br>

<center><font size=3 face="arial" color="white"><b><?php echo $this->_vars['l_tradingport']; ?>:</b></font></center>
<table border=0 width="100%" align="center">
<tr align="center"><td>
<a href=port.php><img src="images/ports/port_<?php echo $this->_vars['port_type']; ?>.gif" border="0" alt="<?php echo $this->_vars['port_type']; ?> port" onMouseover="ddrivetip('<?php echo $this->_vars['portname']; ?>','<?php echo $this->_vars['port_description']; ?>');" onMouseout="hideddrivetip()"><br></a><?php echo $this->_vars['portname']; ?>
</td>
	<?php if ($this->_vars['sector_location'] == 1): ?>
		<td><a href="casino.php?casinogame=casino_forums"><img src="images/ports/port_fedinfo.gif" border="0" alt="" onMouseover="ddrivetip('<?php echo $this->_vars['l_fedinfo']; ?>','<?php echo $this->_vars['l_infoport_description']; ?>');" onMouseout="hideddrivetip()"></a><br><br><b><font color=#33ff00><?php echo $this->_vars['l_fedinfo']; ?></font></b></td>
	<?php endif; ?>
</tr>
</table>

<center><b><font size=3 face="arial" color="white"><?php echo $this->_vars['l_planet_in_sec']; ?> <?php echo $this->_vars['sector']; ?>:</font></b></center>
<table border=0 width="100%" align="center">
<tr align="center">

<?php if ($this->_vars['countplanet'] != 0): ?>
<?php for($for1 = 0; ((0 < $this->_vars['countplanet']) ? ($for1 < $this->_vars['countplanet']) : ($for1 > $this->_vars['countplanet'])); $for1 += ((0 < $this->_vars['countplanet']) ? 1 : -1)):  $this->assign('i', $for1); ?>
	<td align=center valign=top>
	<A HREF=planet.php?planet_id=<?php echo $this->_vars['planetid'][$this->_vars['i']]; ?>>
	<?php echo $this->_run_insert(array('name' => "img", 'src' => "templates/default_menu_classic/images/planet" . $this->_vars['planetimg'][$this->_vars['i']] . ".png", 'alt' => "", 'width' => "100", 'height' => "100")); ?>
	<BR><font size=2 color="white" face="arial">
	<?php echo $this->_vars['planetname'][$this->_vars['i']]; ?>
	<br>(<?php echo $this->_vars['planetowner'][$this->_vars['i']]; ?>)
				<br><?php if ($this->_vars['planetratingnumber'][$this->_vars['i']] == -1): ?>
					<font color="red"><?php echo $this->_vars['planetrating'][$this->_vars['i']]; ?></font>
					<?php elseif ($this->_vars['planetratingnumber'][$this->_vars['i']] == 0): ?>
					<font color="yellow"><?php echo $this->_vars['planetrating'][$this->_vars['i']]; ?></font>
					<?php else: ?>
					<font color="lime"><?php echo $this->_vars['planetrating'][$this->_vars['i']]; ?></font>
					<?php endif; ?>
	</font></td>
<?php endfor; ?>
<?php else: ?>
		<td valign=top><font color="white" size=2><?php echo $this->_vars['l_none']; ?></font></td>
<?php endif; ?>

</tr>
</table>

<center><b><font size=3 face="arial" color="white"><br><?php echo $this->_vars['l_ships_in_sec']; ?> <?php echo $this->_vars['sector']; ?>:</font><br></b></center>
<table border=0 width="100%">
<tr align="center">

	<?php if ($this->_vars['sector_location'] != 1): ?>
		<?php if ($this->_vars['playercount'] != 0): ?>
			<?php for($for1 = 0; ((0 < $this->_vars['playercount']) ? ($for1 < $this->_vars['playercount']) : ($for1 > $this->_vars['playercount'])); $for1 += ((0 < $this->_vars['playercount']) ? 1 : -1)):  $this->assign('myLoop', $for1); ?>
   				<?php if ($this->_vars['shipprobe'][$this->_vars['myLoop']] == "ship"): ?>
					<td align=center valign=top class=nav_title_12>
					<a href="ship.php?player_id=<?php echo $this->_vars['player_id'][$this->_vars['myLoop']]; ?>&ship_id=<?php echo $this->_vars['ship_id'][$this->_vars['myLoop']]; ?>">
					<img src="templates/default_menu_classic/images/<?php echo $this->_vars['shipimage'][$this->_vars['myLoop']]; ?>.gif" border=0></a><BR>
					<?php echo $this->_vars['shipnames'][$this->_vars['myLoop']]; ?>
					<br><b>(<font color=cyan><?php echo $this->_vars['playername'][$this->_vars['myLoop']]; ?></font>)</b>
					<?php if ($this->_vars['teamname'][$this->_vars['myLoop']] != ""): ?>
						&nbsp;<b>(<font color=#33ff00><?php echo $this->_vars['teamname'][$this->_vars['myLoop']]; ?></font>)</b>
					<?php endif; ?>
					<br>
					<?php if ($this->_vars['shipratingnumber'][$this->_vars['myLoop']] == -1): ?>
						<font color="red"><?php echo $this->_vars['shiprating'][$this->_vars['myLoop']]; ?></font>
					<?php elseif ($this->_vars['shipratingnumber'][$this->_vars['myLoop']] == 0): ?>
						<font color="yellow"><?php echo $this->_vars['shiprating'][$this->_vars['myLoop']]; ?></font>
					<?php else: ?>
						<font color="lime"><?php echo $this->_vars['shiprating'][$this->_vars['myLoop']]; ?></font>
					<?php endif; ?>
					</td>
				<?php endif; ?>
   				<?php if ($this->_vars['shipprobe'][$this->_vars['myLoop']] == "probe"): ?>
					<td align=center valign=top class=nav_title_12>
					<a href="probes_upgrade.php?probe_id=<?php echo $this->_vars['player_id'][$this->_vars['myLoop']]; ?>">
					<img src="templates/default_menu_classic/images/<?php echo $this->_vars['shipimage'][$this->_vars['myLoop']]; ?>.gif" border=0></a><BR>
					<?php if ($this->_vars['shipnames'][$this->_vars['myLoop']] != ""): ?>
						<?php echo $this->_vars['shipnames'][$this->_vars['myLoop']]; ?>
					<?php endif; ?>
					<br><b>(<font color=cyan><?php echo $this->_vars['playername'][$this->_vars['myLoop']]; ?></font>)</b>
					<?php if ($this->_vars['teamname'][$this->_vars['myLoop']] != ""): ?>
						&nbsp;<b>(<font color=#33ff00><?php echo $this->_vars['teamname'][$this->_vars['myLoop']]; ?></font>)</b>
					<?php endif; ?>
					</td>
				<?php endif; ?>
   				<?php if ($this->_vars['shipprobe'][$this->_vars['myLoop']] == "debris"): ?>
					<td align=center valign=top class=nav_title_12>
					<a href="showdebris.php?debris_id=<?php echo $this->_vars['player_id'][$this->_vars['myLoop']]; ?>">
					<img src="templates/default_menu_classic/images/<?php echo $this->_vars['shipimage'][$this->_vars['myLoop']]; ?>.gif" border=0></a><BR>
					<br><b>(<font color=#33ff00><?php echo $this->_vars['playername'][$this->_vars['myLoop']]; ?></font>)</b>
					</td>
				<?php endif; ?>
   				<?php if ($this->_vars['shipprobe'][$this->_vars['myLoop']] == "artifact"): ?>
					<td align=center valign=top class=nav_title_12>
					<a href="artifact_grab.php?artifact_id=<?php echo $this->_vars['player_id'][$this->_vars['myLoop']]; ?>" onMouseover="ddrivetip('<?php echo $this->_vars['playername'][$this->_vars['myLoop']]; ?>','<?php echo $this->_vars['artifact_description'][$this->_vars['myLoop']]; ?>');" onMouseout="hideddrivetip()">
					<img src="images/artifacts/<?php echo $this->_vars['shipimage'][$this->_vars['myLoop']]; ?>.gif" border=0></a><BR>
					<br><b>(<font color=#33ff00><?php echo $this->_vars['playername'][$this->_vars['myLoop']]; ?></font>)</b>
					</td>
				<?php endif; ?>

				<?php if ($this->_vars['myLoop'] == 4 || $this->_vars['myLoop'] == 9 || $this->_vars['myLoop'] == 14 || $this->_vars['myLoop'] == 19 || $this->_vars['myLoop'] == 2): ?>
					</tr></table><table border=0 width="100%"><tr>
				<?php endif; ?>
			<?php endfor; ?>
		<?php endif; ?>
	<?php else: ?>
		<td valign=top align=center class=nav_title_12><b><?php echo $this->_vars['l_sector_0']; ?></b></td>
	<?php endif; ?>

</tr>
</table>

<?php if ($this->_vars['sectorzero'] != 1): ?>
<table border=0 width="100%">
<tr>
	<?php if ($this->_vars['lss_sensorlevel'] == 0): ?>
		<td valign="top" align="center"><b><font size=3 face="arial" color="white"><?php echo $this->_vars['l_lss']; ?>:</font></b><br><span class=mnu><font color=#33ff00><?php echo $this->_vars['lss_playername']; ?></font></span></td>
	<?php endif; ?>
	<?php if ($this->_vars['lss_sensorlevel'] == 3): ?>
		<td valign="top" align="center"><b><font size=3 face="arial" color="white"><?php echo $this->_vars['l_lss']; ?>:</font></b><br><span class=mnu><font color=cyan><?php echo $this->_vars['lss_playername']; ?></font>(<font color=#33ff00><?php echo $this->_vars['lss_shipclass']; ?></font>) <font color=#52ACEA><?php echo $this->_vars['l_traveled']; ?></font> <font color=yellow><a class="mnu" href="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['lss_destination'], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lss_destination']; ?></a></font></span></td>
	<?php endif; ?>
	<?php if ($this->_vars['lss_sensorlevel'] == 2): ?>
		<td valign="top" align="center"><b><font size=3 face="arial" color="white"><?php echo $this->_vars['l_lss']; ?>:</font></b><br><span class=mnu><font color=cyan><?php echo $this->_vars['lss_playername']; ?></font>(<font color=#33ff00><?php echo $this->_vars['lss_shipclass']; ?></font>)</span></td>
	<?php endif; ?>
	<?php if ($this->_vars['lss_sensorlevel'] == 1): ?>
		<td valign="top" align="center"><b><font size=3 face="arial" color="white"><?php echo $this->_vars['l_lss']; ?>:</font></b><br><span class=mnu><font color=cyan><?php echo $this->_vars['lss_playername']; ?></font>(<font color=#33ff00><?php echo $this->_vars['lss_shipclass']; ?></font>)</span></td>
	<?php endif; ?>
</tr>
</table>
<?php endif; ?>

<center><b><font size=3 face="arial" color="white"><br><br><?php echo $this->_vars['l_sector_def']; ?>:</font><br></b></center>
<table border=0 width="100%"><tr>
<?php extract($this->_vars, EXTR_REFS);  
	$count = 0;
	for($i = 0; $i < $defensecount; $i++){
		if($defensetype[$i] == "fighters"){
			if($count == 0){
				echo "<td align=center valign=top><img src=templates/default_menu_classic/images/fighters.gif><br>";
			}
			echo "<font class=normal>";
			echo "<a class=mnu href=defense_modify.php?defense_id=" . $defenseid[$i] . ">";
			echo $defplayername[$i];
			echo "</a><br>";
			echo " (<font color=yellow>".strip_places($defenseqty[$i])."</font> <font color=#33ff00>$defensemode[$i]</font>)";
			echo "</font><br>";

			if ($sdratingnumber[$i] == -1)
			{
				echo "<font color=\"red\">$sdrating[$i]</font><br>";
			}
			else if ($sdratingnumber[$i] == 0)
			{
				echo "<font color=\"yellow\">$sdrating[$i]</font><br>";
			}
			else
			{
				echo "<font color=\"lime\">$sdrating[$i]</font><br>";
			}

			$count++;
		}
	}
	if($count != 0)
		echo "</td>";
 ?>
<?php extract($this->_vars, EXTR_REFS);  
	$count = 0;
	for($i = 0; $i < $defensecount; $i++){
		if($defensetype[$i] == "mines"){
			if($count == 0){
				echo "<td align=center valign=top><img src=templates/default_menu_classic/images/mines.gif><br>";
			}
			echo " <font class=normal>";
			echo "<a class=mnu href=defense_modify.php?defense_id=" . $defenseid[$i] . ">";
			echo $defplayername[$i];
			echo "</a><br>";
			echo " (<font color=yellow>".strip_places($defenseqty[$i])."</font> <font color=#33ff00>$defensemode[$i]</font>)";
			echo "</font><br>";

			if ($sdratingnumber[$i] == -1)
			{
				echo "<font color=\"red\">$sdrating[$i]</font><br>";
			}
			else if ($sdratingnumber[$i] == 0)
			{
				echo "<font color=\"yellow\">$sdrating[$i]</font><br>";
			}
			else
			{
				echo "<font color=\"lime\">$sdrating[$i]</font><br>";
			}

			$count++;
		}
	}
	if($count != 0)
		echo "</td>";

 ?>


</tr></table>
<td valign=top>
<br>
				
				
<table  border="0" cellspacing="0" cellpadding="0" align="right">


<tr><td><table width="195" border="0" cellspacing="0" cellpadding="0" align="right">
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-lt1.gif" width="23" height="13"></td>
    <td align="right" background="templates/default_menu_classic/images/b-tbar-bg.gif"><img src="templates/default_menu_classic/images/b-tbar-cnt.gif" width="143" height="13"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rt.gif" width="29" height="13"></td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-ls.gif" width="23" height="21"></td>
    <td bgcolor="#000000"><img src="templates/default_menu_classic/images/b-tbar-rstitle.gif" width="143" height="21"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rs.gif" width="29" height="21"></td>
  </tr>
  <tr>
    <td background="templates/default_menu_classic/images/b-lbar-bg.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center"><table cellspacing = "0" cellpadding = "0" border = "0"><TR align="center"><TD NOWRAP><div id="ToolTip"></div>
<?php if ($this->_vars['gd_enabled']): ?>
<table align="center"><tr><td align="center" valign="top"><a href="galaxy_map3d.php"><?php extract($this->_vars, EXTR_REFS);  
 $coords = explode("|", $ship_coordinates); 
echo "
<img align=\"middle\" src=\"galaxy_position.php?universe_size=$universe_size&sx=$coords[0]&sy=$coords[1]&sz=$coords[2]\" border=\"0\" >";
 ?></a>

</td></tr></table>
<?php endif; ?>
<table border="0" cellspacing="0" cellpadding="0" align="center"  style="border: thin inset #444444;"><tr><td>
<TABLE border=0 cellpadding=1 cellspacing=0 align=center>
<tr>
<?php if ($this->_vars['xyminusp'][8] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[8]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][8]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][8]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][8]; ?> - <?php echo $this->_vars['altportx3'][8]; ?><br><?php echo $this->_vars['altturnsx3'][8]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][8]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[8]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[8]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][8]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][8]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>
<?php if ($this->_vars['xyminusp'][6] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[6]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][6]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][6]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][6]; ?> - <?php echo $this->_vars['altportx3'][6]; ?><br><?php echo $this->_vars['altturnsx3'][6]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][6]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[6]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[6]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][6]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][6]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>
<?php if ($this->_vars['xyminusp'][4] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[4]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][4]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][4]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][4]; ?> - <?php echo $this->_vars['altportx3'][4]; ?><br><?php echo $this->_vars['altturnsx3'][4]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][4]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[4]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[4]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][4]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][4]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
	<TD bgcolor=black rowspan="3" valign="bottom"><img src="templates/default_menu_classic/images/nav_vert.gif"  border=0 width = "12" height = "36"></td>
<?php if ($this->_vars['xyplus'][4] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[4]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][4]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][4]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][4]; ?> - <?php echo $this->_vars['altportx1'][4]; ?><br><?php echo $this->_vars['altturnsx1'][4]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][4]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[4]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[4]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][4]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][4]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>
<?php if ($this->_vars['xyplus'][6] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[6]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][6]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][6]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][6]; ?> - <?php echo $this->_vars['altportx1'][6]; ?><br><?php echo $this->_vars['altturnsx1'][6]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][6]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[6]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[6]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][6]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][6]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyplus'][8] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[8]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][8]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][8]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][8]; ?> - <?php echo $this->_vars['altportx1'][8]; ?><br><?php echo $this->_vars['altturnsx1'][8]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][8]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[8]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[8]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][8]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][8]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
</tr>
<tr>
<?php if ($this->_vars['xyminusp'][7] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[7]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][7]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][7]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][7]; ?> - <?php echo $this->_vars['altportx3'][7]; ?><br><?php echo $this->_vars['altturnsx3'][7]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][7]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[7]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[7]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][7]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][7]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>
<?php if ($this->_vars['xyminusp'][3] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[3]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][3]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][3]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][3]; ?> - <?php echo $this->_vars['altportx3'][3]; ?><br><?php echo $this->_vars['altturnsx3'][3]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][3]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[3]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[3]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][3]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][3]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyminusp'][1] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[1]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][1]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][1]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][1]; ?> - <?php echo $this->_vars['altportx3'][1]; ?><br><?php echo $this->_vars['altturnsx3'][1]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][1]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[1]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[1]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][1]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][1]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	

<?php if ($this->_vars['xyplus'][1] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[1]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][1]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][1]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][1]; ?> - <?php echo $this->_vars['altportx1'][1]; ?><br><?php echo $this->_vars['altturnsx1'][1]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][1]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[1]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[1]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][1]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][1]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyplus'][3] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[3]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][3]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][3]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][3]; ?> - <?php echo $this->_vars['altportx1'][3]; ?><br><?php echo $this->_vars['altturnsx1'][3]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][3]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[3]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[3]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][3]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][3]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>			
<?php if ($this->_vars['xyplus'][7] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[7]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][7]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][7]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][7]; ?> - <?php echo $this->_vars['altportx1'][7]; ?><br><?php echo $this->_vars['altturnsx1'][7]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][7]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[7]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[7]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][7]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][7]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>			
</tr>
<tr>
<?php if ($this->_vars['xyminusp'][5] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[5]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][5]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][5]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][5]; ?> - <?php echo $this->_vars['altportx3'][5]; ?><br><?php echo $this->_vars['altturnsx3'][5]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][5]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[5]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[5]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][5]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][5]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>
<?php if ($this->_vars['xyminusp'][2] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[2]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][2]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][2]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][2]; ?> - <?php echo $this->_vars['altportx3'][2]; ?><br><?php echo $this->_vars['altturnsx3'][2]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][2]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[2]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[2]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][2]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][2]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyminusp'][0] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx3[0]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx3'][0]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx3'][0]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminusp'][0]; ?> - <?php echo $this->_vars['altportx3'][0]; ?><br><?php echo $this->_vars['altturnsx3'][0]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx3'][0]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx3[0]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx3[0]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex3'][0]; ?>.png" title="<?php echo $this->_vars['sectortitlex3'][0]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	

<?php if ($this->_vars['xyplus'][0] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[0]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][0]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][0]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][0]; ?> - <?php echo $this->_vars['altportx1'][0]; ?><br><?php echo $this->_vars['altturnsx1'][0]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][0]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[0]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[0]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][0]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][0]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
<?php if ($this->_vars['xyplus'][2] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[2]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][2]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][2]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][2]; ?> - <?php echo $this->_vars['altportx1'][2]; ?><br><?php echo $this->_vars['altturnsx1'][2]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][2]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[2]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[2]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][2]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][2]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyplus'][5] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx1[5]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx1'][5]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx1'][5]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplus'][5]; ?> - <?php echo $this->_vars['altportx1'][5]; ?><br><?php echo $this->_vars['altturnsx1'][5]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx1'][5]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx1[5]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx1[5]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex1'][5]; ?>.png" title="<?php echo $this->_vars['sectortitlex1'][5]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
</tr>
<tr bgcolor=black><td colspan="3" valign="middle" align="right"><img src="templates/default_menu_classic/images/nav_horz.gif"  border=0 width = "48" height = "12"></td><td border=1 valign="middle" align="center"><A HREF="#" onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['sector']; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['ship_galacticarm']; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $ship_coordinates); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]" ?>');" onMouseout="hideddrivetip()"><img src="images/ports/yourhere.gif" border="0"></a></td><td colspan="3" align="left" valign="middle"><img src="templates/default_menu_classic/images/nav_horz.gif"  border=0 width = "48" height = "12"></td></tr>
<tr>
<?php if ($this->_vars['xyminus'][4] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[4]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][4]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][4]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][4]; ?> - <?php echo $this->_vars['altportx2'][4]; ?><br><?php echo $this->_vars['altturnsx2'][4]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][4]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[4]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[4]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][4]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][4]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyminus'][2] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[2]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][2]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][2]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][2]; ?> - <?php echo $this->_vars['altportx2'][2]; ?><br><?php echo $this->_vars['altturnsx2'][2]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][2]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[2]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[2]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][2]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][2]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>
<?php if ($this->_vars['xyminus'][0] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[0]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][0]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][0]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][0]; ?> - <?php echo $this->_vars['altportx2'][0]; ?><br><?php echo $this->_vars['altturnsx2'][0]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][0]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[0]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[0]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][0]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][0]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
	<TD bgcolor=black rowspan="3" valign="top"><img src="templates/default_menu_classic/images/nav_vert.gif"  border=0 width = "12" height = "36"></td>
<?php if ($this->_vars['xyplusm'][0] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[0]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][0]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][0]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][0]; ?> - <?php echo $this->_vars['altportx4'][0]; ?><br><?php echo $this->_vars['altturnsx4'][0]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][0]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[0]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[0]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][0]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][0]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
<?php if ($this->_vars['xyplusm'][2] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[2]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][2]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][2]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][2]; ?> - <?php echo $this->_vars['altportx4'][2]; ?><br><?php echo $this->_vars['altturnsx4'][2]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][2]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[2]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[2]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][2]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][2]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
<?php if ($this->_vars['xyplusm'][4] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[4]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][4]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][4]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][4]; ?> - <?php echo $this->_vars['altportx4'][4]; ?><br><?php echo $this->_vars['altturnsx4'][4]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][4]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[4]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[4]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][4]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][4]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
</tr>
<tr>
<?php if ($this->_vars['xyminus'][6] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[6]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][6]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][6]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][6]; ?> - <?php echo $this->_vars['altportx2'][6]; ?><br><?php echo $this->_vars['altturnsx2'][6]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][6]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[6]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[6]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][6]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][6]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyminus'][1] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[1]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][1]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][1]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][1]; ?> - <?php echo $this->_vars['altportx2'][1]; ?><br><?php echo $this->_vars['altturnsx2'][1]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][1]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[1]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[1]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][1]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][1]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	

<?php if ($this->_vars['xyminus'][3] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[3]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][3]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][3]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][3]; ?> - <?php echo $this->_vars['altportx2'][3]; ?><br><?php echo $this->_vars['altturnsx2'][3]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][3]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[3]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[3]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][3]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][3]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		

<?php if ($this->_vars['xyplusm'][3] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[3]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][3]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][3]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][3]; ?> - <?php echo $this->_vars['altportx4'][3]; ?><br><?php echo $this->_vars['altturnsx4'][3]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][3]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[3]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[3]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][3]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][3]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
<?php if ($this->_vars['xyplusm'][1] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[1]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][1]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][1]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][1]; ?> - <?php echo $this->_vars['altportx4'][1]; ?><br><?php echo $this->_vars['altturnsx4'][1]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][1]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[1]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[1]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][1]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][1]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
<?php if ($this->_vars['xyplusm'][6] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[6]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][6]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][6]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][6]; ?> - <?php echo $this->_vars['altportx4'][6]; ?><br><?php echo $this->_vars['altturnsx4'][6]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][6]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[6]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[6]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][6]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][6]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>				
</tr>
<tr>
<?php if ($this->_vars['xyminus'][8] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[8]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][8]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][8]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][8]; ?> - <?php echo $this->_vars['altportx2'][8]; ?><br><?php echo $this->_vars['altturnsx2'][8]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][8]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[8]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[8]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][8]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][8]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
<?php if ($this->_vars['xyminus'][7] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[7]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][7]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][7]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][7]; ?> - <?php echo $this->_vars['altportx2'][7]; ?><br><?php echo $this->_vars['altturnsx2'][7]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][7]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[7]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[7]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][7]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][7]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>		
<?php if ($this->_vars['xyminus'][5] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx2[5]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx2'][5]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx2'][5]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyminus'][5]; ?> - <?php echo $this->_vars['altportx2'][5]; ?><br><?php echo $this->_vars['altturnsx2'][5]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx2'][5]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx2[5]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx2[5]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex2'][5]; ?>.png" title="<?php echo $this->_vars['sectortitlex2'][5]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	

<?php if ($this->_vars['xyplusm'][5] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[5]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][5]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][5]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][5]; ?> - <?php echo $this->_vars['altportx4'][5]; ?><br><?php echo $this->_vars['altturnsx4'][5]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][5]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[5]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[5]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][5]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][5]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	

<?php if ($this->_vars['xyplusm'][7] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[7]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][7]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][7]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][7]; ?> - <?php echo $this->_vars['altportx4'][7]; ?><br><?php echo $this->_vars['altturnsx4'][7]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][7]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[7]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[7]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][7]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][7]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>	
	
<?php if ($this->_vars['xyplusm'][8] != ""): ?>
		<?php extract($this->_vars, EXTR_REFS);  $warp_links = str_replace("|", ", ", $link_listx4[8]); ?>
		<TD bgcolor=<?php echo $this->_vars['sectorzonecolorx4'][8]; ?>><A HREF="javascript:fillrealspace('<?php echo $this->_vars['altsectorx4'][8]; ?>'); " onMouseover="ddrivetip('<?php echo $this->_vars['l_sector']; ?>: <?php echo $this->_vars['xyplusm'][8]; ?> - <?php echo $this->_vars['altportx4'][8]; ?><br><?php echo $this->_vars['altturnsx4'][8]; ?>','<?php echo $this->_vars['l_galacticarm']; ?>: <?php echo $this->_vars['galacticarmx4'][8]; ?><br><br><?php extract($this->_vars, EXTR_REFS);   $coords = explode("|", $nav_scan_coordsx4[8]); echo "X: $coords[0]<br>Y: $coords[1]<br>Z: $coords[2]<br><br>$l_port_buys<br>$buy_listx4[8]<br><br>$l_links:<br>$warp_links<hr>" ?>' + returnmessage);" onMouseout="hideddrivetip()"><img src="images/ports/<?php echo $this->_vars['sectorimagex4'][8]; ?>.png" title="<?php echo $this->_vars['sectortitlex4'][8]; ?>" border=0 width = "12" height = "12"></A></TD>
	<?php else: ?>
		<TD bgcolor="#585858"><img src="templates/master_template/images/spacer.gif"  border=0 width = "12" height = "12"></td>
	<?php endif; ?>				
		
</tr>
		</table>
</td></tr></table><br></td></tr>
<TR align="center"><TD NOWRAP><div class=mnu align=center><?php echo $this->_vars['l_sector']; ?> <?php echo $this->_vars['sector']; ?> <?php echo $this->_vars['l_notes']; ?><br>
<?php extract($this->_vars, EXTR_REFS);  
if ($note_view != 0){
	echo "<a class=dis href=\"sector_notes.php?command=viewnote\">[".$l_view_note."]</a>";
}
echo "<a class=dis href=\"sector_notes.php?command=addnote&sector=".$sector."&sector_planets=".count($planetid)."&sector_port=".$portname."&sector_fighters=".$tmp_fighters."&sector_torps=".$tmp_torps."\">[".$l_add_note."]</a>";
 ?>
<br><br>
</div></td></tr>
<tr><td nowrap=""><div class=mnu>
<TABLE BORDER=0 CELLPADDING=1 CELLSPACING=0 BGCOLOR="#000000" >
<form name="lastsector"><tr><td class="nav_title_12" align=center>
<select name="menu" onChange="location=document.lastsector.menu.options[document.lastsector.menu.selectedIndex].value;" value="GO" class="rsform"><option value=""><?php echo $this->_vars['l_RStolastsector']; ?></option>
<?php if ($this->_vars['lastsectors'][0] != ""): ?>
<option value="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['lastsectors'][0], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lastsectors'][0]; ?>(<?php echo $this->_vars['lastsectorsdist'][0]; ?>)</option>
<?php endif; ?>
<?php if ($this->_vars['lastsectors'][1] != ""): ?>
<option value="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['lastsectors'][1], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lastsectors'][1]; ?>(<?php echo $this->_vars['lastsectorsdist'][1]; ?>)</option>
<?php endif; ?>
<?php if ($this->_vars['lastsectors'][2] != ""): ?>
<option value="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['lastsectors'][2], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lastsectors'][2]; ?>(<?php echo $this->_vars['lastsectorsdist'][2]; ?>)</option>
<?php endif; ?>
<?php if ($this->_vars['lastsectors'][3] != ""): ?>
<option value="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['lastsectors'][3], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lastsectors'][3]; ?>(<?php echo $this->_vars['lastsectorsdist'][3]; ?>)</option>
<?php endif; ?>
<?php if ($this->_vars['lastsectors'][4] != ""): ?>
<option value="main.php?move_method=real&engage=1&destination=<?php echo $this->_run_modifier($this->_vars['lastsectors'][4], 'urlencode', 'PHP', 1); ?>"><?php echo $this->_vars['lastsectors'][4]; ?>(<?php echo $this->_vars['lastsectorsdist'][4]; ?>)</option>
<?php endif; ?>
</select></form></td></tr>

<?php extract($this->_vars, EXTR_REFS);  
	echo "<form name=\"presets\"><tr><td class=\"nav_title_12\" align=center>\n";
	echo "<select  name=\"menu\" onChange=\"location=document.presets.menu.options[document.presets.menu.selectedIndex].value;\" value=\"GO\" class=\"rsform\"><option value=\"\">RS to Sector</option>\n";
	for($i = 0; $i < count($preset_display); $i++){
		echo "<option value=\"main.php?move_method=real&engage=1&amp;destination=" . urlencode($preset_display[$i]) . "\">$preset_display[$i] - $preset_info[$i] ($preset_dist[$i])</option>\n";
	}
	echo "</select></td></tr>\n";
	
 ?>

<tr><td class="nav_title_12" align=center>&nbsp;<a class=dis href="preset.php?name=set">[<?php echo $this->_vars['l_set']; ?>]</a>&nbsp;&nbsp;-&nbsp;&nbsp;<a class=dis href="preset.php?name=add">[<?php echo $this->_vars['l_add']; ?>]</a>&nbsp;</td></tr></form>
<form method="post" action="main.php"><input type="hidden" name="move_method" value="real"><tr><td class="nav_title_12" align=center>

<input type="text" id="destination" name="destination" class="rsform" maxlength="30" size="8" onfocus="document.onkeypress=null" ONBLUR="document.onkeypress = getKey;" ><br>
<input type="button" name="autowarp" value="W" class="rsform" onClick="makeRequest();">
<input type="submit" name="explore" value="&nbsp;?&nbsp;" class="rsform">
<input type="submit" name="go" value="Go" class="rsform">
</td></tr></form>
</table></td></tr></table></td>
    <td background="templates/default_menu_classic/images/b-rbar.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-bar-ls_01.gif" width="23" height="12"></td>
    <td background="templates/default_menu_classic/images/b-bar-bg.gif"></td>
    <td><img src="templates/default_menu_classic/images/b-bar-rs_03.gif" width="29" height="12"></td>
  </tr>
</table>
</td></tr>


<tr><td><br>
<table  border="0" cellspacing="0" cellpadding="0" align="left">
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-lt1.gif" width="23" height="13"></td>
    <td align="right" background="templates/default_menu_classic/images/b-tbar-bg.gif"><img src="templates/default_menu_classic/images/b-tbar-cnt.gif" width="143" height="13"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rt.gif" width="29" height="13"></td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-tbar-ls.gif" width="23" height="21"></td>
    <td bgcolor="#000000"><img src="templates/default_menu_classic/images/b-tbar-wttitle.gif" width="143" height="21"></td>
    <td><img src="templates/default_menu_classic/images/b-tbar-rs.gif" width="29" height="21"></td>
  </tr>
  <tr>
    <td background="templates/default_menu_classic/images/b-lbar-bg.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center"><table cellpadding="0" align="left" cellspacing="0"><tr><td NOWRAP>
<div class=mnu>
<?php extract($this->_vars, EXTR_REFS);  
	if(count($links) == 0)
		echo "<tr><td width=100 class=\"nav_title_12\">&nbsp;<b>$linklist<b>&nbsp;</td></tr>\n";

	for($i = 0; $i < count($links); $i++){
		if($links_zone[$i] == "2")
			$zone_type = "F&gt;";
		else $zone_type = "=&gt;";
		if($sg_sector_linkback == $links[$i])
		{
			$zone_type = "<" . $zone_type;
		}
		if($links_type[$links[$i]] == 1)
			$link_image = "<img src=\"images/ports/" . $links_port_type[$i] . ".png\" border=0 width = \"12\" height = \"12\">";
		else $link_image = "";
		if($links_return[$links[$i]] == 1)
			echo "<tr><td width=100 class=\"nav_title_12\">&nbsp;<a class=\"mnu2\" href=\"main.php?move_method=warp&destination=" . urlencode($links[$i]) . "\">$zone_type&nbsp;$link_image&nbsp;$links[$i]</a>&nbsp;<a class=dis href=\"sector_scan.php?command=scan&sector=" . urlencode($links[$i]) . "\">[$l_scan]</a>&nbsp;</td></tr>\n";
		else echo "<tr><td width=100 class=\"nav_title_12\">&nbsp;<a class=\"mnu\" href=\"main.php?move_method=warp&destination=" . urlencode($links[$i]) . "\">$zone_type&nbsp;$link_image&nbsp;$links[$i]</a>&nbsp;<a class=dis href=\"sector_scan.php?command=scan&sector=" . urlencode($links[$i]) . "\">[$l_scan]</a>&nbsp;</td></tr>\n";
	}
 ?>
</div>
</td></tr>

<tr><td colspan=2 align=center class=dis><a href="long_range_scan.php" class=dis>[<?php echo $this->_vars['l_fullscan']; ?>]</a></td></tr>

<?php if ($this->_vars['autototal'] != 0): ?>
<tr>
<td NOWRAP align="center">
<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=0  align="center">
<?php extract($this->_vars, EXTR_REFS);  
	echo "<tr><td width=100 class=\"nav_title_12\" align=center><br>\n";
	echo "<form name=\"autoroutes\"><select name=\"menu\" onChange=\"location=document.autoroutes.menu.options[document.autoroutes.menu.selectedIndex].value;\" value=\"GO\" class=\"rsform\"><option value=\"\">$l_selectautoroute</option>\n";
	for($i = 0; $i < count($autolist); $i++){
		$sgstart = ($autostartsg[$i] == 0) ? "" : "SG:";
		$sgdest = ($autodestsg[$i] == 0) ? "" : "SG:";

		if($sg_sector < 1 and $autostartsg[$i] < 1)
			echo "<option value=\"navcomp.php?state=start&autoroute_id=$autolist[$i]\">" . (($autoname[$i] == "" || empty($autoname[$i])) ? "$sgstart$autostart[$i]&nbsp;=&gt;&nbsp;$sgdest$autoend[$i]" : "(" . $autoname[$i] . ") $sgstart$autostart[$i]&nbsp;=&gt;&nbsp;$sgdest$autoend[$i]") . "</option>\n";

		if($sg_sector > 0 and $autostart[$i] == $sector)
			echo "<option value=\"navcomp.php?state=start&autoroute_id=$autolist[$i]\">" . (($autoname[$i] == "" || empty($autoname[$i])) ? "$sgdest$autoend[$i]&nbsp;=&gt;&nbsp;$sgstart$autostart[$i]" : "(" . $autoname[$i] . ") $sgdest$autoend[$i]&nbsp;=&gt;&nbsp;$sgstart$autostart[$i]") . "</option>\n";

		if($sg_sector > 0 and (($autostart[$i] - 1) == $sector or ($autostart[$i] + 1) == $sector))
			echo "<option value=\"navcomp.php?state=start&autoroute_id=$autolist[$i]\">" . (($autoname[$i] == "" || empty($autoname[$i])) ? "$sgstart$autostart[$i]&nbsp;=&gt;&nbsp;$sgdest$autoend[$i]" : "(" . $autoname[$i] . ") $sgstart$autostart[$i]&nbsp;=&gt;&nbsp;$sgdest$autoend[$i]") . "</option>\n";
	}
	echo "</select></form>";
	echo "</td></tr>\n";
 ?>

</td></tr>
</table>
<?php endif; ?></td></tr></table>
	</td>
    <td background="templates/default_menu_classic/images/b-rbar.gif">&nbsp;</td>
  </tr>
  <tr>
    <td><img src="templates/default_menu_classic/images/b-bar-ls_01.gif" width="23" height="12"></td>
    <td background="templates/default_menu_classic/images/b-bar-bg.gif"></td>
    <td><img src="templates/default_menu_classic/images/b-bar-rs_03.gif" width="29" height="12"></td>
  </tr>
</table>
</td></tr>

</table>
<center>
				</tr>
				</table>
			
</center>

