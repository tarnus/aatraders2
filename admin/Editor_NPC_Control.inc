<?php
// 2: NPC Control
// .
/*
function CHECKED($yesno)
{
  return(($yesno == "Y") ? "CHECKED" : "");
}

function YESNO($onoff)
{
  return(($onoff == "ON") ? "Y" : "N");
}
*/
$module = $menu;

if($swordfish != $adminpass)
{
  echo "<FORM ACTION=furangee_control.php METHOD=POST>";
  echo "Password: <INPUT TYPE=PASSWORD NAME=swordfish SIZE=20 MAXLENGTH=20><BR><BR>";
  echo "<INPUT TYPE=SUBMIT VALUE=Submit><INPUT TYPE=RESET VALUE=Reset>";
  echo "</FORM>";
}
else
{
  // ******************************
  // ******** MAIN MENU ***********
  // ******************************
  if(empty($module))
  {
    echo "Welcome to the BlackNova Traders Furangee Control module<BR><BR>";
    echo "Select a function from the list below:<BR>";
    echo "<FORM ACTION=furangee_control.php METHOD=POST>";
    echo "<SELECT NAME=menu>";
    echo "<OPTION VALUE=instruct>Furangee Instructions</option>";
    echo "<OPTION VALUE=furangeeedit SELECTED>Furangee Character Editor</option>";
    echo "<OPTION VALUE=createnew>Create A New Furangee Character</option>";
    echo "<OPTION VALUE=clearlog>Clear All Furangee Log Files</option>";
    echo "<OPTION VALUE=dropfurangee>Drop and Re-Install Furangee Database</option>";
    echo "</SELECT>";
    echo "<INPUT TYPE=HIDDEN NAME=swordfish VALUE=$swordfish>";
    echo "&nbsp;<INPUT TYPE=SUBMIT VALUE=Submit>";
    echo "</FORM>";
  }
  else
  {
    $button_main = true;
    // ***********************************************
    // ********* START OF INSTRUCTIONS SUB ***********
    // ***********************************************
    if($module == "instruct")
    {
      echo "<H2>Furangee Instructions</H2>";
      echo "<P>&nbsp;&nbsp;&nbsp; Welcome to the Furangee Control module.  This is the module that will control the Furangee players in the game. ";
      echo "It is very simple right now, but will be expanded in future versions. ";
      echo "The ultimate goal of the Furangee players is to create some interactivity for those games without a large user base. ";
      echo "I need not say that the Furangee will also make good cannon fodder for those games with a large user base. ";

      echo "<H3>Furangee Creation</H3>";
      echo "<P>&nbsp;&nbsp;&nbsp; In order to create a Furangee you must choose the <B>\"Create A Furangee Character\"</B> option from the menu. ";
      echo "This will bring up the Furangee character creation screen.  There are only a few fields for you to edit. ";
      echo "However, with these fields you will determine not only how your Furangee will be created, but how he will act in the game. ";
      echo "We will now go over these fields and what they will do. ";

      echo "<P>&nbsp;&nbsp;&nbsp; When creating a new Furangee character the <B>Furangee Name</B> and the <B>Shipname</B> are automatically generated. ";
      echo "You can change these default values by editing these fields before submitting the character for creation. ";
      echo "Take care not to duplicate a current player or ship name, for that will result in creation failure. ";
      echo "<BR>&nbsp;&nbsp;&nbsp; The starting <B>Sector</B> number will also be randomly generated. ";
      echo "You can change this to any sector.  However, you should take care to use a valid sector number. Otherwise the creation will fail.";
      echo "<BR>&nbsp;&nbsp;&nbsp; The <B>Level</B> field will default to '3'.  This field refers to the starting tech level of all ship stats. ";
      echo "So a default Furangee will have it's Hull, Beams, Power, Engine, etc... all set to 3 unless this value is changed. ";
      echo "All appropriate ship stores will be set to the maximum allowed by the given tech level. ";
      echo "So, starting levels of energy, fighters, armour, torps, etc... are all affected by this setting. ";
      echo "<BR>&nbsp;&nbsp;&nbsp; The <B>Active</B> checkbox will default to checked. ";
      echo "This box refers to if the Furangee AI system will see this Furangee and execute it's orders. ";
      echo "If this box is not checked then the Furangee AI system will ignore this record and the next two fields are ignored. ";
      echo "<BR>&nbsp;&nbsp;&nbsp; The <B>Orders</B> selection box will default to 'SENTINEL'. ";
      echo "There are three other options available: ROAM, ROAM AND TRADE, and ROAM AND HUNT. ";
      echo "These Orders and what they mean will be detailed below. ";
      echo "<BR>&nbsp;&nbsp;&nbsp; The <B>Aggression</B> selection box will default to 'PEACEFUL'. ";
      echo "There are two other options available: ATTACK SOMETIMES, and ATTACK ALWAYS. ";
      echo "These Aggression settings and what they mean will be detailed below. ";
      echo "<BR>&nbsp;&nbsp;&nbsp; Pressing the <B>Create</B> button will create the Furangee and return to the creation screen to create another. ";

      echo "<H3>Furangee Orders</H3>";
      echo "<P> Here are the Furangee Order options and what the Furangee AI system will do for each: ";
      echo "<UL>SENTINEL<BR> ";
      echo "This Furangee will stay in place.  His only interactions will be with those who are in his sector at the time he takes his turn. ";
      echo "The aggression level will determine what those player interactions are.</UL> ";
      echo "<UL>ROAM<BR> ";
      echo "This Furangee will warp from sector to sector looking for players to interact with. ";
      echo "The aggression level will determine what those player interactions are.</UL> ";
      echo "<UL>ROAM AND TRADE<BR> ";
      echo "This Furangee will warp from sector to sector looking for players to interact with and ports to trade with. ";
      echo "The Furangee will trade at a port if possible before looking for player interactions. ";
      echo "The aggression level will determine what those player interactions are.</UL> ";
      echo "<UL>ROAM AND HUNT<BR> ";
      echo "This Furangee has a taste for blood and likes the sport of a good hunt. ";
      echo "Ocassionally (around 1/4th the time) this Furangee has the urge to go hunting.  He will randomly choose one of the top ten players to hunt. ";
      echo "If that player is in a sector that allows attack, then the Furangee warps there and attacks. ";
      echo "When he is not out hunting this Furangee acts just like one with ROAM orders.</UL> "; 

      echo "<H3>Furangee Aggression</H3>";
      echo "<P> Here are the Furangee Aggression levels and what the Furangee AI system will do for each: ";
      echo "<UL>PEACEFUL<BR> ";
      echo "This Furangee will not attack players.  He will continue to roam or trade as ordered but will not launch any attacks. ";
      echo "If this Furangee is a hunter then he will still attack players on the hunt but never otherwise.</UL> ";
      echo "<UL>ATTACK SOMETIMES<BR> ";
      echo "This Furangee will compare it's current number of fighters to a players fighters before deciding to attack. ";
      echo "If the Furangee's fighters are greater then the player's, then the Furangee will attack the player.</UL> ";
      echo "<UL>ATTACK ALWAYS<BR> ";
      echo "This Furangee is just mean.  He will attack anyone he comes across regardless of the odds.</UL> ";

    }
    // ***********************************************
    // ********* START OF FURANGEE EDIT SUB ***********
    // ***********************************************
    elseif($module == "furangeeedit")
    {
      echo "<span style=\"font-family : courier, monospace; font-size: 12pt; color: #00FF00 \">Furangee Editor</span><BR>";
      echo "<FORM ACTION=furangee_control.php METHOD=POST>";
      if(empty($user))
      {
        echo "<SELECT SIZE=20 NAME=user>";
$res = $db->Execute("SELECT * FROM {$db_prefix}players LEFT JOIN {$db_prefix}npc_player ON " .
					"{$db_prefix}players.player_id = {$db_prefix}npc_player.npc_id LEFT JOIN " .
					"{$db_prefix}ships ON {$db_prefix}players.currentship = {$db_prefix}ships.ship_id " .
					"WHERE {$db_prefix}npc_player.active='Y' AND {$db_prefix}players.destroyed='N' ORDER BY character_name ASC");
        while(!$res->EOF)
        {
          $row=$res->fields;
          $charnamelist = sprintf("%-20s", $row[character_name]);
          $charnamelist = str_replace("  ", "&nbsp;&nbsp;",$charnamelist);
          $sectorlist = sprintf("Sector %'04d&nbsp;&nbsp;", $row[sector]);
          if ($row[active] == "Y") { $activelist = "Active &Oslash;&nbsp;&nbsp;"; } else { $activelist = "Active O&nbsp;&nbsp;"; }
          if ($row[ship_destroyed] == "Y") { $destroylist = "Destroyed &Oslash;&nbsp;&nbsp;"; } else { $destroylist = "Destroyed O&nbsp;&nbsp;"; }
          printf ("<OPTION VALUE=%s>%s %s %s %s</option>", $row[email], $activelist, $destroylist, $sectorlist, $charnamelist);
          $res->MoveNext();
        }
        echo "</SELECT>";
        echo "&nbsp;<INPUT TYPE=SUBMIT VALUE=Edit>";
      }
      else
      {
        if(empty($operation))
        {
 $res = $db->Execute("SELECT * FROM {$db_prefix}players LEFT JOIN {$db_prefix}npc_player ON " .
					"{$db_prefix}players.player_id = {$db_prefix}npc_player.npc_id LEFT JOIN " .
					"{$db_prefix}ships ON {$db_prefix}players.currentship = {$db_prefix}ships.ship_id " .
					"WHERE {$db_prefix}npc_player.active='Y' AND {$db_prefix}players.destroyed='N' ORDER BY character_name ASC");
          $row = $res->fields;
	  $org_password = ($row[password]);
	  $set_password = ($row[password]);
echo "	<table border=\"0\" width=\"100%\" cellspacing=\"0\" cellpadding=\"0\">\n";
echo "		<tr>\n";
echo "			<td>\n";
echo "			<table cellSpacing=\"0\" cellPadding=\"0\" width=\"100%\" border=\"0\">\n";
echo "				<tr bgColor=\"$color_header\">\n";
echo "					<td><b>Furangee Name: </b><INPUT TYPE=TEXT NAME=character_name VALUE=\"$row[character_name]\"></td>\n";
echo "					<td align=\"middle\"><b>Ship Name: </b><INPUT TYPE=TEXT NAME=ship_name VALUE=\"$row[ship_name]\"></td>\n";
echo "					<td align=\"right\"><b>Credits: </b><INPUT TYPE=TEXT NAME=credits VALUE=\"$row[credits]\"></td>\n";
echo "					<td align=\"right\"><b>Password: </b><INPUT SIZE=32 TYPE=TEXT NAME=set_password></td>\n";
echo "				</tr>\n";
echo "			</table>\n";
echo "			</td>\n";
echo "		</tr>\n";
echo "	</table>\n";
echo "	<table border=\"0\" width=\"100%\" cellspacing=\"0\" cellpadding=\"0\">\n";
echo "		<tr bgcolor=\"$color_line1\">\n";
echo "			<td>ID</td>\n";
echo "			<td>$row[ship_id]</td>\n";
echo "			<td>Turns Available</td>\n";
echo "			<td><INPUT TYPE=TEXT SIZE=6 MAXLENGTH=6 NAME=turns VALUE=\"$row[turns]\"></td>\n";
echo "			<td>Aggression</td>\n";
echo "			<td>\n";
                             $oaggr0 = $oaggr1 = $oaggr2 = "VALUE";
                             if ($row[aggression] == 0) $oaggr0 = "SELECTED=0 VALUE";
                             if ($row[aggression] == 1) $oaggr1 = "SELECTED=1 VALUE";
                             if ($row[aggression] == 2) $oaggr2 = "SELECTED=2 VALUE";
echo "                       <SELECT SIZE=1 LENGTH=20 NAME=aggression>\n";
echo "                       <OPTION $oaggr0=0>Peaceful</option>\n";
echo "                       <OPTION $oaggr1=1>Attack Sometimes</option>\n";
echo "                       <OPTION $oaggr2=2>Attack Always</option>\n";
echo "                       </SELECT>\n";
echo "                                </td>\n";
echo "		</tr>\n";
echo "		<tr bgcolor=\"$color_line2\">\n";
echo "			<td>E-mail</td>\n";
echo "			<td>$row[email]</td>\n";
echo "			<td>Turns Used</td>\n";
echo "			<td>\n";
echo "			<INPUT TYPE=TEXT SIZE=6 MAXLENGTH=6 NAME=turns_used VALUE=\"$row[turns_used]\"></td>\n";
echo "			<td>Orders</td>\n";
echo "			<td>\n";
                             $oorder0 = $oorder1 = $oorder2 = $oorder3 = "VALUE";
                             if ($row[orders] == 0) $oorder0 = "SELECTED=0 VALUE";
                             if ($row[orders] == 1) $oorder1 = "SELECTED=1 VALUE";
                             if ($row[orders] == 2) $oorder2 = "SELECTED=2 VALUE";
                             if ($row[orders] == 3) $oorder3 = "SELECTED=3 VALUE";
echo "                       <SELECT SIZE=1 LENGTH=20 NAME=orders>\n";
echo "                       <OPTION $oorder0=0>Sentinel</option>\n";
echo "                       <OPTION $oorder1=1>Roam\n\n";
echo "                       <OPTION $oorder2=2>Roam and Trade</option>\n";
echo "                       <OPTION $oorder3=3>Roam and Hunt</option>\n";
echo "                       </SELECT>\n";
echo "                  </td>\n";
echo "		</tr>\n";
echo "		<tr bgcolor=\"$color_line1\">\n";
echo "			<td>Active?</td>\n";
echo "			<td><INPUT TYPE=CHECKBOX NAME=active VALUE=ON " . CHECKED($row[active]) . "></td>\n";
echo "			<td>Total Turns</td>\n";
echo "			<td><INPUT TYPE=TEXT SIZE=6 MAXLENGTH=6 NAME=turns_total VALUE=\"$row[turns_total]\"></td>\n";
echo "			<td>Furangee Kills</td>\n";
echo "			<td><INPUT TYPE=TEXT SIZE=6 MAXLENGTH=6 NAME=fk VALUE=\"$row[fk]\"></td>\n";
echo "		</tr>\n";
echo "		<tr bgcolor=\"$color_line2\">\n";
echo "			<td>Destroyed?</td>\n";
echo "			<td><INPUT TYPE=CHECKBOX NAME=ship_destroyed VALUE=ON " . CHECKED($row[ship_destroyed]) . "></td>\n";
echo "			<td>Sector</td>\n";
echo "			<td><INPUT TYPE=TEXT SIZE=6 MAXLENGTH=6 NAME=sector VALUE=\"$row[sector]\"></td>\n";
echo "			<td>Player Kills</td>\n";
echo "			<td><INPUT TYPE=TEXT SIZE=6 MAXLENGTH=6 NAME=pk VALUE=\"$row[pk]\"></td>\n";
echo "		</tr>\n";
echo "	</table>\n";
echo "	<br>\n";
echo "	<table cellSpacing=\"5\" cellPadding=\"0\" width=\"100%\" border=\"0\">\n";
echo "		<tr>\n";
echo "			<td>\n";
echo "			<table cellSpacing=\"0\" cellPadding=\"0\" width=\"100%\" border=\"0\">\n";
echo "				<tr bgColor=\"$color_header\">\n";
echo "					<td><b>Ship Component Levels</b></td>\n";
echo "					<td>&nbsp;</td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Hull</td>\n";
echo "					<td align=\"left\">";
echo "						<SELECT SIZE=1 NAME=hull>";
							options ($row[hull]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Engines</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=engines VALUE=\"$row[engines]\">"; 
							options ($row[engines]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Power</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=power VALUE=\"$row[power]\">"; 
							options ($row[power]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Computer</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=computer VALUE=\"$row[computer]\">"; 
							options ($row[computer]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Sensors</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=sensors VALUE=\"$row[sensors]\">"; 
							options ($row[sensors]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Armor</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=armour VALUE=\"$row[armour]\">"; 
							options ($row[armour]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Shields</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=shields VALUE=\"$row[shields]\">"; 
							options ($row[shields]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Beam Weapons</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=beams VALUE=\"$row[beams]\">"; 
							options ($row[beams]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Torpedo Launchers</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=torp_launchers VALUE=\"$row[torp_launchers]\">"; 
							options ($row[torp_launchers]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Cloak</td>\n";
echo "					<td align=\"left\">
							<SELECT SIZE=1 NAME=cloak VALUE=\"$row[cloak]\">"; 
							options ($row[cloak]);
echo "						</SELECT></td>\n";
echo "				</tr>\n";

$shipavg = $row[hull] + $row[engines] + $row[computer] + $row[beams] + $row[torp_launchers] + $row[shields] + $row[armour];
$shipavg /= 7;

echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td><i>Average Tech Level</i></td>\n";
echo "					<td>" . NUMBER($shipavg, 2) . "</td>\n";
echo "				</tr>\n";
echo "			</table>\n";
echo "			</td>\n";
echo "			<td vAlign=\"top\">\n";
echo "			<table cellSpacing=\"0\" cellPadding=\"0\" width=\"100%\" border=\"0\">\n";

$holds_used = $row[ship_ore] + $row[ship_organics] + $row[ship_goods] + $row[ship_colonists];
$holds_max = NUM_HOLDS($row[hull]);

echo "				<tr bgColor=\"$color_header\">\n";
echo "					<td><b>Holds</b></td>\n";
echo "					<td align=\"right\"><b>" . NUMBER($holds_used) . " / " . NUMBER($holds_max) . "</b></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Ore</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=ship_ore VALUE=\"$row[ship_ore]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Organics</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=ship_organics VALUE=\"$row[ship_organics]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Goods</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=ship_goods VALUE=\"$row[ship_goods]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Colonists</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=ship_colonists VALUE=\"$row[ship_colonists]\"></td>\n";
echo "				</tr>\n";
echo "				<tr>\n";
echo "					<td>&nbsp;</td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td><b>Armor &amp; Weapons</b></td>\n";
echo "					<td>&nbsp;</td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";

$armour_pts_max = NUM_ARMOUR($row[armour]);

echo "					<td>Armor Points</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=armour_pts VALUE=\"$row[armour_pts]\"> / " . NUMBER($armour_pts_max) . "</td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";

$ship_fighters_max = NUM_FIGHTERS($row[computer]);

echo "					<td>Fighters </td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=ship_fighters VALUE=\"$row[ship_fighters]\"> / " . NUMBER($ship_fighters_max) . "</td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";

$torps_max = NUM_TORPEDOES($row[torp_launchers]);

echo "					<td>Torpedoes</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=torps VALUE=\"$row[torps]\"> / " . NUMBER($torps_max) . "</td>\n";
echo "				</tr>\n";
echo "			</table>\n";
echo "			</td>\n";
echo "			<td vAlign=\"top\">\n";
echo "			<table cellSpacing=\"0\" cellPadding=\"0\" width=\"100%\" border=\"0\">\n";
echo "				<tr bgColor=\"$color_header\">\n";
echo "					<td><b>Energy</b></td>\n";

$energy_max = NUM_ENERGY($row[power]);

echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=ship_energy VALUE=\"$row[ship_energy]\"> / " . NUMBER($energy_max) . "</td>\n";
echo "				</tr>\n";
echo "				<tr>\n";
echo "					<td>&nbsp;</td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_header\">\n";
echo "					<td><b>Devices</b></td>\n";
echo "					<td></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Space Beacons</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=5 NAME=dev_beacon VALUE=\"$row[dev_beacon]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Warp Editors</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=5 NAME=dev_warpedit VALUE=\"$row[dev_warpedit]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Genesis Torpedoes</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=5 NAME=dev_genesis VALUE=\"$row[dev_genesis]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Mine Deflectors</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=10 NAME=dev_minedeflector VALUE=\"$row[dev_minedeflector]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Emergency Warp Device</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=TEXT SIZE=5 NAME=dev_emerwarp VALUE=\"$row[dev_emerwarp]\"></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Escape Pod</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=CHECKBOX NAME=dev_escapepod VALUE=ON " . CHECKED($row[dev_escapepod]) . "></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line2\">\n";
echo "					<td>Fuel Scoop</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=CHECKBOX NAME=dev_fuelscoop VALUE=ON " . CHECKED($row[dev_fuelscoop]) . "></td>\n";
echo "				</tr>\n";
echo "				<tr bgColor=\"$color_line1\">\n";
echo "					<td>Last ship seen device</td>\n";
echo "					<td align=\"right\"><INPUT TYPE=CHECKBOX NAME=dev_lssd VALUE=ON " . CHECKED($row[dev_lssd]) . "></td>\n";
echo "				</tr>\n";
echo "			</table>\n";
echo "			</td>\n";
echo "		</tr>\n";
echo "	</table>\n";
echo "	<p align=\"center\">\n";

     $result = $db->Execute("SELECT * FROM $dbtables[ships] WHERE ship_id='$row[ship_id]'");
     $playerinfo=$result->fields;
	{
	$shiptypes[0]= "ship_00.gif";
	$shiptypes[1]= "ship_08.gif";
	$shiptypes[2]= "ship_12.gif";
	$shiptypes[3]= "ship_16.gif";
	$shiptypes[4]= "ship_20.gif";
	$shiptypes[5]= "ship_30.gif";
	$shiptypes[6]= "ship_40.gif";
	$shiptypes[7]= "ship_50.gif";
 	}
	if($shipavg < 8)
	$shiplevel = 0;
	else if ($shipavg < 12)
	$shiplevel = 1;
	else if ($shipavg < 16)
	$shiplevel = 2;
	else if ($shipavg < 20)
	$shiplevel = 3;
	else if ($shipavg < 30)
	$shiplevel = 4;
	else if ($shipavg <40)
	$shiplevel = 5;
	else if ($shipavg < 50)
	$shiplevel = 6;
	else
	$shiplevel = 7;

echo "  <table border=\"0\" width=\"100%\" cellspacing=\"0\" cellpadding=\"0\">\n";
echo "		<tr>\n";
echo "			<td align=\"left\" valign=\"top\" width=\"250\">\n";
echo "				<INPUT TYPE=HIDDEN NAME=user VALUE=$user>\n";
echo "				<INPUT TYPE=HIDDEN NAME=org_password VALUE=$org_password>\n";
echo "				<INPUT TYPE=HIDDEN NAME=operation VALUE=save>\n";
echo "				<INPUT TYPE=SUBMIT VALUE=Save>\n";
echo "				<br>\n";
echo "				<INPUT TYPE=SUBMIT VALUE=\"Return to Furangee editor\">\n";
					$button_main = false;
echo "			</td>\n";
echo "			<td align=\"center\" valign=\"top\"><img src=\"images/$shiptypes[$shiplevel]\" border=0>\n";
echo "			<td width=\"250\">&nbsp;</td>\n";
echo "		</tr>\n";
echo "  </table>\n";

          //******************************
          //*** SHOW FURANGEE LOG DATA ***
          //******************************
          echo "<HR>";
          echo "<span style=\"font-family : courier, monospace; font-size: 12pt; color: #00FF00;\">Log Data For This Furangee</span><BR>";

          $logres = $db->Execute("SELECT * FROM $dbtables[logs] WHERE ship_id=$row[ship_id] ORDER BY time DESC, type DESC");   
          while(!$logres->EOF)
          {
            $logrow = $logres->fields;
            $logtype = "";
            switch($logrow[type])
            {
              case LOG_FURANGEE_ATTACK:
                $logtype = "Launching an attack on ";
                break;
              case LOG_ATTACK_LOSE:
                $logtype = "We were attacked and lost against ";
                break;
              case LOG_ATTACK_WIN:
                $logtype = "We were attacked and won against ";
                break;
            }
            $logdatetime = substr($logrow[time], 4, 2) . "/" . substr($logrow[time], 6, 2) . "/" . substr($logrow[time], 0, 4) . " " . substr($logrow[time], 8, 2) . ":" . substr($logrow[time], 10, 2) . ":" . substr($logrow[time], 12, 2);
            echo "$logdatetime $logtype$logrow[data] <BR>";
            $logres->MoveNext();
          }
        }
        elseif($operation == "save")
        {
          // update database
          $_ship_destroyed = empty($ship_destroyed) ? "N" : "Y";
          $_dev_escapepod = empty($dev_escapepod) ? "N" : "Y";
          $_dev_fuelscoop = empty($dev_fuelscoop) ? "N" : "Y";
          $_dev_lssd = empty($dev_lssd) ? "N" : "Y";
          $_active = empty($active) ? "N" : "Y";

  	  if ($set_password == "")
		{
		$set_password = $org_password;
		} else {
		$set_password = md5($set_password);
		}


          $result = $db->Execute("UPDATE $dbtables[ships] SET character_name='$character_name',ship_name='$ship_name',password='$set_password',ship_destroyed='$_ship_destroyed',pk='$pk',fk='$fk',hull='$hull',engines='$engines',power='$power',computer='$computer',sensors='$sensors',armour='$armour',shields='$shields',beams='$beams',torp_launchers='$torp_launchers',cloak='$cloak',credits='$credits',turns='$turns',turns_total='$turns_total',turns_used='$turns_used',dev_lssd='$_dev_lssd',dev_warpedit='$dev_warpedit',dev_genesis='$dev_genesis',dev_beacon='$dev_beacon',dev_emerwarp='$dev_emerwarp',dev_escapepod='$_dev_escapepod',dev_fuelscoop='$_dev_fuelscoop',dev_minedeflector='$dev_minedeflector',sector='$sector',ship_ore='$ship_ore',ship_organics='$ship_organics',ship_goods='$ship_goods',ship_energy='$ship_energy',ship_colonists='$ship_colonists',ship_fighters='$ship_fighters',torps='$torps',armour_pts='$armour_pts' WHERE email='$user'");
          if(!$result) {
            echo "Changes to Furangee ship record have FAILED Due to the following Error:<BR><BR>";
            echo $db->ErrorMsg() . "<br>";
          } else {
            echo "Changes to Furangee ship record have been saved.<BR><BR>";
            $result2 = $db->Execute("UPDATE $dbtables[furangee] SET active='$_active',orders='$orders',aggression='$aggression' WHERE furangee_id='$user'");
            if(!$result2) {
              echo "Changes to Furangee activity record have FAILED Due to the following Error:<BR><BR>";
              echo $db->ErrorMsg() . "<br>";
            } else {
              echo "Changes to Furangee activity record have been saved.<BR><BR>";
            }
          }
          echo "<INPUT TYPE=SUBMIT VALUE=\"Return to Furangee editor\">";
          $button_main = false;
        }
        else
        {
          echo "Invalid operation";
        }
      }
      echo "<INPUT TYPE=HIDDEN NAME=menu VALUE=furangeeedit>";
      echo "<INPUT TYPE=HIDDEN NAME=swordfish VALUE=$swordfish>";
      echo "</FORM>";
    }
    // ***********************************************
    // ******** START OF DROP FURANGEE SUB ***********
    // ***********************************************
    elseif($module == "dropfurangee")
    {
      echo "<H1>Drop and Re-Install Furangee Database</H1>";
      echo "<H3>This will DELETE All Furangee records from the <i>ships</i> TABLE then DROP and reset the <i>furangee</i> TABLE</H3>";
      echo "<FORM ACTION=furangee_control.php METHOD=POST>";
      if(empty($operation))
      {
        echo "<BR>";
        echo "<H2><FONT COLOR=Red>Are You Sure?</FONT></H2><BR>";
        echo "<INPUT TYPE=HIDDEN NAME=operation VALUE=dropfur>";
        echo "<INPUT TYPE=SUBMIT VALUE=Drop>";
      }
      elseif($operation == "dropfur")
      {
        // Delete all furangee in the ships table
        echo "Deleting furangee records in the ships table...<BR>";
        $db->Execute("DELETE FROM $dbtables[ships] WHERE email LIKE '%@furangee'");
        echo "deleted.<BR>";
        // Drop furangee table
        echo "Dropping furangee table...<BR>";
        $db->Execute("DROP TABLE IF EXISTS $dbtables[furangee]");
        echo "dropped.<BR>";
        // Create furangee table
        echo "Re-Creating table: furangee...<BR>";
        $db->Execute("CREATE TABLE $dbtables[furangee](" .
            "furangee_id char(40) NOT NULL," .
            "active enum('Y','N') DEFAULT 'Y' NOT NULL," .
            "aggression smallint(5) DEFAULT '0' NOT NULL," .
            "orders smallint(5) DEFAULT '0' NOT NULL," .
            "PRIMARY KEY (furangee_id)," .
            "KEY furangee_id (furangee_id)" .
            ")");
        echo "created.<BR>";
      }
      else
      {
        echo "Invalid operation";
      }
      echo "<INPUT TYPE=HIDDEN NAME=menu VALUE=dropfurangee>";
      echo "<INPUT TYPE=HIDDEN NAME=swordfish VALUE=$swordfish>";
      echo "</FORM>";
    }
    // ***********************************************
    // ***** START OF CLEAR FURANGEE LOG SUB *********
    // ***********************************************
    elseif($module == "clearlog")
    {
      echo "<H1>Clear All Furangee Logs</H1>";
      echo "<H3>This will DELETE All Furangee log files</H3>";
      echo "<FORM ACTION=furangee_control.php METHOD=POST>";
      if(empty($operation))
      {
        echo "<BR>";
        echo "<H2><FONT COLOR=Red>Are You Sure?</FONT></H2><BR>";
        echo "<INPUT TYPE=HIDDEN NAME=operation VALUE=clearfurlog>";
        echo "<INPUT TYPE=SUBMIT VALUE=Clear>";
      }
      elseif($operation == "clearfurlog")
      {
 $res = $db->Execute("SELECT * FROM {$db_prefix}players LEFT JOIN {$db_prefix}npc_player ON " .
					"{$db_prefix}players.player_id = {$db_prefix}npc_player.npc_id LEFT JOIN " .
					"{$db_prefix}ships ON {$db_prefix}players.currentship = {$db_prefix}ships.ship_id " .
					"WHERE {$db_prefix}npc_player.active='Y' AND {$db_prefix}players.destroyed='N' ORDER BY character_name ASC");
        while(!$res->EOF)
        {
          $row = $res->fields;
          $db->Execute("DELETE FROM $dbtables[logs] WHERE ship_id=$row[ship_id]");
          echo "Log for ship_id $row[ship_id] cleared.<BR>";
          $res->MoveNext();
        }
      }
      else
      {
        echo "Invalid operation";
      }
      echo "<INPUT TYPE=HIDDEN NAME=menu VALUE=clearlog>";
      echo "<INPUT TYPE=HIDDEN NAME=swordfish VALUE=$swordfish>";
      echo "</FORM>";
    }
    // ***********************************************
    // ******** START OF CREATE FURANGEE SUB **********
    // ***********************************************
    elseif($module == "createnew")
    {
      echo "<B>Create A New Furangee</B>";
      echo "<BR>";
      echo "<FORM ACTION=furangee_control.php METHOD=POST>";
      if(empty($operation))
      {
        // Create Furangee Name
        $Sylable1 = array("Ak","Al","Ar","B","Br","D","F","Fr","G","Gr","K","Kr","N","Ol","Om","P","Qu","R","S","Z");
        $Sylable2 = array("a","ar","aka","aza","e","el","i","in","int","ili","ish","ido","ir","o","oi","or","os","ov","u","un");
        $Sylable3 = array("ag","al","ak","ba","dar","g","ga","k","ka","kar","kil","l","n","nt","ol","r","s","ta","til","x");
        $sy1roll = rand(0,19);
        $sy2roll = rand(0,19);
        $sy3roll = rand(0,19);
        $character = $Sylable1[$sy1roll] . $Sylable2[$sy2roll] . $Sylable3[$sy3roll];
        $ADODB_FETCH_MODE = ADODB_FETCH_NUM;
        $resultnm = $db->Execute ("select character_name from $dbtables[ships] where character_name='$character'");
        $namecheck = $resultnm->fields;
        $ADODB_FETCH_MODE = ADODB_FETCH_ASSOC;
        $nametry = 1;
        // If Name Exists Try Again - Up To Nine Times
        while (($namecheck[0]) and ($nametry <= 9)) {
          $sy1roll = rand(0,19);
          $sy2roll = rand(0,19);
          $sy3roll = rand(0,19);
          $character = $Sylable1[$sy1roll] . $Sylable2[$sy2roll] . $Sylable3[$sy3roll];
          $ADODB_FETCH_MODE = ADODB_FETCH_NUM;
          $resultnm = $db->Execute ("select character_name from $dbtables[ships] where character_name='$character'");
          $namecheck = $resultnm->fields;
          $ADODB_FETCH_MODE = ADODB_FETCH_ASSOC;
          $nametry++;
        }
        // Create Ship Name
        $shipname = "Furangee-" . $character; 
        // Select Random Sector
        $sector = rand(1,$sector_max); 
        // Display Confirmation Form
        echo "<TD><TABLE BORDER=0 CELLSPACING=0 CELLPADDING=5>";
        echo "<TR><TD>Furangee Name</TD><TD><INPUT TYPE=TEXT SIZE=20 NAME=character VALUE=$character></TD>";
        echo "<TD>Level <INPUT TYPE=TEXT SIZE=5 NAME=furlevel VALUE=3></TD>";
        echo "<TD>Ship Name <INPUT TYPE=TEXT SIZE=20 NAME=shipname VALUE=$shipname></TD>";
        echo "<TR><TD>Active?<INPUT TYPE=CHECKBOX NAME=active VALUE=ON CHECKED ></TD>";
        echo "<TD>Orders ";
          echo "<SELECT SIZE=20 NAME=orders>";
          echo "<OPTION SELECTED=0 VALUE=0>Sentinel</option>";
          echo "<OPTION VALUE=1>Roam\n";
          echo "<OPTION VALUE=2>Roam and Trade</option>";
          echo "<OPTION VALUE=3>Roam and Hunt</option>";
          echo "</SELECT></TD>";
        echo "<TD>Sector <INPUT TYPE=TEXT SIZE=5 NAME=sector VALUE=$sector></TD>";
        echo "<TD>Aggression ";
          echo "<SELECT SIZE=20 NAME=aggression>";
          echo "<OPTION SELECTED=0 VALUE=0>Peaceful</option>";
          echo "<OPTION VALUE=1>Attack Sometimes</option>";
          echo "<OPTION VALUE=2>Attack Always</option>";
          echo "</SELECT></TD></TR>";
        echo "</TABLE>";
        echo "<HR>";
        echo "<INPUT TYPE=HIDDEN NAME=operation VALUE=createfurangee>";
        echo "<INPUT TYPE=SUBMIT VALUE=Create>";
      }
      elseif($operation == "createfurangee")
      {
        // update database
        $_active = empty($active) ? "N" : "Y";
        $errflag=0;
        if ( $character=='' || $shipname=='' ) { echo "Ship name, and character name may not be blank.<BR>"; $errflag=1;}
        // Change Spaces to Underscores in shipname
        $shipname = str_replace(" ","_",$shipname);
        // Create emailname from character
        $emailname = str_replace(" ","_",$character) . "@furangee";
        $ADODB_FETCH_MODE = ADODB_FETCH_NUM;
        $result = $db->Execute ("select email, character_name, ship_name from $dbtables[ships] where email='$emailname' OR character_name='$character' OR ship_name='$shipname'");
        if ($result>0)
        {
          while (!$result->EOF)
          {
            $row= $result->fields;
            if ($row[0]==$emailname) { echo "ERROR: E-mail address $emailname, is already in use.  "; $errflag=1;}
            if ($row[1]==$character) { echo "ERROR: Character name $character, is already in use.<BR>"; $errflag=1;}
            if ($row[2]==$shipname) { echo "ERROR: Ship name $shipname, is already in use.<BR>"; $errflag=1;}
            $result->MoveNext();
          }
        }
        $ADODB_FETCH_MODE = ADODB_FETCH_ASSOC;
        if ($errflag==0)
        {
          $makepass="";
          $syllables="er,in,tia,wol,fe,pre,vet,jo,nes,al,len,son,cha,ir,ler,bo,ok,tio,nar,sim,ple,bla,ten,toe,cho,co,lat,spe,ak,er,po,co,lor,pen,cil,li,ght,wh,at,the,he,ck,is,mam,bo,no,fi,ve,any,way,pol,iti,cs,ra,dio,sou,rce,sea,rch,pa,per,com,bo,sp,eak,st,fi,rst,gr,oup,boy,ea,gle,tr,ail,bi,ble,brb,pri,dee,kay,en,be,se";
          $syllable_array=explode(",", $syllables);
          srand((double)microtime()*1000000);
          for ($count=1;$count<=4;$count++) {
            if (rand()%10 == 1) {
              $makepass .= sprintf("%0.0f",(rand()%50)+1);
            } else {
              $makepass .= sprintf("%s",$syllable_array[rand()%62]);
            }
          }
          if ($furlevel=='') $furlevel=0;
          $maxenergy = NUM_ENERGY($furlevel);
          $maxarmour = NUM_ARMOUR($furlevel);
          $maxfighters = NUM_FIGHTERS($furlevel);
          $maxtorps = NUM_TORPEDOES($furlevel);
          $stamp=date("Y-m-d H:i:s");
// *****************************************************************************
// *** ADD FURANGEE RECORD TO ships TABLE ... MODIFY IF ships SCHEMA CHANGES ***
// *****************************************************************************
          $result2 = $db->Execute("INSERT INTO $dbtables[ships] VALUES('','$shipname','N','$character','$makepass','$emailname',$furlevel,$furlevel,$furlevel,$furlevel,$furlevel,$furlevel,$furlevel,$maxtorps,$furlevel,$furlevel,$maxarmour,$furlevel,$start_credits,$sector,0,0,0,$maxenergy,0,$maxfighters,$start_turns,'','N',0,0,0,0,'N','N',0,0, '$stamp',0,0,0,0,'N','127.0.0.1',0,0,0,0,'Y','N','N','Y','','$default_lang','Y','N',-1,'N')");
          if(!$result2) {
            echo $db->ErrorMsg() . "<br>";
          } else {
            echo "Furangee has been created.<BR><BR>";
            echo "Password has been set.<BR><BR>";
            echo "Ship Records have been updated.<BR><BR>";
          }
          $result3 = $db->Execute("INSERT INTO $dbtables[furangee] (furangee_id,active,aggression,orders) VALUES('$emailname','$_active','$aggression','$orders')");
          if(!$result3) {
            echo $db->ErrorMsg() . "<br>";
          } else {
            echo "Furangee Records have been updated.<BR><BR>";
          }
        }
        echo "<INPUT TYPE=SUBMIT VALUE=\"Return to Furangee Creator \">";
        $button_main = false;
      }
      else
      {
        echo "Invalid operation";
      }
      echo "<INPUT TYPE=HIDDEN NAME=menu VALUE=createnew>";
      echo "<INPUT TYPE=HIDDEN NAME=swordfish VALUE=$swordfish>";
      echo "</FORM>";
    }
    else
    {
      echo "Unknown function";
    }

    if($button_main)
    {
      echo "<BR><BR>";
      echo "<FORM ACTION=furangee_control.php METHOD=POST>";
      echo "<INPUT TYPE=HIDDEN NAME=swordfish VALUE=$swordfish>";
      echo "<INPUT TYPE=SUBMIT VALUE=\"Return to main menu\">";
      echo "</FORM>";
    }
  }
}
  
function options($tech)
	{
		$option = 0;
		while ($option < 61)
			{
				if ($option == $tech) {
					echo "<option selected>$option</option>";
				} else {
					echo "<option>$option</option>";
				}
			$option = ($option+1);
			}
	}		

?> 
