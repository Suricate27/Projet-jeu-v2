#include "Map.h"
void Map::creationBoiteSecours(float positionX, float positionY) {
	sf::CircleShape *cercle = new sf::CircleShape(50);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	TabBoiteSecours.push_back(cercle);
}
std::vector<sf::CircleShape*> * Map::getTabBoiteSecours() {
	return &TabBoiteSecours;
}
