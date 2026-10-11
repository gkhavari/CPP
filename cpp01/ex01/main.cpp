#include "Zombie.hpp"

int main(void)
{
	Zombie *Horde = zombieHorde(5, "Zombie");

	for (int i = 0; i < 5; i++)
		Horde[i].announce();
	delete [] Horde;
	return 0;
}
