#include "Balles.h"
Balles::Balles(float positionX, float positionY, sf::RenderWindow * window){
	std::cout << "création balles" << std::endl;

	cercle = new sf::CircleShape(100);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	
}

void Balles::avancer(sf::Time duréeitération, sf::RenderWindow * window) {
	cercle->move(vitesse * duréeitération.asSeconds(), 0);
	std::cout << cercle->getPosition().x << std::endl;
	window->draw(*cercle);
}
