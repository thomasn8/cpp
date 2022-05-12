#include "convert.hpp"

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
	// float_conversion(type, literal);
	// double_conversion(type, literal);
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