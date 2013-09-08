<?php echo '
<script language="javascript">
var xmlSourceDoc = null ;
var xmlDestDoc = null ;
var xmlautoDoc = null ;
var xmlSPautoDoc = null ;
var xmlDPautoDoc = null ;
var sectorname;
var sectornametwo;
var startsector = "";
var endsector = "";
var planetid = "";

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
	sectornametwo = form.port_id2.value;

	if ( xmlautoDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlautoDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlautoDoc.onreadystatechange = processautoroute ;
	}
		else
		{
			xmlautoDoc = new XMLHttpRequest();
			xmlautoDoc.onload = processautoroute ;
		}
	}
	xmlautoDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=find_autoroute&sectorname=" + sectorname + "&sectornametwo=" + sectornametwo, true );
	xmlautoDoc.send( null );
}

function processautoroute() {
	if ( xmlautoDoc.readyState != 4 ) return ;

	returndata = xmlautoDoc.responseText
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

function makeAutorouteSPRequest()
{
	var form = document.forms[0];
	planetid = form.planet_id1.value;

	if ( xmlSPautoDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlSPautoDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlSPautoDoc.onreadystatechange = processSPautoroute ;
	}
		else
		{
			xmlSPautoDoc = new XMLHttpRequest();
			xmlSPautoDoc.onload = processSPautoroute ;
		}
	}
	xmlSPautoDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=find_planetautoroute&planetid=" + planetid, true );
	xmlSPautoDoc.send( null );
}


function processSPautoroute() {
	if ( xmlSPautoDoc.readyState != 4 ) return ;

	returndata = xmlSPautoDoc.responseText
	var workdata=returndata.split(\'^\');
	var forwardautorouteid = workdata[0];
	var forwardwarplist=workdata[1];

	if(forwardautorouteid != 0)
	{
		document.frmMain.forwardautorouteid.value = forwardautorouteid;
		document.getElementById(\'forwardwarplist\').innerHTML = forwardwarplist.replace(/\\|/g, " >> ");
	}
	else
	{
		document.frmMain.forwardautorouteid.value = forwardautorouteid;
		document.getElementById(\'forwardwarplist\').innerHTML = "';  echo $this->_vars['l_tdr_noneavailable'];  echo '" + returndata;
	}
}

function makeAutorouteDPRequest()
{
	var form = document.forms[0];
	planetid = form.planet_id2.value;

	if ( xmlDPautoDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			xmlDPautoDoc = new ActiveXObject("Microsoft.XMLHTTP");
			xmlDPautoDoc.onreadystatechange = processDPautoroute ;
	}
		else
		{
			xmlDPautoDoc = new XMLHttpRequest();
			xmlDPautoDoc.onload = processDPautoroute ;
		}
	}
	xmlDPautoDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=find_planetautoroute&planetid=" + planetid, true );
	xmlDPautoDoc.send( null );
}

function processDPautoroute() {
	if ( xmlDPautoDoc.readyState != 4 ) return ;

	returndata = xmlDPautoDoc.responseText
	var workdata=returndata.split(\'^\');
	var returnautorouteid = workdata[0];
	var returnwarplist=workdata[1];

	if(returnautorouteid != 0)
	{
		document.frmMain.returnautorouteid.value = returnautorouteid;
		document.getElementById(\'returnwarplist\').innerHTML = returnwarplist.replace(/\\|/g, " >> ");
	}
	else
	{
		document.frmMain.returnautorouteid.value = returnautorouteid;
		document.getElementById(\'returnwarplist\').innerHTML = "';  echo $this->_vars['l_tdr_noneavailable'];  echo '";
	}
}

var planetspecial=new Array()
planetspecial[\'none\'] = \'\';
';  echo $this->_vars['planetspecial'];  echo '

function PopulateSourcePlanet() {

   var planet_id1_item = document.frmMain.planet_id1;
   
   // Clear out the list of teams
   ClearOptions(document.frmMain.source_planet_commodity);
   
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][0];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][0];  echo '");
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][1];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][1];  echo '");
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][2];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][2];  echo '");
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][3];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][3];  echo '");
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][4];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][4];  echo '");
	AddToOptionList(document.frmMain.source_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][5];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][5];  echo '");

   if (planetspecial[planet_id1_item[planet_id1_item.selectedIndex].value] != \'\') {
      AddToOptionList(document.frmMain.source_planet_commodity, planetspecial[planet_id1_item[planet_id1_item.selectedIndex].value], planetspecial[planet_id1_item[planet_id1_item.selectedIndex].value]);
   }
}

function PopulateDestPlanet() {

   var planet_id2_item = document.frmMain.planet_id2;
   
   // Clear out the list of teams
   ClearOptions(document.frmMain.destination_planet_commodity);
   
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][0];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][0];  echo '");
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][1];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][1];  echo '");
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][2];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][2];  echo '");
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][3];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][3];  echo '");
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][4];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][4];  echo '");
	AddToOptionList(document.frmMain.destination_planet_commodity, "';  echo $this->_vars['commodity_commodity_type'][5];  echo '", "';  echo $this->_vars['commodity_commodity_type_name'][5];  echo '");

   if (planetspecial[planet_id2_item[planet_id2_item.selectedIndex].value] != \'\') {
      AddToOptionList(document.frmMain.destination_planet_commodity, planetspecial[planet_id2_item[planet_id2_item.selectedIndex].value], planetspecial[planet_id2_item[planet_id2_item.selectedIndex].value]);
   }
}

function ClearOptions(OptionList) {

   // Always clear an option list from the last entry to the first
   for (x = OptionList.length; x >= 0; x = x - 1) {
      OptionList[x] = null;
   }
}

function AddToOptionList(OptionList, OptionValue, OptionText) {
   // Add option to the bottom of the list
   OptionList[OptionList.length] = new Option(OptionText, OptionValue);
}

</script>
'; ?>


<h1><?php echo $this->_vars['title']; ?></h1>

<form name="frmMain" action="traderoute_save.php" method=post>
<table width="600" border="1" align="center" cellpadding="4" cellspacing="0">
  <tr>
    <td>
    	<input type='hidden' name='selectedsource' value=''>
    	<input type='hidden' name='selecteddest' value=''>
	<table width="100%"  border="0">
      <tr>
        <td colspan="4"><p><?php echo $this->_vars['l_tdr_createnew']; ?> <?php echo $this->_vars['l_tdr_traderoute']; ?> <?php echo $this->_vars['l_tdr_cursector']; ?> <?php echo $this->_vars['shipsector']; ?><br>
          <br>
        </p>
          </td>
        </tr>
      <tr>
        <td colspan="4"><b><?php echo $this->_vars['l_tdr_selspoint']; ?></b><br></td>
        </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_port']; ?> : </td>
        <td><input type=radio name="ptype1" value="port" checked></td>
        <td>
          <input onBlur="makeSourceRequest(); makeAutorouteRequest();" type=text name=port_id1 size=20 align=center value="<?php echo $this->_vars['shipsector']; ?>"></td>
        <td id="source">&nbsp;</td>
      </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_autoroute']; ?> : <input type='hidden' name='forwardautorouteid' value='0'></td>
       <td id="forwardwarplist" colspan="2"><?php echo $this->_vars['l_tdr_noneavailable']; ?></td>
        <td id="source">&nbsp;</td>
      </tr>
      <tr>
        <td>Personal <?php echo $this->_vars['l_tdr_planet']; ?> : </td>
        <td><input type=radio name="ptype1" value="planet" onclick="PopulateSourcePlanet(); makeAutorouteSPRequest();"></td>
        <td>
          <select name="planet_id1" onChange="PopulateSourcePlanet(); makeAutorouteSPRequest();">

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
	  endif; ?>
</select></td>
        <td>
          <select name="source_planet_commodity">
<?php extract($this->_vars, EXTR_REFS);  
for ($i=0; $i < $commodity_item_count; $i++)
{
	echo "<option ";
	echo " value=\"" . $commodity_commodity_type[$i] . "\">" . $commodity_commodity_type_name[$i] . "</option>\n";
}
 ?>
</select></td>
      </tr>
      <tr>
        <td colspan="4"><b><?php echo $this->_vars['l_tdr_selendpoint']; ?> : </b><br></td>
        </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_port']; ?> : </td>
        <td><input type=radio name="ptype2" value="port" checked></td>
        <td>
          <input onBlur="makeDestRequest(); makeAutorouteRequest();" type=text name=port_id2 size=20 align=center></td>
        <td id="dest">&nbsp;</td>
      </tr>
      <tr>
        <td><?php echo $this->_vars['l_tdr_autoroute']; ?> : <input type='hidden' name='returnautorouteid' value='0'></td>
       <td id="returnwarplist" colspan="2"><?php echo $this->_vars['l_tdr_noneavailable']; ?></td>
        <td id="source">&nbsp;</td>
      </tr>
      <tr>
        <td>Personal <?php echo $this->_vars['l_tdr_planet']; ?> : </td>
        <td><input type=radio name="ptype2" value="planet" onclick="PopulateDestPlanet(); makeAutorouteDPRequest();"></td>
        <td><select name="planet_id2" onChange="PopulateDestPlanet(); makeAutorouteDPRequest();">
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
	  endif; ?>
</select></td>
        <td><select name="destination_planet_commodity">
<?php extract($this->_vars, EXTR_REFS);  
for ($i=0; $i < $commodity_item_count; $i++)
{
	echo "<option ";
	echo " value=\"" . $commodity_commodity_type[$i] . "\">" . $commodity_commodity_type_name[$i] . "</option>\n";
}
 ?>
</select></td>
      </tr>
	  </table>
	  <table width="100%"  border="0">
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_selmovetype']; ?> : </b></td>
        <td width="50%"><input type=radio name="move_type" value="realspace">
          &nbsp;<?php echo $this->_vars['l_tdr_realspace']; ?>&nbsp;&nbsp;
          <input type=radio name="move_type" value="warp" checked>
          &nbsp;<?php echo $this->_vars['l_tdr_warp']; ?></td>
        </tr>
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_selcircuit']; ?> : </b></td>
        <td width="50%"><input type=radio name="circuit_type" value="N">
          &nbsp;<?php echo $this->_vars['l_tdr_oneway']; ?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <input type=radio name="circuit_type" value="Y" checked>
          &nbsp;<?php echo $this->_vars['l_tdr_bothways']; ?></td>
        </tr>
      <tr>
        <td width="50%"><strong><?php echo $this->_vars['l_tdr_tdrescooped']; ?></strong></td>
        <td width="50%"><input type=radio name=trade_energy value="Y" checked>
          &nbsp;<?php echo $this->_vars['l_tdr_trade']; ?>&nbsp;&nbsp;
          <input type=radio name=trade_energy value="N">
          &nbsp;<?php echo $this->_vars['l_tdr_keep']; ?></td>
        </tr>
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_upgrade_ports']; ?> <?php echo $this->_vars['l_port']; ?> <?php echo $this->_vars['l_tdr_fighters']; ?> : </b></td>
        <td width="50%"><input type=radio name="trade_fighters" value="Y">
          &nbsp;<?php echo $this->_vars['l_tdr_trade']; ?>&nbsp;&nbsp;
          <input type=radio name="trade_fighters" value="N" checked>
          &nbsp;<?php echo $this->_vars['l_tdr_keep']; ?></td>
        </tr>
      <tr>
        <td width="50%"><b><?php echo $this->_vars['l_tdr_trade']; ?> <?php echo $this->_vars['l_upgrade_ports']; ?> <?php echo $this->_vars['l_port']; ?> <?php echo $this->_vars['l_tdr_torps']; ?> : </b></td>
        <td width="50%"><input type=radio name="trade_torps" value="Y">
          &nbsp;<?php echo $this->_vars['l_tdr_trade']; ?>&nbsp;&nbsp;
          <input type=radio name="trade_torps" value="N" checked>
          &nbsp;<?php echo $this->_vars['l_tdr_keep']; ?></td>
        </tr>
    </table>
	  <table width="100%"  border="0">
        <tr>
          <td><div align="center">
              <input type=submit value="<?php echo $this->_vars['l_tdr_create']; ?>">
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
	makeAutorouteRequest(\'\', \'\');
}

window.onload = FillContent;
</script>
'; ?>

