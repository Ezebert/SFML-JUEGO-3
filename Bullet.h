#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class Bullet
{
private:
	//Variables
	float speed;

	//Windows
	sf::Sprite sprite;
	sf::Texture *texture;
	sf::Vector2f direction;
	//Mouse Posicion

	//Resources

	//Text

public:
	//Constructor & Destructor
	Bullet();
	Bullet(sf::Texture* texture,float posX,float posY, float dirX, float dirY, float _speed);
	virtual ~Bullet();
	//Sets & Gets
	sf::FloatRect getBounds() const;
	//Funciones
	void update();
	void draw(sf::RenderTarget* target);
	//Accesorios

protected:
	//Init
	void initVariables();
	void initSprite();
	//Update Secundario
	//Draw Secundario

};

