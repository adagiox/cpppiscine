#include "Pony.hpp"

Pony::Pony(std::string name, std::string where)
{
	this->name = name;
	this->where = where;
	std::cout << this->name << " was born this day on..." << this->where << "!"  << std::endl;
}

void Pony::ponyOnTheStack()
{
	std::string name = "Stacky";
	std::string where = "the Stack";
	Pony stackPony(name, where);
}

void Pony::ponyOnTheHeap()
{
	std::string name = "Heapy";
	std::string where = "the Heap";
	Pony *heapPony = new Pony(name, where);
	delete heapPony;
}

Pony::~Pony()
{
	std::cout << this->name << " has died. Long live " << this->name << "!"  << std::endl;
}
