#include "Arme.h"
Arme::Arme() {
	munitions = 32;
	nom = "pistolet";
	type = classe{ léger };
	distance = 1;
	degat = 10;
	std::cout << "Apparition arme" << std::endl;
}

void Arme::tirer(float PosXJoueur,float PosYJoueur, sf::RenderWindow * window,int direction) {
	VitesseArme++;
	if (VitesseArme > vitesseArmeMax) {
		if (munitions > 0) {
			Balles * balle = new Balles(PosXJoueur, PosYJoueur, direction, window);
			tableauBalles.push_back(balle);
			munitions--;
			std::cout << "Tableau de balles : " << tableauBalles.size() << std::endl;
			std::cout << "Feu" << std::endl;
		}
		VitesseArme=0;
	}
	VitesseArme++;
	
}
int Arme::getVitesseArme() {
	return VitesseArme;
}
void Arme::recharger() {
	munitions = 32;
}
std::vector <Balles*>   *Arme::getTableauBalles() {
	return &tableauBalles;
}
void Arme::setDirectionBalle(short int direction) {
}