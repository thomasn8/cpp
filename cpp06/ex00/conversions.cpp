#include "convert.hpp"

void char_conversion(int type, std::string literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (type == 1)
		std::cout << "char: " << literal[0] << std::endl;
	else if (literal == "-inff" || literal == "+inff" || literal ==  "nanf" 
			 || literal ==  "-inf" || literal ==  "+inf" || literal ==  "nan"
			 || (type == 2 && int_overflow(literal)))
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (type == 2)
		{
			i = atoi(literal.c_str());
			c = static_cast<char>(i);
		}
		else if (type == 3 || type == 4)
		{
			f = atof(literal.c_str());
			c = static_cast<char>(f);
		}
		if (c >= ' ' && c < '~')
			std::cout << "char: '" << c << "'" << std::endl;
		else if ((c >= 0 && c < ' ') || c == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
	}
}

void int_conversion(int type, std::string literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (type == 2 && int_overflow(literal))
		std::cout << "int: impossible (overflow)" << std::endl;
	else if (type == 2)
		std::cout << "int: " << atoi(literal.c_str()) << std::endl;
	else if (literal == "-inff" || literal == "+inff" || literal ==  "nanf" 
			 || literal ==  "-inf" || literal ==  "+inf" || literal ==  "nan")
		std::cout << "int: impossible" << std::endl;
	else
	{
		if (type == 1)
		{
			c = literal[0];
			i = static_cast<int>(c);
		}
		else if (type == 3 || type == 4)
		{
			d = atof(literal.c_str());
			i = static_cast<int>(d);
		}
		std::cout << "int: " << i << std::endl;
	}
}
