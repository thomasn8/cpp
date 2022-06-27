#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>

class Test
{
	public:
	
		Test & operator=(Test const & src);
		Test(Test const & src);
		Test(int id);
		Test();
		~Test();

		void setId(int id);
		int	getId() const ;

	private:

		int _id;
		float _money;
		char _letter;
		char _letter2;
		char _letter3;
		char _letter4;
		char _letter5;
};

std::ostream	& operator<<(std::ostream & o, Test const & inst);

#endif
