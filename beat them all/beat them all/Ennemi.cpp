#include "Ennemi.h"
Ennemi::Ennemi(int niveau) {
	vie = 100*niveau;
	degat = 5*niveau;
	this->niveau = niveau;
	vitesse = 300*((niveau+2)/3); //vitesse par niveau (1|1.33|1.66|2)
	animation = sf::Vector2i((13 - 3 * niveau), haut);
	// chargement de la texture
	if (!textureEnnemi.loadFromFile("Textures/SpriteEnnemi.png")) // vérif ouverture fichier
	{
		std::cout << "Erreur chargement texture ennemi" << std::endl;
	}
	textureEnnemi.setSmooth(true);
	spriteEnnemi.setTexture(textureEnnemi);
	spriteEnnemi.setTextureRect(sf::IntRect((13 - 3 * niveau)*dimensionL, dimensionH, dimensionL, dimensionH)); // Pour que le premier affichage du personnage soit vers la droite
	spriteEnnemi.setPosition(1000, 1200);
}
Ennemi::~Ennemi() {

}
void Ennemi::recevoirDegat(int degat) {
	vie -= degat;
}
int Ennemi::getDegat() {
	return degat;
}
int Ennemi::getVie() {
	return vie;
}
void Ennemi::deplacement() {

}
void Ennemi::setVie(int degat) {

}
sf::Sprite * Ennemi::getSpriteEnnemi() {
	return &spriteEnnemi;
}