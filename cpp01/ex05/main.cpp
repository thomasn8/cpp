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

int main (void)
{
	Harl inst;

	inst.complain("debug ");
	inst.complain("debug");
	inst.complain("info");
	inst.complain("warning");
	inst.complain("error");
	inst.complain("invalid");
	return 0;
}
