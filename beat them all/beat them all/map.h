#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Arme.h"

class Map 
{
protected:
	
	std::vector<sf::CircleShape*> TabBoiteSecours; //tableau de cercle
	sf::CircleShape cercle; //déclaration de la variable

public:

	void creationCercle(float positionX, float positionY);
	void avancer();
	std::vector<sf::CircleShape*> * getTabBoiteSecours();
	sf::IntRect * viePersonnage();
	void creationBoiteSecours(float positionX, float positionY);
};

