<body bgcolor="#000000" text="darkred" marginheight=0 marginwidth=0 topmargin=0 leftmargin=0 link="#52ACEA" vlink="#52ACEA" alink="#52ACEA">
{literal}
<style type="text/css">
.tooltip, .preview, .screenshot { cursor:pointer; }
#tooltip { width: 150px; }
#tooltip, #preview {
 color:#dddddd;
 background:#222222;
 border: 1px solid #333333;
 padding:5px;
 font-size:12px;
 font-family: arial, helvetica, verdana, tahoma;
 opacity: 0.9;
 filter: alpha(opacity=90);
 text-align:left;
 border-radius: 1em;
 -moz-border-radius: 1em;
 -webkit-border-radius: 1em;
 display:none;
}
</style>

<script src="jquery.jatt.js" type="text/javascript"></script>
<script type="text/javascript">
$(document).ready(function(){
 $.jatt();
});
</script>
{/literal}

<table cellspacing = "0" cellpadding = "0" border = "0" width = "100%">
<tr>
	<td align="center">
<img src="templates/master_template/images/main_title.jpg">
	</td>
</tr>

		</table>

	
		<table cellspacing = "0" cellpadding = "0" border = "0" width = "100%">
		<tr>
<td><p align="center">

	
    <td colspan="2" align="center" class='pageheader' valign='bottom'>
<font color="#49A7DD" size="1" face="Verdana, Arial, Helvetica, sans-serif"><b>[Version {$version}]</b></font><br><br></td>


	</tr>
		</table>
<center>
<form method="post" action="login_process.php" style="background:black; border-style:none;" name="clock">

<table border="0" align="center">
  <tr class="tooltip {literal}{direction: n; width: 150px; background: #222; color: #ddd;}{/literal}" title="<b>Player Name</b><br>Enter your Ship Captain's name for the selected game to take command of your ship.<br><br>If you are a new player click on the New Player button to be assigned a ship.">
	<td width="200" height="23"><img border="0" src="templates/master_template/images/playername.gif"></td>
	<td  style="background: url('templates/master_template/images/loginbox.png') no-repeat;width:255px;height:23px;">
		<p align="center">
		<input type="text" name="character_name" value="{$character_name}" size="32" maxlength="30" style="color:#52ACEA; font-weight: bold; background-color:black; text-align:left; border-style:none;width:238px">
		</p>
	</td>
  </tr>
  <tr class="tooltip {literal}{direction: n; width: 150px; background: #222; color: #ddd;}{/literal}"  title="<b>Player Password</b><br>Enter your Ship Captain's password to login to your ships computer systems." >
	<td width="200" height="23"><img border="0" src="templates/master_template/images/password.gif"></td>
	<td  style="background: url('templates/master_template/images/loginbox.png') no-repeat;width:255px;height:23px;">
		<p align="center">
		<input type="password" name="pass" value="{$password}" size="32" maxlength="{$maxlen_password}" style="color:#52ACEA; font-weight:bold; background-color:black; text-align:left; border-style:none;width:238px">
		</p>
	</td>
  </tr>
 </table>

<table border="0" align="center">
  <tr>
	<td colspan="3" align="center"><br><img border="0" src="templates/master_template/images/gameselection.gif" alt="Select Game"></td>
	</tr>
	<tr>
	<td width="220" align="center" valign="top" class="footer">

{literal}
<SCRIPT LANGUAGE="JavaScript">
<!--
var newhref=0;

function changehrefs(newhref)
{
	document.getElementById('newplayer').href = 'new_player.php?game_number='+newhref;
}
// -->
</SCRIPT>
{/literal}

{php}
	for($i = 0; $i < $totalgames; $i++)
	{
		echo "<input class='tooltip' title='<b>Game Selection</b><br>Click on the Radio Button to select <font color=white><b>" . addslashes($gamename[$i]) . "</b></font>'  onClick=\"changehrefs('$i')\" type=\"radio\" name=\"game_number\" value=\"$i\"";
		if($i == 0)
			echo "checked";
		echo "><b><font color=\"#00ffff\"class='tooltip' title='<b>Game Selection</b><br>Click on the Radio Button to select <font color=white><b>" . addslashes($gamename[$i]) . "</b></font>' >$gamename[$i]</font></b><br>";
echo "<script language=\"javascript\" type=\"text/javascript\">
<!--
 var myi$i = $index_seconds_until_update[$i];
 setTimeout(\"rmyx$i();\",1000);

  function rmyx$i()
   {
	myi$i = myi$i - 1;
	if (myi$i <= 0)
	 {
		 myi$i = $index_scheduler_ticks[$i] * 60;
	 }
	document.getElementById(\"myx$i\").innerHTML = myi$i;
	setTimeout(\"rmyx$i();\",1000);
   }
// end hiding script-->
</SCRIPT>
<table width=\"100%\" border=0 cellspacing=0 cellpadding=0>
	<tr>		  
	  <td align=center class=\"footer\"><b><span id=myx$i class=\"footer\">$index_seconds_until_update[$i]</span></b> $index_footer_until_update <br> 
$index_players_online[$i]<br>$index_players_open[$i]<br><br>
<a class='tooltip' title='<b>Player Rankings</b><br>Click to view the player rankings for the <font color=white><b>" . addslashes($gamename[$i]) . "</b></font> game.' href=\"ranking.php?game_number=$i\"><img border=\"0\" src=\"templates/master_template/images/ranking_small.gif\"></a>&nbsp;&nbsp;&nbsp;
	<a class='tooltip' title='<b>Game Settings</b><br>Click to view the game settings for the <font color=white><b>" . addslashes($gamename[$i]) . "</b></font> game.'  href=\"settings.php?game_number=$i\"><img border=\"0\" src=\"templates/master_template/images/setting_small.gif\"></a><br>
	<a class='tooltip' title='<b>FNN News</b><br>Click to view the latest FNN News broadcast for the <font color=white><b>" . addslashes($gamename[$i]) . "</b></font> game.' href=\"news.php?game_number=$i\" class=\"footer\"><img border=\"0\" src=\"templates/master_template/images/fnnnews_small.gif\"></a></td>
	</tr>
  </table>
<br>  ";
		if($server_closed[$i] == 1)
		{
			echo "<b><font size=\"4\" color=\"#ff0000\">$l_login_sclosed</font></b><br>";
		}
		else
		{
			if($tournament_setup_access[$i] == 1)
			{
echo "<SCRIPT LANGUAGE=\"JavaScript\">
<!--
var eventdate$i = new Date(\"$tournament_start_date[$i] 00:00:00 $scheduled_resetdatezone\");

function toSt$i(n) {
  s=\"\"
  if(n<10) s+=\"0\"
  return s+n.toString();
}
 
function tourneycountdown$i() {
  cl=document.clock;
  d=new Date();
  count=Math.floor((eventdate$i.getTime()-d.getTime())/1000);

  if(count<=0)
    {cl.days$i.value =\"----\";
     cl.hours$i.value=\"--\";
     cl.mins$i.value=\"--\";
     cl.secs$i.value=\"--\";
     return;
   }
  cl.secs$i.value=toSt$i(count%60);
  count=Math.floor(count/60);
  cl.mins$i.value=toSt$i(count%60);
  count=Math.floor(count/60);
  cl.hours$i.value=toSt$i(count%24);
  count=Math.floor(count/24);
  cl.days$i.value=count;    
  
  setTimeout(\"tourneycountdown$i()\",500);
}
// end hiding script-->

</SCRIPT>
<div align=\"center\">

<table style=\"border: thin solid #3FA9FC;\" cellpadding=\"0\" cellspacing=\"0\"><tr bgcolor=\"#000000\" align=\"center\"><td>
<TABLE BORDER=0 CELLSPACING=5 CELLPADDING=0 BGCOLOR=\"#000000\">
<TR>
<TD ALIGN=CENTER WIDTH=\"31%\" BGCOLOR=\"#000080\"><FONT COLOR=\"#FFFFFF\" face=\"verdana,arial,helvetica\"><B>Days:</B></FONT></TD>
<TD ALIGN=CENTER WIDTH=\"23%\" BGCOLOR=\"#000080\"><FONT COLOR=\"#FFFFFF\" face=\"verdana,arial,helvetica\"><B>Hours:</B></FONT></TD>
<TD ALIGN=CENTER WIDTH=\"23%\" BGCOLOR=\"#000080\"><FONT COLOR=\"#FFFFFF\" face=\"verdana,arial,helvetica\"><B>Mins:</B></FONT></TD>
<TD ALIGN=CENTER WIDTH=\"23%\" BGCOLOR=\"#000080\"><FONT COLOR=\"#FFFFFF\"><B>Secs:</B></FONT></TD>
</TR>
<TR>
<TD ALIGN=CENTER><INPUT name=\"days$i\" size=4></TD>
<TD ALIGN=CENTER><INPUT name=\"hours$i\" size=2></TD>
<TD ALIGN=CENTER><INPUT name=\"mins$i\" size=2></TD>
<TD ALIGN=CENTER><INPUT name=\"secs$i\" size=2></TD>
</TR>
<TR>
<TD COLSPAN=\"4\" BGCOLOR=\"#000000\">
<CENTER><FONT COLOR=\"#00FF00\" SIZE=1 face=\"verdana,arial,helvetica\">
<SCRIPT LANGUAGE=\"JavaScript\">
<!--
document.write(\" \"+eventdate$i.toLocaleString()+\" \");
tourneycountdown$i();
// end hiding script-->
</SCRIPT>
</FONT>
</CENTER>
</TD>
</TR>
<TR>
<TD COLSPAN=\"4\" BGCOLOR=\"#000080\">
<CENTER><FONT face=\"verdana,arial,helvetica\" SIZE=\"1\" COLOR=\"#FFFF00\">$l_login_tourney_signup</FONT></CENTER>
</TD>
</TR>
</TABLE></td></tr></table>
</div>
";
			}
			if($account_creation_closed[$i] == 1)
			{
				echo "<b><font color=\"#FFFFFF\">$l_login_newclosed_message</font></b><br>";
			}
			if($profile_only_server[$i] == 1)
			{
				echo "<b><font color=\"#00ff00\">$l_login_profile_only</font></b><br>";
			}
			if($tournament_mode[$i] == 1)
			{
				echo "<b><font color=\"#ffff00\">$l_login_tourneymode</font></b><br>";
				if($profile_only_server[$i] != 1)
				{
					echo "<b><font color=\"#00ff00\">$l_login_profile_only</font></b><br>";
				}
			}
		}

		if($totalgames > 1)
		{
			if((($i + 1) / 2) == (int)(($i + 1) / 2))
			{
				echo "</td></tr><tr><td colspan=3><hr></td></tr><tr><td width=\"220\" align=\"center\" valign=\"top\">";
			}
			else
			{
				echo "</td><td background=\"templates/master_template/images/index_divider.png\">&nbsp;</td><td width=\"220\" align=\"center\" valign=\"top\">";
			}
		}
			if($scheduled_reset_set[$i] == 1)
			{
echo "<SCRIPT LANGUAGE=\"JavaScript\">
<!--
var reseteventdate$i = new Date(\"$scheduled_resetdate[$i] 00:00:00 $scheduled_resetdatezone\");

function resettoSt$i(n) {
  s=\"\"
  if(n<10) s+=\"0\"
  return s+n.toString();
}
 
function resetcountdown$i() {
  cl=document.clock;
  d=new Date();
  count=Math.floor((reseteventdate$i.getTime()-d.getTime())/1000);

  if(count<=0)
    {cl.rdays$i.value =\"----\";
     cl.rhours$i.value=\"--\";
     cl.rmins$i.value=\"--\";
     cl.rsecs$i.value=\"--\";
     return;
   }
  cl.rsecs$i.value=resettoSt$i(count%60);
  count=Math.floor(count/60);
  cl.rmins$i.value=resettoSt$i(count%60);
  count=Math.floor(count/60);
  cl.rhours$i.value=resettoSt$i(count%24);
  count=Math.floor(count/24);
  cl.rdays$i.value=count;    
  
  setTimeout(\"resetcountdown$i()\",500);
}
// end hiding script-->

</SCRIPT>
<div align=\"center\">

<table style=\"border: thin solid #3FA9FC;\" cellpadding=\"0\" cellspacing=\"0\"><tr bgcolor=\"#000000\" align=\"center\"><td>
<TABLE BORDER=0 CELLSPACING=5 CELLPADDING=0 BGCOLOR=\"#000000\">
<TR>
<TD ALIGN=CENTER WIDTH=\"31%\" BGCOLOR=\"#800000\"><FONT COLOR=\"#FFFFFF\" face=\"verdana,arial,helvetica\"><B>Days:</B></FONT></TD>
<TD ALIGN=CENTER WIDTH=\"23%\" BGCOLOR=\"#800000\"><FONT COLOR=\"#FFFFFF\" face=\"verdana,arial,helvetica\"><B>Hours:</B></FONT></TD>
<TD ALIGN=CENTER WIDTH=\"23%\" BGCOLOR=\"#800000\"><FONT COLOR=\"#FFFFFF\" face=\"verdana,arial,helvetica\"><B>Mins:</B></FONT></TD>
<TD ALIGN=CENTER WIDTH=\"23%\" BGCOLOR=\"#800000\"><FONT COLOR=\"#FFFFFF\"><B>Secs:</B></FONT></TD>
</TR>
<TR>
<TD ALIGN=CENTER><INPUT name=\"rdays$i\" size=4></TD>
<TD ALIGN=CENTER><INPUT name=\"rhours$i\" size=2></TD>
<TD ALIGN=CENTER><INPUT name=\"rmins$i\" size=2></TD>
<TD ALIGN=CENTER><INPUT name=\"rsecs$i\" size=2></TD>
</TR>
<TR>
<TD COLSPAN=\"4\" BGCOLOR=\"#000000\">
<CENTER><FONT COLOR=\"#00FF00\" SIZE=1 face=\"verdana,arial,helvetica\">
<b>$l_login_reset2<br>$scheduled_resetdate[$i]</b>
<SCRIPT LANGUAGE=\"JavaScript\">
<!--
resetcountdown$i();
// end hiding script-->
</SCRIPT>
</FONT>
</CENTER>
</TD>
</TR>
</TABLE></td></tr></table>
</div>
";
		}
		else
		{
				echo "<b>$scheduled_resetdate[$i]</b><br>";
			}
	}
{/php}
	</td>
  </tr>
 </table>
<br>
<table border="0" align="center">
  <tr>
	{if $total_signupclosed != $totalgames && $total_closed != $totalgames}
	<td width="255" class="tooltip" title="<b>New Player Signup</b><br>Welcome new recruit.  By clicking this button you will be accepting a new ship provided by the Federation for exploration and conquest.  Fill out the required forms and your new ship will be ready and waiting." >
	<a id="newplayer" href="new_player.php"><img border="0" src="templates/master_template/images/newplayer.gif" align="left"></a>
	</td>
	{/if}
	<td width="134" class="tooltip" title="<b>Ship Login</b><br>Make sure you have entered your Ship Captain's name, password and selected the game you would like to play before requesting login." >
	<input type="image" name="login" src="templates/master_template/images/login.gif" value="{$l_login_title}">
	</td>
</tr>
</table>
<br>

<table border="0" align="center">
  <tr>
	<td width="118" align="right"><a class="tooltip" title="<b>Forum Access</b><br>Click here to view the Forums provided for this game."  href="{$link_forums}" target="_blank"><img border="0" src="templates/master_template/images/forums.gif"></a></td>
{if $main_site != ''}
	 <td width="134" align="right">
	  <a class="tooltip" title="<b>Web Site</b><br>Click here to be taken to the Web Site for this game"  href="{$main_site}" target="_blank"><img border="0" src="templates/master_template/images/returntosite.gif"></a>
	 </td>
{/if}

{if $serverlist != ''}
	 <td width="134" align="right">
	  <a class="tooltip" title="<b>Server List</b><br>Click here to view a list of all servers running Alien Assault Traders games."  href="{$serverlist}servers" target="_blank"><img border="0" src="templates/master_template/images/serverlist.gif"></a>
	 </td>
{/if}
	<td width="70" align="right"><a class="tooltip" title="<b>FAQ</b><br>Click here to view a simple F.A.Q. about the game."  href="http://wiki.aatraders.com/tiki-index.php?page=Playing+the+Game" target="_blank"><img border="0" src="templates/master_template/images/faq.gif"></a></td>
  </tr>
<tr>
		<td colspan="4" align="center"><a class="tooltip" title="<b>Contact Admin</b><br>Click here to send an Email to the Admin of this game."  href="contact_admin.php" target="_blank"><img border="0" src="templates/master_template/images/contact.gif"><img border="0" src="templates/master_template/images/contact_admin.gif"></a></td>
</tr>
</table>
</form>
</center>

{if $showserverlist == 1 && $servercount > 0}
	<table style="border: thin solid #3FA9FC;" width="800" border="1" cellspacing="1" cellpadding="1" align="center">
	{php}
	for($i = 0; $i < $servercount; $i++){
		echo "<tr><td class=mnu><a href=\"http://$serverurl[$i]\" class=mnu>$servername[$i]</a></td><td align=\"center\"><span class=mnu>$serversectors[$i] Sectors</span></td><td align=\"center\"><span class=mnu>$serverplayers[$i] Players</span></td><td align=\"center\"><span class=mnu>$servertop[$i]</span></td><td align=\"center\"><span class=mnu>$serverreset[$i]</span></td></tr>";
	}
	{/php}
	</table>
{/if}

{if $newscount}
{literal}
<script type="text/javascript">
       $(document).ready(
                function(){
                    $('#news').innerfade({
                        speed: 'slow',
                        timeout: 8000,
                        type: 'random',
                        containerheight: '150px'

                    });
                    }
    );

</SCRIPT>
{/literal}
<div id="news-wrapper">
<ul id="news"> 
{php}
    for($i = 0; $i < $newscount; $i++) 
        echo "<li><br><font color=#00ff00><b>$l_login_notice</b></font>&nbsp;" . $newsdata[$i] . "</li>\n"; 
{/php}
     </div>              


{/if}

