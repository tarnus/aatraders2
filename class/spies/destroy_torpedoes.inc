<?php
class destroy_torpedoes {
	var $id = "5";
	var $singlepass = 0;

	function destroy_torpedoes()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "purustada torpeedosid";
				$this->description = "Spy h�vitab suure hulga planeetide torpeedod.";
				$this->success = "Spy T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Destroy Torpilles";
				$this->description = "Spy d�truit un grand nombre de torpilles plan�taire.";
				$this->success = "Spy Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "Torpedos zu zerst�ren";
				$this->description = "Spy zerst�rt, eine gro�e Anzahl von Planeten-Torpedos.";
				$this->success = "Spy Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Distruggere siluri";
				$this->description = "Spy distrugge un gran numero di siluri planetaria.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Destruir Torpedos";
				$this->description = "Spy destruye un gran n�mero de torpedos planetaria.";
				$this->success = "Esp�a de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Destroy silur�t";
				$this->description = "Spiun shkat�rron nj� num�r t� madh t� silur�t planetare.";
				$this->success = "Spiun i pun�s me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Destroy Torpedo";
				$this->description = "Spy destrueix un gran nombre de torpedes planet�ria.";
				$this->success = "Espia d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Destroy Torpedoer";
				$this->description = "Spy �del�gger mange planeternes torpedoer.";
				$this->success = "Spy Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Destroy Torpedo";
				$this->description = "Spy vernietigt grote aantallen van planetaire torpedo&#39;s.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Destroy Torpedot";
				$this->description = "Spy tuhoaa paljon planeettojen torpedot.";
				$this->success = "Spy ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Hancurkan Torpedoes";
				$this->description = "Mata-mata menghancurkan sejumlah besar planet torpedo.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Destroy Torpedoes";
				$this->description = "Spy �delegger et stort antall planeter torpedoer.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Destroy Torpedos";
				$this->description = "Spy destr�i um grande n�mero de torpedos planet�rios.";
				$this->success = "Spy Job alterada com �xito.";
			break;

			case "swedish":
				$this->classname = "Destroy Torpeder";
				$this->description = "Spy f�rst�r stora m�ngder av planetsystem torpeder.";
				$this->success = "Spy Job har �ndrats.";
			break;

			default:
				$this->classname = "Destroy Torpedoes";
				$this->description = "Spy destroys large numbers of planetary torpedoes.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier, $spy;

		$blowup_torp = 3000;
		$blowup_torp_trigger = (int) ($blowup_torp / 2);
		$success = mt_rand(0, $blowup_torp);
		if ($success == $blowup_torp_trigger)
		{
			if ($spy['torps'] > 0)
			{
				TextFlush ( "Spy Destroying Torpedoes<br>");

				$roll = myrand(2100, 7500, 3);	//7%...25%
				$blow = floor($spy['torps'] * $roll / 30000);
				$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET torps=torps-$blow WHERE planet_id=$spy[planet_id] ");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
			}
		}

	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix;

		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='0', job_id='5' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>