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
	this->initEnemy();
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
	for (auto* e : this->enemies)
	{
		delete e;
	}
}
//======= Sets & Gets =======
bool Game::getEndGame() const{	return this->endGame;}
//======= FUNCIONES =======
void Game::update()
{
	this->updateEvent();
	this->updateInputKey();
	if (!this->getEndGame()) {//Update
		this->updateTextScore();
		this->updatePlayer();
		this->updateBullets();
		this->updateEnemy();
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
	for (auto* e : enemies)
	{
		e->draw(window);
	}

	//Game Over = drawTextEndGame
	if (this->getEndGame()) {
		this->window->draw(this->textGameOver);
	}	
	this->window->display();
}
//======= FUNCIONES AUX =======
bool Game::running(){	return this->window->isOpen();}


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
void Game::initPlayer(){	this->player = new Player();}
void Game::initEnemy()
{
	spawTimeMax = 50.f;
	spawTime = spawTimeMax;
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

void Game::updateInputKey()
{
	//Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	//Bullets
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->canAttack())
		this->bullets.push_back(new Bullet(this->textures["BULLETS"],
			this->player->getPos().x + player->getGlobalBounds().width / 2.f,
			this->player->getPos().y - player->getGlobalBounds().height / 2,
			0.f, -1.f, 2.5f));

}



void Game::updatePlayer(){	this->player->update();}

void Game::updateBullets()
{
	int cont = 0;
	for (auto* b : bullets)
	{
		b->update();
		//Chequeo Top 
		if (b->getBounds().top + b->getBounds().height <= 0.f) {
			delete bullets.at(cont);// Se libera la memoria de la bala eliminada.
			bullets.erase(bullets.begin() + cont);//Se elimina la bala del contenedor.
			cont--;
			std::cout << "Contador de Bullets " << bullets.size() << "\n";
		}
		cont++;
	}
	
}

void Game::updateEnemy()
{
	spawTime += 1.f;
	if (spawTime > spawTimeMax) {
		spawTime = 0;
		enemies.push_back(new Enemy(rand()%(window->getSize().x-80)+50,-100.f));
	}
	int cont = 0;
	for (auto* e : enemies)
	{
		e->update();
		std::cout << "CONTADOR DE ENEMY:" << enemies.size()<<"\n";
		if (e->getGlobalBounds().top > window->getSize().y) {
			delete enemies.at(cont);
			enemies.erase(enemies.begin() + cont);
			cont--;
		}
		cont++;
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






