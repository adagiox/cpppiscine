#include <iostream>
#include "Zombie.hpp"

std::string Zombie::getName() { return name; }
std::string Zombie::getType() { return type; }
Zombie::Zombie(std::string name) { this->name = name; }
Zombie::~Zombie(){ std::cout << this->name << " is dead!" << std::endl; };
void Zombie::setType(std::string type) { this->type = type; }

void Zombie::announce()
{
	std::cout << "<" << this->getType() << " (" << this->getName() <<
		")> Braiiiiiinnnnssssss......" << std::endl;
	
}
