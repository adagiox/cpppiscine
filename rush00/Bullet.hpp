#ifndef BULLET_HPP
#define BULLET_HPP

#include "GameEntity.hpp"

class Bullet : public GameEntity
{
	public:
		bool isVisible;
		Bullet();
		~Bullet();
		//Bullet(const Bullet &src);
};

#endif