#include "Map.h"

Map::Map() {
	if (!textureBack.loadFromFile("Textures/Back.png")) // vérif ouverture fichier
	{
		std::cout << "Erreur chargement texture back" << std::endl;
	}
	textureBack.setSmooth(true);
	spriteBack.setTexture(textureBack);
	spriteBack.setTextureRect(sf::IntRect(dimension_back_H, dimension_back_L, dimension_back_L, dimension_back_H)); 
	spriteBack.setPosition(0, 0); 
}
std::vector<sf::CircleShape*> * Map::getObjets() {
	return &objets;
}
void Map::creationCercle(float positionX, float positionY) { //crée les cercles
	sf::CircleShape *cercle = new sf::CircleShape(100);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	objets.push_back(cercle);
}
void Map::updateMap() {

}
sf::Sprite *Map::getSpriteBack() {
	return  &spriteBack;
}