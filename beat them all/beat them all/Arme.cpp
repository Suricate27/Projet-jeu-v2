#include "Arme.h"
Arme::Arme() {
	munitions = 32;
	nom = "pistolet";
	type = classe{ léger };
	distance = 1;
}

void Arme::tirer(float PosXJoueur,float PosYJoueur, sf::RenderWindow * window,int direction, int taillePersoH,int taillePersoL) {
	if (timerTir.getElapsedTime().asMilliseconds() > 200)
	{
		if (munitions > 0) {
			Balles * balle = new Balles(PosXJoueur, PosYJoueur, direction, window, taillePersoH,taillePersoL);
			tableauBalles.push_back(balle);
			munitions--;
			timerTir.restart();

		}
	}
	
}
int Arme::getMunitions() {
	return munitions;
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