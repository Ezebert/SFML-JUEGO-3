#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
//#Include Cls
class Game
{
private:
	//Variables
	bool endGame;
	//Game Clases

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
	void upDate();
	void draw();
	bool running();
	//Accesorios				
					
protected:
	//Init
	void initVariables();
	void initWindows();
	void initText();
	void initFont();
	//Update Secundario
	void updateEvent();
	//Draw Secundario
};
