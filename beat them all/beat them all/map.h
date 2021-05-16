#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include <Windows.h>
#include "Arme.h"

#define largeurEcran (GetSystemMetrics(SM_CXSCREEN)/4*3) //3/4 de la largeur de l'écran
#define longueurEcran (GetSystemMetrics(SM_CYSCREEN)/4*3)//3/4 de la longueur de l'écran


class Map 
{
protected:
	
	std::vector<sf::CircleShape*> TabBoiteSecours; //tableau de cercle
	std::vector<sf::RectangleShape*> tabBarreVie;
	int dimension_back_H = 764;
	int dimension_back_L = 1000;
	std::vector<sf::CircleShape*> objets; //tableau de cercle
	sf::CircleShape cercle; //d�claration de la variable
	sf::RectangleShape *BarreVie = new sf::RectangleShape;
	sf::RectangleShape *BarreVieBordure = new sf::RectangleShape;
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
	void affichageBarreVie(int centreVue,int vieJoueur);
	void creationBoiteSecours(float positionX, float positionY);
	std::vector<sf::RectangleShape*> * getTabBarreVie();
	void afficherTexte(sf::Vector2f PositionBarreVie);
	sf::Vector2f getPositionBarreVie();
	void affichageTextMunitions(int munitions, sf::Vector2f PositionBarreVie);
	void affichage(sf::RenderWindow * window);
	sf::Sprite * getSpriteBack();


	std::vector<sf::CircleShape*> * getObjets();
};

