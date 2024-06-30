#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class Enemy{
private:
	//Variables
	float speed, dirY, dirX;
		int hp, hpMax,damage,point,type;
	//Game Clases

	//Windows
		sf::Texture texture;
		sf::Sprite sprite;
		sf::CircleShape shape;
	//Mouse Posicion

	//Resources

	//Text

public:
	//Constructor & Destructor
	Enemy();
	Enemy(float posX, float posY);
	~Enemy();

	//Sets & Gets
	sf::FloatRect getGlobalBounds();
	int getHp();
	int getHpMax();
	int getDamege();
	int getPoint();

	void setHp(int h);
	void setHpMax(int hm);
	void setDamege(int d);
	void setPoint(int p);
	//Funciones
	void update();
	void draw(sf::RenderTarget *target);
	//Accesorios

protected:
	//Init
	void initVariables();
	void initShape();
	//Update Secundario

	//Draw Secundario
};