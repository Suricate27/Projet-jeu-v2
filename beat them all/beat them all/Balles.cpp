#include "Balles.h"
Balles::Balles(float positionX, float positionY, sf::RenderWindow * window){
	std::cout << "création balles" << std::endl;

	//sf::CircleShape *cercle = new sf::CircleShape(100);
	cercle = new sf::CircleShape(100);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	
}

void Balles::avancer(sf::Time duréeitération, sf::RenderWindow * window) {
	//std::cout << "Avance" << std::endl;
	cercle->move(vitesse * duréeitération.asSeconds(), 0);
	std::cout << cercle->getPosition().y << std::endl;
	window->draw(*cercle);
}
