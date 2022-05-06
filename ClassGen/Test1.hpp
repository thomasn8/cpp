#ifndef TEST1_HPP
# define TEST1_HPP

#include <iostream>

class Test1
{
	public:
	
		Test1 & operator=(Test1 const & src);
		Test1(Test1 const & src);
		Test1(std::string const & name);
		Test1();
		~Test1();

		void setName(std::string const & name);
		std::string	getName() const ;

	private:

		std::string	_name;
};

std::ostream	& operator<<(std::ostream & o, Test1 const & inst);

#endif
