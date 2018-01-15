#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include "GameEntity.hpp"
#include "Window.hpp"

class Enemy : public GameEntity
{
	private:
		int number;
	public:
		int hp;
		bool isVisible;
		Enemy();
		~Enemy();
		Enemy(const Enemy &src);
		Enemy &operator=(const Enemy &rhs);
		void talk(WINDOW *win);
		void setNumber(int num);
		void moveEnemy();
		bool takeHit();
};

#endif