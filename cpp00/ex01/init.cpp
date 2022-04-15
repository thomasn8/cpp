#include "Classes.hpp"

// Print Phonebook contacts datas
void	Contact::print_contact(void)
{
	std::cout << "		INDEX " << i << std::endl;
	std::cout << "Index:		" << this->index << std::endl;
	std::cout << "First name:	" << this->fname << std::endl;
	std::cout << "Last name:	" << this->lname << std::endl;
	std::cout << "Nickname:	" << this->nname << std::endl;
	std::cout << "Phone number:	" << this->number << std::endl;
	std::cout << "Secret:		" << this->secret << std::endl;
}
void	PhoneBook::print_contacts(void)
{
	int	i;

	i = 0;
	std::cout << std::endl;
	while (i < 8)
	{
		this->tab[i].print_contact();
		i++;
	}
	std::cout << std::endl;
}

// Initialize a contact datas
void	Contact::init_placeholder(char *tab)
{
	int	i;

	i = -1;
	while(++i < 10)
		tab[i] = BLANK;
	tab[i] = '\0';
}

// Contact Constructor/Destructor
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
	// std::cout << "Constructor Contact" << std::endl;
	return ;
}
Contact::~Contact(void)
{
	// std::cout << "Destructor Contact" << std::endl;
	return ;
}

// PhoneBook Constructor/Destructor
PhoneBook::PhoneBook(void)
{
	// std::cout << "Constructor PhoneBook" << std::endl;
	return ;
}
PhoneBook::~PhoneBook(void)
{
	// std::cout << "Destructor PhoneBook" << std::endl;
	return ;
}
