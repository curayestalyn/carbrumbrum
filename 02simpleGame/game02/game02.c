#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>



#define JOKOA_SOUND ".\\sound\\132TRANCE_02.wav"
#define TXANPONA_IMAGE ".\\img\\elementua\\txanpona.bmp"
#define ENERGYBULL_IMAGE ".\\img\\elementua\\energybull.bmp"
#define KOTXEA1_IMAGE ".\\img\\garajea\\policecar20.bmp"
#define KOTXEA2_IMAGE ".\\img\\garajea\\ssportcar20.bmp"
#define BACKGROUND_IMAGE ".\\img\\carretera.bmp"
#define MARRAK1_IMAGE ".\\img\\marrak.bmp"
#define MARRAK2_IMAGE ".\\img\\marrak2.bmp"
#define JOKOA_PLAYER_IMAGE ".\\img\\garajea\\jokalaria.bmp"
#define BIZITZAK_IMAGE ".\\img\\elementua\\life.bmp"
#define DEPOSITO1_IMAGE ".\\img\\elementua\\deposito1.bmp"
#define DEPOSITO2_IMAGE ".\\img\\elementua\\deposito2.bmp"
#define DEPOSITO3_IMAGE ".\\img\\elementua\\deposito3.bmp"
#define DEPOSITO4_IMAGE ".\\img\\elementua\\deposito4.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\gameovervoice.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"
#define GASOLINA_IMAGE ".\\img\\elementua\\petrol.bmp"
#define BATERIA1_IMAGE ".\\img\\elementua\\bateria1.bmp"
#define BATERIA2_IMAGE ".\\img\\elementua\\bateria2.bmp"
#define BATERIA3_IMAGE ".\\img\\elementua\\bateria3.bmp"
#define BATERIA4_IMAGE ".\\img\\elementua\\bateria4.bmp"
#define BATERIA5_IMAGE ".\\img\\elementua\\bateria5.bmp"
#define SCORETEXT "Hola"


/*int JOKOA_jokalariaIrudiaSortu();
int JOKOA_lehenKotxea();
int JOKOA_background();
int JOKOA_marrak1();
int JOKOA_marrak2();*/
int JOKOAREN_argazkiakGehitu(argazkia);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
//int  BUKAERA_menua(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
void ArgazkiaAplikatu(char *argazkia);
void argazkiakAldatu(n);
int zenbakiRandom();
int aukeratuBidea();
void bateriaArgazkiaAldatu(m);
void bateriaArgazkiaAplikatu(char *argazkia);
void updateScore(int txanponakScore);

//void argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa);


EGOERA jokatu(void) 
{
  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  int n = 1, m = 0;
  int denbora = 2;
  int bigarrenKontagailua = 0, kontagailu = 0;
  int bidea=0, kont=0;
  int txanponakScore = 0;
  JOKO_ELEMENTUA oztopoa, bateria1, bateria2, bateria3, bateria4, bateria5, oztopoa2, jokalaria, background, marrak1, marrak2, txanpona, gasolina, energybull, deposito1, deposito2, deposito3, deposito4, bizitzak1, bizitzak2, bizitzak3;
  POSIZIOA aux;
  //BACKGROUND 
  background.pos.x = 0;
  background.pos.y = 0;

  //Uint32 time01 = SDL_GetTicks(), time02;

  marrak1.pos.x = 0;
  marrak1.pos.y = 0;

  marrak2.pos.x = 0;
  marrak2.pos.y = -480;

  //PISTAKO ELEMENTUAK
  jokalaria.pos.x = 340;
  jokalaria.pos.y = 340;

  oztopoa.pos.x = 80;
  oztopoa.pos.y = 0;

  oztopoa2.pos.x = 80;
  oztopoa2.pos.y = -110;

  txanpona.pos.x = 235;
  txanpona.pos.y = 0;
  
  gasolina.pos.x = 380;
  gasolina.pos.y = 0;

  energybull.pos.x = 100;
  energybull.pos.y = 0;

  deposito1.pos.x = 530;
  deposito1.pos.y = 330;

  bateria1.pos.x = 530;
  bateria1.pos.y = 230;

  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();
  background.id = JOKOAREN_argazkiakGehitu(BACKGROUND_IMAGE);
  oztopoa.id = JOKOAREN_argazkiakGehitu(KOTXEA1_IMAGE);
  oztopoa2.id = JOKOAREN_argazkiakGehitu(KOTXEA2_IMAGE);
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
  gasolina.id = JOKOAREN_argazkiakGehitu(GASOLINA_IMAGE);
  bateria1.id = JOKOAREN_argazkiakGehitu(BATERIA1_IMAGE);
  bateria2.id = JOKOAREN_argazkiakGehitu(BATERIA2_IMAGE);
  bateria3.id = JOKOAREN_argazkiakGehitu(BATERIA3_IMAGE);
  bateria4.id = JOKOAREN_argazkiakGehitu(BATERIA4_IMAGE);
  bateria5.id = JOKOAREN_argazkiakGehitu(BATERIA5_IMAGE);

  do {
    Sleep(denbora);
	kont++;
	//Oztopoa
	aux = ERREALITATE_FISIKOA_mugimendua(oztopoa.pos);
	oztopoa.pos.y = aux.y;
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
	//Oztopoa2
	if (kont > 100000)
	{
		aux = ERREALITATE_FISIKOA_mugimendua(oztopoa2.pos);
		oztopoa2.pos.y = aux.y;
		irudiaMugitu(oztopoa2.id, oztopoa2.pos.x, oztopoa2.pos.y);
	}
	//Marrak1
	aux = ERREALITATE_FISIKOA_mugimendua(marrak1.pos);
	marrak1.pos.y = aux.y;
	irudiaMugitu(marrak1.id, marrak1.pos.x, marrak1.pos.y);
	//Marrak2
	aux = ERREALITATE_FISIKOA_mugimendua(marrak2.pos);
	marrak2.pos.y = aux.y;
	irudiaMugitu(marrak2.id, marrak2.pos.x, marrak2.pos.y);
	//Txanpona
	aux = ERREALITATE_FISIKOA_mugimendua(txanpona.pos);
	txanpona.pos.y = aux.y;
	irudiaMugitu(txanpona.id, txanpona.pos.x, txanpona.pos.y);
	//RedBull
	aux = ERREALITATE_FISIKOA_mugimendua(energybull.pos);
	energybull.pos.y = aux.y;
	irudiaMugitu(energybull.id, energybull.pos.x, energybull.pos.y);
	//Gasolina
	aux = ERREALITATE_FISIKOA_mugimendua(gasolina.pos);
	gasolina.pos.y = aux.y;
	irudiaMugitu(gasolina.id, gasolina.pos.x, gasolina.pos.y);
	//Bizitzak
	irudiaMugitu(bizitzak1.id, 540, 17);
	irudiaMugitu(bizitzak2.id, 574, 17);
	irudiaMugitu(bizitzak3.id, 607, 17);
	//Dèpositoak
	irudiaMugitu(deposito1.id, deposito1.pos.x, deposito1.pos.y);
	irudiaMugitu(deposito2.id, deposito1.pos.x, deposito1.pos.y);
	irudiaMugitu(deposito3.id, deposito1.pos.x, deposito1.pos.y);
	irudiaMugitu(deposito4.id, deposito1.pos.x, deposito1.pos.y);

	//Bateria
	irudiaMugitu(bateria1.id, bateria1.pos.x, bateria1.pos.y);
	irudiaMugitu(bateria2.id, bateria1.pos.x, bateria1.pos.y);
	irudiaMugitu(bateria3.id, bateria1.pos.x, bateria1.pos.y);
	irudiaMugitu(bateria4.id, bateria1.pos.x, bateria1.pos.y);
	irudiaMugitu(bateria5.id, bateria1.pos.x, bateria1.pos.y);
	
	/*Pantaila garbitu*/
    pantailaGarbitu();
    arkatzKoloreaEzarri(0, 0, 0xFF);
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
	irudiaMugitu(oztopoa2.id, oztopoa2.pos.x, oztopoa2.pos.y);
	irudiaMugitu(txanpona.id, txanpona.pos.x, txanpona.pos.y);
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
	irudiaMugitu(energybull.id, energybull.pos.x, energybull.pos.y);
	
    irudiakMarraztu();
    pantailaBerriztu();
    ebentu = ebentuaJasoGertatuBada();
	//Moteltzeko abilitatea izateko
	if (ebentu == TECLA_SPACE && n >= 4) {
		denbora = 5;
		n = 1;
		argazkiakAldatu(n);
	}
	//Moteldu denbora jartzeko
	if (denbora == 5) {
		kontagailu++;
	}
	if (kontagailu >= 500) {
		denbora = 2;
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
		bidea = aukeratuBidea();
		txanpona.pos.x = 95 + bidea;
		txanpona.pos.y = -24;
	}
	if (jokalaria.pos.x > txanpona.pos.x - 15 && jokalaria.pos.x <txanpona.pos.x + 15 && jokalaria.pos.y + 15 >txanpona.pos.y - 15 && jokalaria.pos.y - 12 < txanpona.pos.y + 15)
	{
		txanponakScore++;
		txanpona.pos.y = -2007;
		bidea = aukeratuBidea();
		txanpona.pos.x = 95 + bidea;
	}
	updateScore(txanponakScore);
	if (jokalaria.pos.x > energybull.pos.x - 23 && jokalaria.pos.x <energybull.pos.x + 23 && jokalaria.pos.y + 23 >energybull.pos.y - 23 && jokalaria.pos.y - 16 < energybull.pos.y + 23)
	{
		n++;
		argazkiakAldatu(n);	
		energybull.pos.y = -2007;
		bidea = aukeratuBidea();
		energybull.pos.x = 95 + bidea;

	}
	if (energybull.pos.y > 480)
	{
		energybull.pos.y = -2007;
		bidea = aukeratuBidea();
		energybull.pos.x = 95 + bidea;

	}
	if (jokalaria.pos.x > gasolina.pos.x - 23 && jokalaria.pos.x < gasolina.pos.x + 23 && jokalaria.pos.y + 23 > gasolina.pos.y - 23 && jokalaria.pos.y - 16 < gasolina.pos.y + 23)
	{
		m=0;
		argazkiakAldatu(m);
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
	if (bigarrenKontagailua == 0) {
		bateriaArgazkiaAldatu(m);
	}
	else if (bigarrenKontagailua == 3000)
	{
		m = 2;
		bateriaArgazkiaAldatu(m);
	}
	else if (bigarrenKontagailua == 6000)
	{
		m = 3;
		bateriaArgazkiaAldatu(m);
	}
	else if (bigarrenKontagailua == 9000)
	{
		m = 4;
		bateriaArgazkiaAldatu(m);
	}
	else if (bigarrenKontagailua == 12000)
	{
		m = 5;
		bateriaArgazkiaAldatu(m);
	}
	else if (bigarrenKontagailua == 13000) {
		irudiaMugitu(bateria5.id, 530, 0);
		irudiakMarraztu();
		pantailaBerriztu();
	}
	bigarrenKontagailua++;
	if (oztopoa.pos.y + 30 > 550) {
		int numero;
		numero = rand() % 1000;
		oztopoa.pos.y = -100-numero;
		bidea = aukeratuBidea();
		oztopoa.pos.x = 85 + bidea;

    }
	if (oztopoa2.pos.y + 30 > 550) {
		int numero;
		numero = rand() % 1000;
		oztopoa2.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		oztopoa2.pos.x = 85 + bidea;

	}
    egoera = JOKOA_egoera(jokalaria, oztopoa);
  } while (egoera == JOLASTEN);
  irudiaKendu(jokalaria.id);
  toggleMusic();
  audioTerminate();
  pantailaGarbitu();
  pantailaBerriztu();
  return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, JOKO_ELEMENTUA oztopoa) {
  EGOERA  ret = JOLASTEN;
  int bizitzakGaldu=3;
  if (jokalaria.pos.x >oztopoa.pos.x - 30 && jokalaria.pos.x <oztopoa.pos.x + 30 && jokalaria.pos.y + 22 >oztopoa.pos.y - 34 && jokalaria.pos.y - 22 <oztopoa.pos.y + 30) {
    ret = GALDU;
  }
  else if (jokalaria.pos.x > 476 || jokalaria.pos.x < 64)  
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

void argazkiakAldatu(n)
{
	if (n >= 5) { n = 4; }
	if (n == 4) {
		ArgazkiaAplikatu(DEPOSITO1_IMAGE);
	}
	if (n == 3) {
		ArgazkiaAplikatu(DEPOSITO2_IMAGE);
	}
	if (n == 2) {
		ArgazkiaAplikatu(DEPOSITO3_IMAGE);
	}
	if (n == 1) {
		ArgazkiaAplikatu(DEPOSITO4_IMAGE);
	}
}
/*void argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa)
{
	POSIZIOA aux;
	aux = ERREALITATE_FISIKOA_mugimendua(oztopoa.pos);
	oztopoa.pos.y = aux.y;
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);

}*/
void ArgazkiaAplikatu(char *argazkia)
{
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 530, 330);
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


int BUKAERA_irudiaBistaratu() {
  int id = -1;
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 200, 200);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return id;
}

int zenbakiRandom() {
	int numero;
	numero = rand() % 1000;
	return numero;
}

void bateriaArgazkiaAldatu(m)
{
	if (m == 5) {
		bateriaArgazkiaAplikatu(BATERIA5_IMAGE);
	}
	else if (m == 4) {
		bateriaArgazkiaAplikatu(BATERIA4_IMAGE);
	}
	else if (m == 3) {
		bateriaArgazkiaAplikatu(BATERIA3_IMAGE);
	}
	else if (m == 2) {
		bateriaArgazkiaAplikatu(BATERIA2_IMAGE);
	}
	else if (m == 1) {
		bateriaArgazkiaAplikatu(BATERIA1_IMAGE);
	}
}

void bateriaArgazkiaAplikatu(char *argazkia) {
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 530, 230);
	irudiakMarraztu();
	pantailaBerriztu();
}

void updateScore(int txanponakScore)
{
	do
	{
		textuaIdatzi(560, 200, SCORETEXT);
		pantailaBerriztu();
	} while (txanponakScore == 3);

}
