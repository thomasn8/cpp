#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctype.h>

Form *makeForm(std::string formName, std::string target)
{
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	f_ptr	functions[] = {&newShrubberyCreationForm, &newRobotomyRequestForm, &newPresidentialPardonForm};


}

/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Intern const & instance)
{
	o << "Intern";
	return o;
}

Intern	& Intern::operator=(Intern const & src)
{
	std::cout << "(" << this << " - assign.) Intern (" << &src << ") copied" << std::endl;
	return *this;
}

Intern::Intern(Intern const & src)
{
	std::cout << "(" << this << " - copy) Intern created" << std::endl;
}

Intern::Intern()
{
	std::cout << "(" << this << " - default) Intern created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "(" << this << " - default) Intern destroyed" << std::endl;
}
