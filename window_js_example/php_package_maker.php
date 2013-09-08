<?php
/*
	package::i.tools
	
	php-packages	v1.0	-	www.ipunkt.biz
	
	(c)	2002 - www.ipunkt.biz (rok)
*/

// FUNCTIONS //
function getDirs()
{
	$d = dir( dirname(__FILE__) );
	while ( $entry = $d->read() )
	{
		if ( $entry != "." && $entry != ".." && is_dir($entry) )
			$result[] = $entry."/";
	}
	$d->close();
	return $result;
}

function getFiles()
{
	$d = dir( dirname(__FILE__) );
	while ( $entry = $d->read() )
	{
		if ( $entry != "." && $entry != ".." && is_file($entry) )
			$result[] = $entry;
	}
	$d->close();
	return $result;
}

// MAIN //
header ("Cache-Control: no-cache, must-revalidate");
header ("Pragma: no-cache");

?>
<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
<head>
	<title>php-package-maker v1.0</title>
	<base href="http://www.ipunkt.biz/service/">
	<link rel="stylesheet" href="itools.css" type="text/css" />
</head>

<body>
<?

$okay = ( $_POST['directories'] || $_POST['files'] ) && $_POST['pk_name'];

//	FORM DATA SENT	//
if ( $okay )
{
	require_once("class.package_maker.php");
	
	$pkg = new package($_POST['pk_name']);
	
	if ( !empty($_POST['directories']) )
	{
		foreach ( $_POST['directories'] as $dir )
		{
			$pkg->addDirectory($dir);
		}
	}
	if ( !empty($_POST['files']) )
	{
		foreach ( $_POST['files'] as $file )
		{
			$pkg->add($file);
		}
	}
	if ( !empty($_POST['config']) )
	{
		$pkg->setConfig($_POST['config']);
	}
	$result = $pkg->create();
	
	$pi = $pkg->getPackageInformation();
?>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr> 
		<td><img height="1" alt="" src="images/spacer.gif" width="12" border="0"></td>
		<td width="100%" class="content"><b>New Package generates</b>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr><td><img height="15" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" background="images/bgt.gif" border="0">
				<tr valign="top">
					<td><img height="27" alt="" src="images/ctl.gif" width="27" border="0"></td><!--ecke, oben links-->
					<td background="../images/hd_bg.gif" class="headline" nowrap>Package<img height="15" alt="" src="../images/hd_br.gif" width="30" border="0" align="absmiddle"></td><!--headline-->
					<td align="right" width="100%"><img height="27" alt="" src="images/ctr.gif" width="14" border="0"></td><!--abschluss, oben rechts-->
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" bgcolor="#ffffff" border="0">
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>Package file</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									<a href="http://www.ipunkt.biz/" target="_new" title="www.ipunkt.biz - mit stil im internet präsent sein"><img src="http://www.ipunkt.biz/images/advertizer.gif" width="88" height="31" border="0" align="right" /></a>
									Here you see the result of your attitudes.  
									<br /><img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br />
									Status message of the php-package-maker: <b><?php echo ( $result ) ? '<span style="color: green">well done</span>' : '<span style="color: red">error occured</span>' ?></b><br /><br/>
									<?php echo $pkg->getPackageFilename() ?>&nbsp;&nbsp;&nbsp;(<?php echo filesize($pkg->getPackageFilename()) ?> bytes)<br />
									<dd>creation-time: <?php echo $pi['creation'] ?></dd>
									<dd>file-count: <?php echo $pi['files'] ?></dd>
									<dd>size-of-all-files: <?php echo $pi['files_size'] ?> bytes</dd>
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr>
					<td background="images/bgb.gif"><img height="14" alt="" src="images/cbl.gif" width="27" border="0"></td>
					<td align="right" width="100%" background="images/bgb.gif"><img height="14" alt="" src="images/cbr.gif" width="14" border="0"></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr> 
		<td><img height="1" alt="" src="images/spacer.gif" width="12" border="0"></td>
		<td width="100%" class="content"><b>&nbsp;</b>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr><td><img height="15" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" background="images/bgt.gif" border="0">
				<tr valign="top">
					<td><img height="27" alt="" src="images/ctl.gif" width="27" border="0"></td><!--ecke, oben links-->
					<td background="images/hd_bg.gif" class="headline" nowrap>links<img height="15" alt="" src="images/hd_br.gif" width="30" border="0" align="absmiddle"></td><!--headline-->
					<td align="right" width="100%"><img height="27" alt="" src="images/ctr.gif" width="14" border="0"></td><!--abschluss, oben rechts-->
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" bgcolor="#ffffff" border="0">
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>package</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									<a href="http://localhost<?php echo $_SERVER['PHP_SELF'] ?>">generate new Package</a>
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>email</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									<a href="mailto:r.kummer@ipunkt.biz">Robert Kummer</a><br />
									<a href="mailto:b.gorke@ipunkt.biz">Bastian Gorke</a>
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr>
					<td background="images/bgb.gif"><img height="14" alt="" src="images/cbl.gif" width="27" border="0"></td>
					<td align="right" width="100%" background="images/bgb.gif"><img height="14" alt="" src="images/cbr.gif" width="14" border="0"></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
<?
}
else
//	FORM DATA NOT SENT YET	//
{

	$dirs = getDirs();
	$files = getFiles();
	?>
<form action="http://localhost<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr> 
		<td><img height="1" alt="" src="images/spacer.gif" width="12" border="0"></td>
		<td width="100%" class="content"><b onclick="javascript:location.href='<?php echo $_SERVER['PHP_SELF'] ?>'">Generate new Package</b>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr><td><img height="15" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" background="images/bgt.gif" border="0">
				<tr valign="top">
					<td><img height="27" alt="" src="images/ctl.gif" width="27" border="0"></td><!--ecke, oben links-->
					<td background="images/hd_bg.gif" class="headline" nowrap>Package betiteln<img height="15" alt="" src="images/hd_br.gif" width="30" border="0" align="absmiddle"></td><!--headline-->
					<td align="right" width="100%"><img height="27" alt="" src="images/ctr.gif" width="14" border="0"></td><!--abschluss, oben rechts-->
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" bgcolor="#ffffff" border="0">
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>Package Name</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									<a href="http://www.ipunkt.biz/" target="_new" title="www.ipunkt.biz - mit stil im internet präsent sein"><img src="http://www.ipunkt.biz/images/advertizer.gif" width="88" height="31" border="0" align="right" /></a>
									Indicate here please the name of the Packages to be generated.  
									<br /><img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br />
									<input type="text" name="pk_name" value="<?php echo $_POST['pk_name'] ?>" class="text" />
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr>
					<td background="images/bgb.gif"><img height="14" alt="" src="images/cbl.gif" width="27" border="0"></td>
					<td align="right" width="100%" background="images/bgb.gif"><img height="14" alt="" src="images/cbr.gif" width="14" border="0"></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr> 
		<td><img height="1" alt="" src="images/spacer.gif" width="12" border="0"></td>
		<td width="100%" class="content"><b>&nbsp;</b>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr><td><img height="15" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" background="images/bgt.gif" border="0">
				<tr valign="top">
					<td width="27"><img height="27" alt="" src="images/ctl.gif" width="27" border="0"></td><!--ecke, oben links-->
					<td background="images/hd_bg.gif" class="headline" nowrap>Select files<img height="15" alt="" src="images/hd_br.gif" width="30" border="0" align="absmiddle"></td><!--headline-->
					<td align="right" width="100%"><img height="27" alt="" src="images/ctr.gif" width="14" border="0"></td><!--abschluss, oben rechts-->
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" bgcolor="#ffffff" border="0">
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>Indices</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									Select here please the indices, that you want to receive completely in the Package, (inclusive of all lower indices).  
									<br /><img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br />
							<?
							if ( is_array($dirs) )
							{
								foreach ( $dirs as $dir )
								{
									?>
									<input type="checkbox" name="directories[]" value="<?php echo $dir ?>" class="check" />&nbsp;&nbsp;&nbsp;<?php echo $dir ?><br />
									<?
								}
							}
							else
							{
								?>
									No indices found.  
								<?
							}
							?>
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>Dateien</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									Select here please the files, that you want to receive in the Package.  
									<br /><img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br />
								<?
								foreach ( $files as $file )
								{
									?>
									<input type="checkbox" name="files[]" value="<?php echo $file ?>" class="check" />&nbsp;&nbsp;&nbsp;<?php echo $file ?><br />
									<?
								}
								?>
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr>
					<td background="images/bgb.gif"><img height="14" alt="" src="images/cbl.gif" width="27" border="0"></td>
					<td align="right" width="100%" background="images/bgb.gif"><img height="14" alt="" src="images/cbr.gif" width="14" border="0"></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr> 
		<td><img height="1" alt="" src="images/spacer.gif" width="12" border="0"></td>
		<td width="100%" class="content"><b>&nbsp;</b>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr><td><img height="15" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" background="images/bgt.gif" border="0">
				<tr valign="top">
					<td><img height="27" alt="" src="images/ctl.gif" width="27" border="0"></td><!--ecke, oben links-->
					<td background="images/hd_bg.gif" class="headline" nowrap>Determine option<img height="15" alt="" src="images/hd_br.gif" width="30" border="0" align="absmiddle"></td><!--headline-->
					<td align="right" width="100%"><img height="27" alt="" src="images/ctr.gif" width="14" border="0"></td><!--abschluss, oben rechts-->
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" bgcolor="#ffffff" border="0">
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>Option</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									Select here please the option, that you want to deliver to the Package.  These are considered in the installation.  
									<br /><img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br />
									<input type="checkbox" name="config[do][]" value="setup.php" class="check" />&nbsp;&nbsp;&nbsp;carry out setup.php after successful installation<br /><br />
									<input type="checkbox" name="config[cleanup][]" value="package" class="check" />&nbsp;&nbsp;&nbsp;.phi Delete Package after successful installation<br />
									<input type="checkbox" name="config[cleanup][]" value="installer" class="check" />&nbsp;&nbsp;&nbsp;Delete PHInstaller after successful installation<br />
									<img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br /><i>If you 'self-extracting package select generate' one the upper option ('.phi sufficed it delete' or 'PHInstaller delete') to activate in order to delete the Package.  </i><br /><img height="10" alt="" src="images/spacer.gif" width="1" border="0"><br />
									<input type="checkbox" name="config[phx]" value="1"  class="check"/>&nbsp;&nbsp;&nbsp;generate self-extracting package out of that. phi Package<br />
								<?
								if ( extension_loaded('zlib') )
								{
									?>
									<input type="checkbox" name="config[compress]" value="gzip" class="check" />&nbsp;&nbsp;&nbsp;Pack Package with gzip (zlib is prefaced)<br />
									<?
								}
								?>
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr>
					<td background="images/bgb.gif"><img height="14" alt="" src="images/cbl.gif" width="27" border="0"></td>
					<td align="right" width="100%" background="images/bgb.gif"><img height="14" alt="" src="images/cbr.gif" width="14" border="0"></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
	<tr> 
		<td><img height="1" alt="" src="images/spacer.gif" width="12" border="0"></td>
		<td width="100%" class="content"><b>&nbsp;</b>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr><td><img height="15" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" background="images/bgt.gif" border="0">
				<tr valign="top">
					<td><img height="27" alt="" src="images/ctl.gif" width="27" border="0"></td><!--ecke, oben links-->
					<td background="images/hd_bg.gif" class="headline" nowrap>Generate Package<img height="15" alt="" src="images/hd_br.gif" width="30" border="0" align="absmiddle"></td><!--headline-->
					<td align="right" width="100%"><img height="27" alt="" src="images/ctr.gif" width="14" border="0"></td><!--abschluss, oben rechts-->
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" bgcolor="#ffffff" border="0">
				<tr valign="top">
					<td background="images/bgl.gif"><img height="14" alt="" src="images/arrow.gif" width="34" border="0"></td><!--"anstrich"-punkt für die headline-->
<!--main content-->	<td class="content" width="100%"><b>Generate Package</b><br><img height="6" alt="" src="images/spacer.gif" width="1" border="0"><br>
						<table cellspacing="0" cellpadding="0" width="100%" border="0">
							<tr>
								<td class="content">
									<input type="submit" value="Generate Package" name="sent" />
								</td>
							</tr>
							<tr><td><img height="9" alt="" src="images/spacer.gif" width="1" border="0"></td></tr><!--space from bottom-->
						</table>
						<table cellspacing="0" cellpadding="0" border="0">
							<tr><td><img height="14" alt="" src="images/spacer.gif" width="1" border="0"></td></tr>
						</table>
					</td>
					<td background="images/bgr.gif"><img height="1" alt="" src="images/spacer.gif" width="14" border="0"></td>
				</tr>
			</table>
			<table cellspacing="0" cellpadding="0" width="100%" border="0">
				<tr>
					<td background="images/bgb.gif"><img height="14" alt="" src="images/cbl.gif" width="27" border="0"></td>
					<td align="right" width="100%" background="images/bgb.gif"><img height="14" alt="" src="images/cbr.gif" width="14" border="0"></td>
				</tr>
			</table>
		</td>
	</tr>
</table>
</form>
</body>
</html>
<?
}
?>