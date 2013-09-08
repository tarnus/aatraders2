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
  <B>{$l_spy_cleanupshiptitle}</B><BR>
  {if $executecommand} 
	<FORM ACTION=spy.php METHOD=POST>
	<INPUT TYPE=hidden name=command value=cleanup_ship>
	<INPUT TYPE=hidden name=doit value=1>
	<INPUT TYPE=RADIO NAME=type VALUE=1 {$set1}> {$l_spy_cleanupshiptext1}<BR>
	<INPUT TYPE=RADIO NAME=type VALUE=2 {$set2}> {$l_spy_cleanupshiptext2}<BR>
	<INPUT TYPE=RADIO NAME=type VALUE=3 {$set3}> {$l_spy_cleanupshiptext3}<BR><BR>
	
	{if $disabled}
		{$cleanupstatus}
	{else}
		<INPUT TYPE=submit value="{$cleanupstatus}">
	{/if}
	
	</FORM>
  {else}
	<B>{$l_spy_cleanupshiptitle2}</B><BR>

	{if $disabled != "DISABLED"}
		{php}
	  	for($i = 0; $i < $spycount; $i++)
		{
			echo "$spyinfo[$i]<BR>";
		}
   		{/php}
		
	  {if !$found}
		{$l_spy_spynotfoundonship}<BR>
	  {/if}
	{else}
		<BR>{$l_spy_notenough}<BR>
	{/if}
  {/if}
	<a href=spy.php>{$l_clickme}</a> {$l_spy_menu}

</td></tr>
<tr><td><br><br>{$gotomain}<br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
