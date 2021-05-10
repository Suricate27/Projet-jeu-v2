#pragma once
#include <string.h>
#include <SFML/graphics.hpp>
#include "Arme.h"

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
	int dimension = 192;
	enum direction { haut, gauche, bas, droite };
	sf::Vector2i animation; // tableau à 2 dimension et que pour des int ( d'où le 2i) , x et y
	bool updateFPS = false, moveUp = false, moveDown = false, moveRight = false, moveLeft = false;
	sf::Texture texturePerso;
	sf::Sprite spritePerso;
	sf::Clock clockAnimation;
	Arme *arme;
public:
	
	Personnage(int vie, int dégat, std::string nom);
	int getDimension();
	void deplacement(sf::Time  duréeitération, sf::RenderWindow * window);
	void update(sf::Event event, sf::RenderWindow * window);
	void testingCollision(std::vector<sf::CircleShape*>  * objets);
	sf::Sprite * getSpritePerso();
	
	
};

