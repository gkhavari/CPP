#include "PhoneBook.hpp"
#include <sstream>

static void printCell(const std::string& value)
{
	std::string text = value;
	if (text.length() > 10)
	{
		text.resize(9);
		text += ".";
	}
	std::cout << std::right << std::setw(10) << text;
}

// Constructors
PhoneBook::PhoneBook()
{
	count = 0;
	nextIndex = 0;
}

// Member functions
void PhoneBook::addContact(const Contact& contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;
	if (count < MAX_CONTACTS)
		count++;
}

void PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return ;
	}
	printCell("Index");
	std::cout << '|';
	printCell("First name");
	std::cout << '|';
	printCell("Last name");
	std::cout << '|';
	printCell("Nickname");
	std::cout << '\n';
	std::cout << "----------|----------|----------|----------\n";
	for (int i = 0; i < count; i++)
	{
		int contactIndex = (nextIndex - count + i + MAX_CONTACTS)
			% MAX_CONTACTS;
		std::cout << std::right << std::setw(10) << i << '|';
		printCell(contacts[contactIndex].getFirstName());
		std::cout << '|';
		printCell(contacts[contactIndex].getLastName());
		std::cout << '|';
		printCell(contacts[contactIndex].getNickname());
		std::cout << '\n';
	}
	std::cout << "Enter index: ";
	std::string input;
	if (!std::getline(std::cin, input))
		return ;
	std::istringstream inputStream(input);
	int index;
	char extra;
	if (!(inputStream >> index) || (inputStream >> extra)
		|| index < 0 || index >= count)
	{
		std::cout << "Invalid index.\n";
		return ;
	}
	int contactIndex = (nextIndex - count + index + MAX_CONTACTS)
		% MAX_CONTACTS;
	std::cout << "First name: " << contacts[contactIndex].getFirstName() << '\n'
		<< "Last name: " << contacts[contactIndex].getLastName() << '\n'
		<< "Nickname: " << contacts[contactIndex].getNickname() << '\n'
		<< "Phone number: " << contacts[contactIndex].getPhoneNumber() << '\n'
		<< "Darkest secret: " << contacts[contactIndex].getDarkestSecret() << '\n';
}

int PhoneBook::getNumEntries()
{
	return (this->count);
}
