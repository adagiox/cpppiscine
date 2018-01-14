#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <ncurses.h>
#include "GameEntity.hpp"
#include "Window.hpp"

class Enemy : public GameEntity
{
	private:
		bool isVisible;
		int number;
	public:
		Enemy();
		~Enemy();
		Enemy(const Enemy &src);
		Enemy &operator=(const Enemy &rhs);
		void talk(WINDOW *win);
		void setNumber(int num);
		void moveEnemy();
};

#endif