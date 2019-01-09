#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"
int BUKAERA_irudiaBistaratu();
void ArgazkiaAplikatu(char *argazkia);
void argazkiakAldatu(kontEnergia);
void bateriaArgazkiaAplikatu(char *argazkia);
void bateriaArgazkiaAldatu(kontBateria);
int aukeratuBidea();
int zenbakiRandom();
void carCrashes(kontCarCrashes);
int bizitzakAldatu(kontBizitzakGaldu);

void jokoaAurkeztu(void);
EGOERA jokatu(void);
int  jokoAmaierakoa(EGOERA egoera);
int JOKOAREN_argazkiakGehitu(char * argazkia);

int BUKAERA_irudiaBistaratu();
void ArgazkiaAplikatu(char *argazkia);
void argazkiakAldatu(kontagailuEnergia);
void bateriaArgazkiaAplikatu(char *argazkia);
void bateriaArgazkiaAldatu(kontagailuBateria);
int aukeratuBidea();
int zenbakiRandom();


#endif