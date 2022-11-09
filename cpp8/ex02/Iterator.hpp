#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iterator>
#include <iostream>

template <typename T>
class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	public:
		typedef T * pointer;
		typedef T & reference;
		
	// CONSTR - DESTR
		iterator() : _ptr(0) {};
		iterator(pointer ptr) : _ptr(ptr) {};
		iterator(iterator const & src) : _ptr(src._ptr) {};
		iterator & operator=(iterator const & src) { this->_ptr = src._ptr; return *this; }
		~iterator(){std::cout << "Destr called" << std::endl;};

	// OPERATIONS OVERLOADS
		reference operator*() const { return *this->_ptr; }
		bool operator==(iterator const & rhs) const { return this->_ptr == rhs._ptr; }
		bool operator!=(iterator const & rhs) const { return this->_ptr != rhs._ptr; }
		pointer operator++(void)
		{
			++this->_ptr;
			return this->_ptr;
		}
		pointer operator++(int)
		{
			pointer tmp(this->_ptr);
			this->_ptr++;
			return tmp;
		}
		pointer operator--(void)
		{
			--this->_ptr;
			return this->_ptr;
		}
		pointer operator--(int)
		{
			pointer tmp(this->_ptr);
			this->_ptr--;
			return tmp;
		}
	
	private:
		pointer _ptr;
};

// Comment fonctionnent les iterators :
// https://cplusplus.com/reference/iterator/iterator/?kw=iterator
// https://cplusplus.com/reference/iterator/BidirectionalIterator/

// iterator = objet qui contient une référence sur un autre objet
// plusieurs type d'iterators avec différentes propriétés/méthodes pour être manipulées
// ici, on reproduit le comportement d'un iterator de type BIDIRECTIONAL

#endif