#include <iostream>

// déclaration d'une classe
class Sample
{
	public:					// ?
							// fonctions membres :
	Sample(void);			// constructeur (fonction qui permet d'instancier un objet Sample)
	~Sample(void);			// destructeur (permet de désinstancier un objet Sample)
};

// définitions des fonctions constructeur/destructeur (n'ont jamais valeur de retour)
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}
Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	main(void)
{
	Sample	instance;	// déclaration d'une instance de la class Sample (appel auto au constructeur)

	return 0;	// a la fin du main, destruction de toutes les variables locales ainsi que
				// appel auto au destructeur des classes instanciées
}
