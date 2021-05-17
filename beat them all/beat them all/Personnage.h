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
	int degatCac = 5;
	int dimensionL = 67;
	int dimensionH = 80;
	int direction = 1;
	float vitesseDeplacementinit = 400;
	float vitesseDeplacement;
	float fatigue = 1;
	enum direction { haut, gauche, bas, droite };
	bool updateFPS = false, moveUp = false, moveDown = false, moveRight = false, moveLeft = false,tirer = false,regenerationFatigue = true,cac=false;
	std::string nom;
	sf::Vector2i animation;
	sf::Texture texturePerso;
	sf::Sprite spritePerso;
	sf::Clock clockAnimation;
	sf::Clock clock, clockVie, clockfatigue, clockcorpacorp;
	Arme * arme;
	
public:
	
	Personnage(int vie, int dégat, std::string nom);
	~Personnage();
	void deplacement(sf::Time  duréeitération, std::vector<Crate*>*tabCrate);
	void update(sf::Event event);
	void testingCollision(std::vector<Ennemi*> * tabEnnemi,std::vector<BoiteSecours*>*tabObjRamassé);
	void deplacementBalle(sf::Time duréeitération, sf::RenderWindow * window);
	void setFatigue();
	void regenFatigue();
	void regenerationVie();
	void ramasseBoiteSecours(int pvBoite);
	Arme  * getArme();
	sf::Sprite * getSpritePerso();
	int getDimensionH();
	int getDimensionL();
	int getVie();
	int getPositionX();
	int getPositionY();
	float getFatigue();

};

