#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog & operator=(Dog const & src);
		Dog(Dog const & src);
		Dog();
		~Dog();

};

std::ostream	& operator<<(std::ostream & o, Dog const & inst);

#endif
