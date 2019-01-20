#include "cargame.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "cargame.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "imgpath.h"
#include "soundpath.h"
#include "menu.h"

int jokoaAurkeztu()
{
	int ebentu = 0, menuAukerak = 4, balioa = 0;

	audioInit();
	loadTheMusic(MENU_SOINUA);
	playMusic();

	sarreraArgazkiaAplikatu(STARTMENU_IMAGE);
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN && menuAukerak!=2) {
			menuAukerak--;
			argazkiaAldatu(menuAukerak);
		}
		if (ebentu == TECLA_UP && menuAukerak != 4) {
			menuAukerak++;
			argazkiaAldatu(menuAukerak);
		}
	} while (ebentu != TECLA_RETURN);

	return menuAukerak;
}

void laguntzaMenua()
{
	int ebentu = 0;
	sarreraArgazkiaAplikatu(MENULAGUNTZA_IMAGE);
	do
	{
		ebentu = ebentuaJasoGertatuBada();
	} while (ebentu != TECLA_ESCAPE);
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