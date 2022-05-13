#include "convert.hpp"

void	convert(std::string literal)
{
	int		type;	// types:
	char	c;		// 1
	int		i;		// 2
	float	f;		// 3
	double	d;		// 4

	type = get_type(literal);
	std::cout << "TYPE: " << type << std::endl << std::endl;

	char_conversion(type, literal);
	int_conversion(type, literal);
	float_conversion(type, literal);
	double_conversion(type, literal);
}

int main(int ac, char **av)
{
	if (ac != 2)
		error("Usage: ./convert <value>");
	convert(av[1]);
	return 0;
}

/*
Unit tests:

	
*/