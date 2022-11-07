#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

# define RED "\033[0;31m"
# define WHI "\033[0m"

template<typename T = int>
class Array
{
	public:

		unsigned int size() const { return this->_n; }

		T & operator[](unsigned int index) const
		{
			try
			{
				if (index >= this->_n)
					throw Array::InaccessibleIndex();
			}
			catch (const Array::InaccessibleIndex & e)
			{
				std::cerr << RED;
				std::cerr << "Error: ";
				std::cerr << e.what();
				std::cerr << ". Program exited";
				std::cerr << std::endl;
				std::cerr << WHI;
				exit(1);
			}
			return this->_array[index];
		}

		Array & operator=(Array const & src)
		{
			this->_n = src.size();
			this->_array = new T[src.size()];
			for (unsigned int i = 0; i < src.size(); i++)
				this->_array[i] = src[i];
			std::cout << "(" << this << " - assign.) Array (" << &src << ") copied" << std::endl;
			return *this;
		}

		Array<T>(Array const & src) :
		_n(src.size())
		{
			this->_array = new T[src.size()];
			for (unsigned int i = 0; i < src.size(); i++)
				this->_array[i] = src[i];
			std::cout << "(" << this << " - copy) Array created" << std::endl;
		}

		Array<T>(unsigned int  n) : _n(n)
		{
			this->_array = new T[n];
			for (unsigned int i = 0; i < n; i++)
				this->_array[i] = 0;
			std::cout << "(" << this << " - N) Array created" << std::endl;
		}

		Array<T>() : _n(0)
		{
			this->_array = NULL;
			std::cout << "(" << this << " - default) Null Array created" << std::endl;
		}

		~Array<T>() 
		{
			delete [] this->_array;
			std::cout << "(" << this << " - default) Array destroyed" << std::endl;
		}
	
	private:
		T *_array;
		unsigned int _n;
		class InaccessibleIndex : public std::exception
		{
			public:
				virtual const char* what() const throw() { return ("index out of array"); }
		};
};

template<typename T>
std::ostream	& operator<<(std::ostream & o, Array<T> const & instance)
{
	o << "Array of " << instance.size() << " elements";
	return o;
}

#endif
