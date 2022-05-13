#include "convert.hpp"

static int	parse(std::string literal)
{
	int	i = -1;
	int digits = 0;
	int dots = 0;
	int len = literal.length();
	
	while (literal[++i])
	{
		if (iswdigit(literal[i]))
			digits++;
		if (!iswdigit(literal[i]) && literal[i] != '.' && literal[i] != '-' && literal[i] != 'f')
			return -1;
		else if (literal[i] == '.')
		{	
			dots++;
			if (dots > 1)
				return -1;
			if (!iswdigit(literal[i + 1]))
				return -1;
		}
		else if (literal[i] == '-' && i != 0)
			return -1;
		else if (literal[i] == 'f' && i != (len - 1))
			return -1;
	}
	if (dots == 0 && literal[len - 1] == 'f')
		return - 1;
	if (digits == 0)
		return -1;
	if (dots == 0)
		return 2;
	if (literal[len - 1] == 'f')
		return 3;
	return 4;
}

int	get_type(std::string literal)
{
	int type = 0;

	// Detect char
	if (literal.length() == 1 && !iswdigit(literal[0]))
	{
		if (!iswprint(literal[0]))
			error("Value musts contain only printable characters");
		return 1;
	}
	// Detect exceptions
	std::string specials[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++)
	{
		if (literal == specials[i])
		{
			if (i < 3)
				return 3;
			return 4;
		}
	}
	// Detect numerical values
	type = parse(literal);
	if (type == -1)
		error("Error: invalid value");
	return type;
}
