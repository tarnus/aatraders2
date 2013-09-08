<?php
include ("globals/player_ship_destroyed.inc");

class boobytrap {
	var $classname = "boobytrap";
	var $success = "1600";	// Random value range
	var $trigger = "800";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	var $destroyship_debris = "0";	// Set to 1 is this debris can be created when a ship is destroyed
	var $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	var $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	var $l_debris_zeroship;
	var $l_debris_destroyship;

	// fill language variables
	function boobytrap()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_boobytrap = "Praht on tohman lõksu! Teie laev kannatab suurt kahju! <br><br> [hull] langeb [newhull] <br> [engines] langeb [newengines] <br> [power] langeb [newpower] <br> [fighter] langeb [newfighter] <br> [sensors] langeb [newsensors] <br> [beams] langeb [newbeams] <br> [torp_launchers] langeb [newtorp_launchers] <br> [shields] langeb [newshields] <br> [cloak] langeb [newcloak] <br> [armor] langeb [newarmor] <br> [armor_pts] langeb [newarmor_pts] <br> [torps] langeb [newtorps] <br> [fighters] langeb [newfighters] <br> [energy] langeb [newenergy] <br> [ecm] langeb [newecm] <br>";
			break;

			case "french":
				$this->l_debris_boobytrap = "Les débris ont été piégés! Votre vaisseau subit des dommages considérables! <br><br> [hull] sera en baisse à [newhull] <br> [engines] sera en baisse à [newengines] <br> [power] sera en baisse à [newpower] <br> [fighter] sera en baisse à [newfighter] <br> [engines] sera en baisse à [newengines] <br> [beams] sera en baisse à [newbeams] <br> [torp_launchers] sera en baisse à [newtorp_launchers] <br> [shields] sera en baisse à [newshields] <br> [cloak] sera en baisse à [newcloak] <br> [armor] sera en baisse à [newarmor] <br> [armor_pts] sera en baisse à [newarmor_pts] <br> [torps] sera en baisse à [newtorps] <br> [fighters] sera en baisse à [newfighters] <br> [energy] sera en baisse à [newenergy] <br> [ecm] sera en baisse à [newecm] <br>";
			break;

			case "german":
				$this->l_debris_boobytrap = "Der Schutt hat BOOBY gefangen waren! Ihr Schiff erleidet massiven Schaden! <br><br> [hull] Tropfen [newhull] <br> [engines] Tropfen [newengines] <br> [power] Tropfen [newpower] <br> [fighter] Tropfen [newfighter] <br> [sensors] Tropfen [newsensors] <br> [beams] Tropfen [newbeams] <br> [torp_launchers] Tropfen [newtorp_launchers] <br> [shields] Tropfen [newshields] <br> [cloak] Tropfen [newcloak] <br> [armor] Tropfen [newarmor] <br> [armor_pts] Tropfen [newarmor_pts] <br> [torps] Tropfen [newtorps] <br> [fighter] Tropfen [newfighters] <br> [energy] Tropfen [newenergy] <br> [ecm] Tropfen [newecm] <br>";
			break;

			case "italian":
				$this->l_debris_boobytrap = "Le macerie è stato BOOBY trappola! Vostra nave subisce danni enormi! <br><br> [hull] gocce [newhull] <br> [engines] gocce [newengines] <br> [power] gocce [newpower] <br> [fighter] gocce [newfighter] <br> [sensors] gocce [newsensors] <br> [beams] gocce [newbeams] <br> [torp_launchers] gocce [newtorp_launchers] <br> [shields] gocce [newshields] <br> [cloak] gocce [newcloak] <br> [armor] gocce [newarmor] <br> [armor_pts] gocce [newarmor_pts] <br> [torps] gocce [newtorps] <br> [fighter] gocce [newfighters] <br> [energy] gocce [newenergy] <br> [ecm] gocce [newecm] <br>";
			break;

			case "spanish":
				$this->l_debris_boobytrap = "Los escombros se ha ARMAS atrapados! Su nave sufre un daño masivo! <br><br> [hull] cae a [newhull] <br> [engines] cae a [newengines] <br> [power] se reduce a [newpower] <br> [fighter] se reduce a [newfighter] <br> [sensors] cae a [newsensors] <br> [beams] cae a [newbeams] <br> [torp_launchers] cae a [newtorp_launchers] <br> [shields] cae a [newshields] <br> [cloak] cae a [newcloak] <br> [armor] cae a [newarmor] <br> [armor_pts] cae a [newarmor_pts] <br> [torps] cae a [newtorps] <br> [fighters] se reduce a [newfighters] <br> [energy] se reduce a [newenergy] <br> [ecm] cae a [newecm] <br>";
			break;

			case "albanian":
				$this->l_debris_boobytrap = "Mbeturinave ka qenë objekt bllokuar! Anija juaj vuan dëmtimin masiv! <br><br> [hull] pika të [newhull] <br> [engines] pika të [newengines] <br> [power] pika të [newpower] <br> [fighter] pika të [newfighter] <br> [sensors] pika të [newsensors] <br> [beams] pika të [newbeams] <br> [torp_launchers] pika të [newtorp_launchers] <br> [shields] pika të [newshields] <br> [cloak] pika të [newcloak] <br> [armor] pika të [newarmor] <br> [armor_pts] pika të [newarmor_pts] <br> [torps] pika të [newtorps] <br> [fighters] pika të [newfighters] <br> [power] pika të [newenergy] <br> [ecm] pika të [newecm] <br>";
			break;

			case "catalan":
				$this->l_debris_boobytrap = "La runa s&#39;ha ARMES atrapats! La seva nau pateix un dany massiu! <br><br> [hull] cau a [newhull] <br> [engines] cau a [newengines] <br> [power] es redueix a [newpower] <br> [fighter] es redueix a [newfighter] <br> [sensors] cau a [newsensors] <br> [beams] cau a [newbeams] <br> [torp_launchers] cau a [newtorp_launchers] <br> [shields] cau a [newshields] <br> [cloak] cau a [newcloak] <br> [armor] cau a [newarmor] <br> [armor_pts] cau a [newarmor_pts] <br> [torps] cau a [newtorps] <br> [fighters] es redueix a [newfighters] <br> [energy] es redueix a [newenergy] <br> [ecm] cau a [newecm] <br>";
			break;

			case "danish":
				$this->l_debris_boobytrap = "Resterne er Booby Trapped! Dit skib lider store skader! <br><br> [hull] dråber til [newhull] <br> [engines] dråber til [newengines] <br> [power] dråber til [newpower] <br> [fighter] dråber til [newfighter] <br> [sensors] dråber til [newsensors] <br> [beams] dråber til [newbeams] <br> [torp_launchers] dråber til [newtorp_launchers] <br> [shields] dråber til [newshields] <br> [cloak] dråber til [newcloak] <br> [armor] dråber til [newarmor] <br> [armor_pts] dråber til [newarmor_pts] <br> [torps] dråber til [newtorps] <br> [fighters] dråber til [newfighters] <br> [energy] dråber til [newenergy] <br> [ecm] dråber til [newecm] <br>";
			break;

			case "dutch":
				$this->l_debris_boobytrap = "Het puin is Booby TRAPPED! Uw schip lijdt enorme schade! <br><br> [hull] daalt tot [newhull] <br> [engines] daalt tot [newengines] <br> [power] daalt tot [newpower] <br> [fighter] daalt tot [newfighter] <br> [sensors] daalt tot [newsensors] <br> [beams] daalt tot [newbeams] <br> [torp_launchers] daalt tot [newtorp_launchers] <br> [shields] daalt tot [newshields] <br> [cloak] daalt tot [newcloak] <br> [armor] daalt tot [newarmor] <br> [armor_pts] daalt tot [newarmor_pts] <br> [torps] daalt tot [newtorps] <br> [fighters] daalt tot [newfighters] <br> [energy] daalt tot [newenergy] <br> [ecm] daalt tot [newecm] <br>";
			break;

			case "finnish":
				$this->l_debris_boobytrap = "Roskat on hölmö loukussa! Sinun alus kärsii vakavia vaurioita! <br><br> [hull] putoaa [newhull] <br> [engines] putoaa [newengines] <br> [power] putoaa [newpower] <br> [fighter] putoaa [newfighter] <br> [sensors] putoaa [newsensors] <br> [beams] putoaa [newbeams] <br> [torp_launchers] putoaa [newtorp_launchers] <br> [shields] putoaa [newshields] <br> [cloak] putoaa [newcloak] <br> [armor] putoaa [newarmor] <br> [armor_pts] putoaa [newarmor_pts] <br> [torps] putoaa [newtorps] <br> [fighters] putoaa [newfighters] <br> [energy] putoaa [newenergy] <br> [ecm] putoaa [newecm] <br>";
			break;

			case "indonesian":
				$this->l_debris_boobytrap = "Puing-puing telah Booby terjebak! Kapal anda menderita kerusakan besar! <br><br> [hull] tetes untuk [newhull] <br> [engines] tetes untuk [newengines] <br> [power] tetes untuk [newpower] <br> [fighter] tetes ke [newfighter] <br> [sensors] tetes untuk [newsensors] <br> [beams] tetes ke [newbeams] <br> [torp_launchers] tetes untuk [newtorp_launchers] <br> [shields] tetes untuk [newshields] <br> [cloak] tetes untuk [newcloak] <br> [armor] tetes ke [newarmor] <br> [armor_pts] tetes untuk [newarmor_pts] <br> [torps] tetes untuk [newtorps] <br> [fighters] tetes untuk [newfighters] <br> [energy] tetes untuk [newenergy] <br> [ecm] tetes untuk [newecm] <br>";
			break;

			case "norwegian":
				$this->l_debris_boobytrap = "Vrakrestene har vært Booby Trapped! Skipet ditt lider store skader! <br><br> [hull] synker til [newhull] <br> [engines] synker til [newengines] <br> [power] synker til [newpower] <br> [fighter] synker til [newfighter] <br> [sensors] synker til [newsensors] <br> [beams] synker til [newbeams] <br> [torp_launchers] synker til [newtorp_launchers] <br> [shields] synker til [newshields] <br> [cloak] synker til [newcloak] <br> [armor] synker til [newarmor] <br> [armor_pts] synker til [newarmor_pts] <br> [torps] synker til [newtorps] <br> [fighters] synker til [newfighters] <br> [energy] synker til [newenergy] <br> [ecm] synker til [newecm] <br>";
			break;

			case "portuguese":
				$this->l_debris_boobytrap = "O entulho foi uma armadilha! Seu navio sofre danos massivos! <br><br> [hull] cai para [newhull] <br> [engines] cai para [newengines] <br> [power] cai para [newpower] <br> [fighter] cai para [newfighter] <br> [sensors] cai para [newsensors] <br> [beams] cai para [newbeams] <br> [torp_launchers] cai para [newtorp_launchers] <br> [shields] cai para [newshields] <br> [cloak] cai para [newcloak] <br> [armor] cai para [newarmor] <br> [armor_pts] cai para [newarmor_pts] <br> [torps] cai para [newtorps] <br> [fighters] cai para [newfighters] <br> [energy] cai para  [newenergy] <br> [ecm] cai para newecm [newecm] <br>";
			break;

			case "swedish":
				$this->l_debris_boobytrap = "Skräpet har ELAKT Fångad! Ditt skepp lider stor skada! <br><br> [hull] droppar till [newhull] <br> [engines] droppar till [newengines] <br> [power] droppar till [newpower] <br> [fighter] droppar till [newfighter] <br> [sensors] droppar till [newsensors] <br> [beams] droppar till [newbeams] <br> [torp_launchers] droppar till [newtorp_launchers] <br> [shields] droppar till [newshields] <br> [cloak] droppar till [newcloak] <br> [armor] droppar till [newarmor] <br> [armor_pts] droppar till [newarmor_pts] <br> [torps] droppar till [newtorps] <br> [fighters] droppar till [newfighters] <br> [energy] droppar till [newenergy] <br> [ecm] droppar till [newecm] <br>";
			break;

			default:
				$this->l_debris_boobytrap = "The debris has been BOOBY TRAPPED!  Your ship suffers massive damage!<br><br>[hull] drops to [newhull]<br>[engines] drops to [newengines]<br>[power] drops to [newpower]<br>[fighter] drops to [newfighter]<br>[sensors] drops to [newsensors]<br>[beams] drops to [newbeams]<br>[torp_launchers] drops to [newtorp_launchers]<br>[shields] drops to [newshields]<br>[cloak] drops to [newcloak]<br>[armor] drops to [newarmor]<br>[armor_pts] drops to [newarmor_pts]<br>[torps] drops to [newtorps]<br>[fighters] drops to [newfighters]<br>[energy] drops to [newenergy]<br>[ecm] drops to [newecm]<br>";
			break;
		}
	}
 
	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo, $shipdevice, $playerinfo, $start_armor, $start_energy, $start_fighters;

		$debrismessage = str_replace("[hull]", $shipinfo['hull'], $this->l_debris_boobytrap);
		$debrismessage = str_replace("[engines]", $shipinfo['engines'], $debrismessage);
		$debrismessage = str_replace("[power]", $shipinfo['power'], $debrismessage);
		$debrismessage = str_replace("[fighter]", $shipinfo['fighter'], $debrismessage);
		$debrismessage = str_replace("[sensors]", $shipinfo['sensors'], $debrismessage);
		$debrismessage = str_replace("[beams]", $shipinfo['beams'], $debrismessage);
		$debrismessage = str_replace("[torp_launchers]", $shipinfo['torp_launchers'], $debrismessage);
		$debrismessage = str_replace("[shields]", $shipinfo['shields'], $debrismessage);
		$debrismessage = str_replace("[cloak]", $shipinfo['cloak'], $debrismessage);
		$debrismessage = str_replace("[armor]", $shipinfo['armor'], $debrismessage);
		$debrismessage = str_replace("[armor_pts]", $shipinfo['armor_pts'], $debrismessage);
		$debrismessage = str_replace("[torps]", $shipinfo['torps'], $debrismessage);
		$debrismessage = str_replace("[fighters]", $shipinfo['fighters'], $debrismessage);
		$debrismessage = str_replace("[energy]", $shipinfo['energy'], $debrismessage);
		$debrismessage = str_replace("[ecm]", $shipinfo['ecm'], $debrismessage);

		$techdamage = (mt_rand(50, 75) * 0.01);
		$shipinfo['hull'] = floor($shipinfo['hull'] * $techdamage);
		$shipinfo['engines'] = floor($shipinfo['engines'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['power'] = floor($shipinfo['power'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['fighter'] = floor($shipinfo['fighter'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['sensors'] = floor($shipinfo['sensors'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['beams'] = floor($shipinfo['beams'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['torp_launchers'] = floor($shipinfo['torp_launchers'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['shields'] = floor($shipinfo['shields'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['cloak'] = floor($shipinfo['cloak'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['armor'] = floor($shipinfo['armor'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['armor_pts'] = floor($shipinfo['armor_pts'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['torps'] = floor($shipinfo['torps'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['fighters'] = floor($shipinfo['fighters'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['energy'] = floor($shipinfo['energy'] * (mt_rand(50, 75) * 0.01));
		$shipinfo['ecm'] = floor($shipinfo['ecm'] * (mt_rand(50, 75) * 0.01));

		$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET hull=$shipinfo[hull], engines=$shipinfo[engines], 
		power=$shipinfo[power], fighter=$shipinfo[fighter], sensors=$shipinfo[sensors], beams=$shipinfo[beams], 
		torp_launchers=$shipinfo[torp_launchers], shields=$shipinfo[shields], cloak=$shipinfo[cloak], 
		armor=$shipinfo[armor], armor_pts=$shipinfo[armor_pts], torps=$shipinfo[torps], fighters=$shipinfo[fighters], 
		energy=$shipinfo[energy], ecm=$shipinfo[ecm] WHERE ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$debug_query = $db->Execute("UPDATE {$db_prefix}ship_holds SET amount=amount * $techdamage WHERE ship_id=$shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$debrismessage = str_replace("[newhull]", $shipinfo['hull'], $debrismessage);
		$debrismessage = str_replace("[newengines]", $shipinfo['engines'], $debrismessage);
		$debrismessage = str_replace("[newpower]", $shipinfo['power'], $debrismessage);
		$debrismessage = str_replace("[newfighter]", $shipinfo['fighter'], $debrismessage);
		$debrismessage = str_replace("[newsensors]", $shipinfo['sensors'], $debrismessage);
		$debrismessage = str_replace("[newbeams]", $shipinfo['beams'], $debrismessage);
		$debrismessage = str_replace("[newtorp_launchers]", $shipinfo['torp_launchers'], $debrismessage);
		$debrismessage = str_replace("[newshields]", $shipinfo['shields'], $debrismessage);
		$debrismessage = str_replace("[newcloak]", $shipinfo['cloak'], $debrismessage);
		$debrismessage = str_replace("[newarmor]", $shipinfo['armor'], $debrismessage);
		$debrismessage = str_replace("[newarmor_pts]", $shipinfo['armor_pts'], $debrismessage);
		$debrismessage = str_replace("[newtorps]", $shipinfo['torps'], $debrismessage);
		$debrismessage = str_replace("[newfighters]", $shipinfo['fighters'], $debrismessage);
		$debrismessage = str_replace("[newenergy]", $shipinfo['energy'], $debrismessage);
		$debrismessage = str_replace("[newecm]", $shipinfo['ecm'], $debrismessage);
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$debris_data = (mt_rand(0, 1) == 1) ? -1 : 1;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$debris_data = (mt_rand(0, 1) == 1) ? -1 : 1;
		return $debris_data;
	}
}

?>