#include "Arme.h"
Arme::Arme() {
	munitions = 32;
	nom = "pistolet";
	type = classe{ l�ger };
	distance = 1;
	degat = 25;
	std::cout << "Apparition arme" << std::endl;
}

void Arme::tirer(float PosXJoueur,float PosYJoueur, sf::RenderWindow * window,int direction) {
	if (timerTir.getElapsedTime().asMilliseconds() > 200)
	{
		if (munitions > 0) {
			Balles * balle = new Balles(PosXJoueur, PosYJoueur, direction, window);
			tableauBalles.push_back(balle);
			munitions--;
			timerTir.restart();
		}
	}
	
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