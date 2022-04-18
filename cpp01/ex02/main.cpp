#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	// std::string &stringREF = ;

	std::cout << "1. memory address of the string variable:	" << &str << std::endl;
	std::cout << "2. memory address held by stringPTR:		" << stringPTR << std::endl;
	// std::cout << "3. memory address held by stringREF:		" << stringREF << std::endl;

	std::cout << "4. value of the string variable:		" << str << std::endl;
	std::cout << "5. value pointed to by stringPTR:		" << *stringPTR << std::endl;
	// std::cout << "6. value pointed to by stringREF:		" << *stringREF << std::endl;
	return 0;
}