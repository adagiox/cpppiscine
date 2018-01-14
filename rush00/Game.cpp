#include "Game.hpp"

Game::Game() : maxEnemies(20) 
{
	for (int i = 0; i < this->maxEnemies; i++)
		this->enemies[i] = new Enemy();
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

