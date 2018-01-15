#include "Enemy.hpp"

Enemy::Enemy() : GameEntity('C'), isVisible(false)
{
	// wprintw(stdscr, "Enemy constructor\n");
	// wrefresh(stdscr);
}
Enemy::~Enemy() {}
// Enemy::Enemy(const Enemy &src) 
// {
// 	this->
// }
void Enemy::talk(WINDOW *win)
{
	wprintw(win, "This is enemy number %i\n", this->number);
	wrefresh(win);
}

void Enemy::setNumber(int num)
{
	this->number = num;
	if (rand() % 2 == 0)
	{
		this->hp = 2;
		this->setEntityChar('D');
		if (rand() % 2 == 0)
		{
			this->hp = 3;
			this->setEntityChar('E');
		}
	}
	else
		this->hp = 1;
}

bool Enemy::takeHit()
{
	this->hp--;
	if (this->hp == 0)
	{
		this->isVisible = false;
		return true;
	}
	return false;
}