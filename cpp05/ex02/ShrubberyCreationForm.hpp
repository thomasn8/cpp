#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:
	
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm();

	private:
		
		virtual void abstract() const;
		ShrubberyCreationForm();
};

Form	*newShrubberyCreationForm(std::string const & target);

#endif
