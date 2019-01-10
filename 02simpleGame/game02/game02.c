#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "jokoaAurkeztu.h"

/**************************IRUDIAK**********************************/
#define TXANPONA_IMAGE ".\\img\\elementua\\txanpona.bmp"
#define ENERGYBULL_IMAGE ".\\img\\elementua\\energybull.bmp"
#define KOTXEA1_IMAGE ".\\img\\garajea\\policecar20.bmp"
#define KOTXEA2_IMAGE ".\\img\\garajea\\ssportcar20.bmp"
#define KOTXEA3_IMAGE ".\\img\\garajea\\ambulance10.bmp"
#define KOTXEA4_IMAGE ".\\img\\garajea\\ssportcar60.bmp"
#define KOTXEA5_IMAGE ".\\img\\garajea\\ssportcar50.bmp"
#define KOTXEA6_IMAGE ".\\img\\garajea\\txalupa10.bmp"
#define BACKGROUND_IMAGE ".\\img\\carretera.bmp"
#define MARRAK1_IMAGE ".\\img\\marrak.bmp"
#define MARRAK2_IMAGE ".\\img\\marrak2.bmp"
#define JOKOA_PLAYER_IMAGE ".\\img\\garajea\\jokalaria.bmp"
#define BIZITZAK_IMAGE ".\\img\\elementua\\life.bmp"
#define DEPOSITO1_IMAGE ".\\img\\elementua\\deposito1.bmp"
#define DEPOSITO2_IMAGE ".\\img\\elementua\\deposito2.bmp"
#define DEPOSITO3_IMAGE ".\\img\\elementua\\deposito3.bmp"
#define DEPOSITO4_IMAGE ".\\img\\elementua\\deposito4.bmp"
#define PETROLEOA_IMAGE ".\\img\\elementua\\petrol.bmp"
#define BATERIA1_IMAGE ".\\img\\elementua\\bateria1.bmp"
#define BATERIA2_IMAGE ".\\img\\elementua\\bateria2.bmp"
#define BATERIA3_IMAGE ".\\img\\elementua\\bateria3.bmp"
#define BATERIA4_IMAGE ".\\img\\elementua\\bateria4.bmp"
#define BATERIA5_IMAGE ".\\img\\elementua\\bateria5.bmp"
#define GASOLINA_IMAGE ".\\img\\elementua\\petrol.bmp"
/**************************SOINUA**********************************/
#define JOKOA_SOUND ".\\sound\\132TRANCE_02.wav"
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\gameovervoice.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"
#define TXANPON_SOINUA ".\\sound\\pickingupcoins.wav"
#define REDBULL_SOINUA ".\\sound\\redbull.wav"
#define BIZITZA_SOINUA ".\\sound\\losinghearts.wav"
int JOKOAREN_argazkiakGehitu(argazkia);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa, int bateria, int bizitzakAldatu);



/**************************JOKOAREN INTERAKZIOA**********************************/
//JOKOA_ELEMENTUA [elementu] Jokoaren POSIZIOA pos.[x,y] 
//Jokoaren background: background, marrak1,marrak2
//Jokoaren garajea: jokalaria, oztopoa, oztopoa2, oztopoa3, oztopoa4,oztopoa5
//Jokoaren elementuak: txanpona, energyfull, deposito1,gasolina,bateria1,bizitzak1,bizitzak2, bizitzak3
EGOERA jokatu(void) 
{
  EGOERA  egoera = JOLASTEN;
  
  
  
  //int ebentu = 0, bidea = 0, numero = 0, kontagailu = 0, kont = 0, bigarrenKontagailua = 0, bateria = 0, bizitzakAldatu = 0, kontCarCrashes = 0, txanponakScore = 0, kontagailuEnergia = 1, kontagailuBateria = 1, denbora = 2;
  
  int ebentu = 0;
  int kontagailuEnergia= 1, kontagailuBateria = 1, bateria = 0, bizitzakAldatu = 0, kontCarCrashes = 0;
  int bidea = 0, numero = 0, denbora = 2, kontagailu = 0, bigarrenKontagailua = 0, kont = 0;
  int txanponakScore = 0;


  
  JOKO_ELEMENTUA oztopoa, oztopoa2, oztopoa3, oztopoa4, oztopoa5, oztopoa6, jokalaria, gasolina, background, marrak1, marrak2, txanpona, energybull, deposito1, deposito2, deposito3, deposito4, bizitzak1, bizitzak2, bizitzak3, bateria1, bateria2, bateria3, bateria4, bateria5;
  POSIZIOA aux;
  
  background.pos.x = 0;
  background.pos.y = 0;

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

  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();
  background.id = JOKOAREN_argazkiakGehitu(BACKGROUND_IMAGE);
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
  
 
	irudiaMugitu(bizitzak1.id, bizitzak1.pos.x, bizitzak1.pos.y);
 	irudiaMugitu(bizitzak2.id, bizitzak2.pos.x, bizitzak2.pos.y);
	irudiaMugitu(bizitzak3.id, bizitzak3.pos.x, bizitzak3.pos.y);
  do {
	Sleep(denbora);
	kont++;
	/*******************OZTOPOAK*******************/
	aux = ERREALITATE_FISIKOA_mugimendua(oztopoa.pos);
	oztopoa.pos.y = aux.y;
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
	
	if (kont > 1000)
	{
		aux = ERREALITATE_FISIKOA_mugimendua(oztopoa2.pos);
		oztopoa2.pos.y = aux.y;
		irudiaMugitu(oztopoa2.id, oztopoa2.pos.x, oztopoa2.pos.y);
	}

	if (kont > 2000)
	{
		aux = ERREALITATE_FISIKOA_mugimendua(oztopoa3.pos);
		oztopoa3.pos.y = aux.y;
		irudiaMugitu(oztopoa3.id, oztopoa3.pos.x, oztopoa3.pos.y);
	}

	if (kont > 3000)
	{
		aux = ERREALITATE_FISIKOA_mugimendua(oztopoa4.pos);
		oztopoa4.pos.y = aux.y;
		irudiaMugitu(oztopoa4.id, oztopoa4.pos.x, oztopoa4.pos.y);
	}

	if (kont > 4000)
	{
		aux = ERREALITATE_FISIKOA_mugimendua(oztopoa5.pos);
		oztopoa5.pos.y = aux.y;
		irudiaMugitu(oztopoa5.id, oztopoa5.pos.x, oztopoa5.pos.y);
	}

	if (kont > 50000)
	{
		aux = ERREALITATE_FISIKOA_mugimendua(oztopoa6.pos);
		oztopoa6.pos.y = aux.y;
		irudiaMugitu(oztopoa6.id, oztopoa6.pos.x, oztopoa6.pos.y);
	}
	
	aux = ERREALITATE_FISIKOA_mugimendua(marrak1.pos);
	marrak1.pos.y = aux.y;
	irudiaMugitu(marrak1.id, marrak1.pos.x, marrak1.pos.y);
	
	aux = ERREALITATE_FISIKOA_mugimendua(marrak2.pos);
	marrak2.pos.y = aux.y;
	irudiaMugitu(marrak2.id, marrak2.pos.x, marrak2.pos.y);
	
	aux = ERREALITATE_FISIKOA_mugimendua(txanpona.pos);
	txanpona.pos.y = aux.y;
	irudiaMugitu(txanpona.id, txanpona.pos.x, txanpona.pos.y);
	
	aux = ERREALITATE_FISIKOA_mugimendua(gasolina.pos);
	gasolina.pos.y = aux.y;
	irudiaMugitu(gasolina.id, gasolina.pos.x, gasolina.pos.y);

	aux = ERREALITATE_FISIKOA_mugimendua(energybull.pos);
	energybull.pos.y = aux.y;
	irudiaMugitu(energybull.id, energybull.pos.x, energybull.pos.y);
	
 	
	
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
    pantailaBerriztu();
    ebentu = ebentuaJasoGertatuBada();
	//Moteltzeko abilitatea izateko
	if (ebentu == TECLA_SPACE && kontagailuEnergia >= 4) {
		denbora = 5;
		kontagailuEnergia= 1;
		argazkiakAldatu(kontagailuEnergia);
	}
	//Moteldu denbora jartzeko
	if (denbora == 5) {
		kontagailu++;
	}
	if(kontagailu >= 500) {
		denbora = 2;
		kontagailu = 0;
	}
    if (ebentu == TECLA_RIGHT)
    {
		aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
		jokalaria.pos.x = aux.x+9;
    }
	if (ebentu == TECLA_LEFT) {
		aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
		jokalaria.pos.x = aux.x-10;
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
	if (jokalaria.pos.x > txanpona.pos.x - 20 && jokalaria.pos.x <txanpona.pos.x + 20 && jokalaria.pos.y + 22 >txanpona.pos.y - 15 && jokalaria.pos.y - 22 < txanpona.pos.y + 15)
	{
		int idAudioGame;
		idAudioGame = loadSound(TXANPON_SOINUA);
		playSound(idAudioGame);

		numero = zenbakiRandom();
		txanpona.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		txanpona.pos.x = 95 + bidea;
		txanponakScore++;
	}

	if (jokalaria.pos.x > gasolina.pos.x - 23 && jokalaria.pos.x < gasolina.pos.x + 23 && jokalaria.pos.y + 23 > gasolina.pos.y - 23 && jokalaria.pos.y - 16 < gasolina.pos.y + 23)
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
	if (jokalaria.pos.x > energybull.pos.x - 23 && jokalaria.pos.x <energybull.pos.x + 23 && jokalaria.pos.y + 23 >energybull.pos.y - 23 && jokalaria.pos.y - 23 < energybull.pos.y + 23)
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
	if (jokalaria.pos.x > oztopoa.pos.x - 30 && jokalaria.pos.x <oztopoa.pos.x + 30 && jokalaria.pos.y + 22 >oztopoa.pos.y - 34 && jokalaria.pos.y - 22 < oztopoa.pos.y + 30) {
		kontCarCrashes++;
		if (kontCarCrashes == 0)
		{
			bizitzakAldatu = 0;
			oztopoa.pos.y = -200;
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
			int id = 1;
			oztopoa.pos.y = -200;
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
			int id = 1;
			oztopoa.pos.y = -200;
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
    if (oztopoa.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa.pos.y = -100-numero;
		bidea = aukeratuBidea();
		oztopoa.pos.x = 85 + bidea;
    }
	if (oztopoa2.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa2.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		oztopoa2.pos.x = 85 + bidea;
		/*konprobatuPosizioa(oztopoa2, oztopoa3);
		konprobatuPosizioa(oztopoa2, oztopoa4);
		konprobatuPosizioa(oztopoa2, oztopoa5);
		konprobatuPosizioa(oztopoa2, oztopoa6);*/

	}
	if (oztopoa3.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa3.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		oztopoa3.pos.x = 85 + bidea;
		//konprobatuPosizioa(oztopoa3, oztopoa4);
		//konprobatuPosizioa(oztopoa3, oztopoa5);
		//konprobatuPosizioa(oztopoa3, oztopoa6);

	}
	if (oztopoa4.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa4.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		oztopoa4.pos.x = 85 + bidea;
		//konprobatuPosizioa(oztopoa4, oztopoa5);
		//konprobatuPosizioa(oztopoa4, oztopoa6);

	}
	if (oztopoa5.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa5.pos.y = - 100 - numero;
		bidea = aukeratuBidea();
		oztopoa5.pos.x = 85 + bidea;
		//konprobatuPosizioa(oztopoa5, oztopoa6);

	}
	if (oztopoa6.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa6.pos.y = - 100 - numero;
		bidea = aukeratuBidea();
		oztopoa6.pos.x = 85 + bidea;

	}
	if (bigarrenKontagailua==0) {
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
	bigarrenKontagailua++;

    egoera = JOKOA_egoera(jokalaria, oztopoa, bateria, bizitzakAldatu);

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
  } while (egoera == JOLASTEN && ebentu !=TECLA_ESCAPE);
  
  if (ebentu == TECLA_ESCAPE)
	{
		jokoaAurkeztu();
	}
	
  irudiaKendu(jokalaria.id);
  toggleMusic();
  audioTerminate();
  pantailaGarbitu();
  pantailaBerriztu();
  return egoera;
}

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
  else if(bateria ==1)
  {
	  ret = GALDU;
  }
  return ret;
}


int JOKOAREN_argazkiakGehitu(char * argazkia)
{
	int jokalariaId = -1;
	jokalariaId = irudiaKargatu(argazkia);
	//pantailaGarbitu();
	//irudiakMarraztu();
	//pantailaBerriztu();
	return jokalariaId;
}

POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa) {
  posizioa.y = posizioa.y + 1;
  posizioa.x = posizioa.x + 1;
  return posizioa;
}

int  jokoAmaierakoa(EGOERA egoera)
{
  int ebentu = 0, id;
  int idAudioGame;

  loadTheMusic(BUKAERA_SOUND_1);
  if (egoera == IRABAZI) {
    idAudioGame = loadSound(JOKOA_SOUND_WIN);
    playSound(idAudioGame);
  }
  else {
    idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
    playSound(idAudioGame);
  }
  id=BUKAERA_irudiaBistaratu();
  do 
  {
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA));
  audioTerminate();
  irudiaKendu(id);
  return (ebentu != TECLA_RETURN) ? 1 : 0;
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
/*
void txanponakTextua(char* txanponakScore) {
	textuaGaitu();
	textuaIdatzi(200,230, txanponakScore);
}*/

int BUKAERA_irudiaBistaratu() {
  int id = -1;
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 200, 200);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return id;
}
