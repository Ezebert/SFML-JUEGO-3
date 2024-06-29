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

	float attackCool;
	float attackCoolMax;
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
	sf::Vector2f getPos();
	sf::FloatRect getGlobalBounds();
	
	//Funciones
	void update();
	void draw(sf::RenderTarget &target);
	//Funciones AAux
	void move(float dirX,float dirY);
	bool canAttack();
protected:
	//Init
	void initVariables();
	void initSprite();
	//Update Secundario
	void updateAttackCool();
	//Draw Secundario
};