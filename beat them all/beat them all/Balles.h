#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <vector>
#define taillePersonnage 192
class Balles
{
protected:
	int vitesse = 1000;
	sf::CircleShape *cercle; //déclaration de la variable
	sf::Clock clock;
	sf::Time dureeVie = sf::Time::Zero;
public:
	Balles(float positionX, float positionY, int direction, sf::RenderWindow * window);
	void avancer(sf::Time duréeitération, sf::RenderWindow * window);
	~Balles();
	sf::Time getDureeVie();
	float getPositionX();
	float getPositionY();
	void setDirection(short int direction);
};

