void add_contact(PhoneBook *phonebook)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string darkest_secret;

	first_name = get_input("Please enter 'First Name': ");
	last_name = get_input("Please enter 'Last Name': ");
	nickname = get_input("Please enter 'Nickname': ");
	phone_number = get_input("Please enter 'Phone Number': ");
	darkest_secret = get_input("Please enter 'Darkest Secret': ");
	phonebook->add(first_name, last_name, nickname, phone_number, darkest_secret);
}

int main(void)
{
	std::string command;
	PhoneBook phonebook;

	while(1)
	{
		std::cout << std::endl << "Type ADD to save a new contact, SEARCH to search for a contact or EXIT to exit the program" << std::endl;
		std::cout << "Enter command: ";
		if (!(std::getline(std::cin, command)))
			return (1);
		if (command.compare("ADD") == 0)
			add_contact(&phonebook);
		else if (command.compare("SEARCH") == 0)
			search_contact(&phonebook);
		else if(command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
