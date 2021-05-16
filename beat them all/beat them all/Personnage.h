#pragma once
#include <string.h>
#include <SFML/graphics.hpp>
#include "Arme.h"
#include "Ennemi.h"
#include "Crate.h"
#include "BoiteSecours.h"
#define longueurEcran 500
#define largeurEcran 1000
#define nombreSprite 9
class Personnage
{
protected:
	int vie;
	int dégat;
	float vitesseDeplacement = 400;
	std::string nom;
	int degatCac = 5;
	int dimensionL = 66;
	int dimensionH = 78;
	int direction = 1;
	float fatigue = 1;
	enum direction { haut, gauche, bas, droite };
	sf::Vector2i animation; // tableau à 2 dimension et que pour des int ( d'où le 2i) , x et y
	bool updateFPS = false, moveUp = false, moveDown = false, moveRight = false, moveLeft = false,tirer = false,regenerationFatigue = true,cac=false;
	sf::Texture texturePerso;
	sf::Sprite spritePerso;
	sf::Clock clockAnimation;
	int laurent;
	Arme * arme;
	sf::Clock clock,clockVie,clockfatigue,clockcorpacorp;
public:
	
	Personnage(int vie, int dégat, std::string nom);
	int getDimensionH();
	int getDimensionL();
	int getVie();
	void deplacement(sf::Time  duréeitération, sf::RenderWindow * window, std::vector<Crate*>*tabCrate);
	void update(sf::Event event);
	void testingCollision(Arme * arme, Ennemi * ennemi, std::vector<Ennemi*> * tabEnnemi,std::vector<BoiteSecours*>*tabObjRamassé);
	void deplacementBalle(sf::Time duréeitération, sf::RenderWindow * window);
	Arme  * getArme();
	sf::Sprite * getSpritePerso();
	int getPositionX();
	int getPositionY();
	void regenerationVie();
	void ramasseBoiteSecours(int pvBoite);
	float getFatigue();
	void setFatigue();
	void regenFatigue();
};

