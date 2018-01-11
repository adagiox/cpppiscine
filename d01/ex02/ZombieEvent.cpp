#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(){};
ZombieEvent::~ZombieEvent(){};
void ZombieEvent::setZombieType(Zombie *z, std::string type) { z->setType(type); }
Zombie *ZombieEvent::newZombie(std::string name){ return (new Zombie(name)); }

void ZombieEvent::randomChump(int rand)
{
	std::string names[] = {"Chad", "Chappy", "Chuck", "Char", "Chase", "Chubby", "Chin", "Chadwidck", "Rick", "Morty"};
	std::string name;
	std::string type = "Chump";
	name = names[rand % 10];
	Zombie *z = newZombie(name);
	setZombieType(z, type);
	z->announce();
	delete z;
}
