<?php echo '
<script language="javascript">
var xmlSourceDoc = null ;
var xmlDestDoc = null ;
var xmlautoDoc = null ;
var sectorname;
var sectornametwo;

function makeSourceRequest()
{
	var form = document.forms[0];
	sectorname = form.port_id1.value;
	if(sectorname == \'\')
	{
		return;
	}
	if ( xmlSourceDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlSourceDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlSourceDoc.onreadystatechange = processsource ;
	}
		else
		{
			xmlSourceDoc = new XMLHttpRequest();
			xmlSourceDoc.onload = processsource ;
		}
	}
	xmlSourceDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=traderoute_portinfo&sectorname=" + sectorname, true );
	xmlSourceDoc.send( null );
}

function processsource() {
	if ( xmlSourceDoc.readyState != 4 ) return ;
	document.getElementById("source").innerHTML = xmlSourceDoc.responseText ;
}

function makeDestRequest()
{
	var form = document.forms[0];
	sectorname = form.port_id2.value;
	if(sectorname == \'\')
	{
		return;
	}
	if ( xmlDestDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlDestDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlDestDoc.onreadystatechange = processdestination ;
	}
		else
		{
			xmlDestDoc = new XMLHttpRequest();
			xmlDestDoc.onload = processdestination ;
		}
	}
	xmlDestDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=traderoute_portinfo&sectorname=" + sectorname, true );
	xmlDestDoc.send( null );
}

function processdestination() {
	if ( xmlDestDoc.readyState != 4 ) return ;
	document.getElementById("dest").innerHTML = xmlDestDoc.responseText ;
}

function makeAutorouteRequest()
{
	var form = document.forms[0];
	sectorname = form.port_id1.value;
	if(sectorname == \'\')
	{
		return;
	}
	sectornametwo = form.port_id2.value;
	if(sectornametwo == \'\')
	{
		return;
	}
	if ( xmlautoDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlAutoDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlAutoDoc.onreadystatechange = processautoroute ;
	}
		else
		{
			xmlAutoDoc = new XMLHttpRequest();
			xmlAutoDoc.onload = processautoroute ;
		}
	}
	xmlAutoDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=find_autoroute&sectorname=" + sectorname + "&sectornametwo=" + sectornametwo, true );
	xmlAutoDoc.send( null );
}

function processautoroute() {
	if ( xmlAutoDoc.readyState != 4 ) return ;

	returndata = xmlAutoDoc.responseText
	var workdata=returndata.split(\'^\');
	var forwardautorouteid = workdata[0];
	var forwardwarplist=workdata[1];
	var returnautorouteid = workdata[2];
	var returnwarplist=workdata[3];

	if(forwardautorouteid != 0 && returnautorouteid != 0)
	{
		document.frmMain.forwardautorouteid.value = forwardautorouteid;
		document.getElementById(\'forwardwarplist\').innerHTML = forwardwarplist.replace(/\\|/g, " >> ");
		document.frmMain.returnautorouteid.value = returnautorouteid;
		document.getElementById(\'returnwarplist\').innerHTML = returnwarplist.replace(/\\|/g, " >> ");
	}
	else
	{
		document.frmMain.forwardautorouteid.value = forwardautorouteid;
		document.getElementById(\'forwardwarplist\').innerHTML = "';  echo $this->_vars['l_tdr_noneavailable'];  echo '";
		document.frmMain.returnautorouteid.value = returnautorouteid;
		document.getElementById(\'returnwarplist\').innerHTML = "';  echo $this->_vars['l_tdr_noneavailable'];  echo '";
	}
}

var planetspecialteam=new Array()
planetspecialteam[\'none\'] = \'\';
';  echo $this->_vars['planetspecialteam'];  echo '

var planetspecial=new Array()
planetspecial[\'none\'] = \'\';
';  echo $this->_vars['planetspecial'];  echo '

function PopulateSourcePlanet(item) {

   var planet_id1_item = document.frmMain.planet_id1;
   
   // Clear out the list of teams
   ClearOptions(document.frmMain.source_planet_commodity);
   
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][0];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][0];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][1];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][1];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][2];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][2];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][3];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][3];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][4];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][4];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][5];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][5];  echo '",item);

   if (planetspecial[planet_id1_item[planet_id1_item.selectedIndex].value] != \'\') {
      AddToOptionList(document.frmMain.source_planet_commodity, planetspecial[planet_id1_item[planet_id1_item.selectedIndex].value], planetspecial[planet_id1_item[planet_id1_item.selectedIndex].value],item);
   }
}

function PopulateDestPlanet(item) {

   var planet_id2_item = document.frmMain.planet_id2;
   
   // Clear out the list of teams
   ClearOptions(document.frmMain.destination_planet_commodity);
   
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][0];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][0];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][1];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][1];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][2];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][2];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][3];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][3];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][4];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][4];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][5];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][5];  echo '",item);

   if (planetspecial[planet_id2_item[planet_id2_item.selectedIndex].value] != \'\') {
      AddToOptionList(document.frmMain.destination_planet_commodity, planetspecial[planet_id2_item[planet_id2_item.selectedIndex].value], planetspecial[planet_id2_item[planet_id2_item.selectedIndex].value],item);
   }
}

function PopulateSourceTeamPlanet(item) {

   var planet_id1_item = document.frmMain.team_planet_id1;
   
   // Clear out the list of teams
   ClearOptions(document.frmMain.source_planet_commodity);
   
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][0];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][0];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][1];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][1];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][2];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][2];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][3];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][3];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][4];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][4];  echo '",item);
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][5];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][5];  echo '",item);

   if (planetspecialteam[planet_id1_item[planet_id1_item.selectedIndex].value] != \'\') {
      AddToOptionList(document.frmMain.source_planet_commodity, planetspecialteam[planet_id1_item[planet_id1_item.selectedIndex].value], planetspecialteam[planet_id1_item[planet_id1_item.selectedIndex].value],item);
   }
}

function PopulateDestTeamPlanet(item) {

   var planet_id2_item = document.frmMain.team_planet_id2;
   
   // Clear out the list of teams
   ClearOptions(document.frmMain.destination_planet_commodity);
   
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][0];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][0];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][1];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][1];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][2];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][2];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][3];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][3];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][4];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][4];  echo '",item);
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][5];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][5];  echo '",item);

   if (planetspecialteam[planet_id2_item[planet_id2_item.selectedIndex].value] != \'\') {
      AddToOptionList(document.frmMain.destination_planet_commodity, planetspecialteam[planet_id2_item[planet_id2_item.selectedIndex].value], planetspecialteam[planet_id2_item[planet_id2_item.selectedIndex].value],item);
   }
}

function ClearOptions(OptionList) {

   // Always clear an option list from the last entry to the first
   for (x = OptionList.length; x >= 0; x = x - 1) {
      OptionList[x] = null;
   }
}

function AddToOptionList(OptionList, OptionValue, OptionText, item) {
   // Add option to the bottom of the list
   if(OptionText == item)
   {
		isSelected = \'selected\';
	}
	else
	{
		isSelected = \'\';
	}
   OptionList[OptionList.length] = new Option(OptionText, OptionValue, isSelected);
}

</script>
'; ?>


<h1><?php echo $this->_vars['title']; ?></h1>

<form name="frmMain" action="traderoute_save.php" method=post>
<table width="600" border="1" align="center" cellpadding="4" cellspacing="0">
  <tr>
    <td>
	<table width="100%"  border="0">
      <tr>
        <td colspan="4"><p><?php echo $this->_vars['l_tdr_editinga']; ?> <?php echo $this->_vars['l_tdr_traderoute']; ?> <?php echo $this->_vars['l_tdr_cursector']; ?> <?php echo $this->_vars['shipsector']; ?><br>
          <br>
        </p>
          </td>
        </tr>
      <tr>
        <td colspan="4"><b><?php echo $this->_vars['l_tdr_selspoint']; ?></b><br></td>
        </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_port']; ?> : </td>
        <td><input type=radio name="ptype1" value="port" 
<?php if ($this->_vars['source_type'] == 'port'): ?>
	 checked
<?php endif; ?>
></td>
        <td>
          <input onBlur="makeSourceRequest(); makeAutorouteRequest();" type="text" name="port_id1" size="20" align="center" 
<?php if ($this->_vars['source_type'] == 'port'): ?>
	value="<?php echo $this->_vars['editsource_id']; ?>"
<?php else: ?>
	value="<?php echo $this->_vars['shipsector']; ?>"
<?php endif; ?>
></td>
        <td id="source">&nbsp;</td>
      </tr>
       <tr>
        <td><?php echo $this->_vars['l_tdr_autoroute']; ?> : <input type='hidden' name='forwardautorouteid' value='0'></td>
       <td id="forwardwarplist" colspan="2"><?php echo $this->_vars['l_tdr_noneavailable']; ?></td>
        <td id="source">&nbsp;</td>
      </tr>
     <tr><td colspan="4"><hr></td></tr>
      <tr>
        <td>Personal <?php echo $this->_vars['l_tdr_planet']; ?> : </td>
        <td><input type=radio name="ptype1" value="planet"
<?php if ($this->_vars['source_type'] == 'planet'): ?>
	 checked
<?php endif; ?>
 onclick="PopulateSourcePlanet();"></td>
        <td>
          <select name="planet_id1" onChange="PopulateSourcePlanet();">

<?php if ($this->_vars['num_planets'] == 0): ?>
	<option value=none><?php echo $this->_vars['l_tdr_none']; ?></option>
<?php else: ?>
	<?php extract($this->_vars, EXTR_REFS);  
	for ($i=0; $i < $num_planets; $i++)
	{
		echo "<option ";
		echo $planetselected[$i];
		echo " value=" . $planetid[$i] . ">" . $planetname[$i] . " $l_tdr_insector " . $planetsectorid[$i] . "</option>\n";
	}
	 ?>
<?php endif; ?>
</select></td>
        <td rowspan="2">
          <select name=source_planet_commodity>
<option value=""></option>
</select></td>
      </tr>
      <tr>
        <td><?php echo $this->_vars['l_team']; ?> <?php echo $this->_vars['l_tdr_planet']; ?> : </td>
        <td><input type=radio name="ptype1" value="team_planet"
<?php if ($this->_vars['source_type'] == 'team_planet'): ?>
	 checked
<?php endif; ?>
 onclick="PopulateSourceTeamPlanet();"></td>
        <td><select name="team_planet_id1" onChange="PopulateSourceTeamPlanet();">

<?php if ($this->_vars['num_team_planets'] == 0): ?>
	<option value=none><?php echo $this->_vars['l_tdr_none']; ?></option>
<?php else: ?>
	<?php extract($this->_vars, EXTR_REFS);  
	for ($i=0; $i < $num_team_planets; $i++)
	{
		echo "<option ";
		echo $planetselectedteam[$i];
		echo " value=" . $planetidteam[$i] . ">" . $planetnameteam[$i] . " $l_tdr_insector " . $planetsectoridteam[$i] . "</option>\n";
	}
	 ?>
<?php endif; ?>
</select></td>
        </tr>
      <tr>
        <td>&nbsp;</td>
        <td>&nbsp;</td>
        <td>&nbsp;</td>
        <td>&nbsp;</td>
      </tr>
      <tr>
        <td colspan="4"><b><?php echo $this->_vars['l_tdr_selendpoint']; ?> : </b><br></td>
        </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_port']; ?> : </td>
        <td><input type=radio name="ptype2" value="port" 
<?php if ($this->_vars['dest_type'] == 'port'): ?>
	 checked
<?php endif; ?>
></td>
        <td>
          <input onBlur="makeDestRequest(); makeAutorouteRequest();" type=text name=port_id2 size=20 align=center
<?php if ($this->_vars['dest_type'] == 'port'): ?>
	value="<?php echo $this->_vars['editdest_id']; ?>"
<?php endif; ?>
></td>
        <td id="dest">&nbsp;</td>
      </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_autoroute']; ?> : <input type='hidden' name='returnautorouteid' value='0'></td>
       <td id="returnwarplist" colspan="2"><?php echo $this->_vars['l_tdr_noneavailable']; ?></td>
        <td id="source">&nbsp;</td>
      </tr>
      <tr><td colspan="4"><hr></td></tr>
      <tr>
        <td>Personal <?php echo $this->_vars['l_tdr_planet']; ?> : </td>
        <td><input type=radio name="ptype2" value="planet"
<?php if ($this->_vars['dest_type'] == 'planet'): ?>
	 checked
<?php endif; ?>
 onclick="PopulateDestPlanet();"></td>
        <td><select name="planet_id2" onChange="PopulateDestPlanet();">

<?php if ($this->_vars['num_planets'] == 0): ?>
	<option value=none><?php echo $this->_vars['l_tdr_none']; ?></option>
<?php else: ?>
	<?php extract($this->_vars, EXTR_REFS);  
	for ($i=0; $i < $num_planets; $i++)
	{
		echo "<option ";
		echo $planetdestselected[$i];
		echo " value=" . $planetid[$i] . ">" . $planetname[$i] . " $l_tdr_insector " . $planetsectorid[$i] . "</option>\n";
	}
	 ?>
<?php endif; ?>
</select></td>
        <td rowspan="2"><select name=destination_planet_commodity>
<option value=""></option>
</select></td>
      </tr>
      <tr>
        <td><?php echo $this->_vars['l_team']; ?> <?php echo $this->_vars['l_tdr_planet']; ?> : </td>
        <td><input type=radio name="ptype2" value="team_planet"
<?php if ($this->_vars['dest_type'] == 'team_planet'): ?>
	 checked}
<?php endif; ?>
 onclick="PopulateDestTeamPlanet();"></td>
        <td><select name="team_planet_id2" onChange="PopulateDestTeamPlanet();">

<?php if ($this->_vars['num_team_planets'] == 0): ?>
	<option value=none><?php echo $this->_vars['l_tdr_none']; ?></option>
<?php else: ?>
	<?php extract($this->_vars, EXTR_REFS);  
	for ($i=0; $i < $num_team_planets; $i++)
	{
		echo "<option ";
		echo $planetdestselectedteam[$i];
		echo " value=" . $planetidteam[$i] . ">" . $planetnameteam[$i] . " $l_tdr_insector " . $planetsectoridteam[$i] . "</option>\n";
	}
	 ?>
<?php endif; ?>
</select></td>
        </tr>
      <tr>
        <td>&nbsp;</td>
        <td>&nbsp;</td>
        <td>&nbsp;</td>
        <td>&nbsp;</td>
      </tr>
	  </table>
	  <table width="100%"  border="0">
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_selmovetype']; ?> : </b></td>
        <td width="50%"><input type=radio name="move_type" value="realspace" 
<?php if ($this->_vars['move_type'] == 'R'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_realspace']; ?>&nbsp;&nbsp;
          <input type=radio name="move_type" value="warp" 
<?php if ($this->_vars['move_type'] == 'W'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_warp']; ?></td>
        </tr>
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_selcircuit']; ?> : </b></td>
        <td width="50%"><input type=radio name="circuit_type" value="N"
<?php if ($this->_vars['circuit'] == 'N'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_oneway']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <input type=radio name="circuit_type" value="Y" 
<?php if ($this->_vars['circuit'] == 'Y'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_bothways']; ?></td>
        </tr>
      <tr>
        <td width="50%"><strong><?php echo $this->_vars['l_tdr_tdrescooped']; ?></strong></td>
        <td width="50%"><input type=radio name=trade_energy value="Y"
<?php if ($this->_vars['trade_energy'] == 'Y'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_trade']; ?>&nbsp;&nbsp;
          <input type=radio name=trade_energy value="N"
<?php if ($this->_vars['trade_energy'] == 'N'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_keep']; ?></td>
        </tr>
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_upgrade_ports']; ?> <?php echo $this->_vars['l_port']; ?> <?php echo $this->_vars['l_tdr_fighters']; ?> : </b></td>
        <td width="50%"><input type=radio name="trade_fighters" value="Y"
<?php if ($this->_vars['trade_fighters'] == 'Y'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_trade']; ?>&nbsp;&nbsp;
          <input type=radio name="trade_fighters" value="N"
<?php if ($this->_vars['trade_fighters'] == 'N'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_keep']; ?></td>
        </tr>
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_upgrade_ports']; ?> <?php echo $this->_vars['l_port']; ?> <?php echo $this->_vars['l_tdr_torps']; ?> : </b></td>
        <td width="50%"><input type=radio name="trade_torps" value="Y"
<?php if ($this->_vars['trade_torps'] == 'Y'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_trade']; ?>&nbsp;&nbsp;
          <input type=radio name="trade_torps" value="N"
<?php if ($this->_vars['trade_torps'] == 'N'): ?>
	 checked
<?php endif; ?>
>
          &nbsp;<?php echo $this->_vars['l_tdr_keep']; ?></td>
        </tr>
    </table>
	  <table width="100%"  border="0">
        <tr>
          <td><div align="center">
              <input type=hidden name=editing value=<?php echo $this->_vars['editing']; ?>>
<input type=submit value="<?php echo $this->_vars['l_tdr_modify']; ?>" >
              <br>
              <br>
            <?php echo $this->_vars['l_tdr_returnmenu']; ?><br>
          </div></td>
        </tr>
        <tr>
          <td><div align="center"><?php echo $this->_vars['gotomain']; ?></div></td>
        </tr>
      </table></td>
  </tr>
</table>
</form>

<?php echo '
<script language="javascript">
function FillContent()
{
	makeSourceRequest();
	makeDestRequest();
	makeAutorouteRequest();
	'; ?>

	<?php if ($this->_vars['source_type'] == 'planet'): ?>
	<?php echo '
		PopulateSourcePlanet(\'';  echo $this->_vars['source_commodityselected'];  echo '\');
	'; ?>

	<?php endif; ?>
	<?php echo '

	'; ?>

	<?php if ($this->_vars['source_type'] == 'team_planet'): ?>
	<?php echo '
		PopulateSourceTeamPlanet(\'';  echo $this->_vars['source_commodityselected'];  echo '\');
	'; ?>

	<?php endif; ?>
	<?php echo '

	'; ?>

	<?php if ($this->_vars['dest_type'] == 'planet'): ?>
	<?php echo '
		PopulateDestPlanet(\'';  echo $this->_vars['destination_commodityselected'];  echo '\');
	'; ?>

	<?php endif; ?>
	<?php echo '

	'; ?>

	<?php if ($this->_vars['dest_type'] == 'team_planet'): ?>
	<?php echo '
		PopulateDestTeamPlanet(\'';  echo $this->_vars['destination_commodityselected'];  echo '\');
	'; ?>

	<?php endif; ?>
	<?php echo '

}

window.onload = FillContent;
</script>
'; ?>

