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

/*******Menu aukerak funmenu.c ikusten dira*******/
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
