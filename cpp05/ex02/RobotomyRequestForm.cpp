#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::action() const
{
	std::string noise;
	int rand_num;

	std::cout << BLU;
	noise = "\"TTrrRRRRrrrlktKtTKt TTrrRRRRrrrlktKtTKt\"";
	std::cout << noise << std::endl;
	srand (time(NULL));
	rand_num = rand() % 2 + 1;
	if (rand_num == 1)
		std::cout << this->getName() << " successfuly robotomised" << std::endl;
	else
		std::cout << "Failure: the robotization operation failed" << std::endl;
	std::cout << WHI;
}

Form		*newRobotomyRequestForm(std::string const & target)
{
	Form *ptr = new RobotomyRequestForm(target);
	return ptr;
}

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
	// this->robotomisation();
	std::cout << "(" << this << " - copy) RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
Form(target, 72, 45)
{
	// this->robotomisation();
	std::cout << "(" << this << " - string) RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "(" << this << " - default) RobotomyRequestForm destroyed" << std::endl;
}
