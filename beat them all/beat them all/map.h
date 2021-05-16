#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Arme.h"

class Map 
{
protected:
	
	std::vector<sf::CircleShape*> TabBoiteSecours; //tableau de cercle
	std::vector<sf::RectangleShape*> tabBarreVie;
	std::vector<sf::Text*> tabText;
	sf::CircleShape cercle; //déclaration de la variable
	sf::RectangleShape *BarreVie = new sf::RectangleShape;
	sf::RectangleShape *BarreVieBordure = new sf::RectangleShape;
	sf::Font font;
	sf::Text text;
	float width;

public:

	void creationCercle(float positionX, float positionY);
	void avancer();
	std::vector<sf::CircleShape*> * getTabBoiteSecours();
	std::vector<sf::Text*> * getTabTexte();
	void affichageBarreVie(int centreVue,int vieJoueur);
	void creationBoiteSecours(float positionX, float positionY);
	std::vector<sf::RectangleShape*> * getTabBarreVie();
	void afficherTexte(sf::Vector2f PositionBarreVie);
	sf::Vector2f getPositionBarreVie();
};

