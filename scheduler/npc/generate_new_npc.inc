<?php

include ("globals/newplayer.inc");
include ("globals/ord_crypt_encode.inc");

if (!function_exists('generate_new_npc')) {

    function generate_new_npc()
    {
        global $db, $db_prefix;
$db->debug=true;
        $res = $db->Execute("SELECT {$db_prefix}ships.class as ship_class, count( {$db_prefix}ships.ship_id ) AS total, 
                            min( {$db_prefix}ships.hull ) as min_hull , min( {$db_prefix}ships.engines ) as min_engines , 
                            min( {$db_prefix}ships.power ) as min_power , min( {$db_prefix}ships.fighter ) as min_fighter , 
                            min( {$db_prefix}ships.sensors ) as min_sensors , min( {$db_prefix}ships.beams ) as min_beams , 
                            min( {$db_prefix}ships.torp_launchers ) as min_torp_launchers , min( {$db_prefix}ships.shields ) as min_shields , 
                            min( {$db_prefix}ships.cloak ) as min_cloak , min( {$db_prefix}ships.armor ) as min_armor , 
                            min( {$db_prefix}ships.ecm ) as min_ecm , max( {$db_prefix}ships.hull ) as max_hull , 
                            max( {$db_prefix}ships.engines ) as max_engines , max( {$db_prefix}ships.power ) as max_power , 
                            max( {$db_prefix}ships.fighter ) as max_fighter , max( {$db_prefix}ships.sensors ) as max_sensors , 
                            max( {$db_prefix}ships.beams ) as max_beams , max( {$db_prefix}ships.torp_launchers ) as max_torp_launchers , 
                            max( {$db_prefix}ships.shields ) as max_shields , max( {$db_prefix}ships.cloak ) as max_cloak , 
                            max( {$db_prefix}ships.armor ) as max_armor , max( {$db_prefix}ships.ecm ) as max_ecm 
                            FROM {$db_prefix}ships, {$db_prefix}players
                            WHERE {$db_prefix}players.admin =0
                            AND {$db_prefix}players.npc =0
                             AND {$db_prefix}players.player_id > 3
                            AND {$db_prefix}ships.ship_id = {$db_prefix}players.currentship
                            AND {$db_prefix}ships.class > 10
                            GROUP BY {$db_prefix}ships.class
                            ORDER BY {$db_prefix}ships.class DESC
                            ");
        db_op_result($res,__LINE__,__FILE__);

        $shipclassarray=array();
        $shipclassflag=0;
        while(!$res->EOF)
        {
            $shipclassflag=1;
            $shipclassarray[] = $res->fields['ship_class'];
            $res->MoveNext();
        }
        if ($shipclassflag==1){
        $shipclassmin=$shipclassarray[count($shipclassarray)-1];
        $shipclassmax=$shipclassarray[0];
    }else{
        $shipclassmin=10;
        $shipclassmax=10;
        $shipinfotype['minhull']=150;
        $shipinfotype['maxhull']=150;
        
        $shipinfotype['minengines']=150;
        $shipinfotype['maxengines']=150;
        
        $shipinfotype['minpower']=150;
        $shipinfotype['maxpower']=150;
        
        $shipinfotype['minfighter']=150;
        $shipinfotype['maxfighter']=150;
        
        $shipinfotype['minsensors']=150;
        $shipinfotype['maxhull']=150;
        
        $shipinfotype['minbeams']=150;
        $shipinfotype['maxbeams']=150;
        
        $shipinfotype['mintorp_launchers']=150;
        $shipinfotype['maxtorp_launchers']=150;
        
        $shipinfotype['minshields']=150;
        $shipinfotype['maxshields']=150;
        
        $shipinfotype['mincloak']=150;
        $shipinfotype['maxcloak']=150;
        
        $shipinfotype['minarmor']=150;
        $shipinfotype['minarmor']=150;
        
        $shipinfotype['min_ecm']=150;
        $shipinfotype['maxecm']=150;
        
        $shipinfotype['minarmor']=150;
        $shipinfotype['maxarmor']=150;
        
        $shipinfotype['minarmor']=150;
        $shipinfotype['minarmor']=150;
        
    }
        $res->close();

        $res = $db->SelectLimit("SELECT * FROM {$db_prefix}ship_types WHERE 
        type_id >= $shipclassmin and type_id <= $shipclassmax order by RAND()", 1);
        db_op_result($res,__LINE__,__FILE__);
        $shipinfotype = $res->fields;

        $shipinfo = array();
        $shipinfo['class'] = $shipinfotype['type_id'];
        $ship_level=mt_rand($shipinfotype['minbeams'], $shipinfotype['maxbeams']);
        
        /*$shipinfo['hull'] = mt_rand($shipinfotype['minhull'], $shipinfotype['maxhull']);
        $shipinfo['engines'] = mt_rand($shipinfotype['minengines'], $shipinfotype['maxengines']);
        $shipinfo['power'] = mt_rand($shipinfotype['minpower'], $shipinfotype['maxpower']);
        $shipinfo['fighter'] = mt_rand($shipinfotype['minfighter'], $shipinfotype['maxfighter']);
        $shipinfo['sensors'] = mt_rand($shipinfotype['minsensors'], $shipinfotype['minsensors']);
        $shipinfo['beams'] = mt_rand($shipinfotype['minbeams'], $shipinfotype['maxbeams']);
        $shipinfo['torp_launchers'] = mt_rand($shipinfotype['mintorp_launchers'], $shipinfotype['maxtorp_launchers']);
        $shipinfo['shields'] = mt_rand($shipinfotype['minshields'], $shipinfotype['maxshields']);
        $shipinfo['cloak'] = mt_rand($shipinfotype['mincloak'], $shipinfotype['maxcloak']);
        $shipinfo['armor'] = mt_rand($shipinfotype['minarmor'], $shipinfotype['maxarmor']);
        $shipinfo['ecm'] = mt_rand($shipinfotype['min_ecm'], $shipinfotype['maxecm']);
        */
          
        $shipinfo['hull'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxhull']);
        $shipinfo['engines'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxengines']);
        $shipinfo['power'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxpower']);
        $shipinfo['fighter'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxfighter']);
        $shipinfo['sensors'] = min($ship_level+mt_rand(0,10), $shipinfotype['minsensors']);
        $shipinfo['beams'] = min($shipinfo['power']+mt_rand(10,35), $shipinfotype['maxbeams']);
        $shipinfo['torp_launchers'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxtorp_launchers']);
        $shipinfo['shields'] = min($shipinfo['power']+mt_rand(10,35), $shipinfotype['maxshields']);
        $shipinfo['cloak'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxcloak']);
        $shipinfo['armor'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxarmor']);
        $shipinfo['ecm'] = min($ship_level+mt_rand(0,10), $shipinfotype['maxecm']);
        
        
        $Sylable1 = array("Alliance-");
        $Sylable2 = array("Ak","Al","Ar","B","Br","D","F","Fr","G","Gr","H","J","N","Ol","Om","P","Qu","R","S","T","Z");
        $Sylable3 = array("a","ar","aka","aza","e","el","i","in","int","ili","ish","ido","ir","o","oi","or","os","ov","otre","u","un");
        $Sylable4 = array("ag","al","ak","ba","dar","g","ga","k","ka","kar","kil","l","n","ns","ol","r","s","st","ta","ti","x");
        $Sylable5 = array("an","yen","avi","aka","ens","elf","si","pin","rint","eli","ash","ids","sir","os","soi","por","ost","rov","more","urn","onk");

        $ShipNames = array("Steamrunner", "Battle Buster", "Death Glider", "Starship", "Defiance", "Deathmaster", 
        "Armageddon", "Copernicus", "Crazy Horse", "Daedalus", "Armageddon", "Equinox", "Fearless", "Nebula", "Intrepid", 
        "Warship", "Odyssey", "Pegasus", "Prometheus", "Brave Star", "Pueblo", "Renegade", "Breath of Death", "Stargazer", 
        "Amazonian", "Destructor", "Andromeda", "Devastator",  "Event Horizon", "Storm Force", "Reaper", "Mort", 
        "Repulsifier", "Eradicator", "Annihilator", "Tattoo", "Anthrax", "Scylla", "Alacrity", "Red Alert", "Dog Star", 
        "Invincible", "Predator", "Bird of Prey", "Slip Stream", "Devils Horn", "Crusader", "Fall of Time", "Shadow", 
        "Ulysses", "Punisher", "Iron Maiden", "Thors Hammer", "Thors Chariot", "Solar Storm", "Raptor", "Speed Demon", 
        "Cubix", "Talisman", "Sonic Boom", "Vampyrrhic", "Zed Bed", "Evolution", "Sensai", "Nostradamus", "Harvester", 
        "Sol Slip", "Comet", "Aurora", "Oddysee", "Hive", "Adversary", "Zeppellin", "Zephyr");

        $sy1roll = (0);
        $sy2roll = mt_rand(0,20);
        $sy3roll = mt_rand(0,20);
        $sy4roll = mt_rand(0,20);
        $sy5roll = mt_rand(0,20);
        $character = $Sylable1[$sy1roll] . $Sylable2[$sy2roll] . $Sylable3[$sy3roll] . $Sylable4[$sy4roll] . $Sylable5[$sy5roll];
        $resultnm = $db->Execute ("select character_name from {$db_prefix}players where character_name='$character'");
        db_op_result($resultnm,__LINE__,__FILE__);
        $namecount = $resultnm->RecordCount();
        $resultnm->close();
        $nametry = 1;

        while ($namecount != 0 && ($nametry <= 9))
        {
            $sy1roll = (0);
            $sy2roll = mt_rand(0,20);
            $sy3roll = mt_rand(0,20);
            $sy4roll = mt_rand(0,20);
            $sy5roll = mt_rand(0,20);
            $character = $Sylable1[$sy1roll] . $Sylable2[$sy2roll] . $Sylable3[$sy3roll] . $Sylable4[$sy4roll] . $Sylable5[$sy5roll];
            $resultnm = $db->Execute ("select character_name from {$db_prefix}players where character_name='$character'");
            db_op_result($resultnm,__LINE__,__FILE__);
            $namecount = $resultnm->RecordCount();
            $resultnm->close();
            $nametry++;
        }
        if($namecount != 0)
        {
            return 1;
        }

        $shipname = $ShipNames[mt_rand(0,count($ShipNames)-1)];       
        $resultnm = $db->Execute ("select name from {$db_prefix}ships where name='$shipname'");
        db_op_result($resultnm,__LINE__,__FILE__);
        $namecount = $resultnm->RecordCount();
        $resultnm->close();
        $nametry = 1;

        while ($namecount != 0 && ($nametry <= 9))
        {
            $shipname = $ShipNames[mt_rand(0,count($ShipNames)-1)];       
            $resultnm = $db->Execute ("select name from {$db_prefix}ships where name='$shipname'");
            db_op_result($resultnm,__LINE__,__FILE__);
            $namecount = $resultnm->RecordCount();
            $resultnm->close();
            $nametry++;
        }
        if($namecount != 0)
        {
            return1;
        }

        if($galaxy == 1)
        {
            $findem = $db->SelectLimit("SELECT sector_id, galaxy_id FROM {$db_prefix}universe where sg_sector = 0 and sector_id > 3 ORDER BY rand()", 1);
            db_op_result($findem,__LINE__,__FILE__);
        }
        else
        {
            $findem = $db->SelectLimit("SELECT sector_id, galaxy_id FROM {$db_prefix}universe where sg_sector = 0 and galaxy_id > 1 ORDER BY rand()", 1);
            db_op_result($findem,__LINE__,__FILE__);
        }
        $sector = $findem->fields['sector_id'];
        $galaxy_id = $findem->fields['galaxy_id'];

        $orders = mt_rand(0,3); // 0 = Sentinel, 1 = Explorer, 2 = Trader, 3 = Hunter

        $aggression = mt_rand(1,100);
        if ($aggression <= $fur_aggression)
        {
             $aggression = mt_rand(1,2);  //I do this to create more peacefull than aggressive.  This creates 33% aggressive.  I will make configurable later - Jordo // originally 1 GunSlinger
        }
        else
        {
             $aggression = 0;
        }
        if ($aggression == 1)
        {
             $orders = mt_rand(0,3); // 0 = Sentinel, 1 = Explorer, 2 = Trader, 3 = Hunter
        }

        $active = "Y";
        $emailname = $character . "@npc";
        $password="";
        $syllables="er,in,tia,wol,fe,pre,vet,jo,nes,al,len,son,cha,ir,ler,bo,ok,tio,nar,sim,ple,bla,ten,toe,cho,co,lat,spe,ak,er,po,co,lor,pen,cil,li,ght,wh,at,the,he,ck,is,mam,bo,no,fi,ve,any,way,pol,iti,cs,ra,dio,sou,rce,sea,rch,pa,per,com,bo,sp,eak,st,fi,rst,gr,oup,boy,ea,gle,tr,ail,bi,ble,brb,pri,dee,kay,en,be,se";
        $syllable_array=explode(",", $syllables);
        for ($count = 1; $count <= 4; $count++)
        {
            if (mt_rand()%10 == 1)
            {
               $password .= sprintf("%0.0f",(mt_rand()%50)+1);
           }
           else
           {
              $password .= sprintf("%s",$syllable_array[mt_rand()%62]);
           }
        }

        $password = ord_crypt_encode($password);
        $player_id = newplayer($emailname, $character, $password, $shipname, 1, 0, 0);

        $result = $db->Execute ("select ship_id from {$db_prefix}ships where player_id='$player_id'");
        db_op_result($result,__LINE__,__FILE__);
        $ship_id = $result->fields['ship_id'];
        $result->close();

        $maxenergy = NUM_ENERGY($shipinfo['power']) / 3;
        $maxarmour = NUM_armor($shipinfo['armor']);
        $maxfighters = NUM_FIGHTERS($shipinfo['fighter']);
        $maxtorps = NUM_TORPEDOES($shipinfo['torp_launchers']);

        $time_since = time() - strtotime($reset_date . " 00:00:00");
        $daymultiplyer = max(1, (($time_since/604800) * 7) + (($time_since%604800)/86400));

        $creditreturn = $start_credits * $daymultiplyer;

        $result = $db->Execute ("UPDATE {$db_prefix}players SET credits = '$creditreturn' where player_id='$player_id'");
        db_op_result($result,__LINE__,__FILE__);

        $query = "UPDATE {$db_prefix}ships SET class=$shipinfo[class], hull=$shipinfo[hull], engines=$shipinfo[engines], 
        power=$shipinfo[power], fighter=$shipinfo[fighter], sensors=$shipinfo[sensors], beams=$shipinfo[beams], 
        armor=$shipinfo[armor], cloak=$shipinfo[cloak], torp_launchers=$shipinfo[torp_launchers], shields=$shipinfo[shields], 
        ecm=$shipinfo[ecm], hull_normal=$shipinfo[hull], engines_normal=$shipinfo[engines], 
        power_normal=$shipinfo[power], fighter_normal=$shipinfo[fighter], sensors_normal=$shipinfo[sensors], 
        beams_normal=$shipinfo[beams], armor_normal=$shipinfo[armor], cloak_normal=$shipinfo[cloak], 
        torp_launchers_normal=$shipinfo[torp_launchers], shields_normal=$shipinfo[shields], 
        ecm_normal=$shipinfo[ecm], fighters='$maxfighters', torps='$maxtorps', armor_pts='$maxarmour', 
        energy='$maxenergy', galaxy_id='$galaxy_id', sector_id='$sector' WHERE ship_id=$ship_id ";
        $debug_query = $db->Execute("$query");
        db_op_result($debug_query,__LINE__,__FILE__);

        $result = $db->Execute ("UPDATE {$db_prefix}ship_devices SET amount = '1000000' WHERE class='dev_minedeflector' and player_id = $player_id");
        db_op_result($result,__LINE__,__FILE__);
        $result = $db->Execute ("UPDATE {$db_prefix}ship_devices SET amount = '3' WHERE class='dev_emerwarp' and player_id = $player_id");
        db_op_result($result,__LINE__,__FILE__);

        $res = $db->Execute("INSERT INTO {$db_prefix}npc_player (npc_id, active, aggression, orders, experience) 
        VALUES ('$player_id', '$active', '$aggression', '$orders', '0') ");
        db_op_result($res,__LINE__,__FILE__);
    }
    $db->debug=false;
}


?>
