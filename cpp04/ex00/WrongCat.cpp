#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat was constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat was copy-constructed." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat was destroyed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << _type << ": Nyanya!" << std::endl;
}
