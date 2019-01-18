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
  int jarraitu = 1, balioa=0;
  EGOERA egoera;
 
  if (sgHasieratu() == -1) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    return 1;
  }

  textuaGaitu(); 

  do
  {
<<<<<<< HEAD:02simpleGame/02simpleGameMain.c
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

=======
	
    jokoaAurkeztu();
    egoera = jokatu();
	jarraitu = jokoAmaierakoa(egoera);
>>>>>>> 46ca84d30edb84b2144250fd45089e7f9240e615:02simpleGame/main.c
  } while (jarraitu);

  sgItxi();
  return 0;
}

