#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Window.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Game
{
	public:
		int maxEnemies;
		Window window;
		//EntityManager entityManager;
		Player player;
		Enemy *enemies[];
		Game();
		~Game();
		Game(const Game &src);
		Game &operator=(const Game &rhs);
};

#endif