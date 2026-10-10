#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "main.hpp"

bool	readField(const std::string& prompt, std::string& field)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, field))
			return (false);
		if (!field.empty())
			return (true);
		std::cout << "Field cannot be empty.\n";
	}
}

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while(1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!(std::getline(std::cin, command)))
			return (0);
		if (command == "ADD")
		{
            std::string first;
            std::string last;
            std::string nick;
            std::string phone;
            std::string secret;
            if (!readField("First name: ", first)
                || !readField("Last name: ", last)
                || !readField("Nickname: ", nick)
                || !readField("Phone number: ", phone)
                || !readField("Darkest secret: ", secret))
                break ;
			Contact contact(first, last, nick, phone, secret);
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if(command == "EXIT")
			break ;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
