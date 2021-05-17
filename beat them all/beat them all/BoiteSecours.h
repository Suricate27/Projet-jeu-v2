#pragma once
#include <iostream>
#include <SFML/graphics.hpp>

class BoiteSecours
{
protected:
	int dimension = 34;
	int capaciteSoins = 10;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	BoiteSecours(int positionX, int positionY);
	int getDimension();
	int getCapaciteSoins();
	sf::Sprite * getsprite();
	


};