#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{
	private:
		std::string name;
		std::string type;

	public:
		Zombie();
		~Zombie();
		void setType(std::string type);
		void announce();
		std::string getName();
		std::string getType();
};

#endif
