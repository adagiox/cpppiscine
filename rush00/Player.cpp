#include "Player.hpp"

Player::Player() {}
Player::~Player() {}

Player::Player(const Player &src)
{
	this->playerChar = src.playerChar;
}

Player &Player::operator=(const Player &rhs)
{
	if (this != &rhs)
	{
		this->playerChar = rhs.playerChar;
	}
	return *this;
}