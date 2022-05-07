#include "ShrubberyCreationForm.hpp"

Form		*newShrubberyCreationForm(std::string const & target)
{
	Form *ptr = new ShrubberyCreationForm(target);
	return ptr;
}

/* *****************
	...
***************** */


void ShrubberyCreationForm::abstract() const
{
	return ;
}

/* *****************
	Getters/Setters
***************** */



/* *****************
	Canonical
***************** */

ShrubberyCreationForm	& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	std::cout << "(" << this << " - assign.) Can't reassign an existing form" << std::endl;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
Form(src.getName(), 145, 137)
{
	std::cout << "(" << this << " - copy) ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
Form(target, 145, 137)
{
	std::cout << "(" << this << " - string) ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "(" << this << " - default) ShrubberyCreationForm destroyed" << std::endl;
}
