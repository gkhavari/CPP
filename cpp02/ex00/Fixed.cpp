#include "Fixed.hpp"
#include <iostream>

//Default constructor
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor (calls the copy assignment operator)
Fixed::Fixed(Fixed const & other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//Copy assignment operator (calls getRawBits member function)
Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}
