#include "Classes.hpp"

// Initialize a contact datas
void	Contact::init_placeholder(char *tab)
{
	int	i;

	i = -1;
	while(++i < 10)
		tab[i] = BLANK;
	tab[i] = '\0';
}

/* * * * * * Class Constructor/Destructor * * * * * */
Contact::Contact(void)
{
	static int	i = 0;

	this->i = ++i;
	this->empty = 1;
	init_placeholder(this->index);
	init_placeholder(this->fname);
	init_placeholder(this->lname);
	init_placeholder(this->nname);
	init_placeholder(this->number);
	init_placeholder(this->secret);
	return ;
}
Contact::~Contact(void)
{
	return ;
}
PhoneBook::PhoneBook(void)
{
	return ;
}
PhoneBook::~PhoneBook(void)
{
	return ;
}
