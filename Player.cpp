#include "Player.h"
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
//======= INIT =======
void Player::initVariables()
{
	this->hp = 0;
	this->hp = this->maxHp;
}
void Player::initSprite()
{
	this->texture.loadFromFile("./img/player.png");
	this->sprite.setTexture(this->texture);
}
//======= UPDATE <KeyBoard Press> =======
//======= UPDATE <Spawn> <update> =======
//======= UPDATE <Collision> ======= 
//======= DRAW =======


