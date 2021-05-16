#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <Windows.h> 

#define largeurEcran (GetSystemMetrics(SM_CXSCREEN)/4*3) //3/4 de la largeur de l'écran
#define longueurEcran (GetSystemMetrics(SM_CYSCREEN)/4*3)//3/4 de la longueur de l'écran

class Ennemi
{
protected:
	int vie;
	int niveau;
	int degat;
	int vitesse;
	int dimensionH = 90;
	int dimensionL = 60;
	short int nombreSprite=3;
	enum direction { bas, gauche, droite, haut };
	sf::Vector2i animation;
	sf::Texture textureEnnemi;
	sf::Sprite spriteEnnemi;
	sf::Clock clockAnimation;
public:
	Ennemi(int niveau);
	~Ennemi();
	void recevoirDegat(int degat);
	int getDegat();
	int getVie();
	void deplacement(int positionPersonnageX, int positionPersonnageY);
	void setVie(int degat);
	sf::Sprite * getSpriteEnnemi();
	int getDimensionH();
	int getDimensionL();
};

