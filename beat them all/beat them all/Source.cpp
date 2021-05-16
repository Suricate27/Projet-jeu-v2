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

int main() {
	std::cout <<"largeur ecran : " <<largeurEcran << std::endl;
	//objet
	bool menuIsOpen = true;
	
	//fen�tre
	sf::RenderWindow window(sf::VideoMode(largeurEcran, longueurEcran), "Beat Them All", sf::Style::Close); //cr�ation de la fen�tre (dimension, titre)
	sf::View vue; // déclaration de la vue
	sf::Clock clock;
	sf::Time Dureeiteration;
	sf::Font font;
	sf::Text *textmenu = new sf::Text;
	int mapLevel;
	Map niveau1;
	//création de 3 cercles
	Ennemi * mechant = new Ennemi(1);
	std::vector <Ennemi*> tabEnnemis;
	tabEnnemis.push_back(mechant);
	int selectionMenu=1;
	niveau1.creationBoiteSecours(1000, 400);
	niveau1.CreationBoite(70, 70);
	niveau1.CreationBoite(500, 400);
	Personnage *hero = new Personnage(100, 100, "test");;
	//début de la boucle fenetre ouverte
	while (window.isOpen()) {
		if (!menuIsOpen) {
			Personnage *hero = new Personnage(100, 100, "test");
		}
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
						}
					

					}
				
					
				}
				break;
			}//gestion clavier 	
		}
		if(menuIsOpen){
		window.clear();//nettoyage
		//niveau1.affichageMenu();
		//niveau1.affichage(&window);
		if (!font.loadFromFile("arial.ttf")) {
			std::cout << "Erreur chargement Police : arial.ttf introuvable" << std::endl;
		}
		textmenu->setString("Menu");
		textmenu->setFont(font);
		textmenu->setCharacterSize(largeurEcran / 30);
		textmenu->setFillColor(sf::Color::Blue);
		textmenu->setPosition((largeurEcran / 2) - textmenu->getLocalBounds().width/2, 0);
		window.draw(*textmenu);
		textmenu->setString("Jouer niveau 1");
		if(selectionMenu == 1)textmenu->setFillColor(sf::Color::Red);
		else textmenu->setFillColor(sf::Color::White);
		textmenu->setCharacterSize(largeurEcran / 50);
		textmenu->setPosition((largeurEcran / 2) - textmenu->getLocalBounds().width/2, 100);
		window.draw(*textmenu);
		textmenu->setString("Jouer niveau 2");
		if (selectionMenu == 2)textmenu->setFillColor(sf::Color::Red);
		else textmenu->setFillColor(sf::Color::White);
		textmenu->setCharacterSize(largeurEcran / 50);
		textmenu->setPosition((largeurEcran / 2) - textmenu->getLocalBounds().width/2, 200);
		window.draw(*textmenu);
		}
		if (!menuIsOpen) {
			hero->deplacement(Dureeiteration, &window, niveau1.getTabCrate()); // gestion animation + déplacement
			hero->testingCollision(hero->getArme(), mechant, &tabEnnemis, niveau1.getTabBoiteSecours());
			mechant->deplacement(hero->getPositionX(), hero->getPositionY());
			hero->regenerationVie();
			hero->regenFatigue();
			if (hero->getVie() <= 0) {
				menuIsOpen = true;
			}
			////////////////////AFFICHAGE///////////////////////////
		window.clear();//nettoyage

		paramVue(&vue, hero->getSpritePerso(), &window, hero);// paramétrage de la vue
		for (sf::Sprite * sprite : *niveau1.getTabFond()) {
			window.draw(*sprite);
		}
		for (Crate * crate : *niveau1.getTabCrate()) {
			window.draw(*crate->getSpriteCrate());
		}
		window.draw(*hero->getSpritePerso()); // affichage de notre personnage
		
		niveau1.affichageBarreVie(vue.getCenter().x,hero->getVie(),hero->getFatigue());
		for (sf::RectangleShape * rect : *niveau1.getTabBarreVie())
		{
			window.draw(*rect);
		}
		niveau1.affichageTextMunitions(hero->getArme()->getMunitions(), niveau1.getPositionBarreVie());
		niveau1.afficherTexte(niveau1.getPositionBarreVie());
		niveau1.affichage(&window);
		for (BoiteSecours * objet : *niveau1.getTabBoiteSecours()) {
			window.draw(*objet->getsprite());
		}
		for (Ennemi * mechant : tabEnnemis) {
			window.draw(*mechant->getSpriteEnnemi());
		}
		hero->deplacementBalle(Dureeiteration, &window);
		}
		window.display();//affichage de la fenétre
		
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



