#ifndef Contact_class_hpp
# define Contact_class_hpp

#include <iostream>
# define BLANK '.'

class Contact
{
	public :
	Contact(void);
	~Contact(void);
	int		empty;
	int		i;				// index en mémoire
	char	index[11];		// index dans l'annuaire
	char	fname[11];
	char	lname[11];
	char	nname[11];
	char	number[11];
	char	secret[11];

	// private :
	void	init_placeholder(char *tab);
	void	print_data(void);
};

#endif
