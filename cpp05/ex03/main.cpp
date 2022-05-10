#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	Intern someRandomIntern;	// stack allocation
	Form* form1;				// heap allocation
	Form* form2;
	Form* form3;
	Form* form4;
	form1 = someRandomIntern.makeForm("shrubbery creation", "abc");		// ok
	form2 = someRandomIntern.makeForm("robotomy request", "dfg");		// ok
	form3 = someRandomIntern.makeForm("presidential pardon", "hij");	// ok
	form4 = someRandomIntern.makeForm("nimp", "klm");					// n'existe pas
	delete form1;
	delete form2;
	delete form3;
	delete form4;
	return 0;
}
