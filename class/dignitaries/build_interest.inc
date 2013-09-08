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
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate jõudis sel planeedil.";
				$this->success = "Aukandja Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Credit Booster";
				$this->description = "Dignitaire augmente légèrement la production de crédit des colons en augmentant moral.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette planète.";
				$this->success = "Dignitaire Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Credit Booster";
				$this->description = "Würdenträger leicht erhöht Kredit-Produktion der Kolonisten durch die Erhöhung Moral.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " Würdenträger griff nach diesem Planeten.";
				$this->success = "Würdenträger Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Incrementatore crediti";
				$this->description = "Dignitario aumenta leggermente la produzione di credito dei coloni aumentando morale.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Crédito Booster";
				$this->description = "Dignatario ligeramente aumenta la producción de crédito de los colonos mediante el aumento de moral.";
				$this->toomany = "El número máximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Credit Booster";
				$this->description = "Dignitary pak nxit prodhimin e kreditit të kolonistët duke rritur morale.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur për këtë planet.";
				$this->success = "Dignitary punës sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Crèdit Booster";
				$this->description = "Dignatari lleugerament augmenta la producció de crèdit dels colons mitjançant l&#39;augment de moral.";
				$this->toomany = "El nombre màxim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->success = "Dignatari d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Credit Booster";
				$this->description = "Dignitar lidt øger kredit produktion af kolonisterne ved at øge moralsk.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores nået for denne planet.";
				$this->success = "Dignitar Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Credit Booster";
				$this->description = "Hoogwaardigheidsbekleder verhoogt iets krediet productie van de kolonisten door de verhoging van moraal.";
				$this->toomany = "Maximum aantal " . $this->classname . " Hoogwaardigheidsbekleders bereikt voor deze planeet.";
				$this->success = "Hoogwaardigheidsbekleder Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Luotto Kehua";
				$this->description = "Arvohenkilö hieman parantaa luotto tuotannon siirtolaisten lisäämällä moraalista.";
				$this->toomany = "Maksimimäärä " . $this->classname . " Arvohenkilöitä päästiin tällä planeetalla.";
				$this->success = "Arvohenkilö työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kredit Booster";
				$this->description = "Pembesar sedikit meningkatkan produksi kredit dari kolonis dengan meningkatkan moral.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Credit Booster";
				$this->description = "Herre øker litt kreditt produksjon av kolonistene ved å øke moralen.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner nådd for denne planeten.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Crédito Booster";
				$this->description = "Dignitário ligeiramente impulsiona a produção de crédito dos colonos, aumentando a moral.";
				$this->toomany = "Número máximo de " . $this->classname . " Dignitários chegou para este planeta.";
				$this->success = "Dignitário de trabalho alterado com êxito.";
			break;

			case "swedish":
				$this->classname = "Credit Booster";
				$this->description = "Dignitär ökar något kredit produktion av kolonisterna genom att öka moralisk.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignitärer nått för den här planeten.";
				$this->success = "Dignitär Job har ändrats.";
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