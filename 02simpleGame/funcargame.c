#include "cargame.h"
#include "imgpath.h"
#include "menu.h"
#include "imagen.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "graphics.h"
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "OurTypes.h"

int aukerakAldatu(menuAukerak)
{
	int id;
	if (menuAukerak >= 1) { menuAukerak = 1; }
	if (menuAukerak < 1) { menuAukerak = 0; }
	if (menuAukerak == 0) 
	{
		id = pausaArgazkiakAplikatu(PAUSA_ATERA);
	}
	if (menuAukerak == 1) 
	{
		id = pausaArgazkiakAplikatu(PAUSA_JARRAITU);
	}
	return id;
}

int pausaArgazkiakAplikatu(char *argazkia)
{
	int id;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 0, 0);
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

int pausaMenua()
{
	int ebentu = 0, menuAukerak = 1;
	int id = 0;

	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN && menuAukerak != 0) {
			menuAukerak--;
			id = aukerakAldatu(menuAukerak);
		}
		if (ebentu == TECLA_UP && menuAukerak != 1) {
			menuAukerak++;
			id = aukerakAldatu(menuAukerak);
		}
	} while (ebentu != TECLA_RETURN);
	if (menuAukerak==0)
	{
		id = id + 1000;
	}
	return id;
}

int BUKAERA_irudiaBistaratu() {
	int id = -1;
	id = irudiaKargatu(BUKAERA_IMAGE);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

int zenbakiRandom() {
	int numero;
	numero = rand() % 1000;
	return numero;
}

int aukeratuBidea()
{
	int dBide = 0, Bide;

	Bide = rand() % 4;

	if (Bide == 0) { dBide = 0; }
	if (Bide == 1) { dBide = 125; }
	if (Bide == 2) { dBide = 250; }
	if (Bide == 3) { dBide = 365; }
	return dBide;
}

void bateriaArgazkiaAplikatu(char *argazkia) {
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 540, 230);
	irudiakMarraztu();
	pantailaBerriztu();
}

void ArgazkiaAplikatu(char *argazkia)
{
	int id = 1;
	id = irudiaKargatu(argazkia);
	irudiaMugitu(id, 540, 330);
	irudiakMarraztu();
	pantailaBerriztu();
}

void bateriaArgazkiaAldatu(kontagailuBateria)
{
	if (kontagailuBateria == 5) {
		bateriaArgazkiaAplikatu(BATERIA5_IMAGE);
	}
	else if (kontagailuBateria == 4) {
		bateriaArgazkiaAplikatu(BATERIA4_IMAGE);
	}
	else if (kontagailuBateria == 3) {
		bateriaArgazkiaAplikatu(BATERIA3_IMAGE);
	}
	else if (kontagailuBateria == 2) {
		bateriaArgazkiaAplikatu(BATERIA2_IMAGE);
	}
	else if (kontagailuBateria == 1) {
		bateriaArgazkiaAplikatu(BATERIA1_IMAGE);
	}
}

void argazkiakAldatu(kontagailuEnergia)
{
	if (kontagailuEnergia >= 5) { kontagailuEnergia = 4; }
	else if (kontagailuEnergia == 4) {
		ArgazkiaAplikatu(DEPOSITO1_IMAGE);
	}
	else if (kontagailuEnergia == 3) {
		ArgazkiaAplikatu(DEPOSITO2_IMAGE);
	}
	else if (kontagailuEnergia == 2) {
		ArgazkiaAplikatu(DEPOSITO3_IMAGE);
	}
	else if (kontagailuEnergia == 1) {
		ArgazkiaAplikatu(DEPOSITO4_IMAGE);
	}
}
JOKO_ELEMENTUA oztopoakAgertzeko(JOKO_ELEMENTUA oztopoa)
{
	int numero = 0, bidea = 0;

	if (oztopoa.pos.y + 30 > 550) {
		numero = zenbakiRandom();
		oztopoa.pos.y = -100 - numero;
		bidea = aukeratuBidea();
		oztopoa.pos.x = 85 + bidea;
	}
	return oztopoa;
}
POSIZIOA ERREALITATE_FISIKOA_mugimendua(POSIZIOA posizioa) {
	posizioa.y = posizioa.y + 1;
	posizioa.x = posizioa.x + 1;
	return posizioa;
}
JOKO_ELEMENTUA argazkiakMugiarazi(JOKO_ELEMENTUA oztopoa)
{
	POSIZIOA aux;
	aux = ERREALITATE_FISIKOA_mugimendua(oztopoa.pos);
	oztopoa.pos.y = aux.y;
	irudiaMugitu(oztopoa.id, oztopoa.pos.x, oztopoa.pos.y);
	return oztopoa;
}

int JOKOAREN_argazkiakGehitu(char * argazkia)
{
	int jokalariaId = -1;
	jokalariaId = irudiaKargatu(argazkia);
	return jokalariaId;
}

int konprobatuPosizioa(JOKO_ELEMENTUA elementua1, JOKO_ELEMENTUA elementua2)
{
	int bateraDaude = 0;
	if (elementua1.pos.x == elementua2.pos.x)
	{
		if (elementua1.pos.y + 22 >= elementua2.pos.y - 34 || elementua1.pos.y - 22 <= elementua2.pos.y + 34)
		{
			bateraDaude = 1;
		}
	}
	return bateraDaude;
}

JOKO_ELEMENTUA oztopoakMugitzeko(JOKO_ELEMENTUA oztopoa)
{
	int numero = 0, bidea = 0;

	numero = zenbakiRandom();
	oztopoa.pos.y = -100 - numero;
	bidea = aukeratuBidea();
	oztopoa.pos.x = 85 + bidea;

	return oztopoa;
}
