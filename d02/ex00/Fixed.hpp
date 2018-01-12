#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fpv;
		static const int fb;

	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const & src);
		Fixed & operator=(Fixed const & rhs);
};

std::ostream & operator<<(std::ostream &o, Fixed const & i);

#endif