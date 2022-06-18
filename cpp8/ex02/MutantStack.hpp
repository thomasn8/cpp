#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>

template <typename T = int>
class MutantStack : public std::stack<int>
{
	public:
	
		class iterator : public std::iterator<std::input_iterator_tag, T>
		{
			private:
				T *_ptr;

			public:
				iterator(T *src) : _ptr(src) {};
				
				iterator & operator=(T *src)
				{
					this->_ptr = src;
					return *this;
				}

				T operator*()
				{
					return *this->_ptr;
				}
				T	*operator++(void)	// incrementation d'abord
				{
					++this->_ptr;
					return this->_ptr;
				}
				T	*operator++(int)		// incrementation après
				{
					T *tmp(this->_ptr);
					this->_ptr++;
					return tmp;
				}
				// T	operator--(void)
				// {
				// 	--this->_rawBits;
				// 	return *this;
				// }
				// T	operator--(int)
				// {
				// 	T	tmp(this->toFloat());
				// 	this->_rawBits--;
				// 	return (tmp);
				// }
		};
	
		T *begin() const 
		{
			T *first;
			
			first = static_cast<int *>(const_cast<T *>(&this->top()) - this->size() + 1);
			return first;
		}

		T *end() const 
		{
			T *last;

			last = static_cast<int *>(const_cast<T *>(&this->top()) + 1);
			return last;
		}
};

#endif
