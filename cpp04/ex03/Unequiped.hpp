#ifndef UNEQUIPED_HPP
# define UNEQUIPED_HPP

#include <iostream>
#include "AMateria.hpp"

class Unequiped
{
	public:
	
		Unequiped & operator=(Unequiped const & src);
		Unequiped(Unequiped const & src);
		Unequiped();
		~Unequiped();

		AMateria *materia;
		Unequiped *next;
};

#endif
