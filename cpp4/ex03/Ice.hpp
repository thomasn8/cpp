#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria
{
	public:
	
		Ice & operator=(Ice const & src);
		Ice(Ice const & src);
		Ice();
		~Ice();

		virtual AMateria *clone() const;
		virtual void use(ICharacter & target);
};

std::ostream	& operator<<(std::ostream & o, Ice const & inst);

#endif
