#ifndef PhoneBook_class_hpp
# define PhoneBook_class_hpp

#include <iostream>
# define BLANK '.'

// contact datas are called directly by the PhoneBook class public methods
// so they need to be scoped in public access 
class Contact
{
	public :
	Contact(void);
	~Contact(void);
	int		empty;
	int		i;
	char	index[11];
	char	fname[11];
	char	lname[11];
	char	nname[11];
	char	number[11];
	char	secret[11];
	void	init_placeholder(char *tab);
	void	print_contact(void);
};

// only PhoneBook public methods allows modification in the list of 8 contacts
class PhoneBook
{
	public :
	PhoneBook(void);
	~PhoneBook(void);
	void	print_contacts(void);
	void	add_contact(void);

	private :
	Contact	tab[8];
	int		get_first_empty(void);
	void	shift_contacts(void);
	void	copy_contact(Contact *src, Contact *dst);
	void	save_data(std::string tmp, const char *info, char *placeholder);
	void	save_index(char *placeholder, int index);

};

#endif
