#include "Map.h"
Map::Map(int maplevel) {
	if (maplevel == 2) {
		if (!textureBack.loadFromFile("Textures/Back2.png")) // v�rif ouverture fichier
		{
			std::cout << "Erreur chargement texture back" << std::endl;
		}
	 }
	else
	{
		if (!textureBack.loadFromFile("Textures/Back.png")) // v�rif ouverture fichier
		{
			std::cout << "Erreur chargement texture back" << std::endl;
		}
	}
	textureBack.setSmooth(true);
	for (int i = 0; i < 21; i++)
	{
		sf::Sprite *spriteBack = new sf::Sprite;
		spriteBack->setTexture(textureBack);
		spriteBack->setTextureRect(sf::IntRect(0, 0, dimension_back_L, dimension_back_H));
		spriteBack->setPosition(i*dimension_back_L, 0);
		tabFond.push_back(spriteBack);

	}
}
void Map::creationBoiteSecours(float positionX, float positionY) {
	BoiteSecours *boite = new BoiteSecours(positionX, positionY);
	TabBoiteSecours.push_back(boite);
}
std::vector<BoiteSecours*> * Map::getTabBoiteSecours() {
	return &TabBoiteSecours;
}
sf::Sprite *Map::getSpriteBack() {
	return  &spriteBack;
}
void Map::affichageBarreVie(int centreVue,int vieJoueur, float fatigueJoueur) {
	if (tabBarreVie.size() > 3) {
		tabBarreVie.clear();
	}
	BarreVieBordure->setSize(sf::Vector2f(200+10, (largeurEcran / 40)+22));
	BarreVieBordure->setFillColor(sf::Color::Red);
	BarreVieBordure->setPosition(centreVue-BarreVieBordure->getSize().x/2, 20);
	tabBarreVie.push_back(BarreVieBordure);
	BarreVie->setSize(sf::Vector2f(vieJoueur * 2, largeurEcran / 40));
	BarreVie->setFillColor(sf::Color::Green);
	BarreVie->setPosition(BarreVieBordure->getPosition().x+5 , BarreVieBordure->getPosition().y+5 );
	tabBarreVie.push_back(BarreVie);
	BarreFatigue->setSize(sf::Vector2f(float(fatigueJoueur * 200), largeurEcran / 80));
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
	window->draw(*textmenu);
}
std::vector <sf::Sprite*>*Map::getTabFond() {
	return &tabFond;
}
void Map::CreationBoite(int positionX, int positionY) {
	Crate *box = new Crate(positionX,positionY);
	tabCrate.push_back(box);
}
std::vector <Crate*>*Map::getTabCrate() {
	return &tabCrate;
}
int Map::getDimensionCrate() {
	Crate box(0,0);
	return box.getDimension();
}
int Map::getDimensionSecours() {
	BoiteSecours box(0, 0);
	return box.getDimension();
}