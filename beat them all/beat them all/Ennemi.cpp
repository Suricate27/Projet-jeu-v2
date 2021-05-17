#include "Ennemi.h"
Ennemi::Ennemi(int niveau) {
	vie = 100 * niveau;
	degat = 5 * niveau;
	this->niveau = niveau;
	vitesse = (niveau + 2) / 3; //vitesse par niveau (1|1.33|1.66|2)
	animation = sf::Vector2i((13 - 3 * niveau), haut);
	// chargement de la texture
	if (!textureEnnemi.loadFromFile("Textures/SpriteEnnemi.png")) // v�rif ouverture fichier
	{
		std::cout << "Erreur chargement texture ennemi" << std::endl;
	}
	textureEnnemi.setSmooth(true);
	spriteEnnemi.setTexture(textureEnnemi);
	spriteEnnemi.setTextureRect(sf::IntRect((13 - 3 * niveau)*dimensionL, dimensionH, dimensionL, dimensionH)); // Pour que le premier affichage du personnage soit vers la droite
	std::cout << "Pop !" << std::endl;
	spriteEnnemi.setPosition((rand() % 700) + 300, (rand() % 200) + 300 - dimensionH);//somme des 2 doit faire le chiffre max
}
Ennemi::Ennemi(int niveau, int positionXPersonnage) {
	vie = 100*niveau;
	degat = 5*niveau;
	this->niveau = niveau;
	vitesse = (niveau+2)/3; //vitesse par niveau (1|1.33|1.66|2)
	animation = sf::Vector2i((13 - 3 * niveau), haut);
	// chargement de la texture
	if (!textureEnnemi.loadFromFile("Textures/SpriteEnnemi.png")) // v�rif ouverture fichier
	{
		std::cout << "Erreur chargement texture ennemi" << std::endl;
	}
	textureEnnemi.setSmooth(true);
	spriteEnnemi.setTexture(textureEnnemi);
	spriteEnnemi.setTextureRect(sf::IntRect((13 - 3 * niveau)*dimensionL, dimensionH, dimensionL, dimensionH)); // Pour que le premier affichage du personnage soit vers la droite
	std::cout << "Pop !" << std::endl;
	spriteEnnemi.setPosition((rand()%700)+300+positionXPersonnage,(rand()%200)+300-dimensionH);//somme des 2 doit faire le chiffre max
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
	if (abs(positionPersonnageX - spriteEnnemi.getPosition().x) > 50) {
		if (positionPersonnageX > spriteEnnemi.getPosition().x) {
			spriteEnnemi.move(vitesse, 0);
			if (nombreSprite == 0)nombreSprite = 3;
			spriteEnnemi.setTextureRect(sf::IntRect((((12 - 3 * niveau)-nombreSprite)+3)*dimensionL, 2 * dimensionH, dimensionL, dimensionH));
			if (clockAnimation.getElapsedTime().asMilliseconds() >= (1 / (float)vitesse) * 400)
			{
				nombreSprite--;
				clockAnimation.restart();
			}
		}
		else {
			spriteEnnemi.move(-vitesse, 0);
			if (nombreSprite == 0)nombreSprite = 3;
			spriteEnnemi.setTextureRect(sf::IntRect((((12 - 3 * niveau) - nombreSprite)+3)*dimensionL, dimensionH, dimensionL, dimensionH));
			if (clockAnimation.getElapsedTime().asMilliseconds() >= (1 / (float)vitesse) * 400) {
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
int Ennemi::getDimensionH() {
	return dimensionH;
}
int Ennemi::getDimensionL() {
	return dimensionL;
}
void Ennemi::toucheCac() {
	spriteEnnemi.move(40, 0);
}
void Ennemi::apparition(int niveau) {
	Ennemi * mechant = new Ennemi(niveau);
	tabEnnemis.push_back(mechant);
}
void Ennemi::apparition(int niveau,int positionXperonnage) {
	Ennemi * mechant = new Ennemi(niveau,positionXperonnage);
	tabEnnemis.push_back(mechant);
}
std::vector <Ennemi*>*Ennemi::getTabEnnemi() {
	return &tabEnnemis;
}