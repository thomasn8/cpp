#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public Form
{
	public:
	
		RobotomyRequestForm & operator=(RobotomyRequestForm const & src);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm();

	private:
		
		void robotomisation() const;
		virtual void abstract() const;
		RobotomyRequestForm();
};

Form	*newRobotomyRequestForm(std::string const & target);

#endif
