
#include "Brain.hpp"
#include <iostream>
#include <stdexcept>

Brain::Brain()
{
	std::cout << "Brain was constructed." << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain was copy-constructed." << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed." << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

const std::string& Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		throw std::out_of_range("Brain idea index out of range");
	return _ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		throw std::out_of_range("Brain idea index out of range");
	_ideas[index] = idea;
}
