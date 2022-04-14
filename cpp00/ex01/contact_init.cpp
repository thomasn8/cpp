#include "Contact_class.hpp"

void	Contact::init_placeholder(char *tab)
{
	int	i;

	i = -1;
	while(++i < 10)
		tab[i] = BLANK;
	tab[i] = '\0';
}

void	Contact::print_data(void)
{
	std::cout << "		INDEX " << i << std::endl;
	std::cout << "Index:		" << this->index << std::endl;
	std::cout << "First name:	" << this->fname << std::endl;
	std::cout << "Last name:	" << this->lname << std::endl;
	std::cout << "Nickname:	" << this->nname << std::endl;
	std::cout << "Phone number:	" << this->number << std::endl;
	std::cout << "Secret:		" << this->secret << std::endl;
}

Contact::Contact(void)
{
	static int	i = 0;

	this->i = ++i;
	this->empty = 0;
	init_placeholder(this->index);
	init_placeholder(this->fname);
	init_placeholder(this->lname);
	init_placeholder(this->nname);
	init_placeholder(this->number);
	init_placeholder(this->secret);
	// print_data();
}

Contact::~Contact(void)
{
	std::cout << "Destructor Contact" << std::endl;
	// print_data();
}
