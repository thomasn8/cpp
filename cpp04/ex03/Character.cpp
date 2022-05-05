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
	std::cout << "(" << m << ") " << m->getType() << " Materia has been equiped" << std::endl;
}

void Character::unequip(int idx)
{
	if (this->_items[idx] == NULL)
		return;
	// enregistrer le ptr dans une liste chainées pour free à la fin les materias jetés
	std::cout << "(" << this->getMateria(idx) << ") " << this->getMateria(idx)->getType();
	std::cout << " Materia has been unequiped" << std::endl;
	this->_items[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_items[idx] == NULL)
		return;
	std::cout << *this << " ";
	this->_items[idx]->use(target);
}

void Character::seeEquipement() const
{
	if (this->getMateria(0) != NULL)
		std::cout << this->getName() << " - item1: " << this->getMateria(0)->getType() << " (" << this->getMateria(0) << ")"<< std::endl;
	if (this->getMateria(1) != NULL)
		std::cout << this->getName() << " - item2: " << this->getMateria(1)->getType() << " (" << this->getMateria(1) << ")"<< std::endl;
	if (this->getMateria(2) != NULL)
		std::cout << this->getName() << " - item3: " << this->getMateria(2)->getType() << " (" << this->getMateria(2) << ")"<< std::endl;
	if (this->getMateria(3) != NULL)
		std::cout << this->getName() << " - item4: " << this->getMateria(3)->getType() << " (" << this->getMateria(3) << ")"<< std::endl;
}


/* *****************
	Getters / Setters
***************** */

std::string const & Character::getName() const
{
	return this->_name;
}

AMateria * Character::getMateria(int idx) const
{
	return this->_items[idx];
}

void Character::setName(std::string const & name)
{
	std::cout << "Character " << this->_name << " has been renamed " << name << std::endl;
	this->_name = name;
}


/* *****************
	Canonical
***************** */

std::ostream	& operator<<(std::ostream & o, ICharacter const & instance)
{
	o << instance.getName();
	return o;
}

ICharacter	& Character::operator=(ICharacter const & src)
{
	this->_name = src.getName();
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateria(i) != NULL)
		{
			if (this->_items[i] != NULL)
				delete this->_items[i];
			this->_items[i] = src.getMateria(i)->clone();
		}
	}
	std::cout << "(assign.) Character " << this->_name << " has been copied" << std::endl;
	return *this;
}

Character::Character(ICharacter const & src) :
_name(src.getName())
{
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateria(i) != NULL)
		{
			if (this->_items[i] != NULL)
				delete this->_items[i];
			this->_items[i] = src.getMateria(i)->clone();
		}
	}
	std::cout << "(copy) Character " << this->_name << " has been created" << std::endl;
}

Character::Character(std::string const & name) :
_name(name)
{
	_items[0] = NULL;
	_items[1] = NULL;
	_items[2] = NULL;
	_items[3] = NULL;
	std::cout << "(string) Character " << this->_name << " has been created" << std::endl;
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
