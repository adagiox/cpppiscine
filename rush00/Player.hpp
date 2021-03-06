#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameEntity.hpp"

class Player : public GameEntity
{
	public:
		Player();
		~Player();
		Player(const Player &src);
		Player &operator=(const Player &rhs);
};

#endif