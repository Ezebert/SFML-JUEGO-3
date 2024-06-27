#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//#Include Cls
#include "Player.h"
class Game
{
private:
	//Variables
	bool endGame;
	int score;
	//Game Clases
	Player *player;
	//Windows
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
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
	//Update Secundario
	void updatePlayer();
	void updateTextScore();
	//	<Collision>
	void updateCollision();
	//	<KeyBoard Press>
	void updateEvent();
	void updateEventPlayer();
	//Draw
	void drawTextPoint(sf::RenderTarget& target);
};
