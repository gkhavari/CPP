#include "Harl.hpp"

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	const std::string level(argv[1]);
	int levelIndex = -1;

	switch (level[0])
	{
		case 'D':
			levelIndex = 0;
			break;
		case 'I':
			levelIndex = 1;
			break;
		case 'W':
			levelIndex = 2;
			break;
		case 'E':
			levelIndex = 3;
			break;
		default:
			levelIndex = -1;
			break;
	}

	switch (levelIndex)
	{
		case 0:
			harl.complain("DEBUG");
			// no break execution falls through
		case 1:
			harl.complain("INFO");
			// no break execution falls through
		case 2:
			harl.complain("WARNING");
			// no break execution falls through
		case 3:
			harl.complain("ERROR");
			// now we break
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
