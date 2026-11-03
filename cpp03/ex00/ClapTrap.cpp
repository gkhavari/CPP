#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " is copy-constructed." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack because it has no hit points." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot attack because it has no energy points." << std::endl;
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damage;
	if(amount < _hitPoints)
		damage = amount;
	else
		damage = _hitPoints;
	_hitPoints -= damage;
	std::cout << "ClapTrap " << _name << " takes " << damage
		<< " points of damage and has " << _hitPoints
		<< " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot repair because it has no hit points." << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name
			<< " cannot repair because it has no energy points." << std::endl;
		return;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
		<< " hit points and now has " << _hitPoints
		<< " hit points." << std::endl;
}
