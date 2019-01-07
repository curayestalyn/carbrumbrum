#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define STARTMENU_IMAGE ".\\img\\menu\\startmenu.bmp"
#define STARTMENU2_IMAGE ".\\img\\menu\\startmenu2.bmp"
#define ONGI_ETORRI_MEZUA "PRESS RETURN TO START THE GAME"
void sarreraMezuaIdatzi();
void sarreraArgazkiaAplikatu(argazkia);
void argazkiaAldatu(n);

void jokoaAurkeztu(void)
{
	int ebentu = 0, n=4;

	sarreraMezuaIdatzi();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN) {
			n--;
			argazkiaAldatu(n);
		}
		if (ebentu == TECLA_UP) {
			n++;
			argazkiaAldatu(n);
		}
	} while (ebentu != TECLA_RETURN);
	pantailaGarbitu();
	pantailaBerriztu();
}

void sarreraMezuaIdatzi()
{
	int id = -1;
	id = irudiaKargatu(STARTMENU_IMAGE);
	irudiaMugitu(id, 0, 0);
	irudiakMarraztu();
	textuaIdatzi(200, 450, ONGI_ETORRI_MEZUA);
	pantailaBerriztu();
}

void sarreraArgazkiaAplikatu(char *argazkia)
{
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 0, 0);
	irudiakMarraztu();
	textuaIdatzi(200, 450, ONGI_ETORRI_MEZUA);
	pantailaBerriztu();
}

void argazkiaAldatu(n)
{
	if (n >= 5) { n = 4; }
	if (n <= 0) { n = 1; }
	if (n == 4) {
		sarreraArgazkiaAplikatu(STARTMENU_IMAGE);
	}
	if (n == 3) {
		sarreraArgazkiaAplikatu(STARTMENU2_IMAGE);
	}
}