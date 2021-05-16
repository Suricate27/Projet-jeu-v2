#include "Map.h"
void Map::creationBoiteSecours(float positionX, float positionY) {
	sf::CircleShape *cercle = new sf::CircleShape(50);
	cercle->setFillColor(sf::Color::Green);
	cercle->setPosition(positionX, positionY);
	TabBoiteSecours.push_back(cercle);
}
std::vector<sf::CircleShape*> * Map::getTabBoiteSecours() {
	return &TabBoiteSecours;
}
void Map::affichageBarreVie(int centreVue,int vieJoueur) {

	BarreVieBordure->setSize(sf::Vector2f(410, 60));
	BarreVieBordure->setFillColor(sf::Color::Red);
	BarreVieBordure->setPosition(centreVue-BarreVieBordure->getSize().x/2, 20);
	tabBarreVie.push_back(BarreVieBordure);
	BarreVie->setSize(sf::Vector2f(vieJoueur * 4, 50));
	BarreVie->setFillColor(sf::Color::Green);
	BarreVie->setPosition(BarreVieBordure->getPosition().x + 5, BarreVieBordure->getPosition().y + 5);
	tabBarreVie.push_back(BarreVie);
}
std::vector<sf::RectangleShape*> * Map::getTabBarreVie(){
	return &tabBarreVie;
}
void Map::afficherTexte(sf::Vector2f PositionBarreVie) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Erreur chargement Police : arial.ttf introuvable" << std::endl;
	}	
	text.setString(std::string("Vie : "));
	width = text.getLocalBounds().width;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(PositionBarreVie.x-width, PositionBarreVie.y);
	tabText.push_back(&text);
}
std::vector<sf::Text*> * Map::getTabTexte() {
	return &tabText;
}

sf::Vector2f Map::getPositionBarreVie() {
	return BarreVieBordure->getPosition();
}