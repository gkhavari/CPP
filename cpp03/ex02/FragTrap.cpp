#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " is copy-constructed." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name
		<< " requests a positive high-five!" << std::endl;
}
