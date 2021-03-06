<?php
class production_builder {
	var $id = "1";
	var $dig_prod_max="0.000007"; // Max production percentage production dignitaries will make
	var $max_digs = 1;

	function production_builder()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Tootmine Ehitaja";
				$this->description = "Aukandja veidi suurendab kauba tootmise efektiivsust kolonistide poolt suurendada nende moraalne.";
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate j�udis sel planeedil.";
				$this->success = "Aukandja T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Production Builder";
				$this->description = "Dignitaire augmente l�g�rement l&#39;efficacit� de la production marchande des colons par le renforcement de leur moral.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette plan�te.";
				$this->success = "Dignitaire Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "Produktions-Meister";
				$this->description = "W�rdentr�ger leicht erh�ht Warenproduktion Wirksamkeit der Kolonisten durch die F�rderung ihrer Moral.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " W�rdentr�ger griff nach diesem Planeten.";
				$this->success = "W�rdentr�ger Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Produzione Builder";
				$this->description = "Dignitario aumenta lievemente l&#39;efficacia della produzione delle materie prime dei coloni da potenziare la loro morale.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Producci�n Builder";
				$this->description = "Dignatario aumenta ligeramente la eficacia de la producci�n de los productos b�sicos de los colonos por aumentar su moral.";
				$this->toomany = "El n�mero m�ximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Prodhimi Builder";
				$this->description = "Dignitary pak rrit efikasitetin e prodhimit mall e kolonist�t me rritjen e morale e tyre.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur p�r k�t� planet.";
				$this->success = "Dignitary pun�s sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Producci� Builder";
				$this->description = "Dignatari augmenta lleugerament l&#39;efic�cia de la producci� dels productes b�sics dels colons per augmentar la seva moral.";
				$this->toomany = "El nombre m�xim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->success = "Dignatari d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Produktion Builder";
				$this->description = "Dignitar lidt stigninger vareproduktion effektiviteten af kolonisterne ved at styrke deres moralske.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores n�et for denne planet.";
				$this->success = "Dignitar Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Productie Builder";
				$this->description = "Hoogwaardigheidsbekleder neemt iets warenproductie effectiviteit van de kolonisten door het stimuleren van hun morele.";
				$this->toomany = "Maximum aantal " . $this->classname . " Hoogwaardigheidsbekleders bereikt voor deze planeet.";
				$this->success = "Hoogwaardigheidsbekleder Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Tuotanto Builder";
				$this->description = "Arvohenkil� hieman lis�� hy�dykkeiden tuotannon tehokkuutta siirtolaisten lis��m�ll� niiden moraalista.";
				$this->toomany = "Maksimim��r� " . $this->classname . " Arvohenkil�it� p��stiin t�ll� planeetalla.";
				$this->success = "Arvohenkil� ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Produksi Builder";
				$this->description = "Pembesar sedikit meningkatkan produksi komoditas efektivitas dari kolonis dengan meningkatkan moral mereka.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Produksjon Builder";
				$this->description = "Herre �ker litt vare produksjonen effektiviteten av kolonistene ved � forsterke deres moralske.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner n�dd for denne planeten.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Produ��o Builder";
				$this->description = "Dignit�rio aumenta ligeiramente a efic�cia da produ��o de commodities dos colonizadores, aumentando a sua moral.";
				$this->toomany = "N�mero m�ximo de " . $this->classname . " Dignit�rios chegou para este planeta.";
				$this->success = "Dignit�rio de trabalho alterado com �xito.";
			break;

			case "swedish":
				$this->classname = "Produktion Builder";
				$this->description = "Dignit�r �kar n�got effektivt varuproduktionen av kolonisterna genom att �ka deras moral.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignit�rer n�tt f�r den h�r planeten.";
				$this->success = "Dignit�r Job har �ndrats.";
			break;

			default:
				$this->classname = "Production Builder";
				$this->description = "Dignitary slightly increases commodity production effectiveness of the Colonists by boosting their moral.  ";
				$this->toomany = "Maximum number of " . $this->classname . " Dignitaries reached for this planet.";
				$this->success = "Dignitary Job Successfully Changed.";
			break;
		}
	}

	function sched_process_dignitary()
	{
		global $db, $db_prefix, $multiplier, $colonist_tech_add, $expoprod, $colonist_limit, $organics_consumption, $prate;

		TextFlush ( "Dignitaries increasing production<br>");

	    $planetupdate = "UPDATE {$db_prefix}planets as p, {$db_prefix}dignitary as d SET 
					p.organics=GREATEST(p.organics + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $prate[organics] * prod_organics / 100.0 * $expoprod) - (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $organics_consumption * $expoprod), 0), 
				    p.ore=p.ore + ((LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1)) * $prate[ore] * p.prod_ore / 100.0 * $expoprod), 
					p.goods=p.goods + ((LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1)) * $prate[goods] * p.prod_goods / 100.0 * $expoprod), 
					p.energy=p.energy + ((LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1)) * $prate[energy] * p.prod_energy / 100.0 * $expoprod), 
					p.fighters=p.fighters + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1)) * $prate[Planet_Fighter] * p.prod_fighters / 100.0 * $expoprod, 
					p.torps=p.torps + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1)) * $prate[Planet_Torpedo] * p.prod_torp / 100.0 * $expoprod" .
					"WHERE " .
                    "(p.organics + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $prate[organics] * " .
                    "p.prod_organics / 100.0 * $expoprod) - (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * " .
                    "$organics_consumption * $expoprod) >= 0) AND d.job_id='1' AND d.active='Y' and d.embezzler = 0 and p.planet_id=d.planet_id";

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
			$new_percent = (mt_rand(1, 100) / 100) * $this->dig_prod_max;

			$debug_query = $db->Execute("UPDATE {$db_prefix}dignitary SET percent='$new_percent', job_id='1', active_date='$stamp', reactive_date='$reactive_date' WHERE dig_id=$dig_id ");
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