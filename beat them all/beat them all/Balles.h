#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <vector>
#define taillePersonnage 192
class Balles
{
protected:
	int vitesse = 500;
	sf::CircleShape *cercle; //d�claration de la variable
	sf::Clock clock;
	sf::Time dureeVie = sf::Time::Zero;
public:
	Balles(float positionX, float positionY, sf::RenderWindow * window);
	void avancer(sf::Time dur�eit�ration, sf::RenderWindow * window);
	~Balles();
	sf::Time getDureeVie();
};

