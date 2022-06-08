#include "Form.hpp"
#include "Bureaucrat.hpp"

Form		*newForm(std::string const & name, int grade_sign, int grade_execute)
{
	Form *ptr = new Form(name, grade_sign, grade_execute);
	
	try
	{
		if (grade_sign < 1 || grade_execute < 1)
			throw Form::GradeTooLowException();
		else if (grade_sign > 150 || grade_execute > 150)
			throw Form::GradeTooHighException();
	}
	catch (std::exception & e)
	{
		std::cerr << RED;
		std::cerr << "(" << ptr << ") " << name << " ";
		std::cerr << grade_sign << "/" << grade_execute << ": ";
		std::cerr << e.what() << std::endl;
		std::cerr << WHI;
		delete ptr;
	}
	return (ptr);
}

/* *****************
	Main stuffs
***************** */

bool	Form::beSigned(Bureaucrat const & bureaucrat)
{
	try
	{
		if (this->_signature == true)
			throw Form::SignatureException();
		else if (bureaucrat.getGrade() > this->_gradeSignature)
			throw Form::GradeTooLowException();
		else
			this->_signature = true;
	}
	catch (const Form::SignatureException & e)
	{
		std::cerr << RED;
		std::cerr << this->_name << " couldn't be signed by " << bureaucrat.getName() << ". ";
		std::cerr << this->_name << " ";
		std::cerr << e.what() << std::endl;
		std::cerr << WHI;
		return false;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED;
		std::cerr << bureaucrat.getName() << " couldn't sign ";
		std::cerr << this->_name << " because ";
		std::cerr << e.what() << std::endl;
		std::cerr << WHI;
		return false;
	}
	std::cout << MAG << bureaucrat.getName() << " signed " << this->_name << std::endl << WHI;
	return true;
}


/* *****************
	Exceptions
***************** */

const char* Form::SignatureException::what() const throw()
{
	return ("has already been signed in the past");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

/* *****************
	Getters/Setters
***************** */

void	Form::setSignature()
{
	this->_signature = true;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool	Form::getSignature() const
{
	return this->_signature;
}

int	Form::getGradeSignature() const
{
	return this->_gradeSignature;
}

int	Form::getGradeExecution() const
{
	return this->_gradeExecution;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Form const & instance)
{
	o << instance.getName() << " (" << instance.getGradeSignature();
	o << "/" << instance.getGradeExecution() << ") - signed: ";
	o << instance.getSignature();
	return o;
}

Form	& Form::operator=(Form const & src)
{
	(void) src;
	std::cout << "(" << this << " - assign.) Can't reassign an existing form" << std::endl;
	return *this;
}

Form::Form(Form const & src) :
_name(src.getName()),
_signature(src.getSignature()),
_gradeSignature(src.getGradeSignature()),
_gradeExecution(src.getGradeExecution())
{
	std::cout << "(" << this << " - copy) Form created" << std::endl;
}

Form::Form(std::string const & name, int grade_sign, int grade_execute) :
_name(name),
_signature(false),
_gradeSignature(grade_sign),
_gradeExecution(grade_execute)
{
	std::cout << "(" << this << " - string) Form created" << std::endl;
}

Form::Form() :
_name("unknown"),
_signature(false),
_gradeSignature(0),
_gradeExecution(0)
{
	std::cout << "(" << this << " - default) Form created" << std::endl;
}

Form::~Form()
{
	std::cout << "(" << this << " - default) Form destroyed" << std::endl;
}
