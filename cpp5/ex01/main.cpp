#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "NEW BUREAUCRATS" << std::endl;
	Bureaucrat *melanie = newBureaucrat("Melanie", 175);
	Bureaucrat *sylvan = newBureaucrat("Sylvan", 0);
	std::cout << std::endl;
	Bureaucrat *fanny = newBureaucrat("Fanny", 150);
	Bureaucrat *louis = newBureaucrat("Louis", 5);
	Bureaucrat *frank = newBureaucrat("Frank", 1);
	std::cout << *fanny << std::endl;
	std::cout << *louis << std::endl;
	std::cout << *frank << std::endl;
	std::cout << std::endl;	

	std::cout << "PROMOTIONS/RELEGATIONS" << std::endl;
	fanny->degrade();
	fanny->promote();
	louis->promote();
	louis->promote();
	louis->promote();
	frank->promote();
	frank->degrade();
	std::cout << *fanny << std::endl;
	std::cout << *louis << std::endl;
	std::cout << *frank << std::endl;
	std::cout << std::endl;

	std::cout << "NEW FORMS" << std::endl;
	Form *form1 = newForm("Form 1", 200, 200);
	Form *form2 = newForm("Form 2", 0, 0);
	Form *form3 = newForm("Form 3", 150, 150);
	Form *form4 = newForm("Form 4", 5, 5);
	Form *form5 = newForm("Form 5", 1, 1);
	std::cout << *form3 << std::endl;
	std::cout << *form4 << std::endl;
	std::cout << *form5 << std::endl;
	std::cout << std::endl;

	std::cout << "SIGNATURES - beSign()" << std::endl;
	form3->beSigned(*louis);
	form4->beSigned(*louis);
	form4->beSigned(*frank);
	form5->beSigned(*louis);
	std::cout << std::endl;

	std::cout << "SIGNATURES - signForm()" << std::endl;
	louis->signForm(form5);
	louis->promote();
	louis->signForm(form5);	
	frank->signForm(form5);
	std::cout << std::endl;

	return 0;
}
