#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Bender");
	PresidentialPardonForm pardon("Ford Prefect");

	bureaucrat.signForm(shrubbery);
	bureaucrat.executeForm(shrubbery);
	bureaucrat.signForm(robotomy);
	bureaucrat.executeForm(robotomy);
	bureaucrat.signForm(pardon);
	bureaucrat.executeForm(pardon);
	return 0;
}
