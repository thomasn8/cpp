#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

// class ICharacter
// {
// public:
// virtual ~ICharacter() {}
// virtual std::string const & getName() const = 0;
// virtual void equip(AMateria* m) = 0;
// virtual void unequip(int idx) = 0;
// virtual void use(int idx, ICharacter& target) = 0;
// };

class Character
{
	public:
	
		Character & operator=(Character const & src);
		Character(Character const & src);
		Character(std::string const & name);
		Character();
		virtual ~Character();

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
		virtual AMateria * getMateriaPtr(int idx) const;

	private:

		std::string _name;
		AMateria *_items[4];
};

std::ostream	& operator<<(std::ostream & o, Character const & inst);

#endif

/* 
	Le Character a un inventaire de 4 items, soit 4 Materias maximum. À la construction,
	l’inventaire est vide. 

	Les Materias sont équipées au premier emplacement vide trouvé, soit dans l’ordre suivant : 
	de l’emplacement 0 au 3. 

	Dans le cas où on essaie d’ajouter une Materia à un inventaire plein, ou d’utiliser/retirer
	une Materia qui n’existe pas, ne faites rien (cela n’autorise pas les bugs pour autant). 
	La fonction membre unequip() ne doit PAS delete la Materia !
*/