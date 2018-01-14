#include "Player.hpp"

Player::Player() : GameEntity('>') {}
Player::~Player() {}

Player::Player(const Player &src) : GameEntity(src.entityChar) {}

Player &Player::operator=(const Player &rhs)
{
	if (this != &rhs)
	{
		this->entityChar = rhs.entityChar;
	}
	return *this;
}

