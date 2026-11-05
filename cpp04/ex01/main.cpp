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

	std::cout << "\n=== Cat copy construction and assignment ===\n";
	Cat originalCat;
	originalCat.getBrain().setIdea(0, "cat idea");
	Cat copiedCat(originalCat);
	Cat assignedCat;
	assignedCat = originalCat;
	originalCat.getBrain().setIdea(0, "changed cat idea");
	if (copiedCat.getBrain().getIdea(0) != "cat idea"
		|| assignedCat.getBrain().getIdea(0) != "cat idea")
	{
		std::cerr << "Cat Brain deep-copy test failed.\n";
		return 1;
	}
	std::cout << "Cat Brain copies are independent.\n";
	copiedCat.makeSound();
	assignedCat.makeSound();

	std::cout << "\n=== Dog copy construction and assignment ===\n";
	Dog originalDog;
	originalDog.getBrain().setIdea(0, "dog idea");
	Dog copiedDog(originalDog);
	Dog assignedDog;
	assignedDog = originalDog;
	originalDog.getBrain().setIdea(0, "changed dog idea");
	if (copiedDog.getBrain().getIdea(0) != "dog idea"
		|| assignedDog.getBrain().getIdea(0) != "dog idea")
	{
		std::cerr << "Dog Brain deep-copy test failed.\n";
		return 1;
	}
	std::cout << "Dog Brain copies are independent.\n";
	copiedDog.makeSound();
	assignedDog.makeSound();

	std::cout << "\n=== Stack Cats and Dogs get destroyed automatically ===\n";
	return (0);
}
