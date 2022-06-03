#include "Harl.hpp"

void	string_ptr_to_upper(std::string *s)
{
	int			i;
	char		c;
	std::string u_s;

	i = -1;
	while ((c = s->c_str()[++i]))
		u_s += toupper(c);
	*s = u_s;
}

std::string	string_to_upper(std::string s)
{
	int	i;

	i = -1;
	while (s[++i])
		s[i] = toupper(s[i]);
	return (s);
}

int main (int ac, char **av)
{
	Harl inst;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter function_name" << std::endl;
		return 1;
	}
	inst.complain(av[1]);
	return 0;
}
