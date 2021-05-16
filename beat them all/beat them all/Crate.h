#pragma once
#include <SFML/graphics.hpp>
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

