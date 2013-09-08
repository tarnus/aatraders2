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
	{if $executecommand}
		{$bountystatus}<BR><BR>

		<B>{$l_spy_sendtitle}</B><BR>
		<FORM ACTION=spy.php METHOD=POST>
		<INPUT TYPE=hidden name=command value=send>
		<INPUT TYPE=hidden name=doit value=1>
		<INPUT TYPE=hidden name=planet_id value={$planet_id}>
		<INPUT TYPE=RADIO NAME=mode VALUE=none>{$l_spy_type1}<BR>
		<INPUT TYPE=RADIO NAME=mode VALUE=toship CHECKED>{$l_spy_type2}<BR>
		<INPUT TYPE=RADIO NAME=mode VALUE=toplanet>{$l_spy_type3}<BR><BR>
		
		{$l_spy_trytitle}:<BR>
		{foreach key=key value=item from=$job_name}
			{if $jobid == $key}
				<INPUT TYPE="radio" name="jobid" value="{$key}" CHECKED> {$job_name[$key]} - {$description[$key]}<br>
			{else}
				<INPUT TYPE="radio" name="jobid" value="{$key}"> {$job_name[$key]} - {$description[$key]}<br>
			{/if}
		{/foreach}
			<br>
		<INPUT TYPE=submit value="{$l_spy_sendbutton}">
		</FORM>
	{else}
		{$playerbounty}<br><br>
		{$sendstatus}<br><br>
	{/if}   
	<a href=planet.php?planet_id={$planet_id}>{$l_clickme}</a> {$l_toplanetmenu}<br>
	<a href=spy.php>{$l_clickme}</a> {$l_spy_menu}

</td></tr>
<tr><td><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
