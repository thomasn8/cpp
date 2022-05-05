#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
	
		Character & operator=(ICharacter const & src);
		Character(ICharacter const & src);
		Character(std::string const & name);
		Character();
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter & target);
		
		virtual AMateria * getMateria(int idx) const;
		virtual void setName(std::string const & name);

	private:

		std::string _name;
		AMateria *_items[4];
};

std::ostream	& operator<<(std::ostream & o, ICharacter const & inst);

#endif
