#pragma once
#include <SFML/graphics.hpp>
#include <iostream>

#define largeurEcran 2400
#define longueurEcran 1500
class Ennemi
{
protected:
	int vie;
	int niveau;
	int degat;
	int vitesse;
	int dimensionH = 90;
	int dimensionL = 60;
	enum direction { bas, gauche, droite, haut };
	sf::Vector2i animation;
	sf::Texture textureEnnemi;
	sf::Sprite spriteEnnemi;
public:
	Ennemi(int niveau);
	~Ennemi();
	void recevoirDegat(int degat);
	int getDegat();
	int getVie();
	void deplacement();
	void setVie(int degat);
	sf::Sprite * getSpriteEnnemi();
};

