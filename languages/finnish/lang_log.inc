<?php
$l_log_months = "array ( &#39;Tammikuu&#39;, &#39;Helmikuu&#39;, &#39;Maaliskuu&#39;, &#39;Huhtikuu&#39;, &#39;Toukokuu&#39;, &#39;Kes�kuu&#39;, &#39;Hein�kuu&#39;, &#39;Elokuu&#39;, &#39;Syyskuu&#39;, &#39;Lokakuu&#39;, &#39;Marraskuu&#39;, &#39;Joulukuu&#39;)";
$l_log_months_short = "array ( &#39;Tammi&#39;, &#39;Helmi&#39;, &#39;Maalis&#39;, &#39;Huhti&#39;, &#39;Toukokuu&#39;, &#39;Kes�kuu&#39;, &#39;Hein�kuu&#39;, &#39;Elokuu&#39;, &#39;Syys&#39;, &#39;Lokakuu&#39;, &#39;Marraskuu&#39;, &#39;Joulukuu&#39;)";
$l_log_pod = "Onneksi sinulla oli paeta pod!";
$l_log_nopod 		 = "<font color=yellow><b>You did not have an escape pod, you died.</b></font>";
$l_log_log = "[player] &#39;s Kirjaudu";
$l_log_start = "Log merkint�";
$l_log_end = "End log merkint�";
$l_log_click 		 = "Click <A HREF=main.php><font color=#00ff00>here</font></A> to return to the main menu.";
$l_log_select = "Valitse tiedot:";
$l_log_general = "Yleinen tiedot";
$l_log_dig = "Arvohenkil� Kirjaudu";
$l_log_spy = "Spy Kirjaudu";
$l_log_disaster = "Planet Disaster Log";
$l_log_nova = "Nova Laitteen tiedot";
$l_log_attack = "Attack Kirjaudu";
$l_log_scan = "Scan Log";
$l_log_starv = "Planet N�l�nh�t� Log";
$l_log_probe = "Probe Kirjaudu";
$l_log_combined = "Yhdistetyn Log";


// Log entry data

$l_log_text["LOG_LOGIN"] = "Olet kirjautunut sis��n, alkaen [ip].";
$l_log_title["LOG_LOGIN"] = "Sis��nkirjautumista";
$l_log_text["LOG_LOGOUT"] = "Olet kirjautunut ulos, alkaen [ip].";
$l_log_title["LOG_LOGOUT"] = "Kirjautui ulos";

// General Log Entries

$l_log_title["LOG0_ADMIN_DBERROR"] = "Tietokantavirhe Tapahtui";
$l_log_title["LOG0_ADMIN_COMBAT"] = "Combat Action Tulos";
$l_log_title["LOG0_RAW"] = "Ilmoituksessa";
$l_log_text["LOG0_PLANET_EJECT"] = "Olet ollut ulos siit� planeetan alalla [sector], sill� [name] j�tti joukkueen.";
$l_log_title["LOG0_PLANET_EJECT"] = "Ulos!";
$l_log_text["LOG0_BADLOGIN"] = "On ollut huono kirjautumisyrityst� alkaen [ip].";
$l_log_title["LOG0_BADLOGIN"] = "Bad kirjautunut";
$l_log_title["LOG0_TOW"] = "Vedett�vi�!";
$l_log_text["LOG0_TOW"] = "Sinun alus on vedet��n alalla [sector] aloittain [newsector], koska keskim��r�inen teknologian taso ylitti raja-arvo [hull] tai sinulla on alus varastossa.";
$l_log_text["LOG0_HARAKIRI"] = "Olit v�synyt kapteenina t�m�n tilan proomuilla, joten p��tettiin maailmankaikkeus olisi parempi ilman sit�. Valtuuttama [ip].";
$l_log_title["LOG0_HARAKIRI"] 		= "<font color=red>Self-destructed!</font>";
$l_log_text["LOG0_TEAM_REJECT"] = "[player] on hyl�nnyt kutsun liitty� tiimisi, [teamname].";
$l_log_title["LOG0_TEAM_REJECT"] = "Kutsu hyl�tty";
$l_log_text["LOG0_TEAM_RENAME"] = "Olet nimennyt joukkueesi [team].";
$l_log_title["LOG0_TEAM_RENAME"] = "Joukkueen nimi";
$l_log_text["LOG0_TEAM_M_RENAME"] = "Tiimisi koordinaattori nimettiin tiimin [team].";
$l_log_title["LOG0_TEAM_M_RENAME"] = "Joukkueen nimi";
$l_log_text["LOG0_TEAM_KICK"] = "Olet ollut ulos siit� tiimin [team].";
$l_log_title["LOG0_TEAM_KICK"] = "Ulos tiimin!";
$l_log_text["LOG0_TEAM_CREATE"] = "Olet luonut uuden joukkueen, [team].";
$l_log_title["LOG0_TEAM_CREATE"] = "Luotu uusi tiimi";
$l_log_text["LOG0_TEAM_LEAVE"] = "J�tit team [team].";
$l_log_title["LOG0_TEAM_LEAVE"] = "Vasen Team";
$l_log_text["LOG0_TEAM_NEWLEAD"] = "J�tit joukkue [team]. Olet luopunut joukkueen johtoa [name].";
$l_log_title["LOG0_TEAM_NEWLEAD"] = "Vasen Team";
$l_log_text["LOG0_TEAM_LEAD"] = "Tiimisi koordinaattori on p��tt�nyt j�tt�� [team]. Sinulla on nimitetty ottamaan paikkansa.";
$l_log_title["LOG0_TEAM_LEAD"] = "Edist�minen!";
$l_log_text["LOG0_TEAM_JOIN"] = "Olet liittynyt ryhm��n [team].";
$l_log_title["LOG0_TEAM_JOIN"] = "Yhdistetyt Team";
$l_log_text["LOG0_TEAM_NEWMEMBER"] = "[name] on hyv�ksytty liittym��n [team]. T�m� tuo sinulle yhden askeleen pidemm�lle galaktisen ylivaltaa.";
$l_log_title["LOG0_TEAM_NEWMEMBER"] = "Uuden tiimin j�sen";
$l_log_text["LOG0_TEAM_INVITE"] = "Sinut on kutsuttu olla osa [team].";
$l_log_title["LOG0_TEAM_INVITE"] = "Tarjouskilpailun";
$l_log_text["LOG0_TEAM_NOT_LEAVE"] = "[player] on l�htenyt joukkue.";
$l_log_title["LOG0_TEAM_NOT_LEAVE"] = "Joukkue h�vi�� j�sen";
$l_log_text["LOG0_ADMIN_HARAKIRI"] = "[player] on itse tuhoamatta l�htee IP [ip].";
$l_log_title["LOG0_ADMIN_HARAKIRI"] = "Itsetuhomekanismia";
$l_log_text["LOG0_ADMIN_ILLEGVALUE"] = "[player] oli [quantity] [type], jossa max aukot [holds]";
$l_log_title["LOG0_ADMIN_ILLEGVALUE"] = "Laittoman aluksen arvo";
$l_log_text["LOG0_ADMIN_PLANETDEL"] = "[attacker] on yritt�nyt kaapata [defender] &#39;s planeetan alalla [sector]. Planet tuhoutui sijaan.";
$l_log_title["LOG0_ADMIN_PLANETDEL"] = "Planet tuhoutui";
$l_log_text["LOG0_defense_DEGRADE"] = "Sektori puolustuksemme Fighters sektori [sector] hajoavan [degrade] prosenttia riitt�m�tt�myyden vuoksi energiaa.";
$l_log_title["LOG0_defense_DEGRADE"] = "Alan puolustuksemme huonontunut.";
$l_log_text["LOG0_CHEAT_TEAM"] = "Player [player] IP-osoite [ip] yritt�nyt k�ytt�� joukkueen potkaista ket��n huijata. H�nen alus tuhoutui.";
$l_log_title["LOG0_CHEAT_TEAM"] = "Team Exploit K�ytetyt";
$l_log_text["LOG0_BOUNTY_CLAIMED"] = "Olet v�itti lahjasta [amount] luottoja tuhoaminen aluksen kuuluvan [bounty_on]. Bounty on asetettu vuoteen [placed_by].";
$l_log_title["LOG0_BOUNTY_CLAIMED"] = "Palkkionmets�st�j� haettu.";
$l_log_text["LOG0_BOUNTY_PAID"] = "Sinun Bounty on [bounty_on] on maksettu m��r� on [amount] opintoviikkoa.";
$l_log_title["LOG0_BOUNTY_PAID"] = "Bounty maksettu.";
$l_log_text["LOG0_BOUNTY_TAX_PAID"] = "Fedration Bounty on [bounty_on] on verotetaan m��r� [amount] opintoviikkoa.";
$l_log_title["LOG0_BOUNTY_TAX_PAID"] = "Bounty vero maksettu.";
$l_log_text["LOG0_BOUNTY_CANCELLED"] = "Sinun Bounty on [bounty_on] on m��r� [amount] hyvityksi� on hyvitetty.";
$l_log_title["LOG0_BOUNTY_CANCELLED"] = "Bounty takaisin.";
$l_log_text["LOG0_BOUNTY_FEDBOUNTY"] = "Liitto on asettanut armo teit� varten m��r�n [amount] opintoviikkoa.";
$l_log_title["LOG0_BOUNTY_FEDBOUNTY"] = "Federation Bounty!";
$l_log_text["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Liittouma on asettanut armo teit� varten m��r�n [amount] opintoviikkoa.";
$l_log_title["LOG0_BOUNTY_ALLIANCEBOUNTY"] = "Alliance Bounty!";
$l_log_text["LOG0_IGB_TRANSFER1"] = "Player [name] siirtyy [sum] luottoja sinun IGB huomioon.";
$l_log_title["LOG0_IGB_TRANSFER1"] = "Siirrettyj�";
$l_log_text["LOG0_IGB_TRANSFER2"] = "Olet siirt�nyt [sum] luottojen pelaaja [name] IGB huomioon.";
$l_log_title["LOG0_IGB_TRANSFER2"] = "Siirrettyj�";
$l_log_text["LOG0_ADMIN_PLANETIND"] = "[sector] Planet [planetname] ([planetid]) omistaa [owner] itsen�istyi. Keskiarvo Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_PLANETIND"] = "Planet meni riippumaton.";
$l_log_text["LOG0_ADMIN_INDYPURGE"] = "Riippumaton Planet [planetname] ([planetid]) omistaa [owner] ja [sector] on poistettu. Keskiarvo Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_INDYPURGE"] = "Riippumaton Planet tyhjennet��n.";
$l_log_text["LOG0_ADMIN_NEVEROWNEDPURGE"] = "Koskaan Omisti Planet [planetname] ([planetid]) perustettiin [date] ja [sector] on poistettu. Keskiarvo Tech: [avgtech]";
$l_log_title["LOG0_ADMIN_NEVEROWNEDPURGE"] = "Koskaan Omisti Planet tyhjennet��n.";
$l_log_text["LOG0_TEAM_CANCEL"] = "Olet kutsu osa [team] on peruutettu.";
$l_log_title["LOG0_TEAM_CANCEL"] = "Kutsu Peruutetut";

// Dignitary Log Entries

$l_log_text["LOG1_DIG_PRODUCTION"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] alkaa rakennuksen tuotantoa.";
$l_log_title["LOG1_DIG_PRODUCTION"] = "<font color=#00FF00>Production Building  Started!</font>";
$l_log_text["LOG1_DIG_BIRTHDEC"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] v�hentynyt syntyvyys.";
$l_log_title["LOG1_DIG_BIRTHDEC"] = "<font color=#00FF00>Birthrate Decreased!</font>";
$l_log_text["LOG1_DIG_BIRTHINC"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] kasvaa syntyvyys.";
$l_log_title["LOG1_DIG_BIRTHINC"] = "<font color=#00FF00>Birthrate Increased!</font>";
$l_log_text["LOG1_DIG_SPYHUNT"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] rupesivat hakemaan spys t�ll� planeetalla.";
$l_log_title["LOG1_DIG_SPYHUNT"] = "<font color=#00FF00>Spy Hunter!</font>";
$l_log_text["LOG1_DIG_INTEREST"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] alkaa lis��miseen luotto tuotantoa.";
$l_log_title["LOG1_DIG_INTEREST"] = "<font color=#00FF00>Interest Building Started!</font>";
$l_log_text["LOG1_DIG_MONEY"] = "Arvohenkil� [id] planeetalla [planet_name] kavaltanut [data] luottoja ja lahjoitti sinulle!";
$l_log_title["LOG1_DIG_MONEY"] = "<font color=#00FF00>You Recieved Embezzled  Credits!</font>";
$l_log_text["LOG1_DIG_KILLED_SPY"] = "Sinun arvohenkil� havaittu pelaaja [name] vakoilla planeetallanne [planet_name] sektori [sector]. Vakoilemaan kuolee nyt.";
$l_log_title["LOG1_DIG_KILLED_SPY"] = "<font color=yellow>Enemy Spy Killed!</font>";
$l_log_text["LOG1_DIG_CATACLYSM"] = "Your kaivaa [id] planeetalla [planet_name] sektori [sector] tuhoutunut kauhea mullistuksen kanssa planeetan.";
$l_log_title["LOG1_DIG_CATACLYSM"] = "<font color=yellow>dig Lost!</font>";
$l_log_text["LOG1_SHIPDIG_CATACLYSM"] = "Your kaivaa [id] pelaajien [name] &#39;s aluksen [shipname] tuhoutunut kauhea mullistus kyseisen aluksen.";
$l_log_title["LOG1_SHIPDIG_CATACLYSM"] = "<font color=yellow>dig Lost!</font>";
$l_log_text["LOG1_DIG_TORPS"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] rakennettu [data] planeettojen torpedoja!";
$l_log_title["LOG1_DIG_TORPS"] = "<font color=#00FF00>Torpedoes Built!</font>";
$l_log_text["LOG1_DIG_FITS"] = "Your arvohenkil� [id] planeetalla [planet_name] sektori [sector] rakennettu [data] planeettojen taistelijat!";
$l_log_title["LOG1_DIG_FITS"] = "<font color=#00FF00>Fighters Built!</font>";

// Spy Log Entries

$l_log_text["LOG2_SPY_NEWSHIP"] = "Olet unohtanut Spy [id] on [name] aluksen [shipname], koska pelaaja ostaa uuden aluksen.";
$l_log_title["LOG2_SPY_NEWSHIP"] = "<font color=yellow>Spy Lost!</font>";
$l_log_text["LOG2_SPY_SEND_FAIL"] = "[name] yritt�nyt l�hett�� vakooja sinun Planet [planet_name] sektori [sector], mutta teid�n Anturit havaittu vakooja, ja h�n on kuollut nyt.";
$l_log_title["LOG2_SPY_SEND_FAIL"] = "<font color=yellow>Enemy Spy Killed!</font>";
$l_log_text["LOG2_SPY_SABOTAGE"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] alkaa tuhoty�. Tuotanto on laskenut [data] t�ll� planeetalla.";
$l_log_title["LOG2_SPY_SABOTAGE"] = "<font color=#00FF00>Sabotage Started!</font>";
$l_log_text["LOG2_SPY_BIRTH"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] laski syntyvyys on [data] t�ll� planeetalla.";
$l_log_title["LOG2_SPY_BIRTH"] = "<font color=#00FF00>Birthrate Decreased!</font>";
$l_log_text["LOG2_SPY_INTEREST"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] alkaa ker�t� Planet etua [data] sinulle.";
$l_log_title["LOG2_SPY_INTEREST"] = "<font color=#00FF00>Interest Stealing Started!</font>";
$l_log_text["LOG2_SPY_MONEY"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] oli [data] luottojen sinulle!";
$l_log_title["LOG2_SPY_MONEY"] = "<font color=#00FF00>Credits Have Stolen!</font>";
$l_log_text["LOG2_SPY_TORPS"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] tuhottu [data] planeettojen torpedoja!";
$l_log_title["LOG2_SPY_TORPS"] = "<font color=#00FF00>Torpedoes Destroyed!</font>";
$l_log_text["LOG2_SPY_FITS"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] tuhottu [data] planeettojen taistelijat!";
$l_log_title["LOG2_SPY_FITS"] = "<font color=#00FF00>Fighters Destroyed!</font>";
$l_log_text["LOG2_SPY_CPTURE"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] kiinni t�m�n planeetan! Olet onnekas kaveri ...";
$l_log_title["LOG2_SPY_CPTURE"] = "<font color=#00FF00>PLANET CAPTURED!</font>";
$l_log_text["LOG2_SPY_CPTURE_OWNER"] = "[name] vakooja kiinni planeettanne [planet_name] sektori [sector]! N�ytt�� silt�, ett� se on viisasta ajatusta uudelleenj�rjest�minen sinun planeettoja useammin ...";
$l_log_title["LOG2_SPY_CPTURE_OWNER"] = "<font color=red>Planet Lost!</font>";
$l_log_text["LOG2_SPY_KILLED_SPYOWNER"] = "Ei viestej� Spy [id] planeetalla [planet_name] sektori [sector] pitk�ksi aikaa - n�ytt�� silt�, ett� viitta-laitetta ei kata h�nt� tarpeeksi, ja h�n on kuollut.";
$l_log_title["LOG2_SPY_KILLED_SPYOWNER"] = "<font color=yellow>Spy Lost!</font>";
$l_log_text["LOG2_SPY_KILLED"] = "Sinun Anturit havaittu [name] vakoilla planeetallanne [planet_name] sektori [sector]. Vakoilemaan kuolee nyt.";
$l_log_title["LOG2_SPY_KILLED"] = "<font color=yellow>Enemy Spy Killed!</font>";
$l_log_text["LOG2_SHIPSPY_KILLED"] = "Ei viestej� Spy [id] pelaajien [name] laiva [shipname] pitk�ksi aikaa - n�ytt�� silt�, ett� viitta-laitetta ei kata h�nt� tarpeeksi, ja h�n on kuollut.";
$l_log_title["LOG2_SHIPSPY_KILLED"] = "<font color=yellow>Spy Lost!</font>";
$l_log_text["LOG2_SPY_CATACLYSM"] = "Your Spy [id] planeetalla [planet_name] sektori [sector] tuhoutunut kauhea mullistuksen kanssa planeetan.";
$l_log_title["LOG2_SPY_CATACLYSM"] = "<font color=yellow>Spy Lost!</font>";
$l_log_text["LOG2_SHIPSPY_CATACLYSM"] = "Your Spy [id] pelaajien [name] &#39;s aluksen [shipname] tuhoutunut kauhea mullistuksen kanssa aluksen.";
$l_log_title["LOG2_SHIPSPY_CATACLYSM"] = "<font color=yellow>Spy Lost!</font>";
$l_log_text["LOG2_SPY_TOSHIP"] = "Your Spy [id] from Planet [planet_name] sektori [sector] ujuttautuu pelaaja [playername] &#39;s aluksen [shipname] ja toimii nyt siell�.";
$l_log_title["LOG2_SPY_TOSHIP"] = "<font color=#00FF00>Spy Infiltrates Enemy Ship!</font>";
$l_log_text["LOG2_SPY_TOPLANET"] = "Your Spy [id] pelaajalta [playername] &#39;s aluksen [shipname] ujuttautuu Planet [planet_name] sektori [sector] ja toimii nyt siell�.";
$l_log_title["LOG2_SPY_TOPLANET"] = "<font color=#00FF00>Spy Infiltrates Enemy Planet!</font>";
$l_log_text["LOG2_SPY_FOUND_EMBEZZLER"] = "Your arvohenkil� numero [DIG] planeetalla [PLANET] on pyydetty embezzling. Saatat haluta hyl�t�.";
$l_log_title["LOG2_SPY_FOUND_EMBEZZLER"] 	= "<font color=yellow>Embezzler found!</font>";

// Nova Bomb Logs

$l_log_text["LOG4_PLANET_novaED_D"] = "Planeettanne [planet_name] sektori [sector] oli h�vitetty Nova Bomb on [name]. Yht��n mit��n viel� merkit� planeettoja entisen olemassaolon.";
$l_log_title["LOG4_PLANET_novaED_D"] 	= "<font color=yellow>Planet destroyed with a Nova Bomb</font>";
$l_log_text["LOG4_SHIP_novaED_D"] = "Sinun alus oli h�vitetty Nova pommittivat [name].";
$l_log_title["LOG4_SHIP_novaED_D"] 	= "<font color=yellow>Ship destroyed with a Nova Bomb</font>";

// Attack Logs

$l_log_text["LOG5_PLANET_BOMBED"] = "Planeettanne [planet_name] sektori [sector] on pommitettu [name]. Voit k�ytt�� [beams] energiaa ja [torps] torpedot oman puolustuksen. Olet menett�nyt [figs] taistelijoita.";
$l_log_title["LOG5_PLANET_BOMBED"] = "<font color=red>Planet bombed!</font>";
$l_log_text["LOG5_PLANET_YOUR_CAPTURED"] = "Planeettanne [planet_name] sektori [sector] hyl�ttiin ja vangitsi kurja [name].";
$l_log_title["LOG5_PLANET_YOUR_CAPTURED"]  = "<font color=red>Planet captured!</font>";
$l_log_text["LOG5_ATTACK_OUTMAN"] = "[player] oli t�plik�s hy�kk�ys, mutta mahtava lent�j�n taitoja ja hyvi� moottoreita saa sinut p�ihitt�� vihollisen.";
$l_log_title["LOG5_ATTACK_OUTMAN"] = "V�ist�!";
$l_log_text["LOG5_ATTACK_OUTSCAN"] = "Voit havaita [player] &#39;s aseita yritt�� korjata teid�n aluksen, mutta teid�n piilo generaattorit onnistui huijaamaan vihollisen primitiivinen anturi piirej�.";
$l_log_title["LOG5_ATTACK_OUTSCAN"] = "Viitta onnistunut!";
$l_log_text["LOG5_ATTACK_EWD"] = "Olet yll�ttyneit� [player] &#39;s petollisia hy�kk�ys. N�et saapuvan ydink�rkien niin p��set kuumeisesti kiireellisest� loimi-painiketta. Maailma h�m�rt�� ymp�rill�nne ja, milisecond, luulet olevasi kuollut. Kun vihdoin avata silm�si, huomaat, ett� olet turvallisesti kuljettaa muualle. Mutta miss� tarkalleen, et tied� ...";
$l_log_title["LOG5_ATTACK_EWD"] = "Emergency loimi!";
$l_log_text["LOG5_ATTACK_EWDFAIL"] = "Your anturit tunnistavat [player] &#39;s aluksen hy�kk�yksest�. &quot;Parempi katsoa kuin katua&quot;, ajattelet, ly�m�ll� h�t�tilanteessa loimi-painiketta. Kuulet outo tukehtumisvaara ��ni tulevien moottoreiden huoneessa ja haju poltettiin virtapiirej�. &quot;Stupid pala paskaa!&quot;, Voit Yell, potkiminen on tietokone. Tietokone l�hett�� ��nimerkin ja vakuuttelu kun valmistautua tulevan taistelun ...";
$l_log_title["LOG5_ATTACK_EWDFAIL"] 	= "Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_ATTACK_LOSE"] = "Sinun alus hy�kk�� [player]. Kokeile kuten ehk�, ei voi puolustaa itse�si vastaan [player] &#39;s parempia aseita. Sinun alus tuhoutui.";
$l_log_title["LOG5_ATTACK_LOSE"] 		= "<font color=red>Combat lost!</font>";
$l_log_text["LOG5_ATTACKED_WIN"] = "Voit aluksen hy�kk�siv�t [player]. Olet taisteluun vaikka sitten taistelussa hajoaa. Olet menett�nyt [armor] Armor pistett� ja [fighters] taistelijat kahakka.";
$l_log_title["LOG5_ATTACKED_WIN"] 		= "<font color=yellow>Skirmish!</font>";
$l_log_text["LOG5_HIT_MINES"] = "Osut [mines] kaivokset matkustettaessa alalla [sector].";
$l_log_title["LOG5_HIT_MINES"] 		= "<font color=yellow>Mines alert!</font>";
$l_log_text["LOG5_SHIP_DESTROYED_MINES"] = "Sinun alus tuhoutui miinakentt� sektorissa [sector].";
$l_log_title["LOG5_SHIP_DESTROYED_MINES"] 	= "<font color=red>Mines alert!</font>";
$l_log_text["LOG5_PLANET_DEFEATED_D"] = "Planeettanne [planet_name] sektori [sector] kaatui taistelussa on [name]. Onneksi, vahva uskollisuus oman kansalaisten pelit eduksesi. He ovat rohkeasti p��tt�neet tuhota maapallon sijaan, ett� ne joutuvat vihollisen k�siin. Voit j�rjest�� upea hautajaisissa ja muisti uskollisia ihmisi�.";
$l_log_title["LOG5_PLANET_DEFEATED_D"] 	= "<font color=yellow>Planet destroyed</font>";
$l_log_text["LOG5_PLANET_DEFEATED"] = "Planeettanne [planet_name] sektori [sector] h�visi taistelun jonka kurja [name]. Ihmiset planeetan toivottaa uuden hallitsijan. Kuulet todistamastaasiassa FNN: &quot;Olemme iloisia p��st� eroon siit�, ett� vanha pieru! Emme halua mit��n haiseva h�vi�j�, jotka eiv�t voi suojella meit�!&quot;. Lupaatko ett� ne maksavat ylimielisyytt�.";
$l_log_title["LOG5_PLANET_DEFEATED"] 	= "<font color=red>Planet defeated!</font>";
$l_log_text["LOG5_PLANET_NOT_DEFEATED"] = "Planeettanne [planet_name] sektori [sector] hy�kk�siv�t [name]. Kansalaiset j�rjesti Valliant puolustus kuitenkin, ja onnistui tuhoamaan vastustajan. Ne pelastaa joitakin varoja avaruusromua: [goods] tavaroita, [ore] malmia, [organics] orgaaniset ja [salvage]% aluksen arvosta [credits] opintoviikkoa.";
$l_log_title["LOG5_PLANET_NOT_DEFEATED"] = "Victory!";
$l_log_text["LOG5_DEFS_DESTROYED"] = "[quantity] [type] tuhoutui alalla [sector].";
$l_log_title["LOG5_DEFS_DESTROYED"] = "Alan puolustuksemme tuhoutui";
$l_log_text["LOG5_KABAL_ATTACK"] = "Hy�kk��m�ll� [player] ...";
$l_log_title["LOG5_KABAL_ATTACK"] = "Hy�kk�yst�";
$l_log_text["LOG5_DEFS_DESTROYED_F"] = "Olet tuhonnut [fighters] partioivat taistelijat alalla [sector].";
$l_log_title["LOG5_DEFS_DESTROYED_F"] = "Fighters tuhoutui";
$l_log_text["LOG5_DEFS_KABOOM"] = "Olet tuhosi taistelijat voima-alalla [sector].";
$l_log_title["LOG5_DEFS_KABOOM"] 		= "<font color=red>Ship destroyed!</font>";
$l_log_text["LOG5_PLANET_CAPTURED"] = "Voit vallanneet planeetan kuuluvan [owner]. Oli [cols] uudisasukkaita ja [credits] ov sit�.";
$l_log_title["LOG5_PLANET_CAPTURED"] = "Planet kiinni!";
$l_log_text["LOG5_STORAGE_EWD"] = "Planeettanne h�mm�stelee [player] &#39;s hy�kk�ys. Yksi tallennettujen alusten teki Emergency taivutuksen [sector] ja laskeutui planeetalle [planet]";
$l_log_title["LOG5_STORAGE_EWD"] = "Tallennettu Ship Emergency Warp!";
$l_log_text["LOG5_STORAGE_EWDFAIL"] = "Tallennettu alukset Kiireelliset Warp Device h�vinnyt! Varastoitu alus valtasivat [player] sen j�lkeen, kun he voittivat oman Planet!";
$l_log_title["LOG5_STORAGE_EWDFAIL"] 	= "Stored Ship Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_STORAGE_CAPTURED"] = "Tallennettu alus valtasivat [player] sen j�lkeen, kun he voittivat one planeettoja!";
$l_log_title["LOG5_STORAGE_CAPTURED"] 	= "Stored Ship <font color=red>CAPTURED!</font>";
$l_log_text["LOG5_CONFISCATION"] = "Sinun alus oli takavarikoinut [player]. Tehd� kohtuuttomia hy�kk�ykset Bounty pelaajia [player] on takavarikoinut joku alusten ([ship]).";
$l_log_title["LOG5_CONFISCATION"] 		= "<font color=yellow>Skirmish!</font>";
$l_log_text["LOG5_PLANET_CONFISCATION"] = "Planeettanne oli takavarikoinut [player]. Tehd� kohtuuttomia hy�kk�ykset Bounty pelaajia [player] on takavarikoinut joku planeetat ([name]) sektori [sector] arvo [score] opintoviikkoa.";
$l_log_title["LOG5_PLANET_CONFISCATION"] 		= "<font color=yellow>Planetary Skirmish!</font>";
$l_log_text["LOG5_STORAGE_SUICIDE"] = "Tallennettu alus suicided kun [player] voitti one planeettoja ja yritti vallata sen!";
$l_log_title["LOG5_STORAGE_SUICIDE"] 	= "Stored Ship <font color=red>SUICIDE!</font>";

$l_log_text["LOG5_SM_ATTACK"] = "Laiva Anturit havaitaan tulevan Ala ohjus on erotettiin [sector] on [player]!";
$l_log_title["LOG5_SM_ATTACK"] 	= "<font color=red>INCOMING SECTOR MISSILE DETECTED</font>";
$l_log_text["LOG5_SM_OUTMAN"] = "Ala Missile polttoaineena k�ytt�v�t [player] n�htiin k�yristymisen alalle ja voit kiert�minen hy�kk�ys.";
$l_log_title["LOG5_SM_OUTMAN"] = "Alan Missile V�ist�liike!";
$l_log_text["LOG5_SM_OUTSCAN"] = "Voit havaita [player] &#39;s saapuvan Ala ohjusten yritt�� korjata teid�n aluksen, mutta teid�n piilo generaattorit onnistui huijaamaan sektorin ohjusten anturi piirej�.";
$l_log_title["LOG5_SM_OUTSCAN"] = "Alan Missile Viitta onnistui!";
$l_log_text["LOG5_SM_EWD"] = "Olet yll�ttyneit� [player] &#39;s Sector Missile Attack ja sitoutumaan valmiuslain Warp Device hyppy tuntemattomaan alalla.";
$l_log_title["LOG5_SM_EWD"] = "Alan Missile Emergency Warp!";
$l_log_text["LOG5_SM_EWDFAIL"] = "Your anturit tunnistavat [player] &#39;s Sector Missile Attack ja sitoutumaan valmiuslain Warp Device. Kuulet outo tukehtumisvaara ��ni tulevien moottoreiden huoneessa ja haju poltettiin virtapiirej�. &quot;Stupid pala paskaa!&quot;, Voit Yell, potkiminen on tietokone. Olet ahdin vaikutusten!";
$l_log_title["LOG5_SM_EWDFAIL"] 	= "Sector Missile Emergency warp <font color=red>failed!</font>";
$l_log_text["LOG5_SM_WIN"] = "Sinun aluksen hy�kk�siv�t [player] k�ytt�en Sector ohjus. Olet menett�nyt [armor] Armor pistett� ja [energy] energian yksikk�� hy�kk�ys.";
$l_log_title["LOG5_SM_WIN"] 		= "<font color=yellow>Sector Missile IMPACT!</font>";
$l_log_text["LOG5_SM_LOSE"] = "Sinun alus tuhoutui Ala ohjusten alkaen [player].";
$l_log_title["LOG5_SM_LOSE"] 		= "<font color=red>Sector Missile Combat Lost!</font>";

$l_log_text["LOG5_SURVIVE_PROBE_ATTACK"] = "Voit aluksen hy�kk�siv�t koetin omistama [player] sektori [sector]. Olet menett�nyt [armor] Armor pistett� ja [energy] energian yksikk�� hy�kk�ys.";
$l_log_title["LOG5_SURVIVE_PROBE_ATTACK"] 		= "<font color=yellow>Probe ATTACK!</font>";
$l_log_text["LOG5_PROBE_ATTACK_FAILED"] = "[player] selviytyi hy�kk�ys teid�n anturilla alalla [sector].";
$l_log_title["LOG5_PROBE_ATTACK_FAILED"] 		= "<font color=red>Probe Attack FAILED!</font>";
$l_log_text["LOG5_PROBE_ATTACK_SUCCEEDED"] = "Sinun anturi tuhosi aluksen omistaa [player] sektori [sector].";
$l_log_title["LOG5_PROBE_ATTACK_SUCCEEDED"] 		= "<font color=red>Probe Attack Succeeded!</font>";
$l_log_text["LOG5_DESTROYED_PROBE_ATTACK"] = "Sinun alus tuhoutui koetin alkaen [player] sektori [sector].";
$l_log_title["LOG5_DESTROYED_PROBE_ATTACK"] 		= "<font color=red>Probe Attack Lost!</font>";
$l_log_title["LOG5_AFTER_ACTION"] = "J�lkeen Action Combat Raportti";

// Scan Logs

$l_log_text["LOG6_PLANET_SCAN"] = "[name] on tarkistanut planeettanne [planet_name] sektori [sector].";
$l_log_title["LOG6_PLANET_SCAN"] = "Planet Scan";
$l_log_text["LOG6_PLANET_SCAN_FAIL"] = "[name] on yritt�nyt skannata Planet [planet_name] sektori [sector], mutta ep�onnistui.";
$l_log_title["LOG6_PLANET_SCAN_FAIL"] = "Planet Scan ep�onnistui";
$l_log_text["LOG6_SHIP_SCAN"] = "[player] on tarkistanut sinun aluksen.";
$l_log_title["LOG6_SHIP_SCAN"] = "Laiva Scan";
$l_log_text["LOG6_SHIP_SCAN_FAIL"] = "[player] on yritt�nyt skannata alusta, mutta ep�onnistui.";
$l_log_title["LOG6_SHIP_SCAN_FAIL"] = "Laiva Scan ep�onnistui";

// Starvation Logs

$l_log_text["LOG7_STARVATION"] = "Planet [name] ja [sector] ei kannata v�est�st�! Lis�� orgaaniset tarvitaan. [starvation] siirtolaiset kuoli n�lk��n. Uudisasukkaat alkoivat n�lk�� [date].";
$l_log_title["LOG7_STARVATION"] 		= "<font color=yellow>Starvation!</font>";

// Probe Logs

$l_log_text["LOG9_PROBE_DETECTED_SHIP"]="<font color=yellow>Your probe id [id] detected [ship_name] entering sector [sector]</font>";
$l_log_title["LOG9_PROBE_DETECTED_SHIP"] = "Probe Detected Saapuvat Laiva";
$l_log_text["LOG9_PROBE_SCAN_SHIP"]="<font color=yellow>Your probe id [id] scanned [ship_name] entering sector [sector]<br>Hull: [hull] Engines: [engines] Power: [power] Fighter Bay: [fighter] Sensors: [sensors] Beams: [beams] Torp Launchers: [torps] Armor: [armor] Shields: [shields] Cloak: [cloak]<br>Armor Points: [armor_pts] Fighters: [fighters] Torpedoes: [avail_torps] Ship Energy: [energy] Credits: [credits] <br>Mine Deflectors: [deflectors] Emergency Warp: [ewd] Escape Pod: [pod] ECM: [ecm]</font>";
$l_log_title["LOG9_PROBE_SCAN_SHIP"] = "Probe Skannattu Saapuvat Laiva";
$l_log_text["LOG9_PROBE_DESTROYED"]="<font color='#00ff00'>SECTOR defenses in [sector] destroy your probe.</font>";
$l_log_title["LOG9_PROBE_DESTROYED"] = "Probe Tuhottu";
$l_log_text["LOG9_PROBE_NOTURNS"]="<font color='#00ff00'>You do not have enough turns for probe [probe_id] to move to [sector]</font>";
$l_log_title["LOG9_PROBE_NOTURNS"] = "Probe Raportti";
$l_log_text["LOG9_PROBE_INVALIDSECTOR"] = "<font color='#00ff00'>Moving to sector [target_sector] is not allowed</font>";
$l_log_title["LOG9_PROBE_INVALIDSECTOR"] = "Probe Raportti";
$l_log_text["LOG9_PROBE_DETECTPROBE"]="<font color='#00ff00'>Probe [probe_id] in sector [sector] detected [probe_detect]</font>";
$l_log_title["LOG9_PROBE_DETECTPROBE"] 		= "[probe_type] <font color='yellow'>Probe Report</font>";
$l_log_text["LOG9_PROBE_DETECTED_GATEWAY"]="<font color='#00ff00'>Seeker Probe [probe_id] in sector [sector] detected a Gateway Sector</font>";
$l_log_title["LOG9_PROBE_DETECTED_GATEWAY"] 		= "[probe_type] <font color='yellow'>Seeker Probe Report</font>";

$l_log_text["LOG9_PROBE_SCAN_FAIL"] = "[name] yritt�nyt skannaamme kuumatkat sektori [sector], mutta ep�onnistui.";
$l_log_title["LOG9_PROBE_SCAN_FAIL"] 		= "[probe_type] <font color='yellow'>Probe Report</font>";
$l_log_text["LOG9_PROBE_SCAN"] = "Joku antureista sektori [sector] oli skannata [name].";
$l_log_title["LOG9_PROBE_SCAN"] 		= "[probe_type] <font color='yellow'>Probe Report</font>";
$l_log_text["LOG9_PROBE_ATTACKED"] = "Joku antureista sektori [sector] hy�kk�si ja tuhosi [name].";
$l_log_title["LOG9_PROBE_ATTACKED"] 		= "[probe_type] <font color='yellow'>Probe Destroyed</font>";

$l_log_text["LOG9_PROBEHUNTER_SUCCEED"] = "Joku Probe Mets�st�j� on tuhoutunut [probe_type] omistama [name] ja [sector].";
$l_log_title["LOG9_PROBEHUNTER_SUCCEED"] = "Probe Hunter tuhottu [probe_type]";
$l_log_text["LOG9_PROBEHUNTER_DESTROYED"] = "Omat [probe_type] sektori [sector] hy�kk�si ja tuhosi Probe Hunter omistama [name].";
$l_log_title["LOG9_PROBEHUNTER_DESTROYED"] 		= "[probe_type] <font color='yellow'>Probe Attacked and Destroyed</font>";
$l_log_text["LOG9_PROBEHUNTER_EXPLODED"] = "Sinun Probe Hunter sektori [sector] menetettiin, kun R�j�hdys sen hy�kk�yksen [probe_type] omistama [name] vaipattomia sit�.";
$l_log_title["LOG9_PROBEHUNTER_EXPLODED"] 		= "Probe Hunter Probe <font color='yellow'>Destroyed</font>";


?>
