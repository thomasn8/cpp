#include "Brain.hpp"

/* *****************
	Getters
***************** */

std::string	Brain::getIdeas(int i) const
{
	return this->_ideas[i];
}


/* *****************
	Canonical
***************** */

Brain	& Brain::operator=(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdeas(i);
	std::cout << "(assign.) " << this->_ideas[0] << std::endl;
	return *this;
}

Brain::Brain(Brain const & src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src.getIdeas(i);
	std::cout << "(copy) " << this->_ideas[0] << std::endl;
}

Brain::Brain(std::string type)
{
	if (type == "Dog")
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = "\"I love cats\"";
	}
	if (type == "Cat")
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = "\"I hate dogs\"";
	}
	std::cout << "(string) " << this->_ideas[0] << std::endl;
}

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "\"I have no idea who I am\"";
	std::cout << "(default) " << this->_ideas[0] << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain's death" << std::endl;
}
