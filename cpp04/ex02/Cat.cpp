#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat"),
	_brain(new Brain)
{
	std::cout << "Cat was constructed." << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other),
	_brain(new Brain(*other._brain))
{
	std::cout << "Cat was copy-constructed." << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat was destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	 	*_brain = *other._brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << _type << ": Meow!" << std::endl;
}
