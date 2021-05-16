#include "Personnage.h"
#include <math.h>


Personnage::Personnage(int vie, int dégat, std::string nom){
	this->vie = vie;
	this->dégat = dégat;
	this->nom = nom;
	arme = new Arme();
	animation = sf::Vector2i(1, haut);
	// chargement de la texture
	if (!texturePerso.loadFromFile("Textures/sprites.png")) // vérif ouverture fichier
	{
		std::cout << "Erreur chargement texture" << std::endl;
	}
	texturePerso.setSmooth(true);
	spritePerso.setTexture(texturePerso);
	spritePerso.setTextureRect(sf::IntRect(dimensionL, 3 * dimensionH, dimensionL, dimensionH)); // Pour que le premier affichage du personnage soit vers la droite
	spritePerso.setPosition(0, longueurEcran - dimensionH); //démarre en bas de la fenêtre 
}

void Personnage::deplacement(sf::Time duréeitération, sf::RenderWindow * window) { // gère les naimation de déplacement et les déplacement 
	
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
	// permet de ralentir le nombre d'affichage d'animation 1 images toute les 100ms

		// il va constament tester ( 100 fois par seconde ) s'il doit bouger. Si les variables sont vraies alors il va bouger
		// Le problème de calculer la vitesse avec des pixels c'est que si la machine ram bah le personnage est lent et ça doit être independant.
		// Donc on va calculer le déplacement avec temps passé avec la touche enfoncée.
	
	if (moveUp) {
		if (spritePerso.getPosition().y >= 0.66 * longueurEcran) { //empecher de monter plus haut que 2/3 de l'écran
			spritePerso.move(0, -vitesseDeplacement*duréeitération.asSeconds());
		}
		animation.y = haut;
		updateFPS = true;
	}
	else if (moveDown) {
		if (spritePerso.getPosition().y <= longueurEcran - dimensionH) {//empecher la sortie de fenêtre
			spritePerso.move(0,  vitesseDeplacement*duréeitération.asSeconds());
		}
		animation.y = bas;
		updateFPS = true;
	}
	else if (moveLeft)
	{
		if (spritePerso.getPosition().x >= 0) {
			spritePerso.move( -vitesseDeplacement * duréeitération.asSeconds(), 0);
		}
		animation.y = gauche;
		updateFPS = true;
	}
	else if (moveRight) {
		if (spritePerso.getPosition().x <= 10000 - dimensionL) {
			spritePerso.move( vitesseDeplacement*duréeitération.asSeconds(), 0);
		}
		animation.y = droite;
		updateFPS = true;
	}
	if (tirer) {
		arme->tirer(spritePerso.getPosition().x, spritePerso.getPosition().y, window, direction);
		
	}

}
void Personnage::deplacementBalle(sf::Time duréeitération, sf::RenderWindow * window) {
	int i = -1;
	for (Balles * balle : *arme->getTableauBalles()) { // dessiner les cercles
		balle->avancer(duréeitération, window);
		i++;
		sf::Time max = sf::milliseconds(4000);
		if (balle->getDureeVie().asMilliseconds() >= max.asMilliseconds()) {
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
			tirer = true;
			break;
		case sf::Keyboard::R:
			arme->recharger();
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
			break;
		}
		break;
	}

}// gestion des variables bool a true si une touche est enfoncée

void Personnage::testingCollision(Arme * arme, Ennemi * ennemi, std::vector<Ennemi*>* tabEnnemi, std::vector<sf::CircleShape*>*tabObjRamassé) {
	int i = -1,j=-1,k=-1;
	for (Ennemi * ennemi : *tabEnnemi) {
		j++;
		//gestion collision entre balle et enemi
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
			
			if (clockVie.getElapsedTime().asMilliseconds() > 100 && vie > 0) {
				vie -= 1;
				clockVie.restart();
			}	
		}
	}
	for (sf::CircleShape * objetramasse : *tabObjRamassé) {
		k++;
		if (std::abs(objetramasse->getPosition().x + float(objetramasse->getRadius() / 2) - (spritePerso.getPosition().x + float(dimensionL / 2))) < float(dimensionL*0.8) && std::abs(objetramasse->getPosition().y + float(objetramasse->getRadius() / 2) - (spritePerso.getPosition().y + float(dimensionH / 2))) < float(0.8*dimensionH)) {
			ramasseBoiteSecours(10);
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
