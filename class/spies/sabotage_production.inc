<?php
class sabotage_production {
	var $id = "1";
	var $singlepass = 1;

	function sabotage_production()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "saboteerida tootlust";
				$this->description = "Spy sabotages kõigi planeetide tootmine, välja arvatud krediidi tootmiseks.";
				$this->success = "Spy Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Sabotage de la production";
				$this->description = "Spy sabote toute la production planétaire, sauf pour la production de crédit.";
				$this->success = "Spy Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Sabotage zu betreiben";
				$this->description = "Spy sabotiert alle Planeten-Produktion mit Ausnahme der Kredit-Produktion.";
				$this->success = "Spy Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Sabotare la produzione";
				$this->description = "Spy sabotaggi tutta la produzione planetaria, tranne per la produzione di credito.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Sabotear la producción";
				$this->description = "Spy sabotea toda la producción planetaria, excepto para la producción de crédito.";
				$this->success = "Espía de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Sabotim Prodhimi";
				$this->description = "Spiun sabotages gjithë prodhimin e planetare përveç për prodhimin e kreditit.";
				$this->success = "Spiun i punës me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Sabotejar la producció";
				$this->description = "Spy saboteja tota la producció planetària, excepte per a la producció de crèdit.";
				$this->success = "Espia d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Sabotage Produktion";
				$this->description = "Spy saboterer alle planeternes produktion bortset fra kredit produktion.";
				$this->success = "Spy Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Sabotage Productie";
				$this->description = "Spy saboteert alle planetaire productie behalve voor krediet productie.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Tuhotyö Tuotanto";
				$this->description = "Spy sabotages kaikki planeettojen tuotanto paitsi luotto tuotantoon.";
				$this->success = "Spy työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Sabotase Produksi";
				$this->description = "Spy produksi menyabot semua planet kecuali untuk kredit produksi.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Sabotasje Production";
				$this->description = "Spy sabotages alle planetenes produksjon unntak for kreditt produksjon.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Sabotage Produção";
				$this->description = "Spy sabota toda a produção planetária, exceto para a produção de crédito.";
				$this->success = "Spy Job alterada com êxito.";
			break;

			case "swedish":
				$this->classname = "Sabotage Production";
				$this->description = "Spy saboterar alla planetväxlar produktion utom för kredit produktion.";
				$this->success = "Spy Job har ändrats.";
			break;

			default:
				$this->classname = "Sabotage Production";
				$this->description = "Spy sabotages all planetary production except for credit production.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier, $spy;

		TextFlush ( "Spies Sabotaging Planet Production<br>");

		$query = $db->Execute("UPDATE {$db_prefix}planets as p, {$db_prefix}spies as s SET p.organics=GREATEST(p.organics-(p.organics * ($multiplier * s.spy_percent)), 0), " .
									"p.ore=GREATEST(p.ore-(p.ore * ($multiplier * s.spy_percent)), 0), 
									 p.goods=GREATEST(p.goods-(p.goods * ($multiplier * s.spy_percent)), 0), 
									 p.energy=GREATEST(p.energy-(p.energy * ($multiplier * s.spy_percent)), 0), " .
									"p.torps=GREATEST(p.torps-(p.torps * ($multiplier * s.spy_percent)), 0), " .
									"p.fighters=GREATEST(p.fighters-(p.fighters * ($multiplier * s.spy_percent)), 0)
									WHERE s.job_id='1' AND s.active='Y' and p.planet_id=s.planet_id");
		db_op_result($query,__LINE__,__FILE__);
		$query->close();
	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix;

		$r1 = $db->Execute("SELECT SUM(spy_percent) as s_total FROM {$db_prefix}spies WHERE active='Y' AND planet_id=$planet_id AND job_id='1' ");
		$total = $r1->fields['s_total'];
		$r1->close();

		$r1 = $db->Execute("SELECT prate FROM {$db_prefix}class_modules_commodities WHERE class='colonists' ");
		$colonist_production_rate = $r1->fields['prate'];
		$r1->close();

		$total = floor(($colonist_production_rate - $total) * 30000);
		$new_percent = myrand(floor($total * 0.1), floor($total * 0.3), 1.3);	//10%...30%
		$new_percent /= 30000.0;
		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='$new_percent', job_id='1' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>