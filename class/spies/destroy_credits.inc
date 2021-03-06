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
				$this->description = "Spy on �hkima suurte pankade ja finantsasutuste intitutions p�hjustab suurel hulgal krediite kaduma.";
				$this->success = "Spy T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Destroy Cr�dits";
				$this->description = "Spy fera sauter les grandes banques et intitutions financi�res causant d&#39;�normes quantit�s de cr�dits � perdre.";
				$this->success = "Spy Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "Destroy Credits";
				$this->description = "Spion wird die Luft sprengen gro�en Banken und Finanzdienstleister intitutions verursacht gro�e Mengen an Credits zu verlieren.";
				$this->success = "Spy Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Destroy Credits";
				$this->description = "Spy saltare in aria le principali banche e istituzioni di finanziari causando enormi quantit� di crediti da perdere.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Cr�ditos Destroy";
				$this->description = "Spy har� saltar los principales bancos y financieras instituiciones causando enormes cantidades de cr�ditos que se pierde.";
				$this->success = "Esp�a de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Destroy Kredite";
				$this->description = "Spiun do t� hedhur n� er� e bankave t� m�dha dhe intitutions financiare duke shkaktuar shuma masive t� kredive t� jen� t� humbura.";
				$this->success = "Spiun i pun�s me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Cr�dits Destroy";
				$this->description = "Spy far� saltar els principals bancs i financeres instituiciones causant enormes quantitats de cr�dits que es perd.";
				$this->success = "Espia d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Destroy Credits";
				$this->description = "Spy vil spr�nge store banker og finansielle intitutions massive m�ngder af kreditter til at v�re tabt.";
				$this->success = "Spy Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Destroy Credits";
				$this->description = "Spy zullen opblazen grote banken en financi�le intitutions waardoor enorme hoeveelheden kredieten verloren.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Destroy Laajuus";
				$this->description = "Spy on r�j�ytt�� johtavien pankkien ja rahoituslaitosten intitutions aiheuttaa valtavia m��ri� hyvityksi� menetet��n.";
				$this->success = "Spy ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Hancurkan Credits";
				$this->description = "Mata-mata akan meledakkan bank-bank besar dan intitutions keuangan menyebabkan sejumlah besar kredit yang akan hilang.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Destroy Credits";
				$this->description = "Spy vil bl�se opp store banker og finansielle intitutions for�rsaker enorme mengder kreditt for � v�re tapt.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Destroy Cr�ditos";
				$this->description = "Spy ir� explodir os principais bancos e financeiras intitutions causando enormes quantidades de cr�ditos para ser perdida.";
				$this->success = "Spy Job alterada com �xito.";
			break;

			case "swedish":
				$this->classname = "Destroy Credits";
				$this->description = "Spy kommer att bl�sa upp stora banker och finansiella intitutions orsakar enorma m�ngder krediter som f�rlorat.";
				$this->success = "Spy Job har �ndrats.";
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