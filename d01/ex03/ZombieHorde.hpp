#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <ctime>
#include <cstdlib>

class ZombieHorde
{
	private:
		int n;
		Zombie *zed;

	public:
		ZombieHorde(int n);
		~ZombieHorde();
		Zombie *getZed(int i);
		int getN();
		void announce();

};

#endif
