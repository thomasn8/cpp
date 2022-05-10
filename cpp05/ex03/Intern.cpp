#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form *Intern::makeForm(std::string formName, std::string target)
{
	std::string	formsName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	f_ptr	newForms[3] = {&newShrubberyCreationForm, &newRobotomyRequestForm, &newPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formsName[i])
		{
			std::cout << BLU << *this << " creates " << formName << std::endl << WHI;
			return (*newForms[i])(target);
		}
	}
	std::cout << RED << "\"" << formName << "\": this kind of form doesn't exist" << std::endl << WHI;
	return NULL;
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
