#ifndef JOKOAAURKEZTU_H
#define JOKOAAURKEZTU_H
#include "ourTypes.h"

#define STARTMENU_IMAGE ".\\img\\menu\\hasijokoa.bmp"
#define ITXIJOKOA_IMAGE ".\\img\\menu\\itxijokoa.bmp"
#define LAGUNTZA_IMAGE ".\\img\\menu\\laguntza.bmp"
#define ONGI_ETORRI_MEZUA "PRESS RETURN TO START THE GAME"
#define MENU_SOINUA ".\\sound\\ispace.wav"
#define MENULAGUNTZA_IMAGE ".\\img\\menu\\menulaguntza.bmp"
#define PAUSA_JARRAITU ".\\img\\menu\\jarraitu.bmp"
#define PAUSA_ATERA ".\\img\\menu\\pausa.bmp"

void jokoaAurkeztu(void);
void sarreraMezuaIdatzi();
void sarreraArgazkiaAplikatu(argazkia);
void argazkiaAldatu(menuAukerak);
void zeinPantailaAukeratu(menuAukerak);

#endif