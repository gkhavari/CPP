#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
		AForm();

	protected:
		virtual void executeAction() const = 0;

	public:
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
