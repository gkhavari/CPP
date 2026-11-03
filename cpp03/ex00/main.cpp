#include "ClapTrap.hpp"

int main()
{
	ClapTrap survivor("Survivor");
	survivor.attack("a training dummy");
	survivor.takeDamage(4);
	survivor.beRepaired(2);
	survivor.takeDamage(20);
	survivor.attack("a training dummy");
	survivor.beRepaired(1);

	ClapTrap exhausted("Exhausted");
	for (int i = 0; i < 11; ++i)
		exhausted.attack("a training dummy");
	exhausted.beRepaired(1);

	ClapTrap copied(survivor);
	ClapTrap assigned("Assigned");
	assigned = copied;
}
