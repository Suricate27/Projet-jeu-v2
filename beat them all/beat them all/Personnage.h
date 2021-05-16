#pragma once
#include <string.h>
#include <SFML/graphics.hpp>
#include "Arme.h"
#include "Ennemi.h"

// en pixel par seconde || un define car prend moins de place qu'une constante.

#define nombreSprite 9
#define largeurEcran 2400
#define longueurEcran 1500

class Personnage
{
protected:
	int vie;
	int dégat;
	int vitesseDeplacement = 400;
	std::string nom;
	int dimensionL = 133;
	int dimensionH = 155;
	int direction = 1;
	enum direction { haut, gauche, bas, droite };
	sf::Vector2i animation; // tableau à 2 dimension et que pour des int ( d'où le 2i) , x et y
	bool updateFPS = false, moveUp = false, moveDown = false, moveRight = false, moveLeft = false,tirer = false;
	sf::Texture texturePerso;
	sf::Sprite spritePerso;
	sf::Clock clockAnimation;
	Arme * arme;
	sf::Clock clock,clockVie;
public:
	
	Personnage(int vie, int dégat, std::string nom);
	int getDimensionH();
	int getDimensionL();
	int getVie();
	void deplacement(sf::Time  duréeitération, sf::RenderWindow * window);
	void update(sf::Event event);
	void testingCollision(Arme * arme, Ennemi * ennemi, std::vector<Ennemi*> * tabEnnemi,std::vector<sf::CircleShape*>*tabObjRamassé);
	void deplacementBalle(sf::Time duréeitération, sf::RenderWindow * window);
	Arme  * getArme();
	sf::Sprite * getSpritePerso();
	int getPositionX();
	int getPositionY();
	void regenerationVie();
	void ramasseBoiteSecours(int pvBoite);
};

