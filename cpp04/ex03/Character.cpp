#include "Character.hpp"

/* *****************
	Main actions
***************** */
void Character::equip(AMateria *m)
{
	int i = 0;

	while (this->_items[i] != NULL && i < 4)
		i++;
	if (i == 4) // inventaire plein
		return ;
	this->_items[i] = m;
}

void Character::unequip(int idx)
{
	if (this->_items[idx] == NULL)
		return;
	// enregistrer le ptr dans un tableau pour free à la fin les materias jetés
	this->_items[idx] = NULL;
}

void Character::use(int idx, Character& target)
{
	if (this->_items[idx] == NULL)
		return;
	this->_items[idx]->use(target);
}


/* *****************
	Getters
***************** */

std::string const & Character::getName() const
{
	return this->_name;
}

AMateria * Character::getMateriaPtr(int idx) const
{
	return this->_items[idx];
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, Character const & instance)
{
	o << instance.getName();
	return o;
}

Character	& Character::operator=(Character const & src)
{
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateriaPtr(i) != NULL)
			this->_items[i] = src.getMateriaPtr(i)->clone();
	}
	std::cout << "(assign.) Character has been copied" << std::endl;
	return *this;
}

Character::Character(Character const & src) :
_name(src.getName())
{
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateriaPtr(i) != NULL)
			this->_items[i] = src.getMateriaPtr(i)->clone();
	}
	std::cout << "(copy) Character has been created" << std::endl;
}

Character::Character(std::string const & name) :
_name(name)
{
	_items[0] = NULL;
	_items[1] = NULL;
	_items[2] = NULL;
	_items[3] = NULL;
	std::cout << "(string) Character has been created" << std::endl;
}

Character::Character()
{
	_items[0] = NULL;
	_items[1] = NULL;
	_items[2] = NULL;
	_items[3] = NULL;
	std::cout << "(default) Character has been created" << std::endl;
}

Character::~Character()
{
	std::cout << "Character has been destroyed" << std::endl;
}
