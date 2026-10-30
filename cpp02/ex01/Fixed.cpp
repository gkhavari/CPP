#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::_fractionalBits;

//Default constructor
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
	: _rawBits(value * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value)
	: _rawBits(static_cast<int>(roundf(value * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
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
	return (_rawBits);
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_rawBits / (1 << _fractionalBits));
}

std::ostream & operator<<(std::ostream & output, Fixed const & fixed)
{
	output << fixed.toFloat();
	return (output);
}
