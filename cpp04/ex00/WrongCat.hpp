#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat & operator=(WrongCat const & src);
		WrongCat(WrongCat const & src);
		WrongCat();
		~WrongCat();

	protected:
	
		// std::string _type;
};

std::ostream	& operator<<(std::ostream & o, WrongCat const & inst);

#endif
