#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <vector>
class Balles
{
protected:
	int vitesse = 500;
	sf::CircleShape *cercle; //déclaration de la variable
	sf::Clock clock;
	sf::Time dureeVie = sf::Time::Zero;
public:
	Balles(float positionX, float positionY, sf::RenderWindow * window);
	void avancer(sf::Time duréeitération, sf::RenderWindow * window);
	~Balles();
	sf::Time getDureeVie();
};

