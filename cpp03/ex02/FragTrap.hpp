#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const std::string& name = "generic FragTrap");
		FragTrap(const FragTrap& other);
		~FragTrap();

		FragTrap& operator=(const FragTrap& other);
		void highFivesGuys(void);
};

#endif
