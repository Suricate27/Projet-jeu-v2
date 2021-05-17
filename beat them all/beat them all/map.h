#pragma once
#include <iostream>
#include <SFML/graphics.hpp>
#include "Arme.h"
#include "Crate.h"
#include "BoiteSecours.h"
#define longueurEcran 500
#define largeurEcran 1000


class Map 
{
protected:
	
	std::vector<BoiteSecours*> TabBoiteSecours; //tableau de cercle
	std::vector<sf::RectangleShape*> tabBarreVie;
	std::vector<sf::Sprite*>tabFond;
	std::vector <Crate*> tabCrate;
	sf::RectangleShape *BarreVie = new sf::RectangleShape;
	sf::RectangleShape *BarreVieBordure = new sf::RectangleShape;
	sf::RectangleShape *BarreFatigue = new sf::RectangleShape;
	sf::Font font;
	sf::Text *text = new sf::Text;
	sf::Text *textmun = new sf::Text;
	sf::Text *textmenu = new sf::Text;
	sf::Texture textureBack;
	sf::Sprite spriteBack;
	float width;
	int dimension_back_H = 500;
	int dimension_back_L = 744;
public:
	Map(int maplevel);
	void affichageBarreVie(int centreVue, int vieJoueur,float fatigueJoueur);
	void creationBoiteSecours(float positionX, float positionY);
	void afficherTexte(sf::Vector2f PositionBarreVie);
	void affichageTextMunitions(int munitions, sf::Vector2f PositionBarreVie);
	void affichage(sf::RenderWindow * window);
	void CreationBoite(int positionX, int positionY);
	std::vector<BoiteSecours*> * getTabBoiteSecours();
	std::vector<sf::RectangleShape*> * getTabBarreVie();
	std::vector <sf::Sprite*>*getTabFond();
	std::vector <Crate*>*getTabCrate();
	sf::Vector2f getPositionBarreVie();
	sf::Sprite * getSpriteBack();

	int getDimensionCrate();
	int getDimensionSecours();
};

