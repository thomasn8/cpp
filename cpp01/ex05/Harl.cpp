#include "Harl.hpp"
#include <ctype.h>

void Harl::complain(std::string level)
{
	std::string	complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	f_ptr 		functions[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int			i;

	// string_ptr_to_upper(&level);
	level = string_to_upper(level);
	i = 0;
	while (i < 4)
	{
		if (level == complains[i])
			return (this->*functions[i])();
		i++;
	}
	std::cout << "Invalid: argument passed to complain() member-function not accepted" << std::endl;
}

/* Debug messages contain contextual information.
They are mostly used for problem diagnosis. */
void Harl::_debug(void) const
{
	std::cout << "Debug: ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << std::endl;
}

/* These messages contain extensive information. 
They are helpful for tracing program execution in a production environment. */
void Harl::_info(void) const
{
	std::cout << "Info: ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

/* Warning messages indicate a potential issue in the system.
However, it can be handled or ignored. */
void Harl::_warning(void) const
{
	std::cout << "Warning: ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
}

/* These messages indicate an unrecoverable error has occurred.
This is usually a critical issue that requires manual intervention. */
void Harl::_error(void) const
{
	std::cout << "Error: ";
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

Harl::Harl(void)
{
}

Harl::~Harl()
{
}
