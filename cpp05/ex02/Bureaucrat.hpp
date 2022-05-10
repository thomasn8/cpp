#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
class Form;

# define RED "\033[0;31m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define CYA "\033[0;36m"
# define WHI "\033[0m"

class Bureaucrat
{
	public:
	
		Bureaucrat & operator=(Bureaucrat const & src);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name, int grade);
		~Bureaucrat();

		std::string	getName() const ;
		int	getGrade() const ;

		bool promote();
		bool degrade();
		bool signForm(Form & form);
		bool executeForm(Form const & form);

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

		std::string const _name;
		int _grade;
		
		Bureaucrat();
};

std::ostream	& operator<<(std::ostream & o, Bureaucrat const & inst);
Bureaucrat		*newBureaucrat(std::string const & name, int grade);

#endif
