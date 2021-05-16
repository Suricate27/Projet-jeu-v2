#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>

#define longueurEcran (GetSystemMetrics(SM_CYSCREEN)/4*3)//3/4 de la longueur de l'�cran

class Balles
{
protected:
	int vitesse = 1000;
	int diametre = 10;
	sf::CircleShape *cercle; //d�claration de la variable
	sf::Clock clock;
	sf::Time dureeVie = sf::Time::Zero;
public:
	Balles(float positionX, float positionY, int direction, sf::RenderWindow * window,int tailleH, int tailleL);
	void avancer(sf::Time dur�eit�ration, sf::RenderWindow * window);
	~Balles();
	sf::Time getDureeVie();
	float getPositionX();
	float getPositionY();
	int getDiametre();
};

