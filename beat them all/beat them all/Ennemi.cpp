#include "Ennemi.h"
Ennemi::Ennemi(int niveau) {
	vie = 100*niveau;
	degat = 5*niveau;
	this->niveau = niveau;
	vitesse = 2*((niveau+2)/3); //vitesse par niveau (1|1.33|1.66|2)
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
void Ennemi::deplacement(int positionPersonnageX,int positionPersonnageY) {
	if (abs(positionPersonnageX - spriteEnnemi.getPosition().x) > 100) {
		if (positionPersonnageX > spriteEnnemi.getPosition().x) {
			spriteEnnemi.move(vitesse, 0);
			if (nombreSprite == 0)nombreSprite = 3;
			spriteEnnemi.setTextureRect(sf::IntRect((((12 - 3 * niveau)-nombreSprite)+3)*dimensionL, 2 * dimensionH, dimensionL, dimensionH));
			
			if (clockAnimation.getElapsedTime().asMilliseconds() >= (1 / (float)vitesse) * 500)
			{
				nombreSprite--;
				clockAnimation.restart();
			}
			
		}
		else {
			spriteEnnemi.move(-vitesse, 0);
			if (nombreSprite == 0)nombreSprite = 3;
			spriteEnnemi.setTextureRect(sf::IntRect((((12 - 3 * niveau) - nombreSprite)+3)*dimensionL, dimensionH, dimensionL, dimensionH));
			if (clockAnimation.getElapsedTime().asMilliseconds() >= (1 / (float)vitesse) * 500) {
				nombreSprite--;
				clockAnimation.restart();
			}
			
		}
		
	}

	
}
void Ennemi::setVie(int degat) {

}
sf::Sprite * Ennemi::getSpriteEnnemi() {
	return &spriteEnnemi;
}