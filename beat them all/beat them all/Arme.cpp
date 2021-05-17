#include "Arme.h"
Arme::Arme() {
	nom = "pistolet";
}
void Arme::tirer(float PosXJoueur,float PosYJoueur,int direction, int taillePersoH,int taillePersoL) {
	if (timerTir.getElapsedTime().asMilliseconds() > 200)
	{
		if (munitions > 0) {
			Balles * balle = new Balles(PosXJoueur, PosYJoueur, direction, taillePersoH,taillePersoL);
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
	munitions = capaciteChargeur;
}
std::vector <Balles*>   *Arme::getTableauBalles() {
	return &tableauBalles;
}
int Arme::getArmeDegat() {
	return degat;
}