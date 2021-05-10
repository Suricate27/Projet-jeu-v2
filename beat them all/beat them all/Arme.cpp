#include "Arme.h"
Arme::Arme() {
	munitions = 32;
	nom = "pistolet";
	type = classe{ léger };
	distance = 1;
	std::cout << "Apparition arme" << std::endl;
}

void Arme::tirer(float PosXJoueur,float PosYJoueur, sf::RenderWindow * window) {
	if (munitions > 0) {
		
		Balles * balle = new Balles(PosXJoueur,PosYJoueur,window);
		tableauBalles.push_back(balle);
		munitions--;
		std::cout << "Tableau de balles : " << tableauBalles.size()<< std::endl;
		std::cout << "Feu" << std::endl;
	}
}
void Arme::recharger() {
	munitions = 32;
}
std::vector <Balles*>   *Arme::getTableauBalles() {
	return &tableauBalles;
}