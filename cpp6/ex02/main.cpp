#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdexcept>

// Crée aléatoirement une instance de A, B ou C et la retourne en tant que pointeur sur Base
Base *generate(void)
{
	Base *ptr;
	int rand_num;

	srand (time(NULL));
	rand_num = rand() % 3 + 1;
	if (rand_num == 1)
		ptr = new A;
	else if (rand_num == 2)
		ptr = new B;
	else if (rand_num == 3)
		ptr = new C;
	else
		return NULL;
	return ptr;
}

// affiche le véritable type de l’objet pointé par p : "A", "B" ou "C"
void identify(Base* p)
{
	try
	{
		A & a = dynamic_cast<A &>(*p);
		std::cout << "A class" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		B & b = dynamic_cast<B &>(*p);
		std::cout << "B class" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		C & c = dynamic_cast<C &>(*p);
		std::cout << "C class" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
}

// affiche le véritable type de l’objet pointé par p : "A", "B" ou "C"
void identify(Base& p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		std::cout << "A class" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		B & b = dynamic_cast<B &>(p);
		std::cout << "B class" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		C & c = dynamic_cast<C &>(p);
		std::cout << "C class" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
}

int main()
{
	Base *ptr = generate();
	Base & ref = *ptr;
	identify(ptr);
	identify(ref);
	return 0;
}
