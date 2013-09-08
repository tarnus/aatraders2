<h1><?php echo $this->_vars['title']; ?></h1>

<table border="1" cellspacing="1" cellpadding="2" width="600" align="center">
	<TR BGCOLOR="#585980">
		<TD align="center"><font color="white"><B><?php echo $this->_vars['l_probe_scan']; ?></B></font></TD>
	</TR>
	<TR BGCOLOR="#23244F">
		<TD>
		<?php if ($this->_vars['warplinks'] != ""): ?>
			<?php echo $this->_vars['warplinks']; ?>
		<?php endif; ?>
		<?php if ($this->_vars['lastship'] != ""): ?>
			<?php echo $this->_vars['lastship']; ?>
		<?php endif; ?>
		<?php if ($this->_vars['portinfo'] != ""): ?>
			<?php echo $this->_vars['portinfo']; ?>
		<?php endif; ?>
		<?php if ($this->_vars['sector_def'] != ""): ?>
			<?php echo $this->_vars['sector_def']; ?>
		<?php endif; ?>
		<?php if ($this->_vars['shipdetect'] != ""): ?>
			<?php echo $this->_vars['shipdetect']; ?>
		<?php endif; ?>
		<?php if ($this->_vars['planetinfo'] != ""): ?>
			<?php echo $this->_vars['planetinfo']; ?>
		<?php endif; ?>
		<?php if ($this->_vars['nothing_detected']): ?>
			<?php echo $this->_vars['l_probe2_nothing']; ?>
		<?php endif; ?>

		</TD>
	</TR>
</TABLE>
<table cellspacing = "0" cellpadding = "0" border = "0" width="100%">
	<tr>
		<td><br><br><a href="probes.php"><?php echo $this->_vars['l_clickme']; ?></a> <?php echo $this->_vars['l_probe_linkback']; ?>.
		</td>
	</tr>
	<tr><td><br><br><?php echo $this->_vars['gotomain']; ?><br><br></td></tr>
</table>
