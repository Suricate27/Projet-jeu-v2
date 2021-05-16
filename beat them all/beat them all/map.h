#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Arme.h"
#include "Crate.h"
#define longueurEcran 500
#define largeurEcran 1000


class Map 
{
protected:
	
	std::vector<sf::CircleShape*> TabBoiteSecours; //tableau de cercle
	std::vector<sf::RectangleShape*> tabBarreVie;
	std::vector<sf::Sprite*>tabFond;
	std::vector <Crate*> tabCrate;
	int dimension_back_H = 500;
	int dimension_back_L = 744;
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
	void CreationBoite(int positionX,int positionY);
	sf::Sprite * getSpriteBack();
	std::vector <sf::Sprite*>*getTabFond();
	std::vector <Crate*>*getTabCrate();

	std::vector<sf::CircleShape*> * getObjets();
};

