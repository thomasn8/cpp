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
	Bureaucrat *lucas = newBureaucrat("Lucas", 1);
	std::cout << *lucas << std::endl;
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

	// TEST 4: signatures
	jean->signForm(*shrubbery1);				// 100 vs 145
	jean->signForm(*robotomy1);					// 100 vs 72
	jean->signForm(*presidential1);				// 100 vs 25
	presidential1->beSigned(*lucas);			// 1 vs 5
	std::cout << std::endl;
	
	// TEST 5: execute
	shrubbery1->execute(*jean);					// 100 vs 137
	robotomy1->execute(*jean);					// 100 vs 45
	presidential1->execute(*jean);				// 100 vs 5
	shrubbery1->execute(*lucas);				// 1 vs 137
	robotomy1->execute(*lucas);					// 1 vs 45
	presidential1->execute(*lucas);				// 1 vs 5
	std::cout << std::endl;
	jean->executeForm(*robotomy1);				// 100 vs 45
	robotomy1->beSigned(*lucas);
	jean->executeForm(*robotomy1);				// 100 vs 45
	lucas->executeForm(*robotomy1);				// 1 vs 45

	// TEST 6: destructors
	std::cout << std::endl;
	delete jean;
	delete lucas;
	delete shrubbery1;
	delete robotomy1;
	delete presidential1;
	return 0;
}
