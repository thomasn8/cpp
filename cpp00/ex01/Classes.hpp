#ifndef PhoneBook_class_hpp
# define PhoneBook_class_hpp

#include <iostream>
# define BLANK '_'

/* 
	Contact datas are called by the PhoneBook methods
	So they need to be scoped in public access 
	But only PhoneBook public methods allows modification in the tab of 8 contacts
*/

class Contact
{
	public :
	Contact(void);
	~Contact(void);
	int			empty;
	int			i;
	std::string	s_index;
	char		index[11];
	std::string	s_fname;
	char		fname[11];
	std::string	s_lname;
	char		lname[11];
	std::string	s_nname;
	char		nname[11];
	std::string	s_number;
	char		number[11];
	std::string	s_secret;
	char		secret[11];
	void		init_placeholder(char *tab);
};

class PhoneBook
{
	public :
	PhoneBook(void);
	~PhoneBook(void);
	void	add_contact(void);
	void	search_contact(void);

	private :
	Contact	tab[8];
	int		get_first_empty(void);
	void	shift_contacts(void);
	void	copy_contact(Contact *src, Contact *dst);
	void	save_data(std::string tmp,  std::string *s, const char *info, char *placeholder);
	void	save_index(char *placeholder, int index);
	void	print_contacts(int empty);
	int		ask_index(int empty);
};

#endif
