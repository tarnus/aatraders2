<?php
class sabotage_SD_tech {
	var $id = "10";
	var $singlepass = 0;

	function sabotage_SD_tech()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;

			case "french":
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;

			case "german":
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;

			case "italian":
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;

			case "russian":
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;

			case "spanish":
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;

			default:
				$this->classname = "Sabotage Sector Defense Technology";
				$this->description = "Spy damages the Tech Levels used for Sector Defense";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier, $spy;

/*
		TextFlush ( "Spies Destroying SD Fighters<br>");

		$SD_sabotage = 1500;
		$SD_trigger = (int) ($SD_sabotage / 2);
		$success = mt_rand(0, $SD_sabotage);
		if ($success == $SD_trigger && $flag)
		{
			if ($spy['fighters'] > 0)
			{
				$roll = myrand(2400, 9000, 4);	//8%...30%
				$blow = floor($spy['fighters'] * $roll / 30000);
				$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET fighters=fighters-$blow WHERE planet_id=$spy[planet_id] ");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
			}
		}
*/
	}

	function change_spy($spy_id, $planet_id)
	{
		global $db, $db_prefix;

		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET spy_percent='0', job_id='10' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>