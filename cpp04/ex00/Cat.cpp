#include "Cat.hpp"
#include <iostream>

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat was constructed." << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat was copy-constructed." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat was destroyed." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << _type << ": Meow!" << std::endl;
}
