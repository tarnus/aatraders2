<?php
class spy_hunter {
	var $id = "5";
	var $dig_spyhunter_max="0.00100"; // Max spy hunter effectiveness percentage production dignitaries will make
	var $max_digs = 5;

	function spy_hunter()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Spy Hunter";
				$this->description = "Aukandja jahipidamine jaoks vaenlase spioone ja tapab neid. Veel jahimehed on tõhusam leidmisel spioonid.";
				$this->toomany = "Maksimaalne arv " . $this->classname . " Aukandjate jõudis sel planeedil.";
				$this->success = "Aukandja Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Spy Hunter";
				$this->description = "Dignitaire cherche les espions ennemis et les tue. Plus de chasseurs sont plus efficaces dans la recherche d&#39;espions.";
				$this->toomany = "Nombre maximal de " . $this->classname . " Dignitaires atteint pour cette planète.";
				$this->success = "Dignitaire Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Spionen-Jagd";
				$this->description = "Würdenträger Jagd nach feindlichen Spionen und tötet sie. Weitere Jäger sind effektiver bei der Suche nach Spionen.";
				$this->toomany = "Maximale Anzahl der " . $this->classname . " Würdenträger griff nach diesem Planeten.";
				$this->success = "Würdenträger Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Cacciatore di spie";
				$this->description = "Dignitario a caccia di spie nemiche e li uccide. Più cacciatori sono più efficaci nella ricerca di spie.";
				$this->toomany = "Numero massimo di " . $this->classname . " Dignitari raggiunto per questo pianeta.";
				$this->success = "Dignitario di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Spy Hunter";
				$this->description = "Dignatario de la caza de espías enemigos y los mata. Más cazadores son más eficaces en la búsqueda de espías.";
				$this->toomany = "El número máximo de " . $this->classname . " Dignatarios alcanzado para este planeta.";
				$this->success = "Dignatario de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Spy Hunter";
				$this->description = "Dignitary gjuan për spiunë dhe e vret armikun e tyre. Më shumë janë gjuetarët më të efektshëm në gjetjen e spiunë.";
				$this->toomany = "Numri maksimal i " . $this->classname . " Personalitetet e arritur për këtë planet.";
				$this->success = "Dignitary punës sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Spy Hunter";
				$this->description = "Dignatari de la caça d&#39;espies enemics i els mata. Més caçadors són més eficaços en la recerca d&#39;espies.";
				$this->toomany = "El nombre màxim de " . $this->classname . " Dignataris assolit per aquest planeta.";
				$this->success = "Dignatari d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Spy Hunter";
				$this->description = "Dignitar jagter for fjendens spioner og dræber dem. Flere jægere er mere effektive i at finde spioner.";
				$this->toomany = "Maksimalt antal " . $this->classname . " Honoratiores nået for denne planet.";
				$this->success = "Dignitar Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Spy Hunter";
				$this->description = "Hoogwaardigheidsbekleder jaagt voor vijandelijke spionnen en doodt hen. Meer jagers zijn effectiever bij het vinden van spionnen.";
				$this->toomany = "Maximum aantal " . $this->classname . " Hoogwaardigheidsbekleders bereikt voor deze planeet.";
				$this->success = "Hoogwaardigheidsbekleder Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Nuuskija Hunterin";
				$this->description = "Arvohenkilö metsästävät ja vihollisen vakoojia ja tappaa ne. Lisää metsästäjät ovat tehokkaampia löytämään vakoojia.";
				$this->toomany = "Maksimimäärä " . $this->classname . " Arvohenkilöitä päästiin tällä planeetalla.";
				$this->success = "Arvohenkilö työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Spy Hunter";
				$this->description = "Pembesar perburuan untuk mata-mata musuh dan membunuh mereka. Lebih pemburu lebih efektif dalam menemukan mata-mata.";
				$this->toomany = "Jumlah maksimum " . $this->classname . " Pejabat meraih planet ini.";
				$this->success = "Pembesar Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Spy Hunter";
				$this->description = "Herre jakter på fiendens spioner og dreper dem. Flere jegere er mer effektive i å finne spioner.";
				$this->toomany = "Maksimum antall " . $this->classname . " Myndighetspersoner nådd for denne planeten.";
				$this->success = "Herre Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Spy Hunter";
				$this->description = "Dignitário caças para espiões inimigos e os mata. Mais caçadores são mais eficazes na busca de espiões.";
				$this->toomany = "Número máximo de " . $this->classname . " Dignitários chegou para este planeta.";
				$this->success = "Dignitário de trabalho alterado com êxito.";
			break;

			case "swedish":
				$this->classname = "Spy Hunter";
				$this->description = "Dignitär jagar efter fiender spioner och dödar dem. Fler jägare är effektivare att hitta spioner.";
				$this->toomany = "Maximalt antal " . $this->classname . " Dignitärer nått för den här planeten.";
				$this->success = "Dignitär Job har ändrats.";
			break;

			default:
				$this->classname = "Spy Hunter";
				$this->description = "Dignitary hunts for enemy spies and kills them.  More hunters are more effective in finding spies.";
				$this->toomany = "Maximum number of " . $this->classname . " Dignitaries reached for this planet.";
				$this->success = "Dignitary Job Successfully Changed.";
			break;
		}
	}

	function sched_process_dignitary()
	{
		global $db, $db_prefix;

		TextFlush ( "Dignitaries looking for spies<br>");

		$res = $db->Execute("SELECT SUM(d.percent) as chancetotal, d.*, p.* FROM {$db_prefix}dignitary as d, {$db_prefix}planets as p WHERE d.job_id='5' AND d.active='Y' and d.embezzler = 0 and p.planet_id=d.planet_id group by d.planet_id");
		db_op_result($res,__LINE__,__FILE__);
		while (!$res->EOF)
		{
			$row = $res->fields;

			if (mt_rand(1, 100) < (5+($row['chancetotal']*10000)))
			{
				$result_sf = $db->Execute("SELECT * FROM {$db_prefix}spies,{$db_prefix}players WHERE {$db_prefix}spies.owner_id={$db_prefix}players.player_id and {$db_prefix}spies.planet_id=$row[planet_id] AND {$db_prefix}spies.active='Y' "); 
				db_op_result($result_sf,__LINE__,__FILE__);
				if ($result_sf->RecordCount() > 0){
					while(!$result_sf->EOF)
					{
						$spy1 = $result_sf->fields;
						$result_sf->MoveNext();
					}
				}
				if ($result_sf->RecordCount() > 0){
					$debug_query = $db->Execute("DELETE FROM {$db_prefix}spies WHERE spy_id=$spy1[spy_id]");
					db_op_result($debug_query,__LINE__,__FILE__);
					playerlog($row['owner_id'], "LOG1_DIG_KILLED_SPY", "$row[name]|$row[sector_id]|$spy1[character_name]");
					playerlog($spy1['player_id'], "LOG2_SPY_KILLED_SPYOWNER", "$spy1[spy_id]|$row[name]|$row[sector_id]");
					TextFlush ( "$row[planet_id] - Spy hunter Dig - found and killed enemy spy<br>");
				}
				$result_sf->close();
			}
			$res->MoveNext();
		}
		$res->close();
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
			$new_percent = (mt_rand(1, 100) / 100) * $this->dig_spyhunter_max;

			$debug_query = $db->Execute("UPDATE {$db_prefix}dignitary SET percent='$new_percent', job_id='5', active_date='$stamp', reactive_date='$reactive_date' WHERE dig_id=$dig_id ");
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