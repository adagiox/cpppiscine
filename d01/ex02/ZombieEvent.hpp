#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent();
		~ZombieEvent();
		void setZombieType(Zombie *z, std::string type);
		Zombie *newZombie(std::string name);
		void randomChump(int rand);
};

#endif
