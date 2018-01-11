#include "Brain.hpp"

Brain::Brain()
{
	std::string name = "Bob's brain";
	this->name = name;
}

Brain::~Brain() {}
std::string Brain::identify() const
{
	std::stringstream stream;
	const void* v = this;
	stream << v;
	return stream.str();
}