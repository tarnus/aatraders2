<?php
// Step 10 - get password
?>
<br><font face="verdana" size="2">
Welcome to the Alien Assault Tradewars Game Installer!<br>
This program will create the initial local game configuration files.<br>
If a master password has not been created you will be asked to create one now.<br>
<br>
<hr>
<?php

echo "<hr><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\"><font color=\"#40E0D0\"><b>You need to have your database created, user name and password assigned before you go any further.<b></font><br><font color=\"pink\"><b>YOU MUST DO THIS RIGHT NOW BEFORE GOING ANY FURTHER!</b></font></font>";
echo"<br>";

echo"<hr><br>";

	$title = "Master Password"; // Enter master password
	$body = "Enter the Master Password to gain access to the installation program.";
	if(!isset($aatrade_master_password) || empty($aatrade_master_password))
	{
		echo "<table><tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Create a new Master Password: </font><br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">This is your master password for accessing the<br>installer and should be completely different<br>from the game passwords.</font></td><td valign=\"middle\" nowrap><input type=password name=new_master_password size=20 maxlength=20></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Game root</font><br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">This is the directory path on the server to the game.<br>Do not change this unless you know what you are doing.<br>This program will automatically determine the<br>appropriate path.</font></td><td valign=\"middle\" nowrap><input tabindex=9 type=text size=50 name=_gameroot value=\"$gameroot\"></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<input type=hidden name=step value=1>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Database type<br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">The game works with MySQL.</font></td>";
		echo "<td valign=\"middle\" nowrap><select tabindex=1 name=db_type>";
		foreach($dbs as $value => $name)
		{
			echo "<option value=$value " . ($v[1] == $value ? 'selected' : '') . ">$name</option>\n";
		}
		echo "</select></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Database name<br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">This is the name of your database.<br>You should have created the database before<br>executing the installer.php program. If you haven't<br>created the database you should do so now because<br>the installer will FAIL if the database<br>isn't created before proceeding.</font></font></td><td valign=\"middle\" nowrap><input tabindex=2 type=text name=dbname value=\"\"></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Database username</font><br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">This is the username for accessing the database.</font></td><td valign=\"middle\" nowrap><input tabindex=3 type=text name=dbuname value=\"\"></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Database password<br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">This is the password for the database.</font></font></td><td valign=\"middle\" nowrap><input tabindex=4 type=password name=dbpass value=\"\"></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Database host</font><br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">If the database is on the same server the game<br>is running use <b>localhost</b> else enter the IP<br>address for the database server.</font></td><td valign=\"middle\" nowrap><input tabindex=5 type=text name=dbhost value=\"localhost\"></td></tr>";
		echo "<tr><td nowrap>&nbsp;</td><td valign=\"middle\" nowrap>&nbsp;</td></tr>";
		echo "<tr><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Database port</font><br><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"1\">Leave this blank unless you know what you are doing.<br>Most Mysql databases do not need the port designated.</font></td><td valign=\"middle\" nowrap><input size=3 tabindex=6 type=text name=dbport value=\"\"></td></tr>";
		echo "</table>";
	}
	else
	{
		echo "<table><tr onMouseover=\"ddrivetip('$title', '$body');\" onMouseout=\"hideddrivetip()\"><td nowrap><font face=\"Verdana, Arial, Helvetica, sans-serif\" size=\"2\">Enter the Master Password: </font></td><td valign=\"middle\" nowrap><input type=password name=master_password size=20 maxlength=20></td></tr>";
		echo "</table>";
		echo "<input type=hidden name=step value=10>";
	}

echo "<input type=submit value=Continue><br><br>";
?>