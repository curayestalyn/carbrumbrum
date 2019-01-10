#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "jokoaAurkeztu.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
/********************IRUDIAK****************************/
#define STARTMENU_IMAGE ".\\img\\menu\\hasijokoa.bmp"
//#define HASIJOKOA_IMAGE ".\\img\\menu\\hasijokoa.bmp"
#define ITXIJOKOA_IMAGE ".\\img\\menu\\itxijokoa.bmp"
#define LAGUNTZA_IMAGE ".\\img\\menu\\laguntza.bmp"
#define ONGI_ETORRI_MEZUA "PRESS RETURN TO START THE GAME"

void jokoaAurkeztu(void)
{
	int ebentu = 0, menuAukerak=4;

	sarreraMezuaIdatzi();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN) {
			menuAukerak--;
			argazkiaAldatu(menuAukerak);
		}
		if (ebentu == TECLA_UP) {
			menuAukerak++;
			argazkiaAldatu(menuAukerak);
		}
	} while (ebentu != TECLA_RETURN);
	zeinPantailaAukeratu(menuAukerak);
	pantailaGarbitu();
	pantailaBerriztu();
}

void zeinPantailaAukeratu(n) {
	EGOERA egoera;
	int jarraitu = 0;
	if (n == 4) {
		do
		{
			egoera = jokatu();
			jarraitu = jokoAmaierakoa(egoera);
		} while (jarraitu);

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
	if (menuAukerak >= 5) { menuAukerak = 4; }
	if (menuAukerak <= 0) { menuAukerak = 1; }
	if (menuAukerak == 4) {
		sarreraArgazkiaAplikatu(STARTMENU_IMAGE);
	}
	if (menuAukerak == 3) {
		sarreraArgazkiaAplikatu(ITXIJOKOA_IMAGE);
	}
	if (menuAukerak == 2) {
		sarreraArgazkiaAplikatu(LAGUNTZA_IMAGE);
	}
}