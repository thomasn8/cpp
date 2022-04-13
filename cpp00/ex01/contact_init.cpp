#include "Contact_class.hpp"

void	Contact::init_tab(char *tab)
{
	int	i;

	i = -1;
	while(++i < 10)
		tab[i] = '.';
	tab[i] = '\0';
}

void	Contact::print_data(void)
{
	std::cout << "Index:		" << this->index << std::endl;
	std::cout << "First name:	" << this->fname << std::endl;
	std::cout << "Last name:	" << this->lname << std::endl;
	std::cout << "Nickname:	" << this->nname << std::endl;
	std::cout << "Number:		" << this->number << std::endl;
	std::cout << "Secret:		" << this->secret << std::endl;
	return;
}

Contact::Contact(void)
{
	static int	i = 0;

	this->i = ++i;
	std::cout << "		INDEX " << i << std::endl;
	init_tab(this->index);
	init_tab(this->fname);
	init_tab(this->lname);
	init_tab(this->nname);
	init_tab(this->number);
	init_tab(this->secret);
	print_data();
	return;
}

Contact::~Contact(void)
{
	std::cout << "Destructor Contact" << std::endl;
	return;
}
