#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat & operator=(WrongCat const & src);
		WrongCat(WrongCat const & src);
		WrongCat();
		~WrongCat();

		std::string	getType() const;
		std::string	getSound() const;
		void		makeSound() const;

	protected:
	
		std::string _type;
		std::string _sound;

};

std::ostream	& operator<<(std::ostream & o, WrongCat const & inst);

#endif
