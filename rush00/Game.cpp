#include "Game.hpp"

Game::Game() : maxEnemies(20) 
{
	std::srand(std::time(0));
	this->window = new Window();
	this->enemies = new Enemy[this->maxEnemies];
	for (int i = 0; i < this->maxEnemies; i++)
		this->enemies[i].setNumber(i+1);
	
	usleep(500000);
}
Game::~Game() { this->window->cleanup(); }

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
	if (rand() % 2 == 0)
	{
		int spawnLoc = rand() % this->window->windowHeight;
		spawnLoc = rand();
	}
}

Enemy *Game::getNextEnemy()
{
	Enemy *next = NULL;
	for (int i = 0; i < maxEnemies; i++)
	{
		if (this->enemies[i].isVisible == false)
		{
			next = &this->enemies[i];
			return next;
		}
	}
	return next;
}
