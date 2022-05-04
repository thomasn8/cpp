#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

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
		virtual void		use(Character & target);

	protected:
	
		std::string _type;
};

#endif