#ifndef PhoneBook_class_hpp
# define PhoneBook_class_hpp

#include <iostream>
#include "Contact_class.hpp"

class PhoneBook
{
	public :

	PhoneBook(void);
	~PhoneBook(void);
	Contact	tab[8];
	Contact tmp;
	int		get_first_empty(void);
	void	shift_contacts(void);
	void	print_all(void);
	void	clown_contact(Contact contact);
};

#endif
