<?php
/*
	package::i.tools
	
	php-packages	v1.0	-	www.ipunkt.biz
	
	(c)	2002 - www.ipunkt.biz (rok)
*/

header ("Cache-Control: no-cache, must-revalidate");
header ("Pragma: no-cache");

class phi_package
{
	/*
	version	:	1.0	[2002-08-08]
	author	:	rok
	company	:	ipunkt
	url		:	http://www.ipunkt.biz
	email	:	rok@ipunkt.biz
	
	description
		the php_package_installer should install the pre-packed package
		and should run the setup.php if configured.
		this app is for these people, who would like to distribute their
		appz in order to make it easy for the customer to use it.
		
		the main idea was:
		.	upload (or copy) the phi-file and the installer
		.	start the installer and wait for the okay
		.	then setup starts automatically (if configured)
	
	future coming
		crypted files
		
	*/
	
	/*
	*	@var	array	$package_files	contains all package_files
	*/
	var $package_files;
	
	/*
	*	@var	array	$files	contains all the packaged files
	*/
	var $files;
	
	/*
	*	@var	boolean	$is_phx	is this package a self-extracting one
	*/
	var $is_phx = false;
	
	/**
	*	constructor phi_package()
	*
	*	this function reads in all founded .phi files or the one you gave him
	*
	*	@access	public
	*	@param	string	$file	.phi file, if not set the whole directory will be parsed for .phi files
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function phi_package($file = '')
	{
		if ( defined("PHX_STREAM") )
		{
			$this->is_phx = true;
		}
		
		if ( !$this->is_phx )
		{
			if ( $file == '')
				$this->package_files = $this->_getPHIPackages();
			else
			{
				if ( is_array($file) )
					$this->package_files = $file;
				else
					$this->package_files = array($file);
			}
			
			if ( empty($this->package_files) )
				die('no package files found');
		}
	}
	
	/**
	*	function extract()
	*
	*	this function starts the extraction process.
	*	it reads in the package and writes the packaged files.
	*
	*	@access	public
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function extract()
	{
		if ( !$this->is_phx )
		{
			foreach ( $this->package_files as $package_file )
			{
				$fp = fopen($package_file, 'rb');
				if ( $fp )
				{
					$package_string = fread($fp, filesize($package_file));
				}
				fclose($fp);
				
				$this->files[] = unserialize($package_string);
			}
		}
		else
		{
			$this->files[] = unserialize(PHX_STREAM);
		}
		
		if ( $this->_decodeFiles() )
			if ($this->writeFiles() )
			{
				$this->_do();
				$this->_cleanup();
				return true;
			}
			else return false;
		else
			return false;
	}
	
	/**
	*	function writeFiles()
	*
	*	this function writes all the files stored in the package.
	*
	*	@access	private
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function writeFiles()
	{
		$p = 0;
		foreach ( $this->files as $file )
		{
			for ($f=0; $f < $this->_getFileCountForPackage($p); $f++)
			{
				// directory check
				
				// if empty, write file to root
				if ( $file[$f]['path'] != '' )
				{
					$this->_mkdir($file[$f]['path']);
				}
				
				// file processing
				$path_to_file = ($file[$f]['path'] == '') ? $file[$f]['file'] : $file[$f]['path'].$file[$f]['file'];
				
				$fp = fopen($path_to_file, 'wb');
				if ( $fp )
					fwrite($fp, $file[$f]['string'], $file[$f]['size']);
				else
					return false;
				fclose($fp);
			}
			$p++;
		}
		
		return true;
	}
	
	/**
	*	function _mkdir()
	*
	*	this function makes all needed directories, recursively.
	*
	*	@access	private
	*	@param	string	$path	pathname
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _mkdir($path)
	{
		if ( !is_dir($path) )
		{
			if ( !is_dir(dirname($path)) )
				$this->_mkdir(dirname($path));
			mkdir( $path, 0755);
		}
	}
	
	/**
	*	function _getPHOPackages()
	*
	*	this function parses the whole directory for .phi files and returns the result as array.
	*
	*	@access	private
	*	@param	string	$ext	specified extension to look for
	*	@return	array
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _getPHIPackages($ext = ".phi")
	{
		$dir = @opendir( dirname(__FILE__) );
		$phi_files = array();
	 	while ( false !== ( $file = @readdir($dir) ) )
		{
			if ( strstr($file, $ext) )
				$phi_files[] = $file;
		}
		@closedir($dir);
		
		return $phi_files;
	}
	
	/**
	*	function _decode_Files()
	*
	*	this function decodes the base64_encoding for the file content of every file.
	*
	*	@access	private
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _decodeFiles()
	{
		for ($p=0; $p < count($this->files); $p++)
		{
			for ($f=0; $f < $this->_getFileCountForPackage($p); $f++)
			{
				$this->files[$p][$f]['string'] = base64_decode( $this->files[$p][$f]['string'] );
				// decompress, if set
				if ( $this->files[$p]['package']['config']['compress'] == 'gzip' )
				{
					if ( !function_exists("gzuncompress") || !extension_loaded('zlib') )
						die("FATAL ERROR: missing zlib");
//					set_time_limit(5);
					$this->files[$p][$f]['string'] = gzuncompress( $this->files[$p][$f]['string'] );
					if ( $this->files[$p][$f]['string'] === false )
						die("FATAL ERROR: could not uncompress");
				}
			}
		}
		return true;
	}
	
	/**
	*	function _getFileCountForPackage()
	*
	*	this function returns the number of files stored in the current package.
	*
	*	@access	private
	*	@param	int	$p	package number
	*	@return	int
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _getFileCountForPackage($p)
	{
		$keys = array_keys($this->files[$p]);
		foreach( $keys as $k => $v)
			if ( !is_numeric($v) )	unset($keys[$k]);
		return count($keys);
	}
	
	/**
	*	function _do()
	*
	*	this function starts other files like setup.php if configured in the package.
	*
	*	@access	private
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _do()
	{
		$do_files = '';
		for ($f=0; $f < count($this->files); $f++)
		{
			if ( is_array($this->files[$f]['package']['config']['do']) )
			{
				foreach ( $this->files[$f]['package']['config']['do'] as $file )
				{
					$do_files[] = $file;
				}
			}
		}
		
		if ( is_array($do_files) )
		{
			echo '<body onload="javascript:';
			$i = 0;
			foreach( $do_files as $do_file )
			{
				echo 'f'.$i.'=window.open(\''.$do_file.'\', \'f'.$i.'\', \'\'); ';
				$i++;
			}
			echo '">';
		}
		else
			echo '<body>';
	}
	
	/**
	*	function _cleanup()
	*
	*	this function cleans up after processing the package file.
	*
	*	@access	private
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _cleanup()
	{
		$do_cleanup = '';
		for ($f=0; $f < count($this->files); $f++)
		{
			if ( is_array($this->files[$f]['package']['config']['cleanup']) )
			{
				foreach ( $this->files[$f]['package']['config']['cleanup'] as $file )
				{
					if ( $file === 'package' )
						$do_cleanup[] = ( $this->is_phx ) ? __FILE__ : $this->package_files[$f];
					elseif ( $file === 'installer' )
						$do_cleanup[] = __FILE__;
					else
						$do_cleanup[] = $file;
				}
			}
		}
		
		if ( is_array($do_cleanup) )
		{
			foreach( $do_cleanup as $do_file )
			{
				unlink($do_file);
			}
		}
	}
}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
<head>
	<title>php-package-installer v1.0</title>
</head>
<?
$phi = new phi_package();
if ( $phi->extract() )
	echo "well done";
else
	echo "error occured";
?>
</body>
</html>