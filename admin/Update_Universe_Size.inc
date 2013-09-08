<?php
// 8: Update Universe Size
// This tool will Re-Seed all port prices as if the universe was newly created.  no new ports will be added.  Use the Age Port Prices menu item if you wish port prices to reflect game time.
//TODO: set so the universe size is selectable and what galaxy you want to scale.
//TODO: Update create universe and expanding universe to use a new data item to determine galaxy size based on what galxy you are in.
//TODO: add options in creaate universe for the different galaxies also add to galaxies table


$universe_size=25000000;
$universe_size2=25000;
$galaxy_id=1;

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


$universe_query = $db->Execute("SELECT * from {$db_prefix}universe order by galaxy_id");
$db->debug=true;
db_op_result($universe_query,__LINE__,__FILE__);
while (!$universe_query->EOF) 
{
    $universe_info = $universe_query->fields;
    $galaxyid=$universe_info['galaxy_id'];
    //Revert back to original scale
    $scale = $universe_size / (4.0*pi());
    $universe_info['x'] /= $scale;
    $universe_info['y'] /= $scale;
    $universe_info['z'] /= $scale;
     print  $universe_info['x']. " ". $universe_info['y']." ". $universe_info['z']."<br>";
    // New Scale
    $universe_size2= $galaxy_array[$galaxyid]['universe_size']; 
    $scale2 = $universe_size2 / (4.0*pi());
    $universe_info['x'] *= $scale2;
    $universe_info['y'] *= $scale2;
    $universe_info['z'] *= $scale2;
    
 print  $galaxyid." ".$universe_info['x']. " ". $universe_info['y']." ". $universe_info['z']."<br>";
    // Update the dump of the sector here, remove the $i notes above.
    $res = $db->Execute("update {$db_prefix}universe set x='$universe_info[x]',  
    y='$universe_info[y]',
    z='$universe_info[z]'
    
    where sector_id='".$universe_info['sector_id']."' ");
    db_op_result($res,__LINE__,__FILE__);
    unset($sector);
$universe_query->Movenext();
}
$db->debug=false;
?>
