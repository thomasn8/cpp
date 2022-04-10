#include "PhoneBook_class.hpp"
#include "Contact_class.hpp"

int	main(void)
{
	std::string cmd;

	while (1)
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			exit(0);
		// else if (cmd == "ADD")
			// ...
		// else if (cmd == "SEARCH")
			// ...
	}
	return 0;
}
