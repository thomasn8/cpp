#include "Character.hpp"

void Character::deleteItems()
{
	delete this->_items[0];
	delete this->_items[1];
	delete this->_items[2];
	delete this->_items[3];
}

void Character::deleteUnequiped()
{
	Unequiped *current = this->_unequiped;
	Unequiped *next;
	while (current != NULL)
	{
		next = current->next;
		delete current->materia;
		delete current;
		current = next;
	}
}

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
	std::cout << m->getType() << " Materia has been equiped - " << m << std::endl;
}

void Character::unequip(int idx)
{
	if (this->_items[idx] == NULL)
		return;
	
	// liste chainée des materias jetés par le character
	Unequiped *current = this->_unequiped;
	if (!current)
	{
		current = new Unequiped;
		this->_unequiped = current;
		current->materia = this->getMateria(idx);
		current->next = NULL;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new Unequiped;
		current = current->next;
		current->materia = this->getMateria(idx);
		current->next = NULL;
	}
	
	// retrait de l'item de l'invetaire du character
	std::cout << this->getMateria(idx)->getType();
	std::cout << " Materia has been unequiped - " << this->getMateria(idx) << std::endl;
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
	std::cout << this->getName() << " equiped materias: " << std::endl;
	if (this->getMateria(0) != NULL)
		std::cout << "Item 1: " << this->getMateria(0)->getType() << " (" << this->getMateria(0) << ")"<< std::endl;
	if (this->getMateria(1) != NULL)
		std::cout << "Item 2: " << this->getMateria(1)->getType() << " (" << this->getMateria(1) << ")"<< std::endl;
	if (this->getMateria(2) != NULL)
		std::cout << "Item 3: " << this->getMateria(2)->getType() << " (" << this->getMateria(2) << ")"<< std::endl;
	if (this->getMateria(3) != NULL)
		std::cout << "Item 4: " << this->getMateria(3)->getType() << " (" << this->getMateria(3) << ")"<< std::endl;
}

void Character::seeUnquiped()
{
	Unequiped *current = this->_unequiped;
	Unequiped *next;
	
	std::cout << this->getName() << " unequiped materias: " << std::endl;
	if (!current)
		std::cout << "No items unequiped yet" << std::endl;
	while (current != NULL) 
	{
		next = current->next;
		std::cout << current->materia->getType() << std::endl;
		current = next;
	}
}


/* *****************
	Getters/Setters
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
	this->deleteItems();
	this->deleteUnequiped();
	this->_unequiped = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateria(i) != NULL)
			this->_items[i] = src.getMateria(i)->clone();
	}
	std::cout << "(assign.) Character " << this->_name << " has been copied - " << this << std::endl;
	return *this;
}

Character::Character(ICharacter const & src) :
_name(src.getName()),
_unequiped(NULL)
{
	this->deleteItems();
	this->deleteUnequiped();
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateria(i) != NULL)
			this->_items[i] = src.getMateria(i)->clone();
	}
	std::cout << "(copy) Character " << this->_name << " has been created - " << this << std::endl;
}

Character::Character(std::string const & name) :
_name(name),
_unequiped(NULL)
{
	this->_items[0] = NULL;
	this->_items[1] = NULL;
	this->_items[2] = NULL;
	this->_items[3] = NULL;
	std::cout << "(string) Character " << this->_name << " has been created - " << this << std::endl;
}

Character::Character() :
_name(""),
_unequiped(NULL)
{
	this->_items[0] = NULL;
	this->_items[1] = NULL;
	this->_items[2] = NULL;
	this->_items[3] = NULL;
	std::cout << "(default) Character has been created - " << this << std::endl;
}

Character::~Character()
{
	this->deleteItems();
	this->deleteUnequiped();
	std::cout << "Character has been destroyed - " << this << std::endl;
}
