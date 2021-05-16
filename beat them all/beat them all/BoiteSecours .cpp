#include "BoiteSecours.h"

BoiteSecours::BoiteSecours(int positionX,int positionY) {
	if (!texture.loadFromFile("Textures/Medic.png")) {
		std::cout << "erreur chargement texture Medic" << std::endl;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, dimension, dimension));
	sprite.setPosition(positionX, positionY);

}
int BoiteSecours::getDimension() {
	return dimension;
 }
sf::Sprite * BoiteSecours::getsprite() {
	return &sprite;
}