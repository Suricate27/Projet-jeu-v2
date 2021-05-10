#pragma once
#include <vector>
#include <string.h>
#include "Balles.h"

class Arme
{
protected:
	int munitions;
	std::string nom;
	enum classe { l�ger, lourd, explosif };
	int type;
	bool distance;
	std::vector<Balles*> tableauBalles=std::vector<Balles*>(); //tableau de cercle
public:
	Arme();
	void tirer(float PosXJoueur, float PosYJoueur, sf::RenderWindow * window);
	void recharger();
	std::vector <Balles*> *getTableauBalles();
};

