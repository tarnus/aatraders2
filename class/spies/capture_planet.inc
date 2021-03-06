<?php
class capture_planet {
	var $id = "0";
	var $singlepass = 0;

	function capture_planet()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Pildista Planet";
				$this->description = "Spy mis �hutab rahulolematust elanikkonna p�hjustades nende m�ssu ning muuta sulle truudust.";
				$this->success = "Spy T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Capture Planet";
				$this->description = "Spy fomenter des troubles dans la population en les faisant all�geance � la r�volte et le changement pour vous.";
				$this->success = "Spy Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "den Planeten zu �bernehmen";
				$this->description = "Spy Unruhen in der Bev�lkerung zu sch�ren so dass sie zum Aufstand und �ndern Treue zu dir.";
				$this->success = "Spy Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Catturare il pianeta";
				$this->description = "Spy fomentare disordini nella popolazione causando la loro rivolta e fedelt� cambiare a voi.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Capturar el planeta";
				$this->description = "Esp�a fomentar el malestar en la poblaci�n haciendo que a la revuelta y la lealtad cambio a usted.";
				$this->success = "Esp�a de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Capture Planet";
				$this->description = "Spiun do t� nxis trazira n� popullat�n e tyre p�r t� shkaktuar revolt� dhe besnik�ri t� ndryshoj� p�r ju.";
				$this->success = "Spiun i pun�s me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Captura Planet";
				$this->description = "Espia fomentar el malestar a la poblaci� fent que a la revolta i la lleialtat canvi a vost�.";
				$this->success = "Espia d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Capture Planet";
				$this->description = "Spy vil anstifte uro i befolkningen og f�r dem til at g�re opr�r og �ndre troskab til dig.";
				$this->success = "Spy Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Capture Planet";
				$this->description = "Spy zal aanhitsen onrust in de bevolking waardoor ze in opstand en verandering trouw aan jou.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Capture Planet";
				$this->description = "Spy se lietsoo levottomuuksia v�est�n aiheuttaa niit� kapinaan ja vaihtaa uskollisuutta sinulle.";
				$this->success = "Spy ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Capture Planet";
				$this->description = "Mata-mata akan memicu kerusuhan di penduduk menyebabkan mereka untuk memberontak dan berubah setia kepada Anda.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Capture Planet";
				$this->description = "Spy vil Foment uro i befolkningen fikk dem til � gj�re oppr�r og endre troskap til deg.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Capture Planet";
				$this->description = "Spy ir� fomentar a agita��o na popula��o causando-lhes a revolta e mudan�a fidelidade para voc�.";
				$this->success = "Spy Job alterada com �xito.";
			break;

			case "swedish":
				$this->classname = "Capture Planet";
				$this->description = "Spy kommer att underbl�sa oroligheterna i befolkningen som orsakar dem att g�ra uppror och f�r�ndra trohet till dig.";
				$this->success = "Spy Job har �ndrats.";
			break;

			default:
				$this->classname = "Capture Planet";
				$this->description = "Spy will foment unrest in the population causing them to revolt and change allegiance to you.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier, $spy, $allow_spy_capture_planets, $display_percentage_age, $capture_countdown_max, $capture_quickfind_percentage, $persuasion_countdown_max;

		if ($allow_spy_capture_planets)
		{
			$capture = 20000;
			$capture_trigger = (int) ($capture / 2);

			$success = mt_rand(0, $capture);
			if ($success == $capture_trigger)
			{
				TextFlush ( "Spies Capturing a Planet<br>");

				$spies_on_planet = 0;
				$spy_check = $db->Execute("SELECT COUNT(spy_id) as total FROM {$db_prefix}spies WHERE active='Y' AND ship_id = '0' AND planet_id = $spy[planet_id]");
				db_op_result($spy_check,__LINE__,__FILE__);
				$spies_on_planet = $spy_check->RecordCount();

				$new_age = floor(($display_percentage_age / 2) + mt_rand(0, $display_percentage_age));
				$capture_countdown = mt_rand(floor($capture_countdown_max / 3), $capture_countdown_max);
				$capture_quickfind = floor($spy['credits'] * ((mt_rand(floor($capture_quickfind_percentage / 2), $capture_quickfind_percentage) + $spies_on_planet) * 0.01));
				$hiddencredits = max($spy['credits'] - $capture_quickfind, 0);
				$persuasion_countdown = mt_rand(floor($persuasion_countdown_max / 3), $persuasion_countdown_max);
				$old_rating = good_neutral_evil($spy['owner']);
				$old_owner_rating = $old_rating[0];

				$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET last_owner_rating = $old_owner_rating, persuasion_countdown = $persuasion_countdown, credits = $capture_quickfind, captured_countdown = $capture_countdown, hidden_credits = $hiddencredits, use_age=$new_age, cargo_hull = 0, cargo_power = 0, team=null, owner=$spy[owner_id], base='N', defeated='N' WHERE planet_id=$spy[planet_id]");
				db_op_result($debug_query,__LINE__,__FILE__);

				//echo "ID - $spy[planet_id], OLD - $spy[owner], NEW - $spy[owner_id]<BR>";

				change_planet_ownership($spy['planet_id'], $spy['owner'], $spy['owner_id']);
				calc_ownership($spy['sector_id']);
				playerlog($spy['owner_id'], "LOG2_SPY_CPTURE", "$spy[spy_id]|$spy[name]|$spy[sector_id]");
				playerlog($spy['owner'], "LOG2_SPY_CPTURE_OWNER", "$spy[name]|$spy[sector_id]|$spy[character_name]");

				capture_planet_ships($spy['owner_id'], $spy['planet_id']);
				$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET on_planet='N' WHERE planet_id=$spy[planet_id]");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
			}
		}
	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix;

		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='0', job_id='0' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>