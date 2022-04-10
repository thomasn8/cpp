#include <iostream>

// déclaration d'une classe
class Sample
{
	public:

	Sample(void);
	~Sample(void);
	int		foo;			// déclaration d'un attribut membre
	void	bar(void);		// déclaration d'une fonction membre
};

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	this->foo = 100;		// initialisation de l'attr dans le constructeur grâce au pointeur this
	this->bar();			
	return;
}
Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

// fonction membre renvoie la valeur d'un attribut de l'instance courante 
// grâce à: this->
void	Sample::bar(void)
{
	std::cout << "Foo = " << this->foo << std::endl;
	return;
}

int	main(void)
{
	Sample	instance;
	instance.foo = 31;
	instance.bar();
	return 0;
}
