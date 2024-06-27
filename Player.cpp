#include "Player.h"
#include <iostream>
//======= Constructor & Destructor =======
Player::Player()
{
	this->initVariables();
	this->initSprite();

}
Player::~Player()
{
}
//======= Sets & Gets =======
void Player::setHp(int hp) { this->hp = hp; }
void Player::setMaxHP(int maxHp) { this->maxHp = maxHp; }
int Player::getHp(){	return this->hp;}
int Player::getMaxHp(){	return this->maxHp;}
//======= FUNCIONES =======
void Player::update()
{
}
void Player::draw(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

//======= FUNCIONES AUX =======
 void Player::move(float dirX, float dirY)
{
	 this->sprite.move(this->speed*dirX,this->speed*dirY);
}
//======= INIT =======
void Player::initVariables()
{
	this->speed = 8.f;
	this->hp = 0;
	this->hp = this->maxHp;
}
void Player::initSprite()
{
	if (!this->texture.loadFromFile("./img/enemy2.png"))
		std::cout << "ERROR::PLAYER::INITSPRITE";
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(.5f,0.5f);
}
//======= UPDATE <KeyBoard Press> =======
//======= UPDATE <Spawn> <update> =======
//======= UPDATE <Collision> ======= 
//======= DRAW =======


