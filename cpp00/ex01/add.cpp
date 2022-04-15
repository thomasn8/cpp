#include "main.hpp"
#include <stdio.h>

void	copy_contact(Contact *src, Contact *dst)
{
	strcpy(dst->fname, src->fname);
	strcpy(dst->lname, src->lname);
	strcpy(dst->nname, src->nname);
	strcpy(dst->number, src->number);
	strcpy(dst->secret, src->secret);
}

void PhoneBook::shift_contacts(void)
{
	Contact		old;
	Contact 	current;
	std::string	tmp;
	int			i;

	current.init_placeholder(current.fname);
	current.init_placeholder(current.lname);
	current.init_placeholder(current.nname);
	current.init_placeholder(current.number);
	current.init_placeholder(current.secret);
	current.empty = 1;
	i = 8;
	while (--i > -1)
	{
		copy_contact(&this->tab[i], &old);
		copy_contact(&current, &this->tab[i]);
		copy_contact(&old, &current);
	}
}

int	PhoneBook::get_first_empty(void)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if (this->tab[i].empty == 1)
			return (i);
		i++;
	}
	this->shift_contacts();
	return (7);
}

void	save_data(std::string tmp, const char *info, char *placeholder)
{
	int		len;

	while (tmp.empty())
	{
		std::cout << "At least one chararacter! Try again..." << std::endl;
		std::cout << info << ": ";
		std::getline(std::cin, tmp);
	}
	if (tmp.size() > 10)
		tmp.erase(10, tmp.npos);
	if (tmp.size() < 10)
	{
		len = 10 - tmp.size();
		tmp.insert(tmp.begin(), len, BLANK);
	}
	tmp.copy(placeholder, 10, 0);
}

void	save_index(char *placeholder, int index)
{
	int		len;
	std::string tmp;
	std::stringstream out;

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
