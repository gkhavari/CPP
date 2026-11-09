#include "Animal.hpp"
#include <iostream>

Animal::Animal(const std::string& type)
	: _type(type)
{
	std::cout << "Animal was constructed." << std::endl;
}

Animal::Animal(const Animal& other)
	: _type(other._type)
{
	std::cout << "Animal was copy-constructed." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal was destroyed." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string Animal::getType() const
{
	return(this->_type);
}

// void Animal::makeSound() const
// {
// 	std::cout << this->_type << " makes an unspecified sound." << std::endl;
// }
