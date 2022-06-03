#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:

		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;

		virtual AMateria * getMateria(int idx) const = 0;
		virtual void seeMaterias() const = 0;

	protected:

		virtual void deleteMaterias() = 0;
};

#endif