#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Unequiped.hpp"

class Character : public ICharacter
{
	public:
	
		virtual ICharacter & operator=(ICharacter const & src);
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
		virtual void seeEquipement() const;
		virtual void seeUnquiped();

	private:

		std::string _name;
		AMateria *_items[4];
		Unequiped *_unequiped;
		virtual void deleteItems();
		virtual void deleteUnequiped();
};

std::ostream	& operator<<(std::ostream & o, ICharacter const & inst);

#endif
