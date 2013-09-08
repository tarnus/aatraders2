<center>
<h1><?php echo $this->_vars['title']; ?></h1>
<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['version']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['release_version']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_time_since_reset']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['totaltime']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_allowpl']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_allowplresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_allownewpl']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_allownewplresponse']; ?></font></td>
  </tr>
		</table>
	</td>
  </tr>
</table>


<h1><?php echo $this->_vars['title2']; ?></h1>
<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_allowteamplcreds']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_allowteamplcredsresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_allowfullscan']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_allowfullscanresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_sofa']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_sofaresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_showpassword']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_showpasswordresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_genesisdestroy']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_genesisdestroyresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_igb']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_igbresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_ksm']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_ksmresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_navcomp']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_navcompresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_newbienice']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_newbieniceresponse']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_spies']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_spiesresponse']; ?></font></td>
  </tr>
  <?php if ($this->_vars['enable_spies']): ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_spycapture']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['l_s_spycaptureresponse']; ?></font></td>
  </tr>
  <?php endif; ?>
		</table>
	</td>
  </tr>
</table>


<h1><?php echo $this->_vars['title3']; ?></h1>
<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_gameversion']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['game_name']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_averagetechewd']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['ewd_maxavgtechlevel']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_numsectors']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['sector_max']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_maxwarpspersector']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['link_max']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_averagetechfed']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['fed_max_avg_tech']; ?></font></td>
  </tr>
  <?php if ($this->_vars['allow_ibank']): ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_igbirateperupdate']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['bankinterest']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_igblrateperupdate']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['loaninterest']; ?></font></td>
  </tr>
  <?php endif; ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_techupgradebase']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['basedefense']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_collimit']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['colonist_limit']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_maxturns']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['max_turns']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_maxplanetssector']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['max_planets_sector']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_maxtraderoutes']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['max_traderoutes_player']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_colreprodrate']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['colonist_reproduction_rate']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_energyperfighter']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['energy_per_fighter']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_secfighterdegrade']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['defense_degrade_rate']; ?></font></td>
  </tr>
  <?php if ($this->_vars['enable_spies']): ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_spiesperplanet']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['max_spies_per_planet']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_spysuccessfactor']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['enable_spies2']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_spykillfactor']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['spy_kill_factor']; ?></font></td>
  </tr>
  <?php endif; ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_colsperfighter']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['fighter_prate']; ?></font></td>
  </tr>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_colspertorp']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['torpedo_prate']; ?></font></td>
  </tr>
  <?php $this->_foreach['foreach1'] = array('total' => count((array)$this->_vars['cargoproductionname']), 'iteration' => 0);
if (count((array)$this->_vars['cargoproductionname'])): foreach ((array)$this->_vars['cargoproductionname'] as $this->_vars['key'] => $this->_vars['item']): $this->_foreach['foreach1']['iteration']++;
 ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['cargoproductionname'][$this->_vars['key']]; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['cargoprate'][$this->_vars['key']]; ?></font></td>
  </tr>
  <?php endforeach; endif; ?>
  <tr bgcolor="#000000">
	<td width="500"><font size="2" color="#FFFFFF"><?php echo $this->_vars['l_s_colspercreds']; ?></font></td>
	<td align="right" width="150"><font size="2" color="#00ff00"><?php echo $this->_vars['credits_prate']; ?></font></td>
  </tr>
		</table>
	</td>
  </tr>
</table>


<?php extract($this->_vars, EXTR_REFS);  
for($i = 0; $i < $listcount; $i++)
{
	$variables = explode("|", $variablelist[$i]);
	if($variables[0] == "section")
	{
		if($i != 0)
		{
		 ?>
<tr><td><br><br><?php echo $this->_vars['l_global_mlogin']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
		<?php extract($this->_vars, EXTR_REFS);  
		}
		echo "<h1>$variables[1]</h1>";
		$i++;
		$variables = explode("|", $variablelist[$i]);
 ?>
<table width="650" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
<?php extract($this->_vars, EXTR_REFS);  
	}
	echo "<tr bgcolor=\"#000000\">
	<td align=\"center\" width=\"200\"><font size=\"2\" color=\"#FFFFFF\">$variables[0]</font></td>
	<td align=\"center\" width=\"100\"><font size=\"2\" color=\"#00ff00\">$variables[1]</font></td>
	<td align=\"left\" width=\"300\"><font size=\"2\" color=\"#00ff00\">$variables[2]</font></td>
  </tr>
  <tr><td colspan=3><img src = \"templates/" . $templatename . "images/spacer.gif\" height=8></td></tr>
";
}
 ?>
<tr><td><br><br><?php echo $this->_vars['l_global_mlogin']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
