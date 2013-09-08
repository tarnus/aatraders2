<?php echo '
<style type="text/css">
<!--
.topbar {
	font-family: Tahoma, Verdana, Arial, Helvetica, sans-serif;
	font-size: 9px;
	font-style: normal;
	font-weight: bold;
	text-align: center;
	color: #FFFFFF;
}
.shipbody {
	font-family: Tahoma, Verdana, Arial, Helvetica, sans-serif;
	font-size: 10px;
	font-style: normal;
	font-weight: normal;
	color: #ffffff;
	text-align: center;
}

.dropdown {
	font-family: Tahoma, Verdana, Arial, Helvetica, sans-serif;
	font-size: 10px;
	font-style: normal;
	font-weight: normal;
	color: #000000;
	text-align: center;
}

body {
	background-color: #000000;
	margin-left: 0px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
}
body,td,th {
	font-family: Tahoma, Verdana, Arial, Helvetica, sans-serif;
	font-size: 9px;
}
-->
</style>

<script language="Javascript" type="text/javascript">

function reload1(){
document.ThisForm.offset.value=0;
 document.ThisForm.submit();
}
function reload(){
 document.ThisForm.submit();
}
function loggingchange(){
 document.ThisForm.logging1.value=document.ThisForm.logging.options[document.ThisForm.logging.selectedIndex].value;
 document.ThisForm.submit();
}
function loggingchangeb(){
 document.ThisForm.logging1.value=document.ThisForm.logginga.options[document.ThisForm.logginga.selectedIndex].value;
 document.ThisForm.submit();
}
function prev(){
if (document.ThisForm.offset.value >= \'150\')
{
 document.ThisForm.offset.value=Math.ceil(document.ThisForm.offset.value) - 150;
}
 document.ThisForm.submit();
}
function next(){
if (document.ThisForm.offset.value < ';  echo $this->_vars['log_total'];  echo ')
{
 document.ThisForm.offset.value=Math.ceil(document.ThisForm.offset.value) + 150;
}
 document.ThisForm.submit();
}

function page(){
 document.ThisForm.offset.value=document.ThisForm.pagenum.options[document.ThisForm.pagenum.selectedIndex].value;
 document.ThisForm.submit();
}
</script>
'; ?>

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
<input type="Hidden" name="logging1" value="0">
<input type="Hidden" name="offset" value="<?php echo $this->_vars['offset']; ?>"> 
<br><strong>Player Info</strong>
<table width="100%"  border="1" cellspacing="0" cellpadding="2" >
  <tr class="topbar" bgcolor="#000066">
    <td>Player Name <a href="/log.php?player=<?php echo $this->_vars['player_id']; ?>&md5admin_password=<?php echo $this->_vars['md5admin_password']; ?>&game_number=<?php echo $this->_vars['game_number']; ?>" target="_blank">View Log</a></td>
    <td>IP Address </td>
    <td>Last Login </td>
    <td>Score</td>
    <td>Turns</td>
    <td>Turns Used </td>
    <td>Fed Bounty </td>
    <td>IGB Credits </td>
    <td>Loan Amt</td>
    <td>Loan Date </td>
    <td>Credits</td>
  </tr>
  <tr bgcolor="#6666FF" class="shipbody">
    <td class="shipbody"><select name="user" style="text-align:left;" onchange="reload1();">
	  <?php for($for1 = 0; ((0 < $this->_vars['player_tot']) ? ($for1 < $this->_vars['player_tot']) : ($for1 > $this->_vars['player_tot'])); $for1 += ((0 < $this->_vars['player_tot']) ? 1 : -1)):  $this->assign('i', $for1); ?>
		<?php if ($this->_vars['player_id'] == $this->_vars['list_player_id'][$this->_vars['i']]): ?>
		<option value="<?php echo $this->_vars['list_player_id'][$this->_vars['i']]; ?>" selected><?php if ($this->_vars['list_admin_extended_logging'][$this->_vars['i']] == 1): ?>*<?php endif;  echo $this->_vars['list_character_name'][$this->_vars['i']]; ?> <?php echo $this->_vars['online'][$this->_sections['i']['index']]; ?></option>
		<?php else: ?>
		<option value="<?php echo $this->_vars['list_player_id'][$this->_vars['i']]; ?>" ><?php if ($this->_vars['list_admin_extended_logging'][$this->_vars['i']] == 1): ?>*<?php endif;  echo $this->_vars['list_character_name'][$this->_vars['i']];  echo $this->_vars['online'][$this->_vars['i']]; ?></option>
		<?php endif; ?>  
	  <?php endfor; ?>
	
	</select>
	<?php if ($this->_vars['extras'] != ""): ?>
	<hr><?php echo $this->_vars['extras']; ?>
	<?php endif; ?>
	</td>
    <td class="shipbody"><?php echo $this->_vars['ip_address']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['last_login']; ?></td>
    <td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($score); ?></td>
    <td class="shipbody"><?php echo $this->_vars['turns']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['turns_used']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['fedtot']; ?>/<?php if ($this->_vars['fedtot'] != 0):  extract($this->_vars, EXTR_REFS);  echo strip_places($fedtotamt);  else: ?>0<?php endif; ?></td>
    <td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($balance); ?></td>
    <td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($loan); ?></td>
    <td class="shipbody"><?php echo $this->_vars['loantime']; ?></td>
    <td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($credits); ?></td>
  </tr>
</table>
<table width="100%"  border="1" cellspacing="0" cellpadding="2" >
  <tr class="topbar" bgcolor="#000066">
    <td>Team</td>
    <td>Current Sector </td>
    <td>On Planet </td>
    <td>Kills</td>
    <td>Deaths</td>
    <td>Captures</td>
    <td>Planets Built </td>
    <td>Planets Lost </td>
    <td>Experience</td>
    <td>Rating</td>
	<td>Tot Planets</td>
	<td>Tot Planet<br> Credits</td>
    <td>Extend<br>
	 Logging
    </td>
  </tr>
  <tr bgcolor="#6666FF" class="shipbody">
    <td class="shipbody"><?php echo $this->_vars['team_name']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['sector_id']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['on_planet']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['kills']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['deaths']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['captures']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['planets_built']; ?></td>
    <td class="shipbody"><?php echo $this->_vars['planets_lost']; ?></td>
    <td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($experience); ?></td>
    <td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($rating); ?></td>
	<td class="shipbody"><?php echo $this->_vars['tot_planets']; ?></td>
	<td class="shipbody"><?php extract($this->_vars, EXTR_REFS);  echo strip_places($tot_planet_credits); ?></td>
	<?php if ($this->_vars['enable_mass_logging'] == 1): ?>
	    <td class="shipbody">MASS Logging</td>
	<?php else: ?>
	    <td class="shipbody"><select name="logging" onchange="loggingchange();">
		<?php if ($this->_vars['admin_extended_logging'] == 1): ?>
		<option value="ext_off">Off</option>
		<option value="ext_on" selected>On</option>
		<?php else: ?>
		<option value="ext_off" selected>Off</option>
		<option value="ext_on">On	</option>
		<?php endif; ?>
		</select>
		</td>
	<?php endif; ?>
  </tr>
</table>
<br><strong>Ships</strong>
<table width="100%"  border="1" cellspacing="0" cellpadding="2" >
  <tr class="topbar" bgcolor="#000066">
    <td>Ship ID </td>
    <td>Type</td>
    <td>Hull</td>
    <td>Engines</td>
    <td>Power</td>
    <td>FB</td>
    <td>Sensors</td>
    <td>Beams</td>
    <td>Torps</td>
    <td>Shields</td>
    <td>Amour</td>
    <td>Cloak</td>
    <td>ECM</td>

  </tr>
  <?php for($for1 = "0"; (("0" < "$ship_count") ? ($for1 < "$ship_count") : ($for1 > "$ship_count")); $for1 += (("0" < "$ship_count") ? "1" : -"1")):  $this->assign('i', $for1); ?>
  <tr bgcolor="#6666FF" class="shipbody">
    <td class="shipbody"><?php echo $this->_vars['ship_id'][$this->_vars['i']]; ?></td>
	<?php if ($this->_vars['currentship'] == $this->_vars['ship_id'][$this->_vars['i']]): ?>
    <td class="shipbody"  style="color:lime"><b><?php echo $this->_vars['ship_type'][$this->_vars['i']]; ?><b></td>
	<?php else: ?>
	<td class="shipbody"><?php echo $this->_vars['ship_type'][$this->_vars['i']]; ?></td>
	<?php endif; ?>
    <td class="shipbody"><?php echo $this->_vars['hull_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['hull'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['engines_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['engines'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['power_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['power'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['computer_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['computer'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['sensors_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['sensors'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['beams_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['beams'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['torp_launchers_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['torp_launchers'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['shields_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['shields'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['armour_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['armour'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['cloak_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['cloak'][$this->_vars['i']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['ecm_normal'][$this->_vars['i']]; ?>/<?php echo $this->_vars['ecm'][$this->_vars['i']]; ?></td>
    
  </tr>
  <?php endfor; ?>
</table>
	

<br><strong>Top 10 Planets</strong>
<table width="100%"  border="1" cellspacing="0" cellpadding="2" >
  <tr class="topbar" bgcolor="#000066">
    <td>Planet</td>
    <td>Sector</td>
    <td>Computer</td>
    <td>Sensors</td>
    <td>Beams</td>
    <td>Torps</td>
    <td>Shields</td>
    <td>Jammer</td>
    <td>Cloak</td>
	<td>Amour</td>
    <td>Colonists</td>
    <td>Energy</td>
    <td>Max Credits </td>
    <td>Credits</td>
  </tr>

  <?php for($for1 = 0; ((0 < $this->_vars['planet_count']) ? ($for1 < $this->_vars['planet_count']) : ($for1 > $this->_vars['planet_count'])); $for1 += ((0 < $this->_vars['planet_count']) ? 1 : -1)):  $this->assign('myLoop', $for1); ?>

  <tr bgcolor="#6666FF" class="shipbody">
    <td class="shipbody"><?php echo $this->_vars['planetname'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['psector_id'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pcomputer_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['pcomputer'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['psensors_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['psensors'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pbeams_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['pbeams'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['ptorp_launchers_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['ptorp_launchers'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pshields_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['pshields'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pjammer_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['pjammer'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pcloak_normal'][$this->_vars['myLoop']]; ?>/<?php echo $this->_vars['pcloak'][$this->_vars['myLoop']]; ?></td>
 	<td class="shipbody"><?php echo $this->_vars['parmour'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pcolonists'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['penergy'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pmax_credits'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['pcredits'][$this->_vars['myLoop']]; ?></td>
  </tr>
  <?php endfor; ?>

</table><br>
<div align="center"><input type="Button" value="  Refresh  " onclick="reload();">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<select name="logginga" class="dropdown" onchange="loggingchangeb();">
<option value="">Select Log Purge Option</option>
<option value="cleartoday">Purge older than today</option>
<option value="clearall">Clearall</option>
</select>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="Button" value="  Prev Page  " onclick="prev();">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="Button" value="  Next Page  " onclick="next();">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>

<?php if ($this->_vars['log_count'] != 0): ?>
<br><strong>Admin Log - Page <select name="pagenum" onchange="page();">
<?php extract($this->_vars, EXTR_REFS);   	for ($y=0;$y < $pages;$y++)
		{
			$pval=$y*150;
			if ($current_page==$y)
			{
				echo "<option value=\"$pval\" selected>".$y."</option>\n";
			}else{
				echo "<option value=\"$pval\" >".$y."</option>\n";
			}
		}
 ?>			

</select> of <?php echo $this->_vars['pages']; ?></strong><div align="center">
<div style="width: 650px; align: center; height: 250px; background-color: black; overflow: auto;">
<table width="100%"  border="1" cellspacing="0" cellpadding="2" >
  <tr class="topbar" bgcolor="#000066">
    <td>IP Address </td>
    <td>Score</td>
    <td>Turns</td>	
    <td>Credits</td>
	<td>date/time</td>
    <td>Cur Command</td>
    <td>Get Data </td>
    <td>Post Data </td>
    <td>Player Time Left </td>
  </tr>

   <?php for($for1 = 0; ((0 < $this->_vars['log_count']) ? ($for1 < $this->_vars['log_count']) : ($for1 > $this->_vars['log_count'])); $for1 += ((0 < $this->_vars['log_count']) ? 1 : -1)):  $this->assign('myLoop', $for1); ?>
   
   <?php if ($this->_vars['lcreditdiff'][$this->_vars['myLoop']] > 20 || $this->_vars['lscorediff'][$this->_vars['myLoop']] > 15): ?>
  <tr bgcolor="#AAAAFF" class="shipbody">
  	<?php else: ?>
	  <tr bgcolor="#6666FF" class="shipbody">
	<?php endif; ?>
    <td class="shipbody" ><?php echo $this->_vars['lip_address'][$this->_vars['myLoop']]; ?></td>
	<?php if ($this->_vars['lscorediff'][$this->_vars['myLoop']] > 50): ?>
    <td class="shipbody"  style="color: red;"><?php echo $this->_vars['lscore'][$this->_vars['myLoop']]; ?></td>
	<?php elseif ($this->_vars['lscorediff'][$this->_vars['myLoop']] > 15): ?>
	<td class="shipbody" style="color: yellow;"><?php echo $this->_vars['lscore'][$this->_vars['myLoop']]; ?></td>
	<?php else: ?>
	<td class="shipbody"><?php echo $this->_vars['lscore'][$this->_vars['myLoop']]; ?></td>
	<?php endif; ?>
	
    <td class="shipbody"><?php echo $this->_vars['lturns'][$this->_vars['myLoop']]; ?> </td>	
	<?php if ($this->_vars['lcreditdiff'][$this->_vars['myLoop']] > 50): ?>
    <td class="shipbody"  style="color: red;"><?php echo $this->_vars['lcredits'][$this->_vars['myLoop']]; ?></td>
	<?php elseif ($this->_vars['lcreditdiff'][$this->_vars['myLoop']] > 20): ?>
	<td class="shipbody" style="color: yellow;"><?php echo $this->_vars['lcredits'][$this->_vars['myLoop']]; ?></td>
	<?php else: ?>
	<td class="shipbody"><?php echo $this->_vars['lcredits'][$this->_vars['myLoop']]; ?> </td>
	<?php endif; ?>
    <td class="shipbody"><?php echo $this->_vars['ltime'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody"><?php echo $this->_vars['lurl_path'][$this->_vars['myLoop']]; ?></td>
    <td class="shipbody" style="text-align:left;"><?php echo $this->_vars['lget_data'][$this->_vars['myLoop']]; ?></td>
	<td class="shipbody" style="text-align:left;"><?php echo $this->_vars['lpost_data'][$this->_vars['myLoop']]; ?></td>
	<td class="shipbody" style="text-align:left;"><?php echo $this->_vars['lplayer_online_time'][$this->_vars['myLoop']]; ?></td>
  </tr>
    <?php endfor; ?>
</table>
</div>
</div>
<?php endif; ?>