#include "main.hpp"

void	PhoneBook::_printContact(int index) const
{
	if (index > -1)
	{
		std::cout << "First name:	" << this->_tab[index].getFirstName() << std::endl;
		std::cout << "Last name:	" << this->_tab[index].getLastName() << std::endl;
		std::cout << "Nickname:	" << this->_tab[index].getNickname() << std::endl;
		std::cout << "Number:		" << this->_tab[index].getNumber() << std::endl;
		std::cout << "Darkest secret:	" << this->_tab[index].getSecret() << std::endl << std::endl;
	}
}

int	PhoneBook::_askIndex(int empty) const
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
		{
			std::cout << std::endl;
			return (-1);
		}
		index2 = atoi(index.c_str()) - 1;
	}
	return (index2);
}

// print str sur 10 caractères, Blank padded, truncated si nécessaire avec un '.'
void	PhoneBook::_printIndex(std::string str) const
{
	int			len;
	int			padd;
	std::string	label;

	label = str;
	len = label.length();
	if (len < 10)
	{
		padd = 10 - len;
		label.insert(0, padd, BLANK);
	}
	else if (len > 10)
	{
		label.erase(9, len);
		label += ".";
	}
	std::cout << label;
}

void	PhoneBook::_printIndexes(int empty) const
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
		for (int j = 0; j < 9 ; j++)
			std::cout << BLANK;
		std::cout << (i + 1) << "|";
		this->_printIndex(this->_tab[i].getFirstName());
		std::cout << "|";
		this->_printIndex(this->_tab[i].getLastName());
		std::cout << "|";
		this->_printIndex(this->_tab[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::searchContact(void) const
{
	int			empty;
	int			index;

	empty = -1;
	while (++empty < 8)
	{
		if (this->_tab[empty].isEmpty() == true)
			break ;
	}
	if (empty == 0)
	{
		std::cout << "No recorded contact for now... Use 'ADD' to save a contact" << std::endl << std::endl;
		return ;
	}
	this->_printIndexes(empty);
	index = this->_askIndex(empty);
	this->_printContact(index);
}
