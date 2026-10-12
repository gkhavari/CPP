#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::string name;

	std::cout << "Name for the stack-allocated zombie: ";
	std::getline(std::cin, name);
	std::cout << "Creating a stack zombie..." << std::endl;
	randomChump(name);
	std::cout << "randomChump returned; its stack zombie was destroyed automatically."
		<< std::endl;

	std::cout << "\nName for the heap-allocated zombie: ";
	std::getline(std::cin, name);
	Zombie* heapZombie = newZombie(name);
	heapZombie->announce();
	std::cout << "The heap zombie remains alive until it is explicitly deleted."
		<< std::endl;
	std::cout << "Press Enter to delete it...";
	std::getline(std::cin, name);
	delete heapZombie;
	return (0);
}
