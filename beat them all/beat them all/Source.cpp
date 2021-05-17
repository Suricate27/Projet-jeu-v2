//test pour github partie Laurent
// dev enemi
// test
#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>
#include <Windows.h> 
//#include <WinUser.h>
//#include <ShellScalingApi.h>
#include "Personnage.h"
#include "Map.h"
#include "Arme.h"
#include "Balles.h"
#include "Ennemi.h"
#include "Header.h"
#include "Crate.h"
#define longueurEcran 500
#define largeurEcran 1000
//fonction
void paramVue(sf::View *vue, sf::Sprite *spritePerso, sf::RenderWindow *window, Personnage *hero);
void nettoyage(Map *niveau);
int main() {
	std::cout <<"largeur ecran : " <<largeurEcran << std::endl;
	//objet
	bool menuIsOpen = true;
	bool GodMode = 0;
	srand(time(NULL));
	//fen�tre
	sf::RenderWindow window(sf::VideoMode(largeurEcran, longueurEcran), "Beat Them All", sf::Style::Close); //cr�ation de la fen�tre (dimension, titre)
	sf::View vue; // déclaration de la vue
	sf::Clock clock;
	sf::Time Dureeiteration;
	sf::Font font;
	sf::Text *textmenu = new sf::Text;
	int mapLevel=1;
	int selectionMenu = 1;
	Map *niveau = new Map(1);
	Ennemi *ennemi=new Ennemi(1);
	Personnage *hero = new Personnage(100, 100, "Lord");
	bool vague1 = 0, vague2 = 0, vague3 = 0, vagueBoss = 0;
flag:
	vague1 = 0, vague2 = 0, vague3 = 0, vagueBoss = 0;
	niveau = new Map(mapLevel);
	if (!menuIsOpen) {
		hero = new Personnage(100, 100, "Lord");
		ennemi = new Ennemi(1);
		ennemi->apparition(4);
		ennemi->apparition(1);
		for (int i = 0; i < 10/mapLevel; i++) {
			niveau->creationBoiteSecours((rand() % 500 + 700) + i * 1000, (rand() % 200 + 300) - niveau->getDimensionSecours());
		}
		for (int i = 0; i < 6*mapLevel; i++) {
			niveau->CreationBoite((rand() % 500 + 700) + i * 2000, (rand() % 200 + 300) - niveau->getDimensionCrate());
		}
		
	}
	//début de la boucle fenetre ouverte
	while (window.isOpen()) {
		Dureeiteration = clock.restart();
		sf::Event event; //  création d'un object evenement
		window.setFramerateLimit(100); //FPS limit 100
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:  // permet de fermer la fen�tre si on clique sur la croix
				window.close();
				break;
			default:
				hero->update(event);
				if (menuIsOpen) {
					switch (event.type)
					{
					case sf::Event::KeyPressed:
						switch (event.key.code)
						{
						case sf::Keyboard::Down:
							if (selectionMenu < 2)selectionMenu += 1;
							std::cout << selectionMenu << std::endl;
							break;
						case sf::Keyboard::Up:
							if (selectionMenu > 1)selectionMenu -= 1;
							std::cout << selectionMenu << std::endl;
							break;
						case sf::Keyboard::Enter:
							mapLevel = selectionMenu;
							menuIsOpen = false;
							goto flag;
						}
					}		
				}
				break;
			}//gestion clavier 	
		}
		if(menuIsOpen){
		window.clear();//nettoyage
		//niveau->.affichageMenu();
		//niveau->.affichage(&window);
		if (!font.loadFromFile("arial.ttf")) {
			std::cout << "Erreur chargement Police : arial.ttf introuvable" << std::endl;
		}
		textmenu->setString("Menu");
		textmenu->setFont(font);
		textmenu->setCharacterSize(largeurEcran / 30);
		textmenu->setFillColor(sf::Color::Blue);
		textmenu->setPosition(vue.getCenter().x - textmenu->getLocalBounds().width/2, 0);
		window.draw(*textmenu);
		textmenu->setString("Jouer niveau 1");
		if(selectionMenu == 1)textmenu->setFillColor(sf::Color::Red);
		else textmenu->setFillColor(sf::Color::White);
		textmenu->setCharacterSize(largeurEcran / 50);
		textmenu->setPosition(vue.getCenter().x- textmenu->getLocalBounds().width/2, 100);
		window.draw(*textmenu);
		textmenu->setString("Jouer niveau 2");
		if (selectionMenu == 2)textmenu->setFillColor(sf::Color::Red);
		else textmenu->setFillColor(sf::Color::White);
		textmenu->setCharacterSize(largeurEcran / 50);
		textmenu->setPosition(vue.getCenter().x - textmenu->getLocalBounds().width/2, 200);
		window.draw(*textmenu);
		}
		if (!menuIsOpen) {
			if (hero->getSpritePerso()->getPosition().x> 2000 && vague1 == false)
			{
				vague1 = true;
				for (int i = 0; i < 4*mapLevel; i++) {
					ennemi->apparition(1, hero->getSpritePerso()->getPosition().x);
				}
			}
			if (hero->getSpritePerso()->getPosition().x > 4000 && vague2 == false)
			{
				vague2= true;
				for (int i = 0; i < 4*mapLevel; i++) {
					ennemi->apparition(2, hero->getSpritePerso()->getPosition().x);
				}
			}
			if (hero->getSpritePerso()->getPosition().x > 6000 && vague3 == false)
			{
				vague3= true;
				for (int i = 0; i < 4*mapLevel; i++) {
					ennemi->apparition(3, hero->getSpritePerso()->getPosition().x);
				}
			}
			if (hero->getSpritePerso()->getPosition().x > 10000 && vagueBoss == false)
			{
				vagueBoss = true;
				for (int i = 0; i < 2*mapLevel; i++) {
					ennemi->apparition(4, hero->getSpritePerso()->getPosition().x);
				}	
				
			}
			hero->deplacement(Dureeiteration, &window, niveau->getTabCrate()); // gestion animation + déplacement
			hero->testingCollision(hero->getArme(),ennemi->getTabEnnemi(), niveau->getTabBoiteSecours());
			for (Ennemi * mechant : *ennemi->getTabEnnemi()) {
				mechant->deplacement(hero->getPositionX(), hero->getPositionY());
			}
			hero->regenerationVie();
			hero->regenFatigue();
			if (!GodMode) {
				if (hero->getVie() <= 0) {
					menuIsOpen = true;
				}
			}
			if (ennemi->getTabEnnemi()->size() == 0 && vagueBoss == true) {
				mapLevel = 2;
				nettoyage(niveau);
				goto flag;
			}
			////////////////////AFFICHAGE///////////////////////////
		window.clear();//nettoyage

		paramVue(&vue, hero->getSpritePerso(), &window, hero);// paramétrage de la vue
		for (sf::Sprite * sprite : *niveau->getTabFond()) {
			window.draw(*sprite);
		}
		for (Crate * crate : *niveau->getTabCrate()) {
			window.draw(*crate->getSpriteCrate());
		}
		window.draw(*hero->getSpritePerso()); // affichage de notre personnage
		
		niveau->affichageBarreVie(vue.getCenter().x,hero->getVie(),hero->getFatigue());
		for (sf::RectangleShape * rect : *niveau->getTabBarreVie())
		{
			window.draw(*rect);
		}
		niveau->affichageTextMunitions(hero->getArme()->getMunitions(), niveau->getPositionBarreVie());
		niveau->afficherTexte(niveau->getPositionBarreVie());
		niveau->affichage(&window);
		for (BoiteSecours * objet : *niveau->getTabBoiteSecours()) {
			window.draw(*objet->getsprite());
		}
		for (Ennemi * mechant : *ennemi->getTabEnnemi()) {
			window.draw(*mechant->getSpriteEnnemi());
		}
		hero->deplacementBalle(Dureeiteration, &window);
		}

		window.display();//affichage de la fenétre
		if (menuIsOpen) {
			nettoyage(niveau);
		}
	}
}
void paramVue(sf::View *vue, sf::Sprite *spritePerso, sf::RenderWindow *window, Personnage *hero) {

	vue->reset(sf::FloatRect(0, 0, largeurEcran, longueurEcran)); // declaration d'une vue qui d�marre en 0,0 et qui fait la taille de la fen�tre
	sf::Vector2f position(largeurEcran / 2, longueurEcran / 2); //vue au centre ecran 

	position.x = spritePerso->getPosition().x + (hero->getDimensionH() / 2) - (largeurEcran*0.666); // la vue vers la gauche peut bouger mais pas avant que le perso soit � 2/3 de l'ecran
	position.y = 0; // la vue verticale ne bouge pas

	if (position.x <= 0)position.x = 0; // si la vue doit d�passer l'ecran vers la gauche, elle ne le fait pas
	vue->reset(sf::FloatRect(position.x, position.y, largeurEcran, longueurEcran)); // reset de la vue
	window->setView(*vue); // affichage de la vue 

}
void nettoyage(Map *niveau) {
	for (BoiteSecours * objet : *niveau->getTabBoiteSecours()) {
		delete objet;
	}
	niveau->getTabBoiteSecours()->clear();
	for (Crate * crate : *niveau->getTabCrate()) {
		delete crate;
	}
	niveau->getTabCrate()->clear();
}



