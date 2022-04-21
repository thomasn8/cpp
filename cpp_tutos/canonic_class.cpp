#include <iostream>

class CanonicClass												// Nécessaire pour respecter forme Canonique:
{
	public:
		CanonicClass(void);											// Constructeur par défault (possible de le mettre en private si inutile sous cette forme)
		CanonicClass(int const n);									
		CanonicClass(CanonicClass const & src);						// Constructeur par copie (crée une nvl inst)
		~CanonicClass(void);										// Destructeur

		CanonicClass	& operator=(CanonicClass const & rhs);		// Operateur d'assignation (met à jour l'inst. courante)
		
		int				getFoo(void) const;

	private:
		int				_foo;
};

std::ostream	& operator<<(std::ostream & o, CanonicClass const & i);	/* surcharge de chevron gauche pour rediriger flux sur sortie standard */


/* ******************************************************************* */

std::ostream	& operator<<(std::ostream & o, CanonicClass const & i)
{
	std::cout << "Flux redirection operator called on " << o << ": ";
	o << i.getFoo();
	return o;
}

int				CanonicClass::getFoo(void) const
{
	return (this->_foo);
}

CanonicClass	& CanonicClass::operator=(CanonicClass const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_foo = rhs.getFoo();
	return *this;
}

CanonicClass::CanonicClass(void) : _foo(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

CanonicClass::CanonicClass(int const n) : _foo(n)
{
	std::cout << "Parametric Constructor called" << std::endl;
}

CanonicClass::CanonicClass(CanonicClass const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

CanonicClass::~CanonicClass()
{
	std::cout << "Destructor called" << std::endl;	
}


/* ******************************************************************* */

int main(void)
{
	CanonicClass instance1;
	CanonicClass instance2(42);
	CanonicClass instance3(instance1);

	std::cout << instance1 << std::endl;
	std::cout << instance2 << std::endl;
	std::cout << instance3 << std::endl;

	instance3 = instance2;
	std::cout << instance3 << std::endl;

	return 0;
}
