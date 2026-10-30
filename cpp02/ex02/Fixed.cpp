#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::_fractionalBits;

//Default constructor
Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(int const value)
	: _rawBits(value * (1 << _fractionalBits)) {}

Fixed::Fixed(float const value)
	: _rawBits(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {}

//Copy constructor (calls the copy assignment operator)
Fixed::Fixed(Fixed const & other)
{
	*this = other;
}

//Copy assignment operator (calls getRawBits member function)
Fixed & Fixed::operator=(Fixed const & other)
{	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

//Destructor
Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
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

//comparison operators
bool operator>(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits());
}

bool operator<(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits());
}

bool operator>=(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs.getRawBits() >= rhs.getRawBits());
}

bool operator<=(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs.getRawBits() <= rhs.getRawBits());
}

bool operator==(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs.getRawBits() == rhs.getRawBits());
}

bool operator!=(Fixed const & lhs, Fixed const & rhs)
{
	return (lhs.getRawBits() != rhs.getRawBits());
}

//arithmetic operators
Fixed operator+(Fixed const & lhs, Fixed const & rhs)
{
	Fixed result;
	result.setRawBits(lhs.getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed operator-(Fixed const & lhs, Fixed const & rhs)
{
	Fixed result;
	result.setRawBits(lhs.getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed operator*(Fixed const & lhs, Fixed const & rhs)
{
	return (Fixed(lhs.toFloat() * rhs.toFloat()));
}

Fixed operator/(Fixed const & lhs, Fixed const & rhs)
{
	return (Fixed(lhs.toFloat() / rhs.toFloat()));
}

//increment/decrement operators
Fixed & Fixed::operator++()
{
	++_rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed previous(*this);
	++_rawBits;
	return (previous);
}

Fixed & Fixed::operator--()
{
	--_rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed previous(*this);
	--_rawBits;
	return (previous);
}

Fixed & Fixed::min(Fixed & first, Fixed & second)
{
	return (first < second ? first : second);
}

Fixed const & Fixed::min(Fixed const & first, Fixed const & second)
{
	return (first < second ? first : second);
}

Fixed & Fixed::max(Fixed & first, Fixed & second)
{
	return (first > second ? first : second);
}

Fixed const & Fixed::max(Fixed const & first, Fixed const & second)
{
	return (first > second ? first : second);
}
