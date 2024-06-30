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

sf::Vector2f Player::getPos()
{
	return sprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds()
{
	return sprite.getGlobalBounds();
}

//======= FUNCIONES =======
void Player::update()
{
	updateAttackCool();
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
 bool Player::canAttack()
 {
	 return attackCool>=attackCoolMax;
 }
//======= INIT =======
void Player::initVariables()
{
	this->speed = 8.f;

	this->attackCoolMax = 10.f;
	this->attackCool = attackCoolMax;

	this->hp = 0;
	this->hp = this->maxHp;
}
void Player::initSprite()
{
	if (!this->texture.loadFromFile("./img/player.png"))
		std::cout << "ERROR::PLAYER::INITSPRITE";
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(.5f,0.5f);
}
//======= UPDATE <KeyBoard Press> =======
//======= UPDATE <Spawn> <update> =======
void Player::updateAttackCool()
{
	if (attackCool < attackCoolMax)
		attackCool += 2.f;
	else
		attackCool = 0.f;
}
//======= UPDATE <Collision> ======= 
//======= DRAW =======


