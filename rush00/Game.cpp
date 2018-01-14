#include "Game.hpp"

Game::Game() : maxEnemies(20) 
{
	this->window = new Window();
	this->enemies = new Enemy[this->maxEnemies];
	for (int i = 0; i < this->maxEnemies; i++)
		this->enemies[i].setNumber(i+1);
	for (int i = 0; i < this->maxEnemies; i++)
		this->enemies[i].talk(this->window->gameWin);
	usleep(5000000);
}
Game::~Game() {}

Game::Game(const Game &src)
{
	this->window = src.window;
	//this->entityManager = src.entityManager;
	this->player = src.player;
	// this->enemies = src.enemies;
}

Game &Game::operator=(const Game &rhs)
{
	if (this != &rhs)
	{
		this->window = rhs.window;
		//this->entityManager = rhs.entityManager;
		this->player = rhs.player;
		// this->enemies = rhs.enemies;
	}
	return *this;
}

void Game::spawnEnemy()
{
	
}