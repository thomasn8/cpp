#include "main.hpp"

// fonction pour décaler un contact de -1 dans l'annuaire
void PhoneBook::shift_contact(Contact current)
{
	Contact	prev;
	std::string	tmp;

	prev = this->tab[current.i - 1];
	// copier le current en prev
	tmp = current.index;
	tmp.copy(prev.index, 10, 0);
	tmp = current.fname;
	tmp.copy(prev.fname, 10, 0);
	tmp = current.lname;
	tmp.copy(prev.lname, 10, 0);
	tmp = current.nname;
	tmp.copy(prev.nname, 10, 0);
	tmp = current.number;
	tmp.copy(prev.number, 10, 0);
	tmp = current.secret;
	tmp.copy(prev.secret, 10, 0);
	prev.empty = 0;
	// clean le current
	current.init_placeholder(current.index);
	current.init_placeholder(current.fname);
	current.init_placeholder(current.lname);
	current.init_placeholder(current.nname);
	current.init_placeholder(current.number);
	current.init_placeholder(current.secret);
	current.empty = 1;
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
	i = 1;
	while (++i < 8)
		this->shift_contact(this->tab[i]);
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
