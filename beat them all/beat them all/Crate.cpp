#include "Crate.h"

Crate::Crate(int positionX,int positionY) {
	if (!texture.loadFromFile("Textures/Crate.png") ){
		std::cout <<"erreur chargement texture crate"<<std::endl;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, dimension, dimension));
	sprite.setPosition(positionX, positionY);
}
int Crate::getDimension() {
	return dimension;
}
sf::Sprite * Crate::getSpriteCrate() {
	return &sprite;
}