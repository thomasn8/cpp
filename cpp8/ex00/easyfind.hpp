#ifndef EASYFIND_H
# define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <stdexcept>

# define RED "\033[0;31m"
# define BLU "\033[0;34m"
# define WHI "\033[0m"

template<typename T>
typename T::iterator easyfind(T container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	try
	{
		if (it == container.end())
			throw std::exception();
		else
		{
			std::cout << BLU;
			std::cout << *it;
			std::cout << " found in container";
			std::cout << std::endl;
			std::cout << WHI;
		}
	}
	catch (std::exception)
	{
		std::cerr << RED;
		std::cerr << "No occurence of ";
		std::cerr << n;
		std::cerr << std::endl;
		std::cerr << WHI;
	}
	return it;
}

#endif