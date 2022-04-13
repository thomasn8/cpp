#include "main.hpp"

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
