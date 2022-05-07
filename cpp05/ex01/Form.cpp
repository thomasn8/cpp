#include "Form.hpp"

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
		std::cerr << e.what();
		std::cerr << WHI << std::endl;
		delete ptr;
	}
	return (ptr);
}

/* *****************
	Main stuffs
***************** */

bool	Form::beSigned(Bureaucrat *bureaucrat)
{
	try
	{
		if (bureaucrat->getGrade() > this->getGradeSignature())
			throw Form::GradeTooLowException();
		else
		{
			std::cout << this->_name << ": form signed" << std::endl;
			this->_signature = true;
		}
	}
	catch(const std::exception & e)
	{
		std::cerr << RED;
		std::cerr << this->_name << ": ";
		std::cerr << bureaucrat->getName() << " can't sign it: ";
		std::cerr << e.what();
		std::cerr << WHI << std::endl;
	}
	return this->_signature;
}

/* *****************
	Exceptions
***************** */

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
	o << "/" << instance.getGradeExecution() << ") - signed : ";
	o << instance.getSignature();
	return o;
}

Form	& Form::operator=(Form const & src)
{
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
