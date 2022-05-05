#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define DEFAULT "\033[0m"

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