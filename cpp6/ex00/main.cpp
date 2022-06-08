#include "convert.hpp"

void	convert(std::string literal)
{
	int		type;

	type = get_type(literal);
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
