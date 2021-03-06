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
				$this->classname = "S�ndimus Increaser";
				$this->description = "Aukandja vabastab viljakuse ravimeid planeedid veevarustus suurendada kolonistide s�ndimus.";
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate j�udis sel planeedil.";
				$this->hit_col_limit = "Liiga paljud kolonistid s�ndimus Increaser ei saa liigitada.";
				$this->success = "Aukandja T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Taux de natalit� MULTIPLICATEUR";
				$this->description = "Dignitaire dispense de fournir des m�dicaments contre la st�rilit� des plan�tes � l&#39;eau pour augmenter le taux de natalit� des colons.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette plan�te.";
				$this->hit_col_limit = "Trop nombreux colons qui augmente la natalit� ne peut pas �tre attribu�.";
				$this->success = "Dignitaire Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "Geburtenraten steigern";
				$this->description = "W�rdentr�ger verzichtet Fruchtbarkeit Drogen zu den Planeten Wasserversorgung der Kolonisten Geburtenrate zu erh�hen.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " W�rdentr�ger griff nach diesem Planeten.";
				$this->hit_col_limit = "Zu viele Kolonisten Geburtenrate Increaser kann nicht zugeordnet werden.";
				$this->success = "W�rdentr�ger Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Incrementatore nascite";
				$this->description = "Dignitario dispensa farmaci per la fertilit� per la fornitura di acqua pianeti per aumentare il tasso di natalit� coloni.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->hit_col_limit = "Anche molti coloni di moltiplicatori di tasso di natalit� non pu� essere assegnato.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Tasa de natalidad Increaser";
				$this->description = "Dignatario dispensa f�rmacos de fertilidad para el suministro de los planetas de agua para aumentar la tasa de natalidad colonos.";
				$this->toomany = "El n�mero m�ximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->hit_col_limit = "Demasiado colonos muchos Increaser tasa de natalidad no puede ser asignado.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "P�rqindje e lindjeve Increaser";
				$this->description = "Dignitary dispenses drog� pjellori t� furnizimit me planetet e ujit p�r t� rritur norm�n kolonist�t lindjes.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur p�r k�t� planet.";
				$this->hit_col_limit = "Too kolonist�t Increaser shum� nj� p�rqindje e lindjeve nuk mund t� caktohet.";
				$this->success = "Dignitary pun�s sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Taxa de natalitat increased";
				$this->description = "Dignatari dispensa f�rmacs de fertilitat per al subministrament dels planetes d&#39;aigua per augmentar la taxa de natalitat colons.";
				$this->toomany = "El nombre m�xim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->hit_col_limit = "Massa colons molts increased taxa de natalitat no pot ser assignat.";
				$this->success = "Dignatari d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "F�dselsrate Increaser";
				$this->description = "Dignitar dispenserer fertilitetsmedicin til planeterne vandforsyningen at �ge kolonisterne f�dselstal.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores n�et for denne planet.";
				$this->hit_col_limit = "Alt for mange kolonister en f�dselsrate Increaser kan ikke overdrages.";
				$this->success = "Dignitar Job blevet �ndret.";
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
				$this->description = "Arvohenkil� annostelee hedelm�llisyytt� huumeiden planeettoja vesihuollon lis�t� siirtolaiset syntyvyytt�.";
				$this->toomany = "Maksimim��r� " . $this->classname . " Arvohenkil�it� p��stiin t�ll� planeetalla.";
				$this->hit_col_limit = "Liian monet siirtolaiset syntyvyyden Increaser ei voida lukea.";
				$this->success = "Arvohenkil� ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kelahiran Increaser";
				$this->description = "Pembesar kesuburan membagi-bagikan obat-obatan untuk pasokan air planet untuk meningkatkan tingkat kelahiran kolonis.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->hit_col_limit = "Terlalu banyak koloni Increaser sebuah angka kelahiran tidak dapat ditetapkan.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "F�dselstall forh�ye";
				$this->description = "Herre dispenses fruktbarhet narkotika til planetene vannforsyning til � �ke kolonistene f�dselsrate.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner n�dd for denne planeten.";
				$this->hit_col_limit = "For mange kolonister en f�dselstall forh�ye kan ikke tilordnes.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Natalidade Increaser";
				$this->description = "Dignit�rio dispensam medicamentos de fertilidade para o abastecimento de �gua planetas para aumentar a taxa de natalidade colonos.";
				$this->toomany = "N�mero m�ximo de " . $this->classname . " Dignit�rios chegou para este planeta.";
				$this->hit_col_limit = "Demasiado muitos colonos um Increaser Birthrate n�o pode ser atribu�da.";
				$this->success = "Dignit�rio de trabalho alterado com �xito.";
			break;

			case "swedish":
				$this->classname = "F�DELSESIFFRA utbredare";
				$this->description = "Dignit�r doserar fertilitetsmediciner till planeterna vattenf�rs�rjningen att �ka kolonisterna f�delsetalen.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignit�rer n�tt f�r den h�r planeten.";
				$this->hit_col_limit = "Alltf�r m�nga kolonister en F�DELSESIFFRA utbredare kan inte tilldelas.";
				$this->success = "Dignit�r Job har �ndrats.";
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