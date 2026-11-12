#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream output((_target + "_shrubbery").c_str());
	if (!output)
		throw std::runtime_error("Could not create shrubbery file.");
	output << "       *\n"
		<< "      /\\\n"
		<< "     /**\\\n"
		<< "    /****\\\n"
		<< "   /******\\\n"
		<< "      ||\n"
		<< "      ||\n\n"
		<< "       *\n"
		<< "      /\\\n"
		<< "     /**\\\n"
		<< "    /****\\\n"
		<< "      ||\n"
		<< "      ||\n";
	if (!output)
		throw std::runtime_error("Could not write shrubbery file.");
}
