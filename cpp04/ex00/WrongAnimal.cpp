#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(const std::string& type)
	: _type(type)
{
	std::cout << "WrongAnimal was constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: _type(other._type)
{
	std::cout << "WrongAnimal was copy-constructed." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was destroyed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return(this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << this->_type << " makes an unspecified but wrong sound." << std::endl;
}
