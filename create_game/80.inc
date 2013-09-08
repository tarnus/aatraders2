<?php
// Step 80 - Create default zones and all Universe Sectors

include ("globals/create_sector_coordinates.inc");
include ("globals/create_sector_number.inc");

function check_php_version () {
	$testSplit = explode ('.', '4.3.0');
	$currentSplit = explode ('.', phpversion());

	if ($testSplit[0] < $currentSplit[0])
		return True;
	if ($testSplit[0] == $currentSplit[0]) {
		if ($testSplit[1] < $currentSplit[1])
			return True;
		if ($testSplit[1] == $currentSplit[1]) {
			if ($testSplit[2] <= $currentSplit[2])
				return True;
		}
	}
	return False;
}

$collisions = 0;
# calculate the scale to use such that 
# the max distance between 2 points will be
# approx $universe_size.
$scale = $universe_size / (4.0*pi());

# compute the angle between arms
$angle = deg2rad(360/$spiral_galaxy_arms);

// Build the zones table. Only four zones here. The rest are named after players for
// when they manage to dominate a sector.
TextFlush("Building zone descriptions:\n<br>");

TextFlush("Setting zone 1: Unchartered space ");
$debug_query = $db->Execute("INSERT INTO {$db_prefix}zones (zone_id, zone_name, owner, allow_beacon, team_zone, allow_attack, allow_planetattack, allow_warpedit, allow_planet, allow_trade, allow_defenses, max_hull, zone_color) VALUES ('1', 'Unchartered space', '0', 'Y', 'N', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', '0', '#000000') ");
db_op_result($debug_query,__LINE__,__FILE__);

TextFlush("\nSetting zone 2: Federation alliance space ");
$debug_query = $db->Execute("INSERT INTO {$db_prefix}zones (zone_id, zone_name, owner, allow_beacon, team_zone, allow_attack, allow_planetattack, allow_warpedit, allow_planet, allow_trade, allow_defenses, max_hull, zone_color) VALUES ('2', 'Federation space', '3', 'N', 'N', 'N', 'N', 'N', 'N', 'Y', 'N', '$fed_max_avg_tech', '#00ff00') ");
db_op_result($debug_query,__LINE__,__FILE__);

TextFlush("\nSetting zone 3: Alliance alliance space");
$debug_query = $db->Execute("INSERT INTO {$db_prefix}zones (zone_id, zone_name, owner, allow_beacon, team_zone, allow_attack, allow_planetattack, allow_warpedit, allow_planet, allow_trade, allow_defenses, max_hull, zone_color) VALUES ('3', 'Alliance space', '1', 'N', 'N', 'Y', 'N', 'N', 'N', 'Y', 'N', '0', '#ffff00') ");
db_op_result($debug_query,__LINE__,__FILE__);

TextFlush("\nSetting zone 4: War Zone space");
$debug_query = $db->Execute("INSERT INTO {$db_prefix}zones (zone_id, zone_name, owner, allow_beacon, team_zone, allow_attack, allow_planetattack, allow_warpedit, allow_planet, allow_trade, allow_defenses, max_hull, zone_color) VALUES ('4', 'War Zone', '0', 'N', 'N', 'Y', 'Y', 'Y', 'Y', 'N', 'Y', '0', '#ff0000') ");
db_op_result($debug_query,__LINE__,__FILE__);
TextFlush("");

//Get universe size based on galaxy
// update galaxy universe size
$debug_query = $db->Execute("SELECT * from  {$db_prefix}universe_galaxy  order by galaxy_id" );
    db_op_result($debug_query,__LINE__,__FILE__);
   $galaxy_array=array();
    while (!$debug_query->EOF) 
    {
        $gid=$debug_query->fields['galaxy_id'];
        $galaxy_array[$gid]['universe_size']=$debug_query->fields['universe_size'];
       
    db_op_result($debug_query1,__LINE__,__FILE__);
            
        $debug_query->Movenext();
    }

$scale = $galaxy_array[1]['universe_size'] / (4.0*pi());
// Build Sector 1, Sol
$universe_size= $galaxy_array[1]['universe_size'];
$stamp = date("Y-m-d H:i:s");
TextFlush("\n<br>Creating Sector 1: Sol ");
$sector = array();
create_sector_coordinates();
$res = $db->Execute("INSERT INTO {$db_prefix}universe (sector_id, sector_name, zone_id, star_size, port_type, beacon, x, y, z, creation_date) VALUES ('1', 'Sol', '2', '1', 'upgrades', 'Hub of the Universe', '$sector[x]', '$sector[y]', '$sector[z]', '$stamp') ");
db_op_result($res,__LINE__,__FILE__);

// Build Sector 2, Proxima Centauri
TextFlush("\nCreating Sector 2: Proxima Centauri ");
$sector = array();
create_sector_coordinates();
$res = $db->Execute("INSERT INTO {$db_prefix}universe (sector_id, sector_name, zone_id, star_size, port_type, beacon, x, y, z, creation_date) VALUES ('2', 'Proxima Centari', '2', '0', 'devices', 'Gateway to the Galaxy', '$sector[x]', '$sector[y]', '$sector[z]', '$stamp') ");
db_op_result($res,__LINE__,__FILE__);

// Build Sector 3, Wolf-359
TextFlush("\nCreating Sector 3: Wolf-359 ");
$sector = array();
create_sector_coordinates();
$res = $db->Execute("INSERT INTO {$db_prefix}universe (sector_id, sector_name, zone_id, star_size, port_type, beacon, x, y, z, creation_date) VALUES ('3', 'Wolf-359', '2', '0', 'energy', 'A thriving hub of interstellar commerce', '$sector[x]', '$sector[y]', '$sector[z]', '$stamp') ");
db_op_result($res,__LINE__,__FILE__);
$silent = 1;

$cargototal = 0;
$cargo_query = $db->Execute("SELECT * from {$db_prefix}class_modules_commodities where cargoport=1 and defaultcargoplanet=1");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	$cargo_info = $cargo_query->fields;
	$newcargotype[$cargototal] = AAT_strtolower($cargo_info['classname']);
	if($cargo_info['classname'] == "energy")
		$energy_id = $cargototal;
	if($cargo_info['classname'] == "colonists")
		$colonist_id = $cargototal;
	$limit[$cargototal] = $cargo_info['itemlimit'];
	$initialamount[$cargototal] = $cargo_info['itemlimit'] * $_POST['initscommod'] / 100.0;
	$fixed_start_price[$cargototal] = $cargo_info['fixed_start_price'];
	$increaserate[$cargototal] = $cargo_info['increaserate'];
	$goodevil[$cargototal] = $cargo_info['goodevil'];
	$cargototal++;
	$cargo_query->Movenext();
}
$cargo_query->close();

$prices = (mt_rand(500, $fixed_start_price[$energy_id] * 1000) / 1000) * 2;
if($increaserate[$i] == 0)
{
	$prices = $fixed_start_price[$energy_id];
}

$maxcommodities = $max_port_buy_commodities;
$insertlist = "";
for($ii = 0; $ii < $cargototal; $ii++)
{
	if($newcargotype[$ii] != "colonists" && $newcargotype[$ii] != "energy")
	{
		$startprices = (mt_rand(500, $fixed_start_price[$ii] * 1000) / 1000) * 2;
		$startprices += $fixed_start_price[$ii] * $ratio;
		if($increaserate[$ii] == 0)
		{
			$startprices = $fixed_start_price[$ii] / 2;
		}
		$insertlist .= ", (3, '" . $newcargotype[$ii] . "', $limit[$ii], " . $startprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$ii])";
		$maxcommodities--;
	}
}
$debug_query = $db->Execute("INSERT INTO {$db_prefix}universe_ports 
			(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
				VALUES 
				('3', '" . $newcargotype[$energy_id] . "', '$limit[$energy_id]', '$prices', '" . date("Y-m-d H:i:s") . "', '$goodevil[$energy_id]') 
				$insertlist");
db_op_result($debug_query,__LINE__,__FILE__);
$silent = 0;

// Build Sector 4, Andromeda Base
TextFlush("\nCreating Sector 4: Andromeda Base ");
$sector = array();
create_sector_coordinates();
$res = $db->Execute("INSERT INTO {$db_prefix}universe (sector_id, sector_name, zone_id, star_size, port_type, beacon, x, y, z, creation_date) VALUES ('4', 'Andromeda Base', '2', '0', 'spacedock', 'Federation Starship Repair Base', '$sector[x]', '$sector[y]', '$sector[z]', '$stamp') ");
db_op_result($res,__LINE__,__FILE__);

// Build Sector 5, Outbound Colony Depot
TextFlush("\nCreating Sector 5: Outbound Colony Depot");
$sector = array();
create_sector_coordinates();
$res = $db->Execute("INSERT INTO {$db_prefix}universe (sector_id, sector_name, zone_id, star_size, port_type, beacon, x, y, z, creation_date) VALUES ('5', 'Outbound Colony Depot', '2', '0', 'colonists', 'Federation Colonist Processing Center', '$sector[x]', '$sector[y]', '$sector[z]', '$stamp') ");
db_op_result($res,__LINE__,__FILE__);

$maxcommodities = $max_port_buy_commodities;
$prices = (mt_rand(500, $fixed_start_price[$colonist_id] * 1000) / 1000) * 2;
if($increaserate[$i] == 0)
{
	$prices = $fixed_start_price[$colonist_id];
}

$insertlist = "";
for($ii = 0; $ii < $cargototal; $ii++)
{
	if($newcargotype[$ii] != "colonists" && $newcargotype[$ii] != "energy")
	{
		$startprices = (mt_rand(500, $fixed_start_price[$ii] * 1000) / 1000) * 2;
		$startprices += $fixed_start_price[$ii] * $ratio;
		if($increaserate[$ii] == 0)
		{
			$startprices = $fixed_start_price[$ii] / 2;
		}
		$insertlist .= ", (5, '" . $newcargotype[$ii] . "', $limit[$ii], " . $startprices . ", '" . date("Y-m-d H:i:s") . "', $goodevil[$ii])";
		$maxcommodities--;
	}
}
$silent = 1;

$debug_query = $db->Execute("INSERT INTO {$db_prefix}universe_ports 
			(sector_id, commodity_type, commodity_amount, commodity_price, trade_date, goodevil) 
				VALUES 
				('5', '" . $newcargotype[$colonist_id] . "', '$limit[$colonist_id]', '$prices', '" . date("Y-m-d H:i:s") . "', '$goodevil[$colonist_id]') 
				$insertlist");
db_op_result($debug_query,__LINE__,__FILE__);

// Here's where the remaining sectors get built

TextFlush("<br>Creating remaining ".($_POST['sektors']-5)." sectors <br>\n");

TextFlush("<br>Creating sectors 6 to 499<br>\n");

$galaxybreaknumber = round($_POST['sektors'] / $galaxy);
$galaxynumber = 1;

for ($i=6; $i<=$_POST['sektors']; $i++) 
{
	if(!($i % 500)){
		if($i + 499 > $_POST['sektors'])
			$end = $_POST['sektors'] - $i;
		else
			$end = 499;
		TextFlush("Creating sectors $i to " . ($i + $end) . "<br>\n");
	}

    
    if($i == $galaxybreaknumber)
    {
        $galaxynumber++;
        $galaxybreaknumber += round($_POST['sektors'] / $galaxy);
    }
    $galaxynumber = min($galaxynumber, $galaxy);
    $scale = $galaxy_array[$galaxynumber]['universe_size'] / (4.0*pi());
    $universe_size= $galaxy_array[$galaxynumber]['universe_size'];
	$sector = array();

	create_sector_coordinates();

	$index[$sector['x'].','.$sector['y'].','.$sector['z']] = 1;

	// The Federation owns the first series of sectors. Logical because they
	// probably numbered them as they were found.
	if ($i<$_POST['fedsecs']) 
	{
		$zone_id = '2'; // Federation space
	} 
	else 
	{
		$zone_id = '1'; // Uncharted
	}

	if($max_sector_size > 5)
		$max_sector_size = 5;



	$star_size = mt_rand(0, $max_sector_size);
	$sectorname = create_sector_number((string)$galaxynumber + chr(80 + $sector['spiral_arm']) . (string)$star_size);
	// Insert the dump of the sector here, remove the $i notes above.
	$res = $db->Execute("INSERT INTO {$db_prefix}universe (sector_id, sector_name, zone_id, star_size, x, y, z, spiral_arm, galaxy_id, creation_date) VALUES ('$i', '$sectorname', '$zone_id', '" . $star_size . "', '$sector[x]', '$sector[y]', '$sector[z]', '$sector[spiral_arm]', '$galaxynumber', '$stamp') ");
	db_op_result($res,__LINE__,__FILE__);
	unset($sector);
}

if ($collisions) 
{
	echo("<font color=\"yellow\">- $collisions sector collisions repaired</font> ");
} 
else 
{
	echo("- no sector collisions detected ");
}

TextFlush("<font color=\"lime\">- operation completed successfully.</font><br>");

// Make all federation sectors real close to each other
$res = $db->Execute("UPDATE {$db_prefix}universe SET x=x*0.06, y=y*0.06, z=z*0.06 WHERE zone_id=2 and galaxy_id=1");
db_op_result($res,__LINE__,__FILE__);

$cargo_query = $db->Execute("SELECT classname from {$db_prefix}class_modules_commodities where cargoport=1 order by defaultcargoplanet DESC");
db_op_result($cargo_query,__LINE__,__FILE__);
while (!$cargo_query->EOF) 
{
	echo "<input type=hidden name=$porttypes value=" . $_POST[$porttypes] . ">\n";
	$cargo_query->Movenext();
}
$cargo_query->close();

TextFlush("<br>Creating Wormhole Links Between Galaxies.<br>\n");

$debug_query = $db->Execute("SELECT sector_id, galaxy_id from {$db_prefix}universe");
db_op_result($debug_query,__LINE__,__FILE__);
while (!$debug_query->EOF) 
{
	$galaxynoportlist_galaxy = $debug_query->fields['galaxy_id'];
	$galaxynoportlist_sec = $debug_query->fields['sector_id'];
	$galaxynoportlist_sector[$galaxynoportlist_galaxy][$galaxynoportlist_sec] = $debug_query->fields['sector_id'];
	$debug_query->Movenext();
}

if($galaxy != 1)
{
	for($i = 1; $i <= $galaxy; $i++)
	{
		for($ig = 1; $ig <= $_POST['galaxylinks']; $ig++)
		{
			for($ii = $i; $ii <= $galaxy; $ii++)
			{
				if($i != $ii)
				{
					$start = array_rand($galaxynoportlist_sector[$i]);
					$destination = array_rand($galaxynoportlist_sector[$ii]);
					echo"Creating Wormhole from galaxy $i to galaxy $ii<br>";
					$debug_query = $db->Execute("UPDATE {$db_prefix}universe SET port_type='wormhole', zone_id='3', star_size='0', wormhole_destination='" . $galaxynoportlist_sector[$ii][$destination] . "' WHERE sector_id='" . $galaxynoportlist_sector[$i][$start] . "'");
					db_op_result($debug_query,__LINE__,__FILE__);
					$debug_query = $db->Execute("UPDATE {$db_prefix}universe SET port_type='wormhole', zone_id='3', star_size='0', wormhole_destination='" . $galaxynoportlist_sector[$i][$start] . "' WHERE sector_id='" . $galaxynoportlist_sector[$ii][$destination] . "'");
					db_op_result($debug_query,__LINE__,__FILE__);
					unset($galaxynoportlist_sector[$i][$start]);
				}
			}
		}
	}
}

$silent = 0;
db_op_result($debug_query,__LINE__,__FILE__);

echo "<input type=hidden name=step value=80>";
?>