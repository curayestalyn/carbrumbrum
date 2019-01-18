/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "jokoaAurkeztu.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "game02.h"


int main(int argc, char * str[]) {
  int jarraitu = 1, balioa=0;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }
  textuaGaitu();
  //jokoaAurkeztu();
  
  do
  {
    balioa = jokoaAurkeztu();
	if (balioa == 3)
	{
		break;
	}
	else if (balioa == 2)
	{
		laguntzaMenua();
	}
	else if (balioa == 4)
	{
		egoera = jokatu();
		if (egoera != 5)
		{
			jarraitu = jokoAmaierakoa(egoera);
		}
		
	}

  } while (jarraitu);
  
  sgItxi();
  return 0;
}

