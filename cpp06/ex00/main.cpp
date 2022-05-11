#include <iostream>
#include <stdlib.h>
#include <wctype.h>

int	error(char *msg)
{
	std::cout << msg << std::endl;
	exit(-1);
}

/* 
	SUJET
		Vous devez premièrement détecter le type du littéral passé en paramètre.
		- Exemples de littéraux de type char : ’c’, ’a’, ...
		- Exemples de littéraux de type int : 0, -42, 42...
		- Exemples de littéraux de type float : 0.0f, -4.2f, 4.2f...
		- Exemples de littéraux de type double : 0.0, -4.2, 4.2...

		le convertir de sa représentation sous forme de chaîne de caractères vers son véritable type, 
		et ensuite le convertir explicitement vers les trois autres types de données (char, int, float ou double)

		Si une conversion n’a pas de sens ou overflow, affichez un message pour informer l’utilisateur
		que la conversion de type est impossible. Incluez tout fichier d’en-tête qui vous
		sera nécessaire afin de gérer les limites numériques et les valeurs spéciales.

	-----------------------------------------------------------------------------------------------------------
	
	PSEUDO-CODE
		// PARTIE 1
			// détecter le type du littéral passé en paramètre
				// checker si c'est 1 seul charactère non-numérique, printable	->		char
				// sinon forcément type int, float ou double. Dans ce cas :
					// Détecter si une de ces exceptions :
						// si -inff, +inff et nanf								->		float
						// si -inf, +inf et nan									->		double
					// Parsing de la valeur pour détecter les cas d'erreur
						// si on a un caractère non numérique autre que '.', que '-' et que 'f'
						// si on a un '-' qui n'est pas au début ou si on a un 'f' qui n'est pas à la fin
						// si on a plus d'un '.'
					// Détection du type
						// si aucun '.'											->		int
						// sinon float ou double, dans ce cas :
							// si 'f' à la fin									->		float
							// sinon											->		double
		// PARTIE 2
			// convertir de sa représentation sous forme de chaîne de caractères vers son véritable type
			// grace à atoi ou atof selon le type détecter
		// PARTIE 3
			// ensuite le convertir EXPLICITEMENT vers les trois autres types de données
*/

int	parse(std::string literal)
{
	int	i = -1;
	int dots = 0;
	int len = literal.length();
	
	while (literal[++i])
	{
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


// -1 = erreur ; 1 = char ; 2 = int ; 3 = float ; 4 = double
/* 
	// PARTIE 2
		// convertir de sa représentation sous forme de chaîne de caractères vers son véritable type
		// grace à atoi ou atof selon le type détecter
	// PARTIE 3
		// ensuite le convertir EXPLICITEMENT vers les trois autres types de données
*/
int	convert(std::string literal)
{
	int type;

	type = get_type(literal);
	// ...
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