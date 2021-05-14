#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <vector>
#define taillePersonnage 192
class Balles
{
protected:
	int vitesse = 1000;
	int diametre = 10;
	sf::CircleShape *cercle; //d�claration de la variable
	sf::Clock clock;
	sf::Time dureeVie = sf::Time::Zero;
public:
	Balles(float positionX, float positionY, int direction, sf::RenderWindow * window);
	void avancer(sf::Time dur�eit�ration, sf::RenderWindow * window);
	~Balles();
	sf::Time getDureeVie();
	float getPositionX();
	float getPositionY();
	int getDiametre();
};

