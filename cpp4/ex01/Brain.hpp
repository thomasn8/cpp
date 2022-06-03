#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{

	public:

		Brain & operator=(Brain const & src);
		Brain(Brain const & src);
		Brain(std::string type);
		Brain();
		~Brain();

		std::string getIdeas(int i) const;

	private:

		std::string	_ideas[100];

};

#endif
