#include <iostream>
#include <cstdlib>
#include <cwctype>
#include <climits>

int	error(std::string msg)
{
	std::cout << msg << std::endl;
	exit(-1);
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
		error("Invalid value for conversion");
	return type;
}

/* 
	le convertir de sa représentation sous forme de chaîne de caractères vers son véritable type, 
	et ensuite le convertir explicitement vers les trois autres types de données (char, int, float ou double)

	Si une conversion n’a pas de sens ou overflow, affichez un message pour informer l’utilisateur
	que la conversion de type est impossible. Incluez tout fichier d’en-tête qui vous
	sera nécessaire afin de gérer les limites numériques et les valeurs spéciales.
*/

void	convert(std::string literal)
{
	int		type;	// types:
	char	c;		// 1
	int		i;		// 2
	float	f;		// 3
	double	d;		// 4

	type = get_type(literal);

	if (type == 1)
		c = literal[0];
	else if (type == 2)
		i = atoi(literal.c_str());
	else if (type == 3)
		f = atof(literal.c_str());
	else if (type == 4)
		d = atof(literal.c_str());

	if (type == 1)
	{
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << (int)c << std::endl;
		std::cout << "float: " << (float)c << std::endl;
		std::cout << "double: " << (double)c << std::endl;
	}
	// c = (char)literal[0];
	// std::cout << "char: " << c << std::endl;

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
		-> static cast :
		exemple: static_cast<int>(42);

	- RÉINTERPRÉTATIONS
	- CHANGEMENTS DE TYPE QUALIFIER
	- DOWNCAST
	- UPCAST

	promotion/downcast = quand on va vers un type plus précis, ne pose pas problème
	démotion/upcast = quand on va vers un type moins précis, pose problème
*/