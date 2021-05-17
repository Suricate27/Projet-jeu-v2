#pragma once
#include <vector>
#include <string.h>
#include "Balles.h"

class Arme
{
protected:
	int capaciteChargeur = 32;
	int munitions = capaciteChargeur;
	int degat = 200;
	int VitesseArme = 1;
	int vitesseArmeMax = 25;
	int type;
	sf::Clock timerTir;
	std::string nom;
	std::vector<Balles*> tableauBalles=std::vector<Balles*>(); //tableau de cercle
public:
	Arme();
	void tirer(float PosXJoueur, float PosYJoueur,int direction, int taillePersoH, int taillePersoL);
	void recharger();
	int getArmeDegat();
	int getVitesseArme();
	int getMunitions();
	std::vector <Balles*> *getTableauBalles();
};

