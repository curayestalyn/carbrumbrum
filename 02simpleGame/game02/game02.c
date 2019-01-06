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
#define BACKGROUND_IMAGE ".\\img\\carretera.bmp"
#define MARRAK1_IMAGE ".\\img\\marrak.bmp"
#define MARRAK2_IMAGE ".\\img\\marrak2.bmp"
#define JOKOA_PLAYER_IMAGE ".\\img\\garajea\\jokalaria.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\gameovervoice.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"




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


EGOERA jokatu(void) 
{
  EGOERA  egoera = JOLASTEN;
  int ebentu = 0;
  JOKO_ELEMENTUA oztopoa, jokalaria, background, marrak1, marrak2, txanpona, energybull;
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

  txanpona.pos.x = 235;
  txanpona.pos.y = 0;

  energybull.pos.x = 100;
  energybull.pos.y = 0;

  

  audioInit();
  loadTheMusic(JOKOA_SOUND);
  playMusic();
  background.id = JOKOAREN_argazkiakGehitu(BACKGROUND_IMAGE);
  oztopoa.id = JOKOAREN_argazkiakGehitu(KOTXEA1_IMAGE);
  marrak1.id = JOKOAREN_argazkiakGehitu(MARRAK1_IMAGE);
  marrak2.id = JOKOAREN_argazkiakGehitu(MARRAK2_IMAGE);
  jokalaria.id = JOKOAREN_argazkiakGehitu(JOKOA_PLAYER_IMAGE);
  txanpona.id = JOKOAREN_argazkiakGehitu(TXANPONA_IMAGE);
  energybull.id = JOKOAREN_argazkiakGehitu(ENERGYBULL_IMAGE);


  do {
    Sleep(2);
    aux = ERREALITATE_FISIKOA_mugimendua(oztopoa.pos);
	oztopoa.pos.y = aux.y;
	aux = ERREALITATE_FISIKOA_mugimendua(marrak1.pos);
	marrak1.pos.y = aux.y;
	irudiaMugitu(marrak1.id, marrak1.pos.x, marrak1.pos.y);
	aux = ERREALITATE_FISIKOA_mugimendua(marrak2.pos);
	marrak2.pos.y = aux.y;
	irudiaMugitu(marrak2.id, marrak2.pos.x, marrak2.pos.y);
	aux = ERREALITATE_FISIKOA_mugimendua(txanpona.pos);
	txanpona.pos.y = aux.y;
	aux = ERREALITATE_FISIKOA_mugimendua(energybull.pos);
	energybull.pos.y = aux.y;
	irudiaMugitu(energybull.id, energybull.pos.x, energybull.pos.y);

	
	
	/*Pantaila garbitu*/
    pantailaGarbitu();
    arkatzKoloreaEzarri(0, 0, 0xFF);
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
	irudiaMugitu(txanpona.id, txanpona.pos.x, txanpona.pos.y);
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
	irudiaMugitu(energybull.id, energybull.pos.x, energybull.pos.y);
	
    irudiakMarraztu();
    pantailaBerriztu();
    ebentu = ebentuaJasoGertatuBada();
    if (ebentu == TECLA_RIGHT)
    {
		aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
		jokalaria.pos.x = aux.x+5;
    }
	if (ebentu == TECLA_LEFT) {
		aux = ERREALITATE_FISIKOA_mugimendua(jokalaria.pos);
		jokalaria.pos.x = aux.x-6;
	}
	if (marrak1.pos.y > 480) {
		marrak1.pos.y = -480;
	}
	if (marrak2.pos.y > 480) {
		marrak2.pos.y = -480;
	}
	if (txanpona.pos.y > 480)
	{
		txanpona.pos.y = -24;
	}
	if (energybull.pos.y > 480)
	{
		energybull.pos.y = -24;
	}
    if (oztopoa.pos.y + 30 > 550) {
		int numero;
		numero = rand() % 1000;
		oztopoa.pos.y = -100-numero;
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
  if (jokalaria.pos.x >oztopoa.pos.x - 54 && jokalaria.pos.x <oztopoa.pos.x + 54 && jokalaria.pos.y + 32 >oztopoa.pos.y - 54 && jokalaria.pos.y - 32 <oztopoa.pos.y + 54) {
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

int BUKAERA_irudiaBistaratu() {
  int id = -1;
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 200, 200);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  return id;
}

