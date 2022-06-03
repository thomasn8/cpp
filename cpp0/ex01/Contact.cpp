#include "Contact.hpp"
#include "main.hpp"

bool	Contact::isEmpty(void) const
{
	return (this->_empty);
}

std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getNumber(void) const
{
	return (this->_number);
}

std::string	Contact::getSecret(void) const
{
	return (this->_secret);
}

void	Contact::setEmpty(bool value)
{
	this->_empty = value;
}

void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::setNumber(std::string str)
{
	this->_number = str;
}

void	Contact::setSecret(std::string str)
{
	this->_secret = str;
}

Contact::Contact(void)
{
	this->_index = Contact::_nbIndex;
	Contact::_nbIndex += 1;
	this->_empty = true;
	return ;
}

Contact::~Contact(void)
{
	Contact::_nbIndex -= 1;
	return ;
}

int	Contact::_nbIndex = 0;
