#include "PresidentialPardonForm.hpp"

Form		*newPresidentialPardonForm(std::string const & target)
{
	Form *ptr = new PresidentialPardonForm(target);
	return ptr;
}

/* *****************
	...
***************** */


void PresidentialPardonForm::abstract() const
{
	return ;
}

/* *****************
	Getters/Setters
***************** */



/* *****************
	Canonical
***************** */

PresidentialPardonForm	& PresidentialPardonForm::operator=(PresidentialPardonForm const & src)
{
	std::cout << "(" << this << " - assign.) Can't reassign an existing form" << std::endl;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
Form(src.getName(), 25, 5)
{
	std::cout << "(" << this << " - copy) PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
Form(target, 25, 5)
{
	std::cout << "(" << this << " - string) PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "(" << this << " - default) PresidentialPardonForm destroyed" << std::endl;
}
