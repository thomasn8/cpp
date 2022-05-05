#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
// #include "Character.hpp"

class ICharacter;

class AMateria
{
	public:
	
		AMateria & operator=(AMateria const & src);
		AMateria(AMateria const & src);
		AMateria(std::string const & type);
		AMateria();
		virtual ~AMateria();

		std::string const	&getType() const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter & target);

	protected:
	
		std::string _type;
};

#endif