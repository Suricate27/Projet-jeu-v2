#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Arme.h"
#define longueurEcran 500
#define largeurEcran 1000


class Map 
{
protected:
	
	std::vector<sf::CircleShape*> TabBoiteSecours; //tableau de cercle
	std::vector<sf::RectangleShape*> tabBarreVie;
	int dimension_back_H = 764;
	int dimension_back_L = 10000;
	std::vector<sf::CircleShape*> objets; //tableau de cercle
	sf::CircleShape cercle; //d�claration de la variable
	sf::RectangleShape *BarreVie = new sf::RectangleShape;
	sf::RectangleShape *BarreVieBordure = new sf::RectangleShape;
	sf::RectangleShape *BarreFatigue = new sf::RectangleShape;
	sf::Font font;
	sf::Text *text = new sf::Text;
	sf::Text *textmun = new sf::Text;
	float width;
	sf::Texture textureBack;
	sf::Sprite spriteBack;
	

public:
	Map();
	void creationCercle(float positionX, float positionY);
	void avancer();
	std::vector<sf::CircleShape*> * getTabBoiteSecours();
	void affichageBarreVie(int centreVue, int vieJoueur,float fatigueJoueur);
	void creationBoiteSecours(float positionX, float positionY);
	std::vector<sf::RectangleShape*> * getTabBarreVie();
	void afficherTexte(sf::Vector2f PositionBarreVie);
	sf::Vector2f getPositionBarreVie();
	void affichageTextMunitions(int munitions, sf::Vector2f PositionBarreVie);
	void affichage(sf::RenderWindow * window);
	sf::Sprite * getSpriteBack();


	std::vector<sf::CircleShape*> * getObjets();
};

