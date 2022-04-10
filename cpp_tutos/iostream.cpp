#include <iostream>

// 'std::' comprend toute la bibliothèque standard du c++

char buf[512];

int	main(void)
{
	std::cout << "Hello world !" << std::endl;
	std::cout << "Input a word: " << std::endl;
	std::cin >> buf;
	std::cout << "You entered: " << std::endl << buf << std::endl;
	return 0;
}
