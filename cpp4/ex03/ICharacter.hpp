#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
	public:

		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter & target) = 0;
		
		virtual ICharacter & operator=(ICharacter const & src) = 0;
		virtual AMateria * getMateria(int idx) const = 0;
		virtual void setName(std::string const & name) = 0;
		virtual void seeEquipement() const = 0;
		virtual void seeUnquiped() = 0;
	
	protected:

		virtual void deleteItems() = 0;
		virtual void deleteUnequiped() = 0;
};

#endif
