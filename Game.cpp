#include "Game.h"
#include <iostream>
//======= Constructor & Destructor =======
Game::Game()
{
	this->initVariables();
	this->initWindows();
	this->initFont();
	this->initText();
}

Game::~Game()
{
	delete this->window;
}
//======= Sets & Gets =======
bool Game::getEndGame() const{	return this->endGame;}
//======= FUNCIONES =======
void Game::upDate()
{
	this->updateEvent();
}

void Game::draw()
{
	this->window->clear();
	
	
	//Game Over
	if (this->getEndGame())
		this->window->draw(this->textGameOver);
	this->window->display();
}

bool Game::running()
{
	return this->window->isOpen();
}

//======= FUNCIONES AUX =======

//======= INIT =======
void Game::initVariables()
{
	this->endGame = false;
}

void Game::initWindows()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window =  new sf::RenderWindow(this->videoMode,"JUEGO #3 - SFML",sf::Style::Close||sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}
void Game::initText()
{
}
void Game::initFont()
{
}

//======= UPDATE <KeyBoard Press> =======

void Game::updateEvent()
{
	 while (this->window->pollEvent(this->event)) {
		 switch (this->event.type)
		 {
		 case sf::Event::Closed:
			 this->window->close();
			 break;
		 case sf::Event::KeyPressed:
			 if (this->event.key.code == sf::Keyboard::Escape) {
				 std::cout << "Event Key Code = ESCAPE \n";
				 this->window->close();
			 }
			 break;
		 }
	 }

}
//======= UPDATE <Spawn> <update> =======
//======= UPDATE <Collision> ======= 
//======= DRAW =======






