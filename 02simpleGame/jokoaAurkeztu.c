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
#define ONGI_ETORRI_MEZUA "PRESS RETURN TO START THE GAME"
void sarreraMezuaIdatzi();

void jokoaAurkeztu(void)
{
	int ebentu = 0;

	sarreraMezuaIdatzi();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
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