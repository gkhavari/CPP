#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog()
	: Animal("Dog"),
	_brain(new Brain)
{
	std::cout << "Dog was constructed." << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other),
	_brain(new Brain(*other._brain))
{
	std::cout << "Dog was copy-constructed." << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog was destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	 	*_brain = *other._brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << _type << ": Woof!" << std::endl;
}

Brain& Dog::getBrain()
{
	return *_brain;
}

const Brain& Dog::getBrain() const
{
	return *_brain;
}
