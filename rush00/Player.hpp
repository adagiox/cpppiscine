#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameEntity.hpp"

class Player : public GameEntity
{
	private:
		

	public:
		Player(char entityChar);
		~Player();
		Player(const Player &src);
		Player &operator=(const Player &rhs);
};

#endif