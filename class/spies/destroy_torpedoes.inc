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
				$this->description = "Spy hävitab suure hulga planeetide torpeedod.";
				$this->success = "Spy Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Destroy Torpilles";
				$this->description = "Spy détruit un grand nombre de torpilles planétaire.";
				$this->success = "Spy Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Torpedos zu zerstören";
				$this->description = "Spy zerstört, eine große Anzahl von Planeten-Torpedos.";
				$this->success = "Spy Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Distruggere siluri";
				$this->description = "Spy distrugge un gran numero di siluri planetaria.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Destruir Torpedos";
				$this->description = "Spy destruye un gran número de torpedos planetaria.";
				$this->success = "Espía de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Destroy silurët";
				$this->description = "Spiun shkatërron një numër të madh të silurët planetare.";
				$this->success = "Spiun i punës me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Destroy Torpedo";
				$this->description = "Spy destrueix un gran nombre de torpedes planetària.";
				$this->success = "Espia d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Destroy Torpedoer";
				$this->description = "Spy ødelægger mange planeternes torpedoer.";
				$this->success = "Spy Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Destroy Torpedo";
				$this->description = "Spy vernietigt grote aantallen van planetaire torpedo&#39;s.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Destroy Torpedot";
				$this->description = "Spy tuhoaa paljon planeettojen torpedot.";
				$this->success = "Spy työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Hancurkan Torpedoes";
				$this->description = "Mata-mata menghancurkan sejumlah besar planet torpedo.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Destroy Torpedoes";
				$this->description = "Spy ødelegger et stort antall planeter torpedoer.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Destroy Torpedos";
				$this->description = "Spy destrói um grande número de torpedos planetários.";
				$this->success = "Spy Job alterada com êxito.";
			break;

			case "swedish":
				$this->classname = "Destroy Torpeder";
				$this->description = "Spy förstör stora mängder av planetsystem torpeder.";
				$this->success = "Spy Job har ändrats.";
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