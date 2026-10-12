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
	if (level == "DEBUG")
		levelIndex = 0;
	else if (level == "INFO")
		levelIndex = 1;
	else if (level == "WARNING")
		levelIndex = 2;
	else if (level == "ERROR")
		levelIndex = 3;

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
