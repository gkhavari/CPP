#include "Dog.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog was constructed." << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog was copy-constructed." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << _type << ": Woof!" << std::endl;
}
