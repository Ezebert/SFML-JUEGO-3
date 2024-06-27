#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#pragma once
class Player{
private:
	//Variables
	float speed;
	int hp;
	int maxHp;
	//Windows
	sf::Sprite sprite;
	sf::Texture texture;
	//Mouse Posicion

	//Resources

	//Text

public:
	//Constructor & Destructor
	Player();
	virtual ~Player();
	//Sets & Gets
	void setHp(int hp);
	void setMaxHP(int maxHp);
	int getHp();
	int getMaxHp();
	//Funciones
	void update();
	void draw(sf::RenderTarget &target);
	//Funciones AAux
	void move(float dirX,float dirY);
protected:
	//Init
	void initVariables();
	void initSprite();
	//Update Secundario

	//Draw Secundario
};