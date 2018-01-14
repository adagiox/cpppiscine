#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "GameEntity.hpp"

class Enemy : public GameEntity
{
	private:
		bool isVisible;
	public:
		Enemy();
		~Enemy();
		Enemy(const Enemy &src);
		Enemy &operator=(const Enemy &rhs);
};

#endif