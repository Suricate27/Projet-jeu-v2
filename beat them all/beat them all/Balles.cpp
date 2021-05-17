#include "Balles.h"
Balles::Balles(float positionX, float positionY,int direction, int tailleH, int tailleL){
	dureeVie = clock.restart();
 	cercle = new sf::CircleShape(diametre);
	cercle->setFillColor(sf::Color::Yellow);
	cercle->setPosition(positionX+ tailleL /2, positionY+ tailleH /3);
	this->vitesse = this->vitesse*direction;
}

void Balles::avancer(sf::Time dur�eit�ration, sf::RenderWindow * window) {
	cercle->move(vitesse * dur�eit�ration.asSeconds(), 0);
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
