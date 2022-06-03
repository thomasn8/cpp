#include <iostream>

/* 
	Implémentez les fonctions templates suivantes :
	• swap : Intervertit les valeurs de deux arguments donnés. Ne retourne rien.
	• min : Compare les deux valeurs passées en argument et retourne la plus petite des
	deux. Si les deux sont équivalentes, alors retourne la seconde.
	• max : Compare les deux valeurs passées en argument et retourne la plus grande
	des deux. Si les deux sont équivalentes, alors retourne la seconde.
	Ces fonctions doivent pouvoir être appelées avec n’importe quel type d’argument à
	seule condition que ces derniers aient le même type et supportent les opérateurs de comparaison.
*/

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

/* 
	a = 3, b = 2
	min(a, b) = 2
	max(a, b) = 3
	c = chaine2, d = chaine1
	min(c, d) = chaine1
	max(c, d) = chaine2
*/