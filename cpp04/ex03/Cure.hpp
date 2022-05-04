#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure
{
	public:
	
		Cure & operator=(Cure const & src);
		Cure(Cure const & src);
		Cure();
		~Cure();

		std::string const &getType() const;
		virtual Cure *clone() const;
		virtual void use(Character & target);

	protected:
	
		std::string _type;
};

std::ostream	& operator<<(std::ostream & o, Cure const & inst);

#endif
