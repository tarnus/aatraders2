<?php
/*
	package::i.tools
	
	php-packages	v1.0	-	www.ipunkt.biz
	
	(c)	2002 - www.ipunkt.biz (rok)
*/

class package
{
	/**
	*	@var	array	$files	content of all the files in the package
	*/
	var $files = array();
	
	/**
	*	@var	string	$package_filename	filename of the resulting package
	*/
	var $package_filename = '';
	
	/**
	*	@var	array	$pi	package information
	*/
	var $pi = array();
	
	/**
	*	@var	int	$current_file	last-file-index, contains the current added file number
	*/
	var $current_file = 0;
	
	/**
	*	@var	string	$phinstaller	filename of the php_package_installer
	*/
	var $phinstaller = 'tiny_php_package_installer.php';
	
	/**
	*	constructor package()
	*
	*	this function sets the name of the package. the created package file has it´s
	*	name: {name].phi
	*	this function also sets the creation timestamp.
	*
	*	@access	public
	*	@param	string	$name	package name, if not specified the package is called 'php_package'
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function package($name='')
	{
		$this->files['package']['name'] = ($name == '') ? 'php_package' : $name;
		$this->package_filename = $this->files['package']['name'];
		$this->files['package']['creation'] = date('r');
		// pi
		$this->pi['name'] = $this->files['package']['name'];
		$this->pi['creation'] = $this->files['package']['creation'];
		return true;
	}
	
	/**
	*	function addDirectory()
	*
	*	this function adds the whole directory content to the package.
	*
	*	@access	public
	*	@param	string	$dir	directory name which should be included to the package
	*	@return	nothing
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function addDirectory($dir)
	{
		$dirs = $this->_dir_array($dir);
		foreach ( $dirs as $d )
		{
			$this->add($d['file'], $d['path']);
		}
	}
	
	/**
	*	function add()
	*
	*	this function adds only files. you can specify an directory, there the files
	*	stored.
	*
	*	@access	public
	*	@param	mixed	$files	filename(s), can be a string or an array
	*	@param	string	$path	path to the specified file(s)
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function add($files, $path = '')
	{
		if ( !is_array($files) )
			$files = array($files);
		
		foreach ( $files as $file)
		{
			$path_to_file = ($path == '') ? $file : $path.$file;
			
			$fp = fopen ($path_to_file, 'rb');
			if ($fp)
			{
				$this->files[$this->current_file]['file'] = $file;
				$this->files[$this->current_file]['path'] = $path;
				$this->files[$this->current_file]['string'] = fread($fp, filesize($path_to_file));
				$this->files[$this->current_file]['size'] = filesize($path_to_file);
				// pi
				$this->pi['files_size'] = $this->pi['files_size'] + $this->files[$this->current_file]['size'];
			}
			else
				return false;
			fclose ($fp);
			$this->current_file++;
		}
		// pi
		$this->pi['files'] = $this->current_file;
		return true;
	}
	
	/**
	*	function create()
	*
	*	this function starts the package write process.
	*
	*	@access	public
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*	@see	_write_package()
	*/
	function create()
	{
		if ( $this->_write_package( $result ) )
			return true;
		else
			return false;
	}
	
	/**
	*	function setConfig()
	*
	*	this function adds a configuration to the package file.
	*
	*	@access	public
	*	@param	array	$cfg	configuration array
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function setConfig($cfg)
	{
		if ( is_array($cfg) )
		{
			$this->files['package']['config'] = $cfg;
			return true;
		}
		else
			return false;
	}
	
	/**
	*	function getPackageFilename()
	*
	*	this function returns the filename of the created package.
	*
	*	@access	public
	*	@return	string
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function getPackageFilename()
	{
		return $this->package_filename;
	}
	
	/**
	*	function getPackageInformation()
	*
	*	this function returns additional information of the created package.
	*
	*	@access	public
	*	@return	array
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function getPackageInformation()
	{
		return $this->pi;
	}
	
	/**
	*	function _dir_array()
	*
	*	this function reads a directory recursively in an array.
	*
	*	@access	private
	*	@param	string	$directory	starting directory for recursive action
	*	@return	array
	*	@author	bg	<bg@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _dir_array($directory = "./")
	{
		$dir = @opendir($directory);
		$dir_tree = array();
		while (false !== ($file = @readdir($dir)))
		{
			if ($file != ".." && $file != ".")
			{
				if (is_dir($directory.$file))
				{
					foreach( $this->_dir_array($directory.$file."/") as $subdir)
					{
						$dir_tree[] = $subdir;
					}
				} else {
					$entry['path'] = $directory;
					$entry['file'] = $file;
					$dir_tree[] = $entry;
				}
			}
		}
		@closedir($dir);
		return $dir_tree;
	}	// thanx to bg@ipunkt.biz
	
	/**
	*	function _write_package()
	*
	*	this function writes the package file.
	*
	*	@access	private
	*	@return	boolean
	*	@author	rok	<rok@ipunkt.biz>
	*	@version	2002-08-08
	*/
	function _write_package()
	{
		// gzip compression
		if ( $this->files['package']['config']['compress'] && function_exists("gzcompress") && extension_loaded("zlib") )
		{
			for ($f=0; $f < $this->current_file; $f++)
			{
//				set_time_limit(5);
				$this->files[$f]['string'] = gzcompress($this->files[$f]['string'], 9);
			}
		}
		
		for ($f=0; $f < $this->current_file; $f++)
		{
			$this->files[$f]['string'] = base64_encode( $this->files[$f]['string'] );
		}
		
		// phx file creation
		if ( $this->files['package']['config']['phx'] && file_exists( $this->phinstaller ) )
		{
			$this->package_filename .= ".phx.php";
			$fp = fopen( $this->package_filename, 'w' );
			if ($fp)
			{
				fwrite($fp, '<? define("PHX_STREAM", \'');
				fwrite($fp, serialize($this->files));
				fwrite($fp, '\'); ?>');
				fwrite($fp, fread( fopen($this->phinstaller, 'r'), filesize($this->phinstaller) ) );
			}
			else
				return false;
			fclose($fp);
			// pi
			$this->pi['filename'] = $this->package_filename;
		}
		else
		{
			$this->package_filename .= ".phi";
			$fp = fopen( $this->package_filename, 'w' );
			if ($fp)
				fwrite($fp, serialize($this->files));
			else
				return false;
			fclose($fp);
			// pi
			$this->pi['filename'] = $this->package_filename;
		}
		return true;
	}
}
?>