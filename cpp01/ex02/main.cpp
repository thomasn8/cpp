#include <iostream>

/*
	The goal of this exercise is to demystify references which can
	seem completely new. Although there are some little differences, this is another syntax
	for something you already do: address manipulation.
*/

// Une Ref est un pointeur, qui est constant, toujours déréférencé et jamais null.

int	main(void)
{
	std::string string			= "HI THIS IS BRAIN";
	std::string *stringPTR	= &string;
	std::string &stringREF	= string;

	std::cout << "1. memory address of the string variable:	" << &string << std::endl;
	std::cout << "2. memory address held by stringPTR:		" << stringPTR << std::endl;
	std::cout << "3. memory address held by stringREF:		" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "4. value of the string variable:		" << string << std::endl;
	std::cout << "5. value pointed to by stringPTR:		" << *stringPTR << std::endl;
	std::cout << "6. value pointed to by stringREF:		" << stringREF << std::endl;
	return 0;
}
