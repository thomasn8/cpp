#include "main.hpp"
// #include <stdio.h>

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
