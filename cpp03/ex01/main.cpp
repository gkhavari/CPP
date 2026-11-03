#include "ScavTrap.hpp"

int main()
{
	ScavTrap gatekeeper("Gatekeeper");
	gatekeeper.attack("a training dummy");
	gatekeeper.takeDamage(30);
	gatekeeper.beRepaired(10);
	gatekeeper.guardGate();

	ScavTrap defeated("Defeated");
	defeated.takeDamage(100);
	defeated.attack("a training dummy");

	ScavTrap copied(gatekeeper);
	ScavTrap assigned("Assigned");
	assigned = copied;
}
