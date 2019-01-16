#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"
int BUKAERA_irudiaBistaratu();
void ArgazkiaAplikatu(char *argazkia);
int JOKOAREN_argazkiakGehitu(char * argazkia);
JOKO_ELEMENTUA oztopoakAgertzeko(JOKO_ELEMENTUA oztopoa);
JOKO_ELEMENTUA argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa);

////Depositoak aldatzeko////
void argazkiakAldatu(kontEnergia);
void bateriaArgazkiaAplikatu(char *argazkia);

void bateriaArgazkiaAldatu(kontBateria);
int aukeratuBidea();
int zenbakiRandom();
void carCrashes(kontCarCrashes);
int bizitzakAldatu(kontBizitzakGaldu);

////Jokoaren fase desberdinak////
void jokoaAurkeztu(void);
EGOERA jokatu(void);
int  jokoAmaierakoa(EGOERA egoera);

////Pausa menua////
void pausaMenua(void);
void aukerakAldatu(menuAukerak);
void aukeraExekutatu(menuAukerak);

#endif