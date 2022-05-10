#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
// #include <ctype.h>
class Form;

class Intern
{
	public:
	
		Intern & operator=(Intern const & src);
		Intern(Intern const & src);
		Intern();
		~Intern();

		Form *makeForm(std::string formName, std::string target);
};

std::ostream	& operator<<(std::ostream & o, Intern const & inst);
typedef	Form *(*f_ptr)(std::string const & target);

#endif
