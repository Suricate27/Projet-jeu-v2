#include "Balles.h"
Balles::Balles(float positionX, float positionY, sf::RenderWindow * window){
	std::cout << "cr�ation balles" << std::endl;
	dureeVie = clock.restart();
	cercle = new sf::CircleShape(10);
	cercle->setFillColor(sf::Color::Yellow);
	cercle->setPosition(positionX+taillePersonnage/2, positionY+ taillePersonnage/3);
}

void Balles::avancer(sf::Time dur�eit�ration, sf::RenderWindow * window) {
	cercle->move(vitesse * dur�eit�ration.asSeconds(), 0);
	window->draw(*cercle);
}
Balles::~Balles() {
	//std::cout << "balle d�truite" << std::endl;
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
