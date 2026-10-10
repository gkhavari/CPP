#ifndef CONTACT_H
# define CONTACT_H
# include <string>

class Contact
{
	private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

	public:
		// Constructors
		Contact(); //needed for creating Contacts in the PhoneBook class
		Contact(std::string firstName, std::string lastName, std::string nickname,
			std::string phoneNumber, std::string darkestSecret);
		// Member functions
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};
#endif
