//test pour github partie Laurent
// dev enemi
#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>
#include "Personnage.h"
#include "Map.h"
#include "Arme.h"
#include "Balles.h"
#include "Ennemi.h"
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
	sf::RenderWindow window(sf::VideoMode(largeurEcran, longueurEcran), "Fenetre SFML"); //cr�ation de la fen�tre (dimension, titre)
	sf::View vue; // d�claration de la vue
	sf::Clock clock;
	sf::Time Dureeiteration;
	//cr�ation de 3 cercles
	Ennemi mechant = Ennemi(3);


	//d�but de la boucle fenetre ouverte
	while (window.isOpen()) {
		Dureeiteration = clock.restart();
		sf::Event event; //  cr�ation d'un object evenement
		window.setFramerateLimit(100); //FPS limit 100
		while (window.pollEvent(event)) {

			switch (event.type)
			{
			case sf::Event::Closed:  // permet de fermer la fen�tre si on clique sur la croix
				window.close();
				break;
			default:
				hero.update(event, &window);
				break;
			}//gestion clavier 	
		}
		hero.deplacement(Dureeiteration); // gestion annimation + d�placement

		window.clear(); //nettoyage
		paramVue(&vue, hero.getSpritePerso(), &window, &hero); // param�trage de la vue
		hero.deplacementBalle(Dureeiteration, &window);
		window.draw(*hero.getSpritePerso()); // affichage de notre personnage
		window.draw(*mechant.getSpriteEnnemi());
		window.display();//affichage de la fen�tre
	}
}
void paramVue(sf::View *vue, sf::Sprite *spritePerso, sf::RenderWindow *window, Personnage *hero) {

	vue->reset(sf::FloatRect(0, 0, largeurEcran, longueurEcran)); // declaration d'une vue qui d�marre en 0,0 et qui fait la taille de la fen�tre
	sf::Vector2f position(largeurEcran / 2, longueurEcran / 2); //vue au centre ecran 

	position.x = spritePerso->getPosition().x + (hero->getDimension() / 2) - (largeurEcran*0.666); // la vue vers la gauche peut bouger mais pas avant que le perso soit � 2/3 de l'ecran
	position.y = 0; // la vue verticale ne bouge pas

	if (position.x <= 0)position.x = 0; // si la vue doit d�passer l'ecran vers la gauche, elle ne le fait pas
	vue->reset(sf::FloatRect(position.x, position.y, largeurEcran, longueurEcran)); // reset de la vue
	window->setView(*vue); // affichage de la vue 

}
