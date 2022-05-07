#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

# define RED "\033[0;31m"
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
