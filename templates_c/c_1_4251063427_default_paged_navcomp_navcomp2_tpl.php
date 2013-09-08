<h1><?php echo $this->_vars['title']; ?></h1>
<table width="90%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
		<table border=1 cellspacing=1 cellpadding=2 width="100%">
		<TR BGCOLOR="#000000"><TD colspan=5 align=center><font color=white><B><?php echo $this->_vars['l_autoroute_title']; ?></B></font></TD></TR>
		<TR BGCOLOR="#000000">
		<TD align='center'><B><font size=2 color='#79f487'><?php echo $this->_vars['l_autoroute_id']; ?></font></B></TD>
		<TD align='center'><B><font size=2 color='#79f487'><?php echo $this->_vars['l_autoroute_start']; ?></font></B></TD>
		<TD align='center'><B><font size=2 color='#79f487'><?php echo $this->_vars['l_autoroute_destination']; ?></font></B></TD>
		<TD align='center' width="40%"><B><font size=2 color='#79f487'><?php echo $this->_vars['l_autoroute_warps']; ?></font></B></TD>
		<TD align='center'><B><font size=2 color='#79f487'><?php echo $this->_vars['l_autoroute_deleteroute']; ?></font></B></TD>
		</TR>
		
	<?php if ($this->_vars['autocount'] != 0): ?>
<?php extract($this->_vars, EXTR_REFS);  
		for($i = 0; $i < $autocount; $i++){
			echo "<TR BGCOLOR=" . $autolinecolor[$i] .">";
			echo "<TD align='center'><font size=2 color='#87d8ec'><b>";
			echo "<form action='navcomp.php' enctype='multipart/form-data'>"; 
			echo "<input size='10' maxlength='30' type='text' name='name' value='" . (($autoname[$i] == "" || empty($autoname[$i])) ? $autorouteid[$i] : $autoname[$i]) . "'>";
			echo "<input type='hidden' name='state' value='editname'>";
			echo "<input type='hidden' name='autoroute_id' value='" . $autorouteid[$i] . "'>";
			echo "<input type='submit' value='" . $l_autoroute_editname . "'>";
			echo "</form>";
			
			echo "</b></font></TD>\n";
			echo "<TD align='center'><font size=2 color=yellow>{$l_nav_warp_from} <a href=navcomp.php?state=start&autoroute_id=$autorouteid[$i]&warponly=1>$autostart[$i]</a><br>
				<font size=2 color=yellow>{$l_nav_rs_from} <a href=navcomp.php?state=start&autoroute_id=$autorouteid[$i]>$autostart[$i]</a></font></TD>\n";
			echo "<TD align='center'><font size=2 color=yellow>{$l_nav_warp_from} <a href=navcomp.php?state=reverse&autoroute_id=$autorouteid[$i]&warponly=1>$autoend[$i]</a><br>
				<font size=2 color=yellow>{$l_nav_rs_from} <a href=navcomp.php?state=reverse&autoroute_id=$autorouteid[$i]>$autoend[$i]</a></font></TD>\n";
			echo "<TD align='center' width='40%'><font size=2 color=yellow>$warplist[$i]</font></TD>\n";
			echo "<td align='center'><a href=\"navcomp.php?state=dismiss&delete_id=$autorouteid[$i]\">$l_autoroute_deleteroute</a></td></TR>\n";
		}
 ?>
	<?php else: ?>
		<tr BGCOLOR="#3A3B6E"><TD colspan="5" align='center'><B><font size=2 color='#79f487'><br><?php echo $this->_vars['l_autoroute_noroutes']; ?></font></b><br><br>
		</td></tr>
	<?php endif; ?>
		<TR BGCOLOR="#000000">
		<TD colspan=5 align=center><font color=white size=2><B><?php echo $this->_vars['l_autoroute_info']; ?></B></font></td></tr>
		<TR BGCOLOR="#000000">
		</TABLE><BR><BR>
	</td></tr>


<tr><td>
<?php if ($this->_vars['state'] == 0): ?>
	<table border=0 cellspacing=1 cellpadding=2 width="100%">
		<tr><td width="50%">
			<form action="navcomp.php" method=post>
			<?php echo $this->_vars['l_nav_query']; ?> <input name="stop_sector" <?php if (! $this->_vars['allow_navcomp']): ?>disabled<?php endif; ?>>
			<input type=submit value=<?php echo $this->_vars['l_submit']; ?> <?php if (! $this->_vars['allow_navcomp']): ?>disabled<?php endif; ?>><br>
			<input name=state value=1 type=hidden>
			</form>
		</td><td width="50%">
			<div align="center" ><b><?php echo $this->_vars['l_nav_warplinksleaving']; ?></b></div>
			<hr><br>
<span id="output">
<?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['resultlist']), 'iteration' => 0);
if (count((array)$this->_vars['resultlist'])): foreach ((array)$this->_vars['resultlist'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
	<?php if ($this->_vars['resultvisitedlist'][$this->_vars['key']] == 0): ?>
		<a href="#" onclick="target_sector='<?php echo $this->_vars['resultlist'][$this->_vars['key']]; ?>'; makeRequest();"><?php echo $this->_vars['resultlist'][$this->_vars['key']]; ?></a><br><br>
	<?php else: ?>
		<?php echo $this->_vars['resultlist'][$this->_vars['key']]; ?><br><br> 
	<?php endif; ?>
<?php endforeach; endif; ?>
</span>
<br>
			<div align="center" ><b><?php echo $this->_vars['l_nav_manuallist']; ?></b></div>
			<hr><br>

<span id="output2">None</span>
<br>
<br>
	<form id="manualroute" action='navcomp.php' enctype='multipart/form-data'>
	<?php echo $this->_vars['l_nav_autoroutename']; ?> <input type='text' name='name' value=''>
	<input type='hidden' name='state' value='create'>
	<input type='hidden' name='start_sector' value='<?php echo $this->_vars['start_sector']; ?>'>
	<input type='hidden' name='destination' id="destination" value=''>
	<input type='hidden' name='warp_list' id='warp_list' value=''><br>
	<br><br>
	<input onclick='populate();'  type='submit' value='<?php echo $this->_vars['l_autoroute_createroute']; ?>'>
	</form>
		</td></tr>
	</table>
<?php else: ?>
	<table border=0 cellspacing=1 cellpadding=2 width="100%">
	<?php if ($this->_vars['found'] > 0): ?>
		<tr><td colspan=3><h3><?php echo $this->_vars['l_nav_pathfnd']; ?></h3>
		<?php echo $this->_vars['start_sector']; ?> <?php echo $this->_vars['search_results_echo']; ?><br>
		<?php echo $this->_vars['l_nav_answ1']; ?> <?php echo $this->_vars['search_depth']; ?> <?php echo $this->_vars['l_nav_answ2']; ?><br><br></td></tr>
	<?php else: ?>
		<tr><td colspan=3><?php echo $this->_vars['l_nav_proper']; ?><br><br></td></tr>
	<?php endif; ?>
	</table>
<?php endif; ?>


<tr><td colspan=3><?php echo $this->_vars['l_autoroute_return']; ?> <a href='navcomp.php'><?php echo $this->_vars['l_clickme']; ?></a>.</td></tr>
</td>
				<tr><td width="100%" colspan=3><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

<?php echo '
<script type="text/javascript">
<!--
var xmlDoc = null ;
var target_sector = \'\' ;
var start_sector = \'\' ;
var warplist_stored = \'\' ;
var warplist_last = \'\' ;
var returndata = \'\' ;

function populate()
{
	document.getElementById(\'destination\').value = target_sector
	if(target_sector == warplist_stored)
	{
		document.getElementById(\'warp_list\').value = \'\'
	}
	else
	{
		document.getElementById(\'warp_list\').value = warplist_last
	}
}


function clearvariables()
{
	target_sector = \'\' ;
	start_sector = \'\' ;
	warplist_stored = \'\' ;
	warplist_last = \'\' ;
	returndata = \'\' ;
}

function makeRequest()
{
	if ( xmlDoc == null )
	{
		if (typeof window.ActiveXObject != \'undefined\' ) {
			var XMLHTTP_IDS = new Array(\'MSXML2.XMLHTTP.5.0\',
				 \'MSXML2.XMLHTTP.4.0\',
				 \'MSXML2.XMLHTTP.3.0\',
				 \'MSXML2.XMLHTTP\',
				 \'Microsoft.XMLHTTP\');
			var success = false;
			for (var i=0;i < XMLHTTP_IDS.length && !success; i++)
			{
				try
				{
					xmlDoc = new ActiveXObject
					(XMLHTTP_IDS[i]);
					success = true;
				}
				catch (e)
				{}
			}
		}
		else
		{
			xmlDoc = new XMLHttpRequest();
		}
	}
	
	warplist_last = warplist_stored;
	
	xmlDoc.onreadystatechange = process;
	xmlDoc.open( "GET", "';  echo $this->_vars['full_url'];  echo 'ajax_processor.php?command=navcomp_findlinks&target_sector=" + target_sector + "&warplist=" + warplist_stored, true );
	xmlDoc.send( null );
}

function process() {
	if ( xmlDoc.readyState != 4 )
	{
		return ;
	}
	returndata = xmlDoc.responseText
	var sectorlist=returndata.split(\'|\');
	var returnmessage = \'\';
//	document.write(returndata)
	if(warplist_stored != \'\')
	{
		warplist_stored = warplist_stored + \'|\' + target_sector;
	}
	else
	{
		warplist_stored = warplist_stored + target_sector;
		start_sector = target_sector;
	}
	
	if(sectorlist.length == 1)
	{
		returnmessage = \'[\' + target_sector + \'] ';  echo $this->_vars['l_nav_nowarplinksleaving'];  echo '\'
	}
	else
	{
		for (var x = 0; x < sectorlist.length - 1; x++)
		{
			var sectorname = sectorlist[x];
			var visitedsector=sectorname.split(\'`\');
			if(visitedsector.length > 1)
			{
				returnmessage = returnmessage + visitedsector[1] + \''; ?>
 : <?php echo $this->_vars['l_nav_notinlogs'];  echo '<br><br>\'
			}
			else
			{
				returnmessage = returnmessage + \'<a href="#" onclick="target_sector=\\\'\' + sectorname + \'\\\'; makeRequest();">\' + sectorname + \'</a><br><br>\'
			}
		}
	}

	document.getElementById(\'output\').innerHTML = returnmessage;
	document.getElementById(\'output2\').innerHTML = warplist_stored.replace(/\\|/g, " >> ");
}

clearvariables();


//-->
</script>
'; ?>


