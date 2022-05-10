#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
	
		PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm();

	private:
		
		virtual void action() const;
		virtual void abstract() const;
		PresidentialPardonForm();
};

Form	*newPresidentialPardonForm(std::string const & target);

#endif
