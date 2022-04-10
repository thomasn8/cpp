#include <iostream>

int	main(void)
{
	char buf[512];

	std::cout << "Hello world !" << std::endl;
	std::cout << "Input a word: " << std::endl;
	std::cin >> buf;
	std::cout << "You entered: " << std::endl << buf << std::endl;
	return 0;
}
