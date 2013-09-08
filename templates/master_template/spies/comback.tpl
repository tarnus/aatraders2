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
	{if $planetspies}
		{if $executecommand}
			<table border="0" cellpadding="2" cellspacing="0" width="100%" class="border">
			<tr><td colspan="4" align="center"><B>{$l_spy_confirm}</B><BR>
			<BR></TD>
			</TR>
			<TR BGCOLOR="#000000">
			<TD><font color=white><B>{$l_spy_codenumber}</B></font></TD>
			<TD><font color=white><B>{$l_spy_job}</B></font></TD>
			<TD><font color=white><B>{$l_spy_move}</B></font></TD>
			<TD><font color=white><B>{$l_spy_action}</B></font></TD>
			</TR>
	  
			<TR BGCOLOR="#000000">
			<TD><font size=2 color=white>{$spyid}</font></TD>
			<TD><font size=2 color=white>{$job}</font></TD>
			<TD><font size=2><a href=spy.php?command=change&spy_id={$spyid}&planet_id={$planet_id}>{$move}</a></font></TD>
			<TD><font size=2><a href=spy.php?command=comeback&spy_id={$spyid}&planet_id={$planet_id}&doit=1>{$l_yes}</a><BR><a href=planet.php?planet_id={$planet_id}>{$l_no}</a></font></TD>
			</TR></TABLE><BR>
		{else}
			{$l_spy_backonship}<BR>
		{/if}
	{else}
		{$l_spy_backfailed}<BR><BR>
	{/if}
	
	<a href=planet.php?planet_id={$planet_id}>{$l_clickme}</a> {$l_toplanetmenu}<br><br>

	<a href=spy.php>{$l_clickme}</a> {$l_spy_menu}

</td></tr>
<tr><td><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
