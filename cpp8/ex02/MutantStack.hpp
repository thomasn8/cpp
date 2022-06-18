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
	
		class iterator : public std::iterator<std::forward_iterator_tag, T>
		{
			private:
				T *_ptr;

			public:
				iterator() : _ptr(0) {};
				iterator(T *src) : _ptr(src) {};
  				iterator(iterator const & src) : _ptr(src.getPtr()) {};


				T *getPtr() const
				{
					return this->_ptr;
				}
				
				iterator & operator=(T *src)
				{
					this->_ptr = src;
					return *this;
				}

				T & operator*() const
				{
					return *this->_ptr;
				}

				bool operator==(iterator const & rhs) const
				{
					return this->_ptr == rhs.getPtr();
				}
				bool operator!=(iterator const & rhs) const
				{
					return this->_ptr != rhs.getPtr();
				}

				T	*operator++(void)
				{
					++this->_ptr;
					return this->_ptr;
				}
				T	*operator++(int)
				{
					T *tmp(this->_ptr);
					this->_ptr++;
					return tmp;
				}

				T	*operator--(void)
				{
					--this->_ptr;
					return this->_ptr;
				}
				T	*operator--(int)
				{
					T *tmp(this->_ptr);
					this->_ptr--;
					return tmp;
				}
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
