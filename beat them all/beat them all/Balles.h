#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>
#define taillePersonnage 192
#define longueurEcran (GetSystemMetrics(SM_CYSCREEN)/4*3)//3/4 de la longueur de l'écran
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
	float getPositionX();
	float getPositionY();
};

