<?php
session_start();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
 <head>
  <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=ISO-8859-1">
  <title>Test</title>
 </head>
<body>
Create the object and store data.<br><br>
 <?php

class test
{
	var $something;
	function mytest($data)
	{
		$this->something = $data;
	}
	function gettest()
	{
		return $this->something;
	}
}

$myobject = new test();
$myobject->mytest("This worked");

$_SESSION['myobject'] = $myobject;

echo "\$myobject->gettest() = " . $myobject->gettest();

?>
<br>
<a href="testfinish.php">Click Me</a>
</body>
</html>