<?php
class decrease_birthrate {
	var $id = "3";
	var $singlepass = 1;

	function decrease_birthrate()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Sündimus Decreaser";
				$this->description = "Spy tapab suures koguses planeetide elanike varjatud viisil.";
				$this->success = "Spy Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Taux de natalité Decreaser";
				$this->description = "Spy tue une grande quantité de planètes de la population d&#39;une manière déguisée.";
				$this->success = "Spy Job changé avec succès.";
			break;

			case "german":
				$this->classname = "die Geburtenrate zu senken";
				$this->description = "Spy tötet große Mengen des Planeten Bevölkerung in einer verdeckten Weise.";
				$this->success = "Spy Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Limitatore nascite";
				$this->description = "Spy uccide una grande quantità di popolazione pianeti in maniera occulta.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Reducir natalidad";
				$this->description = "Spy mata grandes cantidades de la población del planeta de manera encubierta.";
				$this->success = "Espía de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Përqindje e lindjeve Decreaser";
				$this->description = "Spiun vret sasi të mëdha të popullsisë planetet në një mënyrë të fshehtë.";
				$this->success = "Spiun i punës me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Taxa de natalitat decreased";
				$this->description = "Spy mata grans quantitats de la població del planeta de manera encoberta.";
				$this->success = "Espia d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Fødselsrate Decreaser";
				$this->description = "Spy dræber store mængder af planeterne befolkningen i en skjult måde.";
				$this->success = "Spy Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Geboortecijfer Decreaser";
				$this->description = "Spy doodt grote hoeveelheden van de planeten bevolking in een verkapte manier.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Syntyvyyden Decreaser";
				$this->description = "Spy tappaa suuret määrät planeettojen väestön peitellyn tavalla.";
				$this->success = "Spy työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kelahiran Decreaser";
				$this->description = "Mata-mata membunuh sejumlah besar penduduk planet cara rahasia.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Fødselstall Decreaser";
				$this->description = "Spy dreper store mengder av planeter befolkningen på en skjult måte.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Natalidade Decreaser";
				$this->description = "Spy mata uma grande quantidade da população planetas de uma forma encoberta.";
				$this->success = "Spy Job alterada com êxito.";
			break;

			case "swedish":
				$this->classname = "FÖDELSESIFFRA Decreaser";
				$this->description = "Spy dödar stora mängder av planeterna befolkningen i ett förtäckt sätt.";
				$this->success = "Spy Job har ändrats.";
			break;

			default:
				$this->classname = "Birthrate Decreaser";
				$this->description = "Spy kills large amounts of the planets population in a covert manner.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier;

	TextFlush ( "Spies Killing Enemy Colonists<br>");

	$query = $db->Execute("UPDATE {$db_prefix}planets as p, {$db_prefix}spies as s SET " .
								"p.colonists=GREATEST(p.colonists-(p.colonists * ($multiplier * s.spy_percent)), 0)
								WHERE s.job_id='3' AND s.active='Y' and p.planet_id=s.planet_id");
	db_op_result($query,__LINE__,__FILE__);
	$query->close();

	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix, $colonist_reproduction_rate;

		$r1 = $db->Execute("SELECT SUM(spy_percent) as b_total FROM {$db_prefix}spies WHERE active='Y' AND planet_id=$planet_id AND job_id='3' ");
		$total = $r1->fields['b_total'];
		$r1->close();
		$total = floor(($colonist_reproduction_rate - $total) * 500000);
		$new_percent = myrand(floor($total * 0.1), floor($total * 0.3), 1.3);	//10%...30%
		$new_percent /= 500000.0;
		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='$new_percent', job_id='3' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>