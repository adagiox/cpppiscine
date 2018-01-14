#include "Player.hpp"

Player::Player(char entityChar) : GameEntity(entityChar) {}
Player::~Player() {}

Player::Player(const Player &src) : GameEntity(src.entityChar)
{
	this->entityChar = src.entityChar;
}

Player &Player::operator=(const Player &rhs)
{
	if (this != &rhs)
	{
		this->entityChar = rhs.entityChar;
	}
	return *this;
}

