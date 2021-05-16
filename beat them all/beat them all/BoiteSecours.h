#pragma once
#include <iostream>
#include <SFML/graphics.hpp>

class BoiteSecours
{
protected:
	int dimension = 34;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	BoiteSecours(int positionX, int positionY);
	int getDimension();
	sf::Sprite * getsprite();


};