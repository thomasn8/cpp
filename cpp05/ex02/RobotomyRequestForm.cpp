#include "RobotomyRequestForm.hpp"

Form		*newRobotomyRequestForm(std::string const & target)
{
	Form *ptr = new RobotomyRequestForm(target);
	return ptr;
}

/* *****************
	...
***************** */


void RobotomyRequestForm::abstract() const
{
	return ;
}

/* *****************
	Getters/Setters
***************** */



/* *****************
	Canonical
***************** */

RobotomyRequestForm	& RobotomyRequestForm::operator=(RobotomyRequestForm const & src)
{
	std::cout << "(" << this << " - assign.) Can't reassign an existing form" << std::endl;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
Form(src.getName(), 72, 45)
{
	std::cout << "(" << this << " - copy) RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
Form(target, 72, 45)
{
	std::cout << "(" << this << " - string) RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "(" << this << " - default) RobotomyRequestForm destroyed" << std::endl;
}
