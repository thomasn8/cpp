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

};

std::ostream	& operator<<(std::ostream & o, Cat const & inst);

#endif
