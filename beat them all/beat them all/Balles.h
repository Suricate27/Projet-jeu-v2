#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <vector>
class Balles
{
protected:
	int vitesse = 1;
	sf::CircleShape *cercle; //déclaration de la variable
	sf::Texture textureBalle;
	sf::Sprite spriteBalle;
public:
	Balles(float positionX, float positionY, sf::RenderWindow * window);
	void avancer(sf::Time duréeitération, sf::RenderWindow * window);
	
};

