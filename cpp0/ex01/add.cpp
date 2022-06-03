#include "main.hpp"

void	PhoneBook::_copyContact(Contact *src, Contact *dst)
{
	dst->setFirstName(src->getFirstName());
	dst->setLastName(src->getLastName());
	dst->setNickname(src->getNickname());
	dst->setNumber(src->getNumber());
	dst->setSecret(src->getSecret());
}

void	PhoneBook::_shiftContacts(void)
{
	Contact	old;
	Contact	current;
	int		i;

	current.setEmpty(true);
	i = 8;
	while (--i > -1)
	{
		this->_copyContact(&this->_tab[i], &old);
		this->_copyContact(&current, &this->_tab[i]);
		this->_copyContact(&old, &current);
	}
}

int	PhoneBook::_getFirstEmpty(void)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if (this->_tab[i].isEmpty() == true)
			return (i);
		i++;
	}
	this->_shiftContacts();
	return (7);
}

void	PhoneBook::_askData(std::string *tmp, const char *info)
{
	while (tmp->empty())
	{
		std::cout << "At least one chararacter! Try again..." << std::endl;
		std::cout << info << ": ";
		std::getline(std::cin, *tmp);
	}
}

void	PhoneBook::addContact(void)
{
	int			empty;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	empty = this->_getFirstEmpty();
	std::cout << "Firstname: ";
	std::getline(std::cin, firstName);
	this->_askData(&firstName, "Firstname");
	std::cout << "Lastname: ";
	std::getline(std::cin, lastName);
	this->_askData(&lastName, "Lastname");
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	this->_askData(&nickname, "Nickname");
	std::cout << "Phone number: ";
	std::getline(std::cin, number);
	this->_askData(&number, "Phone number");
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	this->_askData(&secret, "Darkest secret");
	this->_tab[empty].setFirstName(firstName);
	this->_tab[empty].setLastName(lastName);
	this->_tab[empty].setNickname(nickname);
	this->_tab[empty].setNumber(number);
	this->_tab[empty].setSecret(secret);
	this->_tab[empty].setEmpty(false);
	std::cout << std::endl;
}
