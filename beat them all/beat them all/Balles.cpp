#include "Balles.h"
Balles::Balles(float positionX, float positionY, sf::RenderWindow * window){
	std::cout << "création balles" << std::endl;
	dureeVie = clock.restart();
	cercle = new sf::CircleShape(10);
	cercle->setFillColor(sf::Color::Yellow);
	cercle->setPosition(positionX+taillePersonnage/2, positionY+ taillePersonnage/3);
}

void Balles::avancer(sf::Time duréeitération, sf::RenderWindow * window) {
	cercle->move(vitesse * duréeitération.asSeconds(), 0);
	window->draw(*cercle);
}
Balles::~Balles() {
	//std::cout << "balle détruite" << std::endl;
	delete cercle;
}
sf::Time Balles::getDureeVie() {
	dureeVie += clock.restart();
	return dureeVie;
}
float Balles::getPositionX() {
	return cercle->getPosition().x;
}
float Balles::getPositionY() {
	return cercle->getPosition().y;
}
