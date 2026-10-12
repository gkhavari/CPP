#include "Harl.hpp"

#include <iostream>
#include <string>

int main(void)
{
	Harl harl;
	std::string level;

	std::cout << "Enter a complaint level (DEBUG, INFO, WARNING, ERROR): ";
	if (std::getline(std::cin, level))
		harl.complain(level);
	return (0);
}
