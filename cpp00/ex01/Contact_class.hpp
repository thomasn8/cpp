#ifndef Contact_class_hpp
# define Contact_class_hpp

#include <iostream>

class Contact
{
	public :
	Contact(void);
	~Contact(void);
	int		i;
	char	index[11];
	char	fname[11];
	char	lname[11];
	char	nname[11];
	char	number[11];
	char	secret[11];

	private :
	void	init_tab(char *tab);
	void	print_data(void);
};

#endif