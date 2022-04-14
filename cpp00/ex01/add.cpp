#include "main.hpp"
#include <stdio.h>

// fonction pour décaler un contact de -1 dans l'annuaire
// enregistre le 2 en 1, le 3 en 2, ..., le 8 en 7
void PhoneBook::shift_contacts(void)
{
	Contact		prev;
	Contact 	current;
	std::string	tmp;
	int			i;

	i = 0;
	while (++i < 8)
	{
		current = this->tab[i];
		prev = this->tab[i - 1];

		tmp = current.fname;
		printf("COPY %s -> %s\n", current.fname, prev.fname);
		tmp.copy(prev.fname, 10, 0);								// copy marche pas
		tmp = current.lname;
		tmp.copy(prev.lname, 10, 0);
		tmp = current.nname;
		tmp.copy(prev.nname, 10, 0);
		tmp = current.number;
		tmp.copy(prev.number, 10, 0);
		tmp = current.secret;
		tmp.copy(prev.secret, 10, 0);
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
	// si on atteint cette ligne : décaler tous les contacts de -1 pour libérer le 8
	// enregistre le 2 en 1, le 3 en 2, ..., le 8 en 7
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
