#include "Enemy.h"
//======= Constructor & Destructor =======
Enemy::Enemy()
{
	initVariables();
	initShape();
}

Enemy::Enemy(float posX, float posY)
{
	initVariables();
	initShape();
	shape.setPosition(posX,posY);

}

Enemy::~Enemy()
{
}
//======= Sets & Gets =======
sf::FloatRect Enemy::getGlobalBounds() { return shape.getGlobalBounds(); }

int Enemy::getHp(){	return 0;}

int Enemy::getHpMax(){	return 0;}

int Enemy::getDamege(){	return 0;}

int Enemy::getPoint(){	return 0;}

void Enemy::setHp(int h) {	this->hp = h; }

void Enemy::setHpMax(int hm) { this->hpMax = hp; }

void Enemy::setDamege(int d) { this->damage = d; }

void Enemy::setPoint(int p){	this->point=p;}

//======= FUNCIONES =======
void Enemy::update(){
	shape.move(0.f,speed);
}

void Enemy::draw(sf::RenderTarget* target) { target->draw(shape); }

//======= FUNCIONES AUX =======
//======= INIT =======
 void Enemy::initVariables()
{
	 speed = 5.f;
	 dirY = 0.0f;
	 dirX = 0.0f;

	 hpMax = 10;
	 hp = hpMax;
	 type = 0;
	 damage = (type+1);
	 point = type * 10;
}
void Enemy::initShape()
{
	shape.setRadius(rand()%20+20);
	shape.setPointCount(rand()%20+3);
	shape.setFillColor(sf::Color (rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255)); //RED , GREEN , BLUE , TRANSPARENCIA COLOR
}
//======= UPDATE <KeyBoard Press> =======
//======= UPDATE <Spawn> <update> =======
//======= UPDATE <Collision> ======= 
//======= DRAW =======
