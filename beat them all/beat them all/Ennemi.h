#pragma once
#include <SFML/graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <math.h>

#define longueurEcran 500
#define largeurEcran 1000
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
	std::vector <Ennemi*> tabEnnemis;
public:
	Ennemi(int niveau,int PositionXPersonnage);
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
	void toucheCac();
	void apparition(int niveau);
	void apparition(int niveau,int PositionXPersonnage);
	std::vector <Ennemi*>*getTabEnnemi();
};

