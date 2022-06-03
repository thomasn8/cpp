#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat & operator=(Cat const & src);
		Cat(Cat const & src);
		Cat();
		~Cat();
		
		virtual std::string	getType() const;
		virtual std::string	getSound() const;
		virtual void		makeSound() const;

	protected:
	
		std::string _type;
		std::string _sound;

};

std::ostream	& operator<<(std::ostream & o, Cat const & inst);

#endif
