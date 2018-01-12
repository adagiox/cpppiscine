#include "Fixed.hpp"

Fixed::Fixed():fpv(0) {}
Fixed::~Fixed()

Fixed(Fixed const &src) 
{
	this->fpv = src.fpv;
	this->fb = src.fb;
}

Fixed &operator=(Fixed const &rhs) { return *this; }