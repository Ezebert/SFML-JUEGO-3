#include "Game.h"
#include <iostream>
#include <sstream>

//======= Constructor & Destructor =======
Game::Game()
{
	this->initVariables();
	this->initWindows();
	this->initFont();
	this->initTextPoint();
	this->initTextEndGame();
}

Game::~Game()
{
	delete this->window;
}
//======= Sets & Gets =======
bool Game::getEndGame() const{	return this->endGame;}
//======= FUNCIONES =======
void Game::update()
{
	this->updateEvent();
	if (!this->getEndGame()) {//Update
		this->updateTextScore();
		this->updatePlayer();
	}

}

void Game::draw()
{ // Clear - Draw - Display
	this->window->clear();
	//Draw
	this->drawTextPoint(*this->window);
	this->player.draw(*this->window);
	//Game Over = drawTextEndGame
	if (this->getEndGame()) {
		this->window->draw(this->textGameOver);
	}	
	this->window->display();
}
//======= FUNCIONES AUX =======
bool Game::running()
{
	return this->window->isOpen();
}


//======= INIT =======
void Game::initVariables()
{
	this->endGame = false;
	this->score = 0;
}

void Game::initWindows()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window =  new sf::RenderWindow(this->videoMode,"JUEGO #3 - SFML",sf::Style::Close||sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}
void Game::initFont()
{
	if (!this->font.loadFromFile("./font/SPACE.ttf")) {
		std::cout << " ERROR::GAME::InitFont";
	}
}

void Game::initTextPoint()
{
	this->textScore.setFont(this->font);
	this->textScore.setCharacterSize(15);
	this->textScore.setFillColor(sf::Color::White);
	this->textScore.setString("n/n");
}

void Game::initTextEndGame()
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
void Game::updatePlayer()
{
	this->player.update();
}

void Game::updateTextScore()
{
	std::stringstream ss;
	ss << "Score: " << this->score;
	this->textScore.setString(ss.str());

}
//======= UPDATE <Collision> ======= 
void Game::updateCollision()
{
}

//======= DRAW =======
void Game::drawTextPoint(sf::RenderTarget& target)
{
	target.draw(this->textScore);
}






