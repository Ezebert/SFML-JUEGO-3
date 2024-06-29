#include "Game.h"
#include <iostream>
#include <sstream>

//======= Constructor & Destructor =======
Game::Game()
{
	this->initVariables();
	this->initWindows();
	this->initTexture();
	this->initPlayer();

	this->initFont();
	this->initTextPoint();
	this->initTextEndGame();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	for (auto& t : this->textures) 
	{
		delete t.second; //Elimina l textura del map <String , *texture >
	}
	for (auto* b : this->bullets)
	{
		delete b; 
	}
}
//======= Sets & Gets =======
bool Game::getEndGame() const{	return this->endGame;}
//======= FUNCIONES =======
void Game::update()
{
	this->updateEvent();
	this->updateInputPlayer();
	this->updateInputBullet();
	if (!this->getEndGame()) {//Update
		this->updateTextScore();
		this->updatePlayer();
		this->updateBullets();
	}
}

void Game::draw()
{ // Clear - Draw - Display
	this->window->clear();
	//Draw
	this->drawTextPoint(*this->window);
	this->player->draw(*this->window);
	for (auto* b : this->bullets)
	{
		b->draw(window);
	}

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
void Game::initPlayer()
{
	this->player = new Player();
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
void Game::initTexture()
{
	this->textures["BULLETS"] = new sf::Texture();//vacio
	this->textures["BULLETS"]->loadFromFile("./img/bullet.png");
}
//======= UPDATE <KeyBoard Press> =======

void Game::updateEvent()
{
	sf::Event event;
	 while (this->window->pollEvent(event)) {
		 switch (event.type)
		 {
		 case sf::Event::Closed:
			 this->window->close();
			 break;
		 case sf::Event::KeyPressed:
			 if (event.key.code == sf::Keyboard::Escape) {
				 std::cout << "Event Key Code = ESCAPE \n";
				 this->window->close();
			 }
			 break;
		 }
	 }
	
}

void Game::updateInputPlayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);

}
void Game::updateInputBullet()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		this->bullets.push_back(new Bullet(this->textures["BULLETS"],
			this->player->getPos().x + player->getGlobalBounds().width / 2,
			this->player->getPos().y - player->getGlobalBounds().height/2, 
			0.f,-1.f, 0.5f));
}



void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateBullets()
{
	for (auto* b : bullets)
	{
		b->update();
	}
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






