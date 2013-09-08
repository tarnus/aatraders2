<H1><?php echo $this->_vars['title']; ?></H1>

<table width="80%" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<form action='casino.php' enctype='multipart/form-data' method='post'>
<input type='hidden' name='casinogame' value='casino_forums'>
<input type='hidden' name='command' value='finishreply'>
<input type='hidden' name='topic_id' value="<?php echo $this->_vars['topic_id']; ?>">
<b><?php echo $this->_vars['l_forums_message']; ?></b><br><textarea cols='80' rows='10' name='topicmessage'></textarea><br><br>
<input type='submit' name='Post Topic'>
</form>
				</td>
			</tr>
<tr><td><br><a href='casino.php?casinogame=casino_forums&command=showtopics'><?php echo $this->_vars['l_forums_showtopic']; ?></a></td></tr>
<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
		</table>
	</td>
  </tr>
</table>
