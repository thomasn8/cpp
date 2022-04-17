/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:34 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/16 15:08:35 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	contacts;

	std::cout << std::endl << "'EXIT'		->	Leave the program" << std::endl;
	std::cout << "'ADD'		->	Save a new contact in the list (max. 8)" << std::endl;
	std::cout << "'SEARCH'	->	Get informations about a contact of the list" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Type your command: ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
			contacts.add_contact();
		else if (cmd == "SEARCH")
			contacts.search_contact();
	}
	return (0);
}
