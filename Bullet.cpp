#include "Bullet.h"
#include <iostream>
//======= Constructor & Destructor =======
Bullet::Bullet()
{
	this->initVariables();
	this->initSprite();
	 
}

Bullet::Bullet(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float _speed)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(posX,posY);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->speed = _speed;

}


Bullet::~Bullet()
{
}
//======= Sets & Gets ======= 
//======= FUNCIONES =======
void Bullet::update()
{
	this->sprite.move(this->speed*this->direction);
}
 
void Bullet::draw(sf::RenderTarget *target)
{
	target->draw(this->sprite);
}
//======= FUNCIONES AUX =======
//======= INIT =======
void Bullet::initVariables()
{
	this->direction.x = 0.f;
	this->direction.y = 0.f;
	this->speed = 1.f;
}

void Bullet::initSprite()
{
}
//======= UPDATE <KeyBoard Press> =======
//======= UPDATE <Spawn> <update> =======
//======= UPDATE <Collision> ======= 
//======= DRAW =======