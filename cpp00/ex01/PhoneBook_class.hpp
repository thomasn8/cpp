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
	int	get_first_empty(void);
};

#endif
