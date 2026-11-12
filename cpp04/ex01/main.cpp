#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <string>

static void runTests()
{
	std::cout << "\n=== Creating a bureaucrat called Alice of grade 3 ===\n";
	Bureaucrat mid("Alice", 3);

	std::cout << "\n=== Creating a form called Tax form ===\n";
	Form taxForm("Tax form", 3, 10);
	std::cout << "Created: " << taxForm << std::endl;
	std::cout << "Form name: " << taxForm.getName() << std::endl;
	std::cout << "Form signed: " << taxForm.getIsSigned() << std::endl;
	std::cout << "Grade required to sign: "
		<< taxForm.getGradeToSign() << std::endl;
	std::cout << "Grade required to execute: "
		<< taxForm.getGradeToExecute() << std::endl;

	std::cout << "\n=== Testing signing with a sufficient grade ===\n";
	std::cout << "Before: " << taxForm << std::endl;
	taxForm.beSigned(mid);
	std::cout << "After:  " << taxForm << std::endl;

	std::cout << "\n=== Testing signing with an insufficient grade ===\n";
	Form restrictedForm("Restricted form", 1, 1);
	Bureaucrat junior("Junior", 20);
	std::cout << "Before: " << restrictedForm << std::endl;
	try
	{
		restrictedForm.beSigned(junior);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "After:  " << restrictedForm << std::endl;
	junior.signForm(restrictedForm);

	std::cout << "\n=== Testing signForm with a sufficient grade ===\n";
	Form contract("Contract", 3, 10);
	std::cout << "Before: " << contract << std::endl;
	mid.signForm(contract);
	std::cout << "After:  " << contract << std::endl;

	std::cout << "\n=== Testing Form copy constructor ===\n";
	Form copiedForm(contract);
	std::cout << "Original: " << contract << std::endl;
	std::cout << "Copy:     " << copiedForm << std::endl;

	std::cout << "\n=== Testing Form copy assignment operator ===\n";
	Form assignmentSource("Source form", 3, 5);
	mid.signForm(assignmentSource);
	Form assignmentTarget("Target form", 20, 30);
	std::cout << "Original: " << assignmentSource << std::endl;
	std::cout << "Before assignment: " << assignmentTarget << std::endl;
	assignmentTarget = assignmentSource;
	std::cout << "After assignment:  " << assignmentTarget << std::endl;
	std::cout << "Target name: " << assignmentTarget.getName() << std::endl;
	std::cout << "Target grade to sign: "
		<< assignmentTarget.getGradeToSign() << std::endl;
	std::cout << "Target grade to execute: "
		<< assignmentTarget.getGradeToExecute() << std::endl;
}

int main()
{
	runTests();
	return (0);
}
