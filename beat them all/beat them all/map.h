#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include <Windows.h>
#include "Arme.h"


class Map 
{
protected:
	int dimension_back_H = 764;
	int dimension_back_L = 1000;
	std::vector<sf::CircleShape*> objets; //tableau de cercle
	sf::CircleShape cercle; //d�claration de la variable
	sf::Texture textureBack;
	sf::Sprite spriteBack;
	

public:
	Map();
	void creationCercle(float positionX, float positionY);
	void avancer();
	std::vector<sf::CircleShape*> * getObjets();
	void updateMap();
	sf::Sprite * getSpriteBack();


};

