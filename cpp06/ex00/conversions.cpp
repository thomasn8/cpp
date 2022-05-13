#include "convert.hpp"

void char_conversion(int type, std::string literal)
{
	char	c;
	int		i;
	double	fd;

	if (type == 1)
		std::cout << "char: " << literal[0] << std::endl;
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf" 
			 || literal == "-inf" || literal == "+inf" || literal == "nan"
			 || (type == 2 && int_overflow(literal))
			 || ((type == 3 || type == 4) && int_overflow(get_int_part(literal))))
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
			fd = atof(literal.c_str());
			c = static_cast<char>(fd);
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
	double	fd;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf" 
			 || literal == "-inf" || literal == "+inf" || literal == "nan")
		std::cout << "int: impossible" << std::endl;
	else if (type == 2 && int_overflow(literal))
		std::cout << "int: impossible (integer overflow)" << std::endl;
	else if ((type == 3 || type == 4) && int_overflow(get_int_part(literal)))
		std::cout << "int: impossible (integer overflow)" << std::endl;
	else if (type == 2)
		std::cout << "int: " << integer_useless_zero_remove(literal) << std::endl;
	else
	{
		if (type == 1)
		{
			c = literal[0];
			i = static_cast<int>(c);
		}
		else if (type == 3 || type == 4)
		{
			fd = atof(literal.c_str());
			i = static_cast<int>(fd);
		}
		std::cout << "int: " << i << std::endl;
	}
}

void float_conversion(int type, std::string literal)
{
	char	c;
	int		i;
	float	f;

	if (type == 2 && int_overflow(literal))
		std::cout << "float: impossible (integer overflow)" << std::endl;
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		std::cout << "float: " << literal << std::endl;
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		std::cout << "float: " << literal << "f" << std::endl;
	else if (type == 3 || type == 4)
	{
		f = atof(literal.c_str());
		f = static_cast<float>(f);
		if (f == INFF)
			std::cout << "float: " << "+inff" << std::endl;
		else if (f == NEG_INFF)
			std::cout << "float: " << "-inff" << std::endl;
		else
			std::cout << "float: " << f << decimal_append(itoaf(f)) << "f" << std::endl;
	}
	else
	{
		if (type == 1)
		{
			c = literal[0];
			f = static_cast<float>(c);
		}
		else if (type == 2)
		{
			i = atoi(literal.c_str());
			f = static_cast<float>(i);
		}
		std::cout << "float: " << f << decimal_append(literal) << "f" << std::endl;
	}
}

void double_conversion(int type, std::string literal)
{
	char	c;
	int		i;
	double	d;

	if (type == 2 && int_overflow(literal))
		std::cout << "double: impossible (integer overflow)" << std::endl;
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		std::cout << "double: " << literal.erase(literal.length() - 1, 1) << std::endl;
	else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		std::cout << "double: " << literal << std::endl;
	else if (type == 3 || type == 4)
	{
		d = atof(literal.c_str());
		d = static_cast<double>(d);
		if (d == INF)
			std::cout << "double: " << "+inf" << std::endl;
		else if (d == NEG_INF)
			std::cout << "double: " << "-inf" << std::endl;
		else 
			std::cout << "double: " << d << decimal_append(itoaf(d)) << std::endl;
	}
	else
	{
		if (type == 1)
		{
			c = literal[0];
			d = static_cast<double>(c);
		}
		else if (type == 2)
		{
			i = atoi(literal.c_str());
			d = static_cast<double>(i);
		}
		std::cout << "double: " << d << decimal_append(literal) << std::endl;
	}
}

/*  
	FLOAT AND DOUBLE :
	------------------

	A float can store values 
	from:
    -340282346638528859811704183484516925440.0000000000000000 Float lowest
	to :
    340282346638528859811704183484516925440.0000000000000000 Float max

	A double can store values
	from:
    -179769313486231570814527423731704356798070567525844996598917476803157260
	7800285387605895586327668781715404589535143824642343213268894641827684675
	4670353751698604991057655128207624549009038932894407586850845513394230458
	3236903222948165808559332123348274797826204144723168738177180919299881250
	404026184124858368.0000000000000000 Double lowest
	to :
    1797693134862315708145274237317043567980705675258449965989174768031572607
	8002853876058955863276687817154045895351438246423432132688946418276846754
	6703537516986049910576551282076245490090389328944075868508455133942304583
	2369032229481658085593321233482747978262041447231687381771809192998812504
	04026184124858368.0000000000000000 Double max

	Float's precision allows it to store a value of up to 9 digits 
	(7 real digits, +2 from decimal to binary conversion)

	Double, like the name suggests can store twice as much precision as a float. 
	It can store up to 17 digits. (15 real digits, +2 from decimal to binary conversion)
	
	REF :
	https://stackoverflow.com/questions/48630106/what-are-the-actual-min-max-values-for-float-and-double-c
*/
