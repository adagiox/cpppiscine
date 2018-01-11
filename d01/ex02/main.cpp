#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main()
{
	std::string name = "Zombie1";
	std::string type = "Basic";
	Zombie *zed = new Zombie(name);
	zed->setType(type);
	zed->announce();
	delete zed;
	
	ZombieEvent *z = new ZombieEvent();
	std::srand(time(0));
	z->randomChump(rand());
	z->randomChump(rand());
	z->randomChump(rand());
	return 0;
}
