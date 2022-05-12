#include <iostream>
#include <limits>
// #include <cstdlib>
// #include <cwctype>
// #include <typeinfo>
// #include <exception>

# define INFF std::numeric_limits<float>::infinity()
# define NEG_INFF - std::numeric_limits<float>::infinity()
# define INF std::numeric_limits<double>::infinity()
# define NEG_INF - std::numeric_limits<double>::infinity()

int	error(std::string msg)
{
	std::cout << msg << std::endl;
	exit(-1);
}

bool	int_overflow(std::string literal)
{
	int		len;
	long	num;
	int		digit;
	char	digit2;

	len = literal.length();
	num = atoi(literal.c_str());
	if ((literal[0] == '-' && num > 0) ||
		(literal[0] != '-' && num < 0))				// for 2147483648 and multiples
		return true;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		len--;
		digit = num % 10;
		digit2 = literal.c_str()[len];
		// std::cout << atoi(&digit2) << " vs " << digit << std::endl;
		if (atoi(&digit2) != digit)
			return true;
		num /= 10;
	}
	if (literal[0] == '-')
		len--;
	if (len > 0)									// for 8589934592 (= 2147483648 * 4)
		return true;
	return false;
}

int	parse(std::string literal)
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
		}
		else if (literal[i] == '-' && i != 0)
			return -1;
		else if (literal[i] == 'f' && i != (len - 1))
			return -1;
	}
	if (digits == 0)
		return -1;
	if (dots == 0)
		return 2;
	else if (literal[len - 1] == 'f')
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

void	convert(std::string literal)
{
	int		type;	// types:
	char	c;		// 1
	int		i;		// 2
	float	f;		// 3
	double	d;		// 4

	type = get_type(literal);
	std::cout << "TYPE: " << type << std::endl;

	char_conversion(type, literal);
	int_conversion(type, literal);
}

int main(int ac, char **av)
{
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


/* 
	5 actions de cast possibles

	- CONVERSIONS
	- RÉINTERPRÉTATIONS
	- CHANGEMENTS DE TYPE QUALIFIER
	- DOWNCAST
	- UPCAST

	promotion/downcast	= quand on va vers un type plus précis,		pas de problème de précision
	démotion/upcast		= quand on va vers un type moins précis,	perte de précision possible

	downcast implicite	=> ne compile pas
	upcast implicite	=> pas de problème de compilation

	-> static cast: 
		- pour les conversions de valeurs simples
			exemple: static_cast<int>(42);
		- pour les conversions de class (upcast/downcast), détecte les arbres d'héritages et empêche les conversions sans correspondance
			exemple: static_cast<Unrelated *>(&a)

	-> dynamic cast: 
		- fonctionne au runtime (≠ tous les autres à la compil)
		- fonctionne que sur des classes incorporant le polymorphisme virtuel (= classes avec méthodes, donc basées sur classe abstraite)
		- s'utilise uniquement pour les downcast, et vérifie si possible ou non
		- s'utilise qu'avec des ptr ou des ref
			exemple: dynamic_cast<Child1 *>(b)
			exemple: dynamic_cast<Child2 &>(*b)
		lorsqu'on dynamic_cast avec des ptr, si échoue retourne NULL
		lorsqu'on dynamic_cast avec des ref, si échoue throw une error std::bad_cast à gérer avec try-catch
*/