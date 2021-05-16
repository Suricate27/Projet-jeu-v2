#include "Balles.h"
Balles::Balles(float positionX, float positionY,int direction, sf::RenderWindow * window){
	dureeVie = clock.restart();
 	cercle = new sf::CircleShape(diametre);
	cercle->setFillColor(sf::Color::Yellow);
	cercle->setPosition(positionX+taillePersonnage/2, positionY+ taillePersonnage/3);
	this->vitesse = this->vitesse*direction;
}

void Balles::avancer(sf::Time duréeitération, sf::RenderWindow * window) {
	cercle->move(vitesse * duréeitération.asSeconds(), 0);
	window->draw(*cercle);
}
Balles::~Balles() {
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
int Balles::getDiametre() {
	return diametre;
}
