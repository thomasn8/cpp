#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice
{
	public:
	
		Ice & operator=(Ice const & src);
		Ice(Ice const & src);
		Ice();
		~Ice();

		std::string const &getType() const;
		virtual Ice	*clone() const;
		virtual void use(Character & target);

	protected:
	
		std::string _type;
};

std::ostream	& operator<<(std::ostream & o, Ice const & inst);

#endif
