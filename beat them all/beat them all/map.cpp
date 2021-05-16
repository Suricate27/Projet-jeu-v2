#include "Map.h"
void Map::creationBoiteSecours(float positionX, float positionY) {
	sf::CircleShape *cercle = new sf::CircleShape(50);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	TabBoiteSecours.push_back(cercle);
}
Map::Map() {
	if (!textureBack.loadFromFile("Textures/Back.png")) // v�rif ouverture fichier
	{
		std::cout << "Erreur chargement texture back" << std::endl;
	}
	textureBack.setSmooth(true);
	spriteBack.setTexture(textureBack);
	spriteBack.setTextureRect(sf::IntRect(dimension_back_H, dimension_back_L, dimension_back_L, dimension_back_H)); 
	spriteBack.setPosition(0, 0); 
}
std::vector<sf::CircleShape*> * Map::getObjets() {
	return &objets;
}
void Map::creationCercle(float positionX, float positionY) { //cr�e les cercles
	sf::CircleShape *cercle = new sf::CircleShape(100);
}
std::vector<sf::CircleShape*> * Map::getTabBoiteSecours() {
	return &TabBoiteSecours;
}
sf::Sprite *Map::getSpriteBack() {
	return  &spriteBack;
}
void Map::affichageBarreVie(int centreVue,int vieJoueur, float fatigueJoueur) {
	if (tabBarreVie.size() > 3) {
		tabBarreVie.clear();
	}
	BarreVieBordure->setSize(sf::Vector2f(200+10, (largeurEcran / 40)+35));
	BarreVieBordure->setFillColor(sf::Color::Red);
	BarreVieBordure->setPosition(centreVue-BarreVieBordure->getSize().x/2, 20);
	tabBarreVie.push_back(BarreVieBordure);
	BarreVie->setSize(sf::Vector2f(vieJoueur * 2, largeurEcran / 40));
	BarreVie->setFillColor(sf::Color::Green);
	BarreVie->setPosition(BarreVieBordure->getPosition().x+5 , BarreVieBordure->getPosition().y+5 );
	tabBarreVie.push_back(BarreVie);
	BarreFatigue->setSize(sf::Vector2f(float(fatigueJoueur * 200), largeurEcran / 40));
	BarreFatigue->setFillColor(sf::Color::Yellow);
	BarreFatigue->setPosition(BarreVieBordure->getPosition().x +5, BarreVieBordure->getPosition().y + (largeurEcran / 40)+5);
	tabBarreVie.push_back(BarreFatigue);
}
std::vector<sf::RectangleShape*> * Map::getTabBarreVie(){
	return &tabBarreVie;
}
void Map::afficherTexte(sf::Vector2f PositionBarreVie) {
  	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Erreur chargement Police : arial.ttf introuvable" << std::endl;
	}
	text->setString(std::string("Vie : "));
	width = text->getLocalBounds().width;
	text->setFont(font);
	text->setCharacterSize(largeurEcran/50);
	text->setPosition(PositionBarreVie.x-width, PositionBarreVie.y);
}
void Map::affichageTextMunitions(int munitions, sf::Vector2f PositionBarreVie) {
	textmun->setString(std::string("Munitions : ") + std::to_string(munitions));
	textmun->setFont(font);
	textmun->setCharacterSize(largeurEcran / 50);
	textmun->setPosition(PositionBarreVie.x - 350, 20);
}
sf::Vector2f Map::getPositionBarreVie() {
	return BarreVieBordure->getPosition();
}

void Map::affichage(sf::RenderWindow * window) {
	window->draw(*textmun);
	window->draw(*text);
}