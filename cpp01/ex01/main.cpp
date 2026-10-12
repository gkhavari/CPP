#include "Zombie.hpp"

#include <iostream>
#include <limits>
#include <string>

int main(void)
{
	int count;
	std::string name;

	std::cout << "How many zombies should be in the horde? ";
	if (!(std::cin >> count) || count <= 0)
	{
		std::cerr << "Please enter a positive number." << std::endl;
		return (1);
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "What should their name be? ";
	if (!std::getline(std::cin, name) || name.empty())
	{
		std::cerr << "Please enter a name." << std::endl;
		return (1);
	}

	Zombie *horde = zombieHorde(count, name);
	for (int i = 0; i < count; ++i)
		horde[i].announce();

	std::cout << "Press Enter to delete the horde...";
	std::cin.get();
	delete [] horde;
	return (1);
}
