#include "Bureaucrat.hpp"

int main()
{
	// Exceptions
	Bureaucrat *melanie = newBureaucrat("Melanie", 175);	(void) melanie;
	Bureaucrat *sylvan = newBureaucrat("Sylvan", 0);		(void) sylvan;
	std::cout << std::endl;
	
	// Grades ok
	Bureaucrat *fanny = newBureaucrat("Fanny", 150);
	Bureaucrat *louis = newBureaucrat("Louis", 5);
	std::cout << *fanny << std::endl;
	std::cout << *louis << std::endl;


	return 0;
}
