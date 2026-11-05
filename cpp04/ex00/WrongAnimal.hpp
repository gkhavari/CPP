#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	
	public:
		WrongAnimal(const std::string& = "WrongAnimal");
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);

		WrongAnimal& operator=(const WrongAnimal& other);

		std::string getType() const;
		void makeSound() const;
};

#endif
