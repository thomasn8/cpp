#include "main.hpp"

void	PhoneBook::print_contacts(int empty)
{
	int	i;

	std::cout << std::endl;
	std::cout << "INDEX     " << "|";
	std::cout << "FIRST NAME" << "|";
	std::cout << "LAST NAME " << "|";
	std::cout << "NICKNAME  " << std::endl;
	i = -1;
	while (++i < empty)
	{
		std::cout << this->tab[i].index << "|";
		std::cout << this->tab[i].fname << "|";
		std::cout << this->tab[i].lname << "|";
		std::cout << this->tab[i].nname << std::endl;
	}
}

int	PhoneBook::ask_index(int empty)
{
	std::string index;
	int			index2;

	std::cout << std::endl << "Index:	";
	std::getline(std::cin, index);
	if (index == "STOP")
		return (-1);
	index2 = atoi(index.c_str()) - 1;
	while (index2 < 0 || index2 > empty - 1)
	{
		std::cout << "Select a contact between 1 to " << empty << " or 'STOP' searching" << std::endl;
		std::cout << "Index:	";
		std::getline(std::cin, index);
		if (index == "STOP")
			return (-1);
		index2 = atoi(index.c_str()) - 1;
	}
	return (index2);
}

void	PhoneBook::search_contact(void)
{
	int			i;
	int			index;
	int			empty;


	empty = 0;
	while (empty < 8)
	{
		if (this->tab[empty].empty == 1)
			break ;
		empty++;
	}
	if (empty == 0)
	{
		std::cout << "No recorded contact for now... Use 'ADD' to save a contact" << std::endl << std::endl;
		return ;
	}
	this->print_contacts(empty);
	index = this->ask_index(empty);
	if (index > -1)
	{
		std::cout << "First name:	" << this->tab[index].s_fname << std::endl;
		std::cout << "Last name:	" << this->tab[index].s_lname << std::endl;
		std::cout << "Nickname:	" << this->tab[index].s_nname << std::endl;
		std::cout << "Number:		" << this->tab[index].s_number << std::endl;
		std::cout << "Darkest secret:	" << this->tab[index].s_secret << std::endl << std::endl;
	}
}
