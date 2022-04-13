#include "PhoneBook_class.hpp"
#include "Contact_class.hpp"

#include <stdio.h>

void	test_empty_string(std::string tmp, const char *info)
{
	while (tmp.empty())
	{
		std::cout << "At least one chararacter! Try again..." << std::endl;
		std::cout << info << ": ";
		std::getline(std::cin, tmp);
	}
}

int	main(void)
{
	std::string cmd;
	PhoneBook contacts;
	std::string tmp;

	while (1)
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
		{
			std::cout << "Firstname: ";
			std::getline(std::cin, tmp);
			test_empty_string(tmp, "Firstname");
			// choper le contact à l'index approprié pour enregistrer la valeur
				// à partir de index 1, chercher le premier contact vide
				// si l'index 8 n'est pas vide -> décaler tous les contact de -1 
				// -> supprimera le 1er et laissera une place en 8
				// et enregistrer le nouveau en 8

			std::cout << "Lastname: ";
			std::getline(std::cin, tmp);
			test_empty_string(tmp, "Lastname");

			std::cout << "Nickname: ";
			std::getline(std::cin, tmp);
			test_empty_string(tmp, "Nickname");

			std::cout << "Phone number: ";
			std::getline(std::cin, tmp);
			test_empty_string(tmp, "Phone number");

			std::cout << "Darkest secret: ";
			std::getline(std::cin, tmp);
			test_empty_string(tmp, "Darkest secret");

		}
		// else if (cmd == "SEARCH")
			// ...
	}
	return 0;
}
