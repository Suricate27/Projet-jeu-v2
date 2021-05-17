#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>
#include "Header.h"
#define longueurEcran 500
#define largeurEcran 1000
class Balles
{
protected:
	int vitesse = 1000;
	int diametre = 5;
	sf::CircleShape *cercle; //déclaration de la variable
	sf::Clock clock;
	sf::Time dureeVie = sf::Time::Zero;
	sf::Time dureeVieMax = sf::milliseconds(4000);
public:
	Balles(float positionX, float positionY, int direction,int tailleH, int tailleL);
	~Balles();

	void avancer(sf::Time duréeitération, sf::RenderWindow * window);
	
	sf::Time getDureeVie();
	sf::Time getDureeVieMax();
	float getPositionX();
	float getPositionY();
	int getDiametre();
};

