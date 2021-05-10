#include "Map.h"

std::vector<sf::CircleShape*> * Map::getObjets() {
	return &objets;
}
void Map::creationCercle(float positionX, float positionY) { //crée les cercles
	sf::CircleShape *cercle = new sf::CircleShape(100);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	objets.push_back(cercle);
}
