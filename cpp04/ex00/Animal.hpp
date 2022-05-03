#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{

	public:

		Animal & operator=(Animal const & src);
		Animal(Animal const & src);
		Animal();
		~Animal();

		std::string	getType() const;
		std::string	getSound() const;
		void		makeSound() const;

	protected:
	
		std::string _type;
		std::string _sound;
};

std::ostream	& operator<<(std::ostream & o, Animal const & inst);

#endif
