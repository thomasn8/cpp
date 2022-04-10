#ifndef PhoneBook_class_hpp
# define PhoneBook_class_hpp

#include <iostream>

class PhoneBook
{
	public :

	PhoneBook(void);
	~PhoneBook(void);
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