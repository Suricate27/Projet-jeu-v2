#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <vector>
class Balles
{
protected:
	int vitesse = 1;
	sf::CircleShape *cercle; //d�claration de la variable
	sf::Texture textureBalle;
	sf::Sprite spriteBalle;
public:
	Balles(float positionX, float positionY, sf::RenderWindow * window);
	void avancer(sf::Time dur�eit�ration, sf::RenderWindow * window);
	
};

