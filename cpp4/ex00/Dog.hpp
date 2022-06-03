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

		virtual std::string	getType() const;
		virtual std::string	getSound() const;
		virtual void		makeSound() const;

	protected:
	
		std::string _type;
		std::string _sound;

};

std::ostream	& operator<<(std::ostream & o, Dog const & inst);

#endif
