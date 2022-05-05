#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
	
		Bureaucrat & operator=(Bureaucrat const & src);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name);
		Bureaucrat();
		~Bureaucrat();

		void setName(std::string const & name);
		std::string	getName() const ;

	private:

		std::string	_name;
};

std::ostream	& operator<<(std::ostream & o, Bureaucrat const & inst);

#endif
