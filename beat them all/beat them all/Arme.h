#pragma once
#include <vector>
#include <string.h>
#include "Balles.h"

class Arme
{
protected:
	int munitions;
	int degat;
	std::string nom;
	enum classe { l�ger, lourd, explosif };
	int type;
	int VitesseArme = 1;
	int vitesseArmeMax = 25;
	bool distance;
	sf::Clock timerTir;
	std::vector<Balles*> tableauBalles=std::vector<Balles*>(); //tableau de cercle
public:
	Arme();
	void tirer(float PosXJoueur, float PosYJoueur, sf::RenderWindow * window,int direction);
	void recharger();
	std::vector <Balles*> *getTableauBalles();
	void setDirectionBalle(short int direction);
	int getArmeDegat() {
		return degat;
	}
	int getVitesseArme();
	int getMunitions();
};

