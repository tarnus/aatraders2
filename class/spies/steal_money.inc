<?php
class steal_money {
	var $id = "6";
	var $singlepass = 0;

	function steal_money()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "raha varastada";
				$this->description = "Spy varastab suure summa raha ja salvestab selle oma laeva.";
				$this->success = "Spy Töö edukalt muudetud.";
			break;

			case "french":
				$this->classname = "Voler de l&#39;argent";
				$this->description = "Spy vole de grosses sommes d&#39;argent et le stocke sur votre bateau.";
				$this->success = "Spy Job changé avec succès.";
			break;

			case "german":
				$this->classname = "Geld zu stehlen";
				$this->description = "Spy stiehlt große Summen von Geld und speichert sie auf Ihrem Schiff.";
				$this->success = "Spy Job erfolgreich geändert.";
			break;

			case "italian":
				$this->classname = "Rubare denaro";
				$this->description = "Spy ruba grandi somme di denaro e lo memorizza sulla tua nave.";
				$this->success = "Spia di lavoro sono state modificate.";
			break;

			case "spanish":
				$this->classname = "Robar el dinero";
				$this->description = "Spy robos de grandes sumas de dinero y lo guarda en su barco.";
				$this->success = "Espía de empleo han cambiado correctamente.";
			break;

			case "albanian":
				$this->classname = "Vjedhin Money";
				$this->description = "Spiun vjedh shuma të mëdha parash dhe dyqane mbi anije tuaj.";
				$this->success = "Spiun i punës me sukses Changed.";
			break;

			case "catalan":
				$this->classname = "Robar els diners";
				$this->description = "Spy robatoris de grans sumes de diners i el guarda en el seu vaixell.";
				$this->success = "Espia d&#39;ocupació han canviat correctament.";
			break;

			case "danish":
				$this->classname = "Stjæle penge";
				$this->description = "Spy stjæler store summer af penge og gemmer den på dit skib.";
				$this->success = "Spy Job blevet ændret.";
			break;

			case "dutch":
				$this->classname = "Steal Geld";
				$this->description = "Spy steelt grote sommen geld en slaat het op uw schip.";
				$this->success = "Spy Job zijn gewijzigd.";
			break;

			case "finnish":
				$this->classname = "Varastaa Rahaa";
				$this->description = "Spy varastaa suuria summia rahaa ja tallentaa ne oman aluksen.";
				$this->success = "Spy työ onnistui.";
			break;

			case "indonesian":
				$this->classname = "Mencuri Uang";
				$this->description = "Mata-mata mencuri uang dalam jumlah besar dan toko di kapal Anda.";
				$this->success = "Spy Ayub Berhasil Berubah.";
			break;

			case "norwegian":
				$this->classname = "Stjele penger";
				$this->description = "Spy stjeler store pengesummer og lagrer den på skipet ditt.";
				$this->success = "Spy Job er endret.";
			break;

			case "portuguese":
				$this->classname = "Roubar dinheiro";
				$this->description = "Spy rouba grandes quantias de dinheiro e as armazena em seu navio.";
				$this->success = "Spy Job alterada com êxito.";
			break;

			case "swedish":
				$this->classname = "Stjäla pengar";
				$this->description = "Spy stjäl stora summor pengar och lagrar det på ditt skepp.";
				$this->success = "Spy Job har ändrats.";
			break;

			default:
				$this->classname = "Steal Money";
				$this->description = "Spy steals large sums of money and stores it on your ship.";
				$this->success = "Spy Job Successfully Changed.";
			break;
		}
	}

	function sched_process_spy()
	{
		global $db, $db_prefix, $multiplier, $spy;

		$steal_money = 2000;
		$steal_money_trigger = (int) ($steal_money / 2);
		$success = mt_rand(0, $steal_money);
		if ($success == $steal_money_trigger)
		{
			if ($spy['credits'] > 0)
			{
				TextFlush ( "Spy Stealing Money<br>");

				$roll = myrand(2400, 9000, 2.5);	//8%...30%
				$sum = floor($spy['credits'] * $roll / 30000);
				$debug_query = $db->Execute("UPDATE {$db_prefix}planets SET credits=credits-$sum WHERE planet_id=$spy[planet_id] ");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();

				$debug_query = $db->Execute("UPDATE {$db_prefix}players SET credits=credits+$sum WHERE player_id=$spy[owner_id]");
				db_op_result($debug_query,__LINE__,__FILE__);
				$debug_query->close();
			}
		}
	}

	function change_spy($spy_id, $planet_id, $mode)
	{
		global $db, $db_prefix;

		$debug_query = $db->Execute("UPDATE {$db_prefix}spies SET move_type='$mode', spy_percent='0', job_id='6' WHERE spy_id=$spy_id ");
		db_op_result($debug_query,__LINE__,__FILE__);
		$debug_query->close();
	}
}

?>