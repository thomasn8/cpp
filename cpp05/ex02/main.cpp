#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::endl;
	Bureaucrat *jean = newBureaucrat("Jean", 100);
	std::cout << *jean << std::endl;
	std::cout << std::endl;

	// TEST 1: instanciation of abstract class Form
	// Form *test = new Form("test", 1 , 1);		// DOESN'T COMPILE

	// TEST 2: instanciation of concreat class Shrubbery
	Form *shrubbery1 = newShrubberyCreationForm("Jardin");
	std::cout << *shrubbery1 << std::endl;
	std::cout << std::endl;

	// TEST 3: instanciation of concreat classes Robotomy and Presidential
	Form *robotomy1 = newRobotomyRequestForm("Perceuse");
	std::cout << *robotomy1 << std::endl;
	Form *presidential1 = newPresidentialPardonForm("Corbeau");
	std::cout << *presidential1 << std::endl;
	std::cout << std::endl;

	// TEST 4:
	jean->signForm(shrubbery1);
	std::cout << *shrubbery1 << std::endl;
	jean->signForm(robotomy1);
	std::cout << *robotomy1 << std::endl;
	jean->signForm(presidential1);
	std::cout << *presidential1 << std::endl;

	// End: destructors
	std::cout << std::endl;
	delete jean;
	delete shrubbery1;
	delete robotomy1;
	delete presidential1;
	return 0;
}
