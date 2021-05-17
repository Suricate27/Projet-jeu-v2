#include "Balles.h"
Balles::Balles(float positionX, float positionY,int direction, int tailleH, int tailleL){
	dureeVie = clock.restart();
 	cercle = new sf::CircleShape(diametre);
	cercle->setFillColor(sf::Color::Yellow);
	cercle->setPosition(positionX+ tailleL /2, positionY+ tailleH /3);
	this->vitesse = this->vitesse*direction;
}
Balles::~Balles() {
	delete cercle;
}
void Balles::avancer(sf::Time duréeitération, sf::RenderWindow * window) {
	cercle->move(vitesse * duréeitération.asSeconds(), 0);
	window->draw(*cercle);
}
sf::Time Balles::getDureeVie() {
	dureeVie += clock.restart();
	return dureeVie;
}
sf::Time Balles::getDureeVieMax() {
	return dureeVieMax;
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
