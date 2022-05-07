#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

# define RED "\033[0;31m"
# define WHI "\033[0m"

class Form
{
	public:
	
		Form & operator=(Form const & src);
		Form(Form const & src);
		Form(std::string const & name, int grade_sign, int grade_execute);
		~Form();

		bool beSigned(Bureaucrat *bureaucrat);

		std::string	getName() const;
		bool		getSignature() const;
		int			getGradeSignature() const;
		int			getGradeExecution() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		std::string	const _name;
		bool _signature;
		int const _gradeSignature;
		int const _gradeExecution;

		Form();
};

std::ostream	& operator<<(std::ostream & o, Form const & inst);
Form			*newForm(std::string const & name, int grade_sign, int grade_execute);

#endif
