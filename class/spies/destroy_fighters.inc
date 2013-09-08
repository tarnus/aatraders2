<?php
class destroy_fighters {
	var $id = "4";
	var $singlepass = 0;

	function destroy_fighters()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "purustada h&auml;vitajaid";
				$this->description = "Spy juhuslikult hävitada suur hulk hävitajaid salvestatud planeedi.";
				$this->success = "Spy Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy hasard détruire un grand nombre de combattants enregistrés sur la planète.";
				$this->success = "Spy Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Jäger zu zerstören";
				$this->description = "Spion wird nach dem Zufallsprinzip zu zerstören große Zahl von Kämpfern auf der Erde gespeichert.";
				$this->success = "Spy Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Distruggere droni";
				$this->description = "Spy in modo casuale distruggere un gran numero di combattenti memorizzati sul pianeta.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Destruir Cazas";
				$this->description = "Espía al azar va a destruir un gran número de combatientes almacenados en el planeta.";
				$this->success = "Espía de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Destroy Fighters";
				$this->description = "Spiun rastësisht do të shkatërrojë një numër të madh të luftëtarëve të ruajtur në planetin.";
				$this->success = "Spiun i punës me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Fighters Destroy";
				$this->description = "Espia a l&#39;atzar va a destruir un gran nombre de combatents emmagatzemats al planeta.";
				$this->success = "Espia d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy vil tilfældigt ødelægge et stort antal krigere er gemt på planeten.";
				$this->success = "Spy Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy zal willekeurig vernietigen van grote aantallen strijders opgeslagen op de planeet.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy tulee satunnaisesti tuhota suuren määrän taistelijoiden tallennettu planeetalla.";
				$this->success = "Spy työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Hancurkan Fighters";
				$this->description = "Mata-mata akan secara acak menghancurkan sejumlah besar pejuang yang tersimpan di planet ini.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy vil tilfeldig ødelegge et stort antall jagerfly er lagret på planeten.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy irá aleatoriamente destruir um grande número de combatentes armazenados no planeta.";
				$this->success = "Spy Job alterada com êxito.";
			break;

			case "swedish":
				$this->classname = "Destroy Fighters";
				$this->description = "Spy kommer slumpmässigt förstöra många fighters som lagrats på planeten.";
				$this->success = "Spy Job har ändrats.";
			break;

			default:
				$this->classname = "Destroy Fighters";
				$this->description = "Spy will randomly destroy large numbers of fighters stored on the planet.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier, $spy;

		$blowup_fits = 5000;
		$blowup_fits_trigger = (int) ($blowup_fits / 2);
		$success = mt_rand(0, $blowup_fits);
		if ($success == $blowup_fits_trigger)
		{
			if ($spy['fighters'] > 0)
			{
				TextFlush ( "Spy Destroying Fighters<br>");

				$roll = myrand(2400, 9000, 4);	//8%...30%
				$blow = floor($spy['fighters'] * $roll / 30000);
				$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET fighters=fighters-$blow WHERE planet_id=$spy[planet_id] ");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
			}
	}

	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix;

		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='0', job_id='4' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>