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
	wprintw(win, "This is an enemy.\n");
	wrefresh(win);
}