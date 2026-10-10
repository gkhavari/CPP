#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"


# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		int 	count;
		int		nextIndex;

	public:
		// Constructors
		PhoneBook();
		// Member functions
		void addContact(const Contact& contact);
		void searchContact();
		int getNumEntries();
};

#endif
