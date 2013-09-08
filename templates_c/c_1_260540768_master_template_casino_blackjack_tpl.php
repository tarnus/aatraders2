<H1><?php echo $this->_vars['title']; ?></H1>

<table width="750" border="0" cellspacing="0" cellpadding="0" align="center" bgcolor="#1A640F">

<tr>
	<td colspan="3" valign="middle"><table align="center" width="80%"><tr><td align="center" valign="middle"><FONT color="White" size="+1"><b><?php if ($this->_vars['status'] == "DealerWin" || $this->_vars['status'] == "Bust" || $this->_vars['status'] == "SBust"): ?>
<?php echo $this->_vars['l_dealerwins']; ?>
<?php elseif ($this->_vars['status'] == "DealerBust"): ?>
<?php echo $this->_vars['l_dealerbust']; ?>
<?php elseif ($this->_vars['status'] == "Push"): ?>
<?php echo $this->_vars['l_push']; ?>
<?php elseif ($this->_vars['status'] == "DealerBlackJack"): ?>
<?php echo $this->_vars['l_dealerblackjack']; ?>
<?php endif; ?>
<?php if ($this->_vars['status'] == "SDealerWin"): ?>
<?php echo $this->_vars['l_dealerwins']; ?>
<?php elseif ($this->_vars['status'] == "SDealerBust"): ?>
<?php echo $this->_vars['l_dealerbust']; ?>
<?php elseif ($this->_vars['status'] == "SPush"): ?>
<?php echo $this->_vars['l_push']; ?>
<?php elseif ($this->_vars['status'] == "SDealerBlackJack"): ?>
<?php echo $this->_vars['l_dealerblackjack']; ?>
<?php elseif ($this->_vars['status'] == "PlayerWin" || $this->_vars['status'] == "PlayerBlackJack" || $this->_vars['status'] == "PlayerBlackJackIns" || $this->_vars['status'] == "SPlayerWin" || $this->_vars['status'] == "SPlayerBlackJack"): ?>
<?php echo $this->_vars['l_dealerloses']; ?>

<?php endif; ?></b></font></td><td valign="middle" align="center"><table border="1" cellspacing="1"  bgcolor="#1A640F" bordercolorlight="black" bordercolordark="silver" cellpadding="0" align="center">
<tr>
<td ><font color="white"><b>Credits</b></FONT></td><td><font color="white"><b><?php echo $this->_vars['cash']; ?></b></FONT></td>
</tr>
<tr>
<td ><font color="white"><b>Bet</b></FONT></td><td><font color="white"><b><?php echo $this->_vars['bet']; ?></b></FONT></td>
</tr>
</table></td><td align="center" valign="middle"><FONT color="White" size="+1"><b>
<?php if ($this->_vars['status'] == "Bust"): ?>
<?php echo $this->_vars['l_playerbust']; ?>
<?php elseif ($this->_vars['status'] == "PlayerWin" || $this->_vars['status'] == "DealerBust" || $this->_vars['status'] == "SDealerBust"): ?>
<?php echo $this->_vars['l_playerwins']; ?>
<?php elseif ($this->_vars['status'] == "PlayerBlackJack" || $this->_vars['status'] == "PlayerBlackJackIns"): ?>
<?php echo $this->_vars['l_playerblackjack']; ?>
<?php elseif ($this->_vars['status'] == "Push"): ?>
<?php echo $this->_vars['l_push']; ?>
<?php elseif ($this->_vars['status'] == "SBust"): ?>
<?php echo $this->_vars['l_playerbust']; ?>
<?php elseif ($this->_vars['status'] == "SPlayerWin"): ?>
<?php echo $this->_vars['l_playerwins']; ?>
<?php elseif ($this->_vars['status'] == "SPlayerBlackJack"): ?>
<?php echo $this->_vars['l_playerblackjack']; ?>
<?php elseif ($this->_vars['status'] == "SPush"): ?>
<?php echo $this->_vars['l_push']; ?>
<?php elseif ($this->_vars['status'] == "DealerWin" || $this->_vars['status'] == "DealerBlackJack" || $this->_vars['status'] == "SDealerWin" || $this->_vars['status'] == "SDealerBlackJack"): ?>
<?php echo $this->_vars['l_playerloses']; ?>
<?php endif; ?></b></font></td></tr></TABLE>
</td>
</tr>
  <tr> 
    <td  align="center" rowspan="2" bgcolor="#1A640F" valign="top"><img src="templates/master_template/images/casino/spacer.gif" width="114" height="5"><br>

<table border="1" cellspacing="1" width="80" bgcolor="#1A640F" bordercolorlight="black" bordercolordark="silver" cellpadding="0" align="center">
<?php if ($this->_vars['hand'] == 0 && $this->_vars['split_flag'] == 2): ?>
<tr>
<td align="center"><font color="white"><b><?php echo $this->_vars['l_firsthand']; ?></b></FONT></td>
</tr>
<?php elseif ($this->_vars['hand'] == 1 && $this->_vars['split_flag'] == 2): ?>
<tr>
<td align="center"><font color="white"><b><?php echo $this->_vars['l_secondhand']; ?></b></FONT></td>
</tr>

<?php endif; ?>

<?php if ($this->_vars['hand'] == 0): ?>
<?php if ($this->_vars['status'] == "Bust" || $this->_vars['status'] == "" || $this->_vars['status'] == "DealerWin" || $this->_vars['status'] == "PlayerWin" || $this->_vars['status'] == "DealerBust" || $this->_vars['status'] == "Push" || $this->_vars['status'] == "PlayerBlackJack" || $this->_vars['status'] == "DealerBlackJack" || $this->_vars['status'] == "PlayerBlackJackIns" || $this->_vars['status'] == "Bet" || $this->_vars['status'] == "no bet" && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Bet"><?php echo $this->_vars['l_bet']; ?></a></td>
</tr>

<?php elseif ($this->_vars['status'] == "Insurance"): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Insurance"><?php echo $this->_vars['l_insurance']; ?></a></td>
</tr>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Hit"><?php echo $this->_vars['l_hit']; ?></a></td>
</tr>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Stand"><?php echo $this->_vars['l_stand']; ?></a></td>
</tr>

	<?php if ($this->_vars['playercards'] == 2 && $this->_vars['split_flag'] == 0): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=DoubleD"><?php echo $this->_vars['l_doubledown']; ?></a></td>
</tr>	

	<?php endif; ?>
<?php else: ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Hit"><?php echo $this->_vars['l_hit']; ?></a></td>
</tr>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Stand"><?php echo $this->_vars['l_stand']; ?></a></td>
</tr>

	<?php if ($this->_vars['playercards'] == 2 && $this->_vars['split_flag'] == 0 && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=DoubleD"><?php echo $this->_vars['l_doubledown']; ?></a></td>
</tr>	

	<?php endif; ?>
<?php endif; ?>
<?php else: ?>
<?php if ($this->_vars['status'] == "SBust" || $this->_vars['status'] == "" || $this->_vars['status'] == "SDealerWin" || $this->_vars['status'] == "SPlayerWin" || $this->_vars['status'] == "SDealerBust" || $this->_vars['status'] == "SPush" || $this->_vars['status'] == "SPlayerBlackJack" || $this->_vars['status'] == "SDealerBlackJack" || $this->_vars['status'] == "SPlayerBlackJackIns" || $this->_vars['status'] == "Bet" && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Bet"><?php echo $this->_vars['l_bet']; ?></a></td>
</tr>

<?php elseif ($this->_vars['status'] == "SInsurance" && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Insurance&hand=1"><?php echo $this->_vars['l_insurance']; ?></a></td>
</tr>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Hit&hand=1"><?php echo $this->_vars['l_hit']; ?></a></td>
</tr>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Stand&hand=1"><?php echo $this->_vars['l_stand']; ?></a></td>
</tr>

	<?php if ($this->_vars['playercards'] == 2 && $this->_vars['split_flag'] == 0 && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=DoubleD&hand=1"><?php echo $this->_vars['l_doubledown']; ?></a></td>
</tr>	

	<?php endif; ?>
<?php else: ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Hit&hand=1"><?php echo $this->_vars['l_hit']; ?></a></td>
</tr>	
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Stand&hand=1"><?php echo $this->_vars['l_stand']; ?></a></td>
</tr>

	<?php if ($this->_vars['playercards'] == 2 && $this->_vars['split_flag'] == 0 && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=DoubleD&hand=1"><?php echo $this->_vars['l_doubledown']; ?></a></td>
</tr>	
	<?php endif; ?>
<?php endif; ?>
<?php endif; ?>

<?php if ($this->_vars['split_flag'] == 1 && $this->_vars['availcash'] == 1): ?>
<tr>
<td align="center"><a href="casino.php?casinogame=casino_blackjack&action=Split"><?php echo $this->_vars['l_split']; ?></a></td>
</tr>

<?php endif; ?>
<tr>
<td align="center"><a href="port.php"><?php echo $this->_vars['l_lobby']; ?></a></td>
</tr>
</table>
</td>
    <td background="templates/master_template/images/casino/blackjack/bjtop2.jpg" align="center" valign="middle"><img src="templates/master_template/images/casino/spacer.gif" width="522" height="1">
    <TABLE cellpadding="0" cellspacing="0" border="0" align="center">
    	<tr>
    		<td align="center"><font color="White"><b>
</td
    	</tr>    
    	<tr>
    		<td align="center">
<?php if ($this->_vars['status'] != "Bet"): ?>
<?php echo $this->_vars['dealerout']; ?>
<?php endif; ?></td
    	</tr>
    </table>

</td>
    <td><img src="templates/master_template/images/casino/blackjack/bjtop3.jpg" width="114" height="146"></td>
  </tr>
  <tr> 

    <td background="templates/master_template/images/casino/blackjack/bjmid2.jpg" align="center" valign="middle"><img src="templates/master_template/images/casino/spacer.gif" width="522" height="1"><br>
    <TABLE align="center"><tr><td>
<?php if ($this->_vars['status'] != "Bet"): ?>
<?php echo $this->_vars['playerout']; ?>
<?php endif; ?>
</td></tr>
<tr>
<td align="center"><FONT color="White" ><b>
<?php if ($this->_vars['status'] == "Bust"): ?>
<?php echo $this->_vars['l_playerbust']; ?>
<?php elseif ($this->_vars['status'] == "PlayerWin" || $this->_vars['status'] == "DealerBust"): ?>
<?php echo $this->_vars['l_playerwins']; ?>
<?php elseif ($this->_vars['status'] == "PlayerBlackJack" || $this->_vars['status'] == "PlayerBlackJackIns"): ?>
<?php echo $this->_vars['l_playerblackjack']; ?>
<?php elseif ($this->_vars['status'] == "Push"): ?>
<?php echo $this->_vars['l_push']; ?>
<?php elseif ($this->_vars['status'] == "DealerWin" || $this->_vars['status'] == "DealerBlackJack"): ?>
<?php echo $this->_vars['l_playerloses']; ?>
<?php endif; ?></B></FONT>
</td>
</tr>
<?php if ($this->_vars['status'] == "Bet"): ?><tr><td colspan="3" align="center"><br>
<center><form action="casino.php" method="post">
					<input type="Hidden" name="casinogame" value="casino_blackjack">
	<font color="White"><b><?php echo $this->_vars['l_place_bet']; ?>: <input type="text" name="bet_amt" width="10" size="10" value="<?php echo $this->_vars['old_bet']; ?>">
					<input type="Hidden" name="action" value="Deal">
					<input type="Submit" value="Bet">
</form></b></font></center></td></tr><?php elseif ($this->_vars['status'] == "no bet"): ?>
<tr><td colspan="3" align="center"><br><font color="White"><b><?php echo $this->_vars['l_nobet']; ?></b></font></center></td></tr><?php endif; ?></TABLE>   

</td>
    <td><img src="templates/master_template/images/casino/blackjack/bjmid3.gif" width="114" height="141"></td>
  </tr>
  <tr  bgcolor="#1A640F"> 
    <td><img src="templates/master_template/images/casino/blackjack/bjlow1.gif" width="114" height="120"></td>
    <td> <TABLE align="center"><tr><td>
<?php if ($this->_vars['split_flag'] == 2 || $this->_vars['hand'] == 1): ?>
<?php echo $this->_vars['playersplitout']; ?>
<?php endif; ?>
</td></tr>
<tr>
<td align="center"><FONT color="White" ><b>
<?php if ($this->_vars['status'] == "SBust"): ?>
<?php echo $this->_vars['l_playerbust']; ?>
<?php elseif ($this->_vars['status'] == "SPlayerWin" || $this->_vars['status'] == "SDealerBust"): ?>
<?php echo $this->_vars['l_playerwins']; ?>
<?php elseif ($this->_vars['status'] == "SPlayerBlackJack"): ?>
<?php echo $this->_vars['l_playerblackjack']; ?>
<?php elseif ($this->_vars['status'] == "SPush"): ?>
<?php echo $this->_vars['l_push']; ?>
<?php elseif ($this->_vars['status'] == "SDealerWin" || $this->_vars['status'] == "SDealerBlackJack"): ?>
<?php echo $this->_vars['l_playerloses']; ?>
<?php endif; ?></B></FONT>
</td>
</tr>
</TABLE></td>
    <td><img src="templates/master_template/images/casino/blackjack/bjlow3.gif" width="114" height="120"></td>
  </tr>

</table>

