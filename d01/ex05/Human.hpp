#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"

class Human
{
	public:
		const Brain b;
		const Brain &getBrain();
		std::string identify();
};

#endif