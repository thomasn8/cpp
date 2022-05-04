#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
	public:
	
		Cure & operator=(Cure const & src);
		Cure(Cure const & src);
		Cure();
		~Cure();

		virtual Cure *clone() const;
		virtual void use(Character & target);
};

std::ostream	& operator<<(std::ostream & o, Cure const & inst);

#endif
