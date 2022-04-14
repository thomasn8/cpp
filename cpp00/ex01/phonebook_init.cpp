#include "PhoneBook_class.hpp"

void	PhoneBook::print_all(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		this->tab[i].print_data();
		i++;
	}
}

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor PhoneBook" << std::endl;
}
