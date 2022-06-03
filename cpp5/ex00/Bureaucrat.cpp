#include "Bureaucrat.hpp"

Bureaucrat		*newBureaucrat(std::string const & name, int grade)
{
	Bureaucrat *ptr = new Bureaucrat(name, grade);
	
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooLowException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "(" << ptr << ") ";
		std::cout << name << " " << grade << ", ";
		std::cout << e.what() << std::endl;
		delete ptr;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << "(" << ptr << ") ";
		std::cout << name << " " << grade << ", ";
		std::cout << e.what() << std::endl;
		delete ptr;
	}
	return (ptr);
}


/* *****************
	Main stuffs
***************** */

void Bureaucrat::promote()
{
	this->_grade--;
}

void Bureaucrat::degrade()
{
	this->_grade++;
}


/* *****************
	Exceptions
***************** */

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low: min is 1 (for expert)");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high: max is 150 (for beginer)");
}


/* *****************
	Getters/Setters
***************** */

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Bureaucrat const & instance)
{
	o << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return o;
}

Bureaucrat	& Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src.getGrade();
	std::cout << "(" << this << " - assign.) Bureaucrat (" << &src << ") copied" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) :
_name(src.getName()),
_grade(src.getGrade())
{
	std::cout << "(" << this << " - copy) Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) :
_name(name),
_grade(grade)
{
	std::cout << "(" << this << " - string) Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat()
{
	std::cout << "(" << this << " - default) Bureaucrat created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "(" << this << " - default) Bureaucrat destroyed" << std::endl;
}
