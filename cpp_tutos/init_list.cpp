#include <iostream>

class Sample
{
	public:

	// construct/destruct
	Sample(int p1, int p2, char p3, char p4);
	~Sample(void);

	// attributs/fonctions
	int		a;
	int		b;
	char	c;
	char	d;
	void	print(void) const;								// const indique que cette fonction ne modifie pas l'instance
};

Sample::Sample(int p1, int p2, char p3, char p4) : 
a(p1), b(p2), c(p3), d(p4)									// nvl méthode pour initialisé une liste d'attribut
{
	std::cout << "Constructor called" << std::endl;
	return;
}
Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::print(void)	const							// print les valeurs après l'instanciation
{
	std::cout << "a = " << this->a << std::endl;
	std::cout << "b = " << this->b << std::endl;
	std::cout << "c = " << this->c << std::endl;
	std::cout << "d = " << this->d << std::endl;
	return;
}

int	main(void)
{
	Sample	instance(100, 200, 'x', 'y');
	instance.print();
	return 0;
}
