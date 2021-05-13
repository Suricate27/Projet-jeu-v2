#pragma once
#include <vector>
#include <string.h>
#include "Balles.h"

class Arme
{
protected:
	int munitions;
	std::string nom;
	enum classe { léger, lourd, explosif };
	int type;
	bool distance;
	std::vector<Balles*> tableauBalles=std::vector<Balles*>(); //tableau de cercle
public:
	Arme();
	void tirer(float PosXJoueur, float PosYJoueur, sf::RenderWindow * window,int direction);
	void recharger();
	std::vector <Balles*> *getTableauBalles();
	void setDirectionBalle(short int direction);
};

