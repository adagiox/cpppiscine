#include "ZombieHorde.hpp"

Zombie *ZombieHorde::getZed(int i) { return &zed[i]; }
ZombieHorde::ZombieHorde(int n)
{
	if (n < 1)
		return;
	std::srand(std::time(0));
	this->n = n;
	Zombie *zeds = new Zombie[n];
	this->zed = zeds;
}

ZombieHorde::~ZombieHorde() { delete [] zed; }
int ZombieHorde::getN() { return n; }

void ZombieHorde::announce()
{
	for (int i = 0; i < this->getN(); i++)
		getZed(i)->announce();
}
