#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include "ourTypes.h"
#include "cargame.h"
//New
#include "menu.h"


int main(int argc, char * str[]) {
  int jarraitu = 0;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }

  textuaGaitu(); 

  do
  {
	
    jokoaAurkeztu();
    egoera = jokatu();
	jarraitu = jokoAmaierakoa(egoera);
  } while (jarraitu);

  sgItxi();
  return 0;
}

