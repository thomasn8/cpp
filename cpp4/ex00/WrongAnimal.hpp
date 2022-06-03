#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{

	public:

		WrongAnimal & operator=(WrongAnimal const & src);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal();
		~WrongAnimal();

		std::string	getType() const;
		std::string	getSound() const;
		void		makeSound() const;

	protected:
	
		std::string _type;
		std::string _sound;
};

std::ostream	& operator<<(std::ostream & o, WrongAnimal const & inst);

#endif
