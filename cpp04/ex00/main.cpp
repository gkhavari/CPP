#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

static void runTests()
{
	
	std::cout << "\n=== Creating a bureaucrat called Alice of grade 3 ===\n";
	Bureaucrat mid("Alice", 3);
	std::cout << "Created: " << mid << std::endl;
	std::cout << "Bureaucrat name: " << mid.getName() << std::endl;
	std::cout << "Bureaucrat grade: " << mid.getGrade() << std::endl;


	std::cout << "\n=== Checking incrementing and decrementing grade ===\n";
	std::cout << "Increment grade: " << mid.getGrade() << " -> ";
	mid.incrementGrade();
	std::cout << mid.getGrade() << std::endl;
	std::cout << "Decrement grade: " << mid.getGrade() << " -> ";
	mid.decrementGrade();
	std::cout << mid.getGrade() << std::endl;
	
	
	std::cout << "\n=== Check top and bottom grade ===\n";
	Bureaucrat highest("Top", 1);
	std::cout << "Created: " << highest << std::endl;
	Bureaucrat lowest("Bottom", 150);
	std::cout << "Created: " << lowest << std::endl;
	std::cout << "Try to increment Top's grade: " << highest.getGrade() << " -> ";
	try
	{
		highest.incrementGrade();
		std::cout << highest.getGrade() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << highest.getGrade() << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Try to decrement Bottoms's grade: " << lowest.getGrade() << " -> ";
	try
	{
		lowest.decrementGrade();
		std::cout << lowest.getGrade() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << lowest.getGrade() << std::endl;
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	
	std::cout << "\n=== Using invalid grade ===\n";
	std::cout << "Try grade 0" << std::endl;
	try
	{
		Bureaucrat invalid("Too high", 0);
	}
	catch(std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Try grade 151" << std::endl;
	try
	{
		Bureaucrat invalid("Too low", 151);
	}
	catch(std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	

	std::cout << "\n=== Testing copy constructor ===\n";
	std::cout << "Original: " << mid << std::endl;
	Bureaucrat copied(mid);
	std::cout << "Copy    : " << copied << std::endl;


	std::cout << "\n=== Testing copy assignment operator ===\n";
	Bureaucrat assigned("Bob", 10);
	std::cout << mid << std::endl;
	std::cout << assigned << std::endl;
	std::cout << "Bob = Alice" << std::endl;
	assigned = mid;
	std::cout << mid << std::endl;
	std::cout << assigned << std::endl;
}

int main()
{
	runTests();
	return (0);
}
