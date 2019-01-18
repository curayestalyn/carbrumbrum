#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

int BUKAERA_irudiaBistaratu();
void ArgazkiaAplikatu(char *argazkia);
int JOKOAREN_argazkiakGehitu(char * argazkia);
JOKO_ELEMENTUA oztopoakAgertzeko(JOKO_ELEMENTUA oztopoa);
JOKO_ELEMENTUA argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa);
int aukeratuBidea();
int zenbakiRandom();
////¿¿¿¿????////
void carCrashes(kontCarCrashes);
int bizitzakAldatu(kontBizitzakGaldu);

////Depositoak aldatzeko////
void argazkiakAldatu(kontEnergia);
void bateriaArgazkiaAplikatu(char *argazkia);
void ArgazkiaAplikatu(char *argazkia); //EnergyBull-ena
void bateriaArgazkiaAldatu(kontBateria);

////Jokoaren fase desberdinak////
int jokoaAurkeztu();
EGOERA jokatu(void);
int  jokoAmaierakoa(EGOERA egoera);

////Pausa menua////
int pausaMenua();
void aukerakAldatu(menuAukerak);

#endif