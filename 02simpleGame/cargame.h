#ifndef CARGAME_H
#define CARGAME_H

#include "ourTypes.h"
int jokoaAurkeztu();
EGOERA JOKOA_egoera(JOKO_ELEMENTUA jokalaria, int bateria, int bizitzakAldatu);
JOKO_ELEMENTUA oztopoakAgertzeko(JOKO_ELEMENTUA oztopoa);
JOKO_ELEMENTUA argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa);
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa);
EGOERA jokatu(void);
int JOKOAREN_argazkiakGehitu(char * argazkia);
/*******Oztopoak eta elementuak gurdibideetan ausaz agertzeko*******/
int aukeratuBidea();
int zenbakiRandom();

/*******Depositoak aldatzeko*******/
void bateriaArgazkiaAplikatu(char *argazkia);
void ArgazkiaAplikatu(char *argazkia); //EnergyBull-ena
void bateriaArgazkiaAldatu(kontagailuBateria);
void argazkiakAldatu(kontagailuEnergia);
/*******Pausa menua*******/
int pausaMenua();
void aukerakAldatu(menuAukerak);
/*******Galduz gero*******/
int  jokoAmaierakoa(EGOERA egoera);
int BUKAERA_irudiaBistaratu();
#endif