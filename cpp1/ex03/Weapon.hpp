#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{

	public:
		std::string	&getType(void) const;
		void		setType(std::string type);
		Weapon(std::string type);
		~Weapon(void);

	private:
		std::string	_type;
		std::string &_typeRef;
};

#endif
