#define _CRT_SECURE_NO_WARNINGS
#include "cargame.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "menu.h"
#include "imgpath.h"
#include "soundpath.h"


/**************************JOKOAREN INTERAKZIOA**********************************/
//JOKOA_ELEMENTUA [elementu] Jokoaren POSIZIOA pos.[x,y] 
//Jokoaren background: background, marrak1,marrak2
//Jokoaren garajea: jokalaria, oztopoa, oztopoa2, oztopoa3, oztopoa4,oztopoa5
//Jokoaren elementuak: txanpona, energyBull, deposito1,gasolina,bateria1,bizitzak1,bizitzak2, bizitzak3
EGOERA jokatu(void) 
{
	EGOERA  egoera = JOLASTEN;
  
	int ebentu = 0, bateria = 0, bizitzakAldatu = 0, kontCarCrashes = 0, bidea = 0, numero = 0, denbora = 1, kontagailuMoteldu = 0, bigarrenKontagailua = 0, kontagailuLoop = 0, txanponakScore = 0, salto = 0, saltoMax = 0;
	int kontagailuEnergia = 1, kontagailuBateria = 1;
	int aukera = 2;
	char txanponakBistaratu[50];
  
	JOKO_ELEMENTUA cielo1, cielo2, desierto, oztopoa, oztopoa2, oztopoa3, oztopoa4, oztopoa5, oztopoa6, jokalaria, gasolina, background, marrak1, marrak2, txanpona, energybull, deposito1, deposito2, deposito3, deposito4, bizitzak1, bizitzak2, bizitzak3, bateria1, bateria2, bateria3, bateria4, bateria5,pausa;
	POSIZIOA aux; 
	/*******Eszenaren hasierako posizioa*******/
	background.pos.x = 0;
	background.pos.y = 0;
	marrak1.pos.x = 0;
	marrak1.pos.y = 0;
	marrak2.pos.x = 0;
	marrak2.pos.y = -480;
	cielo1.pos.x = 0;
	cielo1.pos.y = -480;
	cielo2.pos.x = 0;
	cielo2.pos.y = -960;
	desierto.pos.x = 0;
	desierto.pos.y = -480;
	pausa.pos.x = 0;
	pausa.pos.y = 0;
	/*******Jokalarien hasierako posizioa*******/
	jokalaria.pos.x = 340;
	jokalaria.pos.y = 340;
	/*******Oztopoen hasierako posizioa*******/
	oztopoa.pos.x = 80;
	oztopoa.pos.y = 0;
	oztopoa2.pos.x = 80;
	oztopoa2.pos.y = -100;
	oztopoa3.pos.x = 80;
	oztopoa3.pos.y = -100;
	oztopoa4.pos.x = 80;
	oztopoa4.pos.y = -100;
	oztopoa5.pos.x = 80;
	oztopoa5.pos.y = -100;
	oztopoa6.pos.x = 80;
	oztopoa6.pos.y = -100; 
	/*******Elementuen hasierako posizioa*******/
	txanpona.pos.x = 235;
	txanpona.pos.y = 340;
	energybull.pos.x = 100;
	energybull.pos.y = 215;
	gasolina.pos.x = 380;
	gasolina.pos.y = 0;
	/*******Elementu adierazlearen hasierako posizioa*******/
	deposito1.pos.x = 540;
	deposito1.pos.y = 330;
	bateria1.pos.x = 540;
	bateria1.pos.y = 230;
	bizitzak1.pos.x = 540;
	bizitzak1.pos.y = 17;
	bizitzak2.pos.x = 574;
	bizitzak2.pos.y = 17;
	bizitzak3.pos.x = 607;
	bizitzak3.pos.y = 17;

	audioInit();
	loadTheMusic(JOKOA_SOUND);
	playMusic();

	background.id = JOKOAREN_argazkiakGehitu(BACKGROUND_IMAGE);
	desierto.id = JOKOAREN_argazkiakGehitu(DESIERTO_IMAGE);
	cielo1.id = JOKOAREN_argazkiakGehitu(CIELO1_IMAGE);
	cielo2.id = JOKOAREN_argazkiakGehitu(CIELO2_IMAGE);
	oztopoa.id = JOKOAREN_argazkiakGehitu(KOTXEA1_IMAGE);
	oztopoa2.id = JOKOAREN_argazkiakGehitu(KOTXEA2_IMAGE);
	oztopoa3.id = JOKOAREN_argazkiakGehitu(KOTXEA3_IMAGE);
	oztopoa4.id = JOKOAREN_argazkiakGehitu(KOTXEA4_IMAGE);
	oztopoa5.id = JOKOAREN_argazkiakGehitu(KOTXEA5_IMAGE);
	oztopoa6.id = JOKOAREN_argazkiakGehitu(KOTXEA6_IMAGE);
	marrak1.id = JOKOAREN_argazkiakGehitu(MARRAK1_IMAGE);
	marrak2.id = JOKOAREN_argazkiakGehitu(MARRAK2_IMAGE);
	jokalaria.id = JOKOAREN_argazkiakGehitu(JOKOA_PLAYER_IMAGE);
	txanpona.id = JOKOAREN_argazkiakGehitu(TXANPONA_IMAGE);
	energybull.id = JOKOAREN_argazkiakGehitu(ENERGYBULL_IMAGE);
	deposito1.id = JOKOAREN_argazkiakGehitu(DEPOSITO1_IMAGE);
	deposito2.id = JOKOAREN_argazkiakGehitu(DEPOSITO2_IMAGE);
	deposito3.id = JOKOAREN_argazkiakGehitu(DEPOSITO3_IMAGE);
	deposito4.id = JOKOAREN_argazkiakGehitu(DEPOSITO4_IMAGE);
	bizitzak1.id = JOKOAREN_argazkiakGehitu(BIZITZAK_IMAGE);
	bizitzak2.id = JOKOAREN_argazkiakGehitu(BIZITZAK_IMAGE);
	bizitzak3.id = JOKOAREN_argazkiakGehitu(BIZITZAK_IMAGE);
	bateria1.id = JOKOAREN_argazkiakGehitu(BATERIA1_IMAGE);
	bateria2.id = JOKOAREN_argazkiakGehitu(BATERIA2_IMAGE);
	bateria3.id = JOKOAREN_argazkiakGehitu(BATERIA3_IMAGE);
	bateria4.id = JOKOAREN_argazkiakGehitu(BATERIA4_IMAGE);
	bateria5.id = JOKOAREN_argazkiakGehitu(BATERIA5_IMAGE);
	gasolina.id = JOKOAREN_argazkiakGehitu(GASOLINA_IMAGE);

	irudiaMugitu(cielo1.id, cielo1.pos.x, cielo1.pos.y);
	irudiaMugitu(cielo2.id, cielo2.pos.x, cielo2.pos.y);
	irudiaMugitu(desierto.id, desierto.pos.x, desierto.pos.y);
	irudiaMugitu(bizitzak1.id, bizitzak1.pos.x, bizitzak1.pos.y);
	irudiaMugitu(bizitzak2.id, bizitzak2.pos.x, bizitzak2.pos.y);
	irudiaMugitu(bizitzak3.id, bizitzak3.pos.x, bizitzak3.pos.y);
	sarreraArgazkiaAplikatu(SCOREBOX_IMAGE);

	/***************INTERAKZIOREN HASIERA, LOOP-EN BITARTEZ*********/
	do {
		Sleep(denbora);
		kontagailuLoop++;
		pantailaGarbitu();
		/*******************OZTOPOEN AGERPENA DENBORA KONTUAN HARTUTA*******************/
		oztopoa = argazkiakMugiarazi(oztopoa);

		if (kontagailuLoop > 1000)
		{
			oztopoa2 = argazkiakMugiarazi(oztopoa2);
		}
		if (kontagailuLoop > 2000)
		{
			oztopoa3 = argazkiakMugiarazi(oztopoa3);
		}
		if (kontagailuLoop > 3000)
		{
			oztopoa4 = argazkiakMugiarazi(oztopoa4);
		}
		if (kontagailuLoop > 4000)
		{
			oztopoa5 = argazkiakMugiarazi(oztopoa5);
		}
		if (kontagailuLoop > 50000)
		{
			oztopoa6 = argazkiakMugiarazi(oztopoa6);
		}
		/********Eszenaren aldaketa*******/
		if (kontagailuLoop > 5000 && kontagailuLoop < 8000)
		{
			desierto = argazkiakMugiarazi(desierto);
			if (desierto.pos.y > 0)
			{
				irudiaMugitu(desierto.id, 0, 0);
			}
		}
		if (kontagailuLoop > 8000) {
			cielo1 = argazkiakMugiarazi(cielo1);
			cielo2 = argazkiakMugiarazi(cielo2);
			if (cielo1.pos.y > 480)
			{
				cielo1.pos.y = -480;
			}
			if (cielo2.pos.y > 480)
			{
				cielo2.pos.y = -480;
			}
		}
		if (marrak1.pos.y > 480) { marrak1.pos.y = -480; }
		if (marrak2.pos.y > 480) { marrak2.pos.y = -480; }
		marrak1 = argazkiakMugiarazi(marrak1);
		marrak2 = argazkiakMugiarazi(marrak2);
		txanpona = argazkiakMugiarazi(txanpona);
		gasolina = argazkiakMugiarazi(gasolina);
		energybull = argazkiakMugiarazi(energybull);

		irudiaMugitu(deposito1.id, deposito1.pos.x, deposito1.pos.y);
		irudiaMugitu(deposito2.id, deposito1.pos.x, deposito1.pos.y);
		irudiaMugitu(deposito3.id, deposito1.pos.x, deposito1.pos.y);
		irudiaMugitu(deposito4.id, deposito1.pos.x, deposito1.pos.y);

		irudiaMugitu(bateria1.id, bateria1.pos.x, bateria1.pos.y);
		irudiaMugitu(bateria2.id, bateria1.pos.x, bateria1.pos.y);
		irudiaMugitu(bateria3.id, bateria1.pos.x, bateria1.pos.y);
		irudiaMugitu(bateria4.id, bateria1.pos.x, bateria1.pos.y);
		irudiaMugitu(bateria5.id, bateria1.pos.x, bateria1.pos.y);

		irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
		irudiaMugitu(oztopoa2.id, oztopoa2.pos.x, oztopoa2.pos.y);
		irudiaMugitu(oztopoa3.id, oztopoa3.pos.x, oztopoa3.pos.y);
		irudiaMugitu(oztopoa4.id, oztopoa4.pos.x, oztopoa4.pos.y);
		irudiaMugitu(oztopoa5.id, oztopoa5.pos.x, oztopoa5.pos.y);
		irudiaMugitu(oztopoa6.id, oztopoa6.pos.x, oztopoa6.pos.y);

		irudiaMugitu(txanpona.id, txanpona.pos.x, txanpona.pos.y);

		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);

		irudiaMugitu(energybull.id, energybull.pos.x, energybull.pos.y);

		pantailaGarbitu();
		arkatzKoloreaEzarri(0, 0, 0xFF);

		irudiakMarraztu();
		ebentu = ebentuaJasoGertatuBada();
		/*******Moteltzeko abilitatea izateko*******/
		if (ebentu == TECLA_SPACE && kontagailuEnergia >= 4)
		{
			denbora = 5;
			kontagailuEnergia = 1;
			argazkiakAldatu(kontagailuEnergia);
		}
		/*******Moteldu abilezia aktibatzerakon, moteldu kontagailu aktibatzen da******/
		if (denbora == 5) { kontagailuMoteldu++; }
		if (kontagailuMoteldu >= 500)
		{
			denbora = 1;
			kontagailuMoteldu = 0;
		}
		/*******Erabiltzaileak geziak eta (d,a) teklak erabil ditzake*******/
		if (ebentu == TECLA_RIGHT || ebentu == TECLA_d)
		{
			aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
			jokalaria.pos.x = aux.x + 9;
		}
		else if (ebentu == TECLA_LEFT || ebentu == TECLA_a) {
			aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
			jokalaria.pos.x = aux.x - 10;
		}
		/************Jokalariaren kotxea eta txanponaren arteko kolisioa******/
		if (jokalaria.pos.x > txanpona.pos.x - 47 && jokalaria.pos.x <txanpona.pos.x + 27 && jokalaria.pos.y + 24 >txanpona.pos.y - 27 && jokalaria.pos.y - 27 < txanpona.pos.y + 24)
		{
			int idAudioGame;
			idAudioGame = loadSound(TXANPON_SOINUA);
			playSound(idAudioGame);

			numero = zenbakiRandom();
			txanpona.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			txanpona.pos.x = 95 + bidea;
			txanponakScore++;
			saltoMax++;
		}
		if (txanpona.pos.y > 480)
		{
			numero = zenbakiRandom();
			txanpona.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			txanpona.pos.x = 95 + bidea;
		}
		/************Jokalariaren kotxea eta gasolinaren arteko kolisioa******/
		if (jokalaria.pos.x > gasolina.pos.x - 47 && jokalaria.pos.x < gasolina.pos.x + 27 && jokalaria.pos.y + 27 > gasolina.pos.y - 27 && jokalaria.pos.y - 27 < gasolina.pos.y + 27)
		{
			bigarrenKontagailua = 0;
			kontagailuBateria = 1;
			bateriaArgazkiaAldatu(kontagailuBateria);
			gasolina.pos.y = -2500;
			bidea = aukeratuBidea();
			gasolina.pos.x = 95 + bidea;
		}

		if (gasolina.pos.y > 480)
		{
			gasolina.pos.y = -2500;
			bidea = aukeratuBidea();
			gasolina.pos.x = 95 + bidea;
		}
		/************Jokalariaren kotxea eta energyBullaren arteko kolisioa******/
		if (jokalaria.pos.x > energybull.pos.x - 47 && jokalaria.pos.x <energybull.pos.x + 27 && jokalaria.pos.y + 27 >energybull.pos.y - 27 && jokalaria.pos.y - 27 < energybull.pos.y + 27)
		{
			kontagailuEnergia++;
			argazkiakAldatu(kontagailuEnergia);

			int idAudioGame;
			idAudioGame = loadSound(REDBULL_SOINUA);
			playSound(idAudioGame);

			numero = zenbakiRandom();
			energybull.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			energybull.pos.x = 95 + bidea;
		}
		if (energybull.pos.y > 480)
		{
			numero = zenbakiRandom();
			energybull.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			energybull.pos.x = 95 + bidea;

		}
		/************Oztopoen kontra talka egin ondoren, bizitza bat kentzen da, 3 bizitza daude******/
		if (jokalaria.pos.x > oztopoa.pos.x - 30 && jokalaria.pos.x < oztopoa.pos.x + 30 && jokalaria.pos.y + 22 > oztopoa.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa.pos.y + 30 || jokalaria.pos.x > oztopoa2.pos.x - 30 && jokalaria.pos.x < oztopoa2.pos.x + 30 && jokalaria.pos.y + 22 > oztopoa2.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa2.pos.y + 30 || jokalaria.pos.x > oztopoa3.pos.x - 30 && jokalaria.pos.x < oztopoa3.pos.x + 30 && jokalaria.pos.y + 22 > oztopoa3.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa3.pos.y + 30 || jokalaria.pos.x > oztopoa4.pos.x - 30 && jokalaria.pos.x < oztopoa4.pos.x + 30 && jokalaria.pos.y + 22 > oztopoa4.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa4.pos.y + 30 || jokalaria.pos.x > oztopoa5.pos.x - 30 && jokalaria.pos.x < oztopoa5.pos.x + 30 && jokalaria.pos.y + 22 > oztopoa5.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa5.pos.y + 30 || jokalaria.pos.x > oztopoa6.pos.x - 30 && jokalaria.pos.x < oztopoa6.pos.x + 30 && jokalaria.pos.y + 22 > oztopoa6.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa6.pos.y + 30) {
			kontCarCrashes++;
			if (kontCarCrashes == 0)
			{
				bizitzakAldatu = 0;
				bidea = rand() % 1000;
				oztopoa.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa2.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa3.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa4.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa5.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa6.pos.y = -200 - bidea;

				irudiaMugitu(bizitzak1.id, 540, 17);
				irudiaMugitu(bizitzak2.id, 574, 17);
				irudiaMugitu(bizitzak3.id, 607, 17);
			}
			else if (kontCarCrashes == 1)
			{
				int idAudioGame;
				idAudioGame = loadSound(BIZITZA_SOINUA);
				playSound(idAudioGame);

				bizitzakAldatu = 1;
				bidea = rand() % 1000;
				oztopoa.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa2.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa3.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa4.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa5.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa6.pos.y = -200 - bidea;

				irudiaMugitu(bizitzak1.id, 540, -1150);
				irudiaMugitu(bizitzak2.id, 574, 17);
				irudiaMugitu(bizitzak3.id, 607, 17);
			}
			else if (kontCarCrashes == 2)
			{
				int idAudioGame;
				idAudioGame = loadSound(BIZITZA_SOINUA);
				playSound(idAudioGame);

				bizitzakAldatu = 2;
				bidea = rand() % 1000;
				oztopoa.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa2.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa3.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa4.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa5.pos.y = -200 - bidea;
				bidea = rand() % 1000;
				oztopoa6.pos.y = -200 - bidea;
				irudiaMugitu(bizitzak2.id, 574, -1150);
				irudiaMugitu(bizitzak3.id, 607, 17);
			}
			else
			{
				bizitzakAldatu = 3;
				irudiaMugitu(bizitzak3.id, 607, -1100);
			}

		}

		
		oztopoa = oztopoakAgertzeko(oztopoa);
		oztopoa2 = oztopoakAgertzeko(oztopoa2);
		oztopoa3 = oztopoakAgertzeko(oztopoa3);
		oztopoa4 = oztopoakAgertzeko(oztopoa4);
		oztopoa5 = oztopoakAgertzeko(oztopoa5);
		oztopoa6 = oztopoakAgertzeko(oztopoa6);

		if (bigarrenKontagailua == 0) {
			bateriaArgazkiaAldatu(kontagailuBateria);
		}
		if (bigarrenKontagailua == 3000)
		{
			kontagailuBateria = 2;
			bateriaArgazkiaAldatu(kontagailuBateria);
		}
		if (bigarrenKontagailua == 6000)
		{
			kontagailuBateria = 3;
			bateriaArgazkiaAldatu(kontagailuBateria);
		}
		if (bigarrenKontagailua == 9000)
		{
			kontagailuBateria = 4;
			bateriaArgazkiaAldatu(kontagailuBateria);
		}
		if (bigarrenKontagailua == 12000)
		{
			kontagailuBateria = 5;
			bateriaArgazkiaAldatu(kontagailuBateria);
		}
		if (bigarrenKontagailua == 13000) {
			bateria = 1;
			irudiakMarraztu();
			pantailaBerriztu();
		}
		bigarrenKontagailua++;

		if (saltoMax == 3) { salto = salto + 1; saltoMax = 0; }
		if (ebentu == TECLA_g && salto >= 1)
		{
			jokalaria.pos.x = jokalaria.pos.x + 35;
			salto = salto - 1;
		}
		else if (ebentu == TECLA_f && salto >= 1)
		{
			jokalaria.pos.x = jokalaria.pos.x - 35;
			salto = salto - 1;
		}

		egoera = JOKOA_egoera(jokalaria, bateria, bizitzakAldatu);
		/******* aukerak 0 itzultzen badu,  hasierako menura joango da. aukerak 1 itzultzen badu, jokoa jarraituko da.*******/

		if (ebentu == TECLA_ESCAPE)
		{
			audioTerminate();
			int pausaArgazkiaId;
			int idAudioGame;
			pausaArgazkiaId =pausaArgazkiakAplikatu(PAUSA_JARRAITU);
		
			idAudioGame = loadSound(PAUSAON_SOINUA);
			playSound(idAudioGame);
			aukera = pausaMenua();
			if (aukera == 0) 
			{
				egoera = 5;
				break;
			}
			else if (aukera == 1) 
			{
				egoera = JOLASTEN;
				irudiaKendu(pausaArgazkiaId);
				audioInit();
				loadTheMusic(JOKOA_SOUND);
				playMusic();
			}
		}
		sprintf(txanponakBistaratu, "%d", txanponakScore);
		textuaIdatzi(574, 200, txanponakBistaratu);
		pantailaBerriztu();
	 } while (egoera == JOLASTEN);
    /*******************************LOOP FINISIHED*****************/
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}


/*******************************GALDUZ GERO HONAKO EKINTZAK HASIKO DIRA*****************/
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria,int bateria, int bizitzakAldatu) {
	EGOERA  ret = JOLASTEN;
	if (bizitzakAldatu == 3)
	{
		ret = GALDU;
	}
	else if (jokalaria.pos.x > 476 || jokalaria.pos.x < 64)
	{
		ret = GALDU;
	}
	else if(bateria ==1)
	{
		ret = GALDU;
	}
	return ret;
}


int  jokoAmaierakoa(EGOERA egoera)
{
	int ebentu = 0, balioa = 0;
	int idAudioGame;
	int id;

	loadTheMusic(BUKAERA_SOUND_1);
	if(egoera == GALDU)
	{
		idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
		playSound(idAudioGame);
	}
	id=BUKAERA_irudiaBistaratu();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_ESCAPE)
		{
			balioa = 1;
		}

	} while (ebentu != TECLA_ESCAPE);
	audioTerminate();
	irudiaKendu(id);
	return balioa;
}