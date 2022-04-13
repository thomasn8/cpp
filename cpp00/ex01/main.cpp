#include "main.hpp"
// #include <stdio.h>

void	save_index(char *placeholder, int index)
{
	int		len;
	std::string tmp;
	std::stringstream out;

	out << (index + 1);
	tmp = out.str();
	if (tmp.size() > 10)
		tmp.erase(10, tmp.npos);
	if (tmp.size() < 10)
	{
		len = 10 - tmp.size();
		tmp.insert(tmp.begin(), len, BLANK);
	}
	tmp.copy(placeholder, 10, 0);
}

void	save_data(std::string tmp, const char *info, char *placeholder)
{
	int		len;

	while (tmp.empty())
	{
		std::cout << "At least one chararacter! Try again..." << std::endl;
		std::cout << info << ": ";
		std::getline(std::cin, tmp);
	}
	if (tmp.size() > 10)
		tmp.erase(10, tmp.npos);
	if (tmp.size() < 10)
	{
		len = 10 - tmp.size();
		tmp.insert(tmp.begin(), len, BLANK);
	}
	tmp.copy(placeholder, 10, 0);
}

int	PhoneBook::get_first_empty(void)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if (this->tab[i].empty == 1)
			return (i);
		i++;
	}
	// si on atteint cette ligne : décaler tous les contacts de -1 pour libérer le 8
	return (7);
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	contacts;
	int			empty;
	std::string	tmp;

	while (1)
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
		{
			empty = contacts.get_first_empty();
			std::cout << "Firstname: ";
			std::getline(std::cin, tmp);
			save_data(tmp, "Firstname", contacts.tab[empty].fname);
			std::cout << "Lastname: ";
			std::getline(std::cin, tmp);
			save_data(tmp, "Lastname", contacts.tab[empty].lname);
			std::cout << "Nickname: ";
			std::getline(std::cin, tmp);
			save_data(tmp, "Nickname", contacts.tab[empty].nname);
			std::cout << "Phone number: ";
			std::getline(std::cin, tmp);
			save_data(tmp, "Phone number", contacts.tab[empty].number);
			std::cout << "Darkest secret: ";
			std::getline(std::cin, tmp);
			save_data(tmp, "Darkest secret", contacts.tab[empty].secret);
			save_index(contacts.tab[empty].index, empty);
			contacts.tab[empty].empty = 0;
		}
		// else if (cmd == "SEARCH")
			// ...
	}
	return 0;
}
