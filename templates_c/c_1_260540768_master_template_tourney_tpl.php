<?php if ($this->_vars['new_posts'] > 0): ?> 
	<?php echo '
	<style type="text/css">
	#frame_infoport_message {
		z-index: 850;
		position:absolute;
		left: 50%; 
		top: 25%;
		width: 300px;
		height: 100px;
		margin-top: -75px; /* half of the height */
		margin-left: -100px; /* half of the width */
		height:100px;
	}
	input.instant_infoport_button
	{
		font-family:Arial,sans-serif;
		font-weight:bold;
		color:#FFFFFF;
		background-color:#00CC33;
		border-style:outset;
	}
	</style>

	<script language="javascript">
	function infoportgoLite_message(FRM,BTN)
	{
	window.document.forms[FRM].elements[BTN].style.backgroundColor = "#00FF99";
	window.document.forms[FRM].elements[BTN].style.borderStyle = "inset";
	}

	function infoportgoDim_message(FRM,BTN)
	{
	window.document.forms[FRM].elements[BTN].style.backgroundColor = "#00CC33";
	window.document.forms[FRM].elements[BTN].style.borderStyle = "outset";
	}
	</script>
	'; ?>


	<div id="frame_infoport_message" style="position:absolute;border:10px inset #925725;color:white;background:black;">
	<table border=0 width="100%" align="center">
	<tr>
		<td bgcolor="#528768" width="100%" height="96" align="center" valign="middle">
			<b><?php echo $this->_vars['l_forums_new']; ?> <?php echo $this->_vars['forumname']; ?>
				<hr>
				<?php for($for1 = 0; ((0 < $this->_vars['count']) ? ($for1 < $this->_vars['count']) : ($for1 > $this->_vars['count'])); $for1 += ((0 < $this->_vars['count']) ? 1 : -1)):  $this->assign('current', $for1); ?>
					<?php if ($this->_vars['newpost'][$this->_vars['current']] > 0): ?>
						<a href="infoport.php?topic_id=<?php echo $this->_vars['topicid'][$this->_vars['current']]; ?>#<?php echo $this->_vars['postid'][$this->_vars['current']]; ?>" target="_blank"><?php echo $this->_vars['topictitle'][$this->_vars['current']]; ?></a><br>
					<?php endif; ?>
				<?php endfor; ?>
			<b><br><br>
			<form name="template_change_later">
			<input
				type="button"
				name="instant_infoport_btn1"
				class="instant_infoport_button"
				value="Read Later"
				title="Read Later"
				onMouseOver="infoportgoLite_message(this.form.name,this.name)"
				onMouseOut="infoportgoDim_message(this.form.name,this.name)"
				onClick="frame_infoport_message.style.visibility = 'hidden';"
				>
			</form>
			<br>
		</td>
	</tr>
	</table>
	</div>
<?php endif; ?>


<?php echo '
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
	background-color: #4455aa; /*overall menu background color*/
	z-index: 800; 
}

/*Top level menu link items style*/
.suckertreemenu ul li a{
	display: block;
	width: auto; /*Width of top level menu link items*/
	padding: 3px 15px 3px 10px;
	border: 1px solid #dddddd;
	border-left-width: 1;
	text-decoration: none;
	color: white;
	font-weight: bold;
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
	border: 1px solid #dddddd;
}

.suckertreemenu ul li a:hover{
	background-color: #000000;
	color: white;
}

/*Background image for top level menu list links */
.suckertreemenu .mainfoldericon{
	background: #4455aa url(templates/master_template/images/arrow_down.gif) no-repeat center right;
}

/*Background image for subsequent level menu list links */
.suckertreemenu .subfoldericon{
	background: #4455aa url(templates/master_template/images/arrow_right.gif) no-repeat center right;
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

<script language="javascript" type="text/javascript">
 	function OpenSB()
		{
			f2 = open("shoutbox.php","f2","width=700,height=400,scrollbars=yes");
		}
</script>	
<SCRIPT LANGUAGE="JavaScript1.2" TYPE="text/javascript">
<!--
var delay=1000 //set delay between message change (in miliseconds)
var fcontent=new Array()

'; ?>

<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $shoutcount; $i++) 
		echo "fcontent[$i]=\"<A CLASS=headlines HREF='#' onClick='OpenSB();'>" . $shoutmessage[$i] . "</a>\"\n"; 
 ?>
<?php echo '

var fadescheme=1 //set 0 to fade text color from (white to black), 1 for (black to white)
var fadelinks=1  //should links inside scroller content also fade like text? 0 for no, 1 for yes.

///No need to edit below this line/////////////////

var hex=(fadescheme==0)? 255 : 0
var startcolor=(fadescheme==0)? "rgb(255,255,255)" : "rgb(0,0,0)"
var endcolor=(fadescheme==0)? "rgb(0,0,0)" : "rgb(255,255,255)"

var ie4=document.all&&!document.getElementById
var ns4=document.layers
var DOM2=document.getElementById
var faderdelay=0
var index=0

if (DOM2)
	faderdelay=2000

//function to change content
function changecontent(){
	if (index>=fcontent.length)
		index=0
	if (DOM2){
		document.getElementById("IEshout").style.color=startcolor
		document.getElementById("IEshout").innerHTML=fcontent[index]
		linksobj=document.getElementById("IEshout").getElementsByTagName("A")
		if (fadelinks)
			linkcolorchange(linksobj)
		colorfade()
	}
	else if (ie4)
		document.all.IEshout.innerHTML=fcontent[index]
	else if (ns4){
		document.shout.document.write(fcontent[index])
		document.shout.document.close()
	}
	index++
	setTimeout("changecontent()",delay+faderdelay)
}

// colorfade() partially by Marcio Galli for Netscape Communications.  ////////////
// Modified by Dynamicdrive.com

frame=20;

function linkcolorchange(obj){
	if (obj.length>0){
		for (i=0;i<obj.length;i++)
			obj[i].style.color="rgb("+hex+","+hex+","+hex+")"
	}
}

function colorfade() {	         	
// 20 frames fading process
	if(frame>0) {	
		hex=(fadescheme==0)? hex-12 : hex+12 // increase or decrease color value depd on fadescheme
		document.getElementById("IEshout").style.color="rgb("+hex+","+hex+","+hex+")"; // Set color value.
		if (fadelinks)
			linkcolorchange(linksobj)
		frame--;
		setTimeout("colorfade()",20);	
	}
	else
	{
		document.getElementById("IEshout").style.color=endcolor;
		frame=20;
		hex=(fadescheme==0)? 255 : 0
	}   
}

//-->
</SCRIPT>
'; ?>


<table cellspacing = "0" cellpadding = "0" border = "0" width = "700" align="center">
<tr>
	<td><img src="templates/master_template/images/topnav-left.gif" width="41" height="55"></td>
	<td background="templates/master_template/images/topnav-bg.gif" width="100%" height="55" ID="IEshout" align="center">
<layer id="shout"</layer>
	</td>
	<td><img src="templates/master_template/images/topnav-right.gif" width="22" height="55"></td>
</tr>
</table>

<br>

<table width="700" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width=18><img src = "templates/master_template/images/g-top-left.gif"></td>
		<td width=101><img src = "templates/master_template/images/g-top-midleft.gif"></td>
		<td width="100%"><img src = "templates/master_template/images/g-top-midright.gif" width="100%" height="20"></td>
		<td width=18><img src = "templates/master_template/images/g-top-right.gif"></td>
  </tr>
  <tr>
    <td background="templates/master_template/images/g-mid-left.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center" colspan=2 align="center">


		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%" align="center">
<tr><td align="center">
<div class="suckertreemenu" align="center">
<ul id="treemenu">
	<?php if ($this->_vars['lobby_mode'] == 1): ?>
		<li><a href="main.php?lobby_mode=end"><?php echo $this->_vars['l_main_title']; ?></a>
			<ul>
				<li><a href="main.php?lobby_mode=end"><?php echo $this->_vars['l_main_title']; ?></a></li>
				<li><a href="main.php?lobby_mode=end" target="_blank"><?php echo $this->_vars['l_main_title']; ?> in New Window</a></li>
			</ul>
		</li>
	<?php endif; ?>
	<li><a href="ranking.php"><?php echo $this->_vars['l_rankings']; ?></a></li>
	<li><a href="log.php"><?php echo $this->_vars['l_log']; ?></a></li>
	<?php if ($this->_vars['galaxy_map_enabled'] == true && $this->_vars['gd_enabled'] == true): ?>
	<li><a href="#"><?php echo $this->_vars['l_maps']; ?></a>
		<ul>
			<li><a href="galaxy_map3d.php"><?php echo $this->_vars['l_3dmap']; ?></a></li>
		</ul>
	</li>
	<?php endif; ?>
	<li><a href="#"><?php echo $this->_vars['l_teams']; ?></a>
		<ul>
			<li><a href="teams.php"><?php echo $this->_vars['l_teams']; ?></a></li>
<?php if ($this->_vars['team_id'] != 0): ?>
			<li><a href="team_forum.php?command=showtopics"><?php echo $this->_vars['l_teamforum']; ?> - New:<?php echo $this->_vars['newposts']; ?></a></li>
			<li><a href="team_report.php"><?php echo $this->_vars['l_teamships']; ?></a></li>
			<li><a href="shoutbox_team.php" target="team_shoutbox"><?php echo $this->_vars['l_team_shoutbox']; ?></a></li>
<?php endif; ?>
		</ul>
	</li>
	<li><a href="#"><?php echo $this->_vars['l_messages']; ?></a>
		<ul>
			<li><a href="#"><?php echo $this->_vars['forumname']; ?></a>
				<ul>
				<?php for($for1 = 0; ((0 < $this->_vars['count']) ? ($for1 < $this->_vars['count']) : ($for1 > $this->_vars['count'])); $for1 += ((0 < $this->_vars['count']) ? 1 : -1)):  $this->assign('current', $for1); ?>
					<li><a href="infoport.php?topic_id=<?php echo $this->_vars['topicid'][$this->_vars['current']]; ?>#<?php echo $this->_vars['postid'][$this->_vars['current']]; ?>" target="_blank"><?php if ($this->_vars['newpost'][$this->_vars['current']] > 0): ?>
							<font color="lime">*</font>
						<?php endif; ?>
						<?php echo $this->_vars['topictitle'][$this->_vars['current']]; ?></a></li>
				<?php endfor; ?>
				</ul>
			</li>
			<li><a href="message_read.php"><?php echo $this->_vars['l_read_msg']; ?></a></li>
			<li><a href="message_send.php"><?php echo $this->_vars['l_send_msg']; ?></a></li>
			<li><a href="messageblockmanager.php"><?php echo $this->_vars['l_block_msg']; ?></a></li>
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
			<li><a href="http://www.aatraders.com" target="_blank">Profiles</a></li>
		</ul>
	</li>
	<li><a href="logout.php"><?php echo $this->_vars['l_logout']; ?></a>
		<ul>
			<li><a href="logout.php"><?php echo $this->_vars['l_logout']; ?></a></li>
		</ul>
	</li>
</ul>
</div>

</td></tr>
		</table>
<br>

<table border=0 align=center cellpadding=0 cellspacing=0>
<tr>
<td valign=top align="right">
		<?php if ($this->_vars['avatar'] != "default_avatar.gif"): ?>
			<table BORDER=1 CELLPADDING=0 CELLSPACING=0 align="center">
			<tr><td>
			<img src="images/avatars/<?php echo $this->_vars['avatar']; ?>">
			</td></tr></table>
		<?php endif; ?>
		<?php if ($this->_vars['teamicon'] != "default_icon.gif"): ?>
			</td><td align="center">&nbsp;&nbsp;<=-=>&nbsp;&nbsp;</td><td align="left">
			<table BORDER=1 CELLPADDING=0 CELLSPACING=0 align="center">
			<tr><td>
			<img src="images/icons/<?php echo $this->_vars['teamicon']; ?>">
			</td></tr></table>
		<?php endif; ?>
</td></tr></table>
<table cellspacing = "0" cellpadding = "0" border = "0" width = "650" align="center">
<tr>
	<td width="100%" align="center">
   <font color="silver" size=3 face="arial"><img src="templates/master_template/images/rank/<?php echo $this->_vars['insignia']; ?>" height="18">
	<b>
	 <font color="white"><?php echo $this->_vars['player_name']; ?>
	 </font>
	</b>
   </font>
  <font color=silver size=3 face=arial>
  <?php echo $this->_vars['l_abord']; ?>
   <b>
	<font color="white">
	 <a href="report.php"><?php echo $this->_vars['shipname']; ?></a> (<?php echo $this->_vars['classname']; ?>)
	</font>
   </b></font></td>
</tr>
</table>
<?php if ($this->_vars['playeroutoftime'] == 1): ?>
<table cellspacing = "0" cellpadding = "0" border = "0" width = "650" align="center">
<tr>
	<td width="100%" align="center">
   <font color="red" size=3 face="arial">
	<b><?php echo $this->_vars['l_playeroutoftime']; ?>
   </b></font></td>
</tr>
</table>
<?php endif; ?>
	</td>
    <td background="templates/master_template/images/g-mid-right.gif">&nbsp;</td>
  </tr>
  <tr>
		<td width=18><img src = "templates/master_template/images/g-bottom-left.gif"></td>
		<td width=101><img src = "templates/master_template/images/g-bottom-midleft.gif"></td>
		<td width="100%"><img src = "templates/master_template/images/g-bottom-midright.gif" width="100%" height="12"></td>
		<td width=18><img src = "templates/master_template/images/g-bottom-right.gif"></td>
  </tr>
</table>


<table width="170" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width=18><img src = "templates/master_template/images/g-top-left.gif"></td>
		<td width=101><img src = "templates/master_template/images/g-top-midleft.gif"></td>
		<td width="100%"><img src = "templates/master_template/images/g-top-midright.gif" width="100%" height="20"></td>
		<td width=18><img src = "templates/master_template/images/g-top-right.gif"></td>
  </tr>
  <tr>
    <td background="templates/master_template/images/g-mid-left.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>

<table cellspacing = "0" cellpadding = "0" border = "0" width = "600" align="center">
<tr>
	<td>
<iframe width="600px" height="300px" style="width:600px;height:300px" name="view1" src="global_chat.php"></iframe>

</td>
</tr>
</table>	</td>
    <td background="templates/master_template/images/g-mid-right.gif">&nbsp;</td>
  </tr>
  <tr>
		<td width=18><img src = "templates/master_template/images/g-bottom-left.gif"></td>
		<td width=101><img src = "templates/master_template/images/g-bottom-midleft.gif"></td>
		<td width="100%"><img src = "templates/master_template/images/g-bottom-midright.gif" width="100%" height="12"></td>
		<td width=18><img src = "templates/master_template/images/g-bottom-right.gif"></td>
  </tr>
</table>

<?php extract($this->_vars, EXTR_REFS);  
	if($_SESSION['team_id']>0)
{
 ?>
<table width="170" border="0" cellspacing="0" cellpadding="0" align="center">
  <tr>
		<td width=18><img src = "templates/master_template/images/g-top-left.gif"></td>
		<td width=101><img src = "templates/master_template/images/g-top-midleft.gif"></td>
		<td width="100%"><img src = "templates/master_template/images/g-top-midright.gif" width="100%" height="20"></td>
		<td width=18><img src = "templates/master_template/images/g-top-right.gif"></td>
  </tr>
  <tr>
    <td background="templates/master_template/images/g-mid-left.gif">&nbsp;</td>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>

<table cellspacing = "0" cellpadding = "0" border = "0" width = "600" align="center">
<tr>
	<td>
<iframe width="600px" height="300px" style="width:600px;height:300px" name="view2" src="team_chat.php"></iframe>

</td>
</tr>
</table>	</td>
    <td background="templates/master_template/images/g-mid-right.gif">&nbsp;</td>
  </tr>
  <tr>
		<td width=18><img src = "templates/master_template/images/g-bottom-left.gif"></td>
		<td width=101><img src = "templates/master_template/images/g-bottom-midleft.gif"></td>
		<td width="100%"><img src = "templates/master_template/images/g-bottom-midright.gif" width="100%" height="12"></td>
		<td width=18><img src = "templates/master_template/images/g-bottom-right.gif"></td>
  </tr>
</table>
<?php extract($this->_vars, EXTR_REFS);  
}
 ?>
<table cellspacing = "0" cellpadding = "0" border = "0" width = "600" align="center">
<tr>
	<td><img src="templates/master_template/images/topnav-left.gif" width="41" height="55"></td>
	<td background="templates/master_template/images/topnav-bg.gif" width="100%" height="55" ID="IEnews" align="center">
<layer id="news"</layer>
<?php echo '
<SCRIPT LANGUAGE="JavaScript1.2" TYPE="text/javascript">
<!--
arTXT = new Array(';  extract($this->_vars, EXTR_REFS);  for($i = 0; $i < $newscount; $i++) echo "\"" . $newsmessage[$i] . "\", ";   echo '"End of News");

NS4 = (document.layers);
IE4 = (document.all);

FDRblendInt = 3; // seconds between flips
FDRmaxLoops = 200; // max number of loops (full set of headlines each loop)
FDRendWithFirst = true;

FDRfinite = (FDRmaxLoops > 0);
blendTimer = null;

arTopNews = [];
for (i1=0;i1<arTXT.length;i1++)
{
 arTopNews[arTopNews.length] = arTXT[i1];
}

if(NS4)
{
	news = document.news;
	news.visibility="hide";

	pos1 = document.images[\'pht\'];
	pos1E = document.images[\'ph1E\'];
	news.left = pos1.x;
	news.top = pos1.y;
	news.clip.width = 350;
	news.clip.height = pos1E.y - news.top;
}
else 
{
	document.getElementById(\'IEnews\').style.pixelHeight = document.getElementById(\'IEnews\').offsetHeight;
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
				TopnewsStr += "<P><A CLASS=headlines TARGET=_new HREF=\'news.php\'>"
							+ arTopNews[TopnewsCount] + "</" + "A><img src=\'/images/spacer.gif\' width=1 height=15></" + "P>"
				TopnewsCount += 1;
			}
		}
		if (NS4) 
		{
			news.document.write(TopnewsStr);
			news.document.close();
			news.visibility="show";
		}
		else 
		{
			document.getElementById(\'IEnews\').innerHTML = TopnewsStr;
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

function loadall(){
	changecontent();
	FDRcountLoads();
}

window.onload = loadall;
//-->
</SCRIPT>
'; ?>

	</td>
	<td><img src="templates/master_template/images/topnav-right.gif" width="22" height="55"></td>
</tr>
</table>
