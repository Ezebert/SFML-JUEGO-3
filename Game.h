#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//#Include Cls
#include "Player.h"
#include "Bullet.h"
class Game
{
private:
	//Variables
	bool endGame;
	int score;
	//resaourse
	std::map < std::string, sf::Texture* > textures;
	//Game Clases
	Player *player;
	std::vector<Bullet*> bullets;
	
	//Windows
	sf::RenderWindow* window;
	sf::VideoMode videoMode;

	//Mouse Posicion 

	//Resources

	//Text
	sf::Font font;
	sf::Text textScore;
	sf::Text textGameOver;

public:
	//Constructor & Destructor
	Game();
	virtual ~Game();
	//Sets & Gets
	bool getEndGame() const;						
	//Funciones
	void update();
	void draw();
	//Funciones Aux				
	bool running();
					
protected:
	//Init
	void initVariables();
	void initWindows();
	void initPlayer();
	void initFont();
	void initTextPoint();
	void initTextEndGame();
	void initTexture();
	//Update Secundario
	void updatePlayer();
	void updateBullets();
	void updateTextScore();
	//	<Collision>
	void updateCollision();
	//	<KeyBoard Press>
	void updateEvent();
	void updateInputPlayer();
	void updateInputBullet();
	//Draw
	void drawTextPoint(sf::RenderTarget& target);
};
