#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Window.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

class Game
{
	public:
		int maxEnemies;
		int maxBullets;
		Window *window;
		Player *player;
		Enemy *enemies;
		Bullet *bullets;
		Game();
		~Game();
		Game(const Game &src);
		Game &operator=(const Game &rhs);
		void spawnEnemy();
		Enemy *getNextEnemy();
		Bullet *getNextBullet();
		void getInput();
		void processEvents();
		void refreshScreen();
		void moveUp();
		void moveDown();
		void shoot();
};

#endif