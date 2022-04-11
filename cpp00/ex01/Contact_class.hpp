#ifndef Contact_class_hpp
# define Contact_class_hpp

#include <iostream>

class Contact
{
	public :

	Contact(void);
	~Contact(void);
	int		i;
	char	fname[10];
	char	lname[10];
	char	nname[10];
	char	number[10];
	char	secret[10];
	// void	init_tab(char *tab);
	// void	print_data(void);
};

Contact::Contact(void)
{
	static int	i = 0;

	this->i = ++i;
	// initialiser tous les tableaux à "          "
	// init_tab(this->fname);
	// init_tab(this->lname);
	// init_tab(this->nname);
	// init_tab(this->number);
	// init_tab(this->secret);
	// print_data();
	std::cout << "Constructor Contact" << i << std::endl;
	return;
}
Contact::~Contact(void)
{
	std::cout << "Destructor Contact" << std::endl;
	return;
}

// void	Contact::init_tab(char *tab)
// {
// 	int	i;

// 	i = 0;
// 	std::cout << "I=" << i << std::endl;
// 	while(i < 10)
// 	{
// 		tab[i] = '.';
// 		i++;
// 	}
// }

// void	Contact::print_data(void)
// {
// 	std::cout << "First name: " << this->fname << std::endl;
// 	std::cout << "Last name: " << this->lname << std::endl;
// 	std::cout << "Nickname: " << this->nname << std::endl;
// 	std::cout << "Number: " << this->number << std::endl;
// 	std::cout << "Secret: " << this->secret << std::endl;
// 	return;
// }

#endif