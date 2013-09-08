<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
		<div align="center">
		  <center>
		  <table border="0" cellspacing="1" width="100%">
			<tr>
			  <td width="100%" bgcolor="black">
				<div align="center">
				  <table border="0" cellspacing="1" width="100%" bordercolorlight="black">
					<tr>
					  <td width="75%" align="left"><font color="white" size="2"><b><?php echo $this->_vars['topictype'];  echo $this->_vars['l_forums_subject'];  echo $this->_vars['topic_title']; ?></b></font></td>
					  <td width="21%" align="center" nowrap><font color="white" size="2"><?php echo $this->_vars['l_forums_reply'];  echo $this->_vars['totalposts']; ?>&nbsp;&nbsp;&nbsp;<?php echo $this->_vars['l_forums_date'];  echo $this->_vars['topicstartdate']; ?>&nbsp;</font></td>
					  <td width="4%" align="center" bordercolorlight="black">
					  	<?php if ($this->_vars['is_infoport'] != 1): ?>
					  		<A HREF="main.php"><img alt="Click here to return to the main menu" src="templates/master_template/images/c95x.png" width="16" height="14" border="0"></a>
					  	<?php else: ?>
					  		<A HREF="javascript:window.close();"><img alt="Click here to Close" src="templates/master_template/images/c95x.png" width="16" height="14" border="0"></a>
					  	<?php endif; ?></td>
					</tr>
				  </table>
				</div>
			  </td>
			</tr>

		<?php if ($this->_vars['totalposts2'] > 0): ?>
		<?php extract($this->_vars, EXTR_REFS);  
			for($i = 0; $i < $count; $i++){
			echo "<a name=\"$postid[$i]\"></a>";
			echo "<tr>";
			echo "  <td width=\"100%\" align=\"center\" bgcolor=\"black\" height=\"4\"></td>";
			echo "</tr>";
			echo "<tr>";
			echo "  <td width=\"100%\" bgcolor=\"black\" bordercolorlight=\"black\">";
			echo "	<div align=\"center\">";
			echo "	  <table border=\"0\" cellspacing=\"1\" width=\"100%\" cellpadding=\"0\">";
			echo "		<tr>";
			echo "		  <td width=\"150\" aligh=\"left\"><font color=\"white\" size=\"2\"><b>$l_readm_sender:</b></td>";
			echo "		  <td width=\"64\" align=\"left\"><img src=\"images/avatars/$avatarimg[$i]\"></td>";
			echo "		  <td align=\"left\">&nbsp;<font color=\"yellow\" size=\"2\">$accounttypes[$i] $postusername[$i]</font></td>";
			echo "		  <td width=\"20%\" align=\"center\"><font color=\"white\" size=\"2\">$postdate[$i]</font></td>";
			echo "		</tr>";
			echo "	  </table>";
			echo "	</div>";
			echo "  </td>";
			echo "</tr>";
			echo "<tr>";
			echo "  <td width=\"100%\" bgcolor=\"black\" bordercolorlight=\"black\">";
			echo "	<div align=\"center\">";
			echo "	  <table border=\"0\" cellspacing=\"1\" width=\"100%\" bordercolorlight=\"black\">";
			echo "		<tr>";
			echo "		  <td width=\"100%\" class=\"footer\"><font color=\"white\">$posttext[$i]</font></td>";
			echo "		</tr>";
			if($posteditcount[$i] != 0){
			echo "		<tr>";
			echo "		  <td width=\"100%\" class=\"footer\"><font color=\"red\">$l_forums_edited $posteditcount[$i] $shows[$i] - $l_forums_lastedit $posteditdate[$i]</font></td>";
			echo "		</tr>";
			}
			echo "	  </table>";
			echo "	</div>";
			echo "  </td>";
			echo "</tr>";
			if($is_infoport != 1)
			{
				echo "<tr>";
				echo "  <td width=\"100%\" align=\"center\" bgcolor=\"black\" bordercolorlight=\"black\">";
				echo "	<div align=\"center\">";
				echo "	  <table border=\"0\" cellspacing=\"1\" width=\"100%\" bordercolorlight=\"black\" cellpadding=\"0\">";
				echo "		<tr>";
				echo "		  <td width=\"100%\" align=\"center\" valign=\"middle\">";
				if($forumadmin == 1){
				echo "		  	 | <A class=\"but\" HREF=\"casino.php?casinogame=casino_forums&command=delete&post_id=$postid[$i]&topic_id=$topic_id\">$l_readm_del</A>";
				}
				if(($forumadmin == 1 or $isposter[$i]) and $topic_status != 0){
				echo "		  	 | <A class=\"but\" HREF=\"casino.php?casinogame=casino_forums&command=edit&post_id=$postid[$i]&topic_id=$topic_id\">$l_forums_edit</A>";
				}
				if($topic_status != 0){
				echo "			 | <A class=\"but\" HREF=\"casino.php?casinogame=casino_forums&command=postreply&topic_id=$topic_id\">$l_readm_repl</A>";
				}
				echo " |";
				echo "		  </td>";
				echo "		</tr>";
				echo "	  </table>";
				echo "	</div>";
				echo "  </td>";
				echo "</tr>";
				}
				echo "<tr>";
				echo "  <td width=\"100%\" align=\"center\" bgcolor=\"black\" height=\"4\"></td>";
				echo "</tr>";
				if ($forumadmin == 1 and $topic_status != 9){
				echo "<tr>";
				echo "  <td width=\"100%\" align=\"center\" bgcolor=\"black\" bordercolorlight=\"black\">";
				echo "	<div align=\"center\">";
				echo "	  <table border=\"0\" cellspacing=\"1\" width=\"100%\" bordercolorlight=\"black\" cellpadding=\"0\">";
				echo "		<tr>";
				echo "		  <td width=\"100%\" align=\"center\" valign=\"middle\">";
				echo "		  	 | <A class=\"but\" HREF=\"casino.php?casinogame=casino_forums&command=lock&topic_id=$topic_id\">$l_forums_lock</A> |";
				echo "		  </td>";
				echo "		</tr>";
				echo "	  </table>";
				echo "	</div>";
				echo "  </td>";
				echo "</tr>";
				}
			}
			 ?>
		<?php endif; ?>
		  </table>
		  </center>
				</td>
			</tr>
<?php if ($this->_vars['is_infoport'] != 1): ?>
	<tr><td><br><a href='casino.php?casinogame=casino_forums&command=showtopics'><?php echo $this->_vars['l_forums_showtopic']; ?></a></td></tr>
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
<?php else: ?>
	<tr align="center"><td><br><a href="javascript:window.close();">Close<?php echo $this->_vars['l_close']; ?></a><br><br></td></tr>
<?php endif; ?>
		</table>
	</td>
  </tr>
</table>
