#include "Enemy.hpp"

Enemy::Enemy() : GameEntity('C'), isVisible(false) 
{
	std::cout << "Enemy constructor" << std::endl;
}
Enemy::~Enemy() {}
// Enemy::Enemy(const Enemy &src) 
// {
// 	this->
// }