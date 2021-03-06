<?php
class birth_decreaser {
	var $id = "3";
	var $colonist_lower_limit = 100000; //This is the lowest Birthrate reducer digs will drop a planets population.
	var $dig_birthdec_max="0.00005"; // Max birthrate reduction percentage production dignitaries will make
	var $max_digs = 5;

	function birth_decreaser()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "S�ndimus Decreaser";
				$this->description = "Aukandja vabastab kohustuslik rasestumisvastaseid elanikkonnale v�hendada planeetide s�ndimus.";
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate j�udis sel planeedil.";
				$this->toofewcolonists = "Planeet on liiga v�he kolonistide jaoks s�ndimus Decreaser.";
				$this->success = "Aukandja T�� edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Taux de natalit� Decreaser";
				$this->description = "Dispense Dignitaire contraception obligatoire � la population pour r�duire le taux de natalit� de la plan�te.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette plan�te.";
				$this->toofewcolonists = "Planet a colons trop peu pour un Decreaser natalit�.";
				$this->success = "Dignitaire Job chang� avec succ�s.";
			break;

			case "german":
				$this->classname = "Geburtenraten abschw�chen";
				$this->description = "W�rdentr�ger verzichtet obligatorischen Empf�ngnisverh�tung, um die Bev�lkerung zur Verringerung der planetaren Geburtenrate.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " W�rdentr�ger griff nach diesem Planeten.";
				$this->toofewcolonists = "Planet hat zu wenige Kolonisten f�r eine Geburtenrate Decreaser.";
				$this->success = "W�rdentr�ger Job erfolgreich ge�ndert.";
			break;

			case "italian":
				$this->classname = "Limitatore nascite";
				$this->description = "Dispensa Dignitary contraccezione obbligatoria per la popolazione a ridurre il tasso di natalit� planetaria.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->toofewcolonists = "Pianeta ha coloni troppo pochi per un Decreaser tasso di natalit�.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Tasa de natalidad Decreaser";
				$this->description = "Dispensa dignatario anticoncepci�n obligatoria a la poblaci�n para reducir la tasa de natalidad del planeta.";
				$this->toomany = "El n�mero m�ximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->toofewcolonists = "Planet ha colonos muy pocos para un Decreaser tasa de natalidad.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "P�rqindje e lindjeve Decreaser";
				$this->description = "Dispenses Dignitary kontraceptiv t� detyrueshme p�r t� popullsis� p�r t� ulur norm�n planetar lindjes.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur p�r k�t� planet.";
				$this->toofewcolonists = "Planet ka kolonist�t shum� pak p�r nj� Decreaser p�rqindje e lindjeve.";
				$this->success = "Dignitary pun�s sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Taxa de natalitat decreased";
				$this->description = "Dispensa dignatari anticoncepci� obligat�ria a la poblaci� per reduir la taxa de natalitat del planeta.";
				$this->toomany = "El nombre m�xim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->toofewcolonists = "Planet ha colons molt pocs per a un decreased taxa de natalitat.";
				$this->success = "Dignatari d&#39;ocupaci� han canviat correctament.";
			break;

			case "danish":
				$this->classname = "F�dselsrate Decreaser";
				$this->description = "Dignitar dispenserer obligatorisk pr�vention til befolkningen om at reducere den planetariske f�dselstal.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores n�et for denne planet.";
				$this->toofewcolonists = "Planet har for f� kolonister for en f�dselsrate Decreaser.";
				$this->success = "Dignitar Job blevet �ndret.";
			break;

			case "dutch":
				$this->classname = "Geboortecijfer Decreaser";
				$this->description = "Hoogwaardigheidsbekleder ontslaat verplichte anticonceptie voor de bevolking om de planetaire geboortecijfer.";
				$this->toomany = "Maximum aantal " . $this->classname . " Hoogwaardigheidsbekleders bereikt voor deze planeet.";
				$this->toofewcolonists = "Planet heeft te weinig kolonisten voor een geboortecijfer Decreaser.";
				$this->success = "Hoogwaardigheidsbekleder Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Syntyvyyden Decreaser";
				$this->description = "Arvohenkil� annostelee pakollisia ehk�isy� ja v�est�n v�hent�� planeettojen syntyvyys.";
				$this->toomany = "Maksimim��r� " . $this->classname . " Arvohenkil�it� p��stiin t�ll� planeetalla.";
				$this->toofewcolonists = "Planet on liian v�h�n siirtolaiset ja syntyvyyden Decreaser.";
				$this->success = "Arvohenkil� ty� onnistui.";
			break;

			case "indonesian":
				$this->classname = "Kelahiran Decreaser";
				$this->description = "Membagikan pembesar wajib kontrasepsi kepada penduduk untuk mengurangi tingkat kelahiran planet.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->toofewcolonists = "Planet memiliki terlalu sedikit koloni untuk Decreaser angka kelahiran.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "F�dselstall Decreaser";
				$this->description = "Herre dispenses obligatorisk prevensjon til befolkningen for � redusere den planetariske f�dselsrate.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner n�dd for denne planeten.";
				$this->toofewcolonists = "Planet har for f� kolonistene for et f�dselstall Decreaser.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Natalidade Decreaser";
				$this->description = "Dispensa Dignit�rio contracep��o obrigat�ria � popula��o para reduzir a taxa de natalidade do planeta.";
				$this->toomany = "N�mero m�ximo de " . $this->classname . " Dignit�rios chegou para este planeta.";
				$this->toofewcolonists = "Colonos planeta tem muito poucos para uma Decreaser natalidade.";
				$this->success = "Dignit�rio de trabalho alterado com �xito.";
			break;

			case "swedish":
				$this->classname = "F�DELSESIFFRA Decreaser";
				$this->description = "Dignit�r doserar obligatoriska preventivmedel till befolkningen att minska de planetariska f�delsetalen.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignit�rer n�tt f�r den h�r planeten.";
				$this->toofewcolonists = "Planet har alltf�r f� kolonisat�rer f�r ett F�DELSESIFFRA Decreaser.";
				$this->success = "Dignit�r Job har �ndrats.";
			break;

			default:
				$this->classname = "Birthrate Decreaser";
				$this->description = "Dignitary dispenses mandatory contraception to the population to reduce the planetary birth rate.";
				$this->toomany = "Maximum number of " . $this->classname . " Dignitaries reached for this planet.";
				$this->toofewcolonists = "Planet has too few colonists for a Birthrate Decreaser.";
				$this->success = "Dignitary Job Successfully Changed.";
			break;
		}
	}

	function sched_process_dignitary()
	{
		global $db, $db_prefix, $multiplier, $colonist_tech_add, $expoprod, $colonist_limit, $organics_consumption, $prate;

		TextFlush ( "Dignitaries decreasing birthrate<br>");

	    $planetupdate = "UPDATE {$db_prefix}planets as p, {$db_prefix}dignitary as d SET 
    				p.colonists= p.colonists - IF((p.colonists - (p.colonists * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $expoprod)) < " . $this->colonist_lower_limit . ", 0, (p.colonists * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $expoprod)) " .
					"WHERE " .
                    "(p.organics + (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * $prate[organics] * " .
                    "p.prod_organics / 100.0 * $expoprod) - (LEAST(p.colonists, $colonist_limit + ($colonist_tech_add * ((p.fighter + p.sensors + p.beams + p.torp_launchers + p.shields + p.jammer + p.cloak) / 7))) * (pow((d.percent + 1) * 1, $multiplier * 1) - 1) * " .
                    "$organics_consumption * $expoprod) >= 0) AND d.job_id='3' AND d.active='Y' and d.embezzler = 0 and p.planet_id=d.planet_id";

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
	  		$doomcheck = $doom_query->fields;
			$doom_query->close();
			if($doomcheck['colonists'] > ($colonist_limit*0.5)){
				$new_percent = (mt_rand(1, 100) / 100) * $this->dig_birthdec_max;

				$debug_query = $db->Execute("UPDATE {$db_prefix}dignitary SET percent='$new_percent', job_id='3', active_date='$stamp', reactive_date='$reactive_date' WHERE dig_id=$dig_id ");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
				return $this->success;
			}
			else
			{
				return $this->toofewcolonists;
			}
		}
		else
		{
			return $this->toomany;
		}
	}
}

?>