#include "FragTrap.hpp"

int main()
{
	{
		FragTrap frag("Fraggy");
		frag.attack("a training dummy");
		frag.highFivesGuys();
		frag.takeDamage(40);
		frag.beRepaired(15);
	}

	FragTrap survivor("Survivor");
	survivor.highFivesGuys();

	FragTrap copied(survivor);
	FragTrap assigned("Assigned");
	assigned = copied;
}
