<?php
/*
	package::i.tools
	tiny installer
	
	php-packages	v1.0	-	www.ipunkt.biz
	
	(c)	2002 - www.ipunkt.biz (rok)
*/
header ("Cache-Control: no-cache, must-revalidate");
header ("Pragma: no-cache");
class phi_package
{
	var $package_files;
	var $files;
	var $is_phx = false;
	function phi_package($file = '')	{
		if ( defined("PHX_STREAM") )	$this->is_phx = true;
		if ( !$this->is_phx )	{
			if ( $file == '')	$this->package_files = $this->_getPHIPackages();
			else	{
				if ( is_array($file) )	$this->package_files = $file;
				else	$this->package_files = array($file);
			}
			if ( empty($this->package_files) )	die('no package files found');
		}
	}
	function extract()	{
		if ( !$this->is_phx )	{
			foreach ( $this->package_files as $package_file )	{
				$fp = fopen($package_file, 'rb');
				if ( $fp )	$package_string = fread($fp, filesize($package_file));
				fclose($fp);
				$this->files[] = unserialize($package_string);
			}
		}	else	{
			$this->files[] = unserialize(PHX_STREAM);
		}
		if ( $this->_decodeFiles() )
			if ($this->writeFiles() )	{
				$this->_do();
				$this->_cleanup();
				return true;
			}
			else return false;
		else
			return false;
	}
	function writeFiles()	{
		$p = 0;
		foreach ( $this->files as $file )	{
			for ($f=0; $f < $this->_getFileCountForPackage($p); $f++)	{
				if ( $file[$f]['path'] != '' )	$this->_mkdir($file[$f]['path']);
				$path_to_file = ($file[$f]['path'] == '') ? $file[$f]['file'] : $file[$f]['path'].$file[$f]['file'];
				$fp = fopen($path_to_file, 'wb');
				if ( $fp )	fwrite($fp, $file[$f]['string'], $file[$f]['size']);
				else	return false;
				fclose($fp);
			}
			$p++;
		}
		return true;
	}
	function _mkdir($path)	{
		if ( !is_dir($path) )	{
			if ( !is_dir(dirname($path)) )	$this->_mkdir(dirname($path));
			mkdir( $path, 0755);
		}
	}
	function _getPHIPackages($ext = ".phi")	{
		$dir = @opendir( dirname(__FILE__) );
		$phi_files = array();
	 	while ( false !== ( $file = @readdir($dir) ) )	{
			if ( strstr($file, $ext) )	$phi_files[] = $file;
		}
		@closedir($dir);
		return $phi_files;
	}
	function _decodeFiles()	{
		for ($p=0; $p < count($this->files); $p++)	{
			for ($f=0; $f < $this->_getFileCountForPackage($p); $f++)	{
				$this->files[$p][$f]['string'] = base64_decode( $this->files[$p][$f]['string'] );
				if ( $this->files[$p]['package']['config']['compress'] == 'gzip' )	{
					if ( !function_exists("gzuncompress") || !extension_loaded('zlib') )	die("FATAL ERROR: missing zlib");
//					set_time_limit(5);
					$this->files[$p][$f]['string'] = gzuncompress( $this->files[$p][$f]['string'] );
					if ( $this->files[$p][$f]['string'] === false )	die("FATAL ERROR: could not uncompress");
				}
			}
		}
		return true;
	}
	function _getFileCountForPackage($p)	{
		$keys = array_keys($this->files[$p]);
		foreach( $keys as $k => $v)
			if ( !is_numeric($v) )	unset($keys[$k]);
		return count($keys);
	}
	function _do()	{
		$do_files = '';
		for ($f=0; $f < count($this->files); $f++)	{
			if ( is_array($this->files[$f]['package']['config']['do']) )	{
				foreach ( $this->files[$f]['package']['config']['do'] as $file )	{
					$do_files[] = $file;
				}
			}
		}
		if ( is_array($do_files) )	{
			echo '<body onload="javascript:';
			$i = 0;
			foreach( $do_files as $do_file )	{
				echo 'f'.$i.'=window.open(\''.$do_file.'\', \'f'.$i.'\', \'\'); ';
				$i++;
			}
			echo '">';
		}	else
			echo '<body>';
	}
	function _cleanup()	{
		$do_cleanup = '';
		for ($f=0; $f < count($this->files); $f++)	{
			if ( is_array($this->files[$f]['package']['config']['cleanup']) )	{
				foreach ( $this->files[$f]['package']['config']['cleanup'] as $file )	{
					if ( $file === 'package' )	$do_cleanup[] = ( $this->is_phx ) ? __FILE__ : $this->package_files[$f];
					elseif ( $file === 'installer' )	$do_cleanup[] = __FILE__;
					else	$do_cleanup[] = $file;
				}
			}
		}
		if ( is_array($do_cleanup) )	{
			foreach( $do_cleanup as $do_file )	{
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
if ( $phi->extract() )	echo "well done";
else	echo "error occured";
?>
</body>
</html>