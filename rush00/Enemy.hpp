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
	public:
		Enemy();
		~Enemy();
		Enemy(const Enemy &src);
		Enemy &operator=(const Enemy &rhs);
		void talk(WINDOW *win);
};

#endif