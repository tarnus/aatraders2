<H1><?php echo $this->_vars['title']; ?></H1>
<?php echo '
<script language="javascript" type="text/javascript">
function clean_js()
{
	// Here we cycle through all form values (other than buy, or full), and regexp out all non-numerics. (1,000 = 1000)
	// Then, if its become a null value (type in just a, it would be a blank value. blank is bad.) we set it to zero.
	var form = document.forms[0];
	var i = form.elements.length;
	while (i > 0)
	{
		if ((form.elements[i-1].type == \'text\') && (form.elements[i-1].name != \'\'))
		{
			var tmpval = form.elements[i-1].value.replace(/\\D+/g, "");
			if (tmpval != form.elements[i-1].value)
			{
				form.elements[i-1].value = form.elements[i-1].value.replace(/\\D+/g, "");
			}
		}
		if (form.elements[i-1].value == \'\')
		{
			form.elements[i-1].value =\'0\';
		}
		i--;
	}
}
</script>
'; ?>


<table width="500" border="1" cellspacing="0" cellpadding="4" align="center">
  <tr>
    <td bgcolor="#000000" valign="top" align="center" colspan=2>
		<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
			<TR>
				<TD>
<?php echo $this->_vars['l_md_consist']; ?><BR>

<?php if ($this->_vars['defenseid'] == $this->_vars['playerid']): ?>
	<?php echo $this->_vars['l_md_youcan']; ?>:<BR>
	<FORM ACTION=defense_modify.php METHOD=POST>
	<?php echo $this->_vars['l_md_retrieve']; ?> <INPUT TYPE=TEST NAME=quantity SIZE=10 MAXLENGTH=10 VALUE=0> <?php echo $this->_vars['defense_type']; ?>&nbsp;&nbsp;&nbsp;
	<input type=hidden name=response value=retrieve>
	<input type=hidden name=defense_id value=<?php echo $this->_vars['defense_id']; ?>>
	<INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_submit']; ?> ONCLICK="clean_js()"><BR><BR>
	</FORM>
<?php else: ?>
	<?php if ($this->_vars['fight'] == 1): ?>
		<FORM ACTION=defense_modify.php METHOD=POST>
		<?php echo $this->_vars['l_md_attdef']; ?><BR><INPUT TYPE=SUBMIT VALUE=<?php echo $this->_vars['l_md_attack']; ?>>&nbsp;&nbsp;&nbsp;
		<input type=hidden name=response value=fight>
		<input type=hidden name=defense_id value=<?php echo $this->_vars['defense_id']; ?>>
		</FORM>
	<?php endif; ?>
<?php endif; ?>

</td></tr>

<tr><td><?php echo $this->_vars['gotomain']; ?><br><br>
				</td>
			</tr>
		</table>
	</td>
  </tr>
</table>
