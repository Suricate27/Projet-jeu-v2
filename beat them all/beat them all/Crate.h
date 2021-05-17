#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
class Crate
{
protected:
	int vie;
	int dimension = 70;
	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	Crate(int positionX,int positionY);
	int getDimension();
	sf::Sprite * getSpriteCrate();
};

