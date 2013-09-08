<?php
class destroy_credits {
	var $id = "2";
	var $singlepass = 1;

	function destroy_credits()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Destroy Autorid";
				$this->description = "Spy on õhkima suurte pankade ja finantsasutuste intitutions põhjustab suurel hulgal krediite kaduma.";
				$this->success = "Spy Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Destroy Crédits";
				$this->description = "Spy fera sauter les grandes banques et intitutions financières causant d&#39;énormes quantités de crédits à perdre.";
				$this->success = "Spy Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Destroy Credits";
				$this->description = "Spion wird die Luft sprengen großen Banken und Finanzdienstleister intitutions verursacht große Mengen an Credits zu verlieren.";
				$this->success = "Spy Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Destroy Credits";
				$this->description = "Spy saltare in aria le principali banche e istituzioni di finanziari causando enormi quantità di crediti da perdere.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Créditos Destroy";
				$this->description = "Spy hará saltar los principales bancos y financieras instituiciones causando enormes cantidades de créditos que se pierde.";
				$this->success = "Espía de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Destroy Kredite";
				$this->description = "Spiun do të hedhur në erë e bankave të mëdha dhe intitutions financiare duke shkaktuar shuma masive të kredive të jenë të humbura.";
				$this->success = "Spiun i punës me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Crèdits Destroy";
				$this->description = "Spy farà saltar els principals bancs i financeres instituiciones causant enormes quantitats de crèdits que es perd.";
				$this->success = "Espia d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Destroy Credits";
				$this->description = "Spy vil sprænge store banker og finansielle intitutions massive mængder af kreditter til at være tabt.";
				$this->success = "Spy Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Destroy Credits";
				$this->description = "Spy zullen opblazen grote banken en financiële intitutions waardoor enorme hoeveelheden kredieten verloren.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Destroy Laajuus";
				$this->description = "Spy on räjäyttää johtavien pankkien ja rahoituslaitosten intitutions aiheuttaa valtavia määriä hyvityksiä menetetään.";
				$this->success = "Spy työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Hancurkan Credits";
				$this->description = "Mata-mata akan meledakkan bank-bank besar dan intitutions keuangan menyebabkan sejumlah besar kredit yang akan hilang.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Destroy Credits";
				$this->description = "Spy vil blåse opp store banker og finansielle intitutions forårsaker enorme mengder kreditt for å være tapt.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Destroy Créditos";
				$this->description = "Spy irá explodir os principais bancos e financeiras intitutions causando enormes quantidades de créditos para ser perdida.";
				$this->success = "Spy Job alterada com êxito.";
			break;

			case "swedish":
				$this->classname = "Destroy Credits";
				$this->description = "Spy kommer att blåsa upp stora banker och finansiella intitutions orsakar enorma mängder krediter som förlorat.";
				$this->success = "Spy Job har ändrats.";
			break;

			default:
				$this->classname = "Destroy Credits";
				$this->description = "Spy will blow up major banks and financial intitutions causing massive amounts of credits to be lost.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier;

		TextFlush ( "Spies Destroying Credits<br>");

		$query = $db->Execute("UPDATE {$db_prefix}planets as p, {$db_prefix}spies as s SET " .
									"p.credits=GREATEST(p.credits-(p.credits * ($multiplier * s.spy_percent)), 0)
									WHERE s.job_id='2' AND s.active='Y' and p.planet_id=s.planet_id");
		db_op_result($query,__LINE__,__FILE__);
		$query->close();
	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix;

		$r1 = $db->Execute("SELECT SUM(spy_percent) as i_total FROM {$db_prefix}spies WHERE active='Y' AND planet_id=$planet_id AND job_id='2' ");
		$total = $r1->fields['i_total'];
		$r1->close();
		$total = floor(("1.0003" - $total - 1) * 30000);
		$new_percent = myrand(floor($total * 0.15), floor($total * 0.35), 1.3);	//15%...35%
		$new_percent /= 30000.0;
		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='$new_percent', job_id='2' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>