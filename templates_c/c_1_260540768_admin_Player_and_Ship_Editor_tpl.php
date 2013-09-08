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
<table border=0 cellspacing=0 cellpadding=0 width="600">
  <tr>
    <td>Player name: </td>
    <td><input type="text" name="character_name" value="<?php echo $this->_vars['character_name']; ?>" size="32" maxlength="25"></td>
  </tr>
  <tr>
    <td>Password: </td>
    <td><input type="text" name="password2" value="<?php echo $this->_vars['password']; ?>" size="32" maxlength="<?php echo $this->_vars['maxlen_password']; ?>"></td>
  </tr>
  <tr>
    <td>E-mail: </td>
    <td><input type="text" name="email" value="<?php echo $this->_vars['email']; ?>"></td>
  </tr>
  <tr>
    <td>ID: </td>
    <td><?php echo $this->_vars['user']; ?></td>
  </tr>
  <tr>
    <td>Ship ID: </td>
    <td><input type="hidden" name="currentship_id" value="<?php echo $this->_vars['currentship_id']; ?>"><?php echo $this->_vars['currentship_id']; ?></td>
  </tr>
  <tr>
    <td>Ship: </td>
    <td><input type="text" name="ship_name" value="<?php echo $this->_vars['shipname']; ?>"></td>
  </tr>
  <tr>
    <td>Ship Class: </td>
    <td><input type="text" name="ship_class" value="<?php echo $this->_vars['ship_class']; ?>"></td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td>Player Status? </td>
    <td>
	<input type="radio" name="destroyed" value="N"<?php if ($this->_vars['destroyed'] == "N"): ?> checked<?php endif; ?>>Alive<br>
	<input type="radio" name="destroyed" value="K"<?php if ($this->_vars['destroyed'] == "K"): ?> checked<?php endif; ?>>Killed with Escape Pod<br>
	<input type="radio" name="destroyed" value="Y"<?php if ($this->_vars['destroyed'] == "Y"): ?> checked<?php endif; ?>>Killed without Escape Pod (out of game)
  	</td>
  </tr> 
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td>Extended Admin Logging: </td>
    <td>
	<input type="radio" name="admin_extended_logging" value="0"<?php if ($this->_vars['admin_extended_logging'] == "0"): ?> checked<?php endif; ?>>Disabled<br>
	<input type="radio" name="admin_extended_logging" value="1"<?php if ($this->_vars['admin_extended_logging'] == "1"): ?> checked<?php endif; ?>>Enabled<br>
  	</td>
  </tr> 
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td nowrap>Damaged Levels</td>
    <td nowrap>
      <table border=0 cellspacing=0 cellpadding=5>
        <tr>
          <td>Hull: </td>
          <td><input type=text size=5 name="hull" value="<?php echo $this->_vars['hull']; ?>"></td>
          <td>Engines: </td>
          <td><input type=text size=5 name="engines" value="<?php echo $this->_vars['engines']; ?>"></td>
          <td>Power: </td>
          <td><input type=text size=5 name="power" value="<?php echo $this->_vars['power']; ?>"></td>
          <td>Fighter Bay: </td>
          <td><input type=text size=5 name="fighter" value="<?php echo $this->_vars['fighter']; ?>"></td>
        </tr>
        <tr>
          <td>Sensors: </td>
          <td><input type=text size=5 name="sensors" value="<?php echo $this->_vars['sensors']; ?>"></td>
          <td>armor: </td>
          <td><input type=text size=5 name="armor" value="<?php echo $this->_vars['armor']; ?>"></td>
          <td>Shields: </td>
          <td><input type=text size=5 name="shields" value="<?php echo $this->_vars['shields']; ?>"></td>
          <td>Beams: </td>
          <td><input type=text size=5 name="beams" value="<?php echo $this->_vars['beams']; ?>"></td>
        </tr>
        <tr>
          <td>Torpedo Launchers: </td>
          <td><input type=text size=5 name="torp_launchers" value="<?php echo $this->_vars['torp_launchers']; ?>"></td>
          <td>Cloak: </td>
          <td><input type=text size=5 name="cloak" value="<?php echo $this->_vars['cloak']; ?>"></td>
          <td>ECM: </td>
          <td><input type=text size=5 name="ecm" value="<?php echo $this->_vars['ecm']; ?>"></td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td nowrap>Normal Levels</td>
    <td nowrap>
      <table border=0 cellspacing=0 cellpadding=5>
        <tr>
          <td>Hull: </td>
          <td><input type=text size=5 name="hull_normal" value="<?php echo $this->_vars['hull_normal']; ?>"></td>
          <td>Engines: </td>
          <td><input type=text size=5 name="engines_normal" value="<?php echo $this->_vars['engines_normal']; ?>"></td>
          <td>Power: </td>
          <td><input type=text size=5 name="power_normal" value="<?php echo $this->_vars['power_normal']; ?>"></td>
          <td>Fighter Bay: </td>
          <td><input type=text size=5 name="fighter_normal" value="<?php echo $this->_vars['fighter_normal']; ?>"></td>
        </tr>
        <tr>
          <td>Sensors: </td>
          <td><input type=text size=5 name="sensors_normal" value="<?php echo $this->_vars['sensors_normal']; ?>"></td>
          <td>armor: </td>
          <td><input type=text size=5 name="armor_normal" value="<?php echo $this->_vars['armor_normal']; ?>"></td>
          <td>Shields: </td>
          <td><input type=text size=5 name="shields_normal" value="<?php echo $this->_vars['shields_normal']; ?>"></td>
          <td>Beams: </td>
          <td><input type=text size=5 name="beams_normal" value="<?php echo $this->_vars['beams_normal']; ?>"></td>
        </tr>
        <tr>
          <td>Torpedo Launchers: </td>
          <td><input type=text size=5 name="torp_launchers_normal" value="<?php echo $this->_vars['torp_launchers_normal']; ?>"></td>
          <td>Cloak: </td>
          <td><input type=text size=5 name="cloak_normal" value="<?php echo $this->_vars['cloak_normal']; ?>"></td>
          <td>ECM: </td>
          <td><input type=text size=5 name="ecm_normal" value="<?php echo $this->_vars['ecm_normal']; ?>"></td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td nowrap>Holds</td>
    <td nowrap>
      <table border=0 cellspacing=0 cellpadding=5>
	  <tr>
		<td>
		<font size=2><b>
		<?php echo $this->_vars['l_total_cargo']; ?>&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>
		<?php extract($this->_vars, EXTR_REFS);  echo strip_places($hold_space);  ?> / <?php extract($this->_vars, EXTR_REFS);  echo strip_places($holds_max);  ?>
		</b></font>
		</td>
	  </tr>
<?php extract($this->_vars, EXTR_REFS);  
	for($i = 0; $i < $cargo_items; $i++)
	{
		echo "	  <tr>
		<td>
		<font size=2><b>
		&nbsp;<img src=\"images/ports/" . $cargo_name[$i] . ".png\">&nbsp;" . ucfirst($cargo_name[$i]) . ":&nbsp;&nbsp;&nbsp;
		</b></font>
		<td>
		<font color=white><b>";
			echo "<input type=\"text\" size=30 name=\"commodity_" . str_replace(" ", "_", $cargo_name[$i]) . "\" value=\"" . $cargo_amount[$i] . "\">";
			echo " x $cargo_holds[$i]</b></font>
		</td>
	  </tr>";
	}
 ?>
        <tr>
          <td><font size=2><b>&nbsp;<img src="images/ports/energy.png">&nbsp;Energy:&nbsp;&nbsp;&nbsp;</b></font></td>
          <td><input type="text" size=30 name="ship_energy" value="<?php echo $this->_vars['energy']; ?>"></td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td nowrap>Combat</td>
    <td nowrap>
      <table border=0 cellspacing=0 cellpadding=5>
        <tr>
          <td>Fighters: </td>
          <td nowrap><input size=17 type="text" size=8 name="ship_fighters" value="<?php echo $this->_vars['fighters']; ?>"></td>
          <td>Torpedoes: </td>
          <td nowrap><input size=17 type="text" size=8 name="torps" value="<?php echo $this->_vars['torps']; ?>"></td>
          <td>Armor Pts: </td>
          <td nowrap><input size=17 type="text" size=8 name="armor_pts" value="<?php echo $this->_vars['armor_pts']; ?>"></td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td nowrap>Money and more</td>
    <td nowrap>
      <table border=0 cellspacing=0 cellpadding=5>
        <tr>
          <td nowrap>Credits: </td>
          <td nowrap><input size=20 type="text" name="credits" value="<?php echo $this->_vars['credits']; ?>"></td>
          <td nowrap>Current balance: </td>
          <td nowrap><input size=20 type="text" name="igb_balance" value="<?php echo $this->_vars['igb_balance']; ?>"></td>
        </tr>
        <tr>
          <td nowrap>Turns: </td>
          <td nowrap><input size=20 type="text" name="turns" value="<?php echo $this->_vars['turns']; ?>"></td>
          <td nowrap>Loan: </td>
          <td nowrap><input size=20 type="text" name="igb_loan" value="<?php echo $this->_vars['igb_loan']; ?>"></td>
        </tr>
        <tr>
          <td nowrap>Turns Used: </td>
          <td nowrap><input size=20 type="text" name="turns_used" value="<?php echo $this->_vars['turns_used']; ?>"></td>
          <td nowrap>Loan Timestamp: </td>
          <td nowrap><input size=20 type="text" name="igb_loantime" value="<?php echo $this->_vars['igb_loantime']; ?>"></td>
        </tr>
        <tr>
          <td nowrap>Current Sector: </td>
          <td nowrap><input type="text" name="sector" value="<?php echo $this->_vars['sector_id']; ?>"></td>
          <td nowrap>&nbsp;</td>
          <td nowrap>&nbsp;</td>
        </tr>
      </table>
    </td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td nowrap>Special Information</td>
    <td nowrap>
      <table border=0 cellspacing=0 cellpadding=5>
        <tr>
          <td >Federation Bounty Count: </td>
          <td nowrap><input size="8" type="text" name="fed_bounty_count" value="<?php echo $this->_vars['fed_bounty_count']; ?>"></td>
          <td >The last team the player left: </td>
          <td nowrap><input type="text" name="last_team" value="<?php echo $this->_vars['last_team']; ?>"></td>
        </tr>
        <tr>
          <td >Alliance Bounty Count: </td>
          <td nowrap><input size="8"  type="text" name="alliance_bounty_count" value="<?php echo $this->_vars['alliance_bounty_count']; ?>"></td>
          <td >Date player left team: </td>
          <td nowrap><input type="text" name="left_team_time" value="<?php echo $this->_vars['left_team_time']; ?>"></td>
        </tr>
        <tr>
          <td nowrap>Template: </td>
          <td nowrap><input type="text" name="template" value="<?php echo $this->_vars['template']; ?>"></td>
          <td nowrap>Avatar: </td>
          <td nowrap align="center"><img src="images/avatars/<?php echo $this->_vars['avatar']; ?>"><br><input type="text" name="avatar" value="<?php echo $this->_vars['avatar']; ?>"></td>
        </tr>

      </table>
    </td>
  </tr>
  <tr>
    <td colspan="2"><hr></td>
  </tr>
  <tr>
    <td colspan="2"><br></td>
  </tr>
  <tr>
    <td align="center" colspan = "2">
      <input type="hidden" name="user" value="<?php echo $this->_vars['user']; ?>">
      <input type="hidden" name="operation" value="Update">
      <input type="submit" value="Update">
    </td>
  </tr>
</table>

