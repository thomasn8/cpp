#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

struct Data
{
	public:
	
		Data & operator=(Data const & src);
		Data(Data const & src);
		Data(std::string const & name);
		Data();
		~Data();

		void setName(std::string const & name);
		std::string	getName() const ;

	private:

		std::string	_name;
};

#endif
