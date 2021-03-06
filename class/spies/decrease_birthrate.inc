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
				$this->classname = "S�ndimus Decreaser";
				$this->description = "Spy tapab suures koguses planeetide elanike varjatud viisil.";
				$this->success = "Spy T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Taux de natalit� Decreaser";
				$this->description = "Spy tue une grande quantit� de plan�tes de la population d&#39;une mani�re d�guis�e.";
				$this->success = "Spy Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "die Geburtenrate zu senken";
				$this->description = "Spy t�tet gro�e Mengen des Planeten Bev�lkerung in einer verdeckten Weise.";
				$this->success = "Spy Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Limitatore nascite";
				$this->description = "Spy uccide una grande quantit� di popolazione pianeti in maniera occulta.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Reducir natalidad";
				$this->description = "Spy mata grandes cantidades de la poblaci�n del planeta de manera encubierta.";
				$this->success = "Esp�a de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "P�rqindje e lindjeve Decreaser";
				$this->description = "Spiun vret sasi t� m�dha t� popullsis� planetet n� nj� m�nyr� t� fsheht�.";
				$this->success = "Spiun i pun�s me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Taxa de natalitat decreased";
				$this->description = "Spy mata grans quantitats de la poblaci� del planeta de manera encoberta.";
				$this->success = "Espia d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "F�dselsrate Decreaser";
				$this->description = "Spy dr�ber store m�ngder af planeterne befolkningen i en skjult m�de.";
				$this->success = "Spy Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Geboortecijfer Decreaser";
				$this->description = "Spy doodt grote hoeveelheden van de planeten bevolking in een verkapte manier.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Syntyvyyden Decreaser";
				$this->description = "Spy tappaa suuret m��r�t planeettojen v�est�n peitellyn tavalla.";
				$this->success = "Spy ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kelahiran Decreaser";
				$this->description = "Mata-mata membunuh sejumlah besar penduduk planet cara rahasia.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "F�dselstall Decreaser";
				$this->description = "Spy dreper store mengder av planeter befolkningen p� en skjult m�te.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Natalidade Decreaser";
				$this->description = "Spy mata uma grande quantidade da popula��o planetas de uma forma encoberta.";
				$this->success = "Spy Job alterada com �xito.";
			break;

			case "swedish":
				$this->classname = "F�DELSESIFFRA Decreaser";
				$this->description = "Spy d�dar stora m�ngder av planeterna befolkningen i ett f�rt�ckt s�tt.";
				$this->success = "Spy Job har �ndrats.";
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