#ifndef Contact_class_hpp
# define Contact_class_hpp

#include <iostream>

class Contact
{
	public :

	Contact(void);
	~Contact(void);
};

Contact::Contact(void)
{
	std::cout << "Constructor Contact" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Destructor Contact" << std::endl;
	return;
}

#endif