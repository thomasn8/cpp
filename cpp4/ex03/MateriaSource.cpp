#include "MateriaSource.hpp"

/* *****************
	Main actions
***************** */

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while (this->_materias[i] != NULL && i < 4)
		i++;
	if (i == 4) // inventaire plein
		return ;
	this->_materias[i] = m;
	std::cout << m->getType() << " Materia (" << m << ")learned by - " << this << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	return NULL;
}

void MateriaSource::deleteMaterias()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}

void MateriaSource::seeMaterias() const
{
	std::cout << "Materias saved: " << std::endl;
	if (this->getMateria(0) != NULL)
		std::cout << "Item 1: " << this->getMateria(0)->getType() << " (" << this->getMateria(0) << ")"<< std::endl;
	if (this->getMateria(1) != NULL)
		std::cout << "Item 2: " << this->getMateria(1)->getType() << " (" << this->getMateria(1) << ")"<< std::endl;
	if (this->getMateria(2) != NULL)
		std::cout << "Item 3: " << this->getMateria(2)->getType() << " (" << this->getMateria(2) << ")"<< std::endl;
	if (this->getMateria(3) != NULL)
		std::cout << "Item 4: " << this->getMateria(3)->getType() << " (" << this->getMateria(3) << ")"<< std::endl;
}


/* *****************
	Getters/Setters
***************** */

AMateria * MateriaSource::getMateria(int idx) const
{
	return this->_materias[idx];
}


/* *****************
	Canonical
***************** */

IMateriaSource	& MateriaSource::operator=(IMateriaSource const & src)
{
	this->deleteMaterias();
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateria(i) != NULL)
			this->_materias[i] = src.getMateria(i)->clone();
	}
	std::cout << "(assign.) MateriaSource has been copied - " << this << std::endl;
	return *this;
}

MateriaSource::MateriaSource(IMateriaSource const & src)
{
	this->deleteMaterias();
	for (int i = 0; i < 4; i++)
	{
		if (src.getMateria(i) != NULL)
			this->_materias[i] = src.getMateria(i)->clone();
	}
	std::cout << "(copy) MateriaSource has been created - " << this << std::endl;
}

MateriaSource::MateriaSource()
{
	this->_materias[0] = NULL;
	this->_materias[1] = NULL;
	this->_materias[2] = NULL;
	this->_materias[3] = NULL;
	std::cout << "(default) MateriaSource has been created - " << this << std::endl;
}

MateriaSource::~MateriaSource()
{
	this->deleteMaterias();
	std::cout << "MateriaSource has been destroyed - " << this << std::endl;
}
