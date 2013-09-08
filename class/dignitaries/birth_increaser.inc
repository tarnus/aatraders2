<?php
class birth_increaser {
	var $id = "4";
	var $dig_birthinc_max="0.00003"; // Max birthrate increase percentage production dignitaries will make
	var $max_digs = 5;

	function birth_increaser()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Sündimus Increaser";
				$this->description = "Aukandja vabastab viljakuse ravimeid planeedid veevarustus suurendada kolonistide sündimus.";
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate jõudis sel planeedil.";
				$this->hit_col_limit = "Liiga paljud kolonistid sündimus Increaser ei saa liigitada.";
				$this->success = "Aukandja Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Taux de natalité MULTIPLICATEUR";
				$this->description = "Dignitaire dispense de fournir des médicaments contre la stérilité des planètes à l&#39;eau pour augmenter le taux de natalité des colons.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette planète.";
				$this->hit_col_limit = "Trop nombreux colons qui augmente la natalité ne peut pas être attribué.";
				$this->success = "Dignitaire Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Geburtenraten steigern";
				$this->description = "Würdenträger verzichtet Fruchtbarkeit Drogen zu den Planeten Wasserversorgung der Kolonisten Geburtenrate zu erhöhen.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " Würdenträger griff nach diesem Planeten.";
				$this->hit_col_limit = "Zu viele Kolonisten Geburtenrate Increaser kann nicht zugeordnet werden.";
				$this->success = "Würdenträger Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Incrementatore nascite";
				$this->description = "Dignitario dispensa farmaci per la fertilità per la fornitura di acqua pianeti per aumentare il tasso di natalità coloni.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->hit_col_limit = "Anche molti coloni di moltiplicatori di tasso di natalità non può essere assegnato.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Tasa de natalidad Increaser";
				$this->description = "Dignatario dispensa fármacos de fertilidad para el suministro de los planetas de agua para aumentar la tasa de natalidad colonos.";
				$this->toomany = "El número máximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->hit_col_limit = "Demasiado colonos muchos Increaser tasa de natalidad no puede ser asignado.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Përqindje e lindjeve Increaser";
				$this->description = "Dignitary dispenses drogë pjellori të furnizimit me planetet e ujit për të rritur normën kolonistët lindjes.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur për këtë planet.";
				$this->hit_col_limit = "Too kolonistët Increaser shumë një përqindje e lindjeve nuk mund të caktohet.";
				$this->success = "Dignitary punës sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Taxa de natalitat increased";
				$this->description = "Dignatari dispensa fàrmacs de fertilitat per al subministrament dels planetes d&#39;aigua per augmentar la taxa de natalitat colons.";
				$this->toomany = "El nombre màxim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->hit_col_limit = "Massa colons molts increased taxa de natalitat no pot ser assignat.";
				$this->success = "Dignatari d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Fødselsrate Increaser";
				$this->description = "Dignitar dispenserer fertilitetsmedicin til planeterne vandforsyningen at øge kolonisterne fødselstal.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores nået for denne planet.";
				$this->hit_col_limit = "Alt for mange kolonister en fødselsrate Increaser kan ikke overdrages.";
				$this->success = "Dignitar Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Geboortecijfer vermeerdering";
				$this->description = "Hoogwaardigheidsbekleder ontslaat vruchtbaarheid drugs aan de planeten watervoorziening ter verhoging van de kolonisten geboortecijfer.";
				$this->toomany = "Maximum aantal " . $this->classname . " Hoogwaardigheidsbekleders bereikt voor deze planeet.";
				$this->hit_col_limit = "Te veel kolonisten een geboortecijfer vermeerdering kan niet worden toegewezen.";
				$this->success = "Hoogwaardigheidsbekleder Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Syntyvyyden Increaser";
				$this->description = "Arvohenkilö annostelee hedelmällisyyttä huumeiden planeettoja vesihuollon lisätä siirtolaiset syntyvyyttä.";
				$this->toomany = "Maksimimäärä " . $this->classname . " Arvohenkilöitä päästiin tällä planeetalla.";
				$this->hit_col_limit = "Liian monet siirtolaiset syntyvyyden Increaser ei voida lukea.";
				$this->success = "Arvohenkilö työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kelahiran Increaser";
				$this->description = "Pembesar kesuburan membagi-bagikan obat-obatan untuk pasokan air planet untuk meningkatkan tingkat kelahiran kolonis.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->hit_col_limit = "Terlalu banyak koloni Increaser sebuah angka kelahiran tidak dapat ditetapkan.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Fødselstall forhøye";
				$this->description = "Herre dispenses fruktbarhet narkotika til planetene vannforsyning til å øke kolonistene fødselsrate.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner nådd for denne planeten.";
				$this->hit_col_limit = "For mange kolonister en fødselstall forhøye kan ikke tilordnes.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Natalidade Increaser";
				$this->description = "Dignitário dispensam medicamentos de fertilidade para o abastecimento de água planetas para aumentar a taxa de natalidade colonos.";
				$this->toomany = "Número máximo de " . $this->classname . " Dignitários chegou para este planeta.";
				$this->hit_col_limit = "Demasiado muitos colonos um Increaser Birthrate não pode ser atribuída.";
				$this->success = "Dignitário de trabalho alterado com êxito.";
			break;

			case "swedish":
				$this->classname = "FÖDELSESIFFRA utbredare";
				$this->description = "Dignitär doserar fertilitetsmediciner till planeterna vattenförsörjningen att öka kolonisterna födelsetalen.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignitärer nått för den här planeten.";
				$this->hit_col_limit = "Alltför många kolonister en FÖDELSESIFFRA utbredare kan inte tilldelas.";
				$this->success = "Dignitär Job har ändrats.";
			break;

			default:
				$this->classname = "Birthrate Increaser";
				$this->description = "Dignitary dispenses fertility drugs to the planets water supply to increase the colonists birth rate.";
				$this->toomany = "Maximum number of " . $this->classname . " Dignitaries reached for this planet.";
				$this->hit_col_limit = "Too many colonists a Birthrate Increaser can't be assigned.";
				$this->success = "Dignitary Job Successfully Changed.";
			break;
		}
	}

	function sched_process_dignitary()
	{
		global $db, $db_prefix, $multiplier, $colonist_tech_add, $expoprod, $colonist_limit, $organics_consumption, $prate;

		TextFlush ( "Dignitaries increasing birthrate<br>");

	    $planetupdate = "UPDATE {$db_prefix}planets as p, {$db_prefix}dignitary as d SET 
    				p.colonists= LEAST((p.colonists + (p.colonists * ((pow((d.percent + 1) * 1, $multiplier * 1) - 1) * (1 - (p.colonists / ($colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7)))))) * $expoprod)), $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) " .
					"WHERE " .
                    "(p.organics + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $prate[organics] * " .
                    "p.prod_organics / 100.0 * $expoprod) - (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * " .
                    "$organics_consumption * $expoprod) >= 0) AND d.job_id='4' AND d.active='Y' and d.embezzler = 0 and p.planet_id=d.planet_id";

	    $debug_query = $db->Execute($planetupdate);
    	db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}

	function change_dignitary($dig_id, $planet_id, $job_id)
	{
		global $db, $db_prefix, $dig_embezzlerdelay, $colonist_limit;

		$res = $db->Execute("SELECT dig_id FROM {$db_prefix}dignitary WHERE planet_id=$planet_id and job_id=$job_id ");
    	db_op_result($res,__LINE__,__FILE__);

		if($res->RecordCount() < $this->max_digs)
		{
			$stamp = date("Y-m-d H:i:s");
			$reactive_date = date("Y-m-d H:i:s", strtotime($stamp) + mt_rand(floor($dig_embezzlerdelay * 86400 / 2), $dig_embezzlerdelay * 86400));
			$doom_query = $db->SelectLimit("SELECT colonists from {$db_prefix}planets WHERE planet_id=$planet_id", 1);
	    	db_op_result($doom_query,__LINE__,__FILE__);
			$doomcheck = $doom_query->fields;
			$doom_query->close();
			if($doomcheck['colonists'] < ($colonist_limit*0.5))
			{
				$new_percent = (mt_rand(1, 100) / 100) * $this->dig_birthinc_max;
  				$debug_query = $db->Execute("UPDATE {$db_prefix}dignitary SET percent='$new_percent', job_id='4', active_date='$stamp', reactive_date='$reactive_date' WHERE dig_id=$dig_id ");
		   		db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
				return $this->success;
			}
			else
			{
				return $this->hit_col_limit;
			}
		}
		else
		{
			return $this->toomany;
		}
	}
}

?>