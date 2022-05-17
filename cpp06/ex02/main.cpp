#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
// (utiliser un pointeur dans cette fonction est interdit)
void identify(Base* p)
{
	// if (dynamic_cast<A *>(p))
	// 	std::cout << "A class" << std::endl;
	// if (dynamic_cast<B *>(p))
	// 	std::cout << "B class" << std::endl;
	// if (dynamic_cast<C *>(p))
	// 	std::cout << "C class" << std::endl;

	
}

int main()
{
	Base *p = generate();
	identify(p);

	return 0;
}

/* 	
	void identify(Base* p);
	Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".
	
	void identify(Base& p);
	Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C". Utiliser un pointeur
	dans cette fonction est interdit.
	
	Le fichier d’en-tête typeinfo est interdit.
	Écrivez un programme pour tester que tout fonctionne comme attendu.
*/