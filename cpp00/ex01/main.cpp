#include "main.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	contacts;

	while (1)
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "VIEW")
			contacts.print_contacts();
		else if (cmd == "ADD")
			contacts.add_contact();
		else if (cmd == "SEARCH")
			break;
	}
	return (0);
}
