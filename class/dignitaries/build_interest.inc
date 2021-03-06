<?php
class build_interest {
	var $id = "2";
	var $dig_interest_max = 0.000005; //Max interest percentage interest dignitaries will make
	var $max_digs = 1;

	function build_interest()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Krediitkaardiga Booster";
				$this->description = "Aukandja veidi suurendab krediidi tootmise kolonistide suurendades moraalne.";
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate j�udis sel planeedil.";
				$this->success = "Aukandja T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Credit Booster";
				$this->description = "Dignitaire augmente l�g�rement la production de cr�dit des colons en augmentant moral.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette plan�te.";
				$this->success = "Dignitaire Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "Credit Booster";
				$this->description = "W�rdentr�ger leicht erh�ht Kredit-Produktion der Kolonisten durch die Erh�hung Moral.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " W�rdentr�ger griff nach diesem Planeten.";
				$this->success = "W�rdentr�ger Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Incrementatore crediti";
				$this->description = "Dignitario aumenta leggermente la produzione di credito dei coloni aumentando morale.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Cr�dito Booster";
				$this->description = "Dignatario ligeramente aumenta la producci�n de cr�dito de los colonos mediante el aumento de moral.";
				$this->toomany = "El n�mero m�ximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Credit Booster";
				$this->description = "Dignitary pak nxit prodhimin e kreditit t� kolonist�t duke rritur morale.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur p�r k�t� planet.";
				$this->success = "Dignitary pun�s sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Cr�dit Booster";
				$this->description = "Dignatari lleugerament augmenta la producci� de cr�dit dels colons mitjan�ant l&#39;augment de moral.";
				$this->toomany = "El nombre m�xim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->success = "Dignatari d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Credit Booster";
				$this->description = "Dignitar lidt �ger kredit produktion af kolonisterne ved at �ge moralsk.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores n�et for denne planet.";
				$this->success = "Dignitar Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Credit Booster";
				$this->description = "Hoogwaardigheidsbekleder verhoogt iets krediet productie van de kolonisten door de verhoging van moraal.";
				$this->toomany = "Maximum aantal " . $this->classname . " Hoogwaardigheidsbekleders bereikt voor deze planeet.";
				$this->success = "Hoogwaardigheidsbekleder Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Luotto Kehua";
				$this->description = "Arvohenkil� hieman parantaa luotto tuotannon siirtolaisten lis��m�ll� moraalista.";
				$this->toomany = "Maksimim��r� " . $this->classname . " Arvohenkil�it� p��stiin t�ll� planeetalla.";
				$this->success = "Arvohenkil� ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kredit Booster";
				$this->description = "Pembesar sedikit meningkatkan produksi kredit dari kolonis dengan meningkatkan moral.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Credit Booster";
				$this->description = "Herre �ker litt kreditt produksjon av kolonistene ved � �ke moralen.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner n�dd for denne planeten.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Cr�dito Booster";
				$this->description = "Dignit�rio ligeiramente impulsiona a produ��o de cr�dito dos colonos, aumentando a moral.";
				$this->toomany = "N�mero m�ximo de " . $this->classname . " Dignit�rios chegou para este planeta.";
				$this->success = "Dignit�rio de trabalho alterado com �xito.";
			break;

			case "swedish":
				$this->classname = "Credit Booster";
				$this->description = "Dignit�r �kar n�got kredit produktion av kolonisterna genom att �ka moralisk.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignit�rer n�tt f�r den h�r planeten.";
				$this->success = "Dignit�r Job har �ndrats.";
			break;

			default:
				$this->classname = "Credit Booster";
				$this->description = "Dignitary slightly boosts credit production of the Colonists by increasing moral.";
				$this->toomany = "Maximum number of " . $this->classname . " Dignitaries reached for this planet.";
				$this->success = "Dignitary Job Successfully Changed.";
			break;
		}
	}

	function sched_process_dignitary()
	{
		global $db, $db_prefix, $multiplier, $colonist_tech_add, $expoprod, $colonist_limit, $organics_consumption, $prate, $credits_prate;

		TextFlush ( "Dignitaries boosting credits<br>");

	    $planetupdate = "UPDATE {$db_prefix}planets as p, {$db_prefix}dignitary as d SET 
					p.credits = p.credits + (((LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * $prate[colonists]) * $credits_prate * ((100.0 - p.prod_organics - p.prod_ore - p.prod_goods - p.prod_energy - p.prod_fighters - p.prod_torp - p.prod_research - p.prod_build) / 100.0) * $expoprod * (pow((d.percent + 1) * 1, $multiplier * 1) - 1)))" .
					"WHERE " .
                    "(p.organics + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $prate[organics] * " .
                    "p.prod_organics / 100.0 * $expoprod) - (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * " .
                    "$organics_consumption * $expoprod) >= 0) AND d.job_id='2' AND d.active='Y' and d.embezzler = 0 and p.planet_id=d.planet_id";

	    $debug_query = $db->Execute($planetupdate);
    	db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();

	}

	function change_dignitary($dig_id, $planet_id, $job_id)
	{
		global $db, $db_prefix, $dig_embezzlerdelay;

		$res = $db->Execute("SELECT dig_id FROM {$db_prefix}dignitary WHERE planet_id=$planet_id and job_id=$job_id ");
    	db_op_result($res,__LINE__,__FILE__);

		if($res->RecordCount() < $this->max_digs)
		{
			$stamp = date("Y-m-d H:i:s");
			$reactive_date = date("Y-m-d H:i:s", strtotime($stamp) + mt_rand(floor($dig_embezzlerdelay * 86400 / 2), $dig_embezzlerdelay * 86400));
			$new_percent = (mt_rand(1, 100) / 100) * $this->dig_interest_max;
			$debug_query = $db->Execute("UPDATE {$db_prefix}dignitary SET percent='$new_percent', job_id='2', active_date='$stamp', reactive_date='$reactive_date' WHERE dig_id=$dig_id ");
			db_op_result($debug_query,__LINE__,__FILE__);
			$debug_query->close();
			return $this->success;
		}
		else
		{
			return $this->toomany;
		}
	}
}

?>