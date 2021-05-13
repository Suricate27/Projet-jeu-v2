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
	spritePerso.setTextureRect(sf::IntRect(1 * dimension, 3 * dimension, dimension, dimension)); // Pour que le premier affichage du personnage soit vers la droite
	spritePerso.setPosition(0, longueurEcran - dimension); //démarre en bas de la fenêtre 
}

void Personnage::deplacement(sf::Time duréeitération) { // gère les naimation de déplacement et les déplacement 
	
	if (clockAnimation.getElapsedTime().asMilliseconds() >= (1/(float)vitesseDeplacement)*50000) // pour que la vitesse des animations soit liée à la vitesse du personnage j'ai définis 0.2 (1/5) parce que je trouvais ça ok
	{
		animation.x++; //passer a l'annimation suivante pour le x et garder la même pour y	
		clockAnimation.restart();
	}
	if (updateFPS) { // Si l'utilisateur à une touche enfoncée on vas jouer les animation en boucle
		if (animation.x * dimension >= nombreSprite * dimension)animation.x = 0; // il n'y en a que 9
		spritePerso.setTextureRect(sf::IntRect(animation.x * dimension, animation.y * dimension, dimension, dimension)); //x et y c'est parce qu'on va utiliser les sprites comme un tableau
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
		if (spritePerso.getPosition().y <= longueurEcran - dimension) {//empecher la sortie de fenêtre
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
		if (spritePerso.getPosition().x <= 10000 - dimension) {
			spritePerso.move( vitesseDeplacement*duréeitération.asSeconds(), 0);
		}

		animation.y = droite;
		updateFPS = true;
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
int Personnage::getDimension() {
	return dimension;
}
void Personnage::update(sf::Event event, sf::RenderWindow * window) { // gestion des variables bool a true si une touche est enfoncée
	switch (event.type) {
	case sf::Event::KeyPressed: // passe les variables bool à 1 si la touche est enfoncée
		switch (event.key.code)
		{
		case sf::Keyboard::Z:
			moveUp = 1;
			break;
		case sf::Keyboard::Q:
			moveLeft = 1;
			break;
		case sf::Keyboard::S:
			moveDown = 1;
			break;
		case sf::Keyboard::D:
			moveRight = 1;
			break;
		case sf::Keyboard::Space:
			
			arme->tirer(spritePerso.getPosition().x, spritePerso.getPosition().y,window,1);
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
		}
		break;
	}

}// gestion des variables bool a true si une touche est enfoncée

void Personnage::testingCollision(std::vector<Balles* > * objets, Ennemi * ennemi, std::vector<Ennemi*>* tabEnnemi) {
	int i = -1;
	for (Balles * cercle :  *objets) {
		i++;
		if (std::abs(ennemi->getSpriteEnnemi()->getPosition().x+ float( dimension / 2) - (cercle->getPositionX()+ float(dimension / 2))) < float(dimension) && std::abs(ennemi->getSpriteEnnemi()->getPosition().y + float(dimension / 2) - (cercle->getPositionY() + float(dimension / 2))) < float(dimension)) {
			std::cout << "Touche gros fdp" << std::endl;
			delete cercle;
			objets->erase(objets->begin() + i);
			delete ennemi;
			tabEnnemi->erase(tabEnnemi->begin() + i);
		}
	}
}
sf::Sprite * Personnage::getSpritePerso() {
	return &spritePerso;
}
Arme * Personnage::getArme() {
	return arme;
}
