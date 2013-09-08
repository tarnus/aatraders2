<?php
// 1: NPC Report
// .
?>
<p align="center"><font color="#CCCCCC" size="4"><strong> NPC Report</strong></font></p>
<table width="60%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr height="20" align="center" valign="middle">
    <td width="" bgcolor="<?php echo $color_line1?>"></td>
    <td width="25%" bgcolor="<?php echo $color_line1?>"<A HREF=fur_report.php?sort=character_name>Name</a></td>
    <td width="15%" bgcolor="<?php echo $color_line1?>"<A HREF=fur_report.php?sort=orders>Orders</td>
    <td width="15%" bgcolor="<?php echo $color_line1?>"<A HREF=fur_report.php?sort=aggression>Mood</td>
    <td width="15%" bgcolor="<?php echo $color_line1?>"<A HREF=fur_report.php?sort=cloak>Cloak</td>
    <td width="30%" bgcolor="<?php echo $color_line1?>">Avg. Level</td>
  </tr>
  <?php

    $rownumber = 0;

if($sort=="{$db_prefix}players.character_name")
{
  $by="character_name ASC";
}
elseif($sort=="orders")
{
  $by="{$db_prefix}npc_player.orders DESC";
}
elseif($sort=="aggression")
{
  $by="{$db_prefix}npc_player.aggression DESC";
}
elseif($sort=="cloak")
{
  $by="{$db_prefix}ships.cloak DESC";
}
else
{
  $by="{$db_prefix}players.character_name ASC";
}

$res = $db->Execute("SELECT * FROM {$db_prefix}players LEFT JOIN {$db_prefix}npc_player ON " .
					"{$db_prefix}players.player_id = {$db_prefix}npc_player.npc_id LEFT JOIN " .
					"{$db_prefix}ships ON {$db_prefix}players.currentship = {$db_prefix}ships.ship_id " .
					"WHERE {$db_prefix}npc_player.active='Y' AND {$db_prefix}players.destroyed='N' ORDER BY $by");
     while(!$res->EOF)
     {
          $row = $res->fields;
        $rownumber++;
?>
  <tr height="20" align="center" valign="middle">
    <td>
      <?php echo $rownumber?>
    </td>
    <td width="25%">
      <?php echo $row['character_name']?>
    </td>
    <td width="15%">
      <?php
        switch($row['orders']){
         case"0":
            echo "<font color=green>Sentinel</font>";
         break;
         case"1":
            echo "<font color=cyan>Explorer</font>";
         break;
         case"2":
            echo "<font color=amber>Trader</font>";
         break;
         case"3":
            echo "<font color=red>Hunter</font>";
         break;         
      }
      ?>
    </td>
    <td width="15%">
      <?php
        switch($row['aggression']){
         case"0":
            echo "<font color=green>Peaceful</font>";
         break;
         case"1":
            echo "<font color=amber>Aggressive</font>";
         break;
         case"2":
            echo "<font color=red>Hostile</font>";
         break;
      }
      ?>
    </td>
    <td width="15%">
      <?php echo $row['cloak']?>
    </td>
<td width="30%">
<?php echo ($row['hull']+$row['engines']+$row['computer']+$row['armour']+$row['shields']+$row['beams']+$row['torp_launchers'])/7;?>
<?php
/* Heres the code I am using to show a power bar based on your ships average tech level, this is the same as the ones in the ship & planet images - GunSlinger
    Here are the power bar images, 00 is a blank spacer so you wont see a power bar for a ship under 8, its here to keep the formatting neat */

$powertypes[0]= "power_00.gif";
$powertypes[1]= "power_05.gif";
$powertypes[2]= "power_10.gif";
$powertypes[3]= "power_15.gif";
$powertypes[4]= "power_20.gif";
$powertypes[5]= "power_25.gif";
$powertypes[6]= "power_30.gif";
$powertypes[7]= "power_35.gif";
$powertypes[8]= "power_40.gif";
$powertypes[9]= "power_45.gif";
$powertypes[10]= "power_50.gif";

//
/* And here is the code to fetch the power bar image - GunSlinger */

{
$shipavg = $row['hull']+$row['engines']+$row['computer']+$row['armour']+$row['shields']+$row['beams']+$row['torp_launchers']/7;
$shipavg /= 7;
    if($shipavg < 5)
$powerlevel = 0;
    else if ($shipavg < 10)
$powerlevel = 1;
    else if ($shipavg < 15)
$powerlevel = 2;
    else if ($shipavg < 20)
$powerlevel = 3;
    else if ($shipavg < 25)
$powerlevel = 4;
    else if ($shipavg < 30)
$powerlevel = 5;
    else if ($shipavg < 35)
$powerlevel = 6;
    else if ($shipavg < 40)
$powerlevel = 7;
    else if ($shipavg < 45)
$powerlevel = 8;
    else if ($shipavg < 50)
$powerlevel = 9;
    else
$powerlevel = 10;

}
// end of experimental code  
?>
<?php echo  "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src=\"images/$powertypes[$powerlevel]\">";?>  <p>&nbsp;</p></td>
  </tr>

    <?php   
          $res->MoveNext();
     }
?>
</table>
<br>
<table width="60%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td><div align="justify">
        <p>Xenobe (pronounced 'ZeN-oBe') are artificial-intelligence based computer players. Their
          ultimate goal is to create some interactivity within the game.<br> Each
          Xenobe plays once every <? echo NUMBER($sched_furangee) ?> minutes and can attack other players ships, planets and
          sector defences as well as travelling and trading between ports (depending on their orders
          and mood).<br> Due to their limited movement they receive financial aid each tick, 
          this is currently set at <? echo  NUMBER($fur_unemployment) ?> credits per Xenobe update.
    <br>Xenobe don't travel like human players, learning from their descendants who were getting caught in 
           traps they have now perfected worm-hole technology and if no warp-links are 
           present when they are ready to move they can create a worm-hole to leave a sector.<br>
           Any Xenobe destroyed are replaced by some kind of cloning device during the next 
           game update, scientists have yet to discover any further information about this device.</p>
<p>
<b>Orders</b> - this is what they do every 6 minutes<br>
<font color=green><b>Sentinel</b></font>- Doesn't move, just checks the sector he is in.<br>
<font color=cyan><b>Explorer</b></font> - Moves and looks for a target in the sector he moves to.<br>
<font color=amber><b>Trader</b></font> - Moves, trades if possible then looks for a target in that sector.<br>
<font color=red><b>Hunter</b></font> - Very rare due to the fact that they tend to kill themselves, they  
				target a player then act depending on their Mood or they will attack a planet
				defeating the defenses and leave the planet unnowned ready for the next Xenobe
				that wants a planet or the next player who is lucky enough to find it. <br> <br>      
<b>Mood</b> - this is how they react to other ships and planets, and after scanning or being scanned by a real player.  <br>     
<font color=green><b>Peaceful</b></font> - These guys do nothing, they are fighter fodder.<br>
<font color=amber><b>Aggressive</b></font> - These guys attack sometimes so be careful around them.<br>
<font color=red><b>Hostile</b></font> - Caution! These have a mean temper and are liable to attack if your too nosy around them.</p>
        </div></td>
  </tr>
</table>
<p align="center"><a href="main.php">Click here</a> to return to the main menu</p>
 