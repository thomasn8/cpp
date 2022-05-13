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
	// std::cout << "float max = " << std::numeric_limits<float>::max() << std::endl;
	// std::cout << "float min = " << std::numeric_limits<float>::lowest() << std::endl;
	// std::cout << std::endl;
	// float f1 = 313.0123123f;
	// float f2 = static_cast<float>(313.0123123);
	// std::cout << "f1 = " << f1 << std::endl;
	// std::cout << "f2 = " << f2 << std::endl;

	if (ac != 2)
		error("Usage: ./convert <value>");
	convert(av[1]);
	return 0;
}

/* 
	./convert 0
	char: Non displayable
	int: 0
	float: 0.0f
	double: 0.0
	
	./convert nan
	char: impossible
	int: impossible
	float: nanf
	double: nan
	
	./convert 42.0f
	char: '*'
	int: 42
	float: 42.0f
	double: 42.0
*/
