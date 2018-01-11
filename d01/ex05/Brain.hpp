#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
	public:
		Brain();
		~Brain();
		std::string name;
		std::string identify() const;
};

#endif