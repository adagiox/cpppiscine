#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Window.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Game
{
	public:
		int maxEnemies;
		Window *window;
		Player *player;
		Enemy *enemies;
		Game();
		~Game();
		Game(const Game &src);
		Game &operator=(const Game &rhs);
		void spawnEnemy();
		Enemy *getNextEnemy();
};

#endif