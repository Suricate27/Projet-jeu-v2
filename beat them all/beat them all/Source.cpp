//test pour github partie Laurent
// dev enemi
// test
#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>
#include "Personnage.h"
#include "Map.h"
#include "Arme.h"
#include "Balles.h"
#include "Ennemi.h"
#include <ShellScalingApi.h>
#define largeurEcran 2400
#define longueurEcran 1500
//fonction
void paramVue(sf::View *vue, sf::Sprite *spritePerso, sf::RenderWindow *window, Personnage *hero);

#define taillePersonnage 192

int main() {
	//objet
	Personnage hero = Personnage(100, 100, "test");
	Map carte;
	//fen�tre
	sf::RenderWindow window(sf::VideoMode(largeurEcran, longueurEcran), "Allume les tous !"); //cr�ation de la fen�tre (dimension, titre)
	sf::View vue; // déclaration de la vue
	sf::Clock clock;
	sf::Time Dureeiteration;
	Map niveau1;
	//création de 3 cercles
	Ennemi * mechant = new Ennemi(1);
	std::vector <Ennemi*> tabEnnemis;
	tabEnnemis.push_back(mechant);

	niveau1.creationBoiteSecours(1000, 1000);
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
				hero.update(event);
				break;
			}//gestion clavier 	
		}
		hero.deplacement(Dureeiteration,&window); // gestion animation + déplacement
		hero.testingCollision(hero.getArme(), mechant, &tabEnnemis,niveau1.getTabBoiteSecours());
		mechant->deplacement(hero.getPositionX(), hero.getPositionY());
		hero.regenerationVie();
		
		////////////////////AFFICHAGE///////////////////////////
		window.clear();//nettoyage
		paramVue(&vue, hero.getSpritePerso(), &window, &hero);// paramétrage de la vue
		window.draw(*hero.getSpritePerso()); // affichage de notre personnage
		
		niveau1.affichageBarreVie(vue.getCenter().x,hero.getVie());
		for (sf::RectangleShape * rect : *niveau1.getTabBarreVie())
		{
			window.draw(*rect);
		}
		niveau1.affichageTextMunitions(hero.getArme()->getMunitions());
		niveau1.afficherTexte(niveau1.getPositionBarreVie());
		niveau1.affichage(&window);
		for (sf::CircleShape * objet : *niveau1.getTabBoiteSecours()) {
			window.draw(*objet);
		}
		for (Ennemi * mechant : tabEnnemis) {
			window.draw(*mechant->getSpriteEnnemi());
		}
		hero.deplacementBalle(Dureeiteration, &window);
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
