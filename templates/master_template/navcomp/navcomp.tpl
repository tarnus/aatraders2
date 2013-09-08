<h1>{$title}</h1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
{if !$allow_navcomp}
$l_nav_nocomp<br><br>
{else}
	{if $state == "showlist"}
		<form action="navcomp.php" method=post>
		{$l_nav_query} <input name=stop_sector>
		<input type=submit value={$l_submit}><br>
		<input name=state value="searchresult" type=hidden>
		</form>
	{else}
		{if $found > 0}
			<h3>{$l_nav_pathfnd}</h3>
			{$start_sector} {$forward_search_results_echo}<br>
			{$l_nav_answ1} {$forward_search_depth} {$l_nav_answ2}<br><br>

			<form action="navcomp.php" enctype="multipart/form-data">
			Immediately Execute Route without Saving: 
			<input type="hidden" name="state" value="immediatestart">
			<input type="hidden" name="destination" value="{$destination}">
			<input type="hidden" name="forward_warp_list" value="{$forward_warp_list}">
			<input type="submit" value="Execute Route">
			</form>
		{else}
			{if $found == 0}
				{$l_nav_proper}<br><br>
			{else}
				({$sectorname}) : {$l_nav_notinlogs}<br><br>
			{/if}
		{/if}

		{if $return_found > 0}
			<h3>{$l_nav_pathfnd}</h3>
			{$destination} {$return_search_results_echo}<br>
			{$l_nav_answ1} {$return_search_depth} {$l_nav_answ2}<br><br>
		{else}
			{if $return_found == 0}
				{$l_nav_proper}<br><br>
			{else}
				({$start_sector}) : {$l_nav_notinlogs}<br><br>
			{/if}
		{/if}

	{/if}
{/if}

<form action="navcomp.php" enctype="multipart/form-data">
{$l_nav_autoroutename} <input type="text" name="name" value="">
<input type="hidden" name="found" value="{$found}">
<input type="hidden" name="return_found" value="{$return_found}">
<input type="hidden" name="state" value="create">
<input type="hidden" name="start_sector" value="{$start_sector}">
<input type="hidden" name="destination" value="{$destination}">
<input type="hidden" name="return_warp_list" value="{$return_warp_list}">
<input type="hidden" name="forward_warp_list" value="{$forward_warp_list}">
<input type="submit" value="{$l_autoroute_createroute}">
</form>

</td></tr>
<tr><td colspan=3>{$l_autoroute_return} <a href="navcomp.php">{$l_clickme}</a>.</td></tr>
										<tr><td width="100%" colspan=3><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>

