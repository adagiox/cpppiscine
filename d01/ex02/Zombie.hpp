#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
		std::string type;

	public:
		Zombie(std::string name);
		~Zombie();
		void setType(std::string type);
		void announce();
		std::string getName();
		std::string getType();
};

#endif
