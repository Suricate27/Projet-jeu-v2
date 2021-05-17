#pragma once
#include <vector>
#include <string.h>
#include "Balles.h"

class Arme
{
protected:
	int munitions;
	int degat = 200;
	std::string nom;
	enum classe { léger, lourd, explosif };
	int type;
	int VitesseArme = 1;
	int vitesseArmeMax = 25;
	bool distance;
	sf::Clock timerTir;
	std::vector<Balles*> tableauBalles=std::vector<Balles*>(); //tableau de cercle
public:
	Arme();
	void tirer(float PosXJoueur, float PosYJoueur,int direction, int taillePersoH, int taillePersoL);
	void recharger();
	std::vector <Balles*> *getTableauBalles();
	void setDirectionBalle(short int direction);
	int getArmeDegat() {
		return degat;
	}
	int getVitesseArme();
	int getMunitions();
};

