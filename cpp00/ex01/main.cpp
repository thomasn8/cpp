#include "PhoneBook_class.hpp"
#include "Contact_class.hpp"

int	main(void)
{
	std::string cmd;
	PhoneBook contacts;

	while (1)
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		// else if (cmd == "ADD")
			// ...
		// else if (cmd == "SEARCH")
			// ...
	}
	return 0;
}
