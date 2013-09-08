<h1>{$title}</h1>

{literal}
	<style type="text/css">
		.border {
			border-collapse: collapse; 
			border: 1px solid #ccc; 
		}
		.yellow { color: yellow; }
		.white { color: white; }
	</style>
{/literal}
<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
	{if !$isinfoid}
		{if $infocount}
			<font color=red size='4'>{$l_spy_infodeleted}<BR><BR></font>
		{else}
			<B>{$l_spy_infonotyours}</B><BR><BR>
		{/if}
	{/if}

	{if !$isinfoidall}
		<font color=red size='4'>{$l_spy_messagesdeleted}<br><br></font>
	{/if}
	
	<br>
	<table border="0" cellpadding="2" cellspacing="0" width="100%" class="border">
		<tr>
			<td bgcolor="#000000" colspan="4" align=center><font color=white><b>{$l_spy_infotitle}</b></font></td>
		</tr>
		<tr>
			<td bgcolor="#000000"><b><a href="spy.php?command=detect">{$l_spy_time}</a></b></td>
			<td bgcolor="#000000"><b><a href="spy.php?command=detect&by=type">{$l_spy_type}</a></b></td>
			<td bgcolor="#000000"><b><a href="spy.php?command=detect&by=data">{$l_spy_info}</a></b></td>
			<td bgcolor="#000000" align="right"><b><a href="spy.php?command=detect&info_id_all=1">{$l_spy_deleteall}</a></b></td>
		</tr>
		{php}
		$line_color = "#000000";
		for($i = 0; $i < $detectcount; $i++)
		{
			if($line_color == "#000000")   
				$line_color = "#000000"; 
			else
				$line_color = "#000000"; 

			echo "<tr><td bgcolor=" . $line_color . "class=\"white\">$det_time[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$datatype[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\">$datainfo[$i]</td>
						<td bgcolor=" . $line_color . " class=\"white\" align=\"right\">
						<a href=\"spy.php?command=detect&info_id=$det_id[$i]&by=$by\">$l_spy_delete</a></td>
					</tr>";
		}
		{/php}
  </table>&nbsp;<br>
	<a href=spy.php>{$l_clickme}</a> {$l_spy_menu}

</td></tr>
<tr><td><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
