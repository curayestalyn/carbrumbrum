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
#include "menu.h"
#include "imgpath.h"
#include "soundpath.h"


int jokoaAurkeztu()
{
	int ebentu = 0;
	int menuAukerak = 2;

	audioInit();
	loadTheMusic(MENU_SOINUA);
	playMusic();

	sarreraMezuaIdatzi();
	
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN ) {
			menuAukerak--;
			argazkiaAldatu(menuAukerak);
		}
		if (ebentu == TECLA_UP) {
			menuAukerak++;
			argazkiaAldatu(menuAukerak);
		}
	} while (ebentu != TECLA_RETURN);
	pantailaGarbitu();
	pantailaBerriztu();

	return menuAukerak;
}

/*************FUNTZIOAK***********************/
void zeinPantailaAukeratu(menuAukerak) {
	EGOERA egoera;
	int ebentu = 0;
	int jarraitu = 0;
	ebentu = ebentuaJasoGertatuBada();
	if (menuAukerak == 2) {
		do
		{
			egoera = jokatu();
			jarraitu = jokoAmaierakoa(egoera);
		} while (jarraitu);
	}
	if (menuAukerak < 2)
	{

	}
	if (menuAukerak <= 0)
	{
		while (ebentu != TECLA_ESCAPE)
		{

			irudiaKargatu(MENULAGUNTZA_IMAGE);

		}
	}
}


void sarreraMezuaIdatzi()
{
	int id = -1;
	id = irudiaKargatu(STARTMENU_IMAGE);
	irudiaMugitu(id, 0, 0);
	irudiakMarraztu();
	pantailaBerriztu();
}

void sarreraArgazkiaAplikatu(char *argazkia)
{
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 0, 0);
	irudiakMarraztu();
	pantailaBerriztu();
}

void argazkiaAldatu(menuAukerak)
{
	if (menuAukerak >= 2) { menuAukerak = 2; }
	if (menuAukerak <= 0) { menuAukerak = 0; }

	if (menuAukerak == 2) {
		sarreraArgazkiaAplikatu(STARTMENU_IMAGE);
	}
	if (menuAukerak == 1) {
		sarreraArgazkiaAplikatu(ITXIJOKOA_IMAGE);

	}
	if (menuAukerak == 0) {
		sarreraArgazkiaAplikatu(LAGUNTZA_IMAGE);
	}
}