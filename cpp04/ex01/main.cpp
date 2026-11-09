#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j; //should not create a leak
// 	delete i;
// 	//...
// 	return (0);
// }

int main()
{
	std::cout << "=== Polymorphism and deletion through Animal pointers ===\n";
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; ++i)
	{
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; ++i)
		delete animals[i];

	return (0);
}
