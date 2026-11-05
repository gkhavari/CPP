#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// //...
// 	return(0);
// }

int main()
{
	const int animalCount = 4;
	Animal* animals[animalCount];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	std::cout << "\n=== Types and sounds through Animal pointers ===\n";
	for (int i = 0; i < animalCount; ++i)
	{
		std::cout << "Type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << "\n=== Plain Animal sound ===\n";
	Animal animal;
	animal.makeSound();

	std::cout << "\n=== Destroying animals through Animal pointers ===\n";
	for (int i = 0; i < animalCount; ++i)
		delete animals[i];

	std::cout << "\n=== Now testing with WrongAnimal, and wrong Cat, where the makeSound function is not virtual ===\n";
	const int wrongAnimalCount = 2;
	WrongAnimal* wrongAnimals[wrongAnimalCount];

	wrongAnimals[0] = new WrongCat();
	wrongAnimals[1] = new WrongCat();

	std::cout << "\n=== Types and sounds through WrongAnimal pointers ===\n";
	for (int i = 0; i < wrongAnimalCount; ++i)
	{
		std::cout << "Type: " << wrongAnimals[i]->getType() << std::endl;
		wrongAnimals[i]->makeSound();
	}

	std::cout << "\n=== Plain WrongAnimal sound ===\n";
	WrongAnimal wrongAnimal;
	wrongAnimal.makeSound();

	std::cout << "\n=== Destroying WrongAnimals through WrongAnimal pointers ===\n";
	for (int i = 0; i < wrongAnimalCount; ++i)
		delete wrongAnimals[i];
	std::cout << "\n=== Stack Wronganimal gets destroyed automatically ===\n";
	std::cout << "=== Stack animal gets destroyed automatically ===\n";
	return 0;
}
