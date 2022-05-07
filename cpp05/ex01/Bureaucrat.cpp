#include "Bureaucrat.hpp"

Bureaucrat		*newBureaucrat(std::string const & name, int grade)
{
	Bureaucrat *ptr = new Bureaucrat(name, grade);
	
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << RED;
		std::cerr << "(" << ptr << ") ";
		std::cerr << name << " " << grade << ": ";
		std::cerr << e.what();
		std::cerr << WHI << std::endl;
		delete ptr;
	}
	return (ptr);
}

/* *****************
	Exceptions
***************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}


/* *****************
	Main stuffs
***************** */

bool Bureaucrat::promote()
{
	int prev_grade = this->_grade;
	this->_grade--;
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			std::cout << this->_name << ": bureaucrat promoted. New grade: " << this->_grade << std::endl;
	}
	catch(const std::exception & e)
	{
		this->_grade++;
		std::cerr << RED;
		std::cerr << this->_name << " has reached the maximum step in the company";
		std::cerr << WHI << std::endl;
	}
	if (this->_grade != prev_grade)
		return true;
	return false;
}

bool Bureaucrat::degrade()
{
	int prev_grade = this->_grade;
	this->_grade++;
	try
	{
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << this->_name << ": bureaucrat degraded. New grade: " << this->_grade << std::endl;
	}
	catch(const std::exception & e)
	{
		this->_grade--;
		std::cerr << RED;
		std::cerr << this->_name << " is already at the lowest tier in the company.";
		std::cerr << WHI << std::endl;
	}
	if (this->_grade != prev_grade)
		return true;
	return false;
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
