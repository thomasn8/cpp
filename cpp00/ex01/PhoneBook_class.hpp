#ifndef PhoneBook_class_hpp
# define PhoneBook_class_hpp

#include <iostream>
#include "Contact_class.hpp"

class PhoneBook
{
	public :

	PhoneBook(void);
	~PhoneBook(void);
	Contact tab[8];
};

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor PhoneBook" << std::endl;
	return;
}

#endif