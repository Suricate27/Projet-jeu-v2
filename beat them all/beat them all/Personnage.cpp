#include "Personnage.h"
#include <math.h>


Personnage::Personnage(int vie, int dégat, std::string nom){
	this->vie = vie;
	this->dégat = dégat;
	this->nom = nom;
	vitesseDeplacement = vitesseDeplacementinit;
	arme = new Arme();
	animation = sf::Vector2i(1, haut);
	// chargement de la texture
	if (!texturePerso.loadFromFile("Textures/sprites2.png")) // vérif ouverture fichier
	{
		std::cout << "Erreur chargement texture" << std::endl;
	}
	texturePerso.setSmooth(true);
	spritePerso.setTexture(texturePerso);
	spritePerso.setTextureRect(sf::IntRect(dimensionL, 3 * dimensionH, dimensionL, dimensionH)); // Pour que le premier affichage du personnage soit vers la droite
	spritePerso.setPosition(0, longueurEcran - dimensionH); //démarre en bas de la fenêtre 
}
Personnage::~Personnage() {
	delete arme;
}
void Personnage::deplacement(sf::Time duréeitération, std::vector<Crate*>*tabCrate) { // gère les animations de déplacement et les déplacement 
	
	if (clockAnimation.getElapsedTime().asMilliseconds() >= (1/(float)vitesseDeplacement)*50000) // pour que la vitesse des animations soit liée à la vitesse du personnage j'ai définis 0.2 (1/5) parce que je trouvais ça ok
	{
		animation.x++; //passer a l'annimation suivante pour le x et garder la même pour y	
		clockAnimation.restart();
	}
	if (updateFPS) { // Si l'utilisateur à une touche enfoncée on vas jouer les animation en boucle
		if (animation.x * dimensionL >= nombreSprite * dimensionL)animation.x = 0; // il n'y en a que 9
		spritePerso.setTextureRect(sf::IntRect(animation.x * dimensionL, animation.y * dimensionH, dimensionL, dimensionH)); //x et y c'est parce qu'on va utiliser les sprites comme un tableau
		updateFPS = false; //repasse à faux à chaque boucle comme ça il n'est vrai que si une touche est enfoncée.
	}
		// il va constament tester ( 100 fois par seconde ) s'il doit bouger. Si les variables sont vraies alors il va bouger
		// Donc on va calculer le déplacement avec temps passé avec la touche enfoncée.
	for (Crate * crate : *tabCrate) {
		if (std::abs(crate->getSpriteCrate()->getPosition().x + float(crate->getDimension() / 2) - (spritePerso.getPosition().x + float(dimensionL / 2))) < float(0.8*dimensionL) && std::abs(crate->getSpriteCrate()->getPosition().y + float(crate->getDimension() / 2) - (spritePerso.getPosition().y + float(dimensionH / 2))) < float(0.8*dimensionH)) {
			if (crate->getSpriteCrate()->getPosition().x > spritePerso.getPosition().x) {
				moveRight = 0;
			}
			if (spritePerso.getPosition().x > crate->getSpriteCrate()->getPosition().x) {
				moveLeft = 0;
			}
			if (spritePerso.getPosition().y > crate->getSpriteCrate()->getPosition().y) {
				moveUp = 0;
			}
			if (spritePerso.getPosition().y < crate->getSpriteCrate()->getPosition().y) {
				moveDown = 0;
			}
		}
	}
	if (moveUp) {
		if (spritePerso.getPosition().y >= 0.66 * longueurEcran-dimensionH) { //empecher de monter plus haut que 2/3 de l'écran
			spritePerso.move(0, -vitesseDeplacement*duréeitération.asSeconds());
		}
		animation.y = haut;
		updateFPS = true;
	}
	if (moveDown) {
		if (spritePerso.getPosition().y <= longueurEcran - dimensionH) {//empecher la sortie de fenêtre
			spritePerso.move(0,  vitesseDeplacement*duréeitération.asSeconds());
		}
		animation.y = bas;
		updateFPS = true;
	}
	if (moveLeft)
	{
		if (spritePerso.getPosition().x >= 0) {
			spritePerso.move( -vitesseDeplacement * duréeitération.asSeconds(), 0);
		}
		animation.y = gauche;
		updateFPS = true;
	}
	 if (moveRight) {
		if (spritePerso.getPosition().x <= 12510) {// Fin du niveau en 15000
			spritePerso.move( vitesseDeplacement*duréeitération.asSeconds(), 0);
		}
		animation.y = droite;
		updateFPS = true;
	}
	if (tirer) {
		if (clockfatigue.getElapsedTime().asMilliseconds() > 200)
		{
			if (regenerationFatigue == false) {
				if (arme->getMunitions() > 0) {
					arme->tirer(spritePerso.getPosition().x, spritePerso.getPosition().y, direction, dimensionH, dimensionL);
					setFatigue();
					vitesseDeplacement = vitesseDeplacementinit * fatigue;
					if (vitesseDeplacement < 1)vitesseDeplacement = 1;
					clock.restart();
				}
				
			}
			
		}
		
		
	}

}
void Personnage::deplacementBalle(sf::Time duréeitération, sf::RenderWindow * window) {
	int i = -1;
	for (Balles * balle : *arme->getTableauBalles()) { // dessiner les cercles
		balle->avancer(duréeitération, window);
		i++;
		if (balle->getDureeVie().asMilliseconds() >= balle->getDureeVieMax().asMilliseconds()) {
			delete balle;
			arme->getTableauBalles()->erase(arme->getTableauBalles()->begin() + i);
		}	
	}
}
int Personnage::getDimensionH() {
	return dimensionH;
}
int Personnage::getDimensionL() {
	return dimensionL;
}
void Personnage::update(sf::Event event) { // gestion des variables bool a true si une touche est enfoncée
	switch (event.type) {
	case sf::Event::KeyPressed: // passe les variables bool à 1 si la touche est enfoncée
		switch (event.key.code)
		{
		case sf::Keyboard::Z:
			moveUp = 1;
			break;
		case sf::Keyboard::Q:
			moveLeft = 1;
			direction = -1;
			break;
		case sf::Keyboard::S:
			moveDown = 1;
			break;
		case sf::Keyboard::D:
			moveRight = 1;
			direction = 1;
			break;
		case sf::Keyboard::Space:
			if(arme->getMunitions()>0)regenerationFatigue = false;
			tirer = true;
			break;
		case sf::Keyboard::R:
			arme->recharger();
			break;
		case sf::Keyboard::P:
			cac =1;
			break;
		}
		break;
	case sf::Event::KeyReleased:// passe les variables à zéro si la touche est relachée
		switch (event.key.code)
		{
		case sf::Keyboard::Z:
			moveUp = 0;
			break;
		case sf::Keyboard::Q:
			moveLeft = 0;
			break;
		case sf::Keyboard::S:
			moveDown = 0;
			break;
		case sf::Keyboard::D:
			moveRight = 0;
			break;
		case sf::Keyboard::Space:
			tirer = false;
			regenerationFatigue = true;
			break;
		case sf::Keyboard::P:
			cac = false;
			break;
		}
		break;
	}

}// gestion des variables bool a true si une touche est enfoncée

void Personnage::testingCollision(std::vector<Ennemi*>* tabEnnemi, std::vector<BoiteSecours*>*tabObjRamassé) {
	int i = -1, j=-1,k=-1;
	for (Ennemi * ennemi : *tabEnnemi) {
		j++;
		//gestion collision entre balle et ennemi
		i = -1;
		for (Balles * cercle :  *arme->getTableauBalles()) {
			i++;
			if (std::abs(ennemi->getSpriteEnnemi()->getPosition().x + float(ennemi->getDimensionL() / 2) - (cercle->getPositionX()+ float(cercle->getDiametre() / 2))) < float(0.8*ennemi->getDimensionL()) && std::abs(ennemi->getSpriteEnnemi()->getPosition().y + float(ennemi->getDimensionH() / 2) - (cercle->getPositionY() + float(cercle->getDiametre()/ 2))) < float(0.8*ennemi->getDimensionH())) {
				ennemi->recevoirDegat(arme->getArmeDegat());
				if (ennemi->getVie() <= 0) {
					delete ennemi;
					tabEnnemi->erase(tabEnnemi->begin() + j);
				}
				delete cercle;
				arme->getTableauBalles()->erase(arme->getTableauBalles()->begin() + i);
			}
		}
		//gestion collision entre ennemi et le perso
		if (std::abs(ennemi->getSpriteEnnemi()->getPosition().x + float(ennemi->getDimensionL() / 2) - (spritePerso.getPosition().x + float(dimensionL / 2))) < float(0.8*ennemi->getDimensionL()) && std::abs(ennemi->getSpriteEnnemi()->getPosition().y + float(ennemi->getDimensionH() / 2) - (spritePerso.getPosition().y+ float(dimensionH / 2))) < float(0.8*ennemi->getDimensionH())) {
			
			if (clockVie.getElapsedTime().asMilliseconds() > 200 && vie > 0) {
				vie -= ennemi->getDegat();
				clockVie.restart();
			}	
		}
		if (std::abs(ennemi->getSpriteEnnemi()->getPosition().x + float(ennemi->getDimensionL() / 2) - (spritePerso.getPosition().x + float(dimensionL / 2))) < float(ennemi->getDimensionL()) && std::abs(ennemi->getSpriteEnnemi()->getPosition().y + float(ennemi->getDimensionH() / 2) - (spritePerso.getPosition().y + float(dimensionH / 2))) < float(ennemi->getDimensionH())) {
			if (cac == true && clockcorpacorp.getElapsedTime().asMilliseconds() > 300) {
				ennemi->recevoirDegat(degatCac);
				ennemi->toucheCac(direction);
				clockcorpacorp.restart();
				if (ennemi->getVie() <= 0) {
					delete ennemi;
					tabEnnemi->erase(tabEnnemi->begin() + j);
				}
			}
		}
	}
	//collision entre perso soins
	k = -1;
	for (BoiteSecours * objetramasse : *tabObjRamassé) {
		k++;
		if (std::abs(objetramasse->getsprite()->getPosition().x + float(objetramasse->getDimension() / 2) - (spritePerso.getPosition().x + float(dimensionL / 2))) < float(dimensionL*0.8) && std::abs(objetramasse->getsprite()->getPosition().y + float(objetramasse->getDimension() / 2) - (spritePerso.getPosition().y + float(dimensionH / 2))) < float(0.8*dimensionH)) {
			ramasseBoiteSecours(objetramasse->getCapaciteSoins());
			delete objetramasse;
			tabObjRamassé->erase(tabObjRamassé->begin() + k);
		}
	}
}
sf::Sprite * Personnage::getSpritePerso() {
	return &spritePerso;
}
Arme * Personnage::getArme() {
	return arme;
}
int Personnage::getPositionX() {
	return spritePerso.getPosition().x;
}
int Personnage::getPositionY() {
	return spritePerso.getPosition().y;
}
void Personnage::regenerationVie() {
	if (clock.getElapsedTime().asMilliseconds() > 500 && vie < 100) {
		vie += 1;
		clock.restart();
	}
}
int Personnage::getVie() {
	return vie;
}
void Personnage::ramasseBoiteSecours(int pvboite) {
	if (vie < 100) {
		vie += pvboite;
		if (vie > 100)vie = 100;
	}
}
float Personnage::getFatigue() {
	return fatigue;
}
void Personnage::setFatigue() {
	if (fatigue > 0) {
		fatigue -= 0.002;
	}
}
void Personnage::regenFatigue() {
	if (arme->getMunitions() <= 0) {
		regenerationFatigue = true;
	}
	if (regenerationFatigue == true) {
		if (clockfatigue.getElapsedTime().asMilliseconds() > 200) {
			if (fatigue < 1) {
				fatigue += 0.02;
				vitesseDeplacement = 400 * fatigue;
				if (vitesseDeplacement > 400)vitesseDeplacement = 400;
				clockfatigue.restart();
			}
			if (fatigue > 1) fatigue = 1;
			
		}
	}
	
}
