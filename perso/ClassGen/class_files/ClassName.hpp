#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP

#include <iostream>

class ClassName
{
	public:
	
		ClassName & operator=(ClassName const & src);
		ClassName(ClassName const & src);
		ClassName(std::string const & name);
		ClassName();
		~ClassName();

		void setName(std::string const & name);
		std::string	getName() const ;

	private:

		std::string	_name;
};

std::ostream	& operator<<(std::ostream & o, ClassName const & inst);

#endif
