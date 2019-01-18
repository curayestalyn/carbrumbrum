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
//New
#include "imgpath.h"
#include "soundpath.h"
#include "menu.h"

#include <SDL.h>
#include <SDL_render.h>
void sarreraMezuaIdatzi();
int JOKOAREN_argazkiakGehitu(argazkia);

//int  BUKAERA_menua(EGOERA egoera);
//int BUKAERA_irudiaBistaratu();

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int bateria, int bizitzakAldatu);
JOKO_ELEMENTUA oztopoakAgertzeko(JOKO_ELEMENTUA oztopoa);
JOKO_ELEMENTUA argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa);
void aukerakAldatu(menuAukerak);
void pausaMenua(void);
void bateriaw(bigarrenKontagailua, kontagailuBateria, bateria);
int konprobatuPosizioa(JOKO_ELEMENTUA elementua1, JOKO_ELEMENTUA elementua2);
JOKO_ELEMENTUA oztopoakMugitzeko(JOKO_ELEMENTUA oztopoa);

/**************************JOKOAREN INTERAKZIOA**********************************/
//JOKOA_ELEMENTUA [elementu] Jokoaren POSIZIOA pos.[x,y] 
//Jokoaren background: background, marrak1,marrak2
//Jokoaren garajea: jokalaria, oztopoa, oztopoa2, oztopoa3, oztopoa4,oztopoa5
//Jokoaren elementuak: txanpona, energyfull, deposito1,gasolina,bateria1,bizitzak1,bizitzak2, bizitzak3
EGOERA jokatu(void)
{
	EGOERA  egoera = JOLASTEN;
	int ebentu = 0;
	int kontagailuEnergia = 1, kontagailuBateria = 1, bateria = 0, bizitzakAldatu = 0, kontCarCrashes = 0;
	int bidea = 0, numero = 0, denbora = 2, kontagailuMoteldu = 0, bigarrenKontagailua = 0, kontagailuMugimendua = 0, txanponakScore = 0;
	int idAudioGame;
	char buffer[50];
	int jumpMax = 0;
	int tmp = 0;
	int bateraDaude = 0;



	JOKO_ELEMENTUA cielo1, cielo2, desierto, oztopoa, oztopoa2, oztopoa3, oztopoa4, oztopoa5, oztopoa6, jokalaria, gasolina, background, marrak1, marrak2, txanpona, energybull, deposito1, deposito2, deposito3, deposito4, bizitzak1, bizitzak2, bizitzak3, bateria1, bateria2, bateria3, bateria4, bateria5, scorebox;
	POSIZIOA aux;

	cielo1.pos.x = 0;
	cielo1.pos.y = -480;

	cielo2.pos.x = 0;
	cielo2.pos.y = -960;

	background.pos.x = 0;
	background.pos.y = 0;

	scorebox.pos.x = 0;
	scorebox.pos.y = 0;

	marrak1.pos.x = 0;
	marrak1.pos.y = 0;

	marrak2.pos.x = 0;
	marrak2.pos.y = -480;

	jokalaria.pos.x = 340;
	jokalaria.pos.y = 340;

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

	txanpona.pos.x = 235;
	txanpona.pos.y = 340;

	energybull.pos.x = 100;
	energybull.pos.y = 215;

	deposito1.pos.x = 540;
	deposito1.pos.y = 330;

	gasolina.pos.x = 380;
	gasolina.pos.y = 0;

	bateria1.pos.x = 540;
	bateria1.pos.y = 230;

	bizitzak1.pos.x = 540;
	bizitzak1.pos.y = 17;

	bizitzak2.pos.x = 574;
	bizitzak2.pos.y = 17;

	bizitzak3.pos.x = 607;
	bizitzak3.pos.y = 17;

	desierto.pos.x = 0;
	desierto.pos.y = -480;

	scorebox.pos.x = 574;
	scorebox.pos.y = 200;

	audioInit();
	loadTheMusic(JOKOA_SOUND);
	playMusic();

	background.id = JOKOAREN_argazkiakGehitu(BACKGROUND_IMAGE);
	scorebox.id = JOKOAREN_argazkiakGehitu(SCOREBOX_IMAGE);
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
	//If switch
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
	scorebox.id = JOKOAREN_argazkiakGehitu(SCOREBOX_IMAGE);


	/***************LOOP BEGINNING*********/
	do {
		Sleep(denbora);
		kontagailuMugimendua++;
		pantailaGarbitu();
		/*******************OZTOPOAK*******************/
		oztopoa = argazkiakMugiarazi(oztopoa);
		if (kontagailuMugimendua > 1000){oztopoa2 = argazkiakMugiarazi(oztopoa2);}
		else if (kontagailuMugimendua > 2000){oztopoa3 = argazkiakMugiarazi(oztopoa3);}
		else if (kontagailuMugimendua > 3000){oztopoa4 = argazkiakMugiarazi(oztopoa4);}
		else if (kontagailuMugimendua > 4000){oztopoa5 = argazkiakMugiarazi(oztopoa5);}
		else if (kontagailuMugimendua > 50000){oztopoa6 = argazkiakMugiarazi(oztopoa6);}

		if (kontagailuMugimendua < 8000 && kontagailuMugimendua > 5000)
		{
			desierto = argazkiakMugiarazi(desierto);
			if (desierto.pos.y > 0){irudiaMugitu(desierto.id, 0, 0);}
		}

		if (kontagailuMugimendua > 8000)
		{
			cielo1 = argazkiakMugiarazi(cielo1);
			cielo2 = argazkiakMugiarazi(cielo2);
			if (cielo1.pos.y > 480) { cielo1.pos.y = -480; }
			if (cielo2.pos.y > 480) { cielo2.pos.y = -480; }
		}
	
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
		/***TECLA_SPACE ematerakoan erabiltzailea moteltzeko abilitatea lortzen du***/
		if (ebentu == TECLA_SPACE && kontagailuEnergia >= 4) 
		{
			denbora = 5;
			kontagailuEnergia = 1;
			argazkiakAldatu(kontagailuEnergia);
		}
		if (denbora == 5) { kontagailuMoteldu++; }
		if (kontagailuMoteldu >= 500)
		{
			denbora = 2;
			kontagailuMoteldu = 0;
		}
		/***Jokalarien kotxea x ardatza mugitzeko, ezkerra eta eskuma***/
		if (ebentu == TECLA_RIGHT || ebentu == TECLA_d)
		{
			aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
			jokalaria.pos.x = aux.x + 19;
		}
		if (ebentu == TECLA_LEFT || ebentu == TECLA_a) {
			aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
			jokalaria.pos.x = aux.x - 20;
		}

		if (marrak1.pos.y > 480) {
			marrak1.pos.y = -480;
		}
		if (marrak2.pos.y > 480) {
			marrak2.pos.y = -480;
		}

		if (txanpona.pos.y > 480)
		{
			numero = zenbakiRandom();
			txanpona.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			txanpona.pos.x = 95 + bidea;
		}
		if (jokalaria.pos.x > txanpona.pos.x - 43 && jokalaria.pos.x <txanpona.pos.x + 33 && jokalaria.pos.y + 33 >txanpona.pos.y - 33 && jokalaria.pos.y - 33 < txanpona.pos.y + 33)
		{	
			idAudioGame = loadSound(TXANPON_SOINUA);
			playSound(idAudioGame);

			numero = zenbakiRandom();
			txanpona.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			txanpona.pos.x = 95 + bidea;
			txanponakScore++;
		}

		if (jokalaria.pos.x > gasolina.pos.x - 43 && jokalaria.pos.x < gasolina.pos.x + 33 && jokalaria.pos.y + 33 > gasolina.pos.y - 33 && jokalaria.pos.y - 33 < gasolina.pos.y + 33)
		{
			idAudioGame = loadSound(GASOLINA_SOINUA);
			playSound(idAudioGame);
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
		
		if (oztopoa.pos.y < -100 && oztopoa.pos.y > -200)
		{
			bateraDaude = konprobatuPosizioa(oztopoa, txanpona);
			if (bateraDaude == 1)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, energybull);
			if (bateraDaude == 1)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, gasolina);
			if (bateraDaude == 1)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, oztopoa2);
			if (bateraDaude == 1 && kontagailuMugimendua > 1000)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, oztopoa3);
			if (bateraDaude == 1 && kontagailuMugimendua > 2000)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, oztopoa4);
			if (bateraDaude == 1 && kontagailuMugimendua > 3000)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, oztopoa5);
			if (bateraDaude == 1 && kontagailuMugimendua > 4000)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
			bateraDaude = konprobatuPosizioa(oztopoa, oztopoa6);
			if (bateraDaude == 1 && kontagailuMugimendua > 50000)
			{
				oztopoa = oztopoakMugitzeko(oztopoa);
			}
		}
		if (oztopoa2.pos.y < -100 && oztopoa2.pos.y > -200 && kontagailuMugimendua > 1000)
		{
			bateraDaude = konprobatuPosizioa(oztopoa2, txanpona);
			if (bateraDaude == 1)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
			bateraDaude = konprobatuPosizioa(oztopoa2, energybull);
			if (bateraDaude == 1)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
			bateraDaude = konprobatuPosizioa(oztopoa2, gasolina);
			if (bateraDaude == 1)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
			bateraDaude = konprobatuPosizioa(oztopoa2, oztopoa3);
			if (bateraDaude == 1 && kontagailuMugimendua > 2000)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
			bateraDaude = konprobatuPosizioa(oztopoa2, oztopoa4);
			if (bateraDaude == 1 && kontagailuMugimendua > 3000)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
			bateraDaude = konprobatuPosizioa(oztopoa2, oztopoa5);
			if (bateraDaude == 1 && kontagailuMugimendua > 4000)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
			bateraDaude = konprobatuPosizioa(oztopoa2, oztopoa6);
			if (bateraDaude == 1 && kontagailuMugimendua > 50000)
			{
				oztopoa2 = oztopoakMugitzeko(oztopoa2);
			}
		}
		if (oztopoa3.pos.y < -100 && oztopoa3.pos.y > -200 && kontagailuMugimendua > 2000)
		{
			bateraDaude = konprobatuPosizioa(oztopoa3, txanpona);
			if (bateraDaude == 1)
			{
				oztopoa3 = oztopoakMugitzeko(oztopoa3);
			}
			bateraDaude = konprobatuPosizioa(oztopoa3, energybull);
			if (bateraDaude == 1)
			{
				oztopoa3 = oztopoakMugitzeko(oztopoa3);
			}
			bateraDaude = konprobatuPosizioa(oztopoa3, gasolina);
			if (bateraDaude == 1)
			{
				oztopoa3 = oztopoakMugitzeko(oztopoa3);
			}
			bateraDaude = konprobatuPosizioa(oztopoa3, oztopoa4);
			if (bateraDaude == 1 && kontagailuMugimendua > 3000)
			{
				oztopoa3 = oztopoakMugitzeko(oztopoa3);
			}
			bateraDaude = konprobatuPosizioa(oztopoa3, oztopoa5);
			if (bateraDaude == 1 && kontagailuMugimendua > 4000)
			{
				oztopoa3 = oztopoakMugitzeko(oztopoa3);
			}
			bateraDaude = konprobatuPosizioa(oztopoa3, oztopoa6);
			if (bateraDaude == 1 && kontagailuMugimendua > 50000)
			{
				oztopoa3 = oztopoakMugitzeko(oztopoa3);
			}
		}
		if (oztopoa4.pos.y < -100 && oztopoa4.pos.y > -200 && kontagailuMugimendua > 3000)
		{
			bateraDaude = konprobatuPosizioa(oztopoa4, txanpona);
			if (bateraDaude == 1)
			{
				oztopoa4 = oztopoakMugitzeko(oztopoa4);
			}
			bateraDaude = konprobatuPosizioa(oztopoa4, energybull);
			if (bateraDaude == 1)
			{
				oztopoa4 = oztopoakMugitzeko(oztopoa4);
			}
			bateraDaude = konprobatuPosizioa(oztopoa4, gasolina);
			if (bateraDaude == 1)
			{
				oztopoa4 = oztopoakMugitzeko(oztopoa4);
			}
			bateraDaude = konprobatuPosizioa(oztopoa4, oztopoa5);
			if (bateraDaude == 1 && kontagailuMugimendua > 4000)
			{
				oztopoa4 = oztopoakMugitzeko(oztopoa4);
			}
			bateraDaude = konprobatuPosizioa(oztopoa4, oztopoa6);
			if (bateraDaude == 1 && kontagailuMugimendua > 50000)
			{
				oztopoa4 = oztopoakMugitzeko(oztopoa4);
			}
		}
		if (oztopoa5.pos.y < -100 && oztopoa5.pos.y > -200 && kontagailuMugimendua < 4000)
		{
			bateraDaude = konprobatuPosizioa(oztopoa5, txanpona);
			if (bateraDaude == 1)
			{
				oztopoa5 = oztopoakMugitzeko(oztopoa5);
			}
			bateraDaude = konprobatuPosizioa(oztopoa5, energybull);
			if (bateraDaude == 1)
			{
				oztopoa5 = oztopoakMugitzeko(oztopoa5);
			}
			bateraDaude = konprobatuPosizioa(oztopoa5, gasolina);
			if (bateraDaude == 1)
			{
				oztopoa5 = oztopoakMugitzeko(oztopoa5);
			}
			bateraDaude = konprobatuPosizioa(oztopoa5, oztopoa6);
			if (bateraDaude == 1 && kontagailuMugimendua > 50000)
			{
				oztopoa5 = oztopoakMugitzeko(oztopoa5);
			}
		}
		if (oztopoa6.pos.y < -100 && oztopoa6.pos.y > -200 && kontagailuMugimendua > 50000)
		{
			bateraDaude = konprobatuPosizioa(oztopoa6, txanpona);
			if (bateraDaude == 1)
			{
				oztopoa6 = oztopoakMugitzeko(oztopoa6);
			}
			bateraDaude = konprobatuPosizioa(oztopoa6, energybull);
			if (bateraDaude == 1)
			{
				oztopoa6 = oztopoakMugitzeko(oztopoa6);
			}
			bateraDaude = konprobatuPosizioa(oztopoa6, gasolina);
			if (bateraDaude == 1)
			{
				oztopoa6 = oztopoakMugitzeko(oztopoa6);
			}
		}

		if (jokalaria.pos.x > energybull.pos.x - 43 && jokalaria.pos.x <energybull.pos.x + 33 && jokalaria.pos.y + 33 >energybull.pos.y - 33 && jokalaria.pos.y - 33 < energybull.pos.y + 33)
		{
			kontagailuEnergia++;
			argazkiakAldatu(kontagailuEnergia);

			idAudioGame = loadSound(REDBULL_SOINUA);
			playSound(idAudioGame);

			numero = zenbakiRandom();
			energybull.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			energybull.pos.x = 95 + bidea;
		}

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

		if (energybull.pos.y > 480)
		{
			numero = zenbakiRandom();
			energybull.pos.y = -100 - numero;
			bidea = aukeratuBidea();
			energybull.pos.x = 95 + bidea;
		}

		oztopoa = oztopoakAgertzeko(oztopoa);
		oztopoa2 = oztopoakAgertzeko(oztopoa2);
		oztopoa3 = oztopoakAgertzeko(oztopoa3);
		oztopoa4 = oztopoakAgertzeko(oztopoa4);
		oztopoa5 = oztopoakAgertzeko(oztopoa5);
		oztopoa6 = oztopoakAgertzeko(oztopoa6);
		bateriaw(bigarrenKontagailua, kontagailuBateria, bateria);
		bigarrenKontagailua++;
		
		

		egoera = JOKOA_egoera(jokalaria, oztopoa, bateria, bizitzakAldatu);
		/*jump*/			
		if (ebentu == TECLA_g && txanponakScore >=3)
		{
			jokalaria.pos.x = jokalaria.pos.x + 50;
			txanponakScore = txanponakScore - 3;
		}
		if (ebentu == TECLA_f && txanponakScore >= 3)
		{
			jokalaria.pos.x = jokalaria.pos.x - 50;
			txanponakScore = txanponakScore - 3;
		}
		/*jump*/
		if (egoera == JOLASTEN)
		{
			egoera = JOKOA_egoera(jokalaria, oztopoa2, bateria, bizitzakAldatu);
		}
		if (egoera == JOLASTEN)
		{
			egoera = JOKOA_egoera(jokalaria, oztopoa3, bateria, bizitzakAldatu);
		}
		if (egoera == JOLASTEN)
		{
			egoera = JOKOA_egoera(jokalaria, oztopoa4, bateria, bizitzakAldatu);
		}
		if (egoera == JOLASTEN)
		{
			egoera = JOKOA_egoera(jokalaria, oztopoa5, bateria, bizitzakAldatu);
		}
		if (egoera == JOLASTEN)
		{
			egoera = JOKOA_egoera(jokalaria, oztopoa6, bateria, bizitzakAldatu);
		}

		if (ebentu == TECLA_ESCAPE)
		{
			//jokoaAurkeztu();
			sarreraArgazkiaAplikatu(PAUSA_JARRAITU);
			pausaMenua();
		}
		sprintf(buffer, "%d", txanponakScore);
		textuaIdatzi(574, 200, buffer);

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

/************************ZATI HONETAN INTERAKZIOA SORTU DA, ERABILTZAILEA GALTZEN DENEAN************************/
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int bateria, int bizitzakAldatu) {
	EGOERA  ret = JOLASTEN;
	if (bizitzakAldatu == 3)
	{
		ret = GALDU;
	}
	else if (jokalaria.pos.x > 476 || jokalaria.pos.x < 64)
	{
		ret = GALDU;
	}
	else if (bateria == 1)
	{
		ret = GALDU;
	}
	return ret;
}
/***********************HEMENDIK BEHERA FUNTZIOAK DAUDE*******************/

JOKO_ELEMENTUA oztopoakAgertzeko(JOKO_ELEMENTUA oztopoa)
{
	int numero = 0, bidea = 0;

	if (oztopoa.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		oztopoa.pos.x = 85 + bidea;
	}
	return oztopoa;
}

JOKO_ELEMENTUA argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa)
{
	POSIZIOA aux;
	aux = ERREALITATE_FISIKOA_mugimendua(oztopoa.pos);
	oztopoa.pos.y = aux.y;
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
	return oztopoa;
}
////////////////////////////////////////////////////

int JOKOAREN_argazkiakGehitu(char * argazkia)
{
	int jokalariaId = -1;
	jokalariaId = irudiaKargatu(argazkia);
	return jokalariaId;
}

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa) {
	posizioa.y = posizioa.y + 2;
	posizioa.x = posizioa.x + 1;
	return posizioa;
}

int  jokoAmaierakoa(EGOERA egoera)
{
	int ebentu = 0, id;
	int idAudioGame;
	int balioa;

	loadTheMusic(BUKAERA_SOUND_1);
	if (egoera == GALDU) {
		idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
		playSound(idAudioGame);
	}
	id = BUKAERA_irudiaBistaratu();
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

void argazkiakAldatu(kontagailuEnergia)
{
	if (kontagailuEnergia >= 5) { kontagailuEnergia = 4; }
	else if (kontagailuEnergia == 4) {
		ArgazkiaAplikatu(DEPOSITO1_IMAGE);
	}
	else if (kontagailuEnergia == 3) {
		ArgazkiaAplikatu(DEPOSITO2_IMAGE);
	}
	else if (kontagailuEnergia == 2) {
		ArgazkiaAplikatu(DEPOSITO3_IMAGE);
	}
	else if (kontagailuEnergia == 1) {
		ArgazkiaAplikatu(DEPOSITO4_IMAGE);
	}
}
void bateriaArgazkiaAldatu(kontagailuBateria)
{
	if (kontagailuBateria == 5) {
		bateriaArgazkiaAplikatu(BATERIA5_IMAGE);
	}
	else if (kontagailuBateria == 4) {
		bateriaArgazkiaAplikatu(BATERIA4_IMAGE);
	}
	else if (kontagailuBateria == 3) {
		bateriaArgazkiaAplikatu(BATERIA3_IMAGE);
	}
	else if (kontagailuBateria == 2) {
		bateriaArgazkiaAplikatu(BATERIA2_IMAGE);
	}
	else if (kontagailuBateria == 1) {
		bateriaArgazkiaAplikatu(BATERIA1_IMAGE);
	}
}

void ArgazkiaAplikatu(char *argazkia)
{
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 540, 330);
	irudiakMarraztu();
	pantailaBerriztu();
}
void bateriaArgazkiaAplikatu(char *argazkia) {
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 540, 230);
	irudiakMarraztu();
	pantailaBerriztu();
}

int aukeratuBidea()
{
	int dBide = 0, Bide;

	Bide = rand() % 4;

	if (Bide == 0)
	{
		dBide = 0;
	}
	if (Bide == 1)
	{
		dBide = 125;
	}
	if (Bide == 2)
	{
		dBide = 250;
	}
	if (Bide == 3)
	{
		dBide = 365;

	}
	return dBide;
}

int zenbakiRandom() {
	int numero;
	numero = rand() % 1000;
	return numero;
}


int BUKAERA_irudiaBistaratu() {
	int id = -1;
	id = irudiaKargatu(BUKAERA_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

void pausaMenua(void)
{
	int ebentu = 0, menuAukerak = 1;
	//menulanguntza.id = JOKOAREN_argazkiakGehitu(MENULAGUNTZA_IMAGE);
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN && menuAukerak != 0) {
			menuAukerak--;
			aukerakAldatu(menuAukerak);
		}
		if (ebentu == TECLA_UP && menuAukerak != 1) {
			menuAukerak++;
			aukerakAldatu(menuAukerak);
		}
	} while (ebentu != TECLA_RETURN);
	if (menuAukerak != 1)
		jokoaAurkeztu();
	//aukeraExekutatu(menuAukerak);
	pantailaGarbitu();
	pantailaBerriztu();
}
void aukerakAldatu(menuAukerak)
{
	if (menuAukerak >= 1) { menuAukerak = 1; }
	if (menuAukerak < 1) { menuAukerak = 0; }
	if (menuAukerak == 0) {
		sarreraArgazkiaAplikatu(PAUSA_ATERA);
	}
	if (menuAukerak == 1) {
		sarreraArgazkiaAplikatu(PAUSA_JARRAITU);
	}
}
void aukeraExekutatu(menuAukerak)
{
	int ebentu = 0;

	if (menuAukerak == 1)
	{
		//goto line 69;
		jokatu();
	}
	else if (menuAukerak == 0)
	{
		jokoaAurkeztu();
	}
}

void bateriaw(bigarrenKontagailua, kontagailuBateria, bateria)
{
	if (bigarrenKontagailua == 0) {
		kontagailuBateria = 1;
		bateriaArgazkiaAldatu(kontagailuBateria);
	}
	else if (bigarrenKontagailua == 3000)
	{
		kontagailuBateria = 2;
		bateriaArgazkiaAldatu(kontagailuBateria);
	}
	else if (bigarrenKontagailua == 6000)
	{
		kontagailuBateria = 3;
		bateriaArgazkiaAldatu(kontagailuBateria);
	}
	else if (bigarrenKontagailua == 9000)
	{
		kontagailuBateria = 4;
		bateriaArgazkiaAldatu(kontagailuBateria);
	}
	else if (bigarrenKontagailua == 12000)
	{
		kontagailuBateria = 5;
		bateriaArgazkiaAldatu(kontagailuBateria);
	}
	else if (bigarrenKontagailua == 13000) {
		bateria = 1;
		irudiakMarraztu();
		pantailaBerriztu();
	}
}

int konprobatuPosizioa(JOKO_ELEMENTUA elementua1, JOKO_ELEMENTUA
	elementua2)
{
	int bateraDaude = 0;
	if (elementua1.pos.x == elementua2.pos.x)
	{
		if (elementua1.pos.y + 22 >= elementua2.pos.y - 34 || elementua1.pos.y - 22

			<= elementua2.pos.y + 34)

		{
			bateraDaude = 1;
		}
	}
	return bateraDaude;
}
JOKO_ELEMENTUA oztopoakMugitzeko(JOKO_ELEMENTUA oztopoa)
{
	int numero = 0, bidea = 0;
	numero = zenbakiRandom();
	oztopoa.pos.y = -100 - numero;
	bidea = aukeratuBidea();
	oztopoa.pos.x = 85 + bidea;
	return oztopoa;
}