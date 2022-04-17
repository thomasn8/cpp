/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:08:53 by tnanchen          #+#    #+#             */
/*   Updated: 2022/04/17 13:40:36 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	PhoneBook::_copy_contact(Contact *src, Contact *dst)
{
	strcpy(dst->fname, src->fname);
	strcpy(dst->lname, src->lname);
	strcpy(dst->nname, src->nname);
	dst->s_fname = src->s_fname;
	dst->s_lname = src->s_lname;
	dst->s_nname = src->s_nname;
	dst->s_number = src->s_number;
	dst->s_secret = src->s_secret;
}

void	PhoneBook::_shift_contacts(void)
{
	Contact		old;
	Contact 	current;
	int			i;

	current.init_placeholder(current.fname);
	current.init_placeholder(current.lname);
	current.init_placeholder(current.nname);
	current.empty = 1;
	i = 8;
	while (--i > -1)
	{
		this->_copy_contact(&this->_tab[i], &old);
		this->_copy_contact(&current, &this->_tab[i]);
		this->_copy_contact(&old, &current);
	}
}

int	PhoneBook::_get_first_empty(void)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if (this->_tab[i].empty == 1)
			return (i);
		i++;
	}
	this->_shift_contacts();
	return (7);
}

void	PhoneBook::_save_data(std::string tmp, std::string *s,
	const char *info, char *placeholder)
{
	int	len;

	while (tmp.empty())
	{
		std::cout << "At least one chararacter! Try again..." << std::endl;
		std::cout << info << ": ";
		std::getline(std::cin, tmp);
	}
	*s = tmp;
	if (!placeholder)
		return ;
	if (tmp.size() > 10)
	{
		tmp.erase(9, tmp.npos);
		tmp.append(".");
	}
	if (tmp.size() < 10)
	{
		len = 10 - tmp.size();
		tmp.insert(tmp.begin(), len, BLANK);
	}
	tmp.copy(placeholder, 10, 0);
}

void	PhoneBook::_save_index(char *placeholder, int index)
{
	int					len;
	std::string			tmp;
	std::stringstream	out;

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

void	PhoneBook::add_contact(void)
{
	int			empty;
	std::string	tmp;

	empty = this->_get_first_empty();
	std::cout << "Firstname: ";
	std::getline(std::cin, tmp);
	this->_save_data(tmp, &this->_tab[empty].s_fname, "Firstname", this->_tab[empty].fname);
	std::cout << "Lastname: ";
	std::getline(std::cin, tmp);
	this->_save_data(tmp, &this->_tab[empty].s_lname, "Lastname", this->_tab[empty].lname);
	std::cout << "Nickname: ";
	std::getline(std::cin, tmp);
	this->_save_data(tmp, &this->_tab[empty].s_nname, "Nickname", this->_tab[empty].nname);
	std::cout << "Phone number: ";
	std::getline(std::cin, tmp);
	this->_save_data(tmp, &this->_tab[empty].s_number, "Phone number", NULL);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, tmp);
	this->_save_data(tmp, &this->_tab[empty].s_secret, "Darkest secret", NULL);
	this->_save_index(this->_tab[empty].index, empty);
	this->_tab[empty].empty = 0;
	std::cout << std::endl;
}
